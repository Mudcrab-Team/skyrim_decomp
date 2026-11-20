# Orchestrator runbook (routine queue work, any model)

## Ten-line lane guide

1. Use green-main tools and the shared `--flow-dir`; keep approved input roots and committed tooling tips available until their receipts finish.
2. Enqueue functions with `integrate`, `integrate-groups`, `integrate-family` or `integrate-labels`; enqueue all ready work first.
3. Commit named tooling files after the staged guard, then run `tooling-push --wait-lane`; all tooling queued before the lease is taken shares one candidate.
4. Run `lane-run --wait-lane` to drain the queue; CLI calls wait by default, and `--no-wait-lane` is an explicit nonblocking probe.
5. After push, the lease is released during exact-SHA CI; the next candidate checks in parallel and may push only after its origin SHA is GREEN.
6. `lane-status` gives exact resume commands; dead local unpublished owners are skipped automatically, while conflict/stale inputs and candidates remain intact.
7. Builds require Python 3.13 with pyexpat and 3 GB free; below the 10 GB soft floor only explicit `--allow-low-disk` admits a new heavy job.
8. Preview `cleanup --dry-run`, then opt in with `cleanup`; working files alone may be removed, evidence and Git refs/stashes remain; `sync` after GREEN.

### Minimal publication brief

Name the immutable input root/tip, selected groups or family batches, shared flow directory,
claim and handoff path. Enqueue all ready selections once, then use the stock lane and its
receipt. Do not add a second publisher, polling script, source-digest audit, private scan,
full local suite or site build around it: the lane validates the integrated source/evidence,
pins live gates again before push, runs publication checks and waits for exact-SHA CI.
Inspect its accepted/dropped selections and exact commit/CI outcome before reporting completion.

Keep the staged guard immediately before each **new input tooling commit** as required by
the internal workflow; the lane's staged guard checks a different, integrated index. Do not
repeat it on an unchanged committed input. Keep required independent reviews, two-host
confirmation and sampling reruns; rerun them when source/evidence changed or a named gate
requires it, not merely because the publication worker changed.

Local pre-push checks run validation and the site once. Reconstruction/header, report,
progress and derived-view changes need no local tooling unit tests. Other changes select
test modules through both base/current import and file-reference graphs; opaque callers
are retained and unmapped inputs fall back to all tests. Shared comparator, validator,
acceptance, digest and lane changes always select the full suite. `test_suite.py
--changed-since <base>` is local only; CI keeps every shard and rejects combining that option
with sharding. The check and suite overlap; the site follows the check so it can reuse only
the validator's existing exact-content cache after its own fresh publication scan. No rendered
site or acceptance result is trusted from a previous candidate.

Follow `docs/anti-eu-bureaucracy.md`: ship in bulk, decide rather than stop, and add no ceremony beyond named rules.

Paste into a fresh session started in this repository, naming the profile:
`Read docs/orchestrator-runbook.md in this repository and follow it exactly. Your profile is <cheap|full|claude-low>.`

You are the routine orchestrator. Goal: move functions through the pipeline (draft, confirm,
review, accept, push) by executing the list `python3 tools/flow.py next-actions` prints. The tool
holds the state and decides the order; you decide nothing about ordering and judge nothing about
matches. Planning, new kinds of work and every exception below belong to the planning
orchestrator (`.claude/agents/orchestrator.md`, strongest model) or the maintainer.

## Five binding rules

1. **Private stays private.** Everything under `.local/` is game-derived or private. Never paste
   it into a commit, an issue, a PR, a public message or a brief for a model whose exposure is
   not recorded in `docs/authorizations.md`.
2. **Only tools decide.** A match is a comparator report; acceptance is `tools/accept_function.py`
   run by the push lane (`flow.py lane-run`). Never claim a pass, an approval or a green CI a tool did not print.
3. **Never weaken a check.** Never edit the comparator, validator, lint, a match record, a saved
   review, `docs/verification.md`, `docs/authorizations.md`, `AGENTS.md` or agent definitions. A
   refusal is a stop, not a problem to work around.
4. **Workers get a brief path, not prose.** Every worker you start gets one line naming a brief
   file `flow.py` wrote. You never write briefs by hand.
5. **Small context.** Workers return a short table; full output is in files. Do not open a review,
   handoff or log unless a step below tells you to.

## Starting a worker

`next-actions` names the role, the model, the harness and the one-line prompt. Start it the way
your harness does:

| harness | how |
|---|---|
| Claude Code (Agent tool) | `Agent` with `subagent_type` as given (`reviewer`, `engineer`, `drafter`, `direction-check`), `model` as given, the prompt line as given. Independent starts go in one message so they run in parallel. Code-writing workers that may overlap get `isolation: "worktree"`. |
| T3 (`delegate_task`) | `delegate_task` with the model and effort given and the prompt line as the task text. |
| any other (two terminals) | open a second terminal in this repository, start the named model's CLI there (Claude Code, Codex) with the model and effort given, and paste the prompt line. Wait for its return table. |

**Reviewer model.** The acceptance rule (`docs/verification.md`, "Admitted Reviewer classes")
admits Opus by default and `gpt-6.1-terra` under `claude-low`; Sonnet is pending calibration and
a Reviewer-checked rule change. Under `claude-low`, Sol is admitted for any review and Terra
is the default first Reviewer; exactly `gpt-6.1-sol` is the strong Reviewer
for sampling second passes, confirmation of non-Opus escalations and reviews of comparator,
validator, verifier and acceptance-rule changes. Sol was admitted by maintainer decision WITHOUT
a calibration ("sol is goood enough dont waste time"); Terra's admission followed calibration.
Every second pass under `claude-low` uses a different model from the first review; an initial
Sol review therefore needs Opus. Opus keeps these duties outside `claude-low`. Independence is
per run: fresh context, never the run that drafted, engineered, triaged or first-reviewed the
function. A profile Reviewer the rule does not admit is replaced by Opus with a note; a sampling pass with no admitted independent model is refused.

A Codex worker that should follow a runbook gets the runbook line: Reviewer
`Read docs/reviewer-runbook.md and follow it. Your brief is <brief path>.`; Drafter
`Read docs/drafter-runbook.md in this repository and follow it exactly. Your worker label is <label>.`

After a successful lane push, `flow.py lane-run` runs claim synchronization.
A failure prints a warning and leaves integration successful; retry with `python3 tools/claims.py sync`.
Sync counts only acceptances on `origin/main`, updates the accepted count, and comments and closes
an issue when every member is accepted. It leaves unknown range members open. Fetch origin before
running sync manually. Issues without the new claim block are left alone.

Contributor claims are closed separately: the PR bot runs `claims.close_completed` every ten minutes, and
`python3 tools/claims.py close-done [--dry-run]` does the same by hand. Any open `claim:` issue whose
functions are all `matched` on `origin/main` gets one closing comment.

## The loop

1. `python3 tools/flow.py session-start --profile <profile>` (once per session). It prints which
   model does each role. Then run `python3 tools/claims.py publish --dry-run` and
   `python3 tools/claims.py publish` to expose every queued, drafted and confirmed unaccepted
   function on GitHub. This publishes only build ids, RVAs, counts and names from committed
   inventory, assigned to the authenticated GitHub user. It never publishes task paths or notes.
   `publish` is idempotent and groups work by queue, family or static cluster (at most 15 issues).
   Additional family checkouts and static member/range manifests may be supplied with
   `--family-root` and `--cluster-list`, or ignored `.local/claims-config.json` settings
   `family_roots` and `cluster_lists`. A cluster manifest holds `build_id` and `clusters`, each
   with `members` (RVA values or objects with `rva`) and optional `ranges` (`start`, `end`).
   Ranges must cover the member starts; use only ranges known not to reserve unrelated work.
   Set `project_login` in that local config only to override the authenticated user's login.
   `work_queue.py add` and `next` skip units containing other people's live claims, reporting the
   issue; their `--refresh` option bypasses the ten-minute cache. Offline reads warn and use stale
   claims without stopping the pipeline.
2. `python3 tools/flow.py next-actions`. It prints numbered lines, each `[stop]`, `[run]`,
   `[dispatch]`, `[wait]`, `[end]` or `[done]`.
3. Do every `[stop]` line first: report it (see "Stop and escalate"), and do nothing else for the
   group it names. Lines for other groups may continue.
4. Do the `[run]` and `[dispatch]` lines from the top, exactly as written:
   - `[run]`: run the command. If it prints a brief path and says to start a worker, start one
     worker per brief path ("Starting a worker").
   - `[dispatch]`: start the worker as written, then run the `Then:` command it gives (for example
     `python3 tools/flow.py dispatched g004`) so the tool knows.
   - A command that exits non-zero: read its last lines. If it says `STOPPED at`, `REFUSED`,
     `DISAGREE`, `ESCALATE`, or CI `RED`, that is a stop: go to "Stop and escalate". Otherwise run
     it once more; a second failure is a stop.
5. `[wait]` lines need no action: workers are running. When a worker returns its table, check
   that the file it names exists (`ls <path>`), then go back to step 2. Do not read the file.
6. When only `[wait]` and `[end]` lines remain and no worker is running, or after about four
   hours, do the `[end]` lines and finish ("End of session").

`flow.py integrate <group>`, `integrate-groups <groups...> --name <batch>` and
`integrate-family <batch path>` enqueue the existing selections and return immediately. Keep
the source checkout and its approved inputs available until the lane finishes. The queue records
the input root, selection and options under `.local/flow/lane/`; `lane-status` prints its receipts.
Label-only re-acceptances use `integrate-labels --functions <ids or RVAs...>`; their existing
code-section, provenance and sampling requirements remain unchanged.

Every new lane build and `tools/verifier/confirm` invocation has a 3 GB hard minimum (decimal).
A configurable soft floor defaults to 10 GB: `--soft-free-gb` or `SKYRIM_SOFT_FREE_GB`.
Tooling validation uses the same admission policy. Below the soft floor, a job warns and refuses
unless `--allow-low-disk` is explicitly supplied. That flag
never overrides the 3 GB hard minimum. The lane's existing `--min-free-gb` / `SKYRIM_LANE_MIN_FREE_GB`
can request a higher minimum; neither can admit a new build below 3 GB.

Workers enqueue all ready work and leave publication to the persistent lane service below.
An operator may run `python3 tools/flow.py lane-run` for a manual recovery. One runner takes everything
queued at its start, carries only the approved input through the existing acceptance path into
one isolated local clone at current `origin/main`, rebuilds the index once, stages named files,
runs `check.py --staged` and makes one combined commit. It runs `check.py`, the full unit suite
and `build_site.py` once on that exact commit, pushes it, and waits for exact-commit CI with
`ci_status.py`. Work enqueued during the run remains queued for the next run. `--run` on an
integration command remains an operator option; workers omit it. `--no-push` runs locally, stopping after checks.
Resume a failed check or pending CI with `lane-run`; it retains the candidate and checkpoint.
A red CI stops the lane before any later push.

The lane regenerates these fully derived tracked files on the merged tree instead of textually
merging them: `reconstruction/INDEX.md`, `docs/progress.svg`, `docs/progress-map.svg`,
`docs/model-trend.svg`, and `docs/progress-trend.svg`. It uses that tree's `build_index.py`,
`build_progress_svg.py` and `build_model_trend.py`; `build_site.py` rebuilds the ignored `dist/`
site. Only the totals between README's `model-trend-totals` markers are derived; prose still
merges normally. `data/progress.json` is source data: function rows merge atomically by ID,
disjoint additions/edits survive, competing edits to one row or other source data refuse, and
`updated_at` takes the latest input timestamp. No match record or symbol map is derived away.

A lane selection may carry its own new inventory rows, so mapped enrollment and acceptance
need no separate pushes. The lane carries only selected new rows, initially `mapped` with no
acceptance or `named` flags, then runs the unchanged individual/family acceptance checks.
Local shadow approvals for new rows are not copied as acceptance; the acceptor must write them.
Failed members are removed during the ordinary re-carry. Committed mapped-only enrollment can
travel with `--with-metadata`; every historical inventory delta must be additive, with existing
rows and other source data unchanged. Source/tooling commits still need `tooling-push`.

An individual acceptance failure is recorded with its reason and excluded; successful members
still ship. Family binding/sampling failures hold the entire family batch, never shrink its
committed population. A whole-tree check failure stops the run without pushing unless tooling
inputs can be isolated as described below. Inspect dropped items in `lane-status`, fix their evidence and enqueue them again. Missing inputs or conflicting
source closures are refusals, not permission to overwrite them. If origin moves, the lane checks
for overlapping inventory/source changes, replays the combined selection on the winner and
reruns all required checks. It never pushes an unchecked rebased tree.

`.state.lock` protects queue snapshots and short state/receipt writes. It is released throughout
acceptance, checks, push and CI; a separate nonblocking `.lane.lock` admits one runner. Record-only
commands and review saves can proceed during a lane run. Candidate clones and failed attempts
are retained. No lane operation prunes worktrees, branches or stashes; cleanup is opt-in through
`flow.py cleanup` (preview with `--dry-run`). It checks each DONE, RETIRED, STALE or FAILED receipt independently, including retry trees;
running/queued receipts, pending CI and live inputs are retained. Cleanup uses its own lock, so
an unrelated lane run can continue. Add `--prune-claims` to include completed harvested
drafts without claims. AGREE reruns are also eligible. Dirty claim/rerun trees, locked
worktrees and queued inputs stay intact. Finished lane working copies archive any local diff.
Private JSON, text logs, handoffs, reviews and worktree registrations are archived under
`.local/archive/cleanup/`; Git object stores, refs and stashes stay intact. Claim pruning requires
a done marker, a harvest commit present in the object store, no open claim in any tier, and no
changes outside `.local`. Use repeatable `--keep-task-prefix` to protect named workers.
Independent lane clones keep `.git` in place so borrowed objects, refs and stashes stay usable;
only their working files are removed. Registered worktrees use plain `git worktree remove`,
without force, pruning or branch/stash deletion. Afterwards `flow.py sync` fast-forwards the shared checkout, replacing
only local copies byte-identical to origin; differing files refuse and stay intact.

`lane-run` and `tooling-push` refuse a runtime whose Python sources or JSON configuration under
`tools/` differ from the fetched integration base (`origin/<branch>`, normally `origin/main`).
This covers all local imports, not just the entry scripts. Both the sources at process start
and the current files must agree; editing a live runner's files cannot refresh its loaded code.
The guard repeats after waiting for the lane lease, at each new build and before publication.
A changed origin dependency requires restarting with that base's tools. Running lanes are
never reset or upgraded in place. A pre-existing runner from before this guard still needs a
normal restart after it finishes; it cannot acquire this protection retroactively.

When publishing a change to these tools, run the **base's** entry point with the committed
candidate as `--root`. For example, from the repository root (use unique local paths):

```sh
git clone --shared --no-checkout . .local/p151-base-tools
git -C .local/p151-base-tools remote set-url origin "$(git remote get-url origin)"
git -C .local/p151-base-tools fetch origin main
git -C .local/p151-base-tools checkout --detach origin/main
/opt/homebrew/bin/python3.13 .local/p151-base-tools/tools/flow.py \
  --root "$PWD" --flow-dir <shared-flow> tooling-push --wait-lane
```

The retained clone supplies the running implementation and imports. The candidate's changes
are merged into the separate integration tree and run through its own full checks as usual;
the guard does not require those intentionally changed candidate tools to equal the base.
If origin advances its tools while waiting, refresh the base-tools clone to the new origin
revision and restart the command. Keep `--root` pointed at the original committed input.

Tooling publications also use the lane: `flow.py --root <committed-tooling-checkout> --flow-dir
<shared-flow> tooling-push`. For Git worktrees its default flow directory comes from the common
Git directory; independent clones must name the shared flow explicitly. It registers the committed
tip before taking the lane (`--wait-lane` waits for a busy lane). The next runner takes every waiting
tooling request in queue order together with all queued function selections. This includes lane tooling; the
running acceptance implementation still enforces the existing gates, and the candidate runs
all full checks. Waiters do no full checks in their own checkout. Conflicting inputs are bounced
with their revision and reason while the rest continue. One combined tree gets one check run,
one push and one exact-SHA CI watch. Arrivals after the snapshot join the next batch.

If combined checks fail, the lane first checks the function/base tree without tooling. A failing
baseline stops publication without blaming tooling. Otherwise it bisects tooling inputs in
halves, with at most `ceil(log2(n))` split levels (one bad input needs O(log n) probes; several
bad inputs may require more probes at a level). Each probe checks the entire surviving combination,
so its final pass can be published without repeating those checks. Bounced revisions and reasons,
probe rounds and retained logs are recorded in the batch receipt. Every waiter returns its own
request outcome and the common pushed SHA, or exits nonzero with its bounce/failure reason.
Request receipts under `lane/tooling/` refer to their owning `lane/runs/` receipt; the original
`lane/tooling-queue/` entries and `events.jsonl` remain available. Legacy tooling receipt resume
commands retain their existing behavior. With `--no-wait-lane`, a busy lane returns nonzero while
leaving the registered request queued for the next runner.
`lane-status` reports dead owners using PID, host and process birth, including legacy runs after
their lock is free; its resume/retire commands preserve the receipt and candidates. A pushed run
can resume CI but cannot be retired. The service may retire a dead local unpublished receipt and requeue its retained inputs as described below.

For read-only bottleneck numbers, run `python3 tools/pipeline_report.py --root <shared-checkout>
--flow-dir <shared-flow>` (one command), or add `--json`; `--output <file>` saves only that
file. `--offline` skips GitHub job queries; repeat `--log <file>` for operational logs outside
the lane and handoff directories. It reports lane/CI timelines, waiters, estimated
drain time, flow-derived function states with age buckets, handoff stalls and 24-hour refusal
observations. It never fetches refs or creates locks. Run against the shared checkout for its
queues and saved reviews; pushed state uses its existing `origin/main` ref. Unknown historical
times stay unknown; log/receipt-mtime estimates and age proxies are labelled. Process ages
bound unrecorded tooling waits, and refusal counts are observations, not unique attempts.

## Approved subsets (Engineer)

When rejected or disputed members hold an individual group, an Engineer may run
`python3 tools/flow.py split-group <group> --functions <RVA or id> ...` to freeze an explicitly
approved subset. The original group, saved verdicts and sample draw stay unchanged. The subset
retains every selected member's original second-pass requirement. If too few original sampled
members remain to cover 5%, it adds a deterministic random sample and writes new second-review
and clean-rerun briefs; finish those before integration. A selected disagreement still refuses.
Integrate the returned subgroup with `--approved-only`. Only its selected inventory entries,
records and required unit files enter acceptance. Rejected and disputed members stay held.

A shared unit is copied whole, so its changes can stale other acceptances. Re-confirm and
re-review affected accepted functions under "Stale acceptances and delta reviews" before the
unit and renewed evidence land together. Splitting never exempts a family member, clears a
rejection or escalation, or permits a stale unit through the staged check.

## Family batches

`next-actions` also prints family review needed, draw sample, review sample and accept batch
steps. The planning orchestrator and Engineer choose a bounded family and batch; the routine
orchestrator never picks parameters, ranges, the population or a seed. A family is the generator
or stamp template plus version and template digest, bound to the target build, recipe, compiler
and comparator. Any change starts a new family. Each member carries its parameter row and
name-source label; a comparator pass proves no name.

Engineer setup (no verifier or acceptance is performed by these metadata commands):

1. Prepare a private JSON spec with `origin`, `binding`, `template_source`, `parameter_source`,
   `parameter_ranges` and `first_members` (the first 20 enrolled inventory ids, in order).
   `binding` is `family_review.binding(fn, match_record)`; each source has `path` and `sha256`.
   Run `python3 tools/flow.py family-plan --spec <spec>` to freeze member digests, write the
   public manifest under `reports/<build>/families/`, and generate its Reviewer brief.
2. If the first 20 are confirmed and ungrouped, planning creates one normal group and a combined
   brief: one fresh admitted primary Reviewer writes both the family JSON and their individual
   review blocks in one pass. The independent second-pass safeguard still applies. Integrate the
   first 20 normally before approving the family. Already-reviewed first 20 keep their normal
   evidence and safeguards. Start the family Reviewer on the generated brief; its JSON format
   and checklist are in `docs/reviewer-runbook.md`, "Family reviews". `family-approve <manifest>
   --review .local/reviews/<task>.family.json` checks the saved approval and all 20 safeguards.
3. `python3 tools/flow.py family-batch <manifest> --name <batch> --seed <seed> --functions <ids...>`
   freezes the complete later population, including member digests. Stage the metadata by name,
   run `check.py --staged`, and commit it before `family-draw <batch path>`. Commit the drawn
   batch before any population member is accepted. These metadata commits belong to the Engineer;
   the routine orchestrator hands an uncommitted metadata refusal to the strong role.

To correct a family before approval, `python3 tools/flow.py family-plan --spec <corrected-spec>
--supersede <old-manifest>` preserves the old paused manifest with a replacement pointer, archives
its saved review files under `.local/reviews/superseded/`, releases its review groups and creates a
fresh family plan and briefs. The replacement keeps the same family name, binding and first 20.
If its source origin changes, both its version and template digest must change; its members need
fresh confirmation and review under that new origin. No old approval carries into the replacement. The
command refuses an approved family, a family with a batch, or accepted first-20 members; use the
pause and revocation procedure for accepted evidence. Archived reviews are not approvals of the
replacement. Resolve any independent provenance or policy escalation under the existing rule.

The draw ranks population ids by SHA-256 of canonical JSON `[seed, function_id]`, breaking ties
by id, and takes `min(population, max(20, ceil(5%)))`. The public batch preserves seed, full
population, member hashes, pre-draw commit and sample. The gate checks that the planned metadata
was committed before selection, the draw was committed before acceptance, and no population
member had already been accepted at that exact origin and row in that history. Never redraw,
shrink a population or change a seed after seeing the sample.

An Engineer may combine the committed family metadata and sampled acceptance in one push with
`flow.py integrate <sample-group> --with-metadata`. Unpublished commits may change family
manifests, batch JSON or additive mapped-only inventory enrollment and its fully derived views,
without deletions. The tip must descend from current origin; a merge may
preserve moving main only through a parent already on origin, with only metadata added to that base.
The metadata must validate and match its committed content. The seed/population and draw commits
may contain only the exact tip snapshots or the canonical pre-draw batch (null commitment/sample),
so an invalid intermediate blob cannot hide behind a repaired tip. These commits
remain separate ancestors before acceptance; source, tooling and other unpublished changes are
refused. All ordinary review, comparison, staged, clean-tree and CI gates still run.

The ordinary `review-group` excludes eligible unsampled members, reviews all sampled members
and all parameters outside the approved ranges, and keeps every existing second-pass safeguard.
`integrate-family <batch path>` accepts the remaining unsampled in-range members only after
those individual reviews and safeguards pass, through the same push lane as ordinary groups.
The acceptance tool requires the actual saved approving family review,
an admitted model, active family, exact origin/version/digest and target bindings, unchanged
member rows and the committed draw. Other functions keep individual review; a family approval
cannot be carried by label-only acceptance. No family command changes the comparator or lint.

On sampled rejection, binding error, non-reproduction, provenance doubt, Reviewer disagreement
or another material defect, stop the whole family and run `family-pause <manifest> --reason
'<short public reason>'`. Commit the pause by name after the staged check. Assess the affected
population, explicitly revoke accepted members whose evidence is invalidated, and escalate
policy/provenance or systemic doubt under the existing rules. A pause freezes new acceptance;
existing records stay auditable until explicit revocation. Correct the cause and use a freshly
reviewed family version before resuming. Never clear a pause by hand or retain invalidated
acceptances silently.

## What each worker returns

| worker | returns | full output |
|---|---|---|
| Drafter | `| unit | functions passed | attempts | result line file |` | queue `results.jsonl`, unit `attempts/` |
| Reviewer | `| function | verdict | category | blocking findings | naming findings |` and the review path | `.local/reviews/<task-id>.md` |
| strong role (Engineer, Sol) | `| item | outcome | attempts | file |` | `.local/handoffs/<task-id>.md` |
| direction check | five lines | `.local/handoffs/direction-check-<n>.md` |

A longer return is a worker fault: do not copy it anywhere; note "long return" in the session
summary.

## Stop and escalate

Stop that group (or everything, where it says so) and report to the maintainer, quoting the tool's
line, for:

1. A Reviewer `escalate` with category `provenance`, `legal` or `systemic` (`[stop]` line).
   A non-Opus escalation stays held for independent strong Reviewer confirmation (Sol under
   `claude-low`, Opus otherwise); report to the maintainer only if the confirmer also escalates.
2. A sampling disagreement: a second Reviewer differs, or a re-run is not AGREE (`[stop]` line).
3. CI `RED` after a push: stop everything that would push until main is green again.
4. A pass that does not reproduce on the second host, or any sign that an accepted function is
   wrong.
5. Any question about a gate, a licence, provenance, exposure of private material to a model, or
   spend beyond the recorded limits.
6. Any proposal to change the comparator, validator, lint, acceptance rule, a recorded gate or
   these instructions.

Hand to the strong model of your profile (a planning-orchestrator or Opus/Sol check), with the
tool output and nothing else, for:

7. A command that fails twice for a reason that is not one of the above.
8. A situation `next-actions` does not cover, two lines that contradict each other, or a worker
   that returns something this file does not describe.
9. The baseline decision `python3 tools/flow.py baseline ...` (which versions are already past
   their first 20 sampled acceptances): never run it yourself.

Never resolve these by editing files, re-running a Reviewer until it agrees, or choosing a
different group order.

## Reports every session

- **Friction report**: `python3 tools/friction.py --write` once per session (a `[run]` line asks
  for it). Read only its first paragraph: if it says the cheap profile is below its threshold,
  add that line to the session summary.
- **Direction check**: after every 200 accepted functions, and at least once per session (an
  `[end]` line asks for it if none ran), run `python3 tools/flow.py brief direction` and start the
  `direction-check` worker (strong model of the profile) with the brief. It edits nothing; it
  writes `.local/handoffs/direction-check-<n>.md`. Then `python3 tools/flow.py event direction-check`.

At session start run `python3 tools/flow.py worktrees list`; at session end run `python3 tools/flow.py worktrees prune`.

## End of session

Write `.local/handoffs/orchestrator-<date>.md` with: profile; groups dispatched, integrated
(commits and CI result), held; counts accepted, rejected and escalated; stops reported; the
friction report path and its first paragraph; the direction check path; workers started per role
and model; anything that took a second try. Return the same in at most 15 lines to whoever
started you.

## Never

Commit or push except through `flow.py lane-run` or an integration command with `--run`
(Engineer metadata commits are described above); run `accept_function.py` directly; edit a
saved review; start a Reviewer on work it drafted, engineered or triaged; give a worker
material its model is not cleared to read; start a Boat machine (Boat is retired; confirm briefs
use the runner hosts); post anything publicly.

When the profile has a fallback Drafter, `next-actions` offers failed first-tier units through `brief drafter --tier fallback`; dispatch the specified model with that brief. Fallback results and counted attempts are recorded separately from the first tier. The strong tier dispatches only after fallback finishes with unpassed functions; use `work_queue.py hold <unit> --reason <reason>` and `unhold <unit>` to control dispatch.

## Importing isolated family state (Engineer)

`python3 tools/flow.py import-state <worktree>/.local/flow --reviews <worktree>/.local/reviews`
imports an isolated worktree's private review scheduling state into this repository's shared
`.local/flow`. Run it before replacing the source directories with links to the shared ones.
The source must be another worktree of the same repository. It validates match records, unit
and first-member digests, family template/extraction pins, saved family approvals and sampling
rerun records against that worktree. A mismatch refuses the import before publishing state.

The receipt under shared `.local/flow/imports/` records the input hashes, fresh group ids,
review filenames and unchanged review-file hashes. Saved reviews retain their original task
titles and bytes; an imported group's `saved_review` locates the renamed file. Unsent reviews
get new task ids and collision-checked briefs in the shared checkout, with explicit paths
and instructions to review the source worktree. Combined family instructions are retained. Import preserves dispatch and
sampling records, but does not activate families, accept functions, replay session events or
import sampling version baselines. Family plans and original events are retained as private
snapshots; generated public inputs remain in their source worktree. Continue the family steps
from that source worktree, using the shared flow and reviews directories.

An identical import is idempotent, including after normal progress of its imported groups.
Different existing files are never overwritten. A partially written import blocks other flow and acceptance commands until it resumes with its
recorded id mapping. Direct acceptance takes its repository state lock. Lane acceptance operates
on a private scheduling snapshot in an independent local clone, so it never holds the live state
lock while validating or rebuilding. Keep source state unchanged until import completes. Flow
CLI operations use a permanent advisory `.state.lock` in their resolved flow directory; readers
also lock so multi-file mutations stay consistent. Group, queue and receipt JSON use atomic
replacement. Run the updated tooling in every concurrent orchestrator; older integration
processes retain their old whole-run lock until they finish.

## Persistent lane service

Never kill a lane process you didn't start. Only the lane service or a run's recorded owner
may stop or retire it; a worker's time box or missing own output grants no ownership.

Workers only enqueue: use `integrate`, `integrate-family`, `integrate-groups` or
`tooling-push --enqueue-only` (clean committed tip). Omit `--run`. Enqueue-only tooling
records the immutable revision and returns without taking the lane, checking runtime freshness,
running tests or waiting for CI. Keep input checkouts and approvals available.
Never kill a shared publisher, its descendants or process group because a worker's box ends,
its own acceptance output is absent, or it has waited 15 minutes. Report the receipt and log
instead. A publisher can be doing work for thousands of other queued functions.

Run the generic service from an operator-managed scheduler using an ignored configuration:

```sh
python3.13 tools/lane_service.py --config <private-service-config> run-once
```

The private JSON configuration names `root`, `flow_dir`, `python`, `branch`, `soft_free_gb`,
`ci_wait` and optional `environment` settings. Scheduler installation and machine-specific values
belong in the operator's ignored runbook. Supply the private publication and anonymity policies
through that environment when needed. `run-once` probes an empty or busy queue without publishing;
with actionable inputs it really publishes. Do not terminate a live publisher.

Each tick probes the existing lane lock and returns immediately if busy. A separate service
lock prevents overlapping service invocations. An idle tick sends no network traffic. A working
tick checks disk admission before fetching, refreshes only its dedicated clean `origin-tools`
checkout, and starts a new interpreter from that exact origin revision. It runs stock `lane-run`
with all existing acceptance, freshness, full-check, push and exact-SHA CI gates. Gate machinery
continues to publish separately from function selections. New arrivals wait for the next tick.
The service's network operations are git fetch/push and gh CI status only; it disables post-CI
claim synchronization and never dispatches models, remote verifiers or workflow repairs.

Recovery uses the existing retirement path under the lane and state locks. Only known dead
local owners, without a recorded failure and before push, qualify. Their still-owned running or
stale function/tooling queue entries become queued again; newer queue owners and terminal
outcomes stay intact. Receipts, candidates, immutable tooling revisions and every approval are
retained. No review is rewritten or revoked. Recorded failures, conflicts, unknown-host owners
and explicit retirements remain for triage. Legacy tooling receipts use their existing resume
path; workflow repairs require an operator. Pushed checkpoints resume exact-SHA CI and cannot
be retired. The service never overrides the disk floor or weakens a check.

`lane-stop <run-id> --reason ...` and `lane-retire` enforce recorded PID, host and process
birth ownership, or the active service worker's private lock and owner record. A shared source
checkout is not ownership. Foreign calls refuse with a clear message and send no signal or
retirement write. Stop sends SIGTERM only to the birth-checked recorded PID, never a shared
process group. An intentional stop stays held for triage instead of being automatically restarted.
Retirement of a live leased lane still refuses. The service can recover known
dead local owners through its existing guarded recovery path. The private role record prevents
accidental cross-worker control; like the rest of the private flow state, it is not an
authentication boundary against deliberate local state forgery.

Long publishers update `heartbeat` in the run receipt every 10 seconds, including during silent
acceptance, tests, site generation and CI. `alive_at` reports observation time; `progress_at`
advances only when phase/step, measured CPU growth of at least 0.1 seconds (excluding the observer thread), process count,
or log bytes change. Read both: a recent liveness pulse alone is not evidence of forward
progress, a byte match or approval. Missing output is not a timeout. Heartbeats preserve receipt
sidecars and newer ownership and never change a gate, kill a process or imply a test passed.

All service logs and status are under `.local/flow/lane/service/`: `last.json`, timestamped
publisher logs/results and scheduler stdout/stderr. Results record exit status and terminating
signal when observed; service signal handlers log SIGTERM/SIGINT. SIGKILL cannot write a final
receipt, so the next tick recovers a dead owner. A failed command remains visible for triage.

## Pipelined publication and tooling batches

`tooling-push --wait-lane` records the clean committed input before waiting. A new runner takes all
currently queued tooling tips into an independent retained candidate. Input checkouts are never
rebased or reset. Merge conflicts drop only that input, with its reason. A combined check failure
first proves the baseline, then isolates failing inputs using checked prefixes; a failed baseline
stops the whole run. The successful common path runs full checks once.

Queued review groups can share this candidate through the unchanged accept/carry path. Tooling
that changes gate machinery (validator, comparator, acceptance, review parser, verifier or lane)
publishes separately before function work; those functions remain queued. Every member still
passes its original gates. Arrival during a run belongs to the next run.

The build lease ends immediately after push, recorded as `lane_hold_seconds`. Exact-SHA CI and
post-CI bookkeeping run outside it, including `--resume` of a pushed checkpoint. The next run
may check on top of that pushed SHA but must see its CI GREEN immediately before pushing.
A RED or unavailable result aborts the new push. A failed rebase becomes a terminal `conflict`
receipt with an owner resume command. A dead local unpublished owner becomes `stale` at the next
lease, retaining every input and candidate; `--resume <id>` recovers that checkpoint explicitly.
Live owners are waited on, not treated as foreign resume requests.

A maintainer-authorized advisory hash repair can finish an already pushed dead-owner receipt:
`python3.13 tools/flow.py lane-finish-superseded <run-id> --superseding-commit <full-SHA> --reason '<authorization and repair>'`.
The command verifies published ancestry and exact-SHA CI: the original failure must be confined
to the advisory target-hash compile step, Infrastructure and Pages must pass, and every
superseding workflow must pass. It preserves the pushed commit and accepted count, records
`ci: red-advisory-superseded` with both CI observations and the superseding SHA, then finishes
queue bookkeeping. It never changes progress or reports green for the original commit.

`SKYRIM_LANE_PYTHON` may select the interpreter, but it must be Python 3.13 with working pyexpat.
The complete standard unittest discovery inventory runs via `tools/test_suite.py` in isolated
module processes, preserving module/class fixtures and reporting every test. Existing unittest
environment decorators retain their usual meaning; no tests are excluded by the runner.
CI uses the same Python 3.13 runner. Infrastructure performs diff hygiene, metadata/lint, the full
suite and the site build; Pages consumes only its successful artifact for the exact same SHA,
then deploys. This removes duplicated work across workflows, with no check removed.

A lane run may carry approved sampled members and their family bulk together. It applies the
prepared individual reviews through the normal validator first, staging their records and a
validated inventory snapshot in memory. The unchanged family gates read that provisional snapshot.
Preparation shares inventory parsing, global validation, review parsing and hashes within each
stable snapshot; per-member gates still run. An already accepted local member carries through
only when its current digest and exact saved review agree with its validated approval record.
The lane preserves that record and date, including sampled approvals during re-carry after an
unrelated refusal. Changed reviews or bindings still take the ordinary acceptance path.
Before acceptance, the lane drops carried members whose changed unit or header makes an
existing matched sibling stale, with `stale-sibling: needs re-confirm` and the affected units.
It re-carries the rest before the unchanged whole-tree guard; a family selection remains atomic.
Re-confirm the held units and review their deltas together before enqueueing them again.
The final transaction validates everything, writes progress once and rebuilds the index once. Planning, dropped requests or any final failure
restore all provisional public files; no sampled or unsampled member gains an exemption.

Function-only lane runs rely on the lane acceptance checks, check.py, site build and exact-SHA CI. The lane compares its exact candidate with its pinned origin base: source and reports under `reconstruction/` and `reports/`, `data/progress.json` and the generated progress/model views qualify (README changes qualify only inside the generated model totals markers; Python and recipe changes do not qualify). Those runs skip only the local full unit suite; exact-SHA CI still runs the complete suite before a successor may push. All other changes run the full local suite too: computed file reads and dynamic imports prevent reliable dependency-based narrowing. Acceptance records, bindings, digests, harvest equality and Reviewer admission are unchanged.

Lane candidates share successful revision and publication-blob memos in `<shared-flow>/revision-cache`,
selected by their local Git configuration. Revision keys bind the exact index, working/untracked
and ignored public inputs, executing tools, runtime/encoding and private policies. Blob keys bind Git blob identity,
path, mode, scanner code and private policies. Working files are read and hashed on every scan,
including files marked assume-unchanged. Failures never enter either cache; deleting the cache
only makes the next checks cold. Concurrent revision writes use atomic replacement, and blob
additions use atomic database transactions. No memo is acceptance or comparator evidence.


### Re-confirm dropped shared units

`python3 tools/flow.py --flow-dir <shared-flow> reconfirm-dropped --dry-run` lists distinct
stale-sibling and changed-carried-file targets from finished receipts. Without `--dry-run`, it
creates a retained worktree on current origin/main, merges each dropped unit, and confirms every
reported function sharing a changed unit on the configured independent runners. No live receipt
or chunk controller is changed. Conflicting inputs and failed comparisons stay held with logs;
failed comparisons are never retried into a pass. An optional wake hook may restore an
unreachable runner using private configuration. Disk admission keeps the normal floors.

The result names private review briefs, full/delta review modes and a single
`reconfirm-dropped --resume <id>` command. Dispatch the fresh admitted Reviewers named in those
briefs; unchanged approvals are reused only when their bindings still validate. Required second
reviews and clean comparator sampling reruns still apply. Resume checks the saved reviews through
the existing parser and gates, accepts through `accept_function`, then enqueues approved groups
for the next normal lane chunk. Other re-confirmed, still-unmatched records from the same units
travel as validated report refreshes, without marking those companion functions matched. All
inputs, approvals, reports and logs remain under the retained re-confirm receipt.
