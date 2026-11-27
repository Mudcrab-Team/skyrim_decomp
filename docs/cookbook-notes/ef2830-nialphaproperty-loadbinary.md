# 0xef2830 NiAlphaProperty::LoadBinary

<!-- tags: method/diagnostic, wall/layout, wall/register-schedule -->

- Function: 0xef2830 NiAlphaProperty::LoadBinary
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 120/136 aligned matching bytes; distance 1; size 136/136
- Attempts: 5

## What differed

The body loads the base property, then reads the flags and alpha reference through the stream's callback while advancing its position. Modelling that callback as a virtual method added two unnecessary loads and six bytes. A callback member corrected the size. The remaining difference swaps the preparation order of a local component-size store and the outgoing component-count store. Both store the same value to their respective destinations; no byte match was obtained. The body is original from local target observations; community-generated names do not establish identity. No sibling body was read.

## Spellings tried that did not help

Reusing one component-size local, separate scoped size locals, a typed stream-read helper, and a one-element component-size array all retained the best store-order residue. Five counted comparisons stopped after three consecutive non-improvements. A bounded single-worker permutation search then scored 81 candidates, retaining distance 1 without improvement.

## Spelling that fixed it

none
