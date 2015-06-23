#include <cassert>
#include <cstring>

/**
 * Increments the value of the given pointer by one.
 *
 * Note that this works because i is not constant.
 */
void increment(int* i) {
	(*i)++;
}

/**
 * Dereferences the given pointer.
 */
int dereference_pointer(const int* i) {
	// A const pointer can not be modified.
	// The following code does not compile:
	//
	// (*i)++;
	return *i;
}

/**
 * Returns the sum of the given arguments.
 */
int add(int x, int y) {
	return x + y;
}

/**
 * Returns the result of subtracting x from y.
 */
int substract(int x, int y) {
	return x - y;
}

/**
 * Returns the result of executing an operation over two integers.
 */
int operate(int x, int y, int (*func)(int, int)) {
	return (*func)(x, y);
}

void generic_increment(void* data, int psize) {
	if (psize == sizeof(char)) {
		char* pchar = (char*) data;
		(*pchar)++;
	} else if (psize == sizeof(int)) {
		int* pint = (int*) data;
		(*pint)++;
	}
}

/**
 * Tests the address-of and the dereference operators.
 *
 * The address-of operator (&) gives the address of a variable. A pointer is a
 * variable that can store the address of another variable. The dereference
 * operator (*) gives the value pointed by a pointer.
 *
 * A pointer must have a type. Even though all pointers have the same size, the
 * value they point to do not. When a pointer is dereferenced, the size of the
 * value it points to is known through the pointer's type.
 *
 * Note that although both the dereference operator and pointer declaration use
 * an asterisk, they are different things that just happen to use the same sign.
 */
void test_address_of_and_dereference_ops(void) {
	// Initializes foo to some value
	int foo = 25;

	// Declares pointer p and initializes p with foo's address
	// Variable p should now point to foo's address
	int* p = &foo;

	// Dereferences p, giving the value pointed by p
	// Since p points to foo's address, dereferencing gives foo's value
	int bar = *p;

	// Variables foo and bar should have the same value
	assert(foo == bar);
}

/**
 * Tests pointers.
 */
void test_pointers(void) {
	int foo = 1;
	int bar = 2;

	// Stores the address of foo and bar to p1 and p2
	int* p1 = &foo;
	int* p2 = &bar;

	// Sets the values pointed by p1 and p2 to 10 and 20, respectively
	*p1 = 10;
	*p2 = 20;

	// Variables foo and bar should have the values previously assigned
	assert(foo == 10);
	assert(bar == 20);

	// Sets the value of p1 to the value of p2
	// This means p1 now points to bar
	p1 = p2;

	// Sets the value pointed by p1 to 30
	*p1 = 30;

	// Variable bar should have value 30 due to the previous assignment
	assert(bar == 30);
}

/**
 * Tests the similarities and differences between pointers and arrays.
 */
void test_pointer_vs_array(void) {
	long foo[] = { 1, 2, 3, 4, 5 };

	// An array can be implicitly converted to a pointer. The pointer points to
	// the first element of the array.
	long* p = foo;

	// Sets the first element of foo to 10
	*p = 10;
	assert(foo[0] == 10);

	// It it possible to move a pointer n elements by adding n to the pointer.
	// This is known as pointer arithmetic. Note that adding a step works with
	// any type. This means moving the pointer one step moves its address to an
	// amount equal the size of pointer's type.
	//
	// The following code sets the second element of foo to 20.
	p++;
	*p = 20;
	assert(foo[1] == 20);

	// Sets the third element of foo to 30
	p = &foo[2];
	*p = 30;
	assert(foo[2] == 30);

	// Brackets are a dereference operator and can be used both in arrays and
	// pointers. What x[y] means: start with x pointer, step y elements forward
	// and return the value of that address.
	p = foo;
	assert(foo[0] == p[0]);
	assert(foo[3] == p[3]);

	// Since brackets are a dereference operator, x[y] is equivalent to
	// *(x + y), dereferencing pointer x plus y offset.
	assert(*(foo + 3) == *(p + 3));

	// An array is not the same as a pointer. An pointer can be assigned to
	// another address, while an array can not.
	long bar = 20;
	p = &bar;

	// A pointer is not always converted to a pointer either. For example, the
	// size of an array calculated differently than that of a pointer.
	p = foo;
	assert(sizeof(foo) != sizeof(p));
}

/**
 * Tests pointer arithmetic.
 */
void test_pointer_arithmetic(void) {
	long foo[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	long* p = foo;

	/*
	 * The only valid arithmetic operations on a pointer are addition and
	 * subtraction. Adding or subtracting n to a pointer moves the pointer n
	 * elements forward or backward. The amount that is moved depends on the
	 * type of the pointer.
	 */

	// Moves p two steps forwards.
	p = p + 2;
	assert(foo[2] == *p);

	/*
	 * The increment (++) and decrement (--) operators can be used as either
	 * prefix or suffix operators. As prefix operator (e.g., ++x) the increment
	 * or decrement happens before the expression is evaluated. As suffix
	 * operator (e.g., x++) the increment or decrement happens after the
	 * expression is evaluated.
	 *
	 * Postfix operators, such as increment and decrement, have higher
	 * precedence than prefix operators, such as the dereference operator (*).
	 */

	// The expression *p++ is equivalent to *(p++), that is, p is dereferenced
	// and later incremented, after evaluation.
	assert(foo[2] == *p++);
	assert(foo[3] == *p);

	// The expression *++p is equivalent to *(++p), that is, p is incremented
	// and then dereferenced.
	assert(foo[4] == *++p);
	assert(foo[4] == *p);

	// The expression ++*p is equivalent to ++(*p), that is, p is dereferenced
	// and the value it points to is incremented.
	assert(++*p);
	assert(foo[4] == 5 + 1);

	// In the expression (*p)++, p is dereferenced and the value it points to
	// is post-incremented.
	assert(foo[4] == (*p)++);
	assert(foo[4] == 5 + 1 + 1);

	// The expression is equivalent to *(x++) == *(y++). Both expressions are
	// dereferenced and later incremented, so first what happens is *x = *y.
	// Only after evaluation of entire expression both increment.
	long* q = foo;
	*p++ = *q++;

	assert(foo[4] == 1);
	assert(foo[5] == *p);
	assert(foo[1] == *q);
}

/**
 * Tests pointer to constant.
 *
 * A pointer to constant can only read the pointed value, it can not modify it.
 * The pointer itself may be mutated, however, to point to another value.
 */
void test_pointer_to_const(void) {
	int foo = 1;
	int bar = 2;
	const int* p = &bar;

	// Reading the pointed value works fine
	foo = *p;
	assert(foo == 2);

	// However, the following code does not compile because p is a pointer to
	// a constant:
	// *p = *foo;

	// Mutating the pointer itself is valid
	foo = 5;
	p = &foo;
	assert(*p == 5);

	// A pointer to a non constant variable is implicitly converted to a pointer
	// to constant but not the other way around. The following code does not
	// compile:
	//
	// const int x = 1;
	// int* q = &x;

	/*
	 * Pointers to constants can also be used as arguments of a function.
	 */

	// Increments the value of the q pointer. The 'increment' function works
	// because the argument is a pointer to a non constant.
	int* q = &foo;
	increment(q);
	assert(foo == 6);

	// Dereferences the given pointer to a constant. The argument of the
	// 'dereference_pointer' is a pointer constant, so it cannot be modified but
	// can be dereferenced.
	int foo_value = dereference_pointer(q);
	assert(foo_value == foo);

	/*
	 * Naturally a pointer to a constant can use pointer arithmetic, since the
	 * pointer itself can be modified.
	 */

	int array[] = { 1, 2, 3 };
	const int* z = array;
	z++;
	assert(*z == 2);
}

/**
 * Tests constant pointers.
 *
 * A constant pointer cannot be modified. The pointer value can be modified but
 * the address of the pointer can not.
 */
void test_const_pointer(void) {
	int foo = 1;
	int bar = 2;
	int* const p = &foo;

	// Should modify the value of 'foo'. This works because only the pointer is
	// constant but the value it points to is not.
	*p = 2;
	assert(foo == 2);

	// The following code does not compile, however. A constant pointer can not
	// be modified:
	//
	// p = &bar;
	// p++;

	// It is also possible to have constant pointer to a constant. The pointer
	// can not be modified and neither can the pointed value.
	const int* const q = &bar;
	assert(*q == bar);

	// Careful with the placement of the asterisk though, both these lines mean
	// the same: a pointer to a constant integer.
	int const* x = &foo;
	const int* y = &bar;
	x = y;
	assert(*x == bar);
}

/**
 * Tests pointer to string literal.
 */
void test_string_literal(void) {
	// In ISO C++ a string literal should be initialized with a pointer to
	// a constant. That is because a string literal is an array of constant
	// characters and in C++ a pointer to a constant can not be converted to a
	// pointer to a non constant.
	const char* a = "Hello";
	assert(strcmp(a, "Hello"));
	assert(a[1] == 'e');

	// The following code not compile or at least give a warning:
	//
	// char* b = "World!";

	// The following code should not compile because a pointer to a constant
	// can not change the pointed value:
	//
	// a[1] = 'x';

	// The following code should not compile because a pointer to a constant can
	// not be converted to a pointer to a non constant:
	//
	// char* c = a;

	// Even though you can't have a pointer to a non constant store a string
	// literal, you can initialize a string with an array of non constant
	// characters.
	char b[] = "World!";

	// That's because initializing an array with a string literal is just a
	// short-hand for the following code:
	char c[] = { 'W', 'o', 'r', 'l', 'd', '!', '\0' };

	assert(strcmp(b, c));
}

/**
 * Tests pointers to pointers.
 */
void test_pointer_to_pointer(void) {
	int x = 1;
	// Pointer to x
	int* y = &x;
	// Pointer to y, that is, z is a pointer to another pointer
	int** z = &y;

	assert(*y == x);
	// Dereferencing z should be the same as y
	assert(*z == y);
	// Dereferencing z twice should be the same as dereferencing y
	assert(**z == x);
}

/**
 * Tests the void pointer.
 *
 * In C++ void means absence of type, so void pointers are pointers that point
 * to a value that has no type. This means void pointers can point to any value.
 * However, this also means a void pointer has undetermined length and
 * dereferencing properties and can not be directly dereferenced.
 */
void test_void_pointer(void) {
	int x = 1;
	char y = 'a';

	// The void pointer can be used to reference a value of any type.
	void* p;
	p = &x;
	p = &y;

	// The following code will not work because a void pointer cannot be
	// directly dereferenced. Since a void pointer has undetermined length and
	// dereferencing properties, there's no way to know how to dereference a
	// void pointer directly.
	//
	// *p = 'c';

	// One way to dereference a pointer is to convert to another type of
	// pointer.
	char* q = (char*) p;
	assert(*q == 'a');

	// Void pointers may be used to create functions with generic parameters
	generic_increment(&x, sizeof(x));
	generic_increment(&y, sizeof(y));
	assert(x == 2);
	assert(y == 'b');
}

/**
 * Tests invalid pointers.
 */
void test_invalid_pointers(void) {
	/*
	 * Invalid pointers do not result in compilation errors.
	 */

	// Uninitialized pointer
	int *p;

	// Pointer to an element out of bounds
	const int array[] = { 1, 2, 3 };
	const int *q = array + 5;

	/*
	 * However, dereferencing an invalid pointer an invalid pointer results in
	 * undefined behavior (e.g., runtime error, getting a random value).
	 */

	// int x = *p;
	// int y = *q;
	// assert(x >= 0 || x < 0);
	// assert(y >= 0 || y < 0);
}

/**
 * Tests null pointers.
 *
 * A null pointer is a pointer that explicitly points to nowhere.
 */
void test_null_pointers(void) {
	// A null pointer can be initialized in two ways, zero or nullptr
	char* p = 0;
	char* q = nullptr;

	// Many libraries define NULL as 0
	char* r = NULL;

	// Null pointers can be tested for equality
	assert(p == q);
	assert(q == r);

	// Dereferencing a null pointer results in segmentation fault
	// assert(*p == 0);
}

/**
 * Tests pointers to functions.
 */
void test_pointers_to_functions(void) {
	int x = operate(1, 2, add);
	int y = operate(3, 2, substract);
	assert(x == 3);
	assert(y == 1);

	int (*minus)(int, int) = substract;
	int z = operate(4, 2, minus);
	assert(z == 2);
}

void run_pointer_tests(void) {
	test_address_of_and_dereference_ops();
	test_pointers();
	test_pointer_vs_array();
	test_pointer_arithmetic();
	test_pointer_to_const();
	test_pointer_to_pointer();
	test_void_pointer();
	test_invalid_pointers();
	test_null_pointers();
	test_pointers_to_functions();
}

