# 0xee1d10 NiNode::DetachChild2

<!-- tags: abi/exception, abi/virtual, construct/destructor, wall/register-schedule, method/binding -->

- Function: 0xee1d10 NiNode::DetachChild2
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: fixed
- Cause: prologue-epilogue
- Best score: comparator PASS; initial 35/74, then 55/74, then 74/74 matching bytes
- Attempts: 5 invocations, including one binding-only failure; one bounded permutation search

## What differed
The function dispatches child detachment into a temporary owning pointer. Its cleanup atomically releases that result. The first draft reread the owning pointer after the atomic operation and used a different temporary home slot. Caching the object removed the reload and reduced alignment distance from 4.5 to 1.5, with no reported behavioral-value mismatch. Published virtual-slot declarations support the NiNode owner; conflicting CrashLogger function-name hints were not adopted.

## Spellings tried that did not help
The cached object with a named exchange-add result retained the stack-slot difference. A one-worker PC permutation search exhausted its pool after one candidate at distance 1.5. The subsequent zero-distance body initially failed only because its exception-cleanup destructor reference was unbound.

## Spelling that fixed it
Keep the object pointer cached, name the result of the atomic decrement, and test the resulting count for zero before virtual deletion. Cookbook rule 29 explains the changed temporary-home allocation. Bind the cleanup destructor only after distinguishing the pack's atomic reference-release helper from its thread-local cleanup and base-destructor references by local observations. The next ordinary comparison passed with the existing root-includes recipe; a fifth invocation confirmed the compact owning-class declaration required by lint. All bodies were handwritten from local observations before an unrelated legacy sibling-derived template lookup; that exposed template was not used. No excluded sibling middleware body supplied the implementation. Local PASS remains candidate evidence.
