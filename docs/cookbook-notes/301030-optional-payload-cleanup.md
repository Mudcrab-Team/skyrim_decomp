# 0x301030 TESObjectREFR::Function301030

<!-- tags: wall/control-flow, method/diagnostic -->

- Function: 0x301030 TESObjectREFR::Function301030
- Label: GUESS(low)
- Outcome: fixed
- Cause: branch-layout
- Best score: 87/87 matching bytes; local comparator PASS (first draft 85/87, aligned distance 0.5)
- Attempts: 2

## What differed

The first draft combined the outer extra-node test and its payload test. This incorrectly made the list-removal helper conditional on the payload being present. The target removes an existing extra node even when its optional payload is absent. Both drafts had the same call set and instruction count, so the small diagnostic distance did not imply register-only residue.

## Spellings tried that did not help

A single `if (extra && extra->payload)` guarded both the payload callback and the list-removal helper. It compared at 85/87 matching bytes with one branch-layout difference.

## Spelling that fixed it

Use an outer `if (extra)` and an inner payload check around only the callback, leaving list removal in the outer block. Cookbook rule 2's control-flow diagnostic led to this correction. The second comparison passed locally. The body is original target-observation reconstruction; helper names and payload types remain guesses. Naming and declaration exposure includes community headers and permitted anonymous sibling game-code names; no sibling body supplied this implementation. A local pass remains a candidate pending independent verification and review.
