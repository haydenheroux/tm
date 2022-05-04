#include <stdio.h>

#include "instructions.h"
#include "tape.h"

int main() {
	tape_t* tape = new_tape(4);
	go(tape, 1, 6);
	go(tape, 0, 4);
	print_tape(tape);
	delete_tape(tape);
	return 0;
}
