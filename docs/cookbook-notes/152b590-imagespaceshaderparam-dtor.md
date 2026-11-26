# 0x152b590 ImageSpaceShaderParam::dtor_deleting

<!-- tags: method/diagnostic -->

- Function: 0x152b590 ImageSpaceShaderParam::dtor_deleting
- Label: GUESS(low)
- Outcome: unsolved
- Cause: other (exception unwind map)
- Best score: 315/315 bytes
- Attempts: 3

## What differed

All bytes match. One unwind map action is empty in the target and present in the candidate.

## Spellings tried that did not help

A defaulted base destructor (removes the base vtable store) and an object array split into a base and a derived class.

## Spelling that fixed it

none
