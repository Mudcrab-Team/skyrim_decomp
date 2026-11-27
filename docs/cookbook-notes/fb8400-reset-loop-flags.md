# 0xfb8400 NiPSysResetOnLoopCtlr::Update

<!-- tags: wall/control-flow -->

- Function: 0xfb8400 NiPSysResetOnLoopCtlr::Update
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: integer-width-or-cast
- Best score: 47/184 matching bytes; alignment distance 31.0; 146-byte candidate extent
- Attempts: 4

## What differed
The target uses repeated byte-width flag extraction and a virtual scaled-time computation before conditionally setting the particle-system reset flag. The candidate remains shorter, with differences in flag handling, argument preparation and field displacements. The exact cause remains unresolved; layout and control-flow interpretation need another check before register permutation is appropriate.

## Spellings tried that did not help
Ordinary flag masks and explicit shifted tests produced the same score and extent. Separate byte-width locals for the extracted bits made the candidate four bytes longer and increased alignment distance to 34.0 without improving matching bytes. A packed bitfield trial without the speculative target-null guard shortened the candidate to 139 bytes and gave distance 31.5. The earlier 146-byte source is retained.

## Spelling that fixed it
none
