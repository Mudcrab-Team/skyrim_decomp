# Finding: six more LOD function starts and two public renames (issue 937)

Status: selection metadata only; no match and no behavior claim. Function starts and extents are image-derived facts (OBSERVED by local static analysis). Names are placeholders.
Author / human operator: maintainer decision on issue 937
Source exposure: mixed. Local static analysis of the maintainer's pinned image (no bytes, listings or decompiler text are published here) and the public CrashLogger community PDB names already in the repository.
Sources and immutable revisions: the pinned image `sse-steam-1-7-104` (digest in `builds/target.json`); `reconstruction/generated/crashlogger_pdb/names` (label `CRASHLOGGER_PDB(59818@2026.10.24)`).
Confidence: medium for the starts and extents; no class or behavior is claimed.

## What changed

- Renamed two existing `mapped` entries to the complete public name at their RVA: `0x2c5ce0` and `0x2c9900`. A community guess, not evidence.
- Added six `mapped` entries that had no inventory row: `0x51b540`, `0x51b460`, `0x1a2360`, `0x14ecb20`, `0x510210`, `0x51cd40`. Each is a function start of the local function table of the pinned image, and its size is that table's extent. Each name is a `Function<rva>` placeholder with no owner. Their per-function hashes are published in the target-hash manifest.

## Limitations

- Extents were not compared against the project's extent table. Two of the six (`0x51b540`, `0x14ecb20`) have no exception-table entry, so their extent rests on the local function table alone.
- No class is claimed for the six; contributors supply one with `./sr start --class`.
