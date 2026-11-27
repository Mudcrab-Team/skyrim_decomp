# 0xf88d30 NiTextKeyExtraData::IsEqual

<!-- tags: construct/loop, wall/register-schedule, method/diagnostic -->

- Function: 0xf88d30 NiTextKeyExtraData::IsEqual
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: register-allocation
- Best score: 127/127 code bytes; comparator PASS, unwind covered
- Attempts: 4 counted comparisons

## What differed

Same instructions, same sizes. The two key-array base pointers hoisted out of the loop landed in swapped scratch registers, so four loop-body operands used the other register. The target hoists the other object's array first.

## Spellings tried that did not help

- Writing the comparison with the other object's key on the left: the hoisting order followed, but the loaded operand became the other object's key and the loop body then differed instead.
- A bounded permutation search reached distance 1.0 through operand swaps only and could not separate hoisting order from operand order.

## Spelling that fixed it

Name the two entries of the iteration. The other object's entry is bound first, so its array is hoisted first, while the comparison keeps this object's entry on the left.

```cpp
const auto& theirs = data->keys[i];
const auto& mine = keys[i];
if (mine.time != theirs.time || mine.text != theirs.text) {
    return false;
}
```

Reference locals decouple the order in which array bases are hoisted from the order in which operands appear in the comparison.
