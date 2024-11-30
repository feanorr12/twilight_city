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
#define KOL_MAIL 15
#define KOL_THREADS 15

std::mutex mMutex_;

int Sleep()
{
	unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> distribution(0, 10);
	return distribution(generator);
}
class Mail
{
public:
	void Init(int id_)
	{
		id = id_, money = 100000;
		activ_potok = true;
		mythreads = std::thread(&Mail::translation, this);
	}		
	int  GetActivPotok() { return activ_potok; }
	void SetActivPotok(bool activ) { activ_potok = activ; }
	void Send(int sum, Mail& mail)
	{
		if (SendMoney(sum))
		{
			mail.GetMoney(sum);
			mMutex_.lock();
			std::cout << "|----------------------------------------------------------------|\n";
			std::cout << "Get with mail - " << id << " in " << mail.id << "  " << sum << " money    \n";
			std::cout << "In mail - " << id << " contains " << money << " money                  \n";
			std::cout << "|----------------------------------------------------------------|\n";
			mMutex_.unlock();
		}
		else
		{
			mMutex_.lock();
			std::cout << "|----------------------------------------------------------------|\n";
			std::cout << "In mail - " << id << ". The required amount is not in the account   \n";
			std::cout << "|----------------------------------------------------------------|\n";
			mMutex_.unlock();
		}
	}
	bool GetMoney(int money_)
	{
		std::lock_guard<std::mutex> lg(mMutex);
		std::this_thread::sleep_for(std::chrono::seconds(Sleep()% 10));
		money += money_;
		return true;
	}
	bool SendMoney(int money_)
	{
		std::lock_guard<std::mutex> lg(mMutex);
		std::this_thread::sleep_for(std::chrono::seconds(Sleep() % 10));
		if (money_ < money)
		{
			money -= money_;
			return true;
		}
		else
		{
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
};	Mail mail[KOL_MAIL];

void Mail::translation() {
	while (GetActivPotok())
	{
		unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
		std::default_random_engine generator(seed);
		std::uniform_int_distribution<int> distribution(0, KOL_MAIL);
		std::uniform_int_distribution<int> distribution_(10, 100000);
		int id_getter = distribution(generator);
		while (id_getter == id)
			id_getter = distribution(generator);
		int sum = distribution_(generator);
		mMutex_.lock();
		std::cout << "\n\nSend with mail - " << id << " in " << id_getter << " " << sum << " money\n\n";
		mMutex_.unlock();
		Send(sum, mail[id_getter]);
	}
}
int main()
{
	for (int i = 0; i < KOL_MAIL; i++)
		mail[i].Init(i);
	while (!_kbhit())
	{
		//mail[id_setter].SetActivPotok(true);
	}
	for (int i = 0; i < KOL_THREADS; i++)
		mail[i].SetActivPotok(false);
	for (int i = 0; i < KOL_THREADS; i++)
		mail[i].End();
	return 0;
}

