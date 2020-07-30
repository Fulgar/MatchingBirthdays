#include <iostream>
#include <cstdlib>

using namespace std;

//Monte Carlo loop count
const double BIG_NUMBER = 1000000.0;

int main()
{
	//Loop from 10 to 200 people
	for (int N = 10; N <= 200; N++)
	{
		//int value to count how many external experiments have at least 3 people
		int containsThree = 0;
		//int value to count how many external experiments have at least 4 people
		int containsFour = 0;

		//Externally test N a lot of times
		for (int i = 1; i <= BIG_NUMBER; i++)
		{
			//birthdays[] stores the number of birthdays on a given day
			int birthdays[365] = {0};

			//Asking N people for their birthday
			for (int j = 1; j <= N; j++)
			{
				//Will return random int between 0 and 364
				int randomDay = rand() % 365;
				//Adds a count number for a person's birthday on the "randomDay" number day of the year
				birthdays[randomDay] += 1;
			}

			//Iterating through all birthday counts to see if any of them have at least 3 people with that birthday
			for (int x = 0; x <= 364; x++)
			{
				//If a day of the year has at least 3 people with that day as their birthday counted
				if (birthdays[x] >= 3)
				{
					//Increment number of times an experiment has found 3 people with the same birthday
					containsThree += 1;
					//Break out of for-loop, because the experiment has already found a day with 3 people that share its birthday
					break;
				}
			}

			//Iterating through all birthday counts to see if any of them have at least 4 people with that birthday
			for (int y = 0; y <= 364; y++)
			{
				//If a potential birthday has at least 3 people counted
				if (birthdays[y] >= 4)
				{
					//Increment number of times an experiment has found 3 people with the same bday
					containsFour += 1;
					//Break out of for-loop, because the experiment has already found a day with 3 people that share its birthday
					break;
				}
			}
		}

		//Percentage of events with at least 3 people who share a birthday
		double threePercentage = ((double) containsThree / BIG_NUMBER) * 100.0;

		//Percentage of events with at least 4 people who share a birthday
		double fourPercentage = ((double) containsFour / BIG_NUMBER) * 100.0;

		cout << "Chance of 3 bdays in room of " << N << " people: " << threePercentage << endl;
		cout << "Chance of 4 bdays in room of " << N << " people: " << fourPercentage << endl << endl;
	}
}