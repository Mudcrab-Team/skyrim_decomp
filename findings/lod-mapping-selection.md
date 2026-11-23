# Finding: LOD function mapping selection (20 entries)

Status: selection metadata only; no match and no behavior claim. Function starts and extents are image-derived facts (OBSERVED by local static analysis). Every class attribution and every name is a HYPOTHESIS.
Author / human operator: Taylor Turner
AI assistance / model: Claude Sonnet 5.5 (`claude-sonnet-5-5`), worker LOD-ENROL-POST
Date (UTC): 2026-11-23
Target build id / image SHA-256: `sse-steam-1-7-104` / `846efccf0c13… (full digest in builds/target.json)`. The operator measured the same digest on their own copy.
Source exposure: mixed. Local static analysis of the operator's pinned image (no bytes, listings or decompiler text are published here), plus the public CrashLogger community PDB names already in the repository.
Sources and immutable revisions: the pinned image; `reconstruction/generated/crashlogger_pdb/names` (label `CRASHLOGGER_PDB(59818@2026.10.24)`).
Name provenance: CRASHLOGGER_PDB for 6 entries; GUESS (placeholder) for 14 entries.
Confidence: medium for the function starts; low for the extents until compared with the project's extent table; low for every GUESS class.

## Question and method

Why are these 20 RVAs in scope? The department works on retail LOD functions of the pinned build (distant terrain and object LOD tier selection, queued upgrades and downgrades, large-reference handover, terrain LOD texture lookup and fallback). The merged findings [object-lod-retail-facts.md](object-lod-retail-facts.md), [object-lod-segments-retail-facts.md](object-lod-segments-retail-facts.md) and [terrain-lod-shading-retail-facts.md](terrain-lod-shading-retail-facts.md) describe these features. Only `0x51b040` and `0x51b320` appear by RVA in them (both in `object-lod-retail-facts.md`). The other 18 come from a local, unpublished inventory of the operator's static analysis of the same image. That inventory groups them under the same features. The grouping is a HYPOTHESIS and says nothing about what any function does.

How the RVA and size were found: static analysis of the operator's own pinned image gave the function start and the size, which is the extent of the local analysis. These sizes were not yet compared with the project's extent table. The 20 RVAs are not in `data/progress.json` and not in the published target-hash list at the time of this change. No existing entry overlaps them. `python3 tools/mapping_check.py` checks the duplicate and overlap rules.

Name sources, per row:

- 6 entries carry a public qualified name from the CrashLogger community PDB. A community guess, not evidence.
- 13 entries carry `Class::Function<rva>`. The class is a low-confidence reading from local static analysis of field use. It is not from a public table. The method name is a placeholder, as in claim-time entries (`findings/claim-time-mapping.md`).
- 1 entry (`0x2ad340`) carries `TESObjectLAND::Function2ad340`. Its class comes from the public CrashLogger name at that RVA. The method name is a placeholder and the PDB method name is not used.

Sizes: 6 entries up to 128 B, 13 of 129 to 512 B, 1 above 512 B.

## Negative results and limitations

- Class guesses are GUESS(low). A wrong class gives a wrong unit path; contributors cannot change an existing name, so the maintainer would have to.
- Placeholders keep `Function<rva>` method names. No signature, behavior or identity is claimed for any entry.
- Extents are not yet compared with the project's extent table. The `overlap` check may still refuse a row.
- Functions with no class we can name are left out of this change.
- Counts describe this selection only. They are not a completion denominator.
- A comparator pass proves no name (`docs/verification.md`).

## Reviewer and outcome

Not reviewed. No claim, pull request acceptance or match is made by this note.

## Entries

| RVA | size | name | name source |
|---|---|---|---|
| `0x14e7120` | 283 | `BSFadeNode::ComputeFadeAlpha` | CRASHLOGGER_PDB |
| `0x14ec0a0` | 476 | `BSShaderManager::GetTexture` | CRASHLOGGER_PDB |
| `0x1518970` | 516 | `BSLightingShaderProperty::Function1518970` | GUESS |
| `0x1527e60` | 163 | `BSLightingShaderMaterialLODLandscape::ReceiveValuesFromRootMaterial` | CRASHLOGGER_PDB |
| `0x153b3d0` | 226 | `BSShaderTextureSet::SetTexture` | CRASHLOGGER_PDB |
| `0x290e50` | 202 | `TESObjectREFR::Function290e50` | GUESS |
| `0x2ad340` | 89 | `TESObjectLAND::Function2ad340` | GUESS (class from CRASHLOGGER_PDB) |
| `0x511520` | 105 | `BGSTerrainBlock::Function511520` | GUESS |
| `0x5117b0` | 33 | `BGSTerrainBlock::Function5117b0` | GUESS |
| `0x5117e0` | 33 | `BGSTerrainBlock::Function5117e0` | GUESS |
| `0x5188b0` | 122 | `BGSTerrainNode::UnloadDataRecurse` | CRASHLOGGER_PDB |
| `0x518a30` | 139 | `BGSTerrainNode::Function518a30` | GUESS |
| `0x518ad0` | 216 | `BGSTerrainNode::GetChunkForPoint` | CRASHLOGGER_PDB |
| `0x519b20` | 229 | `BGSTerrainNode::Function519b20` | GUESS |
| `0x519c10` | 210 | `BGSTerrainNode::Function519c10` | GUESS |
| `0x519dd0` | 28 | `BGSTerrainNode::Function519dd0` | GUESS |
| `0x51a9b0` | 265 | `BGSQueuedTerrainUpgrade::Function51a9b0` | GUESS |
| `0x51ac60` | 136 | `BGSQueuedTerrainDowngrade::Function51ac60` | GUESS |
| `0x51b040` | 305 | `BGSQueuedObjectUpgrade::Function51b040` | GUESS |
| `0x51b320` | 136 | `BGSQueuedObjectDowngrade::Function51b320` | GUESS |
