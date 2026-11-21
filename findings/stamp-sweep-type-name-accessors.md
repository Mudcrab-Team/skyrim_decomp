# Finding: static type-name accessors with a thread-safe function-local static

Status: OBSERVED local comparator results; selection and mapping only, no accepted matches.
Author / human operator: awarebayes
AI assistance / model: Claude Code Engineer worker (Claude Sonnet 5.5), run locally; no game file or game-derived output was uploaded to any service
Date (UTC): 2026-11-20
Target build id / image SHA-256: `sse-steam-1-7-104` (image hash pinned in `builds/target.json`)
Function RVA / size (if applicable): the RVAs added to `data/progress.json` with evidence `findings/stamp-sweep-type-name-accessors.md`; every size is 140 bytes
Source exposure: mixed (local masked-code clustering of the pinned image's functions; the accessor pattern of the matched exemplar, which was adapted from the anonymous permitted sibling)
Sources and immutable revisions / licenses: matched exemplar 0x79ad20 of this repository (`reconstruction/skyrim/ai/movement/IMovementSetSprinting.cpp`); `fo4-private@1b765c70` under author permission (`docs/authorizations.md`); `tools/analysis/clusters.py` at the repository revision of the pull request
Name provenance: GUESS (placeholder class names `ClassTypeLeaf<rva>`; the accessor and static names come from the exemplar's sibling-derived source and carry `SIBLING(fo4-private@1b765c70, author-permission)`)
Confidence: high that each listed function is byte-identical to the exemplar once the comparator's reference fields are blanked; low for every class name and string content

## Question and method

The group of 164 functions shares the masked code of exemplar 0x79ad20 (level L1 of `tools/analysis/clusters.py`): a
static accessor that constructs a function-local static string object guarded by the compiler's thread-safe
initialisation (the CRT thread epoch, the init header, footer and abort calls, one registered destructor).
Members differ only in the referenced symbols. The exemplar's source with another placeholder class name is the
candidate for each member; the string literal in each unit is a placeholder, not an original class name.

## Observations

- Each unit compiled with the pinned recipe is the same size as its target and passed the unchanged local comparator
  when the thread epoch was bound as a thread-local entry and the init calls by position.
- The comparator compares the string-literal reference as a reference, so it proves nothing about the literal's text.

## Interpretation and alternatives

A byte match shows the stand-in produces the compared code. It does not show original class names, string content or
hierarchy. The pattern is the exemplar's, which comes from a Fallout 4 sibling; the sibling proves no Skyrim layout.

## Reproduction and sanitized evidence

Units are generated from the exemplar's shape and compared with `tools/contrib.py compare` (pinned MSVC under Wine).
The two-host check repeats the compare. No bytes, disassembly or private paths are published.

## Negative results and limitations

Binding the CRT thread epoch needs a thread-local entry that a task's private symbol map carries; a hints file cannot
name it because keys starting with an underscore are dropped.

## Reviewer and outcome

Mapping only; no function is accepted by this finding.
