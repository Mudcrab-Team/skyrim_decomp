# Tail wrappers with a fixed second argument

On the pinned Steam build, 37 indexed functions preserve the first Windows x64 argument register, set the second to a constant and jump to another entry. Their targets resolve to seven distinct callees. One callee has 20 wrappers and another has 12. Across all 37 wrappers there are 34 distinct argument values.

The generator accepts two complete function shapes. A 32-bit immediate supplies the argument in 33 wrappers, and a register clear supplies zero in four. It extracts the unsigned value and jump destination independently for each entry and requires an indexed executable destination. A single C++ template produced a local comparator pass for each of the 37 functions under the pinned MSVC 19.16.27054 recipe and Wine, including the call-target binding. Their RVAs are disjoint from the 143 static-data candidates.

## Reproduce

With Python, `iced-x86==1.21.0`, and the configured contributor toolchain, run the following with a fresh output directory. Omit `--out` and `--compare` for a count without compiling.

```sh
python3 tools/fixed_argument_generate.py --exe "$SKYRIM_EXE" --out .local/fixed-argument --compare
```

The output contains the generated C++ and, under `tasks/FixedArgumentWrappers/`, the symbol map, task and individual comparator reports.

## Evidence

- Target `sse-steam-1-7-104`, image SHA-256 `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f`. Input inventory, target-hash manifest, recipe and community boundary shards at `fb513ebe71f346d9167cfd0a6080eeabaf85748a`. The candidates also have no overlap with accepted inventory ranges at `1a8c983f51ebce65628f6a07204b0563a35f67ea`.
- Scope covers unambiguous extents in the published and community indexes. The single-host comparison gives high confidence in the compiled code, the constant and the bound destination. It leaves the original signature, meaning of the constants, use of other registers and return type unresolved. The wrapper and callee names are guesses. Independent host confirmation and review are pending.
- Source exposure was mixed, from the local pinned image and the committed `CRASHLOGGER_PDB(59818@2026.10.24)` boundary metadata. Original template and analysis by Codex GPT-6.2 Astra, 2026-11-21.
