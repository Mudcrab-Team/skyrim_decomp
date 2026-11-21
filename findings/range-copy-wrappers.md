# Range-copy-and-return-end wrappers

On the pinned Steam build, two C++ wrapper templates produced 114 candidates totaling 5,394 bytes outside the matched inventory. Each compiled function passed the local comparator, including unwind information and its bound direct call target.

| Template | Function observed | Local passes | Bytes | Distinct callees | Already in the published target-hash list |
| --- | --- | ---: | ---: | ---: | ---: |
| `RangeCopyWrappers` | Computes `count = last - first`, calls a byte-copy entry `(dest, first, count)`, and returns `dest + count` | 88 | 4,224 | 1 | 0 |
| `AllocatorRangeCopyWrappers` | Ignores an unused first pointer argument, computes `count = last - first` from arguments 2 and 3, calls a byte-copy entry `(dest, first, count)`, and returns `dest + count` | 26 | 1,170 | 1 | 0 |

## Reproduce

With Python, `iced-x86==1.21.0`, and the configured contributor toolchain, run the following with a fresh output directory. Omit `--out` and `--compare` for candidate counts without compiling.

```sh
python3 tools/range_copy_generate.py --exe "$SKYRIM_EXE"
python3 tools/range_copy_generate.py --exe "$SKYRIM_EXE" --out .local/range-copy --compare
```

The snapshot contains the generated C++ units under `reconstruction/leaves/` and, under `tasks/<family>/`, the task, symbol map and per-RVA comparator reports. The command returns a non-zero exit status if any comparison fails.

## Evidence and limits

- Target `sse-steam-1-7-104`, image SHA-256 `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f`. Input inventory, target-hash manifest, recipe and community boundary shards came from repository revision `521df5ee2e9e1e9d674ddafa702e4bf5bdb74068`. Boundary source `CRASHLOGGER_PDB(59818@2026.10.24)`.
- The candidates are disjoint from the matched inventory, from the 143 static-data candidates (`findings/static-data-families.md`), from the 37 fixed-argument tail wrappers (`findings/fixed-argument-wrappers.md`), from the 102 argument-returning call wrappers (`findings/return-argument-wrappers.md`) and from the 511 conditional deallocator candidates (`findings/conditional-deallocators.md`).
- Scope covers complete, unambiguous indexed extents of 48 bytes (`RangeCopyWrappers`) and 45 bytes (`AllocatorRangeCopyWrappers`). Each candidate verifies that its direct callee is outside its own extent and is either an indexed executable start or a 6-byte executable RIP-relative import jump thunk targeting `.rdata`.
- Verification used the pinned MSVC 19.16.27054 x64 recipe under Wine and the ordinary project comparator. Confidence is high in the compiled code, unwind information and bound direct call target on this host. Original template instantiations, element types, allocator parameter types and names remain unknown; all emitted names are `GUESS(low) STANDIN`.
- Exposure was mixed, from local binary analysis and the committed `CRASHLOGGER_PDB(59818@2026.10.24)` boundary metadata. Original templates and analysis by Antigravity (Gemini 4 Neon), 2026-11-21. These runs supply one-host evidence only; second-host comparison and admitted review are pending.
