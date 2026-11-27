# 0x2b96b0 TESObjectCELL::GetGroupSubBlockKey

<!-- tags: wall/control-flow, wall/inlining -->

- Function: 0x2b96b0 TESObjectCELL::GetGroupSubBlockKey
- Label: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb)
- Outcome: fixed
- Cause: integer-width-or-cast
- Best score: 79/79 code bytes; comparator PASS, unwind none in range
- Attempts: 2 counted comparisons after a structural pass

## What differed
The candidate was 91 bytes against 79: the exterior coordinate pack (two shifts, a shift left and a merge of the halves) was duplicated on both the null-coordinates path and the data path, while the target has one shared copy after the join. The listing showed one extra sign extension in the target in front of the left shift, which the draft lacked.

## Spellings tried that did not help
- Earlier drafts reshaped the null test and the join (branch layout) and kept the duplicate.

## Spelling that fixed it
Cast the shifted x index to `std::int16_t` before the shift left, as the packed key stores a signed 16-bit block x and an unsigned 16-bit block y. The extra sign extension makes the packed tail too large to duplicate, so the compiler shares it after the join; no control-flow edit is needed. Lesson: when a tail is duplicated in the candidate and shared in the target, look for a width or sign cast that makes the tail bigger before restructuring branches.
