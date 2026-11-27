# 0x7a3ec0 MovementHandlerAgentPlayerControls::Func7_1406FB980

<!-- tags: wall/callee, abi/virtual, construct/serialization -->

- Function: 0x7a3ec0 MovementHandlerAgentPlayerControls::Func7_1406FB980
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: calling-convention
- Best score: 47/47 code bytes; comparator PASS, unwind covered
- Attempts: 4 counted comparisons on this lead (plus earlier history)

## What differed
The function reads a value object returned through caller storage from a stream, then calls a virtual setter on an embedded sink with the value's scalar. The target reads the scalar from its own stack slot and ends with a tail jump into the setter. The first draft read the scalar through the returned pointer inside one expression and finished with a normal call and return, which also changed the frame and the saved registers.

## Spellings tried that did not help
- Reading the scalar from a named local object that lives to the end of the function: the scalar came from the stack slot, but the temporary's lifetime blocked the tail jump (distance 3.0).
- Copying the scalar out of the call expression in one statement (`uint32_t v = stream->ReadInput().value;`): the tail jump appeared but the scalar was read through the returned pointer again.

## Spelling that fixed it
Scope the returned object in its own block and copy the scalar to a function-level local; the sink call then follows with no object alive and compiles to the tail jump while the scalar is read from the stack slot. Rule of thumb: an object that has to live in caller storage and an address-taken local both stop a final call from becoming a tail jump while they are in scope.
