#include <string>
#include <cassert>

using namespace std;

struct Person {
	int age;
	double height;
};

struct Color {
	int red;
	int green;
	int blue;
};

struct Pencil {
	int size;
	Color color;
};

/**
 * Tests data structure
 */
void test_struct(void) {
	Person joe;
	joe.age = 24;
	joe.height = 1.75;

	assert(joe.age == 24);
	assert(joe.height == 1.75);
}

/**
 * Tests data structure pointer
 */
void test_struct_pointer(void) {
	Person* john = new Person;

	/*
	 * The '->' is the dereference operator.
	 *
	 * The 'a->b' expression is equivalent to '(*a).b'. Careful though, it is
	 * not the same as '*a.b', that would be equivalent to '*(a.b)'.
	 */

	john->age = 20;
	(*john).height = 1.80;

	assert(john->age == 20);
	assert(john->height == 1.80);

	free(john);
}

void test_nested_structure(void) {
	Pencil pencil;
	pencil.size = 2;
	pencil.color.red = 255;
	pencil.color.green = 0;
	pencil.color.blue = 0;

	assert(pencil.color.red == 255);
}

void run_data_structures_tests(void) {
	test_struct();
	test_struct_pointer();
	test_nested_structure();
}
