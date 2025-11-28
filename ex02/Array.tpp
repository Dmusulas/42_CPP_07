/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:43:53 by dmusulas          #+#    #+#             */
/*   Updated: 2025/11/28 12:47:56 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP
#include "Array.hpp"
#include <stdexcept>

template <typename T> Array<T>::Array() : data(new T[0]()), arraySize(0) {}

/*
** Constructor with an unsigned int n as a parameter.
** Uses new T[n]() (note the parenthesis) to ensure default initialization.
** This means types like int will be initialized to 0 instead of garbage values.
*/
template <typename T>
Array<T>::Array(unsigned int n) : data(new T[n]()), arraySize(n) {}

/*
** Copy Constructor: Performs a deep copy.
** Allocates new memory and copies elements one by one.
*/
template <typename T>
Array<T>::Array(const Array &other)
    : data(new T[other.arraySize]()), arraySize(other.arraySize) {
    for (unsigned int i = 0; i < arraySize; i++) {
        data[i] = other.data[i];
    }
}

/*
** Destructor: Cleans up the allocated memory.
*/
template <typename T> Array<T>::~Array() { delete[] data; }

/*
** Assignment Operator: Performs a deep copy.
** 1. Check for self-assignment.
** 2. Delete old memory.
** 3. Allocate new memory matching the other array's size.
** 4. Copy elements.
*/
template <typename T> Array<T> &Array<T>::operator=(const Array &other) {
    if (this != &other) {
        delete[] data;
        arraySize = other.arraySize;
        data = new T[arraySize]();
        for (unsigned int i = 0; i < arraySize; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

/*
** Subscript operator (non-const).
** Throws std::out_of_range (which inherits from std::exception) if index is
*invalid.
*/
template <typename T> T &Array<T>::operator[](unsigned int index) {
    if (index >= arraySize) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

/*
** Subscript operator (const).
** Necessary for accessing elements of const Array objects.
*/
template <typename T> const T &Array<T>::operator[](unsigned int index) const {
    if (index >= arraySize) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

/*
** Size function: Returns the number of elements.
*/
template <typename T> unsigned int Array<T>::size() const { return arraySize; }

#endif
