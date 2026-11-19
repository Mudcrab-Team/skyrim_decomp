# Finding: nine callees of Actor::Jump (0x675110) added to the address list

Status: OBSERVED (RVA and size only)
Author / human operator: awarebayes, at the request of TaylorTurnerIT (issue #313)
AI assistance / model: Claude Code Engineer worker
Date (UTC): 2026-11-19
Target build id / image SHA-256: `sse-steam-1-7-104` / `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f`
Function RVA / size (if applicable): 0x1c8530 (133), 0x1f3900 (120), 0x1f3a20 (53), 0x23fea0 (99), 0x6d3890 (297), 0x722110 (18), 0x7ae440 (1097), 0xb97880 (4), 0xeb1100 (24)
Source exposure: binary-analysis (the pinned image's function table, sizes only)
Sources and immutable revisions / licenses: the contributor's list in issue #313; the project's private function table for the pinned image
Name provenance: GUESS
Confidence: high for RVA and size; no name is claimed

## Question and method

The contributor listed these RVAs as callees of a drafted function and asked for them to be claimable.
Each RVA and size was compared with the project's private function table for the pinned image; all nine are
function starts with the sizes the contributor gave. None was in `data/progress.json`.

## Observations

Entries are `mapped` with a `Function<rva>` placeholder name labelled GUESS. The community name sources
disagree or only give class placeholders for some of these, so no name or class is taken from them.

## Negative results and limitations

No behaviour, signature or owning class is claimed. Placeholder names are expected to be replaced when a
reconstruction settles them.
