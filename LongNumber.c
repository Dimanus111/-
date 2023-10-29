#include "LongNumber.h"
#include <stdlib.h>

LongNumber* Sum(const LongNumber* n_1, const LongNumber* n_2)
{
	LongNumber* result = malloc(sizeof(LongNumber));
	if (!result)
		return NULL;

	if (n_1 > n_2)
		result->digits = malloc(sizeof(n_1->lenght));
	else
		result->digits = malloc(sizeof(n_2->lenght));

	unsigned int sub = n_1->lenght - n_2->lenght; // �������� ������ ����� �� ������
	for (unsigned int i = n_2->lenght; i > 0; --i) // ��� �� ���������� ����� � ������� � �������
	{
		unsigned int sum = n_1->digits[i + sub] + n_2->digits[i]; // ����� ����� � ������� � ����������� ���������
		unsigned int q1 = sum / 10;
		unsigned int q2 = sum % 10; // ����� 2 �����
		result->digits[i] = q2; // ����������� ����� � �������� (������� �� �����)
		n_1->digits[i + sub + 1] += q1; //���� ����� ���� ����� >= 10, �� ���������� � ���������� �������� � �������(����� 10)
	}
	return result;
}