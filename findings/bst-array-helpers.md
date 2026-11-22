# Bethesda `BSTArray` / `BSTSmallArray` / `BSTScrapArray` container helpers

On the pinned Steam build, eight parameterized C++ templates covering core Bethesda game-code array-container operations (`BSTArray` heap/scrap unordered and ordered range erase, `BSTSmallArray` inline-vs-heap ordered range erase, trivial and constructing `BSTArray` resize, linear find-and-erase for 4-byte and 8-byte elements, and null-guarded buffer release) produced 351 candidates totaling 34,238 bytes outside the matched inventory. Each compiled function passed the local comparator, including unwind information, element strides, allocator layouts, and bound direct call targets.

| Template | Function observed | Local passes | Bytes | Shards | Distinct element strides | Distinct callees | Already in the published target-hash list |
| --- | --- | ---: | ---: | ---: | --- | ---: | ---: |
| `BSTArrayEraseUnordered` | Unordered swap-tail range erase on heap-backed `BSTArray` calling `MoveElements` and subtracting `count` | 140 | 11,480 | 5 | 2 (`4`, `8`) | 1 | 0 |
| `BSTArrayEraseOrdered` | Ordered shift-down range erase on heap-backed or scrap-backed `BSTArray` with full-clear fast path | 94 | 8,844 | 4 | 12 (`2`, `4`, `8`, `12`, `16`, `24`, `32`, `36`, `40`, `52`, `56`, `80`) | 1 | 0 |
| `BSTSmallArrayEraseOrdered` | Ordered shift-down range erase on `BSTSmallArray` dispatching between inline local buffer and heap buffer via sign bit of `capacity` | 8 | 936 | 1 | 4 (`4`, `8`, `16`, `24`) | 1 | 0 |
| `BSTArrayResizeTrivial` | Trivial-element resize on heap-backed (62) or scrap-backed (12) `BSTArray` calling `Alloc` or `Realloc` on growth | 74 | 8,362 | 3 | 9 (`1`, `2`, `4`, `8`, `12`, `16`, `24`, `32`, `48`) | 4 | 0 |
| `BSTArrayResizeConstruct` | Non-trivial-construct resize on heap-backed `BSTArray` calling `Alloc`/`Realloc` and range-construction helper on growth | 6 | 840 | 1 | 5 (`12`, `16`, `20`, `44`, `64`) | 10 | 0 |
| `BSTArrayFindEraseOrdered` | Linear search for a 4-byte or 8-byte key followed by ordered shift-down erase and `bool` found return | 16 | 2,622 | 1 | 2 (`4`, `8`) | 1 | 0 |
| `BSTArrayFindEraseUnordered` | Linear search for a 4-byte or 8-byte key followed by unordered swap-tail erase and `bool` found return | 6 | 922 | 1 | 2 (`4`, `8`) | 1 | 0 |
| `BSTArrayRelease` | Null-guarded buffer deallocation and size reset on heap-backed or scrap-backed `BSTArray` | 7 | 232 | 1 | — | 2 | 0 |

## Reproduce

With Python, `iced-x86==1.21.0`, and the configured contributor toolchain, run the following with a fresh output directory. Omit `--out` and `--compare` for candidate counts without compiling.

```sh
python3 tools/bst_array_generate.py --exe "$SKYRIM_EXE"
python3 tools/bst_array_generate.py --exe "$SKYRIM_EXE" --out .local/bst-array --compare
```

The snapshot contains the sharded C++ units (at most 30 functions per unit, 17 units total) under `reconstruction/leaves/` and, under `tasks/<family>/`, the task, symbol map and per-RVA comparator reports. The command returns a non-zero exit status if any comparison fails.

## Evidence and limits

- Target `sse-steam-1-7-104` (pinned in `builds/target.json`, image SHA-256 `846efccf0c1374d7-1f892907f4654956-0f2fcb0a75cb87a3-eed438baa0f1402f`). Input inventory, target-hash manifest, recipe and community boundary shards came from repository revision `26e3c0f21f`. Boundary source `CRASHLOGGER_PDB(59818@2026.10.24)`.
- Scope follows `docs/resource-guidelines.md`: all 351 candidates belong to Bethesda game-code container templates (`BSTArray` / `BSTSmallArray` / `BSTScrapArray`) with zero third-party middleware (no Havok, Scaleform, Bethesda.net client, CRT/STL, or import thunks).
- The 351 candidates are disjoint from the matched inventory, from the published target-hash list (`0` overlap), and from all eleven checked merged leaf-family generators (`static_data_generate.py`, `fixed_argument_generate.py`, `return_argument_generate.py`, `conditional_dealloc_generate.py`, `vftable_reset_generate.py`, `range_copy_generate.py`, `guarded_callback_generate.py`, `lazy_static_generate.py`, `custom_dealloc_generate.py`, `sbo_alloc_log_generate.py`, and `descriptor_init_generate.py`).
- Validation partitioned the 351 discovered candidates into a development split (173 functions, 17,204 bytes, containing all inspected exemplars) and an untouched held-out validation split (178 functions, 17,034 bytes). Both splits passed 100% locally (`173/173` dev, `178/178` held-out, `unwind: covered` on every function) without per-function edits, followed by `351/351` (`unwind: covered` on all 351) on the full end-to-end snapshot run.
- Scope covers complete, unambiguous indexed non-EH extents (rejecting any function whose `.pdata` unwind entries declare an exception or unwind handler) matching the default MSVC `/O2` code generation. Every candidate validates indexed executable direct callees outside its own extent, exact element stride and allocator-offset consistency (`BSTArrayHeap` vs `BSTArrayScrap` vs `BSTSmallArray_<N>`), and exact control-flow branch targets.
- Sharding at 30 functions per unit keeps every emitted `.cpp` and `.h` file well under `contrib_screen`'s 64 KiB file-size cap (maximum emitted file size 20,127 bytes across all 34 files) and 32-level delimiter-depth bound; all 34 emitted files pass `contrib_screen`, `lint_reconstruction`, `check_code_rules.refusals`, and `check_code_rules` MATCH rules with zero findings.
- Verification used the pinned MSVC 19.16.27054 x64 recipe under Wine and the ordinary project comparator. Confidence is high in the compiled code, unwind information, container layouts, element strides, and bound direct call targets on this host. Original template element types, owning classes, and symbol identities remain unknown; all emitted names are `GUESS(low) STANDIN`.
- Exposure was mixed, from local binary analysis and the committed `CRASHLOGGER_PDB(59818@2026.10.24)` boundary metadata. Original templates and analysis by Antigravity (Gemini 4 Neon), 2026-11-22. These runs supply one-host evidence only; second-host comparison and admitted review are pending.
