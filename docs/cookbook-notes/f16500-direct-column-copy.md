# 0xf16500 NiSpotLight::UpdateWorldData

<!-- tags: construct/float, construct/vector -->

- Function: 0xf16500 NiSpotLight::UpdateWorldData
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: float-codegen
- Best score: PASS, all contract v2 checks passed (53-byte target)
- Attempts: 2

## What differed

The initial original body called the inherited update boundary and assigned the world direction from an aggregate built from one rotation column. It compiled to 68 bytes against the 53-byte target; alignment measured 18/53 matching bytes. The compiler grouped two components into a packed floating-point copy.

## Spellings tried that did not help

Aggregate initialization and assignment of the three-component direction did not reproduce the target's independent component copies. No sibling implementation body was read or adapted.

## Spelling that fixed it

Assign the direction's three scalar components separately from the corresponding rotation-column entries after calling the inherited update. The second native Windows attempt passed the unchanged comparator, including unwind and contract checks. This is one-host candidate evidence, not acceptance. Names are from the labelled CrashLogger and symbol sources; rotation declarations are from the pinned community headers, and accessed offsets were observed locally.
