# Bounded private working storage

Worker creation uses `sparse_checkouts.add_worktree`: the generated static units and site are
omitted until needed. Full acceptance/check/site runs still use their complete required view.
`worker_default(tree, config)` also supports a local post-checkout hook for application-created
workers, keeping reports and all reconstruction sources. Its ignored config supplies
`worker_roots`, protected `keep` paths and optional `shared`
links for toolchains, Wine prefixes, sources and analysis. It changes only clean eligible new
workers and never replaces an existing private input. `draft_worktrees.link_private` already
shares kit inputs rather than copying them.

Lane completion calls `flow_cleanup.automatic_retention`. All worker retention archives use
`archive/cleanup` beside the shared flow directory, so one configured cold store covers them
instead of creating independent archive piles in each worker. Terminal candidate/retry working
files are removed after evidence is saved; dirty registered worktrees are refused **before**
archiving. A process or open file protects the tree. Terminal isolation scheduling snapshots
move to cold archives once all their candidate working files have gone. Git object stores
remain in place unless cold storage has `object_store_roots` configured for a complete project
borrower scan. Terminal stores with no borrowers are then archived and hash-verified before
removal, preserving all refs, objects and metadata for restoration. Borrowed stores stay put.

Optional cold storage is configured in ignored `.local/cold-storage.json` beside the shared
flow directory (or `SR_COLD_STORAGE_CONFIG`). It contains `directory`, `host`, `mkdir`, `copy`,
`hash`, optional `manifest`, `archives` and `min_age_seconds`. Transport values are argument
arrays; `copy` receives the local package and remote `host:path`, and `{path}` in `hash` is
replaced with the remote package path. The hash command must return only SHA-256. No host,
account, private path or scheduler installation belongs in tracked examples.

Only completed retention archives with `receipt.json` and `removed: true` are automatically
eligible, after the configured age. Packaging preserves symlinks, independently verifies the
remote package hash, checks the complete local file inventory again, and writes the offload
manifest **before** deleting local data. Failure or a new live reference retains the original.
The manifest records each original path, remote package and SHA-256 for restoration. Package
and manifest writes are serialized. Local schedulers can invoke `tools/retention_service.py --config <ignored-config>` periodically
to offload archives even when no new publication occurs. Network offload runs only in this
separate service invocation (`offload=True`), so publication never waits on archive transport. Its config supplies `repository` and
`flow_dir`. Scheduler installation and paths stay local.

Space is bounded for completed working files and verified cold archives when the destination
is available. Active/dirty work, unresolved claims and borrowed Git stores remain protected;
their size is reported rather than silently discarded. Archive/network failures preserve inputs
and are recorded in the retention receipt for retry on the next service invocation. Disk admission floors are unchanged.

Staged guards use owned, locked `.local/check-exports` slots. A later guard or the service
reaps only unlocked slots carrying the export marker; a live guard keeps its lock. This also
recovers exports left by abrupt process exit without changing validation or staged contents.
The service config can list `export_roots` glob patterns covering worker namespaces.

For legacy publishers still running the pre-fix archiver, ignored config can explicitly enable
`include_failed_archives`. A saved failed-copy receipt is written only after payload archival;
its independent copy can be offloaded after the same age, live-reference, inventory and hash
checks. The dirty original is never selected or modified. This backstop does not require
stopping older publishers; the pre-archive dirty check prevents new copies in updated tools.
