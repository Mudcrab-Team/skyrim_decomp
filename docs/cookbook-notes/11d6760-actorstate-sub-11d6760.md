# 0x11d6760 ActorState sub_11d6760

- Function: 0x11d6760 ActorState sub_11d6760
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: loop-shape
- Best score: 35/69 bytes matching
- Attempts: 4

## What differed

The target zero-fills a five-element 8-byte local with a rolled loop plus a trailing 32-bit store. Every spelling gives unrolled or vector stores. 0x11d67b0 is a twin and was not attempted.

## Spellings tried that did not help

Aggregate init, a constructor loop, an element class with a constructor.

## Spelling that fixed it

none
