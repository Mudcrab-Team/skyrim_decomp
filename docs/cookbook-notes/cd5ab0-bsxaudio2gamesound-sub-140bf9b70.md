# 0xcd5ab0 BSXAudio2GameSound::sub_140BF9B70

<!-- tags: wall/register-schedule, construct/float -->

- Function: 0xcd5ab0 BSXAudio2GameSound::sub_140BF9B70
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 54/57 (aligned_matching_bytes)
- Attempts: 5

## What differed

Under `o2-fpfast`, the candidate matches size and every instruction except the order of two adjacent instructions in the upper-clamp branch: the compiler hoists loading the vtable pointer from `this` above the immediate store of `1.0f` to `volume`, whereas the target stores `1.0f` before loading the vtable pointer for the tail call. In the lower-clamp branch the compiler preserves the store-before-load order because the fallthrough path joins at the vtable load.

## Spellings tried that did not help

- Storing `volume = a_volume;` then `if (a_volume > 1.0f) { volume = 1.0f; } else if (a_volume < 0.00001f) { volume = 0.00001f; } Unk_18();`: same size, vtable load hoisted above the `1.0f` store.
- Early return with duplicated tail call `if (a_volume > 1.0f) { volume = 1.0f; Unk_18(); return; }`: identical output to the `else if` form.
- Testing the member (`if (volume > 1.0f)`) instead of the parameter: identical output.
- Clamping `a_volume` first and storing `volume = a_volume;` once before `Unk_18();`: folds into a shorter 31-byte sequence without the duplicated tail call.
- Reversing the outer test (`if (a_volume <= 1.0f) { ... } else { volume = 1.0f; }`): keeps the store before the vtable load in the `1.0f` branch, but flips the branch order and hoists the vtable load in the lower-clamp branch instead.

## Spelling that fixed it

none
