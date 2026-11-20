# Source reconstruction

Reconstructed source for functions that have a match record under `reports/`. A byte match does
not settle copyright status, and it does not verify a function's name or show what the original
source looked like. Each function's provenance is checked by a Reviewer subagent under the
acceptance rule in `docs/verification.md`, with provenance or legal doubt escalated. The
maintainer has decided that reconstructed source is published in this repository, organized by
engine area as below, in the same manner as the FNV decompilation project publishes its
reconstruction (`LEGAL.md`, "Publication of reconstructed source"). Changes to the matching gate
follow the acceptance rule's machinery-change path. Source is pushed only together with its
acceptance (`CONTRIBUTING.md`, "Publication"); a branch that holds integrated source still
awaiting a Reviewer approve stays local.
Do not copy raw decompiler output, proprietary middleware or unlicensed implementations. The one
exception is the FNV decompilation `momusdigital/fnv_decomp@91e1b6e8`, whose names, declarations
and code the maintainer allowed (`docs/authorizations.md`, Notes; `LEGAL.md`): label what is taken
`SIBLING(...)` and cite a reused body in a `Sibling source:` header line.
Read `LEGAL.md`, `PROVENANCE.md` and `docs/verification.md` before adding source.

## Layout

- **One pair per class** (except the static interval units below): `reconstruction/<area>/<Class>.cpp` holds the class's reconstructed
  member functions, and `reconstruction/<area>/<Class>.h` beside it the type declarations they
  need. The .cpp includes its header by a quoted name, so the unit compiles from the repository
  root with the recipe's flags and no include path. Every repository file a unit reaches through
  quoted includes belongs to its match record's translation unit; `tools/check.py` derives that
  set and rejects a record that omits or adds a file (`docs/verification.md`, "Match gate"). This stays the rule until the original
  translation units are evidenced (for example by RTTI or layout showing which classes shared an
  object); then a unit may hold several classes, as that evidence shows.
- **`<area>`** is one or more lowercase folders, chosen from the closed list `AREAS` in
  `tools/unit_paths.py`, which `tools/contrib.py`, the skeleton generator and the contributor intake
  all read. The areas follow the engine's own layers, the way the FNV decompilation lays out its
  folders: `gamebryo/` (the NetImmerse scene graph: `nimain`, `nianimation`, `niparticle`), the
  Bethesda engine libraries (`bscore`, `bssystem`, `bsinput`, `bsmain`, `bsshader`, `bsaudio`,
  `bshavok`, `bsscript`, `bsscaleform`), `skyrim_shared/` (data shared by the game's systems:
  forms, actors, extra data, conditions, magic, pathfinding, world, quests and the like),
  `skyrim/` (game logic: `ai`, `ai/combat`, `ai/movement`, `camera`, `controls`, `interface`,
  `magic`, `papyrus`) and `thirdparty/` (middleware, kept apart). `place(class)` in
  `tools/unit_paths.py` picks the area from the class name by ordered prefix rules; the few classes
  it does not decide are listed in `data/unit-areas.json`. A class with no rule is not filed
  anywhere by default: add a rule or an entry first. There is no `misc/`.
  A second unit of a class that already has one is `<Class>_<lowest rva>.cpp` and `.h` beside it.
  `declarations/` holds the published declaration kit and `recipes/` the compile recipes; neither
  is an engine area. Folders of the earlier one-folder-per-class layout are still accepted for
  units that were written against them and have not moved yet (`tools/migrate_layout.py` moves
  them); no new unit is started there. A moved unit keeps its digests, and its earlier path stays
  readable through `data/source-moves.json` for the comparator and CI evidence recorded at it.
  `tools/ghidra/export_pack.py` proposes the unit path with the same rules.
- **Owner-unknown compiler-generated static initialisers and teardowns.** Use
  `reconstruction/unmapped/static/`, grouping entries by the fixed 16-byte RVA interval containing
  their entry address. Name the unit `Static<lowercase hexadecimal interval start>`, and
  put its declarations in the corresponding header. Each header states that the owning
  system is unknown and referenced object names are stand-ins unless otherwise labelled.
  A member whose owner becomes known may move by a normal source change.
- **Stand-ins.** A unit may declare the other classes its functions use as minimal per-unit
  stand-ins (only the members and slots the compared code needs). Label them in the header as
  stand-ins, with the community source of each name. When a class is declared by several units
  (two units already declare their own `Actor`), it moves to one shared header in its own area;
  that move changes every affected unit's digest, so it is done together with their re-confirmation.
- **Primitive leaf interval units.** Trivial empty and constant-return leaves whose original
  signature or owner is unknown may use `reconstruction/unmapped/leaves/Leaf<entry RVA>.h` and `.cpp`.
  These are explicitly labelled minimal source stand-ins, with no claim of original class
  ownership. Every method name and placeholder class is `GUESS(low) STANDIN`; public naming
  evidence is retained separately. The family rule and ordinary comparison/review gates apply.
- **Census leaf ABI stand-ins.** `reconstruction/unmapped/leaves/LeafForward<rva>` and
  `LeafAddress<rva>` pairs isolate externally bound direct forwarders and global-address
  accessors whose original ownership or signature is not established. The class, method and
  reference names are explicitly guessed stand-ins, not recovered ownership. Each unit compares
  one complete externally bound entry with its own extracted reference; this layout makes no
  admission of other internal function kinds and leaves existing class units unchanged.
- **Generated PDB output.** `generated/crashlogger_pdb/` holds layout headers, a type index and RVA-to-name maps
  that `tools/pdb_types.py` regenerates from the CrashLogger community PDB. It is not an engine area and no unit
  lives there; a unit may include one of its headers, and then labels what it takes `CRASHLOGGER_PDB(59818@<version>)`.
  Do not edit it by hand: regenerate it.
- **One recipe per source unit.** A match record binds a translation unit to one recipe in
  `recipes/<compiler>-<flags>.json` (compiler binary hash and version, flags, SDK, host). If a
  class's functions need different recipes, split them into separate units, one per recipe,
  instead of mixing flags. Never edit a recipe that a record names; add one.
- **Middleware stays apart.** Code identified as third-party middleware is not mixed into game
  classes' units; it needs its own area and its own provenance and licence assessment.
- Paths are build-independent. The build id lives in the match record and the inventory, not in
  the path. A class whose source differs between builds would need a reviewed layout extension.

The translation unit's identity is `tools/source_digest.py`: a SHA-256 over every file of the unit
with its path. That digest is the `source_revision` the comparator task, build record and report
carry, the digest a Reviewer record binds, and what `tools/check.py` recomputes from these files
for every entry that names a match record.

## Header of each file

State the build id, RVA and size of each compared function, the evidence path, the source exposure
(`PROVENANCE.md` categories), the model or person who drafted it, and which community
definitions, at which immutable revision and licence, informed the types. Label community names
as unverified. Say which functions in the unit are compared and which exist only to make it
compile. Comments explain why, never when or at whose request.

New units write every name-origin label on a
line of the form `// <names>: <LABEL> [<LABEL>...][; note]`, LABEL being one of
`COMMUNITY(<owner>/<repo>@<rev>, <licence>)`, `GUESS` (optionally `GUESS(low|medium|high)`),
`EXE_RTTI`, `STANDIN` (with the name's origin label beside it) or `OBSERVED`.
`tools/lint_reconstruction.py` enforces the grammar in every unit file except eight legacy ones,
whose free-form labels stay because editing them would change their digests. Headers are short:
`Source exposure:`, the one-line SPDX notice for CommonLibSSE-NG declarations (full text in
`licenses/CommonLibSSE-NG.txt`), the label lines and one `// 0x<rva> <Name>` line per compared function.

## Contents

The status of every reconstructed function (unit, name and origin, identity, recipe, record,
status, review kind) is in `INDEX.md`, generated by `tools/build_index.py` from
`data/progress.json` and the records. Do not add per-function rows here or in `reports/README.md`;
`tools/check.py` fails when `INDEX.md` is out of date, and `tools/accept_function.py` rewrites it.

Approved integration selections enter the shared push lane with `tools/flow.py integrate`,
`integrate-groups` or `integrate-family`. These commands enqueue; `tools/flow.py lane-run`
combines all currently queued work, accepts and rebuilds the index once, checks the exact
combined tree, pushes and waits for CI. See `docs/orchestrator-runbook.md` for resume and
label-only refresh commands. Integration retains candidates and never prunes worker checkouts.
