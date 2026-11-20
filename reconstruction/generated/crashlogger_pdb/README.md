<!-- CRASHLOGGER_PDB(59818@2026.10.24) -->
# CrashLogger community PDB output

Names, class layouts, enums, function prototypes and function boundaries generated from the community PDB
published with CrashLogger.

- Source: Nexus Mods mod 59818, CrashLogger Contributors (alandtse/CrashLoggerSSE), version 2026.10.24.
- PDB signature: {AE3F5F99-472E-44CE-9D81-6030F9C7B5C3}. The PDB itself is never committed.
- Label: every name, layout or signature taken from here into a unit carries `CRASHLOGGER_PDB(59818@2026.10.24)`.
- Regenerate with `python3 tools/pdb_types.py generate <SkyrimSE.pdb> --version 2026.10.24`; the whole directory is
  rewritten deterministically, so a diff shows exactly what a new PDB changed.

## Contents

- `types/<identifier>.h`: one header per class, union or enum (5750 types, 282 of them enums with
  4369 enumerators). A struct header holds the PDB's fields and offsets with explicit padding,
  includes the headers of the types it holds by value, forward-declares the ones it only points to, and ends with a
  `static_assert` on the PDB size. An enum is an `enum class` with the PDB's underlying type and values. Nothing
  includes these headers until a unit does.
- `types.tsv`: PDB name, identifier, kind and size of every type.
- `names/<NN>.tsv`: RVA to public name for the 25561 functions whose name is not a decompiler
  placeholder, one file per MiB of RVA (`NN` is the RVA shifted right by 20, in hex).
- `prototypes/<NN>.tsv`: RVA, calling convention and prototype of the 13386 functions whose type is more
  than a bare `void()` stub, spelled with the identifiers of `types/`. Same sharding.
- `boundaries/<NN>.tsv`: the exact start and code size, both in hex without a prefix, of the 102726
  functions the PDB records. Same sharding. A function missing here is not known to be absent: the PDB does not
  cover every function.

## Cautions

- These are community reconstructions of the game's types, not the game's own declarations. A field name, offset,
  parameter type or calling convention is a guess until the compiled function matches.
- A prototype lists a method's `this` as its first parameter, and the class named there is often another class
  that shares the code: take the owning class from the name, not from that parameter. `thiscall` marks a function
  the exporter believes is a method; `cdecl` is its default.
- A base class appears as an ordinary member named `_base`, `_base_<Name>`: the PDB has no inheritance records.
  The first base carries the virtual-table pointer.
- Names containing `::`, `<`, `>` or other punctuation are written with `__` and `_` in identifiers; `types.tsv`
  maps the PDB spelling to the identifier. Template instantiations are kept, with long names cut and tagged by a
  hash of the original.
- The exporter drops namespaces, so one name can stand for several unrelated types. Each distinct type gets its
  own header; the fullest keeps the plain identifier and the others add a hash suffix (624 names have more than one).
- Enumerators of different enums share names such as `kNone`, so enums are scoped (`Type::kNone`).
- `const` and `volatile` are dropped; member and function pointers are plain `void*`.
- An RVA belongs to the build the PDB was made for (`builds/target.json`); do not reuse it for another build.
