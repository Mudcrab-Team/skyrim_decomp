# 0x2b6540 Unk2b6540::Function2b6540

<!-- tags: construct/float, construct/vector, method/diagnostic -->

- Function: 0x2b6540 Unk2b6540::Function2b6540
- Label: GUESS(low)
- Outcome: fixed
- Cause: float-codegen
- Best score: 122/122 aligned bytes; local comparator PASS
- Attempts: 2 verifier invocations, 2 counted; permutation candidates are separate

## What differed

The first source cached all three vector components before computing the norm. Its function extent differed.

## Spellings tried that did not help

A fast floating-point recipe was already selected; retaining the named component temporaries still failed. A single-worker search tried 49 candidates over 3 rounds; its diagnostic distance changed from 14.5 to 0.0, stopping at distance-0.

## Spelling that fixed it

Use the component fields directly in the norm expression and in each scaled assignment. A bounded search found this source form, and a normal comparison of the cleaned source passed.

This is first-host candidate evidence; a second host, independent review and integration remain required.
