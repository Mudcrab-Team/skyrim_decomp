# Finding: twin stamping from matched exemplars, strict and loose

Status: OBSERVED local comparator results on the Windows runner host; candidates for the normal two-host review route, no accepted matches yet.
Author / human operator: awarebayes
AI assistance / model: Claude Code Engineer worker (Claude Sonnet 5.5); no game file or game-derived output was uploaded to any service
Target build id / image SHA-256: `sse-steam-1-7-104` (image hash pinned in `builds/target.json`)
Function RVA / size (if applicable): the RVAs of the reconstruction pull request that carries this note
Source exposure: binary-analysis (a local code-shape index of the pinned image) plus this repository's own matched units; no community or sibling body is introduced beyond what the exemplar units already carry
Sources and immutable revisions / licenses: matched units of this repository at the revision of the pull request; `tools/twins/` at the same revision; no third-party source
Name provenance: GUESS (placeholder owner `Owner<rva>` and method `Function<rva>`, or the exemplar's own RVA-stamped placeholder class); no owner, signature or original name is claimed
Confidence: high that each unit compiles to the same code as its target on the pinned compiler; low for every name and every class layout

## Question and method

Static method: every function of the pinned image is reduced to a code shape (`tools/twins/shapes.py`, the digests of `tools/analysis/clusters.py` plus the pattern of which reference fields share a target). Two functions are strict twins when code outside the comparator's reference fields, the field layout, the unwind data and the sharing pattern are equal; loose twins also blank displacements and immediates. A matched function in the same group is the exemplar. `tools/twins/twins.py plan` joins the groups with `data/progress.json` and picks the exemplar whose unit can be cut down to one function (placeholder-named units first).

`tools/twins/unit.py` cuts the exemplar unit to the compared function, keeps the helpers it names, and writes the twin:

- stamped: the exemplar's own class carries its RVA, so the RVA is replaced in every identifier, file name and header line and only the declarations the kept code reaches are copied;
- stand-in: the exemplar's owner is a real class, so the twin header includes the exemplar's header and adds a copy of the owner declaration named `Owner<rva>`, with the method renamed `Function<rva>` unless it is virtual, an override, a constructor or a destructor. Names the copy took from community sources are relabelled GUESS(low) STANDIN, and comments that claim another function's RVA are dropped;
- loose, constants: an integer literal of the function is changed when every immediate operand of that value changes the same way;
- loose, members: a member of the stand-in is moved by resizing the padding in front of it, when the layout is computable (no base classes, scalar, pointer or byte-array members).

Compiling and comparing ran on the project's Windows runner host (`tools/verifier/attempt`, position binding, the unchanged comparator). Twins with a community or vtable-slot name, static initializers, teardowns, thunks, and RVAs in open pull requests, in the claim of another contributor, or in likely downstream targets were left out.

## Observations

| level | planned | compiled and compared | local passes | pass rate of planned |
|---|---:|---:|---:|---:|
| strict, stamped exemplar | 327 | 325 | 325 | 99.4% |
| strict, stand-in owner | 858 | 858 | 809 | 94.3% |
| loose, stand-in owner | 960 | 160 | 141 | 14.7% (88% of those compiled) |

Strict failures (80 of 1,185 planned): 26 relocation-target mismatches (a callee named in a shared header resolves to the exemplar's target, so the twin would need a different stand-in callee), 9 symbol-missing, 9 compile errors (the body hands `this` to a function that takes the real class), 4 size mismatches, 1 undeclared alias, 2 existing units under the same path.

Loose twins left unsupported (800): 218 constants not spelled as a literal, 209 owners with base classes, 128 layouts with a member type the layout reader does not size, 120 displacements with no member at that offset, 58 members that would have to move toward the start with no padding to shrink, 25 immediates that are ambiguous, 22 functions without a definition under the stamped name, 20 stamped-class layouts. The 19 loose compile failures are bodies that pass `this` to a real-class parameter.

The 3 stand-in twins whose bodies resembled a sibling body above the origin-check threshold were held back.

## Interpretation and alternatives

A byte match shows that the stand-in produces the compared code; it shows nothing about the original class, hierarchy or layout, nor that a twin relates to its exemplar beyond the code shape. A loose twin in particular says only that this function reads a member at this offset, or uses this constant, in code of the exemplar's shape. The largest untapped supply is loose twins whose owner has base classes or members of class type: a layout reader that sizes bases from the included headers would unlock the most.

## Reproduction and sanitized evidence

Commands are in `docs/generators.md`; the index, plan and compare output stay under `.local/`. Counts and RVAs only are published. Index rebuilds from scratch take about ten seconds for 107,865 functions and gave identical records on the Mac and on the Windows host.

## Negative results and limitations

Static initializers, teardowns and thunks use the internal-linkage comparator contract and are not stamped. Compiler-made symbols (deleting destructors with no source definition, adjustor thunks) have no definition to cut out and are skipped. A type or width change moves opcode bytes, so such pairs never share a shape here. Exemplars whose header line is missing, whose owner is a template or nested class, or whose preprocessor lines are conditional are not used. A masked shape is a lead; the unchanged comparator, two hosts and one review decide.

## Reviewer and outcome

Tooling and stand-in units only; no function is accepted by this finding.

## Extended generator

The layout reader resolves declared bases, class-typed fields and integral enum widths from the
exemplar's repository include closure. It uses the sibling layout engine with community size
fallbacks disabled. A move edits padding in the stand-in's own declaration. An interior
displacement can move with its containing member when all requested offsets into that member
agree on the move. Inherited members stay in their original bases. The reader checks existing
size and offset assertions against the exemplar before adjusting them for the twin.

A loose constant can also come from a distinct integral `constexpr` declared in the
translation unit and used once in the selected function. The generator edits its initializer
and preserves its literal type. Expressions, shared definitions and ambiguous uses remain
unsupported.

`plan --community-names` can use unique, build-specific CrashLogger names with compatible
bounds and prototype evidence. It also accepts a unique Address Library name corroborated by
the authorized symbol sources and labels both origins. The name has to fit an isolated
declaration and the source still describes a stand-in layout.

`stamp --retarget-callees` can give a direct call its own external declaration when a
strict twin changes the reference target. The supported member signature has a void return
and takes only the receiver. Scalar deleting destructors can be selected by the externally
emitted symbol from an accepted exemplar. Construction and destruction remain ordinary C++
definitions. Static startup and shutdown functions that need internal selectors are outside
the reconstruction-only CI hash route. Failed units are removed from the working tree, and
verdicts and source revisions come from the verifier's result records.
