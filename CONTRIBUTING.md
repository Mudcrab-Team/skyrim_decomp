# Contributing

The project rebuilds Skyrim Special Edition's code one function at a time: you write C++ that the
same Microsoft compiler turns into exactly the bytes of the game's function. No programming
background is needed if you let a coding agent (Claude Code, Codex, Gemini CLI, ...) do the work;
you supply the game and approve required personal actions.

## Match one function

**You need:** a computer running Windows, macOS or Linux; Python 3.11 or newer and git; a GitHub
account; your own copy of Skyrim Special Edition **1.7.104.0 from Steam** (the exact file is pinned
in `builds/target.json`); disk space for the measured baseline plus margin ([platform and disk record](docs/contributor-platforms.md)). Everything else is
installed for you.

```sh
git clone https://github.com/Mudcrab-Team/skyrim_decomp.git
cd skyrim_decomp
./sr go            # Windows (cmd or PowerShell): .\sr.cmd go
```

`go` checks your machine, installs what is missing (Wine on macOS and Linux, LLVM, the pinned
Microsoft compiler from Microsoft's own servers), proves the setup on a function the project
already matched, picks a small unclaimed function, claims it on GitHub and creates its source file.
It stops and tells you the exact next command whenever a person is needed. Game-specific setup needs these two decisions:

1. **Where your `SkyrimSE.exe` is** (found automatically in a normal Steam library).
2. **Whether you accept Microsoft's licence** for the Visual Studio 2017 Build Tools, which the
   compiler download requires. `setup` prints the licence link; nothing accepts it on your behalf.

Your system may add its own questions: a package manager can ask for your password (`sudo` on
Linux), Apple silicon Macs need Rosetta 2 (`softwareupdate --install-rosetta`, Apple's licence), and
winget on Windows asks you once to accept the terms of its package source.

Then write the function (or ask your agent to) and run:

```sh
./sr compare       # compile + compare; repeat until PASS
./sr submit --dry-run  # check the unit and report any blockers
./sr submit            # commit, push to your fork, open the pull request
```

**With a coding agent:** open your agent in the cloned folder and say *"Help me match one function
in this repository. Follow docs/contributing-agent.md."* It runs the commands above itself.

**What happens after you submit.** Your pull request carries only your source files and a
sanitized summary (pass/fail, sizes, hashes). A local pass is not yet a match: the project
re-compiles and re-compares your source on two of its own machines, and a Reviewer checks that it
is plausible source with honest provenance. If both agree, the function is recorded as matched and
you are credited in the commit. If not, the reasons come back on your pull request.

Intake runs automatically; follow your PR's labels and comments for status.

A contradicted explicit exact-head match claim (including the generated local PASS table) can earn
a [strike](docs/contributor-ci.md#strike-rules). Setup or compile failures, missing targets,
unverified results and review rejection do not.

**Tested platforms and storage:** see the single [platform-status and disk record](docs/contributor-platforms.md).
Git author/co-author credit is preserved in the accepted integration commit. A rejected or
incomplete contribution receives reasons to revise; a local pass is not an accepted match.

### The game executable

The comparator needs exactly the pinned file (`builds/target.json`: Steam, version 1.7.104.0,
Steam build 24914197). `doctor` reads your file's version and hash and tells you plainly if it is
another build. Fetching your own purchased copy with your own account through Valve's clients is
fine: the Steam app on Windows, or Valve's command-line client SteamCMD (also the route on macOS
and Linux, where the Steam app cannot install this Windows-only game). `setup --steamcmd` installs
SteamCMD with your package manager and prints the steps; you type your Steam login into SteamCMD
yourself. SteamCMD itself is your install, from Valve's official download or your package
manager's package of it; this tool does not hash-check it. The printed steps install the whole game (about 13 GB download); since only the executable is needed, they also show a shorter alternative that fetches just
its depot (about 38 MB), not yet tried by the project. This tool never sees, stores or passes Steam credentials and never
downloads the game itself; third-party downloaders, cracks and DRM removal are not acceptable
routes. A Steam install made in October 2026 delivered exactly the pinned build; if yours is
different, `setup` says so.

### Rules that the tools check for you

- Source files go in `reconstruction/<area>/<Class>.h` and `.cpp`, with the header comment the
  skeleton gives you. Label every name with its origin (`docs/contributor-card.md`). Write C++ a
  programmer could have written; no inline assembly, byte arrays or tricks to force bytes.
- Never paste or attach bytes, listings, disassembly or decompiler output anywhere public (issues,
  pull requests, comments, screenshots). They stay in `.local/` on your machine. When you post the
  tool's output (for example in a platform report), run it with `--redact`, which replaces your
  checkout and home paths.
- A coding agent that helps you reads the listing made from your own copy, which sends parts of it
  to your AI provider. Whether to allow that is your decision and your responsibility, under your
  provider's terms; your agent asks you once. The project grants no rights in the game and uploads
  nothing.
- Community headers (CommonLibSSE-NG, powerof3's CommonLibSSE, meh321's Address Library names) and
  the FNV and Fallout 3 decompilations (`momusdigital/fnv_decomp@91e1b6e8`, `momusdigital/f3_decomp@f5bac1b5`, which `setup` clones) may be used, with
  their labels: `SIBLING(...)` for what you take from them and a `Sibling source:` header line for a
  reused body. Both are other, older 32-bit games (FNV, and Fallout 3 built with VC++ 2005 SP1): read
  them for shape and names, never as evidence about Skyrim's offsets or layouts. For engine-shared
  classes (Gamebryo/NetImmerse, TES forms, AI, scripting) read FO3 and FNV first for names, layouts,
  vtable order and body shape, whichever has the class.
- The repository also carries names generated from the community CrashLogger PDBs
  (`reconstruction/generated/crashlogger_pdb/`, label `CRASHLOGGER_PDB(59818@2026.10.24)`) and candidate
  names from sibling symbol files (`data/symbol-names.json`, label `SYMBOLS(tesv-2013-map|fo4-pdb|fnv-x360-pdb)`,
  `findings/sibling-symbol-files.md`); both are name sources, never evidence of identity.
- State who drafted the unit and which AI model helped (`--drafted-by`). You stay responsible for
  what your agent submits.

## Other ways to help

- **Names and labels.** Matched functions whose names or labels still have open findings show
  `open` in the `names` column of `reconstruction/INDEX.md`. Fixing a label comment against the
  pinned community headers (`python3 tools/check_labels.py <files>` after `contrib.py setup`) is
  re-accepted by the project without a new review when the compiled code is unchanged. Change
  comments and labels only, not code or declared names.
- **Code rules.** `python3 tools/check_code_rules.py` counts the matched functions whose source still
  holds an offset cast, a private copy of a type or a padding member ([docs/code-rules.md](docs/code-rules.md)).
  Clearing a finding is an ordinary source change to that unit: it is recompiled and compared like any other.
- **Platform reports.** Run `./sr --redact doctor` and `setup` on your machine
  and open an issue with the output (it contains no game data) if something fails.
- **Documentation.** Unclear steps in this file or `docs/contributing-agent.md` are bugs.

## Project members and research contributions

Read `AGENTS.md`, `LEGAL.md`, `PROVENANCE.md` and `docs/verification.md` first. A human operator is
accountable for AI-assisted work; state assistance and source exposure. Do not submit material you
lack rights to contribute. The licensing scope is in `LICENSE`; there is no blanket relicensing of
recovered implementations or third-party material.

1. Pick or open a focused issue. State who is working on it and how long the claim lasts.
2. Pin the target and dependencies before making build-specific claims. Keep inputs in `.local/`.
3. Record the method and outcome with the research template, including failures and unknowns.
4. Update the work item in `data/progress.json`. Changes to GitHub issues do not silently update
   the report: commit the reviewed status so it has a reproducible source revision.
5. Stage named files and inspect their contents. Run:

```sh
python3 tools/check.py --staged
python3 tools/check.py
python3 -m unittest discover -s tests -v
python3 tools/build_site.py
```

Include these results in the PR, along with exact revisions and limitations. Do not attach
private outputs. The automated guard is defense in depth, not a secret scanner or legal review.
Use the tooling/research PR checklist; function-only submissions use the separate function intake template. A passed infrastructure check does not establish a byte match.

How an external pull request enters the acceptance pipeline is in `docs/contributor-intake.md`.

## Publication

Reconstructed source is published in this repository by engine area, per the maintainer's
decision in `LEGAL.md`. Each function is published only when accepted under the acceptance rule in
`docs/verification.md`: reproduced comparator pass, approval by a fresh Reviewer subagent that
checks plausibility and provenance, and integration. Do not ask the maintainer to review
individual functions; escalate only as that rule lists. Approving behavior specifications for
transfer to Mudcrab still needs the boundary review in `docs/clean-room.md`. Keep executable-building tools separate if pursued later,
with a fresh review of scope and publication policy. No such builder exists here today.
