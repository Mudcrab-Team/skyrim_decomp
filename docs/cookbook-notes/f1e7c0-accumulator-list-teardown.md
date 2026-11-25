# 0xf1e7c0 NiBackToFrontAccumulator::~NiBackToFrontAccumulator

<!-- tags: construct/destructor, construct/loop, wall/register-schedule -->

- Function: 0xf1e7c0 NiBackToFrontAccumulator::~NiBackToFrontAccumulator
- Label: EXE_RTTI
- Outcome: fixed
- Cause: register-allocation
- Best score: 214/214 aligned matching bytes
- Attempts: 5

## What differed

The destructor releases the two sorting buffers, removes list heads while the count is nonzero, and then runs the list member’s destructor. The first draft matched the count-controlled loop. In the member destructor it kept the current node in the argument register and moved the next node after deletion.

## Spellings tried that did not help

Saving the successor as a temporary and updating the cursor after deleting the node kept the function length and changed the register allocation in the second loop.

## Spelling that fixed it

Keep the cursor on the next node before deletion. Save the old cursor, advance through its next link, clear the old node’s item, and delete the old node. The local comparator first passed on the second attempt.
