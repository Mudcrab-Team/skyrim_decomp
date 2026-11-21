# Polymorphic table-reset wrappers

On the pinned Steam build, four C++ templates produced 282 candidates totaling 12,337 bytes outside the matched inventory. Each compiled function passed the local comparator, including unwind information, its read-only table address and its direct call targets.

| Template | Function observed | Local passes | Bytes | Shards | Distinct tables | Distinct cleanups | Distinct sizes | Already in the published target-hash list |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| `TableInitializers` | Stores a read-only table pointer at offset 0 of the first argument and returns it | 27 | 378 | 1 | 27 | 0 | 0 | 0 |
| `TableTailCleanups` | Stores a read-only table pointer at offset 0 of the first argument and tail-calls a cleanup entry | 31 | 465 | 1 | 28 | 22 | 0 | 10 |
| `TableDeallocators` | Stores a read-only table pointer at offset 0, conditionally calls a sized deallocator on bit 0 of the second argument, and returns the first argument | 126 | 5,418 | 2 | 80 | 0 | 18 | 126 |
| `TableCleanupDeallocators` | Stores a read-only table pointer at offset 0, calls a cleanup entry, conditionally calls a sized deallocator on bit 0 of the second argument, and returns the first argument | 98 | 6,076 | 1 | 86 | 42 | 36 | 7 |

## Reproduce

With Python, `iced-x86==1.21.0`, and the configured contributor toolchain, run the following with a fresh output directory. Omit `--out` and `--compare` for candidate counts without compiling.

```sh
python3 tools/vftable_reset_generate.py --exe "$SKYRIM_EXE"
python3 tools/vftable_reset_generate.py --exe "$SKYRIM_EXE" --out .local/vftable-reset --compare
```

The snapshot contains the sharded C++ units (at most 100 functions per unit) under `reconstruction/leaves/` and, under `tasks/<family>/`, the task, symbol map and per-RVA comparator reports. The command returns a non-zero exit status if any comparison fails.

## Evidence and limits

- Target `sse-steam-1-7-104`, image SHA-256 `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f`. Input inventory, target-hash manifest, recipe and community boundary shards came from repository revision `521df5ee2e9e1e9d674ddafa702e4bf5bdb74068`. Boundary source `CRASHLOGGER_PDB(59818@2026.10.24)`.
- The candidates are disjoint from the matched inventory, from the 143 static-data candidates (`findings/static-data-families.md`), from the 37 fixed-argument tail wrappers (`findings/fixed-argument-wrappers.md`), from the 102 argument-returning call wrappers (`findings/return-argument-wrappers.md`) and from the 511 conditional deallocator candidates (`findings/conditional-deallocators.md`).
- Scope covers complete, unambiguous indexed extents of 14 bytes (`TableInitializers`), 15 bytes (`TableTailCleanups`), 43 bytes (`TableDeallocators`, observed sizes 24 to 491,576 bytes) and 62 bytes (`TableCleanupDeallocators`, observed sizes 8 to 1,752 bytes) matching the default MSVC `/O2` instruction sequence. Every table target is verified to lie in the read-only non-executable `.rdata` section, and every cleanup or deallocator target is verified as an indexed executable entry outside the member's own extent with no member-to-member references inside the same base family.
- Verification used the pinned MSVC 19.16.27054 x64 recipe under Wine and the ordinary project comparator. Confidence is high in the compiled code, unwind information, read-only table addresses, constant size arguments and bound direct call targets on this host. Original class ownership, inheritance, member layouts, destructor identities and names remain unknown; all emitted names are `GUESS(low) STANDIN`.
- Exposure was mixed, from local binary analysis and the committed `CRASHLOGGER_PDB(59818@2026.10.24)` boundary metadata. Original templates and analysis by Antigravity (Gemini 4 Neon), 2026-11-21. These runs supply one-host evidence only; second-host comparison and admitted review are pending.
