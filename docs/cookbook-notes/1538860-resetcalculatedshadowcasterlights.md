# 0x1538860 ResetCalculatedShadowCasterLights

<!-- tags: construct/loop, method/binding -->

- Function: 0x1538860 ResetCalculatedShadowCasterLights
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: integer-width-or-cast
- Best score: 328/328
- Attempts: 4

## What differed

The first draft was close at once; the frame, the focus flag and the tail call to the directional culling pass came out right. Three things were
off. The three per-frame counters written as separate globals were stored one by one, where the target writes the first two with one eight-byte
zero store. The counter increment and the mask update used a read-modify-write on memory and a bit-set instruction, where the target loads the
counter, adds one into a second register and stores it, and ORs a shifted one into memory. The scene node pointer was re-read from its global
where the target kept the first load in a callee-saved register for the array clear and the later reorder call.

## Spellings tried that did not help

- Separate globals for the counters: two stores for the first pair.
- `g_count++` on the global and `mask |= 1u << start` with an unsigned one: a memory increment and a bit-set on a register.
- Reading the scene node from its global at each use.

## Spelling that fixed it

A struct for the counters (so the first two zero stores merge), a local for the counter value (`index = count; count = index + 1;`), the mask
update spelled with a signed one, and one local for the scene node used for the array clear and the reorder call while the light is read from the
global again:

```
g_casterState.mask |= 1 << g_casterState.start;
```

The signed `1 << n` keeps the shift and the OR separate; the unsigned form is turned into a bit-set instruction.
