#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <thread>
#include <stdio.h>
#include <iostream>
#include <random>
#include <time.h>
#include <mutex>
#include <agents.h>
#define KOL_MAIL 3

using namespace concurrency;
using namespace std;
int Sleep()
{
	unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> distribution(0, 10);
	return distribution(generator);
};
unbounded_buffer<int> buffs[KOL_MAIL];
unbounded_buffer<int> bufft[KOL_MAIL];
ITarget<int>& target = bufft[0];

class Mail_ : public agent
{
    public:
	explicit Mail_(
		ISource<int>& _source,
		ITarget<int>& _target,
		int _id) : source(_source), target(_target), money(100000), id(_id), active(true)
	{
		send(target, 0);
	    source.link_target(&target);
	}
	bool SendMoney(int money_)
	{
		std::this_thread::sleep_for(std::chrono::seconds(Sleep() % 10));
		if (money_ < money)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void Message()
	{
		int dataToProcess;
		while (0 != (dataToProcess = receive(source)))
		{
			if (dataToProcess > 0)
			{
				money += dataToProcess;
				std::cout << "Get in mail - " << id << " contains " << money << " money\n\n";
			}
			else
			{
				money -= dataToProcess;
				std::cout << "\n\nSend with mail - " << id << " " << money << " money\n\n";
			}
		}
	}
	void End()
	{
		active = false;
	}
    protected:
		void run()
		{
			while (active)
			{
				unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
				std::default_random_engine generator(seed);
				std::uniform_int_distribution<int> distribution(0, KOL_MAIL);
				std::uniform_int_distribution<int> distribution_(10, 100000);
				int id_getter = distribution(generator);
				while (id_getter == id)
					id_getter = distribution(generator);
				int sum = distribution_(generator);
				send(target, -sum);
				Message();
				if (SendMoney(sum))
				{
					send(bufft[id_getter], +sum);
				}
				else
				{
					std::cout << "In mail - " << id << ". The required amount is not in the account   \n";
				}
			}
		}
	private:
		ITarget<int>& target;
		ISource<int>& source;
		int money;
		bool active;
		int id;
};




std::mutex mMutex_;
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
			std::cout << "Get In mail - " << id << " contains " << money << " money                  \n";
			mMutex_.unlock();
		}
		else
		{
			mMutex_.lock();
			std::cout << "In mail - " << id << ". The required amount is not in the account   \n";
			mMutex_.unlock();
		}
	}
	bool GetMoney(int money_)
	{
		std::lock_guard<std::mutex> lg(mMutex);
		std::this_thread::sleep_for(std::chrono::seconds(Sleep() % 10));
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
	for (int i = 0; i < KOL_MAIL; i++)
		mail[i].SetActivPotok(false);
	for (int i = 0; i < KOL_MAIL; i++)
		mail[i].End();
	return 0;
}



