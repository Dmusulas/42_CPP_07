/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:18:56 by dmusulas          #+#    #+#             */
/*   Updated: 2025/11/28 11:58:48 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

// NOTE: I use a template parameter 'F' instead of a specific function pointer
// (like void (*)(T&)) to allow flexibility. This lets the compiler deduce
// the function type automatically, supporting both 'T&' and 'const T&'
// parameters without strict type matching errors.
template <typename T, typename F> void iter(T *array, size_t length, F func) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

#endif
