#pragma once

typedef struct {
	int* tape;
	unsigned int head;
	unsigned int slots;
} tape_t;

// Create a new tape.
// Returns a pointer to the created tape with exactly `slots` slots.
// Returns NULL on failure.
tape_t* new_tape(unsigned int slots);

// Delete an existing tape.
// Returns 0 if `tape` was deleted successfully.
// Returns 1 on failure.
int delete_tape(tape_t* tape);

// Set the contents of a tape to replicate the layout of an existing data source.
// At most `slots` number of slots will be replicated from `data` to `tape`.
// The replicated slots will begin at the initial position of `tape->head`.
// Returns 0 if all slots were replicated successfully.
// Returns the number of slots successfully replicated on failure.
int set_tape(tape_t* tape, int* data, unsigned int slots);

// Print the contents of a tape, with the position of the head being highlighted.
// Returns 0 if the tape was printed successfully.
// Returns 1 on failure.
int print_tape(tape_t* tape);
