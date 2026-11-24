# 0x340b80 TESGlobal scalar deleting destructor

<!-- tags: abi/virtual, construct/destructor, method/diagnostic, method/sibling, sibling/fnv, wall/inlining -->

- Function: 0x340b80 TESGlobal scalar deleting destructor
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
- Outcome: fixed
- Cause: inlining
- Best score: 93/93
- Attempts: 2

## What differed

After the vftable store, the wrapper makes a direct call on `this`, destroys the editor ID string at
0x20 and calls the TESForm destructor. NiExtraData-derived BSBehaviorGraphExtraData and
BSBoneLODExtraData have the same shape without the first call: member at 0x18, then the base.

## Spellings tried that did not help

An unqualified call to a new member function matched the bytes, but check_origin reported it as
similar to both sibling destructors without the header naming them.

## Spelling that fixed it

Spell the FNV sibling body, `TESForm::ClearData();`. The qualified call is direct even though
ClearData is virtual. Then let the BSString member and the out-of-line `virtual ~TESForm();` produce
the rest. Name both sibling files on `Sibling source:` lines.
