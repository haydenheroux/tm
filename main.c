#include <stdio.h>

#include "tape.h"

int main() {
	int data[3] = {111, 222, 333};
	tape_t* tape = new_tape(40);
	set_tape(tape, data, 3);
	printf("%d %d %d\n", tape->tape[0], tape->tape[1], tape->tape[2]);
	delete_tape(tape);
	return 0;
}
