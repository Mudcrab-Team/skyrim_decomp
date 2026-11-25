# 0x2b96b0 TESObjectCELL::GetGroupSubBlockKey

<!-- tags: wall/control-flow, wall/inlining -->

- Function: 0x2b96b0 TESObjectCELL::GetGroupSubBlockKey
- Label: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb)
- Outcome: unsolved
- Cause: branch-layout
- Best score: 69/79 matching bytes; candidate size 91, target size 79
- Attempts: 6

## What differed

The exterior path packs two signed coordinates after dividing each by eight. A missing exterior-data pointer supplies zero coordinates. The target joins that fallback into the shared packing calculation. The best candidate has extra calculation and exit instructions. The interior identifier calculation has no reported behavior mismatch in that attempt. This is a local comparison result, not a match or proof of semantic equivalence.

## Spellings tried that did not help

- Returning zero immediately for missing exterior data measured 51/79 matching bytes.
- Returning the interior result first measured 41/79.
- Assigning both coordinate locals before packing improved to 69/79, but produced a larger function.
- An inline accessor assigning coordinate references and separate scalar accessors both remained at 69/79.
- A common result local measured 32/79.

The sixth comparison reached the hard cap and the third consecutive comparison without improvement. No register-only wall was diagnosed, so no permutation run was required. All six snapshots and reports remain private. The best direct-local spelling is retained as a near miss. Rules 40 and 61 suggested accessor boundaries but did not close this function; rule 34 did not improve it.

## Spelling that fixed it

None.
