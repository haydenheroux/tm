#include <stdio.h>

#include "instructions.h"
#include "tape.h"

int main() {
	int data[3] = { 1, 2, 3 };
	tape_t* tape = new_tape(3);
	printf("%d\n", set_tape(tape, data, 3));
	print_tape(tape);
	printf("%d\n", set_tape(tape, data, 3));
	print_tape(tape);
	printf("%d\n", set_tape(tape, data, 3));
	print_tape(tape);
	delete_tape(tape);
	return 0;
}
