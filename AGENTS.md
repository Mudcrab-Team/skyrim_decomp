# Agent entry point

**External contributor:** follow [docs/contributing-agent.md](docs/contributing-agent.md) and
[the contributor card](docs/contributor-card.md). Use `tools/contrib.py` on your own machine.
Read the common publication and evidence rules below. Internal runners, queues and role briefs
are not prerequisites for drafting or submitting a function.

**Flow for everyone:** open a PR touching only `reconstruction/**`; checks run (scope and leak scan,
Windows CI-hash compile); the bot compares on a second host, makes one review and squash-merges.
A function is `matched` on a byte match on two hosts plus one admitted review
([docs/verification.md](docs/verification.md), [docs/threat-model.md](docs/threat-model.md)).

**Internal project worker:** also read [the internal agent workflow](docs/internal-agent-workflow.md)
before operating verifier hosts or publication. It preserves the role, gate, staged-check,
tooling-push and exact-SHA CI requirements. Its lane, queue, review-group and claims sections are
superseded and pending deletion.

Read `LEGAL.md`, `PROVENANCE.md` and `docs/clean-room.md` before research or publication.
[The full acceptance specification](docs/verification.md) remains authoritative; the contributor
card explains the local-pass boundary. Follow `docs/anti-eu-bureaucracy.md`. This repository is
independent of Mudcrab; never apply another checkout's build/cache instructions here.

## Keep private inputs private

- Use `.local/` for legally obtained executables, toolchains, databases, raw decompiler output,
  traces, saves and generated objects. Never force-add ignored paths.
- No game files, binary bytes, disassembly, dumps, proprietary symbols/SDKs, leaked code or
  unlicensed copied code in commits, PRs, issues, logs, releases or CI artifacts. Maintainer
  exceptions: names, declarations and code from the FNV decompilation `momusdigital/fnv_decomp@91e1b6e8`
  may be reused in reconstructions, labelled `SIBLING(...)`, which is itself CC0 1.0 (`LICENSE`)
  (`docs/authorizations.md`, Notes; `LEGAL.md`). The anonymous private Fallout 4 sibling
  `fo4-private@1b765c70` is also permitted for game-code folders only, with author permission conditional on anonymity, labelled
  `SIBLING(fo4-private@1b765c70, author-permission)` (same policy references). Its middleware
  folders and mixed generated aggregates are excluded. Neither sibling is
  evidence about the Skyrim binary.
- Do not upload game-derived material to an AI/cloud service without explicit owner authorization
  and assessment of the service terms. Permission to research locally is not permission to upload.
  An external contributor may let their own coding agent read listings made locally from their own
  legally obtained copy, under their own account and their AI provider's terms; that is their
  decision and responsibility, and the contributor docs say so and ask once. Nothing game-derived
  goes into the repository, PRs, issues or CI either way (`docs/authorizations.md`, Notes).
- Analyze your own legally obtained inputs. Do not download game binaries from anyone else or
  unofficial PDBs, acquire cracks, or add copy-protection removal instructions/tools. An owner
  fetching their own purchased copy with their own account through Valve's Steam client or SteamCMD
  is fine; the project itself never distributes a game file.
- One narrow exception to the PDB rule: the CrashLogger PDBs (Nexus mod 59818, "CrashLogger PDBs",
  author "CrashLogger Contributors", alandtse/CrashLoggerSSE; the `ae17` variant for the pinned 1.7.104
  build) are community-generated from the CrashLogger authors' Ghidra project, not Bethesda debug
  symbols. Content generated from them (layout headers, an RVA-to-name map, a README crediting the source)
  may be committed in the one directory `reconstruction/generated/crashlogger_pdb/`, every file there
  carrying `CRASHLOGGER_PDB(59818@<version>)`; it is regenerated, never edited by hand, and can be stripped
  in bulk. A name or layout a unit takes from it carries the same label. The `.pdb` itself is never
  committed or redistributed (a contributor may keep their own download under `.local/` to refresh the
  output); leaked or real Bethesda PDBs, MAP files and similar stay forbidden. A name from it is not
  evidence of identity; only a byte match is acceptance (`docs/authorizations.md`, Notes).
- A second narrow exception to the PDB rule: five symbol files of sibling builds (a 2013 linker map of this
  game, one Fallout 4 program database, three Xbox 360 Fallout: New Vegas program databases, identified by
  SHA-256 and size in `docs/authorizations.md`, Notes) are allowed as name evidence only. Their class-member and
  object-file names may stay in `data/name-corroboration.json`, `data/symbol-names.json` and
  `findings/sibling-symbol-files.md`; a name a unit takes from them carries `SYMBOLS(<source-id>)` with
  `<source-id>` one of `tesv-2013-map`, `fo4-pdb`, `fnv-x360-pdb`. The files themselves and any dump of them are
  never committed, and no address, type or decorated name from them is published. This is separate from the
  `fo4-private` game-code sibling above and does not touch its anonymity. A name from them is not evidence of
  identity; only a byte match is acceptance.
- Stop the affected publication if provenance is uncertain. Record the question without reproducing
  suspect content. Unrelated original tooling work may continue.

## Be precise about evidence

- The target is pinned by `builds/target.json`, including its locally measured hash.
  Do not invent a version, checksum, compiler, address, test result, cost or completion denominator.
- Address identity is `(build id, RVA)`; never transfer an address between versions without proof.
- Every finding identifies sources, revisions, source exposure, method, limitations and confidence.
  Label inferred names as guesses. Preserve unknowns rather than filling them plausibly.
- Byte match, semantic equivalence, inferred behavior and layout-size agreement are different claims.
- Mark a function `matched` only under the implemented matching gate and acceptance rule in
  `docs/verification.md`: byte match on two hosts plus one Reviewer
  approval, integration. Bootstrap CI checks only publication hygiene, metadata and site
  generation; it does NOT compare against the game. The separate CI-hash job (docs/verification.md, "CI hash check as the second host") does compare compiled functions against published target hashes and counts as the second verifier host.
- A byte match is not yet readable source. [docs/code-rules.md](docs/code-rules.md) holds the code rules and
  the project profile; `python3 tools/check_code_rules.py --list <files>` reports a unit's findings. It is
  advisory and changes no gate.
- Progress comes only from `data/progress.json`; totals are derived, not manually entered into HTML.
  Unknown scope means no completion percentage. No dummy success records or fake history.
