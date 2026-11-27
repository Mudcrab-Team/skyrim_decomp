# 0xeac790 allocation size temporary

<!-- tags: abi/calling-convention, construct/allocation, wall/register-schedule -->

- Function: 0xeac790 allocation size temporary
- Label: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0)
- Outcome: fixed
- Cause: calling-convention
- Best score: PC comparator pass, 89-byte extent including unwind
- Attempts: 5

## What differed
The size and alignment were both correctly pointer-sized, but the incoming size parameter occupied the wrong home slot and its clamped value survived in the wrong register.

## Spellings tried that did not help
Changing the incoming parameter itself to one when it was zero.

## Spelling that fixed it
Leave the incoming parameter unchanged. Declare the alignment first and a separate size_t bytes initialized from the clamped incoming size, then pass both locals by reference to Allocate. This complements cookbook rule 68: correct widths alone do not establish the address-taken local lifetime.
