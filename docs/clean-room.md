# Research and implementation boundary

Mudcrab is a separate engine project. This repo is an exposure-bearing research workspace;
its existence does not certify Mudcrab or any contributor as clean-room independent.

A strict separated workflow assigns binary/source inspection to researchers and independent
implementation to people who work from reviewed behavior specifications and test observations.
Track access/exposure rather than relying on repository names. Reading the FNV or Fallout 3 (`momusdigital/f3_decomp`) decompilation,
which the maintainer allowed for reconstruction work (`docs/authorizations.md`, Notes), is
exposure to another game's reconstructed implementation and to names its README attributes to a
development-build PDB and middleware source. Record it like any other exposure; units carrying
`SIBLING` labels or a `Sibling source:` line show it. An agent that has read recovered
implementation code must not claim to be an unexposed implementer. A fresh chat does not erase
prior access, shared files or retrieved context. Reading the CrashLogger PDB or its committed output (a community name and layout source the
maintainer allowed, `docs/authorizations.md`, Notes) is exposure to community-generated names and type layouts;
units carrying `CRASHLOGGER_PDB` labels show it, and the generated directory can be stripped in bulk.

For each proposed transfer, record intended recipients, all relevant source exposure, what
information is being transferred, the evidence supporting it and the maintainer's decision.
Prefer externally observable input/output rules and synthetic tests. Do not translate a
reconstructed function line-for-line into prose and call it a clean specification.

Every specification begins `Transfer status: UNREVIEWED` and includes an exposure declaration.
Approval is a project process decision, not a legal certification. Do not automatically copy
files into Mudcrab, add research as its dependency, or port recovered code there.

Running a matched pure leaf unit (or a closed chain of matched units with no stubs) locally as an
input/output oracle is a local-only research aid: commit and publish none of its inputs, outputs or
traces (at most aggregated pass/fail counts per RVA), and it is never evidence for `matched`, which
stays a byte match on two hosts plus one review.
