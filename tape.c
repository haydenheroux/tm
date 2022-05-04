#include <stdio.h>
#include <stdlib.h>

#include "tape.h"

// Create a new tape.
// Returns a pointer to the created tape with exactly `slots` slots.
// Returns NULL on failure.
tape_t* new_tape(unsigned int slots) {
	if (slots == 0) {
		// Why allocate an empty tape?
		return NULL;
	}
	int* memory = (int*)calloc(slots, sizeof(int));
	if (memory == NULL) {
		return NULL;
	}
	tape_t* tape = (tape_t*)malloc(sizeof(tape_t));
	if (tape == NULL) {
		return NULL;
	}
	tape->tape = memory;
	tape->head = 0; // Sets the head at the "start" of the tape by default.
	tape->slots = slots;
	tape->highest_slot = slots - 1;
	return tape;
}

// Delete an existing tape.
// Returns 0 if `tape` was deleted successfully.
// Returns 1 on failure.
int delete_tape(tape_t* tape) {
	free(tape->tape);
	free(tape);
	return 0;
}

// Set the contents of a tape to replicate the layout of an existing data source.
// At most `slots` number of slots will be replicated from `data` to `tape`.
// The replicated slots will begin at the initial position of `tape->head`.
// Returns 0 if all slots were replicated successfully.
// Returns the number of slots successfully replicated on failure.
int set_tape(tape_t* tape, int* data, unsigned int slots) {
	int i, failed;
	failed = 0;
	for (i = 0; i < slots; i++) {
		if (tape->head > tape->highest_slot) {
			failed = 1;
			break;
		}
		tape->tape[tape->head] = data[i];
		tape->head++;
	}
	// FIXME: Replicating exactly `tape->slots` values results in out-of-bounds head.
	if (tape->head > tape->highest_slot) {
		tape->head = tape->highest_slot;
	}
	if (failed) {
		return i;
	}
	return 0;
}

// Print the contents of a tape, with the position of the head being highlighted.
// Returns 0 if the tape was printed successfully.
// Returns 1 on failure.
int print_tape(tape_t* tape) {
	int i;
	for (i = 0; i < tape->head; i++) {
		printf("%d,", tape->tape[i]);
	}
	printf("\033[7m%d\033[m", tape->tape[i++]);
	for (; i < tape->slots; i++) {
		printf(",%d", tape->tape[i]);
	}
	puts("");
	return 0;
}
