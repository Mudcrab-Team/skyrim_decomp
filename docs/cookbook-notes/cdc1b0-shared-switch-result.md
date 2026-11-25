# 0xcdc1b0 BSXAudio2DataSrc::GetSampleCount

<!-- tags: construct/switch, wall/control-flow, method/diagnostic -->

- Function: 0xcdc1b0 BSXAudio2DataSrc::GetSampleCount
- Label: CRASHLOGGER_PDB(59818@2026.10.24); GUESS(low)
- Outcome: fixed
- Cause: branch-layout
- Best score: comparator PASS; 83/83 code bytes, no unwind entry in range
- Attempts: 5 counted comparisons; 5 invocations total, including binding-only and final-source provenance checks as applicable

## What differed

The initial switch returned directly from each format arm. It matched 76/83 bytes at alignment distance 1.5, with the final format check selecting the opposite branch polarity and exchanging the final two return blocks. These observations concern sse-steam-1-7-104 only. The method name is a behavioral guess, and the layout names come from the community-generated CrashLogger source; neither establishes identity.

## Spellings tried that did not help

A chain of early-return conditions grew to 94 bytes and distance 18. Keeping the switch but using a break for its final arm and returning that field after the switch retained distance 1.5. The bounded PC permuter exhausted its pool after 185 candidates and three unique objects, without improving that distance.

## Spelling that fixed it

Initialize one unsigned result to zero, assign it in each recognized switch arm, and return it after the switch. The fourth comparison passed; the fifth passed after final field-name provenance corrections. This ordinary shared-result form follows cookbook rule 2's control-flow guidance; the body was written originally rather than copied from another source.
