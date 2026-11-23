# 0xce3360 BSReadWriteLock::LockForRead

- Function: 0xce3360 BSReadWriteLock::LockForRead
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: fixed
- Cause: prologue-epilogue
- Best score: 102/102
- Attempts: 2

## What differed

The candidate saved two registers one home slot earlier than the target; the rest of the function agreed.

## Spellings tried that did not help

- Testing the atomic compare-exchange directly in the loop condition.

## Spelling that fixed it

Name the compare-exchange result and reuse it in the loop:

```cpp
long observed = Acquire();
while (observed != 0) {
    Yield();
    observed = Acquire();
}
```

The helper names are illustrative; the unit uses the atomic operation directly.
