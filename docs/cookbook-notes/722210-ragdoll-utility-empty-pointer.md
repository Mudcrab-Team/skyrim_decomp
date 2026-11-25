# 0x722210 ActorProcess::GetRagdollPenetrationUtil

<!-- tags: wall/control-flow, wall/inlining, construct/destructor, abi/virtual -->

- Function: 0x722210 ActorProcess::GetRagdollPenetrationUtil
- Label: SYMBOLS(fo4-pdb)
- Outcome: fixed
- Cause: branch-layout
- Best score: 95/95 exact, unwind covered; local PC comparator pass
- Attempts: 2 counted comparisons; 2 invocations total, including binding-only and final-source provenance checks as applicable

## What differed

Cookbook rule 40 previously left this target open because the ordinary null fallback lost a zero-initialized stack local before the pointer test. The preserved draft represents the fallback as a default-constructed intrusive pointer and passes the selected source by reference into its inline assignment helper. The local comparator passed the full function with unwind coverage.

## Spellings tried that did not help

No alternate spelling was compared in this run. The earlier cookbook diagnosis describes the unresolved null-path shape; this run retained the interrupted draft rather than recreating that unsuccessful form.

## Spelling that fixed it

Create a const empty pointer wrapper, select the member wrapper or that empty wrapper as a reference, assign through the inline retain-and-release helper, and then test the output pointer. The local empty object naturally accounts for the initialized stack slot. This is one local pass candidate, pending independent review and second-host verification.
