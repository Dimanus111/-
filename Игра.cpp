#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 4

int RandomNumber()
{

	srand(time(NULL));
	int number = 0;
	int digits[10] = { 0 };

	for (int i = 0; i < LENGTH; i++)
	{
		int digit;
		do
		{
			digit = rand() % 10;
		} 
		while (digits[digit] != 0);
		digits[digit] = 1;
		number = number * 10 + digit;
	}
	return number;
}

int countBulls(int number, int guess)
{
	int bulls = 0;
	for (int i = 0; i < LENGTH; i++)
	{
		if (number % 10 == guess % 10)
		{
			bulls++;
		}
		number /= 10;
		guess /= 10;
	}
	return bulls;
}

int countCows(int number, int guess)
{
	int cows = 0;
	for (int i = 0; i < LENGTH; i++)
	{
		int remainingDigits = guess;
		int currentDigit = number % 10;
		for (int j = 0; j < LENGTH; j++)
		{
			if (currentDigit == remainingDigits % 10)
			{
				cows++;
				break;
			}
			remainingDigits /= 10;
		}
		number /= 10;
	}
	return cows;
}

int main()
{
	printf("���� '���� � ������'/n");
	int number = RandomNumber();
	int attempts = 0;
	while (1)
	{
		attempts++;
		printf("������� %d: ", attempts);
		int guess;
		scanf_s("%d", &guess);
		if (guess < 1000 || guess > 9999)
		{
			printf("����� ������ ���� �������������/n");
			continue;
		}
		if (guess == number)
		{
			printf("�������-��! ���� �� � %d �������!/n", attempts);
			break;
		}
		int bulls = countBulls(number, guess);
		int cows = countCows(number, guess);
		printf("�����: %d, �����: %d/n", bulls, cows);
	}
	printf("��� �����? (y/n) ");
	char playAgain;
	scanf_s(" %c", &playAgain);
	if (playAgain == 'y' || playAgain == 'Y')
	{
		main();
	}
	return 0;
}