# 0x7db450 BSTDerivedCreator<BGShkMatFadeController, BShkNonTransformController>::Create

<!-- tags: wall/register-schedule, construct/constructor, construct/allocation, sibling/fo4 -->

- Function: 0x7db450 BSTDerivedCreator<BGShkMatFadeController, BShkNonTransformController>::Create
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 91/106
- Attempts: 6

## What differed

The allocation through the memory manager with its initialisation guard, the null check and the size all match. The four stores that construct the object come out in a different order: the target writes the reference count, then the second member, then the vftable pointer, then the last member. The candidate writes the reference count, the vftable pointer, the second member, the last member, and loads the vftable address one instruction earlier. Only the schedule of these stores differs.

## Spellings tried that did not help

- Both base members set in the base constructor's initialiser list, then in its body.
- The second member moved into the derived constructor.
- Three levels (referenced object, controller base, derived) so each level stores its own vftable and the dead stores fold away.
- The last member typed as a float with the engine's large-float literal instead of an integer.
- A base without virtual functions, so the derived vptr is first and the base fields follow (the shape that closed a pathing location destructor): the object grew to 128 bytes, worse.

## Spelling that fixed it

none; the residue is a store schedule, a candidate for the permuter.
