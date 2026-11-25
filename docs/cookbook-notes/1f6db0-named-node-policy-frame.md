# 0x1f6db0 BGSNamedNodeAttach::Detach

<!-- tags: abi/exception, abi/virtual, construct/destructor, method/binding, method/sibling, sibling/fo4, wall/layout, wall/register-schedule -->

- Function: 0x1f6db0 BGSNamedNodeAttach::Detach
- Label: EXE_RTTI SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: 32/42 aligned matching bytes; distance 1.0; comparator fail
- Attempts: 1 counted comparisons; 1 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
The local policy object's stack home remained one pointer slot away from the target. The parent body had the same size and instruction count, but this is not a byte match. The policy's unwind destructor also stayed unbound; no reference identity was invented to bypass that limitation. Class ownership comes from local RTTI and vtable facts. Method naming and the policy construction pattern are leads from the permitted sibling, not proven identity.

## Spellings tried that did not help
The void owner method and void forwarding helper retained the displacement. The paired Attach function also retained it with bool results and explicit virtual declarations; those variants were measured on that other function only.

The bounded PC permuter tested one candidate, exhausted its mutation pool, and retained distance 1.0. Retrieval for the register and scheduling wall did not provide a demonstrated fix for this frame allocation. No winner was applied.

## Spelling that fixed it
None. Preserve the private source and diagnostics for signature and lifetime investigation; the return type remains unproven. No passing source is published for this function.
