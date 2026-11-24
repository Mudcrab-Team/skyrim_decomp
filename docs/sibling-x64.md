# Sibling decompilations as x64

Two forks hold the Fallout: New Vegas and Fallout 3 decompilations ported to compile as x64 with the
same compiler and flags as this project's recipe (MSVC 19.16, `/O2 /MD /GS- /EHsc /GR /fp:precise /Gy`):

- `awarebayes/fnv_decomp`, branch `x64-msvc1916` (from `momusdigital/fnv_decomp@2b07cb3e`)
- `awarebayes/f3_decomp`, branch `x64-msvc1916` (from `momusdigital/f3_decomp@f5bac1b5`)

**What the forks are.** The upstream code and names, unchanged in meaning, plus original port edits: an
`include/x64_compat.h` force-included header, mechanical source edits (32-bit size asserts disabled, inline
assembly stubbed, `operator new`/`delete` widened to `size_t`, CRT redeclarations corrected), and a build
script `tools/x64/build_x64.py`. Licence stays CC0 1.0; the README credits upstream and keeps its provenance
notes. Upstream's Xbox 360 PDB-derived names and Havok/Gamebryo material are not covered by CC0, and the port
adds nothing of that kind.

**Nothing game-derived lives there.** No game files, executables, objects, disassembly, addresses from the
Skyrim binary, match results or indexes. Those stay under `.local/`.

**Build (Windows, your own toolchain).**

```
git clone -b x64-msvc1916 https://github.com/awarebayes/fnv_decomp
python fnv_decomp/tools/x64/build_x64.py --msvc <dir holding VC/Tools/MSVC/<ver> and Windows Kits/10> --jobs 6
```

Only the compile step runs. A minority of units (about 6 percent of FNV, 8 percent of F3) still fail to
compile; the build output lists them.

**How to use the output.** Treat compiled sibling functions as leads: match them to Skyrim functions by code
shape with offsets masked, then run the normal comparator. A sibling is never evidence about the Skyrim
binary (`docs/authorizations.md`); labels and the `Sibling source:` header rules in the cards still apply.
