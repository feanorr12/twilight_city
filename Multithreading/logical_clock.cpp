#include <iostream>
#include <mutex>
#include <cstdlib>
#include <thread>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <random>
#include <time.h>
#include <vector>
#define KOL_MAIL 10
#define time 5

std::mutex mMutex_;
int Sleep()
{
	unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> distribution(0, 2);
	return distribution(generator);
}
int max_(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

class Clock_V
{
public:
	void Init(int id_)
	{
		id = id_;
		for(int i=0;i< KOL_MAIL;i++)
		  counter[i] = 0;
	}
	void print()
	{
		std::cout << "In  " << id << " time - (";
		for (int i = 0; i < (KOL_MAIL - 1); i < i++)
			std::cout << counter[i] << ",";
        std::cout << counter[KOL_MAIL - 1] << ")\n";
	};
	void send_message()
	{
		counter[id] += 1;
	}
	int* GetCounter() { return counter; }
	void get_message(int* counter_, int id_)
	{
		for (int i = 0; i < (KOL_MAIL); i < i++)
		{
			if (id == i)
		      counter[i] = max_(counter_[id_], counter[i]) + 1;
			else
			  counter[i] = counter_[i];
		}
	}
private:
	int counter[KOL_MAIL];
	int id;
};

class Clock_S
{
public:
	void Init(int id_)
	{
		id = id_;
		counter = 0;
	}
	void print()
	{
		std::cout << "In  " <<id << " time - " << counter << " \n";
	};
	void send_message()
	{
		counter += 1;
	}
	int GetCounter() { return counter; }
	void get_message(int counter_)
	{
		counter = max_(counter_, counter) + 1;
	}
private:
	int counter;
	int id;
};
class Mail
{
public:
	void Init(int id_)
	{
		id = id_, money = 100000;
		activ_potok = true;
		mythreads = std::thread(&Mail::translation, this);
		clock_1.Init(id_);
		clock_2.Init(id_);
	}
	int  GetActivPotok() { return activ_potok; }
	void SetActivPotok(bool activ) { activ_potok = activ; }
	void Send(int sum, Mail& mail)
	{
		if (SendMoney(sum, mail.GetId()))
		{
			mail.GetMoney(sum, id, clock_1, clock_2);
		}
	}
	int GetId() { return id; }
	bool GetMoney(int money_,int id_, Clock_S& clock, Clock_V& clock_)
	{
		std::lock_guard<std::mutex> lg(mMutex);
		std::this_thread::sleep_for(std::chrono::seconds(Sleep() % 10));
		mMutex_.lock();
		money += money_;
		std::cout << "Get in the account " << id << " from account  " << id_ << " " << money_ << " money \n";
		clock_1.get_message(clock.GetCounter());
		clock_1.print();
		clock_2.get_message(clock_.GetCounter(),id);
		clock_2.print();
		std::cout << "In mail - " << id << " contains " << money << " money                  \n\n";
		mMutex_.unlock();
		return true;
	}
	bool SendMoney(int money_, int id_)
	{
		std::lock_guard<std::mutex> lg(mMutex);
		std::this_thread::sleep_for(std::chrono::seconds(Sleep() % 10));
		mMutex_.lock();
		std::cout << "Try Send with the account  " << id << " on account  " << id_ << " " << money_ << " money \n";
	    clock_1.send_message();
		clock_1.print();
		clock_2.send_message();
		clock_2.print();
		if (money_ < money)
		{
			money -= money_;
			mMutex_.unlock();
			return true;
		}
		else
		{
			std::cout << "In mail - " << id << ". The required amount is not in the account   \n\n";
			mMutex_.unlock();
			return false;
		}
	}
	void translation();
	void End()
	{
		mythreads.join();
	};
private:
	int money;
	int id;
	std::mutex mMutex;
	bool activ_potok;
	std::thread mythreads;
	Clock_S clock_1;
	Clock_V clock_2;
};	Mail mail[KOL_MAIL];

void Mail::translation() {
    while (GetActivPotok()){
		unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
		std::default_random_engine generator(seed);
		std::uniform_int_distribution<int> distribution(0, KOL_MAIL);
		std::uniform_int_distribution<int> distribution_(10, 100000);
		int id_getter = distribution(generator);
		//if(id_getter == id)
			//id_getter = distribution(generator);
		int sum = distribution_(generator);
		Send(sum, mail[id_getter]);
	}
}
int main()
{
	for (int i = 0; i < KOL_MAIL; i++)
		mail[i].Init(i);
	while (!_kbhit()){}
    for (int i = 0; i < KOL_MAIL; i++)
		mail[i].SetActivPotok(false);
	for (int i = 0; i < KOL_MAIL; i++)
		mail[i].End();
	return 0;
}
