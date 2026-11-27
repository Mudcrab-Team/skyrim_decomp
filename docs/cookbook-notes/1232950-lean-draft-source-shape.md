# 0x1232950 MovementTweenerAgentAnimationDriven::Function1232950

<!-- tags: abi/virtual, construct/destructor, method/binding -->

- Function: 0x1232950 MovementTweenerAgentAnimationDriven::Function1232950
- Label: GUESS(low)
- Outcome: fixed
- Cause: vtable-or-virtual
- Best score: 51/51 aligned bytes; local comparator PASS
- Attempts: 2 verifier invocations, 1 counted; permutation candidates are separate

## What differed

The guessed queue name did not identify the defined destructor, so the first attempt stopped at symbol binding.

## Spellings tried that did not help

The ambiguous compared-function header could not bind the intended destructor.

## Spelling that fixed it

Use genuine primary and secondary C++ bases and identify the non-deleting destructor in the compared-function header and bind hints. The secondary base is destroyed before the primary base. The normal comparison passed.

This is first-host candidate evidence; a second host, independent review and integration remain required.
