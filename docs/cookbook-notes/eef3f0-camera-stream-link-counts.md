# 0xeef3f0 NiCamera::LinkObject

<!-- tags: construct/loop, wall/control-flow -->

- Function: 0xeef3f0 NiCamera::LinkObject
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: loop-shape
- Best score: 232/232 aligned matching bytes
- Attempts: 7

## What differed

The camera retains the first resolved stream link while consuming two counted lists. Each list entry acquires and immediately releases a reference. The stream supplies a 32-bit unsigned count. Within each nonempty list the remaining count occupies a wider counter.

## Spellings tried that did not help

A single wide countdown converted the count before testing it. A guarded increasing index changed the loop exit. Naming the decremented reference count restored the stack layout but left the count setup different.

## Spelling that fixed it

Test the returned unsigned count before copying it into the wide countdown, then use a do-while loop. Each link goes out of scope before the loop condition. The first full pass was comparison six.
