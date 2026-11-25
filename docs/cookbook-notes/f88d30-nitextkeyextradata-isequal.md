# 0xf88d30 NiTextKeyExtraData::IsEqual

<!-- tags: construct/float, construct/loop, method/diagnostic, wall/register-schedule -->

- Function: 0xf88d30 NiTextKeyExtraData::IsEqual
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 116/127 aligned matching bytes; distance 1; size 127/127
- Attempts: 5

## What differed

The original body checks the argument and base equality, compares the key count, then compares each key's scalar time and interned string pointer. The best draft has the same size, call set and branch shape, with one register-allocation difference remaining. This is a diagnostic score, not a byte match. Names use the community-generated source above; the body is original from local target observations, with no sibling body exposure.

## Spellings tried that did not help

The first draft compared the receiver's time first and reached 98/127 matching bytes. A bounded single-worker permutation search scored 153 candidates and improved the result by comparing the peer's time first. Reversing the string-pointer comparison, naming references to both keys, and an inline key equality helper did not improve the best result. Five counted comparisons stopped after three consecutive non-improvements.

## Spelling that fixed it

none
