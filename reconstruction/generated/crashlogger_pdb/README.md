<!-- CRASHLOGGER_PDB(59818@2026.10.24) -->
# CrashLogger community PDB output

Names and class layouts generated from the community PDB published with CrashLogger.

- Source: Nexus Mods mod 59818, CrashLogger Contributors (alandtse/CrashLoggerSSE), version 2026.10.24.
- PDB signature: {AE3F5F99-472E-44CE-9D81-6030F9C7B5C3}. The PDB itself is never committed.
- Label: every name or layout taken from here into a unit carries `CRASHLOGGER_PDB(59818@2026.10.24)`.
- Regenerate with `python3 tools/pdb_types.py generate <SkyrimSE.pdb> --version 2026.10.24`; the whole directory is
  rewritten deterministically, so a diff shows exactly what a new PDB changed.

## Contents

- `types/<identifier>.h`: one layout header per class, union or enum (5750 types). Each holds the PDB's fields and
  offsets with explicit padding, includes the headers of the types it holds by value, forward-declares the ones it
  only points to, and ends with a `static_assert` on the PDB size. Nothing includes them until a unit does.
- `types.tsv`: PDB name, identifier, kind and size of every type.
- `names/<NN>.tsv`: RVA to public name for the 25561 functions whose name is not a decompiler placeholder, one
  file per MiB of RVA (`NN` is the RVA shifted right by 20).

## Cautions

- These are community reconstructions of the game's types, not the game's own declarations. A field name or
  offset is a guess until the compiled function matches.
- A base class appears as an ordinary member named `_base`, `_base_<Name>`: the PDB has no inheritance records.
  The first base carries the virtual-table pointer.
- Names containing `::`, `<`, `>` or other punctuation are written with `__` and `_` in identifiers; `types.tsv`
  maps the PDB spelling to the identifier. Template instantiations are kept, with long names cut and tagged by a
  hash of the original.
- The exporter drops namespaces, so one name can stand for several unrelated types. Each distinct type gets its
  own header; the fullest keeps the plain identifier and the others add a hash suffix (624 names have more than one).
- `const` and `volatile` are dropped; member and function pointers are plain `void*`.
- An RVA belongs to the build the PDB was made for (`builds/target.json`); do not reuse it for another build.
