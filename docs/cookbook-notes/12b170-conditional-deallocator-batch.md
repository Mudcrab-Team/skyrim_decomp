# 0x12b170 ConditionalDeallocators::Delete12b170

<!-- tags: construct/allocation, abi/calling-convention, method/binding -->

- Function: 0x12b170 ConditionalDeallocators::Delete12b170
- Label: GUESS(low) STANDIN
- Outcome: fixed
- Cause: calling-convention
- Best score: 59 of 59 family members passed the native Windows comparator
- Attempts: 1 per member

## What differed

No mismatch occurred in this batch. The existing conditional-deallocator generator produced 59 complete
functions, including this representative. Each preserves the object argument, tests the low flag bit,
conditionally calls its independently bound sized deallocator, and returns the object. The comparator
checked each function's code, call target and unwind information on the native Windows host.

Names, ownership and original signatures remain unknown. These are labelled static ABI stand-ins;
the conditional source form does not establish an original class or destructor identity.

## Spellings tried that did not help

None. The existing source template passed on the first attempt for every selected member.

## Spelling that fixed it

Retain the explicit low-bit test, a 32-bit unsigned flag argument and a 64-bit unsigned size argument
to the declared deallocator. Preserve and return the pointer after the conditional call. Extract the
size and bind the deallocator separately for every member rather than transferring a reference from
another function. The template is in `tools/conditional_dealloc_generate.py`; family background is
in `findings/conditional-deallocators.md`. This batch adds one-host candidate evidence; acceptance
still requires the bot's two-host comparison and independent review.
