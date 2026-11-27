# 0xa57820 BSScript::NativeFunction0<TESObjectREFR, BGSScene*>::MarshallAndDispatch

<!-- tags: abi/exception, wall/register-schedule -->

- Function: 0xa57820 BSScript::NativeFunction0<TESObjectREFR, BGSScene*>::MarshallAndDispatch
- Label: EXE_RTTI (owner and template arguments), COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) (method)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 144/152 aligned matching bytes
- Attempts: 4

## What differed

The scene-returning callback constructs a script variable and assigns it to the caller’s result. An initial candidate had the correct function length but the wrong exception-state count. After recovering the result lifetime, the remaining difference was an extra frame-pointer copy at the earlier stack-page lookup.

## Spellings tried that did not help

Using a variable returned by value fed the return address directly into assignment. A named local constructed from the callback result instead made assignment use its stack address. Inlining the destructor around a call to its cleanup helper restored the two exception states, but the full comparison still failed on function length.

## Spelling that fixed it

none
