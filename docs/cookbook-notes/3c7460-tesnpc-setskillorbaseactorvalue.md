# 0x3c7460 TESNPC::SetSkillOrBaseActorValue

- Function: 0x3c7460 TESNPC::SetSkillOrBaseActorValue
- Label: GUESS(low)
- Outcome: fixed
- Cause: constant-folding
- Best score: 50/50
- Attempts: 4

## What differed

The candidate reused the result of the range test's index calculation for the skill store. The target calculated the index again after the tests and scheduled the conversion of the stored value later.

## Spellings tried that did not help

Writing the range test as an unsigned offset comparison let MSVC share the index computation. Casting after the subtraction or widening the index parameter also left the calculation shared.

## Spelling that fixed it

Express the test as an inclusive interval on the incoming actor value. Calculate the index only inside the skill-store branch. MSVC lowers the range test to an unsigned offset comparison and computes the index again for the store.

```cpp
if (actorValue >= 6 && actorValue <= 23) {
    skills[static_cast<std::uint32_t>(actorValue) - 6] =
        static_cast<std::uint8_t>(value);
}
```
