# Conditional sized deallocators and cleanup-then-deallocate wrappers

On the pinned Steam build, two C++ templates produced 511 candidates totaling 24,330 bytes outside the matched inventory. Each compiled function passed the local comparator, including unwind information and its own direct call targets.

| Template | Function observed | Local passes | Bytes | Shards | Distinct sizes | Distinct cleanup callees | Already in the published target-hash list |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: |
| `ConditionalDeallocators` | Tests bit 0 of the second argument, conditionally calls a sized deallocator with the first argument and a constant size, and returns the first argument | 118 | 3,894 | 2 | 23 | 0 | 59 |
| `CleanupDeallocators` | Calls a cleanup entry on the first argument, tests bit 0 of the second argument, conditionally calls a sized deallocator with a constant size, and returns the first argument | 393 | 20,436 | 4 | 89 | 234 | 30 |

## Reproduce

With Python, `iced-x86==1.21.0`, and the configured contributor toolchain, run the following with a fresh output directory. Omit `--out` and `--compare` for candidate counts without compiling.

```sh
python3 tools/conditional_dealloc_generate.py --exe "$SKYRIM_EXE"
python3 tools/conditional_dealloc_generate.py --exe "$SKYRIM_EXE" --out .local/conditional-dealloc --compare
```

The snapshot contains the sharded C++ units (at most 100 functions per unit) under `reconstruction/leaves/` and, under `tasks/<family>/`, the task, symbol map and per-RVA comparator reports. The command returns a non-zero exit status if any comparison fails.

## Evidence and limits

- Target `sse-steam-1-7-104`, image SHA-256 `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f`. Input inventory, target-hash manifest, recipe and community boundary shards came from repository revision `3b2d3051afa64fd02862a831389cdef8d26b292b`. Boundary source `CRASHLOGGER_PDB(59818@2026.10.24)`.
- The candidates are disjoint from the matched inventory, from the 143 static-data candidates (`findings/static-data-families.md`), from the 37 fixed-argument tail wrappers (`findings/fixed-argument-wrappers.md`) and from the 102 argument-returning call wrappers (`findings/return-argument-wrappers.md`).
- Scope covers complete, unambiguous indexed extents of 33 bytes (`ConditionalDeallocators`, observed sizes 8 to 2,392 bytes) and 52 bytes (`CleanupDeallocators`, observed sizes 16 to 197,120 bytes) matching the default MSVC `/O2` instruction sequence. Each candidate requires indexed executable direct callees outside its own extent, distinct cleanup and deallocator targets, and excludes member-to-member calls within the same base family.
- Verification used the pinned MSVC 19.16.27054 x64 recipe under Wine and the ordinary project comparator. Confidence is high in the compiled code, unwind information, constant size arguments and bound direct call targets on this host. Original class ownership, inheritance, member layouts, destructor identities and names remain unknown; all emitted names are `GUESS(low) STANDIN`.
- Exposure was mixed, from local binary analysis and the committed `CRASHLOGGER_PDB(59818@2026.10.24)` boundary metadata. Original templates and analysis by Antigravity (Gemini 4 Neon), 2026-11-21. These runs supply one-host evidence only; second-host comparison and admitted review are pending.
