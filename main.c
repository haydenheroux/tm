#include <stdio.h>

#include "tape.h"

int main() {
	tape_t* tape = new_tape(3);
	print_tape(tape);
	delete_tape(tape);
	return 0;
}
