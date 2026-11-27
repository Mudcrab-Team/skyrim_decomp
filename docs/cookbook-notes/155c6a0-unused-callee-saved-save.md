# 0x155c6a0 ShadowmapDescriptor::ShadowmapDescriptor

<!-- tags: wall/register-schedule, abi/exception, construct/constructor -->

- Function: 0x155c6a0 ShadowmapDescriptor::ShadowmapDescriptor (also 0x155da30)
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 163/163 bytes, unwind and registers differ
- Attempts: 5

## What differed
The target saves rbp in the frame but never uses it, keeps the zero constant in r14 and takes rsi, rdi, r14 as pushed registers.
The draft uses rbp for the zero. The same descriptor constructor inlined into the range construction (0x155da30) keeps a second,
biased item pointer (item plus 0xC0) in the target; the draft uses one pointer and is six bytes longer.

## Spellings tried that did not help
Index versus pointer loops, a post-incremented placement address, member initialisers in declaration order. The permuter has no
mutation site in an initialiser-only constructor.

## Spelling that fixed it
none. An extra live local that later disappears would explain the saved but unused register.
