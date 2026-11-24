# 0xb4fe40 hkpPrismaticConstraintData::Routine140A71580

- Function: 0xb4fe40 hkpPrismaticConstraintData::Routine140A71580
- Label: GUESS
- Outcome: fixed
- Cause: struct-layout
- Best score: 82/82, unwind covered
- Attempts: 2 (the first spelling had the right members at the wrong offsets)

## What differed
A sibling function compiled for x64 differs from the Skyrim function in one number, because the
sibling's class is laid out differently. Rules learned from about 300 such near pairs:

1. A member offset is enough to reproduce the target: a class that declares only the members the
   function touches, placed at the target offsets with anonymous padding between them, compiles to the
   target's bytes. The padding before the first used member and placeholder virtual slots do the work.
2. A fact that says an immediate changed on an `add reg, N` or `lea reg, [reg + N]` instruction is a
   member (or sub-object) offset, not a constant. Adding the base pointer plus N is how the address of a
   member is formed. Treat it exactly like a member-offset fact.
3. Function-pointer members called through the object (`m_pfnRead(...)`) show up as virtual-slot facts
   but are ordinary members.
4. A template instance of a one-byte type that the target builds with a 2, 4 or 8 byte type shows the
   element size as an immediate (1 against N). Instantiate the template with the type of that size.
5. A single immediate that feeds a call argument (a type or kind code passed to a registration helper)
   is a constant of that Skyrim function. Change that literal in every argument position that held the
   sibling value; the registration helpers differ only in these codes.

## Spellings tried that did not help
Plain transplant with no layout for stack-frame offset differences: local variable layout differs and
nothing at source level reproduces it. A class-size-only deleting destructor that the target inlines a
body into (the target is larger than any empty destructor): there is no class-independent shape.
Pairs where the listing's source line belongs to the neighbouring statement or another template:
find the function by its symbol name, not by the line number.

## Spelling that fixed it
Declare `char padding_0_[48]` before the first used member so that `m_kPointA` sits at 0x30 and the
second sub-object follows it, instead of declaring it at the sibling's 0x20. Two more points matter
for units that need support text: pull in earlier inline helper templates the function calls (a bare
declaration emits a call the target does not make), and add the missing typedef, class or prototype to
the unit's own header, never a shared one, when the compiler reports an unknown name.
