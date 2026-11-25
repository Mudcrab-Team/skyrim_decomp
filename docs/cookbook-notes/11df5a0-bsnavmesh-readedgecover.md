# 0x11df5a0 BSNavmesh::ReadEdgeCover

<!-- tags: construct/bitfield, method/diagnostic, wall/register-schedule -->

- Function: 0x11df5a0 BSNavmesh::ReadEdgeCover
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); ReadEdgeCover GUESS(low)
- Outcome: fixed
- Cause: integer-width-or-cast
- Best score: 91/91 aligned matching bytes; PC comparator pass
- Attempts: 3 counted comparisons; 4 invocations total, including binding-only and final-source provenance checks as applicable

## What differed

The packed flag extraction was complete at 84/91 aligned matching bytes, distance 1, with only two register-renaming edits. The temporary that holds the low four-bit cover value was declared as a 16-bit integer, and the differing instructions selected scratch registers differently.

## Spellings tried that did not help

The retained wider flag result draft scored 75/91. Narrowing the return temporary to 16 bits improved it to 84/91 but left the register residue. Ranked lesson retrieval described lifetime and declaration changes; it did not identify the narrower temporary directly.

## Spelling that fixed it

A bounded PC permutation search (one job, batch eight, 60-second budget) found the 8-bit temporary after 33 candidates. The selected source truncates the packed flags to an 8-bit local, masks its low four bits and returns it through the 16-bit return type. Tidying the cast to match the local width retained the PC comparator pass. The name remains an inference; this is a local candidate, not acceptance.
