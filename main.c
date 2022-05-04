#include <stdio.h>

#include "tape.h"

int main() {
	int data[3] = {111, 222, 333};
	tape_t* tape = new_tape(3);
	tape->head++;
	printf("set_tape(): %d\n", set_tape(tape, data, 2));
	tape->head = 0;
	printf("set_tape(): %d\n", set_tape(tape, data, 2));
	printf("tape->tape: %d %d %d\n", tape->tape[0], tape->tape[1], tape->tape[2]);
	printf("tape->slots: %d\n", tape->slots);
	delete_tape(tape);
	return 0;
}
