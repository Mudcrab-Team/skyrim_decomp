# 0xebf7a0 Archive::set_endian_swap

<!-- tags: wall/register-schedule, wall/control-flow -->

- Function: 0xebf7a0 Archive::set_endian_swap
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: fixed
- Cause: instruction-order
- Best score: local comparator PASS, 47/47 bytes
- Attempts: 3 counted comparisons; 3 invocations total, including binding-only and final-source provenance checks as applicable

## What differed

Two independently selected callback temporaries produced interleaved selection and member stores. The target groups both selections before writing the callback members. Callback roles are inferred; the local byte match does not establish their names.

## Spellings tried that did not help

- Separate write and read callback ternaries: the compiler selected and stored the read callback first.
- A shared branch testing the inverse condition and assigning the write member first: callback selection direction and store order differed.

## Spelling that fixed it

Use one branch on the positive swap flag. In each arm assign the read callback, then the write callback. This exposes the paired selection to the optimizer and matches the local comparator. A bounded one-job permutation run on this spelling reported zero initial distance; a subsequent ordinary attempt supplied the actual PASS.
