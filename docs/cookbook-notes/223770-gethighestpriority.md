# 0x223770 GetHighestPriority

<!-- tags: wall/register-schedule, sibling/fo4 -->

- Function: 0x223770 GetHighestPriority
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: register-allocation
- Best score: 107/107
- Attempts: 4

## What differed

A scene-graph helper that looks up a controller on a node, scans its target array for a node and returns a priority byte from a
72-byte-stride array. With the blend entries declared as a typed struct array and indexed as `blendInterps[i].priority`, every
instruction matched but two registers were swapped: the target keeps the controller pointer in the register that the candidate gave to
the target-array pointer, and the other way round. Same size, same shape, register choice only.

## Spellings tried that did not help

- Folding the controller local into one cast expression (`static_cast<...>(GetController(...))`): same swap.
- Collapsing the loop body to one conditional return: size grew by 14 bytes and the score fell.

## Spelling that fixed it

Reading the priority through a byte offset from the array base, as the sibling body does, instead of a typed element:

```cpp
return *(char*)((char*)multi->blendInterps + 72 * i + 0x1C);
```

The typed-element form gives the optimiser a different address expression and a different register order; the byte-offset form fixed
both registers at once. The element type is left as a forward declaration because only its stride and the byte offset are known.
