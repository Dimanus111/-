#pragma once
#include <stdbool.h>

#ifndef _FUNCTION_H_
#define _FUNCTION_H_

int Mult2(int value_);

/*
* @brief ������� �������� ����� �� ��������
* @param x: �����, ������� �����������
* @return 1 - ���� ������� �����, 0 - ���� ������� �������
*/
int Prime(unsigned long long int x);

/*
* @brief ������� �������� ����� �� ���������
* @param number_: �����, ������� �����������
* @return ��������� ��� ���
*/
bool IsPalindrome(const unsigned int number_);

/*
* @brief �������� ��������� �������� �� ����
*/

void Contraction(char* str); //��������� ��������� �������� � ����
#endif