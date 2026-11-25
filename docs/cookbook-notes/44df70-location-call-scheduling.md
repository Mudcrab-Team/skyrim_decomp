# 0x44df70 BGSPackageDataLocation::IsRefAtLocation

<!-- tags: abi/virtual, method/diagnostic, wall/register-schedule -->

- Function: 0x44df70 BGSPackageDataLocation::IsRefAtLocation
- Label: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 63/75 aligned matching bytes; distance 1.5
- Attempts: 4 counted comparisons; 4 invocations total, including binding-only and final-source provenance checks as applicable

## What differed

The two nullable virtual dispatches have the expected call slots, extent and prologue. The resolved location is moved into the receiver register later in the candidate, and its second vtable uses another scratch register. The measured residue is scheduling and register selection, with no reference mismatch.

## Spellings tried that did not help

- A local resolved pointer inside nested positive null checks: 63/75 matching bytes, distance 1.5.
- A local lambda providing null-safe final dispatch: unchanged on the completed PC comparison.
- A static null-safe dispatch helper and a flat early-return body: both unchanged at 63/75 and distance 1.5.
- Bounded permute search from the initial source: 73 candidates, pool exhausted, distance 1.5 unchanged.

## Spelling that fixed it

none. The first-pass draft remains a private near-miss; this score is not a byte match.
