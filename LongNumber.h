#pragma once

typedef struct NongNumber
{
	unsigned char* digits;
	unsigned int lenght;
} LongNumber;

/*
* @breaf ����� ���� ������� �����
* @param n1_ - ������ ������������ �����, n2_ - ������ ������������ �����
* @return ����� n1_ � n2_
*/
LongNumber* Sum(const LongNumber* n_1, const LongNumber* n_2);
