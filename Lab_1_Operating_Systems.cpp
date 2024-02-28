#include<iostream>
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
		long long decimalNum;
		cout << "\nPlease, enter a non-negative number in the septenary system >> ";
		cin >> septenaryNum;

		bool flag = true;
		while (flag)
		{
			decimalNum = 0;
			if (!cin.fail() && septenaryNum >= 0 && cin.peek() == '\n') // проверка на корректность ввода
				flag = false;

			if (!flag) // если ввод корректен то проверяем на соответствие семеричной системе
			{
				int position = 0;
				while (septenaryNum > 0 && !flag)
				{
					int digit = septenaryNum % 10; // получаем последнюю цифру числа
					if (digit > 6)
					{
						flag = true;
					}
					else
					{
						decimalNum += digit * pow(7, position); // переводим цифру в десятичную систему и добавляем к десятичному числу
						septenaryNum /= 10; // удаляем последнюю цифру числа
						position++;
					}
				}
			}
			
			if (flag)
			{
				uncorrect();
				cout << "Enter a non-negative number in the septenary system! >> ";
				cin >> septenaryNum;
			}

		}

		cout << "Answer: " << decimalNum << endl;
		answer = valid_continue();

	} while (answer == 'y');

	cout << "Thanks for using this program.\n" << "Goodbye!";
	return 0;
}