# 0x15299a0 BSEffectShaderProperty::WithMemoryContext

<!-- tags: abi/exception, construct/destructor, method/binding, wall/callee -->

- Function: 0x15299a0 BSEffectShaderProperty::WithMemoryContext
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); CRASHLOGGER_PDB(59818@2026.10.24); GUESS(low)
- Outcome: fixed
- Cause: other
- Best score: 80/80 aligned code bytes; native PC comparator PASS with unwind coverage
- Attempts: 1 counted comparisons; 3 invocations total, including binding-only and final-source provenance checks as applicable

## What differed

The inherited draft already aligned the complete function body, but its scope guard destructor was unresolved in exception cleanup. Body alignment alone did not establish a pass. The permitted CrashLogger name data identified the pack-listed cleanup helper as AutoMemContext; its name is a naming lead, while the unchanged comparator supplied the byte evidence.

## Spellings tried that did not help

- An anonymous MemoryContextScope with an original inline destructor left its cleanup reference unbound.
- Renaming the helper to AutoMemContext preserved body alignment, but the human-readable destructor binding was not resolved by the binder.

## Spelling that fixed it

Keep the inline save-and-restore scope guard from cookbook rule 21 and bind the exact decorated destructor name to the cleanup helper already present in the assigned pack. The final unchanged source passed the native PC comparator, including exception metadata and unwind coverage. The operation name remains a low-confidence guess; this local result is a candidate and does not establish acceptance.
