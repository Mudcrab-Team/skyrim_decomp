# 0xfc7fd0 QueuedNamedFile::GetName

<!-- tags: abi/calling-convention, method/binding, wall/register-schedule -->

- Function: 0xfc7fd0 QueuedNamedFile::GetName
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 32/55 matching bytes; alignment distance 4.0; candidate size 55 bytes
- Attempts: 5

## What differed
The routine copies a nullable filename into a bounded output buffer and returns whether a filename was present. The target preserves the narrow nonnull predicate across the copy call; the closest handwritten spelling keeps the original pointer and computes the return predicate afterward. Both reference bindings were checked against the local pack before diagnosing the remaining lifetime and ordering differences. The best candidate has the target extent but is not a byte match.

## Spellings tried that did not help
A full-width integer return produced a 57-byte candidate. Selecting the fallback pointer into an explicit local did not improve the score. A Boolean return reduced the extent to 55 bytes, without improving the matching-byte count. Reassigning the filename local to its fallback produced a 61-byte candidate and reduced the score to 25/55. A one-worker bounded permutation tried 81 candidates and left distance 5.0 unchanged before the Boolean-return experiment. Three consecutive comparisons did not improve the best matching-byte score, so the draft stopped within its six-compare cap. No available indexed lesson applied; the cookbook's source-order rule was only a diagnostic lead.

## Spelling that fixed it
None. The Boolean-return draft is retained as the best measured candidate; all failed source snapshots and reports remain private. The name comes from community-generated CrashLogger metadata; the body is original from pinned-build observations, with no adapted sibling body. Missing compiled-sibling indexes prevented shape retrieval and are not evidence about this function.
