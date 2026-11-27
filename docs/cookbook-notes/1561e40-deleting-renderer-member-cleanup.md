# 0x1561e40 BSBatchRenderer::dtor_deleting

<!-- tags: abi/exception, construct/destructor -->

- Function: 0x1561e40 BSBatchRenderer::dtor_deleting
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: other
- Best score: 403/403 aligned bytes
- Attempts: 6

## What differed

The scalar deleting destructor includes the same group and array cleanup as the ordinary destructor, followed by a conditional release of the renderer. Correct deletion size and an aligned primary body were insufficient while the exception map differed.

## Spellings tried that did not help

Using an explicit cleanup call for the array size member retained the exception-state difference. Changing how the group array was traversed corrected the frame but did not fix that metadata.

## Spelling that fixed it

Compile the virtual destructor with the size member destroyed as a member and the group pointer cleared inside its non-null branch. Bind the compiler-generated deleting entry and the size destructor to the observed targets. The full comparator passed. The published hash has a different relocation layout.
