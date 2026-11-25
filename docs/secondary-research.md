# Secondary research during decompilation and rebuild

This guide tells an agent or contributor how to use sources about other games, and public
community knowledge, while reconstructing a Skyrim function. It grants nothing. Every permission
named here comes from a maintainer decision in `docs/authorizations.md` (Notes), `LEGAL.md`,
`PROVENANCE.md` and `AGENTS.md`. If this guide and those files differ, those files win.
It follows `docs/anti-eu-bureaucracy.md`: it adds no gate and no review step.

## 1. Purpose and scope

"Secondary research" means any source that is not the pinned Skyrim binary (`builds/target.json`)
and that helps you reconstruct one Skyrim function. Examples are the Fallout sibling
decompilations, community header libraries, name lists and symbol files.

| Claim | What secondary research can show | What it never shows |
|---|---|---|
| Byte match | Nothing. Only the comparator decides (`docs/verification.md`). | Equivalence to the Skyrim binary. |
| Semantic equivalence | A hypothesis about intent. | A proof of it. |
| Name or layout | A candidate name, a member role, a shape to test. | Identity of a function, an offset, a vtable slot or a size. |
| Name similarity | That a class of that name existed in another game. | That the two classes behave alike. |

Rules that apply to every source in this guide:

- Address identity is `(build id, RVA)`. No address, slot, offset, layout or form ID moves from
  another game to Skyrim without proof on `sse-steam-1-7-104`.
- A source is a lead. A sibling compiled as x64 (`docs/sibling-x64.md`) is also a lead.
- Reading a sibling is source exposure (`docs/clean-room.md`). Labels and `Sibling source:`
  lines record it. Do not claim to be an unexposed implementer after you read one.
- No game bytes, disassembly or decompiler text goes into a unit, a note or this guide.
- This guide does not change the privacy rules of `AGENTS.md`. Read access on your machine is not
  permission to upload game-derived text to a service.

## 2. Source register

State of `origin/main` on 2026-11-23. "Decision" quotes the date recorded in
`docs/authorizations.md`. The legal wording stays in that file and in `LEGAL.md`.

| Source | Pin | Licence or permission basis | Decision | Allowed use | Label |
|---|---|---|---|---|---|
| FNV decompilation `momusdigital/fnv_decomp` | `2b07cb3e` (upstream main). The earlier pin `91e1b6e8` stays valid for merged units. | CC0 1.0 for the contributors' own work since upstream commit `42baf49a` (2026-11-18). Earlier revisions granted no licence. The README tags some names as from an Xbox 360 development-build PDB, Havok source or Gamebryo source. Those names are not covered by CC0. | 2026-11-12 (read and reuse). The pin move to `2b07cb3e` is recorded in the Notes block dated 2026-11-24. | Read, names, declarations, bodies, with the limits in section 5, trap 9. | `SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0)`. Old units keep `SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)`. |
| Fallout 3 decompilation `momusdigital/f3_decomp` | `f5bac1b5` | CC0 1.0. The README says much of the code started from FNV matching functions, so treat F3 as largely derived from FNV. | 2026-11-21 | Read, names, declarations, bodies. Declare a reused body as an adapted body. | `SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0)` |
| `fo4-private` (anonymous Fallout 4 game-code sibling) | `1b765c70` | Author permission on condition of anonymity. Not a general licence. Not dedicated to CC0. | 2026-11-14 | Read, names, declarations, bodies, inside the folder allowlist in `docs/authorizations.md`. Middleware folders and generated aggregates are excluded. | `SIBLING(fo4-private@1b765c70, author-permission)` |
| Sibling-build symbol files (`tesv-2013-map`, `fo4-pdb`, `fnv-x360-pdb`) | SHA-256 in `docs/authorizations.md` | Maintainer decision. Files are never committed or shared. | 2026-11-21. Widened 2026-11-22 for the 2013 map and the Fallout 4 files. | Names for all. Full use (prototypes, layouts, vtables, hierarchies) only for the 2013 map and the Fallout 4 files. The three Xbox 360 files stay name-only. | `SYMBOLS(<source-id>)` |
| CommonLibSSE-NG `CharmedBaryon/CommonLibSSE-NG` | `b93280e` | MIT. Keep the MIT notice in a file that holds adapted code (`SOURCES.md`). | Recorded in `SOURCES.md`. | Names, declarations, small cited excerpts. | `COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)` |
| CommonLibSSE-po3 `powerof3/CommonLibSSE` | `654e55f` | GPL-3.0-or-later. A file that uses its names states GPL-3.0 in its header. | 2026-11-12 | Names and declarations. No body is adapted from it. | `COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)` |
| Address Library database `meh321/AddressLibraryDatabase` | `0379cb6` | No licence file. Used with the author's permission, as the maintainer reported. | 2026-11-12 | Names (`skyrimae.rename`). | `COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)` |
| CrashLogger-derived generated files (Nexus mod 59818) | `2026.10.24` | Community-generated PDB, not Bethesda symbols. The `.pdb` is never committed. | 2026-11-20 | A naming and layout source. Generated output lives in `reconstruction/generated/crashlogger_pdb/`. | `CRASHLOGGER_PDB(59818@2026.10.24)` |
| CommonLibF4 `Ryan-rsm-McKenzie/CommonLibF4` | none pinned | MIT | No decision recorded. `findings/community-resources.md` rates it "study only" for layouts, never addresses. | No decision recorded: read for names only, ask before reuse. | none defined |
| `libxse/commonlibf4` and GPL forks of CommonLibF4 | none | GPL-3.0 | None. The GPL decision of 2026-11-12 covers the powerof3 fork only. | Do not reuse. Do not read bodies. | none defined |
| Any other source | none | n/a | Needs its own maintainer decision. | Metadata only until the decision exists. | none defined |

Facts that matter when you pick a source:

- Upstream FNV moved to CC0 after our first pin. The pin moved to `2b07cb3e`. Another upstream
  revision needs its own decision.
- A name taken from a CC0 file can still be a name that upstream took from a source CC0 does not
  cover (trap 9).
- F3 function names are mostly placeholders in the name-level appraisal of 2026-11-23, and F3
  was not read at body level. Prefer FNV for names. Read F3 when FNV has no counterpart.
- The two Fallout 4 sources are different. `fo4-private` is game code with anonymity terms. The
  `fo4-pdb` symbol file is a name source with its own label. Do not mix the labels.
- `fo4-private`: use only that identity. Never write the upstream repository, owner, URL or
  nickname in a tracked file, a commit message, CI or any file under `reconstruction/`.
- Other public sources were assessed and are listed with their status in
  `findings/community-resources.md`. A listing there is not a decision.

## 3. Reuse map by category

These ratings are planning aids from a name-level appraisal dated 2026-11-23. The appraisal
joined class names and function counts. It did not compare bodies and it measured no match
rate. A shared class name does not show shared behaviour. Ratings that fell between two levels
are rounded down. The FO4 column rates the public header library only. `fo4-private` was not
appraised; section 6 shows where its labels already sit.

Kinds: **N** names and declarations, **A** algorithm knowledge (no text), **B** bodies,
**T** test oracle (behaviour comparison; a local aid only, `docs/clean-room.md`).

| Skyrim category (`reconstruction/`) | FNV | F3 | FO4 | Useful kinds, main limit |
|---|---|---|---|---|
| `gamebryo/nimain` | HIGH | MED | MED | N, A; B after rework. Layouts and vtables differ. |
| `gamebryo/nianimation` | HIGH | MED | LOW | N, A. Skyrim has many more spline types. |
| `gamebryo/niparticle` | HIGH | MED | LOW | N, A. Skyrim-only modifiers have no counterpart. |
| `skyrim_shared/forms` | MED | LOW | MED | N, A. Form layouts and flags changed. |
| `skyrim_shared/world` | MED | LOW | MED | N, A. Terrain, LOD and grass are new code. |
| `skyrim_shared/actors` | MED | LOW | MED | N, A. Process data is split differently. |
| `skyrim_shared/refs` | MED | LOW | MED | N, A, T. Projectile family matches best. |
| `skyrim_shared/extradata` | MED | LOW | LOW | N. The extra-data base object has a different size in FO4. |
| `skyrim_shared/magic`, `skyrim/magic` | MED | LOW | LOW | N, A. Casting classes were restructured or cut. |
| `skyrim_shared/pathfinding` | MED | LOW | MED | N, A, T. Navmesh format changed. |
| `skyrim_shared/perks` | MED | LOW | MED | N, A. Entry-point lists differ. |
| `skyrim_shared/quest`, `dialogue` | MED (dialogue), LOW (quest) | LOW | MED | N, A. Scenes are new in Skyrim. |
| `skyrim_shared/tempeffects` | MED | LOW | LOW | N. Decals were reworked. |
| `skyrim_shared/facegen`, `saveload` | MED | LOW | LOW | N, A. Save format differs. |
| `skyrim_shared/audio` | LOW | NONE | MED (forms) | N. Reverb and music wrappers are Skyrim-only in FNV. |
| `skyrim_shared/conditions`, `sky` | LOW | LOW | LOW | N. Most `conditions` units are generated thunks. |
| `skyrim_shared/inventory` | LOW | LOW | NONE | A. FO4 replaced the inventory model. |
| `skyrim/ai` | LOW | LOW | MED | N, A. Skyrim combat trees are new. FO4 packages and attack data are closer. |
| `skyrim/camera` | LOW | NONE | MED | N, A. Same state-machine design in FO4. |
| `skyrim/controls`, `bsinput` | NONE | NONE | LOW | N. |
| `skyrim/interface`, `bsscaleform` | LOW | NONE | LOW | A. Skyrim uses Scaleform. Do not reuse vendor material. |
| `skyrim/papyrus`, `bsscript` | NONE | NONE | LOW | A. Different virtual machine in every game. |
| `bscore`, `bsmain` | LOW | NONE | MED (containers, locks), else LOW | N. Memory and task code differ. |
| `bssystem` | MED | MED | LOW | N, A. Stream and file classes. Archive format differs. |
| `bsshader` | LOW | LOW | LOW | N, A. Shader models differ. |
| `bsaudio` | LOW | NONE | NONE | N. Engine side uses a different audio library. |
| `bshavok` | LOW | LOW | NONE | N. Different Havok version in every game. |
| `unmapped/static`, `leaves`, `storage`, `buffers`, `fields`, `represented`, `wrappers`, `support` | NONE | NONE | NONE | None. Units have placeholder names, so no class counterpart exists. |
| `contrib_*` (single-class units) | Rate as the parent category | | | |
| `declarations`, `generated`, `recipes`, `thirdparty` | Not rated | | | Tooling and data, not engine classes. |

## 4. Procedure

### During decompilation (one function)

1. **Find the Skyrim class and function.** Use the unit, the inventory entry and its name origin.
2. **Find sibling counterparts by exact class name.** Look in the pinned clones under
   `.local/sources/<name>` and in the pack's "Sibling source" section (`docs/drafter-card.md`).
   Check the class header. Different classes can share an identifier.
3. **Read names and declarations first.** Take base classes, member roles, enum names and method
   order as hypotheses.
4. **Check the traps in section 5.** Derive every offset, size and vtable slot from Skyrim evidence.
5. **Adapt a body only when the source allows it and you label it.** Re-express the logic for
   the Skyrim compiler. A body from an older unoptimised build gives shape, not code to paste.
6. **Compile and compare.** `attempt` and the comparator decide (`docs/drafter-card.md`).
   Stop at the budget the tool prints.
7. **Record the source.**
   - Put the label on the name line (`// <names>: <LABEL>`).
   - Add one `// Sibling source: <repo>@<rev> <path>:<line>` line to the unit header for each
     reused body.
   - Declare the body as an adapted body (method, upstream file, revision, licence).
   - Run `python3 tools/check_labels.py <unit>.h <unit>.cpp` and
     `python3 tools/check_origin.py <unit>.h <unit>.cpp`. A reused body without a
     `Sibling source:` line blocks acceptance.
8. **Flag a rights concern.** If provenance is uncertain, stop using that source for that unit.
   Record the question without copying the suspect content. Tell the maintainer. Unrelated work
   continues (`AGENTS.md`).

### During rebuild (readable source after a match, `docs/code-rules.md`)

Follow the same steps, plus:

- Take a sibling name only when you can label it. Do not restyle a unit to another unit's style.
- Recompile and compare after every edit. A better name never excuses a changed byte.
- Keep sibling-derived code removable. Use one label per name line, one `Sibling source:` line
  per reused body, and one adapted body per citation. A rights holder who objects must be able
  to find and delete each piece.
- Do not add a sibling name to a unit that has no use for it.

## 5. Traps

| # | Trap | What differs | What to do |
|---|---|---|---|
| 1 | 32-bit against 64-bit | FNV and F3 are x86. Skyrim SE is x64. Pointer size, padding, alignment, offsets and vtable slots all differ. | Take names and field roles only. |
| 2 | Compiler and `/Od` | Skyrim is MSVC 19.16.27054 x64 `-O2`. FNV is VC 2008 SP1. F3 is VC++ 2005 SP1. About two thirds of FNV function bytes (name-level estimate) sit in units built `/Od`, so the code has temporaries and no inlining. `fo4-private` is a VS2012 build. | Expect a different shape. Read unit flags before you trust a body. |
| 3 | Gamebryo 2.x against the Creation Engine fork | The `BSGeometry` and `BSTriShape` family has no FNV class. FNV `NiTriShape` can inform only the older `NiTriBasedGeom` family. | Do not search FNV for that family. |
| 4 | Process model | FNV uses `HighProcess`, `MiddleHighProcess` and `LowProcess`. Skyrim uses `AIProcess` and `ActorProcess`. | Re-derive logic that reads process data. |
| 5 | Rendering | FNV shaders are D3D9. Skyrim SE uses DX11 shader families. | Expect little reuse in `bsshader`. |
| 6 | Havok version | FNV links Havok 7.1. Skyrim uses `hkp` and `bhk` classes of a later version. FO4 moved to `hknp`. | Do not copy collision shapes or controller layouts. |
| 7 | Naming style | FNV uses `m_` plus type prefixes. Skyrim units use community-style names. | A sibling name is a rename, not a paste. |
| 8 | Subsystems without a counterpart | UI (Tile or Scaleform), script machines, audio and input back ends differ in every game. | Do not budget reading time there. |
| 9 | Name tags in FNV | README tags some names as from an Xbox 360 development-build PDB, Havok source or Gamebryo source (tags such as `XBOX_PDB`, `HAVOK_SRC`, `GAMEBRYO_SRC`). Large game classes carry many of them (name-level estimate). `AGENTS.md` says these names are not covered by CC0 and stay excluded at the current pin. | Check the tag of each name before you take it. Do not take a tagged name until the maintainer answers question 2 in section 7. |
| 10 | FO4 base-class sizes | In the public FO4 headers, `BSExtraData` is 0x18 (Skyrim community header: 0x10), `NiAVObject` is 0x120 (0x110) and `NiNode` is 0x140 (0x128). The `NiObject` vtable also differs. | No derived layout or slot transfers. |
| 11 | Name coincidence and variant files | Examples: `TaskQueueInterface`, `Script`, `MemoryHeap`, `BSFile`. FNV also has placeholder and `_variant` files that compiled differently. | Compare the header, not only the identifier. |
| 12 | Address Library and `REL::ID` numbers | They belong to other runtimes. | Never use them as Skyrim addresses. |

## 6. Realised reuse so far

Measured on `origin/main` at `0fd62d4d27`, 2026-11-23, with `git grep` from the repository root.
A citation shows that a unit claims reuse. It does not show that reuse helped.

```sh
git grep -l  "Sibling source: <repo>" -- reconstruction | wc -l    # files with a body citation
git grep -h  "Sibling source: <repo>" -- reconstruction | wc -l    # citation lines
git grep -l  "SIBLING(<repo>"         -- reconstruction | wc -l    # files with a name label
```

`<repo>` is `momusdigital/fnv_decomp`, `momusdigital/f3_decomp` or `fo4-private`. Add
`':!reconstruction/unmapped/static'` (or `unmapped/leaves`) to separate the bulk family.

| Source | Files with a body citation | Citation lines | Files with a name label | Bulk family | Files outside the bulk family |
|---|---:|---:|---:|---|---:|
| FNV | 10,828 | 10,873 | 10,787 | 10,710 files in `unmapped/static` (5,355 units, a `.h` and a `.cpp` each) cite one line, a one-helper static initializer. | 118 files (80 units), 163 lines |
| F3 | 71 | 86 | 11 | None. Some lines record a similarity, not a copied body. | 71 files |
| `fo4-private` | 900 | 1,121 | 933 | 328 files in `unmapped/leaves` cite one header. | 572 files, 793 lines |

Read the table with these limits:

- All FNV citations use the earlier pin `91e1b6e8`. No file yet cites `2b07cb3e`.
- The meaningful FNV body citations are the 118 files outside `unmapped/static`. By folder they
  sit mostly in `skyrim_shared/forms`, `skyrim_shared/world`, `gamebryo/nimain` and
  `skyrim_shared/extradata`.
- Outside `unmapped/leaves`, `fo4-private` citations sit mostly in `skyrim/ai`, `skyrim/magic`,
  `skyrim_shared/forms`, `skyrim_shared/refs`, `skyrim_shared/pathfinding`, `skyrim_shared/actors`
  and `skyrim_shared/world`.
- The repository holds no data that compares sibling-aided drafts with unaided drafts. Any claim
  that a sibling raised the pass rate is unmeasured.
- The counts are files, not functions. A join with `reconstruction/INDEX.md` would give a share
  of matched functions. This guide does not provide that join.

## 7. Decisions of the maintainer

All five questions that stood here are closed. The decisions are recorded in
`docs/authorizations.md` ("Community and sibling source decisions") and apply to any worker.

1. Newer CC0 sibling revisions (FNV, F3) are adopted by a tooling PR that moves the pin; there is
   no per-revision ask. Labels on an older pin stay valid with their own licence word.
2. Names tagged as taken from an Xbox 360 PDB are authorized in bulk (PR #572, label
   `SYMBOLS(<source>)`). Havok and Gamebryo source stays excluded.
3. A per-class map from Skyrim classes to sibling files may be published.
4. CommonLibF4 (MIT) may be used for names, declarations and bodies, labelled
   `COMMUNITY(CommonLibF4@<pin>, MIT)` (written with the `<owner>/<repo>` the label grammar needs).
5. GPL forks of CommonLibF4 (for example `libxse/commonlibf4`) and any other community library
   are allowed, labelled `COMMUNITY(<owner>/<repo>@<pin>, <SPDX>)`. A GPL label needs the file's
   leading comment to state the GPL licence (`tools/lint_reconstruction.py`).
