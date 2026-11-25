# 0x1555fd0 BSFadeNodeCuller::Process1

<!-- tags: abi/virtual, construct/float, construct/loop, method/diagnostic, method/sibling, wall/register-schedule -->

- Function: 0x1555fd0 BSFadeNodeCuller::Process1
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 137/195 aligned matching bytes; distance 2.5; 47 instructions on both sides; comparator FAIL
- Attempts: 6 counted comparisons; 6 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
The best candidate has the same instruction shape as the target, but three integer temporaries occupy different registers. Operand load order initially also differed. An original body was drafted using authorized local binary analysis, community declarations, and a permitted sibling body read as a shape lead. The sibling is not evidence about this build.

## Spellings tried that did not help
- Initial indexed-plane loop: 106/195.
- Reversing the first two product terms: unchanged at 106/195.
- The documented fast-float recipe: 111/195; reversing the product spelling again was unchanged.
- A bounded permutation searched 257 candidates and swapped the x/y local declarations: 137/195 on comparison five, distance 2.5, register-only residue.
- Explicit plane-pointer iteration regressed to 108/195, distance 7.5 on comparison six.

## Spelling that fixed it
None. The declaration-order change improved the candidate but did not pass. The six-comparison cap ended drafting. The exact comparison-five snapshot, worse sixth draft, and search history remain private. A later label-grammar correction passed source checks but was not compared after the cap; the unit is withheld from passing-source publication.
