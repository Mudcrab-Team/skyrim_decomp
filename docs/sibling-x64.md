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

**Prebuilt index.** Release `x64-index-v1` of each fork carries `x64-index-v1-<game>.json.gz`: one signature
per compiled sibling function (mnemonic stream, call count, large immediates, string literals), built from the
compiled CC0 code only. It holds no Skyrim bytes, results or addresses. `./sr setup` downloads both into
`.local/x64-index/` and refuses a file whose SHA-256 differs from the pin in `data/x64-index.json`
(`--no-sibling` skips it). `tools/x64_index.py` packs, verifies, fetches and loads the format; the maintainer
rebuilds it from the forks' `x64-msvc1916` branches and publishes a new tag with a new pin.

**In `./sr start`.** `tools/x64_lookup.py` builds the target function's signature locally (llvm-objdump) and prints
the top sibling candidates from the downloaded index, also saved as `sibling_x64.json` in the task directory. Names,
paths and scores only. A missing index or objdump gives one line and never stops `start`.

**Library-shape index (`tools/msvclib`).** CRT/STL-heavy leftovers have no sibling source to transplant, so a third
index is built from code we write and compile ourselves with the same recipe: `catalog.py gen` writes explicit
instantiations of the standard headers the compiler ships (containers, smart pointers, `std::function`, algorithms,
small wrapper functions) over scalar, pointer, plain-struct and nested element types; `build.py` compiles each as
its own unit natively on Windows (at most four jobs); `index.py sigs`/`leads` and the `tools/f3x64` match, score and
`cmp_run.py --tag msvclib` steps find unmatched target functions of the same shape. The sources copy no library
text. `docs/resource-guidelines.md` counts `std::` template instances that the game's own code instantiated as game code, so a
pass here becomes a reconstruction unit labelled `OBSERVED`; plain C runtime functions and import thunks stay out of scope.

**Near pairs (`tools/f3x64/layout.py`, `tools/sibling_layout.py`).** A sibling function whose compiled code equals the target's except
for numbers or operand widths states facts about the Skyrim layout. `layout.py` lists them per pair from any sibling build (Fallout 3,
New Vegas or the private Fallout 4 tree) and keeps class sizes keyed by the Skyrim owner, never by the sibling class: member and
sub-object offsets (`add-offset` is the same kind as a displacement), virtual slots, class and allocation sizes, constants passed to a
call, and operand widths. `sibling_transplant.py run --layouts` applies them to the transplanted unit: stand-in classes with the
members at the target offsets and padding between them, members retyped to the target width, a tail pad to the target size, the
target's call-argument constants, and integer parameters widened for register-width facts. `SIBLING_DRY=1` stops after the layout
step to count what is ready without starting tasks. Nothing here is match evidence; the comparator decides.

**Checking the cookbook against the compiler.** `tools/f3x64/lab_experiments.py` compiles toy spelling variants on the Windows
runner with the recipe and judges a stated claim per experiment (`lab_compile.py` is the transport and listing parser);
`corpus.py` counts a source pattern's effect over the sibling listings (line effects, the UnwindHelp store with and without a handler, vftable
thunks, tail calls, source-identical twins); `cluster.py` groups the hunks of near pairs into width, register, offset, immediate and
instruction-only kinds. Results are in the "Sibling x64 verification" section of [the cookbook](matching-cookbook.md). All of it
reads only compiled sibling code and toy sources; the near-pair score files stay under `.local/`.

