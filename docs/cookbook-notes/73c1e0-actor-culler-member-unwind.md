# 0x73c1e0 HighActorCuller::~HighActorCuller

<!-- tags: construct/destructor, abi/exception -->

- Function: 0x73c1e0 HighActorCuller::~HighActorCuller
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: 317/347 aligned matching bytes
- Attempts: 1

## What differed

The destructor reaches the target size and its cleanup body aligns. The saved-register locations in the prologue and epilogue differ.

## Spellings tried that did not help

Modelling the subobjects as destructor-bearing members recovered the cleanup sequence but left the unwind record different.

## Spelling that fixed it

None.
