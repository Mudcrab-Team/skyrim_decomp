# 0x151e430 BSShaderAccumulator::AccumulateSceneGraph

<!-- tags: construct/destructor, abi/exception -->

- Function: 0x151e430 BSShaderAccumulator::AccumulateSceneGraph
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: other
- Best score: 160/160 aligned matching bytes
- Attempts: 4

## What differed

Traversal constructs a guard for the thread render context, then passes the accumulator and its filter flag to the visitor. The first lock model emitted separate loads when testing the owner and recursion count.

## Spellings tried that did not help

Keeping both fields volatile changed the lock-release code. Ordinary fields with explicit fences and interlocked operations restored the complete body, but exception metadata still contained one extra state transition.

## Spelling that fixed it

Use the nonthrowing guard constructor declaration already used for the project render lock. The unchanged release logic then had the expected exception-state range. Comparison three passed the full comparator.
