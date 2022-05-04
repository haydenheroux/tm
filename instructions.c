#include "instructions.h"
#include "tape.h"

// Move the head of the tape machine `slots` slots in a direction.
// Automatically wraps out-of-bounds movement to the other side of the tape.
// `right` is 1 if the head should move to the right, 0 if the head should move to the left.
void go(tape_t* tape, int right, int slots) {
	for (int i = slots; i > 0; i--) {
		if (tape->head == tape->highest_slot && right) {
			tape->head = 0;
			continue;
		}
		if (tape->head == 0 && !right) {
			tape->head = tape->highest_slot;
			continue;
		}
		if (right) {
			tape->head++;
		} else {
			tape->head--;
		}
	}
	return;
}
