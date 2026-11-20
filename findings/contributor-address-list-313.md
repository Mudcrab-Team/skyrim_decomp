# Finding: 205 contributor-listed functions added to the address list

Status: OBSERVED (RVA and size only)
Author / human operator: awarebayes, at the request of TaylorTurnerIT (issue #313)
AI assistance / model: Claude Code Engineer worker
Date (UTC): 2026-11-19
Target build id / image SHA-256: `sse-steam-1-7-104` / `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f`
Function RVA / size (if applicable): 205 functions, listed in issue #313 and in their `data/progress.json` entries
Source exposure: binary-analysis (the pinned image's function table, sizes only)
Sources and immutable revisions / licenses: the contributor's list in issue #313; the project's private function table for the pinned image
Name provenance: GUESS
Confidence: high for RVA and size; no name is claimed

## Question and method

The contributor asked for these addresses to be claimable. Each RVA was looked up in the project's private function
table for the pinned image. All 205 are ordinary function starts and none was already in `data/progress.json`, so none
was skipped.

## Observations

Entries are `mapped` with a `Function<rva>` placeholder name labelled GUESS. Sizes are taken from the function table;
for 22 entries the contributor's own size differs from the table extent, and the table value is recorded. Community name
sources exist for about half of the RVAs but were not consulted for agreement, so no name or class is taken from them.

## Negative results and limitations

No behaviour, signature or owning class is claimed. Placeholder names are expected to be replaced when a
reconstruction settles them.
