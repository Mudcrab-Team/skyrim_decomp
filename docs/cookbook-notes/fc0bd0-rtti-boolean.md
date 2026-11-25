# 0xfc0bd0 NiPSysModifierFloatCtlr::SynchronizePoseInterpolator

<!-- tags: construct/loop, wall/control-flow, abi/virtual -->

- Function: 0xfc0bd0 NiPSysModifierFloatCtlr::SynchronizePoseInterpolator
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: branch-layout
- Best score: local PASS, 126/126 code bytes
- Attempts: 6

## What differed
The first drafts guarded use of the runtime cast result, although the observed caller uses that result unconditionally. After removing that guard, the remaining difference lay in the type-test result and loop exits.

## Spellings tried that did not help
A pointer-valued loop condition was shorter than the target. A local boolean assigned inside the loop reached the target length but still differed. Moving the pointer-valued cast into a helper did not change that result.

## Spelling that fixed it
Use a small boolean helper that walks the type-parent chain, returning true immediately on the requested type and false after exhaustion. The cast helper handles a null input and selects the original pointer from that boolean result. The caller retrieves the float and sets the pose without another null guard. The sixth local comparison passed; no sibling body was used.
