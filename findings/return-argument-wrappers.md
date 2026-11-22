# Argument-returning call wrappers

On the pinned Steam build, three C++ wrapper templates produced 102 candidates totaling 2,983 bytes outside the matched inventory. Each compiled function passed the local comparator, including unwind information and its own direct call target.

| Template | Function observed | Local passes | Bytes | Distinct callees | Already in the published target-hash list |
| --- | --- | ---: | ---: | ---: | ---: |
| `ReturnFirstWrappers` | Saves the first pointer argument, calls another entry with it, and returns the saved first argument | 41 | 943 | 38 | 0 |
| `ReturnSecondWrappers` | Saves the second pointer argument, calls another entry with the first two arguments, and returns the saved second argument | 12 | 276 | 5 | 0 |
| `ReturnFirstConstantWrappers` | Saves the first pointer argument, calls another entry with the first argument, a 64-bit constant and the second argument, and returns the saved first argument | 49 | 1,764 | 49 | 0 |

## Reproduce

With Python, `iced-x86==1.21.0`, and the configured contributor toolchain, run the following with a fresh output directory. Omit `--out` and `--compare` for candidate counts without compiling.

```sh
python3 tools/return_argument_generate.py --exe "$SKYRIM_EXE"
python3 tools/return_argument_generate.py --exe "$SKYRIM_EXE" --out .local/return-argument --compare
```

The snapshot contains the generated C++ units under `reconstruction/leaves/` and, under `tasks/<family>/`, the task, symbol map and per-RVA comparator reports. The command returns a non-zero exit status if any comparison fails.

## Evidence and limits

- Target `sse-steam-1-7-104`, image SHA-256 `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f`. Input inventory, target-hash manifest, recipe and community boundary shards came from repository revision `cdffe293631eb717b0429697b519290768bd5562`. Boundary source `CRASHLOGGER_PDB(59818@2026.10.24)`.
- The candidates are disjoint from the matched inventory, from the 143 static-data candidates (`findings/static-data-families.md`) and from the 37 fixed-argument tail wrappers (`findings/fixed-argument-wrappers.md`).
- Scope covers complete, unambiguous indexed extents of 23 bytes (`ReturnFirstWrappers`, `ReturnSecondWrappers`) and 36 bytes (`ReturnFirstConstantWrappers`). Each candidate requires an indexed executable direct callee outside its own extent and excludes callees that are members of the same emitted unit.
- Verification used the pinned MSVC 19.16.27054 x64 recipe under Wine and the ordinary project comparator. Confidence is high in the compiled code, unwind information and bound direct call targets on this host. Original ownership, class/method names, additional forwarded argument registers, callee return values and the meaning of the 64-bit constant (1 distinct value across the 49 constant-argument wrappers) remain unknown. All emitted names are `GUESS(low) STANDIN`.
- Exposure was mixed, from local binary analysis and the committed `CRASHLOGGER_PDB(59818@2026.10.24)` boundary metadata. Original templates and analysis by Antigravity (Gemini 4 Neon), 2026-11-21. These runs supply one-host evidence only; second-host comparison and admitted review are pending.
