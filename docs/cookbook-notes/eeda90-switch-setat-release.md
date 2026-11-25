# 0xeeda90 NiSwitchNode::SetAt2

<!-- tags: abi/exception, abi/virtual, construct/destructor, wall/register-schedule, method/binding -->

- Function: 0xeeda90 NiSwitchNode::SetAt2
- Label: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
- Outcome: fixed
- Cause: prologue-epilogue
- Best score: comparator PASS, 74/74 matching bytes; earlier 35/74 and 55/74
- Attempts: 5 counted comparisons, 6 invocations including one binding-only failure; one bounded permutation search

## What differed
The child-replacement wrapper obtains an owning result through a virtual out-parameter, then releases it atomically. The initial release reread the owning pointer after the atomic operation. Caching the object removed that reload and reduced alignment distance from 4.5 to 1.5, but the temporary still occupied a different home slot. Local vtable metadata and public override declarations support NiSwitchNode::SetAt2; a conflicting CrashLogger name hint was not adopted.

## Spellings tried that did not help
The cached object with an exchange-add comparison retained the temporary-slot difference. A one-worker PC permutation search exhausted its pool after 69 candidates without improving distance 1.5. The next body reached 74/74 bytes but its exception-cleanup destructor reference remained unbound. Later comparisons reconfirmed provenance-only source revisions.

## Spelling that fixed it
Cache the released object, name the result of the atomic decrement, and test the resulting count for zero before virtual deletion, following cookbook rule 29 and the existing temporary-detachment lesson. Use the public NiNode virtual declaration chain and the NiSwitchNode override declaration. Bind the owning-pointer cleanup only after confirming that the pack reference performs atomic ownership release with virtual deletion. All bodies were handwritten from local observations and existing project-authored helpers; no excluded sibling middleware body was read or reused. Local PASS is candidate evidence only.
