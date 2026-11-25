# 0x637e10 BGSLoadFormBuffer::ReadEncodedValue

<!-- tags: construct/serialization, construct/switch, method/diagnostic, wall/register-schedule -->

- Function: 0x637e10 BGSLoadFormBuffer::ReadEncodedValue
- Label: GUESS(low)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 68/83 aligned matching bytes; comparator FAIL, function-size-mismatch
- Attempts: 6 counted comparisons; 6 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
The best complete draft preserves the three storage widths and advances the buffer position after reading,
then removes the two tag bits from the returned value. The remaining candidate retains the tag load for
reuse in the byte case and calculates the current pointer in a different register order. The comparator
still rejects its function extent. This score is diagnostic, not a byte match.

## Spellings tried that did not help
The interrupted first draft advanced before reading and omitted the decoded-value shift; its preserved
score was 15/83. Loading each value before the advance and returning the shifted value reached 25/83.
Using unaligned-safe memcpy with a correctly sized local reached 45/83. Using the community void pointer
declaration and a signed char cursor reached 68/83. A two-bit tag field and separate pointer increment
fell back to 45/83. The bounded PC permuter used one job, batch eight and budget sixty seconds: 241
candidates, 63 distinct objects, best distance unchanged at 5.0. It stopped on patience. The finalized
best draft was compared again at attempt six, still 68/83 and FAIL. Label, origin and lint checks passed.
Cookbook rule 6 was retrieved as a lead but did not supply a closing spelling.

## Spelling that fixed it
none
