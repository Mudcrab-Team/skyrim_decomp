# 0x3b49f0 TESFaction::Function3b49f0

<!-- tags: wall/register-schedule, construct/loop -->

- Function: 0x3b49f0 TESFaction::Function3b49f0
- Label: GUESS(low)
- Outcome: fixed
- Cause: register-allocation
- Best score: full native comparator PASS
- Attempts: 2 ordinary comparisons; 25 search candidates

## What differed
The list lookup and interned-name assignment had the same instructions, but the search counter and result pointer received different scratch registers.

## Spellings tried that did not help
The initial spelling declared the null result pointer before the zero counter. It stopped at normalized distance 1.

## Spelling that fixed it
Declare the zero counter before the null result pointer. The bounded search isolated this declaration-order change; an ordinary comparison of the authored source then passed, including exception data.
