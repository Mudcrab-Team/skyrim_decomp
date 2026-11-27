# 0x419b30 Sky::GetCurrentRoomLightingTemplate

<!-- tags: method/diagnostic -->

- Function: 0x419b30 Sky::GetCurrentRoomLightingTemplate
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: inlining
- Best score: 41/113 (aligned_matching_bytes)
- Attempts: 2

## What differed

MSVC did not inline `BSPointerHandle::get()` returning a destructible `NiPointer<TESObjectREFR>` into the exception-handling frame (`104` vs `113` bytes), while calling `LookupReferenceByHandle` directly caused a stack reload after `GetRoomLightingTemplate()`.

## Spellings tried that did not help

- Wrapping lookup in `BSPointerHandle::get()` with a move constructor on `NiPointer`.

## Spelling that fixed it

none
