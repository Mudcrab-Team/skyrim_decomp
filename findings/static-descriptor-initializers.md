# Static reflection descriptor initializers

On the pinned Steam build, two parameterized C++ templates for static reflection metadata initializers (14-argument class-descriptor registration calls and 6-field type-info descriptor record initializers) produced 960 candidates totaling 91,938 bytes outside the matched inventory. Each compiled function passed the local comparator, including unwind information, static descriptor storage references, read-only name and metadata table addresses, callback function pointers, object sizes, and bound direct call targets.

| Template | Function observed | Local passes | Bytes | Shards | Distinct object sizes | Distinct callees | Distinct descriptor globals | Already in the published target-hash list |
| --- | --- | ---: | ---: | ---: | --- | ---: | ---: | ---: |
| `ClassDescriptorInitializers` | Straight-line 14-argument class-descriptor initializer call passing target slot, name, optional parent, object size, optional enum/member/defaults/attribute tables, counts, flags, and described version (82–121 bytes, including the frame-pointer stack-slot variant) | 617 | 61,754 | 13 | 49 sizes (1–1,072 B) | 1 | 617 | 0 |
| `TypeInfoDescriptorInitializers` | Straight-line 88-byte 6-field static type-info record initializer writing name, finish/cleanup callback pointers, object size, and the result of a zero-argument vtable-getter call | 343 | 30,184 | 7 | 37 sizes (16–1,072 B) | 343 | 343 | 0 |

## Reproduce

With Python, `iced-x86==1.21.0`, and the configured contributor toolchain, run the following with a fresh output directory. Omit `--out` and `--compare` for candidate counts without compiling.

```sh
python3 tools/descriptor_init_generate.py --exe "$SKYRIM_EXE"
python3 tools/descriptor_init_generate.py --exe "$SKYRIM_EXE" --out .local/descriptor-inits --compare
```

The snapshot contains the sharded C++ units (at most 50 functions per unit, 20 units total) under `reconstruction/leaves/` and, under `tasks/<family>/`, the task, symbol map and per-RVA comparator reports. The command returns a non-zero exit status if any comparison fails.

## Evidence and limits

- Target `sse-steam-1-7-104` (pinned in `builds/target.json`, image SHA-256 `846efccf0c1374d7-1f892907f4654956-0f2fcb0a75cb87a3-eed438baa0f1402f`). Input inventory, target-hash manifest, recipe and community boundary shards came from repository revision `b0c97b03a2`. Boundary source `CRASHLOGGER_PDB(59818@2026.10.24)`.
- The 960 candidates are disjoint from the matched inventory and from all previously merged leaf-family generators (`static_data_generate.py`, `fixed_argument_generate.py`, `return_argument_generate.py`, `conditional_dealloc_generate.py`, `vftable_reset_generate.py`, `range_copy_generate.py`, `guarded_callback_generate.py`, `lazy_static_generate.py`, `custom_dealloc_generate.py`, and `sbo_alloc_log_generate.py`).
- Validation partitioned the 960 discovered candidates into a development split (502 functions, 48,154 bytes, containing all inspected exemplars) and an untouched held-out validation split (458 functions, 43,784 bytes). Both splits passed 100% locally (`502/502` dev, `458/458` held-out) without per-function edits, followed by `960/960` on the full end-to-end snapshot run (`coverage.unwind == "covered"` on all 960 reports).
- Scope covers complete, unambiguous indexed non-EH extents (rejecting any function whose `.pdata` unwind entries declare an exception or unwind handler) matching the default MSVC `/O2` code generation. Every candidate validates indexed executable direct callees outside its own extent, 16-byte-aligned or indexed executable callback targets, non-executable read-only `.rdata` name and table targets, and writable non-executable `.data` descriptor globals. For `ClassDescriptorInitializers`, symbolic register/stack-slot evaluation covers both standard `sub rsp, 0x78` and the `mov rax, rsp; sub rsp, 0x78` frame-pointer addressing variant (6 functions).
- Sharding at 50 functions per unit keeps every emitted `.cpp` and `.h` file well under `contrib_screen`'s 64 KiB file-size cap and 32-level delimiter-depth bound (max emitted file size 20,325 bytes; all 40 emitted files pass `contrib_screen`, `lint_reconstruction`, `check_code_rules.refusals`, and `check_code_rules` MATCH rules with zero findings).
- Verification used the pinned MSVC 19.16.27054 x64 recipe under Wine and the ordinary project comparator. Confidence is high in the compiled code, unwind information, static descriptor references, metadata table pointers, callback addresses, object sizes, flags/versions, and bound call targets on this host. Original class ownership, reflection framework names, struct layouts, and symbol identities remain unknown; all emitted names are `GUESS(low) STANDIN`.
- Exposure was mixed, from local binary analysis and the committed `CRASHLOGGER_PDB(59818@2026.10.24)` boundary metadata. Original templates and analysis by Antigravity (Gemini 4 Neon), 2026-11-22. These runs supply one-host evidence only; second-host comparison and admitted review are pending.
