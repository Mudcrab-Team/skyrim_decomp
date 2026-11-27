# 0x2caf00 TESObjectCELL::Function2caf00

<!-- tags: wall/register-schedule, wall/control-flow, abi/virtual -->

- Function: 0x2caf00 TESObjectCELL::Function2caf00
- Label: GUESS(low)
- Outcome: fixed
- Cause: instruction-order
- Best score: local comparator pass for the 55-byte function; first compare 51/55 matching bytes, distance 2.0
- Attempts: 3 (two source comparisons and one final provenance-label comparison)

## What differed
The first shared-pointer assignment model re-read the loaded-data owner around the atomic increment. It added two operations while matching the remaining instructions.

## Spellings tried that did not help
Directly reading the old pointer from the owner member and writing through the owner member again after incrementing the replacement produced 51/55 matching bytes at distance 2.0.

## Spelling that fixed it
Bind a reference to the stored pointer before the ownership update. Read the old value and store the replacement through that reference, preserving the storage location across the atomic count update. Keep the existing increment-before-store and decrement-after-store ordering, including virtual destruction when the old count reaches zero. This closed the one-host comparison; independent verification and review remain required.
