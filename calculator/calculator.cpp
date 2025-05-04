#include "calculator.h"
#include <iostream>
#include <string>
#include <cmath>

// Определение функции ReadNumber.
//При вызове считываем из потока ввода число. Если поток ввода пуст или не число, возвращаем false.
bool ReadNumber(Number& result) {
    std::cin >> result;
    if (std::cin.fail()) {
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false;
    }
    return true;
}

// Определение функции ReadNumber.
bool RunCalculatorCycle() {
    // объявляем переменную для хранения значения в ячейке памяти.
    Number memory = 0;   
    // объявляем переменную для проверки наличия значения в ячейке памяти.
    bool memory_cell = false;   
    // объявляем переменную, которая будет хранить значение оператора
    std::string operator_variable = "";
    // объявляем переменную, которая будет хранить значение первого введенного числа
    Number number = 0; 
    
    // завершаем программу сразу, если первое число неккоретно введено
    if (!ReadNumber(number)) {
        return false;
    }
    // открывает цикл из которого будем выходить при появлении неизвестного оператора, неправильном использовании команды l с сообщением об ошибке, или после появления комады q, которая завершает программу.
    while (true) {
        // объявляем переменную храняющую следующее число.
        Number next_number = 0;
        //считываем оператор.
        std::cin >> operator_variable;
        
        if (operator_variable == "+") { // оператор сложения.
            if (ReadNumber(next_number)) {
                number += next_number;
            } else {
                return false;
            }
        } else if (operator_variable == "-") { // оператор вычитания.
            if (ReadNumber(next_number)) {
                number -= next_number;
            } else {
                return false;
            }
        } else if (operator_variable == "*") { // оператор умножения.
            if (ReadNumber(next_number)) {
                number *= next_number;
            } else {
                return false;
            }
        } else if (operator_variable == "/") { // оператор деления.
            if (ReadNumber(next_number)) {
                number /= next_number;
            } else {
                return false;
            }
        } else if (operator_variable == "**") { // оператор возведения в степень.
            if (ReadNumber(next_number)) {
                number = std::pow(number, next_number);
            } else {
                return false;
            }
        } else if (operator_variable == "=") { // команда выводит текущее значение в калькуляторе.
            std::cout << number << std::endl;
        } else if (operator_variable == ":") { // команда позволяет явно задать число. 
            if (!ReadNumber(number)) {
                return false;
            }
        } else if (operator_variable == "c") { // команда очистит.
            number = 0;
        } else if (operator_variable == "s") {  
            // при появлении команды s сохраняет последнее число в память и возвращат true в переменную проверки ячейки памяти.
            memory = number; 
            memory_cell = true;
        } else if (operator_variable == "l") { 
            // проверяет наличиее числа в памяти и использует его, либо выводит сообщение об ошибке и завершает программу.
            if (memory_cell) {
                number = memory;
            } else {
                std::cerr << "Error: Memory is empty" << std::endl;
                return false;
            }
        } else if (operator_variable == "q") { // команда завершающая выполнение программы. 
            return false;  
        } else {
            std::cerr << "Error: Unknown token " << operator_variable << std::endl;
            return false;
        }
    }
}