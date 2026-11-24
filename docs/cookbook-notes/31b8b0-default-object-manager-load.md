# 0x31b8b0 default object manager load

- Function: 0x31b8b0 default object manager load
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: fixed
- Cause: loop-shape
- Best score: sim 88.1 (Sonnet; not a byte match)
- Attempts: 7

## What differed
Near-pilot function (506 bytes), Sonnet draft 78.6 at the first score and 88.1 at the end (not a byte match). The first linear
search was a `for` with a combined condition; MSVC unrolled it six times and the candidate was 604 bytes against 506 (size ratio
1.19, the warning sign to read after round one).

## Spellings tried that did not help
- A `for` with `break`: the unrolled form, -3.7 against the best.
- Switching the loop index to `size_t` without a listing reason: -3.7 (reverted).
- A helper for the byte swap: 0.0.

## Spelling that fixed it
Write the loop in the decompiler's own shape: a do-while with the exit test at the top of the body and a pointer increment
(+10.2; 604 bytes down to 520). Compute the pair count before the allocation and walk a pair pointer (+3.0). Left: the table size
constant is held in a callee-saved register in the target and is an immediate in the draft; the target recomputes the index times
24 for each pair where the draft strength-reduces to a pointer; the target loads, swaps and stores the key before touching the form.

The snippet is a generic shape with invented names, not the unit's code.

```cpp
do {
    if (done) { break; }
    /* body */
    ++pair;
} while (--remaining != 0);
```
