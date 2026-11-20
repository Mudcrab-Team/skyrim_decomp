# Finding: twin propagation from matched placeholder exemplars

Status: OBSERVED local comparator results; selection and mapping only, no accepted matches.
Author / human operator: awarebayes
AI assistance / model: Claude Code Engineer worker (Claude Sonnet 5.5), run locally; no game file or game-derived output was uploaded to any service
Target build id / image SHA-256: `sse-steam-1-7-104` (image hash pinned in `builds/target.json`)
Function RVA / size (if applicable): the RVAs added to `data/progress.json` with evidence `findings/twin-propagation.md`
Source exposure: binary-analysis (local masked-code grouping of the pinned image's functions and the comparator's own references); no community or sibling declaration is introduced beyond what the cited exemplar units already carry
Sources and immutable revisions / licenses: matched exemplars of this repository (RVAs below, their published units); the analysis helpers of `tools/analysis/` at the repository revision of the pull request; no third-party source
Name provenance: GUESS (placeholder class names made from the RVA; no owner, signature or original name is claimed)
Confidence: high that each listed function has the same code as its exemplar once the comparator's reference fields are blanked, with the same target-sharing pattern; low for every name and every class layout

## Question and method

Every matched function is a candidate exemplar for functions that are not matched yet and have the same
code after normalisation. Two functions are strict twins when the bytes outside the reference fields
(calls, jumps, vftable and global addresses), the field layout, the unwind data and the pattern of which
reference fields point at the same target are equal (the `masked` level of `tools/analysis/clusters.py`
plus the sharing pattern, because the stamped source names one symbol per distinct target). Loose twins
also blank displacements and immediates (the `shape` level); loose twins are counted, not stamped.

Counts over the non-funclet functions of the pinned image (ordinary, static initializer, teardown,
thunk), with a matched and a not-matched member in the group:

| level | groups with both | not-matched functions covered |
|---|---|---|
| strict | 359 | 2564 |
| loose | 354 | 4316 |

A twin unit is stamped only when the exemplar's unit holds one compared function, names that function
with its own RVA in the class name (a placeholder stand-in), and the twin has no community name or
owner claim. The unit is the exemplar's source with the RVA substituted in every identifier, header
line and file name; labels (`GUESS(low)`, `STANDIN`, and any `COMMUNITY` or `SIBLING` declaration
source the exemplar already carried) are copied with it, and the `Code origin:` line names the exemplar.
Only twins whose unit passed the unchanged local comparator are mapped or published.

| exemplar RVA | exemplar unit | twins that passed |
|---|---|---|
| 0x10fca0 | `reconstruction/unmapped/leaves/TableStoreLeaf10fca0.cpp` | 18 |
| 0x112670 | `reconstruction/unmapped/fields/FieldLeaf112670.cpp` | 58 |
| 0x145670 | `reconstruction/unmapped/fields/FieldLeaf145670.cpp` | 7 |
| 0x17c100 | `reconstruction/unmapped/represented/F004Recovered17c100.cpp` | 7 |
| 0x17c780 | `reconstruction/unmapped/represented/F004Recovered17c780.cpp` | 6 |
| 0x184b80 | `reconstruction/unmapped/fields/FieldLeaf184b80.cpp` | 4 |
| 0x2f94e0 | `reconstruction/unmapped/represented/F004Recovered2f94e0.cpp` | 2 |
| 0x41cca0 | `reconstruction/unmapped/represented/F004Recovered41cca0.cpp` | 2 |
| 0x4497b0 | `reconstruction/unmapped/fields/FieldLeaf4497b0.cpp` | 5 |
| 0x5ba020 | `reconstruction/unmapped/represented/F004Recovered5ba020.cpp` | 1 |
| 0x5ba8b0 | `reconstruction/unmapped/represented/F004Recovered5ba8b0.cpp` | 1 |
| 0x5dcce0 | `reconstruction/unmapped/fields/FieldLeaf5dcce0.cpp` | 3 |
| 0x9fe0d0 | `reconstruction/unmapped/fields/FieldLeaf9fe0d0.cpp` | 1 |
| 0xf43970 | `reconstruction/unmapped/fields/FieldLeaff43970.cpp` | 2 |
| 0x1283250 | `reconstruction/skyrim/papyrus/ErasedSignature1283250CallableLayout.cpp` | 48 |
| 0x14a99c0 | `reconstruction/unmapped/fields/FieldLeaf14a99c0.cpp` | 1 |
| 0x14a99d0 | `reconstruction/unmapped/fields/FieldLeaf14a99d0.cpp` | 2 |
| 0x14a9ad0 | `reconstruction/unmapped/fields/FieldLeaf14a9ad0.cpp` | 1 |

## Observations

- The comparator binds each reference by position from the target's own field, so a twin unit keeps the
  exemplar's callee and data names; the names are generic stand-ins declared in the unit.
- Names, class layouts and the sized-delete or field-offset constants are copied from the exemplar; for
  a strict twin the constants are equal by construction (immediates are not blanked at this level).

## Interpretation and alternatives

A byte match shows that the stand-in produces the compared code. It does not show the original class
name, hierarchy or layout, nor that a twin is related to its exemplar. Twins with a community name or an
RTTI owner are left out so that no name or ownership is asserted.

## Reproduction and sanitized evidence

The units are generated from the exemplar sources and compared with the project's local comparator
(`tools/contrib.py compare`, pinned MSVC under Wine); the project's own hosts repeat the compare. No bytes,
disassembly or private paths are published.

## Negative results and limitations

Exemplars in multi-function units, exemplars of real (community or RTTI) classes, static initializers and
other internal-linkage shapes, and twins with a community name are not stamped here.

## Reviewer and outcome

Mapping and stand-in units only; no function is accepted by this finding.
