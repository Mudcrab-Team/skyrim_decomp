# 0x14b150 EffectSetting::Function14b150

<!-- tags: wall/register-schedule -->

- Function: 0x14b150 EffectSetting::Function14b150
- Label: GUESS(low)
- Outcome: unsolved
- Cause: register-allocation
- Best score: normalized distance 1.0; full comparator FAIL
- Attempts: 2

## What differed
The string assignment and allocation-tag guard use the same operations, but two saved registers trade roles.

## Spellings tried that did not help
The bounded search tried declaration, expression, branch and local-name variations. It retained one distinct object and the distance stayed at 1.

## Spelling that fixed it
none
