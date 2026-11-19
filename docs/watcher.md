# Project watch runbook

For any LLM or agent running the periodic project watch. It is generic: host, path and scheduler
details belong in your private `.local/` notes, never here.

## Each tick (about every 30 minutes)

- Open outside PRs: their checks and the pr-bot verdict.
- Open issues that wait on a reply or have no labels.
- CI on `main`: red or green.
- Whether the bot is alive (a recent run or sticky comment update).

## Quiet rule

If nothing is stuck, write one line ("nothing stuck") and do nothing else. Do not re-audit
items that are progressing.

## Outside PRs

- Contributors never wait on a person or a particular machine.
- The two hosts are a maintainer host plus the CI `hash` job.
- Merge on a two-host byte match plus one review (`docs/verification.md`).
- Fix small problems (header budget, format) on the contributor's branch and credit them with
  `Co-authored-by`. Do not ask them to redo trivia.
- If the bot is wrong, fix the bot with a tooling PR; do not patch around it in the PR.
- Workers post no PR comments. The bot keeps one sticky comment per PR and edits it in place.

## Issues

Labels: `from-agent`, `bug`, `tooling`, `question`, `docs`, `contributor-help`,
`function-request`, `needs-maintainer`, `answered`, `wontfix`, `duplicate`. Claim issues keep
`claim` / `claims-tool`.

- Label every unlabeled issue with the fitting labels.
- Reply at most once per issue, briefly, and only when the answer comes from the repo or docs.
  Then add `answered`.
- Fix small bugs through a tooling PR and merge it once the `check` job is green (`scope` and
  `hash` do not apply to tooling PRs).
- A decision only the owner can make gets `needs-maintainer`. Do not guess.
- Close an issue when its fix merges.

## Privacy

Never paste game bytes, disassembly, decompiler output, dumps or symbols into any issue, PR,
comment, log or commit. Refer to functions by RVA and name only. If a reporter posts such content,
delete or hide it and say only that it was removed under the privacy rule. If provenance of
something is doubtful, stop publishing the affected item and escalate.

## Escalate to the maintainer only for

- a decision that is truly the owner's;
- a privacy or provenance doubt;
- red `main` you cannot fix.

Do not ask questions that have an obvious answer: decide, act and report. Report only when
something changed.

## Cost

Use a cheap model for read-only checks, a mid-tier model for fixes, and one worker per stuck item.
