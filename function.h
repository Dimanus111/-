#pragma once
#include <stdbool.h>

#ifndef _FUNCTION_H_
#define _FUNCTION_H_

int Mult2(int value_);

/*
* @brief функция проверки числа на простату
* @param x: число, которое проверяется
* @return 1 - если функция верна, 0 - если функция неверна
*/
int Prime(unsigned long long int x);

/*
* @brief функция проверки числа на палнидром
* @param number_: чичло, которое проверяется
* @return палиндром или нет
*/
bool IsPalindrome(const unsigned int number_);

/*
* @brief заменить несколько пробелов на один
*/

void Contraction(char* str); //сокращает несколько пробелов в один
#endif