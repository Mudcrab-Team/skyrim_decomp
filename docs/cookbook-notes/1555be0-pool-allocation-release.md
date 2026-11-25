# 0x1555be0 BSRenderPassCache::Kill

<!-- tags: construct/allocation, wall/register-schedule -->

- Function: 0x1555be0 BSRenderPassCache::Kill
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 167/171 aligned bytes
- Attempts: 8

## What differed

Each of two pools releases two allocations. In the closest draft the loop and both frees agreed in size and shape. The target reads the second allocation before clearing the first pointer. The draft does those operations in the opposite order.

## Spellings tried that did not help

A nested range loop kept an inner loop. Calling the same release helper twice from an indexed outer loop removed it. Capturing the second allocation before the clear changed which pool member anchored the loop. Distinct pointer types and a release method on the pool did not recover both properties.

## Spelling that fixed it

none
