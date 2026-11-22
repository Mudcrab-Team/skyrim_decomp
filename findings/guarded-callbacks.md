# Guarded static-callback dispatch and destroy wrappers

On the pinned Steam build, two C++ wrapper templates produced 126 candidates totaling 4,314 bytes outside the matched inventory. Each compiled function passed the local comparator, including unwind information, its static guard and callback-slot addresses and its direct cleanup call target.

| Template | Function observed | Local passes | Bytes | Distinct guards | Distinct callback slots | Distinct cleanup callees | Already in the published target-hash list |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: |
| `GuardedCallbacks` | Checks a static 64-bit guard and static callback pointer, and tail-calls the callback with the second argument | 96 | 2,784 | 1 | 1 | 0 | 0 |
| `GuardedDestroyCallbacks` | Checks the first argument for null, calls a cleanup entry on it, then checks the static 64-bit guard and static callback pointer and calls the callback on it | 30 | 1,530 | 1 | 1 | 15 | 0 |

## Reproduce

With Python, `iced-x86==1.21.0`, and the configured contributor toolchain, run the following with a fresh output directory. Omit `--out` and `--compare` for candidate counts without compiling.

```sh
python3 tools/guarded_callback_generate.py --exe "$SKYRIM_EXE"
python3 tools/guarded_callback_generate.py --exe "$SKYRIM_EXE" --out .local/guarded-callback --compare
```

The snapshot contains the generated C++ units under `reconstruction/leaves/` and, under `tasks/<family>/`, the task, symbol map and per-RVA comparator reports. The command returns a non-zero exit status if any comparison fails.

## Evidence and limits

- Target `sse-steam-1-7-104`, image SHA-256 `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f`. Input inventory, target-hash manifest, recipe and community boundary shards came from repository revision `521df5ee2e9e1e9d674ddafa702e4bf5bdb74068`. Boundary source `CRASHLOGGER_PDB(59818@2026.10.24)`.
- The candidates are disjoint from the matched inventory, from the 143 static-data candidates (`findings/static-data-families.md`), from the 37 fixed-argument tail wrappers (`findings/fixed-argument-wrappers.md`), from the 102 argument-returning call wrappers (`findings/return-argument-wrappers.md`) and from the 511 conditional deallocator candidates (`findings/conditional-deallocators.md`).
- Scope covers complete, unambiguous indexed extents of 29 bytes (`GuardedCallbacks`) and 51 bytes (`GuardedDestroyCallbacks`). Each candidate verifies that its guard and callback slots are distinct, 8-byte aligned writable `.data` addresses, and each destroy wrapper verifies an indexed executable cleanup callee outside its own extent with no member-to-member calls within the base family.
- Verification used the pinned MSVC 19.16.27054 x64 recipe under Wine and the ordinary project comparator. Confidence is high in the compiled code, unwind information, static storage references and bound direct cleanup targets on this host. Original ownership, allocator or subsystem roles, unused parameter types and names remain unknown; all emitted names are `GUESS(low) STANDIN`.
- Exposure was mixed, from local binary analysis and the committed `CRASHLOGGER_PDB(59818@2026.10.24)` boundary metadata. Original templates and analysis by Antigravity (Gemini 4 Neon), 2026-11-21. These runs supply one-host evidence only; second-host comparison and admitted review are pending.
