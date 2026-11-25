# 0xf983f0 NiFloatController::Functionf983f0

<!-- tags: wall/register-schedule, method/diagnostic -->

- Function: 0xf983f0 NiFloatController::Functionf983f0
- Label: GUESS(low)
- Outcome: fixed
- Cause: other
- Best score: 41/41 aligned matching bytes, local comparator pass
- Attempts: 2 fresh original-draft comparisons

## What differed

The first fresh draft read the controller's data member separately for the null test and each output. It measured 17/41 aligned matching bytes. The target observations describe one nullable data pointer supplying a count, type, stride and returned key array; a null source clears all three outputs. The community declarations supply field names and layout leads, not the body.

## Spellings tried that did not help

Repeated direct access through the controller member did not match. No instruction or register forcing was used.

## Spelling that fixed it

Read the data member into a local pointer, then use that local throughout the conditional and output assignments. This measured 41/41 and passed the unchanged comparator. The measured result supports this source spelling; it does not establish the compiler's alias-analysis rationale. This is an original draft from the authorized target observations and CommonLibSSE-NG declarations at b93280e (MIT), with no adapted body. Historical task counters remain intact privately; these two comparisons refer only to this fresh draft. A local pass is a candidate, not acceptance.
