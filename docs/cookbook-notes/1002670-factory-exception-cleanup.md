# 0x1002670 BSMultiBoundCapsule::Function1002670

<!-- tags: abi/exception, construct/allocation -->

- Function: 0x1002670 BSMultiBoundCapsule::Function1002670
- Label: GUESS(low)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: normalized distance 0.0; full comparator FAIL
- Attempts: 2

## What differed
The source reproduces the complete instruction sequence, but the exception state count differs. The source has an allocation-failure cleanup that is absent from the target metadata.

## Spellings tried that did not help
A class-scope allocation operator, an inline derived constructor and the observed scalar defaults reproduce the instructions. Resolving the language-runtime handler exposes the exception-state mismatch.

## Spelling that fixed it
none
