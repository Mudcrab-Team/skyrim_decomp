# 0x52cf60 TESWaterSystem::FindReflection

<!-- tags: construct/bitfield, construct/loop, wall/control-flow, wall/flag-fold -->

- Function: 0x52cf60 TESWaterSystem::FindReflection
- Label: GUESS(low)
- Outcome: unsolved
- Cause: constant-folding
- Best score: 11/94 matching bytes; best structural distance 11.0 was a different draft, not a byte match
- Attempts: 4

## What differed

The inferred reflection lookup walks the reflection pointer array and tests separate flag bits for the two filter cases. The target reads one byte of each flag word, repeats the filter test, and reloads the array before the second flag query. The closest exact-byte drafts still folded work and compiled to 81 or 82 bytes against the 94-byte target. Identity and the semantic meaning of the filter remain guesses.

## Spellings tried that did not help

- Two separate early returns with direct flag masks: 81 bytes, 11/94 matching bytes.
- A by-value word-sized bit query: 58 bytes, 2/94 matching bytes.
- A by-value byte-sized bit query: 82 bytes, 11/94 matching bytes; this represents the observed read width.
- One disjunction sharing the return: 71 bytes, 8/94 matching bytes, structural distance 11.0. It still omits repeated work.

## Spelling that fixed it

none. Stopped after three counted comparisons without an improvement over the first exact-byte diagnostic. This extends cookbook rule 41 with a byte-width observation; it does not establish a compiler fix. The byte-query draft is retained for the next investigation.
