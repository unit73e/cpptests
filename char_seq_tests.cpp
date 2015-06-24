#include <cassert>
#include <cstring>
#include <string>

using namespace std;

/**
 * Tests if an array of char is the same as a c-string.
 *
 * Borrowed from C, a c-string in C++ is an array of char where the last
 * character is the null character, whose literal is written '\0'.
 */
void test_char_seq(void) {
	// Initialized like a normal array
	char foo[] = { 'H', 'e', 'l', 'l', 'o', '\0' };

	// Initialized with a string
	char bar[] = "Hello";

	// The variables foo and bar should have the same value
	assert(strcmp(foo, bar) == 0);
}

/**
 * Tests conversion between string and c-string and vice-versa.
 *
 * One difference between a c-string and a string is that c-strings have fixed
 * size, while a string size is determined at runtime.
 */
void test_string_vs_char_seq(void) {
	char hello[] = "Hello";
	string world = "World";

	// Converts from string to c-string
	const char* world2 = world.c_str();

	// Converts from c-string to string
	string bar2 = hello;

	// Should be equal to the assigned string literals
	assert(strcmp(hello, "Hello") == 0);
	assert(world.compare("World") == 0);

	// Should be equal to the converted values
	assert(strcmp(world2, "World") == 0);
	assert(bar2.compare("Hello") == 0);
}

void run_char_seq_tests(void) {
	test_char_seq();
	test_string_vs_char_seq();
}
