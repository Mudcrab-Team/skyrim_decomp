# 0x1555920 BSRenderPass::ClearRenderPass

<!-- tags: wall/register-schedule -->

- Function: 0x1555920 BSRenderPass::ClearRenderPass
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: operand-order
- Best score: 104/104 bytes, local comparator pass
- Attempts: 3

## What differed

The deferred-free path checks how many entries remain between two masked ring indices. The first draft read the indices in reverse order. Once their order agreed, the compiler still selected the opposite arm of the wraparound test and tested a different temporary.

## Spellings tried that did not help

Reading the write index first improved alignment from 62/104 to 99/104. Starting with the difference and conditionally adding the capacity still missed.

## Spelling that fixed it

Read the write index before the read index. Compute the count as a choice between the two unsigned distances, then test that count for zero.

```cpp
const unsigned int count = write >= read ? write - read : capacity + write - read;
```
