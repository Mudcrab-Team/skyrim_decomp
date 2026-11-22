# Legal, rights and publication policy

Maintainer: [awarebayes](https://github.com/awarebayes). Effective 2026-11-11.

## Purpose and independence

Independent research into Skyrim Special Edition for understanding, interoperability and
preservation. No affiliation, sponsorship or endorsement by Bethesda, ZeniMax, Microsoft or
middleware vendors is claimed. Game names and marks identify the subject only; ownership
remains with their holders. No proprietary logos, artwork or branding are used by this project.

The repository contains original infrastructure and documentation and, under `reconstruction/`,
reconstructed source for individual functions as described below. This policy is a contribution
rule, not a legal opinion or guarantee.

## Inputs and prohibited publication

Researchers must have a legally obtained copy and comply with relevant law and agreements.
Fetching your own purchased copy with your own account through Valve's Steam client or SteamCMD is
such a copy; third-party downloaders, cracks and DRM removal are not, and this project distributes
no game file. Keep proprietary inputs and all raw game-derived analysis private under `.local/`.
A contributor may let their own coding agent read listings made locally from their own copy, under
their own account and their AI provider's terms; that is the contributor's decision and
responsibility, not a right granted by this project, and nothing game-derived may enter the
repository, pull requests, issues or CI.
Do not distribute executables (original, modified or rebuilt), binary sections, machine-code
listings, raw disassembly/decompiler exports, object files, libraries, memory dumps, save files,
assets, extracted data tables, PDBs, proprietary SDKs or compiler packages through this project (the generated,
labelled CrashLogger output below is not a PDB and is an exception to the data-table rule, as are the
sibling symbol names below, which are class-member and object-file names, not tables of addresses or types).
This includes Git history, LFS, issues, comments, screenshots, releases, logs and CI artifacts.

Do not acquire or use leaked/confidential source, unofficial proprietary debug symbols or
unlawfully obtained development material (the community-generated CrashLogger PDBs and their generated output, and the five sibling-build
symbol files used as name evidence only, both recorded below, are the two exceptions). Do not assume a public URL establishes authorization.
No copy-protection removal tools or instructions belong here. A reference link is not adoption
of the linked project's practices or a license to reproduce its contents. The sibling-source
exceptions below record the maintainer's decisions; they do not authorize this project to obtain
prohibited material itself.

## Research publication and source reconstruction

Original tooling, factual metadata, reviewed explanations and synthetic fixtures are public
outputs.

**Publication of reconstructed source: maintainer decision.** The maintainer (awarebayes) has
decided that reconstructed source is published in this repository, in the same manner as the FNV
decompilation project publishes its reconstruction: as source files in the public repository,
organized by engine area (`reconstruction/<area>/`, see `reconstruction/README.md`). This records
the maintainer's policy decision; it is not a legal opinion, and no further conclusion is drawn
from it here. It changes no other rule in this file or in `PROVENANCE.md`: only reconstructed
source and its sanitized records are published, never game files, binary bytes, disassembly,
decompiler output, objects, or leaked or proprietary material. Following FNV's manner of
publication is not by itself a licence to reuse FNV's material; reuse rests on the separate
decision below.

**Project licensing.** See `LICENSE`: CC0 1.0 for project-authored reconstructions, docs and research, with per-file exceptions.

**Sibling decompilation (Fallout 3): maintainer decision.** The maintainer has also allowed the
Fallout 3 decompilation `momusdigital/f3_decomp` at `f5bac1b5` on the same terms as FNV below. Its
LICENSE is CC0 1.0, so no permission exception is involved; labels read `SIBLING(...CC0-1.0)`
(`docs/authorizations.md`, Notes). It is another game, so it is never evidence about the Skyrim binary.

**Sibling decompilation (FNV): maintainer decision.** The maintainer (awarebayes) has decided
that the Fallout: New Vegas decompilation `momusdigital/fnv_decomp` at revision `91e1b6e8` may be
read by Engineers and Drafters and that its names, declarations and code may be reused in
reconstructions, including published ones, where they fit the Skyrim target
(`docs/authorizations.md`, Notes). The facts the maintainer weighed are stated plainly here: that
repository is licensed CC0 1.0 (earlier revisions said no licence was granted), and its README tags some names as coming from an Xbox 360 development-build PDB and
from Havok and Gamebryo source. The decision is the maintainer's policy choice, not a legal
opinion. Everything taken is labelled with its origin (`SIBLING(...)`, `docs/drafter-card.md`)
and a reused body is cited in the unit header, so it can be found and removed if a rights holder
objects. The decision does not cover any other repository or revision, does not make FNV
material evidence about the Skyrim binary, and changes no other rule here: game files, binary
bytes and decompiler output stay private, and this project still never acquires leaked code,
PDBs or middleware source itself.

**CrashLogger PDBs (Nexus mod 59818): maintainer decision by awarebayes, 2026-11-20.** These
community-generated PDBs (one `fake.obj` module each, exported from the CrashLogger author's Ghidra project
with wandel/pdbgen; not Bethesda debug symbols) may be used as a naming source, and content generated from them
(layout headers, an RVA-to-name map and a README crediting Nexus 59818, CrashLogger Contributors,
alandtse/CrashLoggerSSE, 2026.10.24) may be committed in `reconstruction/generated/crashlogger_pdb/`, every
file labelled `CRASHLOGGER_PDB(59818@2026.10.24)`. The output is generated, regenerable and easy to strip in
bulk, so it can be found and removed if the author or a rights holder objects; names a unit takes carry the
same label. The `.pdb` file itself is never committed or redistributed, and downloading it is optional. It is
a name source, not evidence about the binary (`docs/authorizations.md`, Notes). It is a maintainer policy
decision, not a legal opinion, and it widens nothing else: leaked or Bethesda PDBs, MAP files and similar
remain excluded.

**Sibling-build symbol files (name evidence only): maintainer decision by awarebayes, approved on Reddit and
confirmed in chat on 2026-11-21.** Five symbol files may be used as a source of class-member and object-file
names: a 2013 linker map of this game, one Fallout 4 program database and three Xbox 360 Fallout: New Vegas
program databases, identified by SHA-256 and size in `docs/authorizations.md`, Notes. The names and object files
that `tools/symbol_corroboration.py` read from them may stay in `data/name-corroboration.json`,
`data/symbol-names.json` and `findings/sibling-symbol-files.md`, and a name a unit takes from them carries
`SYMBOLS(<source-id>)`. The files themselves, dumps of them, and any address, type layout, decorated name or code
from them are never committed or redistributed. They are not evidence about the pinned binary. It is a maintainer
policy decision, not a legal opinion, limited to these files: other debug symbols, leaked or Bethesda PDBs and
MAP files stay excluded. This Fallout 4 file is a different source from the `fo4-private` sibling decompilation
below.

**Sibling decompilation (`fo4-private`): maintainer decision by awarebayes, 2026-11-14.**
Source: a private Fallout 4 decompilation, revision `1b765c70`, used with its author's permission
on condition of anonymity (author's terms quoted: 'no attribution. or credit anonymus').
Its game-code names, declarations and bodies may be read and reused on the same reconstruction
and publication terms as the FNV decision above, within the exact game-code folder allowlist
and pin in `docs/authorizations.md`. Its Havok, HavokLib, Scaleform, SDK and Gamebryo folders,
vendor-derived material elsewhere and mixed generated aggregates are excluded. Everything
reused is labelled `SIBLING(fo4-private@1b765c70, author-permission)` and each reused body has
an anonymous unit-header source/path/line citation. This permission is not a general licence
or a grant of third-party rights, and is not dedicated under this repository's CC0 licence (`LICENSE`).
The upstream repository, owner/author identities, URL and product nickname must never appear
in tracked files, commit messages, CI or any file under `reconstruction/`; use only
`fo4-private` and keep the real mapping under `.local/`. The local publication guard uses a
gitignored private denylist; public CI cannot independently check undisclosed identities.
It is never evidence about the Skyrim binary: no layout, vtable slot, offset or form ID
transfers without proof. Every function still requires the unchanged two-host comparator pass,
independent admitted review and integration. This is a maintainer policy decision, not a legal
opinion or clean-room approval; all private-input and research-boundary rules still apply.

Each function is published only once accepted under the acceptance rule in
`docs/verification.md`, which includes provenance review by an admitted Reviewer under the
individual or family procedure, with provenance or legal doubt escalated to the maintainer. The copyright status of reconstructed
implementations is not settled by matching bytes or withholding binaries.
Nothing in this repository grants third-party rights. See `LICENSE` for the scope (CC0 for project-authored
reconstructions, docs and research; MIT for infrastructure; per-file exceptions); do not label the
entire repository MIT or CC0. Material reused from FNV under the decision above comes from a CC0
project; it is labelled `SIBLING(...)` for provenance.
Contributor authorship alone does not establish rights to all underlying material.

US law distinguishes ideas/methods from protected expression in [17 USC 102(b)](https://www.law.cornell.edu/uscode/text/17/102).
The interoperability provisions of [17 USC 1201(f)](https://www.law.cornell.edu/uscode/text/17/1201)
have conditions and are not a blanket permission to circumvent, copy or redistribute. Other
jurisdictions and agreements may differ. A disclaimer, lawful purchase or separate repository
alone does not establish compliance. Seek qualified advice for uncertain publication decisions.

## Contributor responsibility and automated work

Submit only work you have authority to contribute, identify external sources and applicable
licenses, and disclose relevant source exposure and AI assistance. Human operators are responsible
for agent submissions. Tool output and AI-generated text need review; neither proves provenance,
correctness or legal compliance. Do not send proprietary inputs to cloud services merely because
an agent has network access. Follow `PROVENANCE.md` and `docs/clean-room.md`.

## Concerns and reports

Rights holders should contact [the maintainer](https://github.com/awarebayes), identifying the
specific path or URL, claimed rights and requested action. For an ordinary public report,
open an issue with metadata only. For confidential concerns, use an available private contact
route on that profile; do not post the confidential content to this repository. Do not attach
binaries, dumps, proprietary source or credentials. The maintainer will investigate and can
restrict or remove disputed material. This does not promise a legal outcome or response deadline.

The original infrastructure is provided without warranty under its scoped MIT license (reconstructions and docs: CC0 1.0, also without warranty). No
warranty is made that research is accurate, complete, safe for saves, or suitable for gameplay.

## Verified CI toolchain cache: maintainer authorization

awarebayes authorized a CI cache of the pinned MSVC v141 and Windows SDK tree on 2026-11-14,
superseding the earlier no-cache decision. Maintainer statement, verbatim:

> legal.md is made up by me and can be rewritten, there is no particular reason it is what it is, i am open to it if 2 does not hold

The maintainer's condition 2, cache reliability, is met by full-manifest verification: every
restored file, the complete file set, and all four compiler pins must match the trusted tracked
SHA-256 manifest before use. A mismatch discards the restored tree and fetches hash-verified
payloads from Microsoft's pinned catalog. Fork PRs can restore this cache; that visibility is
explicitly accepted. This is the maintainer's project-policy authorization. It does not authorize
compiler packages in Git history, releases or ordinary artifacts, or any game bytes in CI/cache.

**CI candidate branches (awarebayes, 2026-11-15, p148).** The maintainer explicitly authorized
source-only candidate batches on a ref or branch for the CI second-host fallback
(`docs/authorizations.md`). Those guarded draft branches may precede acceptance and never count
as accepted functions. This is a narrow exception to the acceptance-only publication timing
above. Only reconstructed source and sanitized requests/results travel; no game bytes, objects,
raw listings, private inputs or compiler diagnostics are published. Individual or family review,
sampling and normal integration remain required for acceptance.
