# Bethesda `MemoryManager::Allocate` factory and creator methods

On the pinned Steam build, five parameterized C++ templates covering core Bethesda game-code heap allocation and object-creation factories (`MemoryManager::Allocate` fixed-size and dynamic-size tail allocators, inline-constructed plain objects, `NiRefObject`-derived creators, and `BSTSmartPointer` intrusive-refcount create-and-assign factories) produced 280 candidates totaling 30,493 bytes outside the matched inventory. Each compiled function passed the local comparator, including unwind information, allocation sizes, field layouts, static storage references, and direct call targets.

| Template | Function observed | Local passes | Bytes | Shards | Distinct allocation sizes | Distinct data/vftable targets | Already in the published target-hash list |
| --- | --- | ---: | ---: | ---: | --- | ---: | ---: |
| `MemoryAllocFixed` | Fixed-size `MemoryManager::GetSingleton()->Allocate(N, 0, false)` tail allocator | 17 | 986 | 1 | 3 (`0x10`, `0x18`, `0x20`) | 0 | 17 |
| `MemoryAllocDynamic` | Dynamic-size `MemoryManager::GetSingleton()->Allocate(size, align, alignReq)` tail allocator (`operator new` wrapper) | 7 | 447 | 1 | — | 0 | 7 |
| `MemoryCreateObject` | `MemoryManager::Allocate` followed by null check and inline object field/vftable initialization | 132 | 12,041 | 5 | 6 (`0x8`, `0x10`, `0x18`, `0x20`, `0x28`, `0x30`) | 116 | 132 |
| `MemoryCreateNiRefObject` | `MemoryManager::Allocate` followed by `NiRefObject` base initialization (vftable, zero refcount, interlocked instance counter increment) and derived field/vftable initialization | 98 | 11,570 | 4 | 9 (`0x20`, `0x28`, `0x38`, `0x40`, `0x48`, `0x50`, `0x58`, `0x60`) | 98 | 98 |
| `BSTSmartPointerCreate` | `MemoryManager::Allocate` followed by intrusive-refcounted object construction and `BSTSmartPointer` acquire/assign/release | 26 | 5,449 | 1 | 7 (`0x10`, `0x18`, `0x20`, `0x28`, `0x30`, `0x40`, `0x50`) | 26 | 26 |

## Reproduce

With Python, `iced-x86==1.21.0`, and the configured contributor toolchain, run the following with a fresh output directory. Omit `--out` and `--compare` for candidate counts without compiling.

```sh
python3 tools/memory_factory_generate.py --exe "$SKYRIM_EXE"
python3 tools/memory_factory_generate.py --exe "$SKYRIM_EXE" --out .local/memory-factory --compare
```

The snapshot contains the sharded C++ units (at most 30 functions per unit, 12 units total) under `reconstruction/leaves/` and, under `tasks/<family>/`, the task, symbol map and per-RVA comparator reports. The command returns a non-zero exit status if any comparison fails.

## Evidence and limits

- Target `sse-steam-1-7-104` (pinned in `builds/target.json`, image SHA-256 `846efccf0c1374d7-1f892907f4654956-0f2fcb0a75cb87a3-eed438baa0f1402f`). Input inventory, target-hash manifest, recipe and community boundary shards came from repository revision `792cd52bc8`. Boundary source `CRASHLOGGER_PDB(59818@2026.10.24)`.
- Scope follows `docs/resource-guidelines.md`: all 280 candidates belong to Bethesda game-code `MemoryManager::Allocate` factories and creators with zero third-party middleware (no Havok, Scaleform, Bethesda.net client, CRT/STL, or import thunks).
- The 280 candidates are disjoint from the matched inventory and from all twelve checked merged leaf-family generators (`static_data_generate.py`, `fixed_argument_generate.py`, `return_argument_generate.py`, `conditional_dealloc_generate.py`, `vftable_reset_generate.py`, `range_copy_generate.py`, `guarded_callback_generate.py`, `lazy_static_generate.py`, `custom_dealloc_generate.py`, `sbo_alloc_log_generate.py`, `descriptor_init_generate.py`, and `bst_array_generate.py`, `0` overlap). All 280 candidates already have rows in the published target-hash list.
- Validation partitioned the candidate pool into a development split (140 functions, 15,224 bytes, containing all inspected exemplars) and an untouched held-out validation split (140 functions, 15,269 bytes). During the first frozen held-out run (281 candidates), 141/141 dev and 139/140 held-out passed; the single held-out miss (`MemoryCreateNiRefObject` with a secondary non-zero-offset address store) was resolved by enforcing the same single-vftable-at-offset-0 invariant already applied to `MemoryCreateObject`. The final end-to-end snapshot passed 280/280 locally (`unwind: covered` on all 280) with zero failures.
- Scope covers complete, unambiguous indexed non-EH extents (rejecting any function whose `.pdata` unwind entries declare an exception or unwind handler) matching the default MSVC `/O2` code generation. Every candidate validates indexed executable direct callees outside its own extent, non-executable readable static data targets for all singleton/guard/vftable/counter references, and exact control-flow targets.
- Sharding at 30 functions per unit keeps every emitted `.cpp` and `.h` file well under `contrib_screen`'s 64 KiB file-size cap (maximum emitted file size 25,083 bytes across all 24 files) and 32-level delimiter-depth bound; all 24 emitted files pass `contrib_screen`, `lint_reconstruction`, `check_code_rules.refusals`, and `check_code_rules` MATCH rules with zero findings.
- Verification used the pinned MSVC 19.16.27054 x64 recipe under Wine and the ordinary project comparator. Confidence is high in the compiled code, unwind information, object layouts, allocation sizes, and bound direct call and data targets on this host. Original class names, member names, and symbol identities remain unknown; all emitted names are `GUESS(low) STANDIN`.
- Exposure was mixed, from local binary analysis and the committed `CRASHLOGGER_PDB(59818@2026.10.24)` boundary metadata. Original templates and analysis by Antigravity (Gemini 4 Neon), 2026-11-24. These runs supply one-host evidence only; second-host comparison and admitted review are pending.
