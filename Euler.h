﻿#pragma once

/*
* @brief Найдите сумму чисел меньше value_, кратных multipies_
* @param value_: число, меньше котрого ищем сумму
* @param multipies_: массив кратных чисел
* @return сумма чисел
*/
unsigned long long Problem_1(const unsigned int value_, const int* multiples_, const unsigned int size_);

/*
* @brief Найди сумму чётных элементов фибаначи не превышающих число 4000000
* @param value_: число фибаначи, меньше котрого ищем сумму
* @return сумма чисел
*/
unsigned long long Problem_2(const unsigned int value_);

/*
* @brief найти самый большой делитель числа 600851475143, являющийся простым числом
* @param value_: число, для которого ищем наибольший делитель 
* @return наибольший делитель 
*/
unsigned long long Problem_3(const unsigned long long value_);

/*
* @brief нахождение самого большого палиндрома, сделанный из произведения двух 3-х значных чисел
* @return наибольший палиндром
*/
unsigned long long Problem_4();

/*
* @brief найти наименьшее положительное число является равномерно делимым(без остатка) на все числа от 1 до 20
* @param значение, до которого перебираем делители
* @return искомое наименьшее положительное число
*/
unsigned long long Problem_5(const unsigned int value_);