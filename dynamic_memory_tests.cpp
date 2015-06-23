#include <cassert>
#include <iostream>
#include <cstdlib>

using namespace std;

/**
 * Tests dynamic memory
 */
void test_dynamic_memory() {
	// Allocates memory for an int
	int* x = new int;
	*x = 1;
	assert(*x == 1);

	// Allocates memory for an array of int
	int* xs = new int[5];
	for (int i = 0; i < 5; i++) {
		xs[i] = i;
	}
	assert(xs[0] == 0);

	// Free memory
	delete x;
	delete[] xs;

	// The computer will probably not have enough memory to allocate and if it
	// does not a 'bad_alloc' exception is thrown.
	long ys_size = 1000000000;
	try {
		new int[ys_size];
	} catch (bad_alloc& e) {
	}

	// If there's not enough memory to allocate an object and 'nothrow' is
	// specified, 'null' is returned instead of throwing the 'bad_alloc'
	// exception.
	int* ys = new (nothrow) int[ys_size];
	assert(ys == nullptr);
}

/**
 * Tests C dynamic memory
 */
void test_c_dynamic_memory() {
	// Allocates memory for an int
	int* x = (int*) malloc(sizeof(int));
	*x = 1;
	assert(*x == 1);
	free(x);

	// Allocates memory for an array of int
	int* xs = (int*) calloc(sizeof(int), 5);
	for (int i = 0; i < 5; ++i) {
		xs[i] = i;
	}
	assert(xs[1] == 1);
	free(xs);
}

void run_dynamic_memory_tests(void) {
	test_dynamic_memory();
	test_c_dynamic_memory();
}

