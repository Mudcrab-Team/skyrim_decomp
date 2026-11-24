# Cookbook lesson notes

One small file per lesson, so a near-miss you solved (or could not) helps the next drafter.
Merged notes are folded into [docs/matching-cookbook.md](../matching-cookbook.md) at the next round,
and the folded note files are deleted.

Read the notes for your function's class or cause here before drafting.

## When to write one

Send a note, in the same PR as your functions or alone, when one of these holds. Check
[docs/matching-cookbook.md](../matching-cookbook.md) first; a note that only repeats a rule adds little, but a
near-miss whose cause the cookbook already names is still welcome when it adds a new function or a new twist.

1. **Near-miss.** A function you could not match: what differed, what you tried (outcome `unsolved`).
2. **Hard pass.** A pass that took four or more compares: the spelling that finally closed it (outcome `fixed`).
3. **A compiler shape you solved**, even on the first try, when the cookbook has no entry for it.
4. **Tool friction** (a slow step, a confusing message, a wrong hint) is not a note: list it under a
   "Bottlenecks" heading in the PR description, one line with a time cost (AGENTS.md).

`./sr lesson <rva>` writes the template, pre-filled from your task (or bare, with `--name`, when you have none);
finish every `TODO`. The bot asks for a note in its one comment when a function mismatched and the PR has none,
and the same comment thanks you when one merges. Notes are merged after the leak scan, the template check and one
review, never affect matching or digests, and credit the contributor as co-author of the merge commit. Merged
notes are folded into the cookbook at the next round (`python3 tools/lesson_credits.py` lists who wrote which).

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

<!-- example-note -->
A complete small example (names and RVAs only; the function is synthetic):

```markdown
# 0x123abc Example::Helper

- Function: 0x123abc Example::Helper
- Label: GUESS(low)
- Outcome: fixed
- Cause: integer-width-or-cast
- Best score: 18/20 aligned instructions before the fix
- Attempts: 5

## What differed
The two stack stores of the size argument were 4 bytes wide where the target writes 8, and the zero test used
32-bit registers. The callee takes its size by reference as a `size_t`.

## Spellings tried that did not help
- Widening only the helper's own parameter: the callee's reference type still forced a 32-bit temporary.
- A cast at the call site: the compiler folded it away.

## Spelling that fixed it
Make the parameter, the forwarding member and the callee's reference parameters all `size_t`; the width hunks
vanish together.
```
<!-- /example-note -->

Words and plain C++ only, under 6000 bytes, fenced code at most 12 lines. Never bytes, hex instruction
sequences, disassembly, decompiler output or listing excerpts: the leak scan refuses them. A note must
make a concrete claim (what differed, what was tried, what fixed it), not only say the function was hard.
"Spelling that fixed it" is `none` for an unsolved note.

## Causes

register-allocation, instruction-order, operand-order, inlining, loop-shape, branch-layout,
constant-folding, integer-width-or-cast, calling-convention, struct-layout, vtable-or-virtual,
float-codegen, prologue-epilogue, switch-lowering, other.
