#include "union_tests.h"
#include <cassert>

/**
 * In a union all members occupy the same physical space in memory. The size of
 * of a union equals to the largest member element.
 */
union MyUnion {
	unsigned short s;
	unsigned int i;
	unsigned long l;
};

/**
 * An anonymous union is a union without a name. An anonymous union can appear
 * inside a class, structure or union. The access of members of an anonymous
 * union is differs from a named union.
 */
struct MyStruct {
	int id;
	union {
		int i;
		long l;
	};
};

/**
 * Tests a union.
 */
void test_union(void) {
	MyUnion u;

	// Since all members of a union share the same memory space, changing one
	// member of a union will affect all members.
	u.l = 4;

	assert(u.s == 4);
	assert(u.i == 4);
	assert(u.l == 4);
}

void test_annonymous_union(void) {
	MyStruct s;

	// Access to members of an anonymous union is direct.
	s.l = 8;

	assert(s.i == 8);
}

void run_union_tests(void) {
	test_union();
	test_annonymous_union();
}
