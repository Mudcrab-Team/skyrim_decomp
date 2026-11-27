# 0x1538430 DrawWorld_RenderShadowCasters

<!-- tags: method/diagnostic -->

- Function: 0x1538430 DrawWorld_RenderShadowCasters
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: struct-layout
- Best score: 555/604 aligned bytes
- Attempts: 7

## What differed

Every instruction matches except the stack offsets of three locals: the job-submit scope object, the loop index and the saved memory-context value sit in a different order in the frame. The job structs, the reference-count releases and the branch layout all came out right once the first two job structs, the submit scope and the caster loop each got their own braces, so the structs die before the final flag check and the memory-context scope ends before the job list is finished. A call to the destructor of the job struct also stays unbound.

## Spellings tried that did not help

- Caster walk written inline in the function body, in its own block, and as a static inline helper: same frame order each time.
- Declaring the index before the memory-context scope: moved the index store earlier and lost bytes.
- Assigning the accumulator through a smart pointer global instead of a raw pointer global fixed the load order but not the frame.

## Spelling that fixed it

none
