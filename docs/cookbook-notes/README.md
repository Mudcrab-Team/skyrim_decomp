# Cookbook lesson notes

One small file per lesson, so a near-miss you solved (or could not) helps the next drafter.
Maintainers fold notes into [docs/matching-cookbook.md](../matching-cookbook.md) from time to time.

Read the notes for your function's class or cause here before drafting.

## When to write one

After a batch: one note for each near-miss (function not matched when you stopped) and each hard-won
pass (four or more compares). `./sr note <task>` writes the template pre-filled; finish every `TODO`.
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
