/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:43:44 by dmusulas          #+#    #+#             */
/*   Updated: 2025/11/29 18:27:05 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T> class Array {
private:
    T *data;
    unsigned int arraySize;

public:
    // Constructor declarations only
    Array();
    Array(unsigned int n);
    Array(const Array &other);

    // Destructor
    ~Array();

    // Assignment operator
    Array &operator=(const Array &other);

    // Subscript operator
    T &operator[](unsigned int index);
    const T &operator[](unsigned int index) const;

    // Size function
    unsigned int size() const;
};

// Include the implementation at the end
#ifndef ARRAY_TPP
#include "Array.tpp"
#endif
#endif
