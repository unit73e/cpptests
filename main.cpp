#include "array_tests.h"
#include "char_seq_tests.h"
#include "pointer_tests.h"
#include "dynamic_memory_tests.h"
#include "data_structures_tests.h"
#include "type_aliases_tests.h"
#include "union_tests.h"
#include "enumerated_types_tests.h"

int main(void) {
	run_array_tests();
	run_char_seq_tests();
	run_pointer_tests();
	run_dynamic_memory_tests();
	run_data_structures_tests();
	run_type_aliases_tests();
	run_union_tests();
	run_enumerated_types_tests();

	return 0;
}
