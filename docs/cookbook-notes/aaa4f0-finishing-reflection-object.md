# 0xaaa4f0 hkSimpleLocalFrame::Functionaaa4f0

<!-- tags: method/sibling, sibling/f3, construct/constructor -->

- Function: 0xaaa4f0 hkSimpleLocalFrame::Functionaaa4f0
- Label: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0)
- Outcome: fixed
- Cause: struct-layout
- Best score: PC comparator PASS (all checks passed)
- Attempts: 4

## What differed

The reflection query constructs a finishing object and returns its virtual table. The finishing member and object alignment are part of the observable construction.

## Spellings tried that did not help

No separate unaligned trial is claimed. The adapted finishing-object shape was verified against the target; the alignment and member constructor remain explicit.

## Spelling that fixed it

Adapt the cited sibling finishing-object pattern, retain explicit alignment and the finishing member, and verify against the pinned target independently.
