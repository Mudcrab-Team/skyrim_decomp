# 0xfc7fd0 QueuedNamedFile::GetName

<!-- tags: abi/calling-convention, method/binding, wall/register-schedule -->

- Function: 0xfc7fd0 QueuedNamedFile::GetName
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: register-allocation
- Best score: 55/55 code bytes; comparator PASS, unwind covered
- Attempts: 3 counted comparisons on this lead (plus earlier history)

## What differed
The target keeps the has-name flag in a callee-saved register across the bounded string copy and returns it; the draft kept the name pointer there and re-tested it after the call, adding a test and changing the register choice.

## Spellings tried that did not help
- Computing the flag from the pointer before the copy (`bool hasName = name != nullptr;`) and selecting the fallback with a ternary: the compiler rematerialised the test after the call.
- Return types of different width.

## Spelling that fixed it
Set the flag on the branch where the pointer exists and substitute the fallback on the other branch (`if (name) hasName = true; else name = emptyName;`). The flag is then a separate live value from the pointer and the compiler keeps it across the call.
