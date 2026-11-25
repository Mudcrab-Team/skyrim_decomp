# Worker checkout disk use

New Drafter and queue-claim trees, restored draft branches, harvested confirmation trees and
sampling rerun trees use cone-mode sparse checkout and omit `site/` and
`reconstruction/unmapped/static/`. The post-checkout hook for application-created workers
keeps every tracked directory except `site/`, including reports and all reconstruction sources.
Create a detached rerun tree with `python3 tools/sparse_checkouts.py <tree> <revision>`.
Existing live worker trees are left alone.

Legacy sparse workers can materialize report dependencies on demand from their own index, including
pinned maps, histories and family metadata. Working edits take precedence. Inventory-wide draft
symbol lookups stream omitted reports through `git cat-file --batch` from that index. Source
evidence in the unit's include closure is materialized before the existing lint runs.

`check.py` temporarily expands sparse trees, runs its unchanged full checks, and restores the
patterns even after failure. Old harvest commits with tools predating sparse support expand for
the confirmation command. Confirmation without `--out` therefore still performs its full check.

Reconfirmation needs all reports to find accepted siblings sharing changed includes. It prepares
and operates with a temporary full view, then leaves its retained tree sparse with selected
records and dependencies. Tooling isolation probes likewise require full acceptance and site
checks; each completed or failed probe is made sparse in `finally`. These two kinds save retained
disk, while active full checks still need the full checkout's peak space.

Acceptance lane and legacy integration/check trees stay full: acceptance, publication hygiene
and site generation need the complete reports and site. No comparator, validation condition,
review requirement, acceptance rule or cleanup policy changes. Shared Git objects are unchanged;
savings are working-tree files and their filesystem allocation, less any selected dependencies.
