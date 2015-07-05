#include <cassert>

enum RGB {
	Red, Green, Blue
};

enum Weekday {
	Monday = 1, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
};

enum class Month {
	January,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

// It is possible to specify the size of an enumeration class type
enum class Planet
	: char {
		Mercury, Venus, Earth, Mars, Jupiter, Saturn, Uranus, Neptune
};

/**
 * Tests enumeration types
 */
void test_enum() {
	assert(Blue != Red);
	assert(Blue == Blue);

	RGB rgb = Red;
	assert(rgb != Green);

	// All members of an enumeration are numbers, starting from 0
	assert(Red == 0);

	// It is also possible to specify the number of a member of an enumeration
	assert(Monday == 1);

	// If no explicit numbering has been given to other members of the
	// enumeration, they will have the number of the previous member plus one.
	assert(Tuesday == 2);

	// Enumerations can also be used in a switch (and often are)
	RGB w = Red;
	switch (w) {
	case Red:
		assert(w == 0);
		break;
	case Green:
		assert(w == 1);
		break;
	case Blue:
		assert(w == 2);
		break;
	default:
		break;
	}
}

/**
 * Tests enumeration classes
 */
void test_enum_class(void) {
	/**
	 * Unlike an enumeration type an enumeration class is not an integer.
	 */

	// To access a enumeration class member, one must call by its scope
	Month month = Month::January;
	assert(month == Month::January);

	// By default the size of an enumeration class is that of an 'int' but it
	// is possible to specify the size of the enumeration class
	assert(sizeof(Month) == sizeof(int));
	assert(sizeof(Planet) == sizeof(char));
}

void run_enumerated_types_tests(void) {
	test_enum();
}
