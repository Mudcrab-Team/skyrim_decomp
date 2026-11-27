# 0xf1e8a0 NiBackToFrontAccumulator::Slot39

<!-- tags: construct/destructor, wall/register-schedule -->

- Function: 0xf1e8a0 NiBackToFrontAccumulator::Slot39
- Label: GUESS(low)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 179/213 aligned matching bytes
- Attempts: 2

## What differed

The accumulator teardown reaches the target size and pairs the body registers consistently, but exchanges two saved nonvolatile registers.

## Spellings tried that did not help

Changing the exception recipe and destructor exception specification retained the save-register exchange.

## Spelling that fixed it

None.
