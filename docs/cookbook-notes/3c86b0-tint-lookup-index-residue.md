# 0x3c86b0 TESNPC::Function3c86b0

<!-- tags: construct/loop, wall/register-schedule, wall/control-flow -->

- Function: 0x3c86b0 TESNPC::Function3c86b0
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 41/68 matching bytes; alignment distance 3.5
- Attempts: 4 counted comparisons; 81 one-worker permutation candidates

## What differed

The bounded tint-layer search has the observed lookup and result-selection structure, but the best candidate is 64 bytes against a 68-byte target. Alignment identifies a missing index copy, one width difference and inconsistent scratch-register assignments. This is a near miss, not a match.

## Spellings tried that did not help

The best source tests the result before the bound and selects a null pointer on a nonmatching tint index. Testing the bound first and assigning the result before clearing it increased distance to 15.5. A 64-bit counter narrowed at both uses increased distance to 5.0. Copying and incrementing the index before lookup gave distance 4.0. The bounded one-worker permutation search retained distance 3.5 after 81 candidates. Rule 44 motivated the index-copy spelling, but did not close this function.

## Spelling that fixed it

None. The best measured first draft is retained. Stop: three consecutive counted comparisons without improvement.
