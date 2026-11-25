# 0x1521360 BSShaderAccumulator::Function1521360

<!-- tags: construct/bitfield, wall/flag-fold -->

- Function: 0x1521360 BSShaderAccumulator::Function1521360
- Label: GUESS(low)
- Outcome: fixed
- Cause: branch-layout
- Best score: PC comparator PASS (all checks passed)
- Attempts: 2

## What differed

The material flag test selected a different conditional branch despite an otherwise identical function.

## Spellings tried that did not help

A bare truth test of the masked flag kept the different branch form.

## Spelling that fixed it

Use an explicit unsigned greater-than-zero predicate for the masked flag. The related slot-fourteen wrapper uses the same spelling.
