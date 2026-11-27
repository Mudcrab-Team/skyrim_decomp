# 0xfea050 BSPortalSharedNode::dtor_deleting

<!-- tags: construct/destructor, abi/exception -->

- Function: 0xfea050 BSPortalSharedNode::dtor_deleting
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: inlining
- Best score: 174/174 aligned matching bytes
- Attempts: 4 comparisons, first local pass on comparison 1

## What differed

The deleting destructor clears the light array before resetting the portal. Destruction of the array then checks its storage again before destroying its count and allocator bases.

## Spellings tried that did not help

The explicit-clear and member-destructor form passed on the first comparison. Rechecking it with the shared array declaration retained the result.

## Spelling that fixed it

Use one inline array clear operation in both destructors. The class destructor can clear its member and release the portal before ordinary base and member destruction runs.
