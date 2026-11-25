# 0xa63040 NativeCallback::MarshallAndDispatch

<!-- tags: wall/register-schedule -->

- Function: 0xa63040 NativeCallback::MarshallAndDispatch
- Label: GUESS(low)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 199/206 aligned matching bytes
- Attempts: 9

## What differed

The provisional accumulator RTTI getter name conflicts with a callback invocation that receives a virtual machine, stack ID, receiver and one argument. A null receiver returns false. Success assigns a typed integer variable to the output and returns true. The receiver and argument types remain unresolved.

## Spellings tried that did not help

Constructing the type tag directly in the result omitted a temporary. Constructing and copying a separate type tag restored the full function length. Packing the value after default construction split a single wide store. Passing the callback expression directly to the variable constructor changed the lifetime of the type temporary.

## Spelling that fixed it

Unsolved. The best candidate uses the correct result width and type-tag lifetime. The compiler uses a different scratch register when widening the callback result for storage.
