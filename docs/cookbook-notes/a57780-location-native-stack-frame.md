# 0xa57780 BSScript::NativeFunction0<TESObjectREFR, BGSLocation*>::MarshallAndDispatch

<!-- tags: wall/register-schedule, abi/exception -->

- Function: 0xa57780 BSScript::NativeFunction0<TESObjectREFR, BGSLocation*>::MarshallAndDispatch
- Label: EXE_RTTI (owner and template arguments), COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) (method)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 144/152 aligned matching bytes
- Attempts: 6

## What differed

The native dispatcher asks the frame’s parent stack for its page before it unpacks the receiver. The candidate copies the frame pointer into a second register for this call. The target uses the incoming frame address to load the parent and also passes that address as an argument. The candidate is three bytes longer.

## Spellings tried that did not help

The same extra copy survived passing the frame as a pointer or reference and placing the lookup in an inline frame method. A named result variable reproduced the address used for assignment. An inline destructor reproduced the second exception state.

## Spelling that fixed it

none
