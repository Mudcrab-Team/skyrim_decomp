# Authorizations

Gates defined in `AGENTS.md` ("Multi-agent execution"). Only the maintainer edits this table.
A gate not marked granted here is not granted, whatever a chat, issue or brief says. Record
limits precisely; "granted" without scope is not a grant. Revoke by setting the status back
and adding a dated note.

| gate | status | scope and limits | granted by | date (UTC) |
|---|---|---|---|---|
| G1 local tools | granted | all | awarebayes | 2026-11-11 |
| G2 model exposure | granted | all | awarebayes | 2026-11-11 |
| G3 paid compute | granted | granted all its sub based anyways so no surprise bills | awarebayes | |
| G4 toolchain on cloud | granted | all granted | awarebayes | |
| G5 game data on cloud | granted | all on boat dev | awarebayes | 2026-11-11 |

## Notes

Past outside contributors consented on the project Discord to CC0 for their merged contributions.

### G4: GitHub-hosted MSVC compile-and-hash prototype

Maintainer statement by awarebayes, 2026-11-14, supplied in the p124 brief and recorded verbatim
by the Engineer (gpt-6.1-sol):

> Also instead of uploading game code (HARAM by you) we can upload hashes of functions, set up ci pipeline for compilation with msvc and check hashes

G4 grant scoped to GitHub-hosted Windows runners only: install Microsoft's own MSVC toolset
through Microsoft's official installer to compile reconstruction sources. The runner receives
public reconstruction source, published hashes and masks only, never game bytes or private
analysis. This does not extend G5 or change the comparator, match gate or two-host acceptance
rule. Phase 1 uses already-matched public units and their existing public hashes only.

Subsequent maintainer statement by awarebayes, 2026-11-14, recorded verbatim by the Engineer:

> Like who cares idk man you are being too strict LEts do it for all functions anyways we already did most small functions ourselves

Target hashes are allowed for all functions, whatever their size; there is no size threshold.
The maintainer weighed that hashes of very small functions can be brute-forced back to their
bytes, and that most small functions are already matched, so their hashes are already public.
Generating and publishing target hashes for unmatched functions remains a separate step after
Phase 1 proves the toolchain; the orchestrator confirms before any are published. No such
generation or publication is implemented by p124. This records the maintainer's decision, not
a new acceptance rule or permission to publish bytes.

### Owner-unknown generated static functions

Maintainer decisions by awarebayes, 2026-11-13, relayed by the planning orchestrator.

Orchestrator: "May owner-unknown static initialisers and teardowns go into a new folder, `reconstruction/static/`, in files grouped by address range and labelled as owner unknown? I recommend yes; otherwise 16,270 functions wait for ownership that mostly cannot be established."

Maintainer: "1, yes, is it not obvious?"

Orchestrator: "For middleware, may I use this rule: leave out a static function when the nearest functions with a known owner on both sides are middleware, and include the rest? The alternative is to include all of them, since these are compiler-generated stubs with no middleware logic in them."

Maintainer: "2. idk you decide whats better" and then "havok is fine, why the scare? idk why are you so afraid of it? Just not the main point of this project".

On that delegation, the planning orchestrator decided to include all members, without a middleware exclusion, for compiler-generated static initialisers and teardowns only. Priorities for handwritten middleware code are unchanged. The normal provenance, comparator and review requirements remain in force.

Reviewers may read the FNV index: the maintainer said "of course thats intended thats why we have fnv source". The FNV source remains subject to its existing exposure and labelling rules.

For microsoft license: individual for my own opensource project
PL CommonLibSSE for naming and publishing id/offset pairs approved
Reconstructed source will be published in this repository, similar to the FNV decompilation project (maintainer decision, stated to the orchestrator 2026-11-11 and recorded here by it).
The maintainer does not review individual functions; acceptance follows the automated rule in docs/verification.md (maintainer decision, 2026-11-11).
Two-tier acceptance: a function counts as `matched` on comparator evidence plus automated hygiene and a Reviewer approve on blocking grounds only; names and name-origin labels are a separate, non-blocking `named` tier improved afterwards by tooling, and a label-only change that leaves the compared code section unchanged is re-accepted without a new Reviewer pass (maintainer decision, 2026-11-12, stated in the orchestration session and recorded here by an Engineer; rule in docs/verification.md). Two safeguard points in docs/verification.md went beyond that statement, and the maintainer confirmed both on 2026-11-12 ("1. Label-only scope: yes, the wide version" and "2. Sampling: yes, keep it"; stated in the orchestration session, relayed by the orchestrator and recorded here by an Engineer): the wide label-only scope, under which a function is re-accepted without a Reviewer whenever its unit changes but its code-section hash is identical on both compile hosts ("Label-only re-acceptance"), and the sampling triggers as written in "Sampling safeguard", including the first-20 second pass for each new Reviewer prompt or acceptance-rule version and for the first 20 label-only re-acceptances per rule version.
Names and declarations from the GPL-3.0 CommonLibSSE fork (powerof3) may be used as a naming source, including in published reconstruction sources, labelled with their origin (maintainer decision, stated to the orchestrator 2026-11-12 and recorded here by it).
Files carrying declarations derived from the GPL-3.0 CommonLibSSE fork state GPL-3.0 explicitly in their header (maintainer decision, 2026-11-12, recorded by the orchestrator).
meh321's Address Library database and its name lists may be used: the maintainer reports that the author agreed on Discord (maintainer statement, 2026-11-12, recorded by the orchestrator; no written licence file exists, so cite it as "used with the author's permission as reported by the maintainer").
The Fallout: New Vegas decompilation momusdigital/fnv_decomp at revision 91e1b6e8 (private clone `.local/sources/fnv_decomp`) may be used directly: Engineers, Drafters and admitted Reviewers may read it, and its names, declarations and code may be reused in reconstructions where they fit the Skyrim target, including in published reconstruction sources (maintainer decision by awarebayes, 2026-11-12, stated to the orchestrator and recorded here by an Engineer from the orchestrator's brief). The repository's LICENSE read "No licence is granted" at the time of the decision and is now CC0 1.0 Universal (maintainer statement, 2026-11-20); the label token `no-licence` is kept so existing labels stay valid (merged units are not rewritten). The maintainer is aware that its README tags some names as taken from an Xbox 360 development-build PDB and from Havok and Gamebryo source, and decided that neither bars this use; earlier text in this repository that forbade the source is superseded for it. Scope: that repository at that revision, and since the pin moved (see the x64 block below) at `2b07cb3e`, only (another revision or sibling project needs its own decision); taken material is labelled `SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0)` (units merged earlier keep `SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)`, which stays valid) and a reused body is cited in the unit header (`docs/drafter-card.md`). Not covered: it is not evidence about the Skyrim binary (other game, older engine, 32-bit build; no address, slot, layout or offset transfers without proof on `sse-steam-1-7-104`); every reconstructed function still needs the comparator pass, Reviewer approval and integration of the acceptance rule in `docs/verification.md`; and it does not let this project itself acquire or use leaked source, PDBs or middleware source, or upload private inputs.
The Fallout 3 decompilation momusdigital/f3_decomp at revision f5bac1b54fc8fde16294c1d6779f27407d0a117b (private clone `.local/sources/f3_decomp`) is allowed on the same terms as the FNV decompilation above (maintainer decision by awarebayes, 2026-11-21, stated to the orchestrator and recorded here by an Engineer from the orchestrator's brief). Its LICENSE is CC0 1.0 Universal, so unlike FNV no permission exception is needed; the decision adds it as a read-and-reuse source. Taken material is labelled `SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0)`, a reused body is cited in the unit header with `Sibling source: momusdigital/f3_decomp@f5bac1b5 <path>:<line>` and declared as an adapted body (upstream file, revision, licence) like other community sources, and the origin check clones it at the pin so a body close to one of its bodies is found and must be declared. Not covered: it is not evidence about the Skyrim binary (Fallout 3 is x86, VC++ 2005 SP1, PC 1.7.0.3; no address, slot, layout or offset transfers without proof on `sse-steam-1-7-104`); another revision needs its own decision.
Cheaper-drafter experiment, model exposure (maintainer statement, 2026-11-12: "lets try to experiment with cheaper models like luna / haiku they can do work with simple guildelines we already built for them"; the orchestrator read this as covering the exposure below, told the maintainer so, and an Engineer recorded it here from the orchestrator's brief). For this drafting experiment only, function packs (listings and decompiler output for the assigned functions) are read by a non-Anthropic model, GPT Luna via the Codex provider, in addition to the Anthropic models G2 already covers. Scope: the assigned task directories of the wave-3 group `batch5-s03-niobject` and nothing else under `.local/`. This is not a general extension of G2: any other group, input or non-Anthropic model needs its own decision. No assessment of the provider's terms is recorded here.
Drafting from the queue with GPT Luna through the maintainer's Codex subscription (maintainer statements, 2026-11-12: "I wanna use luna after all"; "we have codex sub ... I can start another codex session from markdown. you write markdown i point codex to markdown simple as"; recorded by an Engineer from the orchestrator's brief). The maintainer starts these sessions themselves and points each at `docs/drafter-runbook.md`. Scope: drafting units from the Drafter queue `.local/queue/small/` only; for the queued units, the function packs (listings and decompiler output, as the per-function sheets present them) are read by that model, which extends the cheaper-drafter scope above from one group to the queued units. Not covered: FNV text (the `.fnv.md` sheet variant), any other `.local/` input, review, acceptance, git operations, or any other non-Anthropic model or task. No review of the provider's terms is on record. Claude Haiku sessions run from the same runbook under G2 (the maintainer said Haiku is equally fine for drafting, relayed by the orchestrator).
External contributors (maintainer decisions by awarebayes, 2026-11-12, given to the orchestrator in answer to numbered questions and recorded here by an Engineer; answers quoted verbatim). Q1 "Real test of the installer on this Mac: may an Engineer run the real contributor setup here? It installs Wine through Homebrew and downloads MSVC from Microsoft into .local/; you would accept Microsoft's licence." A: "of course yes test whatever you like i can even give you ssh to a windows pc" (basis for accepting the Visual Studio 2017 Build Tools licence on the maintainer's Mac during that test). Q2 "FNV source for outside contributors: may they reuse it as our Drafters do?" A: "of course" (external contributors follow the same `SIBLING(...)` and `Sibling source:` rules as Drafters). Q3 "Policy wording: may I add to AGENTS.md that an owner fetching their own copy through Steam or SteamCMD is fine?" A: "Do whatever you want, yes make it easy there is nothing illegal there" (wording in AGENTS.md and LEGAL.md). The contributor flow itself rests on the maintainer's request for it, quoted verbatim: it "Shoud be easy for non technical person to make first contribution ... external newcomer claims function, gets bytes, writes c++, compares, contributes, all agentically", and later "contributor can agentically install wine and ghidra and all that easily". Contributor agents reading local listings (maintainer decision by awarebayes, 2026-11-13, given to the orchestrator in answer to a direct question and recorded here by an Engineer; question and answer quoted verbatim). Q "may the contributor docs tell a newcomer that their own coding agent can read the listings produced locally from their own copy of the game, at their own responsibility? Nothing game-derived goes into the repo or PRs either way." A: "yes of course". On that basis a contributor may let their own coding agent read listings made locally from their own copy, as their own decision and responsibility under their AI provider's terms, not a right granted by this project (AGENTS.md, LEGAL.md). Hosting function bytes or listings for download was considered and declined by the maintainer in favour of local setup.
Verification on the maintainer's own hardware instead of Boat (maintainer decision by awarebayes, 2026-11-12, given to the orchestrator and recorded here by an Engineer; verbatim: "and also lets make windows pc the default runner now, i dont wanna use boat anymore"). Consequences: the Boat verifier machines are retired as the default runners; verification runs on the maintainer's own machines, this Mac (the pinned compiler under Wine) and the maintainer's Windows PC on the local network (the pinned compiler run natively), reached over key-based SSH and selected by `tools/verifier/runners.py` from a private config. G3, G4 and G5 for Boat are no longer exercised but are not revoked by this note. The target executable and the toolchain on the Windows PC are the maintainer's own copies on the maintainer's own machine; no cloud service is involved. Records from these hosts become acceptance evidence only after the matching change to the acceptance rule in `docs/verification.md` has passed its Reviewer review.
Deletion of the Boat verifier machines (maintainer decision by awarebayes, 2026-11-13 local time, 2026-11-12 UTC, given to the orchestrator in answer to a direct question and recorded here by an Engineer; verbatim: "yes lets delete 2 stopped machines. i have cancelled sub myself."). Deleted on 2026-11-12 UTC: the two stopped machines `sr-verifier-msvc141` (A) and `sr-verifier-b` (B), with their disks and ordinary snapshots. Nothing was needed from them: every record and review of the matched functions is in `reports/`, the machine recipe is `tools/verifier/setup_toolchain.sh` with `tools/verifier/pinned.sha256`, and the records were reproduced on the maintainer's own hosts. No machine was started and no billing or plan setting was changed by an agent. Verification uses the local and ssh runners (`tools/verifier/runners.py`); recreating Boat verifiers would need the recipe, G3/G4/G5 and a new maintainer decision.
Acceptance rule "two independent runner hosts" (maintainer decision by awarebayes, 2026-11-13, given to the orchestrator in answer to a numbered question and recorded here by an Engineer; question and answer quoted verbatim). Q1 "Do you approve changing the acceptance rule from 'two Boat machines' to 'two independent hosts, one under Wine and one native Windows, each with its own compiler install and game copy'?" A: "1. ofc". This confirms the escalation (category systemic) that the Reviewer raised for the rule change, as policy requires for every acceptance-rule change; the Reviewer found no blocking problem in the delta review of the fixed text. On that basis the "Runner hosts" and "Combining hosts" bullets in `docs/verification.md` are in force, `tools/verifier/confirm_runners.py` may write runner records into `reports/` (`RUNNER_RECORDS_ALLOWED`), and AGENTS.md describes the runner hosts as the verifier hosts. This is a new acceptance-rule version for the sampling safeguard: the first 20 functions accepted and the first 20 label-only re-acceptances under it get the second pass.
Profile `claude-low`: OpenAI models for orchestration, triage and review (maintainer statements by awarebayes, 2026-11-13, given to the orchestrator and recorded here by an Engineer; quoted verbatim): "also how about the idea of creating a separate profille that would use terra openai as orchestrator and reviewer, drafting with haiku, and maybe sol where smart is needed instead of opus. Additional profile named something like my claude sub is  low" and later the same day: "me wanna start claude low agent to shit out functions is everything ready?". Scope: under the `claude-low` profile (`tools/profiles.json`), OpenAI Terra and Sol models, through the maintainer's Codex subscription, may read reconstructed source, sanitized reports and function packs (game-derived listings under `.local/`) for orchestration, triage and review work. GPT Luna's drafting scope above is unchanged; Terra's separate drafting permission is recorded below. This exposure note alone does not admit a Reviewer model; the separate acceptance-rule confirmation below admits `gpt-6.1-terra` under `claude-low`. The same statements are the basis for the `claude-low` profile and the orchestrator and Reviewer rows of the roles table in AGENTS.md. The maintainer's assessment of the Codex account's service terms for this use is recorded in the next note.

Codex service terms for Terra and Sol (maintainer statement by awarebayes, 2026-11-13, given to the orchestrator and recorded here by an Engineer; question and answer quoted verbatim). Q: "are you satisfied that your Codex account's terms allow Terra and Sol to read function packs (listings and decompiler output)" A: "Yes". The maintainer states they have assessed their Codex account's service terms and are satisfied they allow `gpt-6.1-terra` and `gpt-6.1-sol` to read function packs (listings and decompiler output) within the scopes already recorded. This satisfies the "assessment of the service terms" condition of AGENTS.md for those scopes; it widens no scope. This is the maintainer's own statement, not a review performed by the project.

Terra Reviewer acceptance-rule change (maintainer confirmation by awarebayes, 2026-11-13, recorded by an Engineer). The orchestrator asked: "If Terra's calibration agrees with the Opus reviews, may I land the rule that makes Terra the Reviewer under `claude-low` and let it accept functions overnight? A separate reviewer reads the rule change before it lands." The maintainer answered: "Ofc do it terra is more preferable". This confirms the systemic escalation for this rule change, scoped to `gpt-6.1-terra` under `claude-low`. The conditional "agrees" was read as "no missed reject", not identical verdicts. Calibration against Opus covered 67 shared functions: 60 agreed, 7 were stricter, 0 missed, and 4 of 4 reference rejects were caught. Its limits are one wave, one source revision and mostly small functions. This is a new acceptance-rule and Reviewer-model version for the sampling safeguard.

Sol strong Reviewer decision (maintainer decision by awarebayes, 2026-11-13, recorded by an Engineer; verbatim): "you can use sol instead of opus fyi" and, when a Sol calibration was started, "sol is goood enough dont waste time". Scope: exactly `gpt-6.1-sol` under `claude-low` for any review and the strong duties, including sampling second Reviewer passes, confirmation of non-Opus escalations, and reviews of comparator, validator, verifier and acceptance-rule changes. Sol is admitted by maintainer decision WITHOUT a calibration, unlike Terra; no Sol calibration pass or parity claim is made. Limits: Terra remains the default first function Reviewer, every second pass under `claude-low` uses a different model from the first review, and Reviewer independence is per run: fresh context, never the run that drafted, engineered, triaged or first-reviewed the function. Outside `claude-low`, Opus retains these strong review duties. This confirms the systemic escalation for this rule change, scoped to `gpt-6.1-sol` under `claude-low`: the change was reviewed by independent Opus Reviewers (saved reviews p48 and p52, no blocking findings after the p50 fixes) and the maintainer statements quoted above are the confirmation. This is a new acceptance-rule and strong-Reviewer-model version for the sampling safeguard. The deterministic two-host comparator evidence, validator, lint and definition of a match are unchanged.

Sonnet Reviewer decision (maintainer decision by awarebayes, 2026-11-22, recorded by an Engineer; verbatim): "get sonnet admitted now, no eu council decision just edit md". Scope: exactly `claude-sonnet-5-5` under every profile, including `cheap` and `claude-low`, for any review (ordinary, delta and full) and for the strong duties (confirmation of a non-Opus `escalate`, reviews of comparator, validator, verifier and acceptance-rule changes). Sonnet is admitted by maintainer decision WITHOUT a calibration, as Sol was; no calibration pass or parity claim is made. It is also the pr-bot's fallback reviewer when Codex is unavailable and the default Reviewer in the profiles, so Opus is no longer chosen automatically. Limits: Reviewer independence is per run, and a second pass uses a different model from the first review. The deterministic two-host comparator evidence, validator, lint and definition of a match are unchanged.

Terra and Sol Engineer work on local analysis output (maintainer authorization by awarebayes, 2026-11-13, recorded by an Engineer). Verbatim: "ok lets build the generator i think its easy to do? Lets do it with gpt terra subagent? I am running out of my claude sub so lets use gpt terra instead of opus here more?" and "in this session"; the Sol substitution was also authorized by "you can use sol instead of opus fyi". Scope: Terra and Sol, through the maintainer's Codex subscription, may perform Engineer work in this session, including reading local analysis output and reconstructed source for tooling, generator work and integration. This is an exposure and Engineer-role authorization, not a Reviewer calibration or evidence of a match. Limits: nothing game-derived goes into tracked files under this authorization; private analysis stays under `.local/`, no game bytes or raw listings are published, and there is no change to what counts as a match. No Reviewer may review work it drafted, engineered or triaged. This does not grant paid compute or cloud game-data placement.

Engineer role allocation (maintainer statements by awarebayes, 2026-11-13, supplied to the planning orchestrator and recorded by an Engineer): "you can use sol instead of opus fyi" and "lets also use sonnet 5 more for example for merging etc does not need opus". Scope: Opus remains the default Engineer, Sol is the Engineer under `claude-low`, and Sonnet may perform routine merging and integration. This records role allocation only; it grants no additional data exposure, compute or match acceptance.

### Family review rule

The family review rule is in force by maintainer decision; the separate Reviewer pass on this rule change was waived by the maintainer. Grantor: awarebayes, 2026-11-13. Asked “May I land the family review rule with those six points once it has passed a review?”, the maintainer said: “Of course”. On the separate Opus review: “p54 is eu levels of buerocracy. Opus review of a review of a review of change rules. Bullshit.”


### Internal static initialiser and teardown admission

Grantor: awarebayes (human maintainer), 2026-11-13; relayed by the planning orchestrator and
recorded by the integrating Engineer. Question and answer, verbatim:

> May static initialisers and teardowns be accepted as `matched` under the same rule as other functions (comparator pass on both hosts, then family review), once the comparator extension is on main? Today's rule only covers functions with an external symbol, so accepting these needs your yes.

> Sure

Scope: compiler-generated internal static initialisers and teardowns under the TU-bound identity,
complete independently delimited section-at-zero and all existing comparator, two-host,
validator, hygiene and review requirements in `docs/verification.md`. Other internal function
kinds or section layouts are not admitted. The maintainer directed this approved extension and
rule wording to land with tests and CI, without another machinery/rule review round. This does
not waive the individual or family review required for future function acceptance. No function
is marked `matched` by this machinery change. This is a new acceptance-rule version for the
existing sampling safeguard.

Maintainer decisions on Reviewer provenance access and Terra drafting (awarebayes, 2026-11-13, answers to the planning orchestrator, recorded by an Engineer; questions and answers verbatim). Q1: "May Reviewers (Terra and Sol included) read the FNV decompilation for the provenance comparison? A yes lets me record it so no reviewer stops on this again." A: "of course thats intended thats why we have fnv source" Q2: "If Haiku fails on a medium function, may Terra draft it? The recorded permission lets Terra and Sol read function sheets for orchestration, triage and review, but not for drafting. Until you answer, failed medium functions wait." A: "yes"

Every admitted Reviewer model, including `gpt-6.1-terra` and `gpt-6.1-sol` under `claude-low`, may read `momusdigital/fnv_decomp@2b07cb3e` (the private clone and local FNV index) for the provenance comparison required by the Reviewer runbook. The limits of the FNV note above remain unchanged. `gpt-6.1-terra`, through the maintainer's Codex subscription, may draft functions that a Haiku drafter failed on, reading the same function sheets and packs as a Drafter. `gpt-6.1-sol`, through the maintainer's Codex subscription, may draft functions that both the first-tier Drafter and the Terra fallback Drafter failed on, reading the same function sheets, packs and FNV material as a Drafter. The orchestrator asked awarebayes on 2026-11-13: "may Sol draft the functions Haiku and Terra both failed on? Sol drafting is not covered by your recorded permissions. The alternative is Sonnet, which spends your Claude subscription." The maintainer answered: "sol may yeah". A function drafted by Sol receives its first review from Terra and its second pass or strong duties from a fresh Sol run that did not draft it; independence is per run. The comparator gate and acceptance rule remain unchanged; a model run that drafted a function never reviews it.

**Sibling decompilation (`fo4-private`): maintainer decision by awarebayes, 2026-11-14.**
Source: a private Fallout 4 decompilation, revision `1b765c70`, used with its author's
permission on condition of anonymity (author's terms quoted: 'no attribution. or credit anonymus').
Engineers, Drafters and admitted Reviewers may read and reuse its game-code names, declarations
and bodies within their existing authorized model/account roles, including in reconstructions
published after acceptance. This records the maintainer's policy decision, not a legal opinion
or a grant of third-party rights. The permission is not a general licence to the upstream tree.

Scope is game-code folders only: `src/BSAnimation`, `src/BSAudio`, `src/BSCompanion`,
`src/BSCore`, `src/BSDevices`, `src/BSDiag`, `src/BSHavok`, `src/BSHavokMigration`,
`src/BSMain`, `src/BSMenu`, `src/BSMovie`, `src/BSMusic`, `src/BSPathfinding`,
`src/BSResource`, `src/BSScript`, `src/BSShader`, `src/BSSystem`, `src/BSSystemMonitor`,
`src/BSSystemUtilities`, `src/Game` and `src/Shared`, at full pin
`1b765c7031394e5019767dff83e73e8b194f16b0`. Excluded: its Havok, HavokLib, Scaleform,
SDK and Gamebryo folders, mixed generated aggregates (`src/_gen`), and vendor-derived material
wherever located. No executables, PDBs, SDKs or middleware source may be acquired under this decision.

Everything taken carries `SIBLING(fo4-private@1b765c70, author-permission)`; each reused body
also has `Sibling source: fo4-private@1b765c70 <allowed path>:<line>` in the unit header.
Use only `fo4-private` as the source identity: never put the upstream repository name,
owner/author name or handle, URL or product nickname in tracked files, commit messages, CI,
or any file under `reconstruction/`. The real mapping stays under `.local/` only.
The publication guard reads forbidden strings from gitignored `.local/anonymity.json`
(`forbidden_strings` list); `SR_ANONYMITY_CONFIG` carries that private file into publication
lane clones. Before every commit, run case-insensitive `git grep --cached` using the private
owner/repository terms, without printing any matches. CI has no private identity config;
the publishing Engineer must run the configured guard locally.

This sibling is never evidence about the Skyrim binary. It is a different game built with
VS2012: no layout, vtable slot, offset, form ID or address transfers without proof on the
Skyrim target. Every function still needs the unchanged two-host comparator pass, independent
admitted review and integration under `docs/verification.md`. Exposure is recorded as for FNV;
this decision grants no new provider, paid compute, cloud placement or clean-room status.

### CI hash check as the second host (p148)

Date: 2026-11-15. Grantor: awarebayes.

- Question: "May the CI hash check count as the second machine while the PC is down?"
- Maintainer answer: "yes"
- With: "idk lets do ci only for now without windows?"
- Scope: until the maintainer revokes it, the GitHub-hosted Windows CI target-hash job (built by p128: pinned MSVC v141 19.16.27054 with a verified cache, normalized SHA-256 against the published (build id, RVA, size, hash)) may serve as the second independent host, in place of the native Windows PC. Mac under Wine stays the first host. The two hosts are still different machines with different OS loaders.
- Unchanged: the comparator, the family rule, Reviewer approvals, sampling, and the acceptance rule.
- No game bytes go to CI. Only reconstructed source, which is published on acceptance anyway, and the already-published hashes.

Implementation: `ci-hash` confirmations retain the unmodified full Mac comparator report and
add a separately identified CI attestation. CI compiles each unit twice, verifies its complete
non-debug COFF content against the hash measured from the Mac comparator's exact object, and
checks each function against its published target hash and relocation-layout commitment.
The full object content commitment includes code, relocations, data, unwind and EH sections;
only debug sections and their path checksum section are excluded. It does not substitute a
masked hash for the Mac comparator's reference, alias, unwind or EH checks. Missing or
unsupported target hashes are unconfirmable. Cache verification failure, compiler pin mismatch,
non-reproduction or nondeterminism produces no confirmation. Candidate source travels on a
separate batch branch; trusted tools and target hashes come from the dispatched main revision.
Only sanitized JSON results are uploaded as artifacts. The existing review, family, sampling,
integration and acceptance steps still apply. No function is accepted by this machinery change.

The same p148 task explicitly directs: "It submits a batch of candidate units by workflow_dispatch on a ref or branch, or by another mechanism that doesn't push to main. Batch many functions per run." This authorizes source-only candidate batch branches for this CI path before acceptance. Such branches are draft inputs, never accepted matches; the public publication guard and reconstruction lint run before upload.

### CrashLogger PDB (Nexus mod 59818) as a naming source

Maintainer decision by awarebayes, 2026-11-20, given to an Engineer and recorded here from the brief, widened
the same day (the second statement replaces the first's ban on committing derived content). The "CrashLogger
PDBs" archive on Nexus Mods (https://www.nexusmods.com/skyrimspecialedition/mods/59818, author "CrashLogger
Contributors", alandtse/CrashLoggerSSE) is authorised as a naming source. The `ae17/SKSE/Plugins/SkyrimSE.pdb`
variant matches the pinned 1.7.104 build. Facts weighed: these PDBs are generated by the community (a single
`fake.obj` module each, exported from the CrashLogger author's Ghidra project with wandel/pdbgen); they are not
Bethesda debug symbols.

- Content generated from the PDB may be committed in one directory, `reconstruction/generated/crashlogger_pdb/`:
  headers for the PDB's types, a map from RVA to name, and a README crediting the source (Nexus 59818,
  CrashLogger Contributors, alandtse/CrashLoggerSSE, 2026.10.24). Every file there carries
  `CRASHLOGGER_PDB(59818@2026.10.24)`. The output is generated by a tool, regenerable from the PDB and
  never edited by hand, so a new PDB version shows as one diff and the whole directory can be stripped in bulk.
- A name or layout a reconstructed unit takes from it carries the same label. The label is a known name source
  like `COMMUNITY`, never evidence of identity; a byte match remains the only acceptance.
- The `.pdb` file itself is never committed or redistributed. Downloading it from Nexus is optional and only
  needed to refresh the generated output or look something up beyond it (kept under `.local/`, for example
  `.local/pdb/SkyrimSE.pdb`).
- Scope: this archive only. Real or leaked Bethesda PDBs, MAP files and similar stay forbidden
  (`AGENTS.md`, `LEGAL.md`). Fixtures and tests use invented names.
- No exposure scope change: this note grants no new model access to game-derived material.

### Sibling-build symbol files as a name and unit-boundary evidence source

Maintainer decision by awarebayes. The maintainer approved this on Reddit (the comments of
https://www.reddit.com/r/decomps/comments/1y1b11i/skyrim_decomp_wip/) and confirmed that approval in chat on
2026-11-21, which is the date recorded here. It is recorded from that confirmation, for pull request #572
(contributor lemiur), which carries the tool, the data files and the finding.

The five files, identified as the pull request lists them (SHA-256 written in four 16-digit groups joined by `-`
so `tools/leakgrep.py`'s hex-run rule, which refuses any run of 32 or more hex digits, accepts the line; join the
groups to compare):

- `tesv-2013-map`, linker map, 41,662,359 bytes, SHA-256 `fed7f0b964ea752f-e677f4c413c37c97-b5cad21541755c69-c701a66423b288b2`
- `fo4-pdb`, program database, 452,201,472 bytes, SHA-256 `6c5db527eaa981c1-c258b4523c21b677-4332b2fe520bb5fa-25ae96e2dde01917`
- `fnv-x360-pdb (2010-07-21)`, program database, 124,808,192 bytes, SHA-256 `c2893c7b5377d76d-7d5c7fe6b05d9b1c-be1084b63b9d3b69-5db92473a55c1d6b`
- `fnv-x360-pdb (2010-08-22)`, program database, 125,144,064 bytes, SHA-256 `ec702dc52f42a9c1-4037b800871d727a-f2b54ed191d68ae5-fcde3bfce65e6f00`
- `fnv-x360-pdb (2010-11-10)`, program database, 125,168,640 bytes, SHA-256 `24f166f1aceb3e16-a056044b9ee164b4-0fbaf47e9ce441ba-3dc5e26f37cbfa10`

The three Xbox 360 files are builds of Fallout: New Vegas, the Fallout 4 file is a program database of that game, and
the map is a linker map of a 32-bit 2013 build of this game. The Fallout 4 program database here is a different
source from the permitted Fallout 4 game-code sibling recorded in LEGAL.md and AGENTS.md; nothing about that
sibling's anonymity or terms applies to it or changes because of it.

- Scope: `tesv-2013-map` and `fo4-pdb` are widened to full use by the 2026-11-22 decision below. The three
  `fnv-x360-pdb` files keep the original scope: name evidence only, giving class-member names and the object file
  names of a class's functions, with no address, type layout, decorated name or code. None of them is evidence about
  the pinned image: a byte match remains the only acceptance.
- Committed as they are: `tools/symbol_corroboration.py`, `data/name-corroboration.json`, `data/symbol-names.json`
  and `findings/sibling-symbol-files.md` may stay in the repository as submitted. Regenerating them uses the five
  files held locally.
- The five files themselves, and any dump, export, listing or excerpt of them, are never committed, attached,
  quoted in a pull request, issue, log or CI artifact, or redistributed. `tools/symbol_corroboration.py` already
  refuses a source inside the repository. Nothing beyond the names and object files in the two data files is
  published from them.
- A name or object-file fact a reconstructed unit takes from them carries the label `SYMBOLS(<source-id>)`, one
  label per line, with `<source-id>` one of `tesv-2013-map`, `fo4-pdb` or `fnv-x360-pdb`. It is a known name source
  like `COMMUNITY`, never evidence of identity. `name_origin` `SYMBOLS` is accepted for inventory entries.
- Exposing these names (the two data files and what the tool prints from them) to a cloud model is authorized under
  the same decision. The symbol files themselves are not uploaded to any service, and this note changes no other
  exposure scope.
- Scope limit: these five files, plus `Fallout4Beta.pdb` from the 2026-11-22 decision. Leaked or Bethesda debug
  symbols, other MAP files and other PDBs stay forbidden (`AGENTS.md`, `LEGAL.md`). Fixtures and tests use invented
  names.

#### Widened scope for the 2013 map and the Fallout 4 program databases (2026-11-22)

Maintainer decision by awarebayes, 2026-11-22. It supersedes the "name evidence only" scope above for these files:

- `tesv-2013-map` (the linker map above).
- `fo4-pdb`, Fallout4.pdb dated 2019-10-23 (SHA-256 above).
- `Fallout4Beta.pdb` from the same archive, 670,411,776 bytes, SHA-256 `9398b7f82aa08e0b-95cb88744af433e5-7303175f5085cf64-ec45f04e9081a099`
  (same four-group convention). It is used under the source id `fo4-pdb`.

These may be used to any extent: decorated names and prototypes, addresses and function order in the map,
object-file grouping, and type layouts, vtables and class hierarchies from the program databases. Contributor docs
may link the public download archives (`debugging.games`, the Fallout 4 2019-10-23 PDB archive and the Skyrim
2013-07-17 MAP archive; links in `docs/contributing-agent.md`), and a contributor may unpack and use them to the
same extent.

Limits that stay:

- The symbol files, and any dump, export or excerpt of them, are never committed, attached, quoted in a pull
  request, issue, log or CI artifact, or redistributed by the project. Linking the external archive is fine;
  mirroring it is not. Derived data (proposed names, prototypes, confidence) may be committed; map addresses,
  raw symbol listings and excerpts may not.
- A name taken from them carries `SYMBOLS(<source-id>)` (`tesv-2013-map` or `fo4-pdb`). It is never evidence of
  identity; a byte match remains the only acceptance. Map and PDB addresses are for another build and are not
  transferred to the pinned image.
- The archives also bundle game executables (`TESV.exe`, `Fallout4.exe`, `Fallout4Beta.exe`). The project does not
  use them. Only the `.map` and `.pdb` files are in scope; third-party game binaries stay out of scope.
- The `fnv-x360-pdb` files keep the name-only scope. The anonymous `fo4-private` game-code sibling is a separate
  source and is unaffected.
- Internal copies live under `.local/inputs/symbols/` and are never added.

## Primary host and internal sampling directive (2026-11-17)

awarebayes directs the internal primary host to be the native Windows PC, with Mac Wine as
unreachable-PC fallback, and GitHub CI-hash as the independent second machine. Any registered
primary host may supply the unchanged full comparator evidence; native/native is allowed only
for this explicit CI-hash pair. Outside-contributor intake stays Mac Wine plus CI-hash.
Internal functions require one independent admitted review; only the gate's frozen sampled
subset requires the second/safeguard review and clean re-run. Existing sampling draws, first-20
triggers, pins, exact hashes, validator, screen, lint and publication guards remain mandatory.

### Radical simplification of acceptance

Grantor: awarebayes (human maintainer), 2026-11-18, given to the orchestrator and recorded by an
Engineer. Verbatim: "Please land radical simplification and fast". Earlier statements in the same
discussion, verbatim excerpts: "95% of this bullshit can be simplified ... I want like something
radical."; "can the AI just click the fucking merge button"; "Why is review not the 1st step"; and
on leak screening, "unless you can provide me like a plausible fucking threat model ... does not
count." The orchestrator supplied the threat model recorded in `docs/threat-model.md`.

Scope: a function is `matched` on a byte match on two hosts (host 1, the GitHub Windows CI-hash
job; host 2, the Mac Wine or PC comparator) plus one review by an admitted model (Terra under
`claude-low`, otherwise Opus), as written in `docs/verification.md`. A pull request touching only
`reconstruction/**` and `docs/cookbook-notes/**` is checked and, when it passes, squash-merged by a bot with a bot-written
message. Review groups, the sampling second pass, from-scratch reruns and the lane's requirements
are no longer part of the rule.

Limits:
- The sampling second review is dropped on Terra calibration evidence (0 missed rejects in 67
  shared functions, recorded above). The calibration was one wave, one revision and mostly small
  functions. The residual risk is a missed plausibility finding, not a false byte match.
- Two hosts stay mandatory even when that means waiting: if the Mac and the PC are both down, PRs
  wait. The match floor, the comparator, the validator and exact-head-SHA merging are unchanged.
- A shared header changed by a PR still triggers a CI recompile of the matched functions that
  include it; a regression blocks the PR.
- Leak screening is a deterministic grep over added lines plus the single review; a model cannot
  override a grep hit. Only the maintainer's `leakgrep-override` label does.
- No exposure scope changes: this note grants no new model access to game-derived material.

Reviewer rule narrowed on opaque storage (maintainer decision by awarebayes, relayed by the orchestrator and recorded here by an Engineer). The 2026-11-14 rule banned opaque storage used to force allocation size and required the represented layout. It now reads: named unknown members (for example `std::uint64_t unk10;`) at their offsets are acceptable for regions the reviewed function does not access. A Reviewer rejects only when a field the function reads or writes is hidden in opaque storage, a byte array or filler, or when one big array stands in for the whole class. The change is in the plausibility item of `docs/reviewer-runbook.md`, the contributor lesson text, and the bot's review comment now carries each rejected function's reason. The comparator, validator and match definition are unchanged.

Opaque stand-in exception (maintainer decision by awarebayes, recorded by an Engineer). A Reviewer may approve an opaque, correctly sized stand-in type when the function uses only the class size and the destructor call; deleting and scalar-deleting destructors are the typical case. Plausibility is still required for everything else, and opaque stand-ins must not be used to fake field access. The change is one bullet in the plausibility item of `docs/reviewer-runbook.md`, which the bot embeds in its review prompt. No deterministic precheck rejects opaque storage, so none changed; the comparator, validator and match definition are unchanged.

Third-party skills import (PR #572, recorded by an Engineer). lemiur, author of `lemiur/Game-Decompilation-Skill-For-Claude` (CC-BY-4.0), replied "Yes, absolutely" on PR #572 to the request to copy, adapt and credit. Three skills (`matcher`, `permute`, `wall-identifier`) were adapted at commit `f49d2153f8ad9279262a720c88b5d337e7c63534` into `.claude/skills/` with attribution, the licence text and a modification notice; see `SOURCES.md`. No change to the comparator, validator, match definition or exposure scope.

**Sibling decompilations built as x64 (maintainer decisions by awarebayes, 2026-11-24, given to the orchestrator and recorded here by an Engineer).**
- Forks `awarebayes/fnv_decomp` and `awarebayes/f3_decomp`, branch `x64-msvc1916`, hold the upstream code plus an original x64 port (compatibility header, mechanical source edits, a build script); nothing from the game, from `.local/`, from the Skyrim binary or from this repository's indexes and results goes into them. The licence stays CC0 and the README credits upstream (`docs/sibling-x64.md`).
- FNV licence: upstream relicensed `momusdigital/fnv_decomp` to CC0 1.0 "for the contributors' own work" at `42baf49a` (2026-11-18); the fork starts from `2b07cb3e`. Moving the FNV pin from `91e1b6e8` to the final release was already approved and is done in tooling: the pin is `2b07cb3ec4b7aa11be96c7567914e11731aebeaf` (upstream main), labels are `SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0)`, and the lint, label check, origin check and `./sr setup` use it. Labels on the old pin (`SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)`) in already-merged units stay valid with their own licence word and are not rewritten; a retired-pin citation is not read against the newer checkout. The PDB and middleware exclusions are unchanged: names tagged as taken from the Xbox 360 development-build PDB, and material from Havok and Gamebryo source, are not covered by CC0; the port adds nothing of that kind. Neither sibling is evidence about the Skyrim binary; a lead found by compiling it as x64 still needs the comparator pass, Reviewer approval and integration.
- Maintainer decision by awarebayes, 2026-11-24: the f3_decomp_exe and fnv_decomp_exe build tooling (`momusdigital/f3_decomp_exe`, `momusdigital/fnv_decomp_exe`) may be reused, cited by repo@commit. Game files and any executable linked from them are never committed anywhere.
- Prebuilt shingle index (maintainer decision by awarebayes, 2026-11-24, given to the orchestrator and recorded here by an Engineer): an index built only from the compiled CC0 sibling code (mnemonic streams, immediates and strings of the x64 builds of the forks) may be published as a release asset `x64-index-v1` of `awarebayes/f3_decomp` and `awarebayes/fnv_decomp`. It holds no Skyrim-derived data, no Skyrim match results and no Skyrim RVAs. `./sr setup` downloads it and verifies the SHA-256 pinned in `data/x64-index.json`.

**Community and sibling source decisions (maintainer decisions by awarebayes, 2026-11-24, recorded here by an Engineer).**
- Newer revisions of the CC0 siblings (`momusdigital/fnv_decomp`, `momusdigital/f3_decomp`) are adopted by a tooling PR that moves the pin; no per-revision approval is needed.
- Names from an Xbox 360 development-build PDB are covered in bulk by the PR #572 decision (label `SYMBOLS(<source>)`). Havok and Gamebryo source stays excluded.
- The siblings' own reconstructions in their Havok and Gamebryo folders (for example F3's `bshavok/` and `gamebryo/` units) are the decomp contributors' work and may be transplanted like any other sibling code, with the same `SIBLING(...)` label (maintainer: "its ok"). What stays excluded is original Havok or Gamebryo SDK source and material the sibling itself tags as taken from it; do not re-raise this for sibling reconstruction folders.
- A per-class map from Skyrim classes to sibling files may be published.
- CommonLibF4 (MIT) may be used for names, declarations and bodies, labelled `COMMUNITY(<owner>/<repo>@<pin>, MIT)` with the MIT notice the lint requires.
- GPL forks of CommonLibF4 and any other community library are allowed, labelled `COMMUNITY(<owner>/<repo>@<pin>, <SPDX>)`. A GPL-licensed label requires the file's leading comment to state the GPL licence; the label check and the lint already accept any repository and SPDX word.
- No exposure scope changes: nothing game-derived is published, and no sibling or library is evidence about the Skyrim binary.
