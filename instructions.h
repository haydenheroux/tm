#pragma once

#include "tape.h"

// Move the head of the tape machine `slots` slots in a direction.
// Automatically wraps out-of-bounds movement to the other side of the tape.
// `right` is 1 if the head should move to the right, 0 if the head should move to the left.
void go(tape_t* tape, int right, int slots);
