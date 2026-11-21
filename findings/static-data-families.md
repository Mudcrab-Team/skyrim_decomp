# Static-data readers and object wrappers

On the pinned Steam build, two C++ templates produced 143 candidates outside the matched inventory. Each compiled function passed the local comparator with its own data and call targets.

| Template | Function observed | Local passes | Already in the published target-hash list |
| --- | --- | ---: | ---: |
| Static-data reader | Reads one scalar from writable static storage and returns it | 45 | 8 |
| Static-object wrapper | Passes the address of writable static storage as the first argument and tail-calls another entry | 98 | 0 |

## Reproduction

Use Python with `iced-x86==1.21.0`. The first command prints the candidate counts. The second needs the pinned contributor MSVC toolchain configured for `tools/contrib.py` and a fresh output directory.

```sh
python3 tools/static_data_generate.py --exe "$SKYRIM_EXE"
python3 tools/static_data_generate.py --exe "$SKYRIM_EXE" --out .local/static-data-families --compare
```

The snapshot contains the C++ units in `reconstruction/leaves/` and a task, symbol map and per-RVA comparison reports in `tasks/<family>/`. The command returns a failure status if any comparison fails.

## Evidence and limits

- Target `sse-steam-1-7-104`, image SHA-256 `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f`. Inventory, published target extents, community boundary shards and build recipe came from repository revision `4b1758012a8d5835e09b6075e4c5eea876371aaf`. Boundary source `CRASHLOGGER_PDB(59818@2026.10.24)`.
- The search used complete, indexed extents. It checked the instruction count, operand types, registers and terminal return or jump, decoded each relative reference at the member's own RVA, and checked the referenced section. A wrapper's callee had to be an indexed start. Conflicting sizes, accepted ranges and incompatible storage views were excluded. Coverage is limited to the indexed entries and forms recognized by the generator.
- Verification used the pinned MSVC 19.16.27054 x64 recipe under Wine and the ordinary project comparator. Confidence is high in the code and reference comparison on this host. Storage ownership, original types and names are unknown. A tail jump can preserve other arguments or a return value, so the wrapper signature remains a guess.
- Exposure was mixed, from local binary analysis and the committed community boundary metadata. Original templates and analysis by Codex GPT-6.2 Astra, 2026-11-21. The runs supply one-host evidence. Second-host comparison and admitted review are pending.
