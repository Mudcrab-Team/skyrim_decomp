# 0x1571c0 ExtraDataList::GetExtraDataUnsafe

<!-- tags: wall/register-schedule -->

- Function: 0x1571c0 ExtraDataList::GetExtraDataUnsafe
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 155/344 (aligned_matching_bytes)
- Attempts: 1

## What differed

The candidate reproduced the presence-bitfield fast exit, TLS cache version check, zeroing `memset`, and linked-list fallback loop within four bytes of the target size, but swapped the callee-saved registers holding `this` and the result pointer and reloaded the TLS cache-table offset instead of keeping it in a register across the loop.

## Spellings tried that did not help

- Declaring the three thread-local cache fields as separate `extern __declspec(thread)` globals with `_tls_0x10`, `_tls_0x18`, and `_tls_0x20` suffixes and consulting them before the linked-list scan.

## Spelling that fixed it

none
