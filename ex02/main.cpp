/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:32:09 by dmusulas          #+#    #+#             */
/*   Updated: 2025/11/29 18:28:00 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

void printTitle(const std::string &title) {
    std::cout << "\n--- " << title << " ---" << std::endl;
}

int main() {
    try {
        // ---------------------------------------------------------
        printTitle("Test 1: Empty Array");
        Array<int> emptyArr;
        std::cout << "Empty array size: " << emptyArr.size() << std::endl;

        // ---------------------------------------------------------
        printTitle("Test 2: Int Array & Default Initialization");
        unsigned int n = 5;
        Array<int> intArr(n);

        std::cout << "Size: " << intArr.size() << std::endl;
        std::cout << "Checking initialization (should be 0): ";
        for (unsigned int i = 0; i < intArr.size(); i++) {
            std::cout << intArr[i] << " ";
        }
        std::cout << std::endl;

        // Modify values
        for (unsigned int i = 0; i < intArr.size(); i++) {
            intArr[i] = i * 10;
        }
        std::cout << "Modified values: ";
        for (unsigned int i = 0; i < intArr.size(); i++) {
            std::cout << intArr[i] << " ";
        }
        std::cout << std::endl;

        // ---------------------------------------------------------
        printTitle("Test 3: Deep Copy (Copy Constructor)");
        Array<int> copyArr(intArr);

        std::cout << "Original before modification: " << intArr[0] << std::endl;
        std::cout << "Copy before modification:     " << copyArr[0]
                  << std::endl;

        intArr[0] = 999; // Modify original

        std::cout << "Original after modification:  " << intArr[0] << std::endl;
        std::cout << "Copy after modification:      " << copyArr[0]
                  << " (Should be 0)" << std::endl;

        if (intArr[0] != copyArr[0])
            std::cout << "✅ Deep copy confirmed!" << std::endl;
        else
            std::cerr << "❌ Deep copy failed!" << std::endl;

        // ---------------------------------------------------------
        printTitle("Test 4: Assignment Operator");
        Array<int> assignArr(2);
        assignArr = intArr; // Assignment

        intArr[1] = 888; // Modify original

        std::cout << "Original [1]: " << intArr[1] << std::endl;
        std::cout << "Assigned [1]: " << assignArr[1] << " (Should be 10)"
                  << std::endl;

        if (intArr[1] != assignArr[1])
            std::cout << "✅ Deep assignment confirmed!" << std::endl;
        else
            std::cerr << "❌ Deep assignment failed!" << std::endl;

        // ---------------------------------------------------------
        printTitle("Test 5: Out of Bounds Exception");
        try {
            std::cout << "Accessing valid index 2: " << intArr[2] << std::endl;
            std::cout << "Attempting to access index " << n
                      << " (out of bounds)..." << std::endl;
            std::cout << intArr[n] << std::endl; // Should throw
        } catch (const std::exception &e) {
            std::cout << "✅ Caught expected exception: " << e.what()
                      << std::endl;
        }

        // ---------------------------------------------------------
        printTitle("Test 6: Complex Types (std::string)");
        Array<std::string> strArr(3);
        strArr[0] = "Hello";
        strArr[1] = "42";
        strArr[2] = "World";

        for (unsigned int i = 0; i < strArr.size(); i++) {
            std::cout << strArr[i] << " ";
        }
        std::cout << std::endl;

        // ---------------------------------------------------------
        printTitle("Test 7: Const Correctness");
        const Array<int> constArr(intArr);
        std::cout << "Read from const array: " << constArr[0] << std::endl;
        // constArr[0] = 5; // Uncommenting this should cause a compile error

    } catch (const std::exception &e) {
        std::cerr << "Unhandled exception: " << e.what() << std::endl;
    }

    return 0;
}
