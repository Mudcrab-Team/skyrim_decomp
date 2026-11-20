# Finding: stamping matched exemplars onto byte-identical-modulo-references leaf functions

Status: OBSERVED local comparator results; selection and mapping only, no accepted matches.
Author / human operator: awarebayes
AI assistance / model: Claude Code Engineer worker (Claude Sonnet 5.5), run locally; no game file or game-derived output was uploaded to any service
Date (UTC): 2026-11-19
Target build id / image SHA-256: `sse-steam-1-7-104` (image hash pinned in `builds/target.json`)
Function RVA / size (if applicable): the RVAs added to `data/progress.json` with evidence `findings/stamp-sweep-leaves.md`; sizes 8 to 52 bytes
Source exposure: binary-analysis (local masked-code clustering of the pinned image's functions and the comparator's own references); no community or sibling declaration is reused
Sources and immutable revisions / licenses: matched exemplars of this repository (RVAs below, their published units); `tools/analysis/clusters.py` and `tools/analysis/stamp.py` at the repository revision of the pull request; no third-party source
Name provenance: GUESS (placeholder class names built from the RVA; no owner, signature or original name is claimed)
Confidence: high that each listed function is byte-identical to its exemplar once the comparator's reference fields are blanked; low for every name and every class layout

## Question and method

Many not-matched functions have the same code as an already matched function once the fields the
comparator treats as references (calls, jumps, vftable and global addresses) are blanked and
compared with the same field layout, unwind data and displacements. Such a function differs from
its exemplar only in WHICH symbols it references, so the exemplar's source with other symbol names
should compile to it. This finding records the selection: functions are grouped by the masked-code
hash of the private function table (`tools/analysis/clusters.py` definition of the L1 level), and a
group is used when it holds a matched exemplar and at least one function that is not matched.

Exemplars and their shape (the source of each is public in this repository):

| exemplar RVA | unit | shape |
|---|---|---|
| 0x1259aa0 | `reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp` | scalar deleting destructor, abstract base chain, sized delete of 16 |
| 0x10fd30 | `reconstruction/bscore/ArrayAllocatorLeafLayout.cpp` | scalar deleting destructor storing its vftable, sized delete of 16 |
| 0x1507e00 | `reconstruction/bsshader/BSImagespaceShaderBlur3.cpp` | scalar deleting destructor calling the out-of-line destructor, sized delete of 0x1a8 |
| 0x20b3d0 | `reconstruction/unmapped/wrappers/F004Represented20b3d0.cpp` | same shape, sized delete of 56 |
| 0x17c1e0 | `reconstruction/unmapped/represented/F004Recovered17c1e0.cpp` | same shape, sized delete of 48 |
| 0x390cc0 | `reconstruction/skyrim_shared/forms/TESModelTri_390cc0.cpp` | constructor calling a base constructor and storing a vftable |
| 0x5dd1d0 | `reconstruction/skyrim_shared/sky/SkyEffectController.cpp` | move of the second argument into the first and a tail call |
| 0x146720 | `reconstruction/skyrim_shared/forms/TESFullName.cpp` | member address adjustment and a tail call |
| 0x2dd530 | `reconstruction/skyrim_shared/refs/TESObjectREFR_2dd510.cpp` | one call whose result receives `this` in a tail call |

A shape that no entry cites has not produced a passing unit at the time of mapping and is not claimed.

Each selected function becomes a `mapped` entry with a placeholder class name made from its RVA
(`DeletingLeaf<rva>`, `CtorLeaf<rva>`, `ForwardLeaf<rva>`, `ThunkLeaf<rva>`, `RelayLeaf<rva>`), the
size of the function table, and `GUESS(low)` as name source. Only functions whose generated unit
passed the unchanged comparator locally are mapped. A unit declares the smallest stand-in classes
that produce the code (a root class with a virtual destructor, an abstract base for the deleting
shape without a vftable store, a base class for the constructor shape); the object sizes in the
deleting shapes come from the exemplars' published `static_assert`s, which the comparator confirms
through the sized-delete immediate. No stand-in claims a real class layout; unknown storage is a
labelled `unknown08` stand-in.

## Observations

- Within one group the compared code differs only in reference targets, so one template per group
  serves every member; the comparator binds each reference by position from the target's own field.
- Class names, field names and callee names are invented; the comparator proves bytes, not names.

## Interpretation and alternatives

A byte match shows these stand-ins produce the compared code. It does not show the original class
names, hierarchy, field layout or that two functions of one group belong to related classes. An
owner class read from the image RTTI could name some members; none is used here so that no name or
ownership is asserted.

## Reproduction and sanitized evidence

The units are generated from per-group templates and compared with the project's local comparator
(`tools/contrib.py compare`, pinned MSVC under Wine); the project's own hosts repeat the compare.
No bytes, disassembly or private paths are published.

## Negative results and limitations

Groups whose members cannot be produced from one stand-in (functions of a named-class family with a
distinct body, template owners, thread-local or sibling-derived bodies) are not selected here.

## Reviewer and outcome

Mapping only; no function is accepted by this finding.
