# 0x1d89e0 BGSKeywordForm::HasKeyword

- Function: 0x1d89e0 BGSKeywordForm::HasKeyword
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: fixed
- Cause: loop-shape
- Best score: 104/104
- Attempts: 5

## What differed

The search loop assigned the found flag and loaded entry to different temporaries and widened the index.

## Spellings tried that did not help

A loop with an early return for the found flag, wider or signed indices, and breaking on the flag did not match.

## Spelling that fixed it

```cpp
bool found = false;
for (std::uint32_t i = 0; i < count && !found; ++i) {
    current = entries[i];
    found = current == key;
}
return found;
```

This extends rule 35 to the previously unsolved search; condition order and the final flag return were changed together.
