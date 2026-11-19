# Finding: functions without an inventory entry are claimable and get their entry when recorded

Status: OBSERVED (tooling behaviour; RVA and size only)
Author / human operator: awarebayes
AI assistance / model: Claude Code Engineer worker
Date (UTC): 2026-11-19
Target build id / image SHA-256: `sse-steam-1-7-104` / `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f`
Function RVA / size (if applicable): none; this note is the shared evidence file of claim-time entries
Source exposure: binary-analysis (function bounds from the published target-hash manifest and the project's private function table, sizes only)
Sources and immutable revisions / licenses: `data/target-hashes/` at the repository revision of the entry
Name provenance: GUESS
Confidence: high for RVA and size; no name is claimed beyond a placeholder

## Question and method

Contributors could only claim functions already in `data/progress.json` as `mapped`. A function that is in the
published target-hash manifest and in the project's function table can now be claimed and started without an entry,
and `tools/record.py` creates the entry (status `mapped`, then `matched` in the same step) when the function is
accepted. The inventory therefore grows with accepted work, not in bulk.

## Observations

An entry created this way is named `Function<rva>` (or `Class::Function<rva>` when the offered row names a class
that already has a layout unit), labelled GUESS(low), owner `claim-time`, and cites this file as evidence.
Placeholder names are expected to be replaced when a reconstruction settles them.

## Negative results and limitations

No behaviour, signature or owning class is claimed. The class on an offered row is the vtable owner in the private
function table and is a guess until a reconstruction confirms it.
