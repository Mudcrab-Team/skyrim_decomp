# 0xfe9c20 BSPortalSharedNode::CreateClone

<!-- tags: construct/constructor, abi/exception, wall/inlining -->

- Function: 0xfe9c20 BSPortalSharedNode::CreateClone
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: inlining
- Best score: 205/205 aligned matching bytes
- Attempts: 5 comparisons, first local pass on comparison 2

## What differed

The clone constructs a node and its light array in the allocated block. Value-initializing the shared array representation inserted zero stores before its allocator and count constructors.

## Spellings tried that did not help

Using a value initializer on the array produced a longer candidate even though the calls to both base constructors remained.

## Spelling that fixed it

Default-initialize the light array. Its allocator and count bases initialize their own storage. Verify the exceptional cleanup targets for the node and allocator bases as well as the ordinary constructor path.
