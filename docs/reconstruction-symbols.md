# Reconstruction debug symbols

The symbol tool projects names and C++ line ranges from our compiled reconstruction objects onto
the original RVAs in an [exelink plan](exelink.md). The plan supplies the pinned build ID, the
matched RVAs and the object selectors. The tool uses the recorded size and, for single-section
records, the recorded code hash to check the selected object. The JSON stores sizes measured
from the objects. It reads no game image, third-party symbol file, symbol map or target hash table.

## Generate a map

Create the plan from the revision whose source you want to debug. The exelink plan options
can select a small set of units before a full build.

```sh
python3.13 tools/exelink/exelink.py plan --out .local/symbols/plan.json
```

On the Windows build worker, in the same source revision, compile the plan's units into a fresh
directory. Use the worker's Python executable and your share of its compiler slots. Here
`python` denotes that executable.

```powershell
python tools/exelink/symbols.py build --plan .local/symbols/plan.json --objects .local/symbols/objects --msvc C:/path/to/pinned-toolchain
python tools/exelink/symbols.py map --plan .local/symbols/plan.json --objects .local/symbols/objects --out .local/symbols/rvamap.json
```

`build` adds `/Z7` to the accepted recipes. `map` can also use existing exelink-named objects
compiled with embedded CodeView. To run `map` in a different checkout of the same source,
pass the original compiler checkout path via `--build-root`. The symbol and object output
paths resolve under `.local/`. A partial map is still written if binding fails for some
entries. The command exits with status 1 in that case and lists the missing RVAs and reasons
in the JSON.

```sh
python3.13 tools/exelink/symbols.py lookup --map .local/symbols/rvamap.json 0x2340
```

## JSON format

Schema 1 uses integer RVAs, in bytes from the image base. The top-level `build_id` qualifies
every RVA. Each entry in the RVA-sorted `functions` array has:

- `rva` and `size` for the half-open function range.
- `name`, from the CodeView procedure or, if absent, the object linkage name. `linkage_name`
  always holds the C++ object symbol. `unit` is the current repository-relative compiled file.
- `lines`, ordered by function-relative byte `offset`. Each entry has a byte `length`, a
  repository-relative `file`, a one-based `line` and the compiler's `statement` flag.
- `labels`, the existing provenance labels on associated reconstruction sources and their
  included reconstruction headers. These are unit-level context, so an entry can carry labels
  for names other than the procedure itself. `CRASHLOGGER_PDB(...)` and `SYMBOLS(...)` retain
  their exact source spelling.
- `code_hash_verified`, which records whether the selected section was checked against the
  accepted code hash. The prototype checks the selector and size for records whose hash
  also covers exception funclets.

The header includes coverage counts and the separate `missing` array. Missing line ranges
indicate where the compiler omitted line information or where source paths or checksums
could not be verified against the reconstruction tree. Optimized code can have sparse or
out-of-order source lines. The tool maps the primary function body and omits inline frames,
separate exception funclets, local variables and type information.

## Generate and use a PDB

Use Clang and LLD from LLVM 20 or later on the local machine. The linker builds a synthetic
PE carrier with an empty, padded code section. It writes a native PDB with procedure and
line records at the mapped RVAs, and stamps the carrier with the matching PDB identity.
The carrier has no entry point. Keep it beside the PDB for offline lookup.

```sh
python3.13 tools/exelink/symbols.py pdb --map .local/symbols/rvamap.json --out .local/symbols/Reconstruction.pdb
llvm-symbolizer --functions=short --relative-address --obj=.local/symbols/Reconstruction.dll 0x2340
```

`--source-root` sets the absolute checkout path as seen by the debugger. Pass a Windows
checkout path when generating the PDB on another OS for Windows use. The PDB keeps the build
ID and exact unit labels in its `/reconstruction/name-origins` named stream. The stream is
JSON with `build_id` and a `labels` object keyed by decimal RVA.

```sh
llvm-pdbutil export --stream=/reconstruction/name-origins --out=.local/symbols/origins.json .local/symbols/Reconstruction.pdb
```

At runtime, add the game's actual load base to an RVA. A debugger using DbgHelp can load
the generated PDB in a dedicated symbol session with `SymLoadModuleExW`, the actual module
base and a nonzero module size, then resolve names and lines on that address range. A debugger that accepts
explicitly loaded images can use the carrier as a symbol overlay. In WinDbg, set the
executable and symbol search paths to the carrier directory, then try
`.reload /f Reconstruction.dll=<game-base>,<carrier-size>` and look up the virtual address.
The overlay has its own identity. Automatic symbol matching against the owner's executable
will depend on debugger support for loading a symbol file with a different identity.
The explicit PDB load and offline lookups are verified. A live WinDbg overlay is unverified. See
[Microsoft's explicit PDB loading documentation](https://learn.microsoft.com/en-us/windows/win32/api/dbghelp/nf-dbghelp-symloadmoduleexw)
and the [WinDbg module reload options](https://learn.microsoft.com/en-us/windows-hardware/drivers/debuggercmds/-reload--reload-module-).

The prototype keeps every generated artifact local. The JSON contains source metadata and
public RVAs that can be considered for publication under the usual provenance review.
[The repository publication policy](../LEGAL.md) excludes PDBs and executables, including
the synthetic carrier.
