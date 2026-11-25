# 0x480750 BGSProcedureSandboxExecState::PickEntry

<!-- tags: abi/calling-convention, abi/exception, abi/virtual, construct/destructor, construct/loop, construct/switch, method/diagnostic, wall/callee, wall/control-flow, wall/inlining, wall/layout, wall/register-schedule -->

- Function: 0x480750 BGSProcedureSandboxExecState::PickEntry
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: fixed
- Cause: branch-layout
- Best score: sim 86.8 (Opus; not a byte match)
- Attempts: 11

## What differed
Near-pilot function, Sonnet draft 70.1, Sol 83.7 and Opus 86.8 (not a byte match). The draft ended every reject path in its
own `continue` and the accept path too; the target sets the weight to zero and continues on each reject (each with its
own inline reference release) and shares one accept tail. The space test was a four-way case split where the target has
one condition: when both cells exist and either is an interior, the cells must be equal, otherwise the world spaces must
be equal. The pick was a pre-test `for` with `break` behind a `count != 0` guard; the target guards on `total > 0` and
walks a post-test loop. The weight clamp was `< 0`; the target selects on `<= 0`. With the callee sets already equal the
path-cost call had its arguments in the wrong receiver order (Sol, +11.2 together with a typed handle base and one
world-space fallback); the handle-counted base is a sub-object at a fixed offset with a virtual delete.

## Spellings tried that did not help
- A by-value lookup wrapper returning the smart pointer: MSVC 19.16 would not inline it, even forced, and one callee went
  missing.
- A full if/else chain with a `bool usable` helper: 65.0. Early `continue`s were right; only the accept path is shared.
- Grouping the anchor coordinates into a point (it helped on 0x7fd020): 81.4.
- A walk that stops on `picked == 0xFFFFFFFF` in the loop condition: 85.8; with `break`: 84.6.

## Spelling that fixed it
Reject: set the weight to zero, release inline, `continue`; accept: one shared tail
(`entry.weight = weight; total += weight;`) (+6.9). One inline condition for the interior and world-space test (+4.9).
`if (total > 0)` and a post-test walk that ends by setting the index past the end instead of `break`, with the anchor world
space in the positive `if (anchorCell)` form (+4.6); clamp `weight <= 0` (+0.3). Hoisting the squared radius before the loop
and copying the entry handle to a local before the lookup was worth +5.3 on the draft. After each handle lookup the target
keeps the pointer in a register with an unwind no-op where the draft reloads it from the stack; no spelling here moved
that (same residue as 0x7fd020).
