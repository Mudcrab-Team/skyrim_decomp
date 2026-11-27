# 0xef2830 NiAlphaProperty::LoadBinary

<!-- tags: construct/serialization, abi/calling-convention, wall/register-schedule -->

- Function: 0xef2830 NiAlphaProperty::LoadBinary
- Label: none
- Outcome: unsolved
- Cause: instruction-order
- Best score: 28/30 aligned instructions; distance 1.0, two displacement hunks
- Attempts: 2 counted comparisons

## What differed

Two reads go through a virtual stream call, each with a one-element count in a local and a literal one on the stack. For the second read the target stores the local before the literal one; the draft stores the literal first. Everything else, including the first read, agrees.

## Spellings tried that did not help

- Two braced blocks, each declaring its own local.
- One local assigned twice, with no blocks.
- A bounded permutation search found no object closer than the start; its pool is exhausted at once because the body is two statements.

- A counted read with the element count taken from the local (`Read(..., &size, size)`), a templated load helper for both reads and a single reused local all kept the two stores in the draft's order. The target's second read puts the local store directly after the address computation of the destination, before the previous read's byte count is added; the draft sinks that store to just before the call.

## Spelling that fixed it

None. The sibling near-miss in the save buffer writer shows the opposite order for the same two stores, so the order depends on something around the call rather than on the local's scope. Candidates not yet tried: the count local declared before the base-class call, or a typed count parameter in the stream wrapper.
