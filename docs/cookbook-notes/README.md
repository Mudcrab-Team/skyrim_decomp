# Cookbook lesson notes

One small file per lesson, so a near-miss you solved (or could not) helps the next drafter.
Merged notes are folded into [docs/matching-cookbook.md](../matching-cookbook.md) at the next round,
and the folded note files are deleted.

Read the notes for your function's class or cause here before drafting.

## When to write one

Write a note only when one of these holds, and check [docs/matching-cookbook.md](../matching-cookbook.md)
first:

1. A spelling fixed something the cookbook does not record (outcome `fixed`; usually a pass that took four
   or more compares).
2. A near-miss whose cause is not covered by any cookbook rule or "Unsolved patterns" entry (outcome
   `unsolved`, a new cause).

A failure that matches a cookbook rule or unsolved pattern gets no note; the round's results already
record it. `./sr note <task>` writes the template pre-filled; finish every `TODO`.
Put the note in the same PR as the units, or send a notes-only PR; it is merged after the leak scan,
the template check and one review. Notes never affect matching or digests.

## File and template

`docs/cookbook-notes/<rva>-<slug>.md`: `<rva>` is lowercase hex without `0x` (3 to 8 digits), the slug
is lowercase letters, digits and dashes. Fields, in this order, then three sections:

```
# 0x<rva> <name>

- Function: 0x<rva> <name>
- Label: <the label the unit declares, or none>
- Outcome: fixed | unsolved
- Cause: <one of the list below>
- Best score: <what compare measured>
- Attempts: <count>

## What differed
## Spellings tried that did not help
## Spelling that fixed it
```

Words and plain C++ only, under 6000 bytes, fenced code at most 12 lines. Never bytes, hex instruction
sequences, disassembly, decompiler output or listing excerpts: the leak scan refuses them. A note must
make a concrete claim (what differed, what was tried, what fixed it), not only say the function was hard.
"Spelling that fixed it" is `none` for an unsolved note.

## Causes

register-allocation, instruction-order, operand-order, inlining, loop-shape, branch-layout,
constant-folding, integer-width-or-cast, calling-convention, struct-layout, vtable-or-virtual,
float-codegen, prologue-epilogue, switch-lowering, other.
