#include <cassert>
#include <cstring>
#include <string>
#include <vector>

/*
 * A type alias is an alias to an already existing type. Type aliases can be
 * used to reduce the length of long type names. For example, instead of
 * 'unsigned long' one could create the 'ulong' type alias.
 *
 * Type aliases can also be used to create abstract types. For example, instead
 * of using 'int' directly one could create a type alias 'number'. One advantage
 * is that if 'int' was found to not have a large enough capacity, one would
 * have to change the meaning of 'number' only once to a type with larger
 * capacity, such as 'long'.
 */

/*
 * The original style was borrowed from C.
 */
typedef char Char;
typedef const char* CString;
typedef std::string String;

/*
 * The preferred new C++11 type alias syntax has an advantage over templates.
 * Some aliases involving templates are much easier to achieve with the new
 * syntax. Both styles have the same semantics, meaning they are equivalent.
 */
using Int = int;
using Long = long;
template<class T> using Pointer = T*;

void test_typedef(void) {
	Char x = 'a';
	CString cstr = "test";
	String str = "test";

	assert(x == 'a');
	assert(strcmp(cstr, "test") == 0);
	assert(str.compare("test") == 0);
}

void test_using(void) {
	Int i = 1;
	Long l = 1L;
	Pointer<int> j = &i;

	assert(i == 1);
	assert(l == 1);
	assert(*j == i);
}

void run_type_aliases_tests(void) {
	test_typedef();
	test_using();
}
