# 0x1f6d80 BGSNamedNodeAttach::Attach

<!-- tags: abi/exception, abi/virtual, construct/destructor, method/binding, method/sibling, sibling/fo4, wall/layout, wall/register-schedule -->

- Function: 0x1f6d80 BGSNamedNodeAttach::Attach
- Label: EXE_RTTI SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: 32/42 aligned matching bytes; distance 1.0; comparator fail
- Attempts: 4 counted comparisons; 5 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
The local policy object's stack home remained one pointer slot away from the target. The parent body had the same size and instruction count, but this is not a byte match. The policy's unwind destructor also stayed unbound; no reference identity was invented to bypass that limitation. Class ownership comes from local RTTI and vtable facts. Method naming and the policy construction pattern are leads from the permitted sibling, not proven identity.

## Spellings tried that did not help
The original bool result, an explicitly virtual owner method, a void owner method, and a void forwarding helper all retained the same frame displacement. The initial rename-only bind attempt did not count as a comparison.

The bounded PC permuter tested one candidate, exhausted its mutation pool, and retained distance 1.0. Retrieval for the register and scheduling wall did not provide a demonstrated fix for this frame allocation. No winner was applied.

## Spelling that fixed it
None. Preserve the private source and diagnostics for signature and lifetime investigation; the return type remains unproven. No passing source is published for this function.
