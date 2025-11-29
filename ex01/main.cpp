/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:24:42 by dmusulas          #+#    #+#             */
/*   Updated: 2025/11/29 18:26:48 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

// Functions that take non-const references (can modify elements)
void increment(int &n) { n++; }

void toUpper(char &c) {
    if (c >= 'a' && c <= 'z') {
        c = c - 'a' + 'A';
    }
}

void doubleValue(double &d) { d *= 2.0; }

// Functions that take const references (read-only)
void printInt(const int &n) { std::cout << n << " "; }

void printChar(const char &c) { std::cout << c; }

void printDouble(const double &d) { std::cout << d << " "; }

void printString(const std::string &s) { std::cout << "\"" << s << "\" "; }

// Function template that works with any type
template <typename T> void printGeneric(const T &value) {
    std::cout << value << " ";
}

int main() {
    std::cout << "=== Testing iter function template ===\n\n";

    // Test 1: Integer array with non-const reference function
    std::cout << "Test 1: Integer array modification\n";
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intSize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Before increment: ";
    iter(intArray, intSize, printInt);
    std::cout << "\n";

    iter(intArray, intSize, increment);

    std::cout << "After increment: ";
    iter(intArray, intSize, printInt);
    std::cout << "\n\n";

    // Test 2: Character array with non-const reference function
    std::cout << "Test 2: Character array modification\n";
    char charArray[] = {'h', 'e', 'l', 'l', 'o'};
    size_t charSize = sizeof(charArray) / sizeof(charArray[0]);

    std::cout << "Before toUpper: ";
    iter(charArray, charSize, printChar);
    std::cout << "\n";

    iter(charArray, charSize, toUpper);

    std::cout << "After toUpper: ";
    iter(charArray, charSize, printChar);
    std::cout << "\n\n";

    // Test 3: Double array with non-const reference function
    std::cout << "Test 3: Double array modification\n";
    double doubleArray[] = {1.5, 2.5, 3.5, 4.5};
    size_t doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << "Before doubling: ";
    iter(doubleArray, doubleSize, printDouble);
    std::cout << "\n";

    iter(doubleArray, doubleSize, doubleValue);

    std::cout << "After doubling: ";
    iter(doubleArray, doubleSize, printDouble);
    std::cout << "\n\n";

    // Test 4: String array with const reference function
    std::cout << "Test 4: String array (const reference)\n";
    std::string stringArray[] = {"Hello", "World", "C++", "Template"};
    size_t stringSize = sizeof(stringArray) / sizeof(stringArray[0]);

    std::cout << "String array: ";
    iter(stringArray, stringSize, printString);
    std::cout << "\n\n";

    // Test 5: Template function as parameter
    std::cout << "Test 5: Template function as parameter\n";
    int mixedArray[] = {10, 20, 30};
    size_t mixedSize = sizeof(mixedArray) / sizeof(mixedArray[0]);

    std::cout << "Using template function: ";
    iter(mixedArray, mixedSize, printGeneric<int>);
    std::cout << "\n\n";

    // Test 6: Const array (should work with const reference functions)
    std::cout << "Test 6: Const array\n";
    const int constArray[] = {100, 200, 300};
    size_t constSize = sizeof(constArray) / sizeof(constArray[0]);

    std::cout << "Const array: ";
    iter(constArray, constSize, printInt);
    std::cout << "\n";

    std::cout << "Const array with template: ";
    iter(constArray, constSize, printGeneric<int>);
    std::cout << "\n\n";

    std::cout << "\n=== All tests completed successfully! ===\n";

    return 0;
}
