# Finding: symbol files of sibling builds as a naming and unit-boundary source

Status: HYPOTHESIS
Author / human operator: lemiur
AI assistance / model: Claude Code (claude-fable-5-2), run locally on the operator's machine
Date (UTC): 2026-11-20
Target build id / image SHA-256: `sse-steam-1-7-104` /
`846efccf0c1374d7-1f892907f4654956-0f2fcb0a75cb87a3-eed438baa0f1402f`
Function RVA / size (if applicable): not applicable
Source exposure: mixed (this repository's tracked files; the public symbol tables of one linker
map and four program databases held by the operator, read locally; the model saw class and
member names from them, no code, no bytes and no executable)
Sources and immutable revisions / licenses: this repository at `a3514b259`; the five symbol
files below, identified by SHA-256 (written in four 16-digit groups joined by `-`), no license grant
Name provenance: sibling-build symbols; label `SYMBOLS(<source-id>)` (see the decision below)
Confidence: high for the counts; low to medium for any single name as a name in the pinned image

## Question and method

`docs/code-rules.md` asks for names from evidence (R7), functions in their real class (R12) and
original unit boundaries (R15). The strongest evidence for all three is a symbol file. What do
the symbol files of sibling builds say about the names this repository already publishes?

`tools/symbol_corroboration.py` read each file's public symbols (for the map, also the object
file of each function that is not inline), split every decorated name into class and member,
and compared them with `name` in `data/progress.json`. It wrote two files:

- `data/name-corroboration.json`: per published `Class::Method` name, which sources have that
  member in that class (`confirmed`) and which have the class without it (`absent`).
- `data/symbol-names.json`: per class the inventory names, the map's object files for its
  member functions, and, where the class still has placeholder or unconfirmed names, the member
  names the sources give that no inventory function of the class uses.

No executable in the operator's archives was extracted or read. No address, type, decorated
name or symbol of a class the inventory does not name is in either file.

## Observations

| key | label | kind | bytes | SHA-256 | public symbols | classes |
|---|---|---|---:|---|---:|---:|
| a | `tesv-2013-07-17-map` | linker map | 41,662,359 | `fed7f0b964ea752f-e677f4c413c37c97-b5cad21541755c69-c701a66423b288b2` | 283,377 | 6,515 |
| b | `fo4-2019-10-23-pdb` | program database | 452,201,472 | `6c5db527eaa981c1-c258b4523c21b677-4332b2fe520bb5fa-25ae96e2dde01917` | 498,817 | 10,489 |
| c | `fnv-x360-2010-07-21-pdb` | program database | 124,808,192 | `c2893c7b5377d76d-7d5c7fe6b05d9b1c-be1084b63b9d3b69-5db92473a55c1d6b` | 107,045 | 3,519 |
| d | `fnv-x360-2010-08-22-pdb` | program database | 125,144,064 | `ec702dc52f42a9c1-4037b800871d727a-f2b54ed191d68ae5-fcde3bfce65e6f00` | 107,231 | 3,522 |
| e | `fnv-x360-2010-11-10-pdb` | program database | 125,168,640 | `24f166f1aceb3e16-a056044b9ee164b4-0fbaf47e9ce441ba-3dc5e26f37cbfa10` | 107,322 | 3,523 |

The map's own header: module `TESV`, link timestamp `51e657ad` (2013-07-17 17:37:01), preferred
load address `00400000`, so a 32-bit build of the earlier edition of this game. The labels of
the other four repeat the dates in the operator's archive names; the files' own headers were
not read for a date. Each program database is the release configuration's, the one of several
in its archive.

| count | value |
|---|---:|
| inventory functions | 33,953 |
| with a class and a method name that are both real names | 3,904 |
| of which a source has the class | 2,547 |
| confirmed by at least one source | 1,982 |
| confirmed by every source that has the class | 1,682 |
| absent from every source that has the class | 565 |
| classes with an object file from the map | 885 (800 with one object, 85 with several) |
| classes with candidate names | 570 |
| candidate names | 19,259 |

| source | confirms | absent |
|---|---:|---:|
| `tesv-2013-07-17-map` | 1,875 | 609 |
| `fo4-2019-10-23-pdb` | 1,904 | 534 |
| each `fnv-x360-*` | 937 | 621 |

## Interpretation and alternatives

- 1,982 published names are members of the same class in a sibling build. That is
  corroboration of the name, by sources independent of the community headers the name came
  from. It is not evidence that the function at that address is that member.
- 565 names are in no source that has their class. Candidates to look at, not errors: a
  method can be renamed, inlined away or added between builds, a community name can be a
  description, and the comparison is by plain name with no overloads.
- The map's object column is the only evidence seen so far of original translation units.
  `reconstruction/README.md` keeps one pair per class "until the original translation units are
  evidenced"; for 800 classes the map agrees with that layout and for 85 it shows the member
  functions in several objects. It shows a 2013 build's units, which the pinned build may have
  changed.
- The candidate lists name what a class's members are called, never which function is which.
  Assigning one needs evidence from the compared code, because an address transfers to no other
  build (`AGENTS.md`, "Address identity"). No unit and no inventory name was changed.
- Alternative: none of this is used, and the names stay `COMMUNITY`, `GUESS` or placeholder.

## Reproduction and sanitized evidence

With the five files at `<local>/symbols/`, outside the repository:

    python3 tools/symbol_corroboration.py --source tesv-2013-07-17-map=<local>/symbols/TESV.map \
        --source fo4-2019-10-23-pdb=<local>/symbols/fo4/Fallout4.pdb ... --write

The tool refuses a source inside the repository. Its output is the two data files and the
counts above.

## Negative results and limitations

- Nothing here is evidence about the pinned image: other builds, other architectures (32-bit
  x86, PowerPC), another game for four of the five.
- Public symbols only. No type record was read, so there are no layouts, no vtable order and no
  member-variable types; the three New Vegas databases agree with each other almost entirely.
- Provenance of the files is not established here. Possession or a public URL is not
  authorization (`LEGAL.md`); the use is authorized by the maintainer decision below.
- **Decision.** The maintainer approved using these symbol files as name evidence on Reddit (the
  comments of <https://www.reddit.com/r/decomps/comments/1y1b11i/skyrim_decomp_wip/>) and confirmed that
  approval in chat on 2026-11-21. It is recorded in `docs/authorizations.md`, Notes ("Sibling-build symbol
  files as a name and unit-boundary evidence source"), with the five files by SHA-256 and size, the
  scope (name evidence only) and the conditions: the files and dumps of them are never committed, a name a
  unit takes from them carries a label, and the data files here are allowed as committed.
- **Widened scope (2026-11-22).** For `tesv-2013-map`, `fo4-pdb` and `Fallout4Beta.pdb` the "public symbols
  only, no layouts" limits described above are no longer limits on use; see `docs/authorizations.md`, Notes. The
  `fnv-x360-pdb` files stay name-only. Files and excerpts are still never committed.
- **Removal.** Everything taken from a symbol file is in `data/name-corroboration.json` and
  `data/symbol-names.json` and nowhere else. Deleting those two files removes it.
- **Label.** `SYMBOLS(<source-id>)`, with `<source-id>` one of `tesv-2013-map` (the map),
  `fo4-pdb` (the Fallout 4 database) or `fnv-x360-pdb` (the three New Vegas databases). The data files key
  their sources by the longer labels in the table above; the unit label uses the short id of the source
  kind.

## Reviewer and outcome

Authorized by the maintainer decision recorded in `docs/authorizations.md`, Notes. The counts are
the contributor's and were not recomputed (the symbol files are not held by the project).
