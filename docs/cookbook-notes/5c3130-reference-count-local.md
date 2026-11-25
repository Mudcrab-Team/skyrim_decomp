# 0x5c3130 RefAttachTechniqueInput::SetAttachRoot

<!-- tags: construct/destructor, abi/exception, wall/register-schedule, method/binding -->

- Function: 0x5c3130 RefAttachTechniqueInput::SetAttachRoot
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: prologue-epilogue
- Best score: local PASS, 127/127 code bytes
- Attempts: 5

## What differed
An intrusive-pointer assignment reloaded the old pointer after retaining the incoming pointer. Caching the old pointer removed that load, leaving the saved-register and temporary home locations one slot away from the target.

## Spellings tried that did not help
Testing the decrement result directly kept the wrong home locations. The first assignment also read the old field only after retaining the replacement, which introduced a reload.

## Spelling that fixed it
Cache the old pointer before retaining the replacement. Apply cookbook rule 29 to both releases: save the decrement result in a named count and test that local. Code then aligned exactly; binding the outlined temporary destructor to the observed cleanup reference completed the fourth local attempt. The unresolved-binding attempt and the final fifth-run source confirmation are included in this run count.
