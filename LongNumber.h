#pragma once

typedef struct LongNumber
{
	unsigned char* digits;
	unsigned int lenght;
} LongNumber;

/*
* @brief ����� ���� ������� �����
* @param n1_ - ������ ������������ �����, n2_ - ������ ������������ �����
* @return ����� n1_ � n2_
*/
LongNumber* Sum(const LongNumber* n_1, const LongNumber* n_2);
