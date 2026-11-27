# 0x419c80 Sky::GetPreviousRoomLightingTemplate

<!-- tags: method/diagnostic -->

- Function: 0x419c80 Sky::GetPreviousRoomLightingTemplate
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 84/113 (aligned_matching_bytes)
- Attempts: 4

## What differed

Moving `LookupReferenceByHandle` out of an inner scoped `NiPointer<TESObjectREFR> tmp` into an outer `NiPointer<TESObjectREFR> ref` with `GetRoomLightingTemplate() noexcept` gave the expected register allocation across the body (`84` aligned bytes), but left an extra stack zeroing store for `ref` (`118` or `119` vs `113` bytes).

## Spellings tried that did not help

- Direct `NiPointer<TESObjectREFR> ref` without `tmp` reloaded the handle slot after `GetRoomLightingTemplate()`.
- Moving `tmp` via an inline `BSPointerHandle::get()` getter was not inlined by MSVC even with `__forceinline`.
- Scoped `{ NiPointer tmp; LookupReferenceByHandle(..., tmp); ref = ...; }` kept the outer `ref` slot on stack across the lookup call.

## Spelling that fixed it

none
