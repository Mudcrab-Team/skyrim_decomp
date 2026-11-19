# Contributor lessons

- Declare every field the function reads or writes at its offset; named unknown members are fine for regions it never touches, but never hide an accessed field in a byte array or filler, or stand in for the whole class with one array. (docs/reviewer-runbook.md#checklist-per-function)
- Write plausible original source rather than copying decompiler output. (docs/reviewer-runbook.md#checklist-per-function)
- Avoid code whose only plausible purpose is steering emitted bytes. (docs/reviewer-runbook.md#checklist-per-function)
- Ensure each submitted function compiles and binds to its intended symbol. (docs/verification.md)
- Reproduce the comparator pass on both verifier hosts before claiming a match. (docs/verification.md#acceptance-rule)
- Keep the unit header compact: the skeleton's lines only, the one-line `SPDX-License-Identifier: MIT (CommonLibSSE-NG ...)` notice instead of licence text, no Task, Labels, Evidence, Drafted by, default Recipe or disclaimer lines, and at most 6 header lines besides labels, `Sibling source:` and `0x<rva> <Name>` lines. (docs/contributor-card.md, compact headers) To tidy an older header run `python3 tools/compact_headers.py --apply`: with no path it touches only the reconstruction files your branch changed against origin/main and lists them first; the whole tree needs `--all-tree`.
- Mark inferred names as guesses and preserve unknowns. (docs/reviewer-runbook.md#checklist-per-function)
