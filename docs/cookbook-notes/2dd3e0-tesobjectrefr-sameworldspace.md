# 0x2dd3e0 TESObjectREFR::SameWorldspace

<!-- tags: wall/control-flow, wall/register-schedule -->

- Function: 0x2dd3e0 TESObjectREFR::SameWorldspace
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: 148/284 (aligned_matching_bytes)
- Attempts: 3

## What differed

The candidate emitted a separate early epilogue for the interior-cell comparison and saved only two callee-saved registers before the interior check, whereas the target saves three callee-saved registers at entry and branches from the interior comparison directly into a shared tail epilogue after skipping the delayed fourth register restore.

## Spellings tried that did not help

- Calling an inline `GetWorldSpace()` helper on both references after the interior-cell early return.
- Expanding the first reference's worldspace lookup inline against the already-loaded `cell` local while calling `other->GetWorldSpace()` when `otherCell` is null.
- Inverting the `allowParent` and non-null worldspace guard around the parent-worldspace lookup.

## Spelling that fixed it

none
