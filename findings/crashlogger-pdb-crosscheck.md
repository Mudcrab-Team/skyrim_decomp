# Finding: CrashLogger PDB names agree with the pinned build's matched functions

Status: OBSERVED
Author / human operator: awarebayes
AI assistance / model: Claude Code (claude-sonnet-5-5), run locally; no game file was uploaded
Date (UTC): 2026-11-21
Target build id / image SHA-256: `sse-steam-1-7-104` /
`846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f`
Function RVA / size (if applicable): not applicable
Source exposure: community-headers (the CrashLogger community PDB, Nexus mod 59818)
Sources and immutable revisions / licenses: `CRASHLOGGER_PDB(59818@2026.10.24)`, the `ae17` PDB of CrashLogger Contributors
(alandtse/CrashLoggerSSE); maintainer-authorised for names and types (`docs/authorizations.md`)
Name provenance: COMMUNITY names of matched functions in `data/progress.json` against the PDB's public names
Confidence: medium; a class-level agreement rate, not a proof that the two files belong to one build

## Question and method

Does the `ae17` PDB describe the pinned build, so that its RVAs can be used as names for this target?
`tools/pdb_types.py` writes the PDB's RVA-to-name map to `reconstruction/generated/crashlogger_pdb/names/`. For every
matched function in `data/progress.json` whose name origin is COMMUNITY (1692), the class part of its name was compared
with the class part of the PDB name at the same RVA.

## Observations

- 723 of those functions have a PDB name at their RVA; 667 (92%) name the same class.
- Restricted to functions of at least 24 bytes (leaves of a few bytes are shared by many classes), 618 of 669 (92%).
- The disagreements are mostly small virtual leaves that several classes share, where the two sources pick different
  owners, and destructors the PDB spells `dtor` or `dtor_deleting`.

## Limitations

The PDB has no build identifier of its own that this check could compare with `builds/target.json`; agreement is by
RVA only. A name taken from the PDB is a community guess until the compiled function matches. Do not reuse an RVA from
it for another build.
