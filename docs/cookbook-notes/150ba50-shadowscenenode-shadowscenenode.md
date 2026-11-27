# 0x150ba50 ShadowSceneNode::ShadowSceneNode

<!-- tags: abi/exception, construct/constructor, construct/bitfield, wall/flag-fold -->

- Function: 0x150ba50 ShadowSceneNode::ShadowSceneNode
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 1414/1436 aligned bytes
- Attempts: 7

## What differed
Everything but one spot matched after binding. The base constructor needs a stand-in layer that declares the constructor taking a child capacity and the name setter; the two out-of-line array destructors, the allocator destructor and the smart-pointer destructors are bound by address. The remaining difference is two single-bit sets on the node flag word with a float store between them: the target loads the word once, sets one bit in the register, stores the float, sets the second bit and stores the word; every spelling here merges the two sets into one OR with a two-bit constant.

## Spellings tried that did not help
- Plain `flags |= a; fade = 1.0f; flags |= b;` on the member: one OR on memory with a merged constant.
- The same through a local copy of the word, with and without a by-value bit-set helper: still merged.
- A bit-set intrinsic on a reference parameter: the local is spilled to the stack, worse.
- A bit-field struct for the flag word: same merged OR.

## Spelling that fixed it
none. Other moves that did help: a three-float point type whose default constructor zeroes its members (the value-initialised pairs then merge into 8-byte zero stores), the name passed as a temporary (the unwind slot then shares the temporary's stack slot), removing `noinline` from the array resize so it inlines into the constructor, and writing the `NiPointer` assignment form for the focus object with a local pointer for the two zero stores.
