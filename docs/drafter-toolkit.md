# Drafter toolkit

Every resource a Drafter has, with the command and the moment to use it. Read this before the
first draft; the card ([drafter card](drafter-card.md), [contributor card](contributor-card.md)) says
what is allowed, this page says what exists. Everything listed reads private inputs from `.local/`
or public tracked files; nothing here puts game bytes or disassembly in a commit, PR, issue or log.
A lead from any row is a hypothesis; only the comparator (`attempt` or `./sr compare`) decides.

## First 10 minutes

Do these in order before the first `attempt`. Each step is a few seconds of reading or one command.

1. **Fresh worktree?** `python3 tools/worktree_kit.py <worktree>` once (safe to repeat). It links the
   community and sibling sources, the sibling indexes and the analysis tables into the worktree's
   `.local/`, so raw `grep .local/sources/...` and the tools below find them.
2. **Cookbook, by class and cause.** Skim the ranking table at the top of
   [the cookbook](matching-cookbook.md), then `ls docs/cookbook-notes/` and read the notes for your
   class. For a function that already has failures, search its RVA:
   `grep -n '0x<rva>' docs/matching-cookbook.md docs/cookbook-notes/*.md` (the `Evidence:` and
   `Still failing:` lines name the RVAs each rule closed or left open).
3. **Sibling source and x64 hints.** Open the file and line in the task's `sibling.md`, then
   `sibling_x64.json` (closest compiled Fallout functions by code shape). An `exact_shape` candidate
   goes through `tools/sibling_transplant.py` before you draft by hand. Search the community
   headers for every name you are about to invent (`grep -rn '<name>' .local/sources/CommonLibSSE-NG/include`).
4. **Pick the recipe from the float evidence.** If the target compares floats against zero with a
   parity branch, widens `fabsf` through double, or the first attempt shows a parity-flag jump the
   target lacks, set `Recipe: reconstruction/recipes/o2-fpfast.json` in the unit's header before
   spending attempts on source shapes (cookbook rule 48). A unit the target compiled for size uses `o2-os` (`/Os`).
5. **Bind hints first.** Run `attempt` once on the skeleton, read the `UNBOUND` lines, and write every
   callee, data symbol and string-literal pool name you know into
   `<task-dir>/bind-hints.json` before changing any logic. An unbound callee scores as a different
   function and hides the real first mismatch. A made-up member name that equals an existing symbol
   name binds silently to that symbol's RVA: check missing callees against your own names.
6. **Names and layouts.** `python3 tools/pdb_facts.py 0x<rva>` (CrashLogger and sibling-symbol
   candidates), `python3 tools/header_index.py --class <Class>` (published declarations and
   slots), `reconstruction/generated/crashlogger_pdb/` and `reconstruction/declarations/`.
7. **Draft, then loop.** `tools/verifier/attempt <task-dir>`; read `attempts/<NNN>/0x<rva>/side-by-side.txt`
   locally; keep going while matching bytes rise.
8. **Register-only or schedule-only residue** (same instructions, different registers or order):
   stop editing by hand and run the permuter (below), then explain the winner in authentic source.
9. **Idiom you have not seen** (SIMD shuffles, STL instances, scope guards): search the sibling
   listings and the library-shape index (below) for the shape before writing it from scratch.
10. **Before finishing:** `check_labels`, `check_origin`, `lint_reconstruction`, `check_code_rules`
    on your files, then a lesson note only for what the cookbook does not record.

## Resources

All commands run from the repository root of the worktree you draft in. `<task>` is your task
directory (`.local/tasks/<id>` or `.local/contrib/tasks/<id>`).

| Resource | Command or path | Use when |
|---|---|---|
| Context pack and listing | `./sr start 0x<rva>` writes the pack (`listing.txt`, `pack.json`, `bytes.txt`) under `.local/contrib/packs/`; internal tasks come with a pack in the brief | Reading the target. Never `cat` `pack.json` or `bytes.txt`: they hold the raw function bytes on one line |
| Unit sheets | `python3 tools/sheet.py <task>/<unit dir> --function 0x<rva>` (`--page N`) | A compact page of one function: listing, callees, prototype hints, in tool-output-sized pages |
| Skeleton | `python3 tools/skeleton.py <task>` (`./sr start` does it) | Starting `.h`/`.cpp` with the header and one stub per compared function |
| Attempt loop | `tools/verifier/attempt <task>` (`--rule N` on the passing run, `--model <id>`) | Every compile and compare; prints PASS/FAIL, first mismatch, matching-byte progress |
| Side-by-side and align | `<task>/attempts/<NNN>/0x<rva>/side-by-side.txt`, `tools/verifier/align.py --attempt <task>/attempts/<NNN>` | Reading why a function fails: `*` rows differ outside relocations; align prints the weighted distance and moved blocks |
| Bind hints | `<task>/bind-hints.json` (format in the [card](drafter-card.md), "Names and binding") | `UNBOUND` lines, string literals, thread-locals, vftable thunks |
| Matching cookbook | [docs/matching-cookbook.md](matching-cookbook.md): ranking table first, rule by `#rule-N` | Before the first draft, and for any near-miss. Ranking: `python3 tools/cookbook_rank.py --check` |
| Cookbook hits | [docs/cookbook-hits.json](cookbook-hits.json), the "Which rules matter most" table | Deciding which rule to try first: fixed and still-failing counts per rule |
| Lesson notes | `ls docs/cookbook-notes/`; write one with `python3 tools/cookbook_notes.py --new 0x<rva> ...` | Reading: your class or cause. Writing: only a fix or cause the cookbook does not record |
| Sibling source: FNV, F3 | `.local/sources/fnv_decomp`, `.local/sources/f3_decomp`; the task's `sibling.md` lists same-named methods and small accessors | Helper boundaries, argument order, accessor forms, names. Label what you take `SIBLING(...)` and add the `Sibling source:` header line |
| Sibling source: FO4 private | `.local/sources/fo4-private-index` (exact qualified-name hints in `sibling.md` variants), game-code folders only | Same as above for FO4 game code; anonymity rules in the [card](drafter-card.md); never name its origin in tracked files |
| Sibling x64 hints | `sibling_x64.json` in the task; `python3 tools/x64_lookup.py --index-dir .local/contrib/x64-index --exe <image> --objdump <llvm-objdump> <rva>:<size>`; index fetched by `./sr setup` or `python3 tools/x64_index.py fetch --dest .local/contrib/x64-index` | First check for every function: the closest compiled Fallout function by code shape and its source line |
| Sibling transplant | `python3 tools/sibling_transplant.py` (`plan`, `write`, `run`; see its header) | An `exact_shape` or near-shape candidate: cuts the body and its declarations into a unit with the labels already written |
| Sibling x64 corpus | `python3 tools/f3x64/lookup.py rva|idiom --root .local/f3x64/shadow --srcmap .local/f3x64/srcmap.pkl ...`; `tools/f3x64/corpus.py`, `cluster.py`, `lab_experiments.py` ([sibling-x64](sibling-x64.md)) | "How does the sibling source spell this instruction pattern?" and checking a cookbook rule against compiled sibling listings |
| Library-shape index | `tools/msvclib/index.py sigs|leads|family`, data in `.local/msvclib/` | CRT/STL-heavy code with no sibling source: find std:: template instances of the same shape; passes become `OBSERVED` units |
| Community headers | `.local/sources/CommonLibSSE-NG/include`, `CommonLibSSE-po3`, `AddressLibraryDatabase`; `python3 tools/check_labels.py <files>` | Naming any class, member, enum or slot: search first, label `COMMUNITY`, check the label afterwards |
| Declaration kit | `reconstruction/declarations/`, [declaration-kit.md](declaration-kit.md), `python3 tools/declaration_kit.py` | Base-class chains (`NiNode`, `TESForm`, `BSTEventSink`): include `"declarations/<Class>.h"` instead of inventing a stand-in |
| CrashLogger names and layouts | `reconstruction/generated/crashlogger_pdb/`, `python3 tools/pdb_facts.py 0x<rva>` | Names, prototypes, sizes and layouts; label `CRASHLOGGER_PDB(59818@<version>)`; a name is a lead, not identity |
| Sibling symbol names | `data/symbol-names.json` (candidates per class), `data/name-corroboration.json` (verdict per published name) | A member name for a placeholder-named function; label `SYMBOLS(<source-id>)` |
| Published header index | `python3 tools/header_index.py --class <Class> [--slot N]` | Which declarations, slots and known gaps are already published for a class |
| Include and unit paths | `python3 tools/unit_paths.py <Class>`, `python3 tools/check_include_resolve.py` | Where the unit goes; whether the include closure resolves |
| Recipes | `reconstruction/recipes/*.json`; `o2-fpfast` (fast float), `o2-os` (size), `-reconstruction` (cross-area includes), `-root-includes` (declaration kit) | Rule 48 for float evidence; a different compiler build only with a cookbook or comparator reason. Name the recipe on the unit's `Recipe:` line |
| Permuter | `tools/verifier/permute.py run <task> --rva 0x<rva> --dry-run`, then without `--dry-run` ([permuter.md](permuter.md)) | The function is complete, bytes are close, and the residue is register choice, scheduling or operand order. Needs a defined body in the unit |
| Matcher, wall-identifier and permute skills | `.claude/skills/matcher` (with `levers.md`), `.claude/skills/wall-identifier`, `.claude/skills/permute` | A plateau: classify the wall first (call set, control flow, register/schedule, masked), then use the lever for that class; permute for the search |
| Origin check | `python3 tools/check_origin.py <files>` | Before finishing: lists bodies close to a community or sibling body that need a header declaration |
| Code rules and lint | `python3 tools/check_code_rules.py --list <files>`, `python3 tools/lint_reconstruction.py <files>` | Before finishing: readable-source findings (advisory) and the hard source rules |
| Worktree kit | `python3 tools/worktree_kit.py <worktree> [--check]` | A new worktree, or any time a tool cannot find `.local/sources`, the x64 index or the analysis tables |

## What a fresh worktree has

A git worktree starts without `.local/`. Several tools fall back to the main checkout's private
folder per resource, but raw paths and scripts do not. `tools/worktree_kit.py` adds, without
replacing or deleting anything and only below the worktree's own `.local/`:

- links to `sources`, `f3x64`, `fnvx64`, `msvclib`, `toolchains`, `inputs` and `config`;
- missing analysis tables (`functions.jsonl`, `classes.jsonl`, the FNV index and its metadata,
  `origin-index`), the sibling x64 index under `contrib/x64-index` and the FNV index under
  `contrib/analysis/`, which `./sr start` reads for the "Sibling source" section;
- `verifier/config.json` (a copy: image and objdump paths) and `verifier/runners.json` (a link);
- a `contrib/config.json` with the executable path when none exists. An existing config is never
  edited; the command then prints the `SR_SKYRIM_EXE` line to export.

`--check` prints the table without changing anything. Worktree creation helpers
(`tools/draft_worktrees.py`, `tools/sparse_checkouts.py`) call the same function.

Export `SR_SKYRIM_EXE` (the path of your own game executable) in the same shell command that runs a
tool that reads the image; the exported variable does not persist between separate commands in some
shells. If your shell does not split an unquoted variable into words (zsh), define a function for a
repeated command instead of storing it in a variable.

## Reporting

Report each slow step, repeated failure or surprising tool output as one line with an estimated
time cost, under a "Bottlenecks" heading in your result or PR (name the tool and step, never bytes
or listing text). A lesson note belongs in `docs/cookbook-notes/` only when the cookbook lacks it.
