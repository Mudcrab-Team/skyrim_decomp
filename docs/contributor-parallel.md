# Advanced contributor parallel work (opt-in)

First complete the ordinary [contributor guide](contributing-agent.md). Use this page only when
the owner explicitly chooses parallel work. It grants no extra source exposure or acceptance rights.

## Several agents on one machine

Give each agent its own Git worktree and assign disjoint classes/units so they do not edit the
same source files or contributor task. Point each worktree at the same **existing** private
storage directory with `SR_LOCAL_DIR` (an absolute path is best):

```sh
export SR_LOCAL_DIR="<absolute path to the shared .local directory>"
export SR_CONTRIB_OFFLINE=1
export SR_NO_SIBLING_NAMES=1
./sr --json claim 0x<rva> --offline-ok --model <your-model-id>
./sr --json start 0x<rva> --no-branch --drafted-by "<person>, assisted by <model>"
./sr --json compare <task-id>
./sr --json submit <task-id> --dry-run
```

Without `SR_LOCAL_DIR`, storage stays in this checkout's `.local`. The override shares toolchains,
sources, config, claims, packs and tasks without a symlink; the source under `reconstruction/`
stays in each worktree. Run `setup` once before dispatching agents. Avoid simultaneous writes to
shared config/claims or the same task; coordinate claims and allocate work before the agents start.
`SR_CONTRIB_OFFLINE=1` with `claim --offline-ok` records unpublished local claims; it does not
reserve anything on GitHub. Unset it and run `claim` online before submitting. `start --no-branch`
keeps the worktree's existing branch. `start` prints the task id. With several tasks, `compare`
without a name uses the task whose unit has uncommitted changes, else the most recently modified
task, and prints which one it chose; `submit` still needs `submit <task-id>`.

Without `SR_LOCAL_DIR`, a worktree that has a `.local` of its own (any tool may create one) still reads
what only the main checkout's `.local` holds, per resource: tasks (`contrib/tasks`, an own task of the same id
wins), `contrib/config.json`, the game executable under `contrib/game`, `sources/**` and
`verifier/config.json` (so `tools/check_labels.py` verifies COMMUNITY labels there). An own file or
directory always wins, and an explicit `SR_LOCAL_DIR` is never second-guessed. New files are still written
to the worktree's own `.local`.

Several tasks in one PR: `./sr submit <task> <task>...` or `./sr submit --all-dirty` (every unsubmitted
task whose unit has uncommitted changes) checks each task's last compare, then opens one PR; `preflight`
takes the same arguments. `./sr next --class REGEX` filters classes before readiness is computed, and
`./sr claim ... --skip-conflicts` claims the functions that are free and prints each skipped RVA with its
claim issue (without the flag a conflict stops the claim and names each RVA and issue).

Without `SR_LOCAL_DIR`, a worktree whose own `.local` lacks a toolchain (MSVC under
`contrib/msvc` or `toolchains/msvc*`, Wine under `contrib/wine` or `toolchains/wine*`) falls back
to the main checkout's `.local`, found through `git rev-parse --git-common-dir`. `SR_MSVC` and
`SR_WINE_BIN` still override. `start` on a unit that already exists leaves its header alone and
keeps the task pointing at that unit; only functions the unit does not mention get a new header.

For an agent assigned community headers only, allow searches in the assigned unit, its private
pack, the profile's documents, and these explicit source roots (relative to `SR_LOCAL_DIR`, or to
`.local` without an override):

- `sources/CommonLibSSE-NG/include` and `sources/CommonLibSSE-NG/src`;
- `sources/CommonLibSSE-po3/include` and `sources/CommonLibSSE-po3/src`;
- `sources/AddressLibraryDatabase` (the community name lists).

Exclude `sources/fnv_decomp`, the sibling decompilation directory. Never recursively search all
of `.local`, `SR_LOCAL_DIR` or `sources/`: that includes sibling content. `setup --no-sibling`
skips fetching the optional sibling clone. `SR_NO_SIBLING_NAMES=1` suppresses identifiers in
sibling lookup output from `start` and submit's label/origin advice; for the label tool alone,
`python3 tools/check_labels.py --no-sibling-names <files>` does the same. Findings and exit codes
are unchanged: this controls message text, and does not grant permission to read sibling files.

Adding new functions to an existing unit is fine. Never change the bodies of already matched
functions; add new ones alongside them. Intake re-confirms **every accepted function in a touched
unit** with the unchanged comparator on two hosts. If an accepted function stops matching, that
part is dropped and sent back. A local pass is still not project acceptance.
