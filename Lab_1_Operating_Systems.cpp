#include<iostream>
#include<list>
#include<limits>
#include <cmath>
using namespace std;

void Program() 
{
	cout << "Hello!\n" << "This program converts a number from a septenary to a decimal." << endl;
}

void uncorrect() 
{
	cin.clear(); // возврат оператора ввода в состояние без ошибок 
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очистка буфера по максимальному значению типа int (streamsize) до того, пока не найдет enter
	cout << "I don't understand you, sorry. Please, try again.\n";
}

char valid_continue() 
{
	cout << "\nDo you want to continue? (y/n) >> ";
	char answer;
	cin >> answer;
	answer = tolower(answer); // С помощью библиотеки locale и функции tolower понижаем регистр
	while (answer != 'y' && answer != 'n' || cin.peek() != '\n') 
	{
		uncorrect();
		cout << "Do you want to continue? (y/n) >> ";
		cin >> answer;
	}
	return answer;
}

int main() 
{
	char answer;
	Program();
	do 
	{
		long long septenaryNum;
		list<int> septenaryNumList;
		long long decimalNum = 0;
		cout << "\nPlease, enter a non-negative number in the septenary system >> ";
		cin >> septenaryNum;

		bool flag = true;
		while (flag)
		{
			if (!cin.fail() && septenaryNum >= 0 && cin.peek() == '\n') // проверка на корректность ввода
				flag = false;

			if (!flag) // если ввод корректен
			{
				bool septenarySystemFlag = true; // флаг соответсвия семеричной системе
				// проверка на соответствие семеричной системе
				while (static_cast<int>(log10(septenaryNum)) + 1 > 0 && septenarySystemFlag)
				{
					int digit = septenaryNum % 10; // получаем последнюю цифру числа
					if (digit > 6)
					{
						septenarySystemFlag = false;
					}
					else
					{
						septenaryNumList.push_back(digit);
						septenaryNum /= 10; // удаляем последнюю цифру числа
						// получается список цифр числа в обратном порядке
					}
				}

				septenarySystemFlag ? 1 : flag = true;
			}
			
			if (flag)
			{
				uncorrect();
				cout << "Enter a non-negative number in the septenary system! >> ";
				cin >> septenaryNum;
			}

		}

		for (int i = 0; i < septenaryNumList.size(); i++)
		{
			decimalNum += *next(septenaryNumList.begin(), i) * pow(7, i);
		}

		cout << "Answer: " << decimalNum << endl;
		answer = valid_continue();

	} while (answer == 'y');

	cout << "Thanks for using this program.\n" << "Goodbye!";
	return 0;
}