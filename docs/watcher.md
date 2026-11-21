# Intake operator runbook

For a person (with their own coding agent and repo write/admin rights) or an agent running the
periodic watch over outside contributions. It is generic: hosts, paths and scheduler details belong
in your private `.local/` notes, never here. The bot's behaviour is defined in `tools/pr_bot.py`;
the acceptance rule in [verification.md](verification.md).

## Each tick (about every 30 minutes)

1. Open outside PRs: their checks, the pr-bot sticky comment and labels.
2. Open issues that wait on a reply or have no labels.
3. CI on `main`: red or green.
4. Bot liveness: a recent edit of any sticky comment (see "What needs the maintainer's machine").

If nothing changed, write one line ("nothing stuck") and stop. Do not re-audit progressing items.

## Reading the bot's verdict

The bot keeps one sticky comment per PR head and edits it in place.

- **header**: a changed unit header breaks the compact-header budget; the comment names file, lines
  over and which lines count. Held before any compile. Small: fix it on the branch yourself.
- **stale**: an already accepted function's record binds the unit text, and this PR's edit outdates it.
  It must be re-confirmed and re-approved with the PR. Contributor's job only if the re-check really
  fails; otherwise a tooling fault.
- **regression**: a function that matched on main no longer does (often a shared header, layout or
  inline helper). Both hosts failing on an accepted function is usually genuine: contributor fixes.
- **companion**: accepted functions of a changed unit that the PR does not name are re-confirmed with
  it; one failing blocks the PR. Same reading as regression.
- **leak**: leakgrep hit or a review that names concrete evidence (copied text, decompiler artifact,
  secret, host path, steering, origin similarity). Blocks the whole PR. For similarity to a private
  sibling the contributor cannot see the source: ask them to rewrite the body, never to "remove the
  copy". A leak claim with no named evidence is a style opinion and does not count.
- **tooling**: no file under `reconstruction/`; not a function PR (see below).
- **conflict**: PR conflicts with main. The bot merges main into the branch only when contributors
  allow maintainer edits and only header comment blocks conflict; anything else is the contributor's.
- **precheck** and **origin** findings: a mechanical lint, readiness, undeclared-adapted-body or
  binding refusal before any review, with the exact fix in the comment; origin notes that say "not
  a block" are informational (correctly labelled sibling similarity).
- **unbound**: no function was compared (no target row, symbol missing, unresolved symbol). It says
  nothing about the bytes. Fix the binding (a `// CI hash:` line, a recipe, a target row); do not
  tell the contributor their code differs.
- **carried** host result: the bot reused a host result because the function text or only comments
  changed and the function has no target at base. Normal.

Heuristics: a failure on one host only is often tooling (recipe, symbol binding, stale name at an
RVA): investigate the bot or data before blaming the PR. A function already failing on base is
project debt; it never blocks and is never recorded. The same infrastructure failure on one head
three times backs that head off; read the bot's log before re-triggering.

## Rules

- Contributors never wait on a person or a particular machine.
- Fix small things (SPDX or header lines, label typos) on the contributor's branch and credit them
  with `Co-authored-by`. Do not ask them to redo trivia.
- Fix the bot, not the PR: if a verdict is wrong, land a tooling PR; do not patch around it.
- Post no PR comments beyond the bot's one sticky comment.
- A function is `matched` only by a two-host byte match plus one Reviewer approval. Never hand-mark
  one, never edit `data/progress.json` to skip it, never lower the match floor, comparator or
  validator.
- Never paste game bytes, disassembly, decompiler output, dumps or proprietary symbols into any
  issue, PR, comment, log or commit; refer to functions by RVA and name. If a reporter posts such
  content, delete or hide it and say only that it was removed under the privacy rule.

## Non-reconstruction PRs (bot says `tooling`)

The bot never merges these. Review scope and run the leak scan; when `check` is green, merge with
`gh pr merge --squash --admin` (`scope` and `hash` failing or absent is expected). Accepted precedents:

- static findings with VA addresses, constants and behaviour, such as
  [grass-retail-constants](../findings/grass-retail-constants.md) and
  [interior-portal-admission](../findings/interior-portal-admission.md);
- bulk generators with synthetic generic x64 test fixtures (no game bytes);
- documentation fixes.

Label `needs-maintainer` and stop (do not guess) for: new sources or permissions, acceptance-rule or
provenance-policy changes, privacy-relevant changes, anything legal, or a red `main` you cannot fix.

## Issues

Labels: `from-agent`, `bug`, `tooling`, `question`, `docs`, `contributor-help`, `function-request`,
`needs-maintainer`, `answered`, `wontfix`, `duplicate`; claim issues keep `claim` / `claims-tool`.

- Label every unlabelled issue.
- Reply once, concisely, only when the answer is in the repo or docs; then add `answered`.
- Fix small bugs through a tooling PR; close the issue when it merges.
- A decision only the owner can make gets `needs-maintainer`.

## What needs the maintainer's machine

The pr-bot service and the local compare (the second host of the bot's two-host check) run on a
maintainer-operated host. The CI `hash` job runs on GitHub and does not. If that host is down,
outside PRs queue: you can still review and merge tooling PRs and triage issues, but cannot produce
local compare results or acceptance. You can tell it is down when no sticky comment or label has
changed on open PRs for well over an hour although new heads or PRs exist. Report that to the
maintainer once; do not try to compare or accept by hand. Host-specific restart steps live in the
maintainer's private notes.

## Permitted sources and labels

Full terms and limits are in [authorizations.md](authorizations.md); this is only a pointer.

| source | unit label | where it may appear |
|---|---|---|
| CrashLogger PDB (Nexus 59818) | `CRASHLOGGER_PDB(59818@<ver>)` | generated files under `reconstruction/generated/crashlogger_pdb/` |
| Sibling-build symbol files (name evidence only) | `SYMBOLS(<source>)` | names and object-file facts in units; the files are never committed |
| FNV decompilation (pinned revision) | `SIBLING(...)` | reconstructions, with `Sibling source:` line |
| F3 decompilation (CC0) | `SIBLING(...)` | same rules as FNV |
| Fallout 4 private sibling, anonymous | `SIBLING(fo4-private@1b765c70, author-permission)` | game-code folders only; never name the upstream |

No sibling is evidence about the Skyrim binary. Leaked or Bethesda debug symbols beyond the listed
files stay forbidden.
