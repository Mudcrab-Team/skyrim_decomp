# 0xfe9f00 BSPortal::CreateClone

<!-- tags: construct/constructor, construct/destructor, abi/exception -->

- Function: 0xfe9f00 BSPortal::CreateClone
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: inlining
- Best score: 163/163 aligned matching bytes
- Attempts: the original draft first passed on comparison 4 of 7. The typed assignment first passed on comparison 4 of the revision.

## What differed

The clone allocated and copied both rooms in the right order. A raw shared-node pointer left out the exception-state transition after base construction.

## Spellings tried that did not help

A reference wrapper with a null initializer and an external destructor left the body one byte short. Resetting through a temporary reference also left the transition absent.

## Spelling that fixed it

The CrashLogger layout identifies `portalSharedNode` as a `NiPointer<BSPortalSharedNode>`. An independent construction site, `BSPortal::Create` at RVA `0x213170` in the pinned build, calls a plane constructor, installs the portal vtable and initializes the shared-node member to null. It then sets the plane flags and clears the room links. After those writes it reads the shared-node member again. If occupied, it clears the member, drops the old node's reference and calls its virtual deletion method on the last release.

That factory constructs a portal without cloning one. Its ordering supports putting the null assignment in portal construction. The clone's own work is to copy the two room links. The two sites call different plane constructors, so the flag and room initialization in the factory is specific evidence for that path.

Use the ordinary `NiPointer<T>::operator=(T*)` ownership sequence from the project's `NiObjectNET.h`. It handles self-assignment, retains the incoming object, replaces the pointer and releases the old object. With an empty member and a null argument the clone needs only one null store. The full comparator also verifies the allocation, base and member cleanup funclets.
