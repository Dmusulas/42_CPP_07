/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:43:53 by dmusulas          #+#    #+#             */
/*   Updated: 2025/11/29 18:27:48 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP
#include "Array.hpp"
#include <stdexcept>

template <typename T> Array<T>::Array() : data(new T[0]()), arraySize(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : data(new T[n]()), arraySize(n) {}

template <typename T>
Array<T>::Array(const Array &other)
    : data(new T[other.arraySize]()), arraySize(other.arraySize) {
    for (unsigned int i = 0; i < arraySize; i++) {
        data[i] = other.data[i];
    }
}

template <typename T> Array<T>::~Array() { delete[] data; }

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

template <typename T> T &Array<T>::operator[](unsigned int index) {
    if (index >= arraySize) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

template <typename T> const T &Array<T>::operator[](unsigned int index) const {
    if (index >= arraySize) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

template <typename T> unsigned int Array<T>::size() const { return arraySize; }

#endif
