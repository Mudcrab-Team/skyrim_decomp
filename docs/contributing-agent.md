# Guide for a contributor's coding agent

You are helping an **external contributor** match functions of Skyrim Special Edition. Everything
here runs on the contributor's computer. Do not use the project's internal runners, queues or
verifier hosts.

## The flow

1. Draft the reconstruction locally and get a local comparator PASS.
2. Open a pull request that touches only `reconstruction/**` and `docs/cookbook-notes/**`. Read the notes there
   for your function's class or cause before drafting; write a note with `./sr note <task>` only for a spelling that fixed
   something the cookbook does not record, or a near-miss cause it does not cover (format:
   `docs/cookbook-notes/README.md`), and include it in the PR. Merged notes are folded into the cookbook at the next round.
3. Checks run on the PR: a path and leak scan, and a Windows compile whose hashes are compared to
   the published target hashes (host 1). The project's bot compares on a second host, reviews the
   source once and squash-merges the PR with its own message. Nothing else is needed from you.

A function counts as `matched` only after both host comparisons and one review; a local pass is a
candidate. A function that fails stays a draft and the bot comment names a reason code. The bot keeps
one comment per PR and edits it for each new push. Fix it and push to the same branch.
Aim for 50 to 200 functions per PR (1000 is the per-PR cap); more is fine, and one PR per family or
class is ideal. A single large function is also a fine PR on its own. Classes can be mixed. Fewer,
bigger PRs help most: each PR costs a full verification and merge cycle, and large batches have
merged cleanly in about an hour. Thank you, don't be shy.

## Big batches: use subagents

Don't try to do it all in one go; spawn subagents (Claude Code's Agent tool, Codex subagents or any
equivalent). Cheaper models are fine for drafting.

1. The lead agent picks one family or class and runs `start` for 50 to 150 functions.
2. It splits them into batches of 10 to 15 and gives each subagent one batch.
3. Each subagent works in its own worktree and its own new unit files, one unit per function. It
   never edits a shared header or an already matched unit, since that makes matched functions stale.
   Name each new unit `<Class>_<rva>.h` and `<Class>_<rva>.cpp` (RVA in lowercase hex, no `0x`).
4. Each subagent loops `compare` on its tasks until PASS and gives up on a function after a few tries.
5. The lead merges the passing branches into one, runs `submit --dry-run`, and opens one PR with
   `submit --all-dirty`.
6. Every subagent brief asks it to report bottlenecks and suspicious behaviour, one line each with a
   time cost (AGENTS.md, "Report bottlenecks"). The lead lists them under "Bottlenecks" in the PR
   description, or opens a `tooling.yml` issue for a step that costs more than about 5 minutes per function.

**Subagent batches are a drafting split, not a PR split.** Never open one PR per subagent, worktree or
batch of 10 to 15. Subagents never open PRs or run `submit`; only the lead does, once, for the whole
run. Split only above the 1000 cap, and never open extra PRs just to trigger checks.

Worktree and storage setup for this is in [contributor-parallel.md](contributor-parallel.md).

## Skills

`.claude/skills/` holds `matcher` (a near-miss you are iterating on), `permute` (only register
allocation or ordering differs) and `wall-identifier` (a stalled function: classify the wall before
giving up). They are adapted from lemiur's Game-Decompilation-Skill-For-Claude, CC-BY-4.0; see the
`NOTICE.md` in each directory.

Read `docs/contributor-lessons.md` before your first PR: common Reviewer rejections. Optional
advanced parallel work is in `docs/contributor-parallel.md`. Optional bulk sources for a contributor
with their own exe: `tools/static_data_generate.py` (`findings/static-data-families.md`),
`tools/fixed_argument_generate.py` (`findings/fixed-argument-wrappers.md`),
`tools/return_argument_generate.py` (`findings/return-argument-wrappers.md`),
`tools/conditional_dealloc_generate.py` (`findings/conditional-deallocators.md`) and
`tools/vftable_reset_generate.py` (`findings/vftable-reset-wrappers.md`) draft whole families
locally; their results are one-host until the PR's checks run.

## Tooling

Drive one tool, `tools/contrib.py` (macOS/Linux: `./sr`; Windows: `.\sr.cmd`), always with
`--json`. Each call prints one JSON object with `ok`, `exit_code`, `error` and `next` (the one next
action); do what `next` says. Exit codes: 0 ok, 1 a check failed, 2 usage, 3 compile failed, 4 unit
or include problem, 5 input missing, 7 a person must decide, 8 offline.

```sh
./sr --json --yes go [--exe "<path>"] [--accept-microsoft-license] \
    --drafted-by "<person>, assisted by <your model id>"
./sr --json compare
./sr --json submit --dry-run
./sr --json submit
```

`go` installs and checks the toolchain (idempotent; finished steps are skipped), picks a function
and prepares a skeleton and a private pack. Then edit the unit under `reconstruction/`, run
`compare` until it passes, and `submit` (it needs a fork remote; if none, ask the person to fork
the repository on GitHub). When you show output publicly, add `--redact`.

`next`, `claim` and `start` also take any function in the published target-hash list, even without a `mapped`
entry in `data/progress.json` (`next` prints the counts and prefers small functions of classes that already have a
layout). The bot adds the inventory entry (a `Function<rva>` GUESS name) when it records the match; you never edit `data/progress.json`.

An entry still named `Function<rva>` has no class, so `start` stops and asks for one: `./sr start 0x<rva> --class <Class>`
names the unit after your reading of the owner class. Label that class GUESS unless a public table (CrashLogger,
`SYMBOLS(...)`, `SIBLING(...)`) names it. The flag does not rename the inventory entry and is not evidence of identity.

By submitting, a contributor dedicates their contribution under CC0 1.0, or under the file's stated exception licence (`LICENSE`). The contributor card has the source, label, short-header and stopping rules. Do not add licence text, task or evidence lines or disclaimers to a header: the PR check refuses a new or changed header that is long or carries licence text. The
[matching cookbook](matching-cookbook.md) and [declaration kit](declaration-kit.md) are optional
references.

## When to ask the person

Ask when the helper reports these decisions; account, fork and sign-in steps also need them.

1. The path to their `SkyrimSE.exe`, if `setup` cannot find it (exit 5).
2. Microsoft's licence for the Visual Studio 2017 Build Tools (exit 7, `licence` field). Show
   the link; pass `--accept-microsoft-license` only after they accept. Never accept it yourself.
3. System prompts such as Rosetta 2, a `sudo` password or winget source terms. Package installs
   themselves need no decision: pass `--yes`.

**Ask once before reading any listing or pseudo-C.** Reading a pack made from their own copy sends
parts of it to your AI provider. That is their decision and responsibility under their provider's
terms; the project grants no rights in the game. Continue only if they agree.

## Privacy

Packs, listings, pseudo-C, Ghidra projects, bytes, objects, raw diagnostics and paths never go
into a commit, PR, issue or comment. A PR containing disassembly or decompiler names (`FUN_`,
`param_1`, `local_28`), inline assembly, byte arrays or host paths is blocked by an automatic scan
that reports only rule codes and line numbers. Squash merging replaces your commit messages with the
bot's, so your history is not published.

## If you can't match it

Release the function with a give-up record, `./sr release 0x<rva> --reason "..." --category <wall> --tried "..."
--still-differs "..." --suspected-cause "..."`, so the next drafter starts from what you learned
([contributor card](contributor-card.md), "If you can't match it").

## Getting help

If the helper or a check blocks you and the docs do not say why, open an issue instead of guessing:
`gh issue create --template <file>` (or the web forms): `tooling.yml` (bug), `contributor-help.yml`
(stuck), `question.yml`, `function-request.yml`. Add `--label from-agent` and name your model/tool.
Labels: `bug`, `tooling`, `contributor-help`, `question`, `function-request`, `docs`; the project sets
`needs-maintainer`, `answered`. Privacy: no game bytes, disassembly, decompiler output, dumps or
symbols; functions by RVA and name only.

The periodic project watch is described in [the watcher runbook](watcher.md).

## The game executable

The pinned build is in `builds/target.json` (Steam, 1.7.104.0). If `setup` reports another build,
tell the person; never obtain or modify game files yourself. Their own purchased copy fetched with
their own account through the Steam client or SteamCMD (`setup --steamcmd`) is fine. Never handle
Steam credentials.

## Recommended local decompiler

`go` installs a hash-pinned Ghidra and Temurin privately and analyses in the background (about
1.8 GiB on disk; skipped below about 18 GiB of free RAM; `--no-decompiler` skips it). `start` then
adds a private `decomp.c`. Treat it as an untrusted hint for control flow and types; write your own
source, because `compare` decides the match.

## Recommended: CrashLogger PDB names

The repository carries names and layouts generated from the community "CrashLogger PDBs"
(https://www.nexusmods.com/skyrimspecialedition/mods/59818, CrashLogger Contributors) in
`reconstruction/generated/crashlogger_pdb/`; read its README. `next` shows a function's name from
`names/<NN>.tsv` as a suggestion, so you need download nothing.

- A name or layout you take is labelled `CRASHLOGGER_PDB(59818@<version>)` on its label line, for example
  `// Foo::Bar: CRASHLOGGER_PDB(59818@2026.10.24)`. It is a name source like `COMMUNITY`, not evidence of what the
  function does; only a byte match accepts a function.
- Downloading the mod is optional, needed only to refresh the generated output or for a lookup beyond it: take the
  `ae17` variant (`ae17/SKSE/Plugins/SkyrimSE.pdb`, 1.7.104) and keep it under `.local/`, for example
  `.local/pdb/SkyrimSE.pdb` (or point `SR_CRASHLOGGER_PDB` at it). `next` and `start` fall back to it for an RVA the
  committed map lacks; put the archive's version in `.local/pdb/version.txt` or `SR_CRASHLOGGER_PDB_VERSION`.
  `llvm-pdbutil dump -publics SkyrimSE.pdb` lists its publics; keep that output under `.local/`.
- `start` also prints `PDB layout ...` with the header of the class a function belongs to
  (`reconstruction/generated/crashlogger_pdb/types/<Class>.h`: fields, offsets, padding and `_base` members). A unit
  that already declares the class copies only the members it needs; a unit that does not may include the header.
  Layouts are community guesses; `compare` decides.
- `start` prints `PDB prototype ...` (return type, parameter types, calling convention, from `prototypes/<NN>.tsv`) for a
  function whose PDB type is more than a bare `void()` stub; a method's first parameter is its `this`, often typed as
  another class. It also prints `PDB boundary warning` when a claimed RVA is inside a function that
  `boundaries/<NN>.tsv` records but is not its start; `intake` and `submit` give the same warning. It never blocks.
- `start` also prints up to 12 sibling-symbol member-name candidates for the class with their `SYMBOLS(<source-id>)` ids (`data/symbol-names.json`; candidates, never evidence of which function is which).
- Never commit the `.pdb`, or a name list from it outside the generated directory.

## Mapping-only PRs

A PR that only names functions touches `data/progress.json` and, optionally, new `findings/*.md`:

- Append entries to `functions` only: status `mapped`, the existing entry fields, no `report` or `matched`; change
  nothing else in the file and keep its layout. Add no RVA that is already present.
- Each entry's `evidence` is a findings file that exists; a guessed name has `GUESS(` in `name_source`.
- Leave out `docs/progress.svg` and `reconstruction/INDEX.md`; the bot regenerates them after the merge.
- The `mapping` check and `tools/mapping_check.py` run these rules; one review checks names, evidence and that
  nothing is game-derived. No host runs, and no function can become `matched` this way.

## While a PR is open

Leave **Allow edits by maintainers** on and pull before continuing. Run `./sr feedback --json` at
the start of each session; push fixes to the same branch and never force-push over reviewed commits.

## Optional: sibling symbol names

`data/symbol-names.json` and `data/name-corroboration.json` hold candidate names read from sibling
symbol files (label `SYMBOLS(tesv-2013-map|fo4-pdb|fnv-x360-pdb)`; a name hint, never identity
evidence); see `findings/sibling-symbol-files.md`. Contributed by lemiur (#572).

For the register of sibling and community sources, their labels and the traps when reading them, see
`docs/secondary-research.md`.

## Optional: 2013 map and Fallout 4 PDB (full use)

The maintainer authorized using the Skyrim 2013 linker map and the Fallout 4 PDBs to any extent: decorated names
and prototypes, map order and object-file grouping, type layouts, vtables and class hierarchies
(`docs/authorizations.md`, Notes).

- Download, from `debugging.games` (the file names are given here, URL-encoded as the site lists them under
  `https://debugging.games/_files/Windows/`): the Fallout 4 2019-10-23 PDB archive,
  `[WIN]%20Fallout%204%20[2019-10-23]%20(PDB).7z`, and the Skyrim 2013-07-17 map archive,
  `[WIN]%20The%20Elder%20Scrolls%20V%20Skyrim%20[2013-07-17]%20(MAP).7z`.
- Put them under `.local/inputs/symbols/` (`tesv-2013-07-17/TESV.map`, `fo4-2019-10-23/Fallout4.pdb`) or point
  `SR_SYMBOLS_DIR` at the folder. `./sr setup` checks the SHA-256 values and `./sr doctor` warns when they are missing.
- **Step 1 of every function:** read `./sr facts 0x<rva>` (`./sr start` prints the same). It gives the CrashLogger
  prototype and size, the map's aligned name, prototype, object file and neighbouring members, the Fallout 4 layout
  and prototype where the class is shared, and the label lines to paste. `./sr compare` warns, before compiling,
  when your name or signature disagrees with a known PDB prototype; the warning is advisory, a byte match decides.
  Without the files, the committed `data/symbol-alignment.json` and CrashLogger output still give the first part.
- Extract only the `.map` and the `.pdb` files into `.local/`. The archives also hold game executables; the
  project does not use them and third-party game binaries stay out of scope.
- Label every name taken from them `SYMBOLS(tesv-2013-map)` or `SYMBOLS(fo4-pdb)`. A name is a hint, never identity;
  only a byte match is acceptance. Addresses are from other builds.
- Never commit, attach or quote the files, dumps, listings or excerpts anywhere (PR, issue, log, CI). Derived
  names, prototypes and confidence may be committed. The Xbox 360 New Vegas PDBs stay name-only.

## Questions

Ask in the project Discord: https://discord.gg/tbXD8gwgjJ. The publication rules apply there too:
no listings, pseudo-C, bytes or screenshots of them.
