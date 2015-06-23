/*
 * array_test.cpp
 *
 *  Created on: Jun 13, 2015
 *      Author: emanuel
 */

#include <iostream>
#include <cassert>
#include <array>
#include "array_tests.h"

using namespace std;

/**
 * Returns the size of the given array
 */
template<typename T, unsigned S>
unsigned array_size(const T (&v)[S]) {
	return S;
}

/**
 * Returns the size of an array of ints.
 */
int first_elem(int array[]) {
	return array[0];
}

/**
 * Tests a full array initialization.
 */
void test_full_init(void) {
	int foo[5] = { 3, 4, 5, 2, 1 };
	assert(foo[0] == 3);
	assert(foo[1] == 4);
	assert(foo[2] == 5);
	assert(foo[3] == 2);
	assert(foo[4] == 1);
}

/*
 * Tests a partial array initialization.
 *
 * If an array of size x is initialized with y elements where y < x, the
 * remaining elements are initialized to a default value. In this case x = 5,
 * y = 3 and the default value of int is 0. So the array should be [1,2,3,0,0].
 */
void test_partial_init(void) {
	int foo[5] = { 1, 2, 3 };
	assert(foo[0] == 1);
	assert(foo[1] == 2);
	assert(foo[2] == 3);
	assert(foo[3] == 0);
	assert(foo[4] == 0);
}

/**
 * Test an empty array initialization.
 *
 * If an array of size x is initialized with nothing, all elements are set to
 * a default value. The default value of int is 0 so all elements of the array
 * are set to 0.
 */
void test_empty_init(void) {
	int foo[5] = { };
	assert(foo[0] == 0);
	assert(foo[1] == 0);
	assert(foo[2] == 0);
	assert(foo[3] == 0);
	assert(foo[4] == 0);
}

/**
 * Tests the ability of inferring the size of an initialized array.
 *
 * The size of an initialized array is inferred if the size is not
 * explicitly specified. Since the array is set to [1,2,3] the size can
 * only be 3.
 */
void test_inferred_size(void) {
	int foo[] = { 3, 2, 1 };
	assert(foo[0] == 3);
	assert(foo[1] == 2);
	assert(foo[2] == 1);
	assert(array_size(foo) == 3);
}

/**
 * Tests the universal initialization of an array.
 */
void test_universal_init(void) {
	int foo[] { 3, 2, 1 };
	assert(foo[0] == 3);
	assert(foo[1] == 2);
	assert(foo[2] == 1);
	assert(array_size(foo) == 3);
}

/**
 * Tests setting an element of an array.
 */
void test_set_elem(void) {
	int foo[5];
	foo[3] = 1;
	assert(foo[3] == 1);
}

/**
 * Tests getting an element of an array.
 */
void test_get_elem(void) {
	int foo[] = { 1, 2, 3 };
	int elem = foo[1];
	assert(elem == 2);
}

/**
 * Test access out of boundaries element.
 *
 * In C++ it is possible to access an element of an array that does not belong
 * to the boundaries of the array. This does not cause compilation errors, but
 * may cause runtime errors. The reason for this being allowed is because arrays
 * are implemented using pointers.
 */
void test_out_of_boundaries_access(void) {
	int foo[] = { 1, 2, 3 };
	int elem = foo[10];
	assert(elem >= 0 || elem < 0);
}

/**
 * Test multidimensional array.
 */
void test_multi_dimensional_array(void) {
	int foo[][3] = { { 1, 2, 3 }, { 4, 5, 6 } };
	assert(foo[1][1] == 5);
}

/**
 * Tests passing an array as argument of a function.
 *
 * Passing an array as argument does pass the entire block of memory of the
 * array. Instead, what is passed is the address of the array.
 */
void test_pass_array_as_arg(void) {
	int foo[] = { 1, 2, 3 };
	int f = first_elem(foo);
	assert(f == 1);
}

/**
 * Tests the C++ 11 array library.
 */
void test_library_array(void) {
	array<int, 3> foo = { 1, 2, 3 };
	int foo_size = foo.size();
	assert(foo_size == 3);
}

void run_array_tests(void) {
	test_full_init();
	test_partial_init();
	test_empty_init();
	test_inferred_size();
	test_set_elem();
	test_get_elem();
	test_out_of_boundaries_access();
	test_multi_dimensional_array();
	test_pass_array_as_arg();
}
