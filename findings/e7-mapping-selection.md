# Finding: render material, shader and particle function mapping selection (E7, part 1)

Status: selection metadata only; no new match or behavior claim. Image-derived facts (function starts, extents, vftable slots) are OBSERVED; every name is a HYPOTHESIS.
Author / human operator: Taylor Turner
AI assistance / model: Claude Sonnet 5.5 (`claude-sonnet-5-5`), worker MAP-2
Date (UTC): 2026-11-19
Target build id / image SHA-256: `sse-steam-1-7-104` / `846efccf0c13… (full digest in builds/target.json)`
Source exposure: mixed (local binary-analysis metadata and community headers).
Sources and immutable revisions / licenses: Address Library 1.7.104.0 database (ids to RVAs; `findings/address-mapping.md`); full revisions are in `SOURCES.md`; CharmedBaryon/CommonLibSSE-NG `b93280e` (MIT); powerof3/CommonLibSSE `654e55f` (GPL-3.0); meh321/AddressLibraryDatabase `0379cb6`, used with the author's permission as reported by the maintainer (`docs/authorizations.md`); image RTTI vftable slots; function extents from the image's `.pdata` and the Ghidra analysis body.
Name provenance: COMMUNITY (unverified) for 209 entries; GUESS (placeholder) for 191 entries.
Confidence: high for RVA, extent and non-overlap; medium for class attribution of RTTI-joined names; low for id-joined names and every GUESS class; names remain unverified.

## Question and method

The contributor inventory (`data/progress.json`) lists no function for many materials, shader properties, image-space shaders, particle systems and other render-side effect classes. `./sr claim` and `./sr start` accept only listed functions. This note records the selection that adds 400 such functions as `mapped` entries in one mapping-only change (`docs/contributor-card.md`, "Mapping-only PRs"; `docs/anti-eu-bureaucracy.md`, rules 2 and 3: the cheapest option that keeps the floor, recorded in one line).

The selection starts from 1483 unlisted functions of materials, shader properties, image-space shaders, particle systems and other render-side effect classes that are at most 4096 bytes. Third-party library code is excluded. An entry is added only when all of these hold:

1. The RVA is a function start of the pinned image, and the recorded size equals one extent: the single `.pdata` entry, or the chain of contiguous `.pdata` entries equal to the analysis body, or the analysis body of a leaf without `.pdata` that ends at int3 padding or at the next function. A function whose analysis body and `.pdata` chain differ is held back.
2. No existing entry has the same RVA or an overlapping range.
3. The name has the form `Class::Method` with a capital-first class and the class has an area rule in `tools/unit_paths.py`, so that `./sr start` accepts it (`PLAIN_NAME`, `unit_files` in `tools/contrib.py`). Classes whose name starts with `hk` or `bhk`, free functions and nested names are held back.
4. The name follows this order, per RVA: a name of the pinned MIT NG tree; else a name of the pinned powerof3 tree; else a real meh321 name; else a GUESS placeholder. A name joins either through the image RTTI vftable slot (the virtual slot comment of the class header) or through the Address Library id that the header declares. A name from a newer or different snapshot of any tree is not used and not cited.
5. A meh321 placeholder (`Class::FuncN`, `sub`) is not a name. Such a function gets `Class::Function<rva>` (class only from the placeholder), or `Class::Unk_<slot>` where the image RTTI primary vftable gives the class and the pinned headers name no method for the slot. A class that cannot be fixed (no RTTI vftable and no class in a placeholder, or two unrelated RTTI classes) leaves the function out.

Where one RVA carries several names (shared slot or identical code folding), the entry keeps one name: the first by tree order whose class matches an RTTI vftable class of the function. 0 selected RVAs carried more than one name in the winning tree.

Entries are chosen in this order: functions flagged as priority in the contributor request list first, then by the advisory difficulty bucket of the project model (A before B before C before D), then by size and RVA. This change takes the first 400 of that order for this subsystem; 800 further selected functions remain for later changes.

## Observations

Entries: 400. Name sources: 17 MIT NG, 7 powerof3, 185 meh321, 191 GUESS. GUESS entries by basis: 97 RTTI primary vftable slot with an unnamed header slot (`Class::Unk_<slot>`), 75 RTTI class from a non-primary vftable, 19 class-only meh321 placeholder, 0 event-sink slot.
Extent basis: 191 single `.pdata` entries, 0 chains of contiguous entries, 209 leaves without `.pdata`.
Sizes: 400 entries up to 128 B, 0 entries of 129 to 512 B, 0 entries above 512 B.
Difficulty bucket of the project model (advisory only): A 400.
Startable by the contributor tools: 400 of 400 (every entry has a plain `Class::Method` name and a class area).

Held back or skipped across the 1483 candidate functions of this subsystem:

| reason | functions |
|---|---|
| class-ambiguous (hold) | 6 |
| class-less (hold) | 10 |
| extent-leaf-end (hold) | 2 |
| extent-pdata (hold) | 29 |
| name-shape (hold) | 27 |
| no-area (hold) | 164 |
| already-listed (skip) | 45 |

Largest classes in this change: `BSShaderResourceManager` 26, `NiPSysEmitterCtlr` 6, `BSLightingShaderProperty` 6, `BSShaderAccumulator` 5, `NiPSysData` 4, `NiPSysVolumeEmitter` 4, `BSImagespaceShaderMap` 4, `BSImagespaceShaderNoiseNormalmap` 4, `BSImagespaceShaderNoiseScrollAndBlend` 4, `NiLightDimmerController` 3, `BSPSysHavokUpdateModifier` 3, `NiPSysColorModifier` 3.

## Interpretation and alternatives

An entry is an inventory fact, not a claim about behavior. A COMMUNITY name was written for a different build (1.6.x layouts); the Address Library id may point at another function on 1.7.104, as MAP-1's earlier selection found for two ids. An RTTI-joined name is better evidence than an id-joined name because the vftable slot ties the function to the class, but the community header may still be out of date for this build. A GUESS class that comes from a class-only meh321 placeholder can be wrong. 0 names occur at more than one RVA (template instantiations, overloads and shared slots); the RVA stays the identity.

The contributor tools accept only a name of the form `Class::Method` whose class starts with a capital letter and has an area in `tools/unit_paths.py`. Functions outside that form are held back rather than listed as entries that no tool can start.

## Reproduction and sanitized evidence

Inputs stay in a local private folder: the pinned image (RTTI vftables, `.pdata`), the Address Library database, the three pinned name trees, and the Ghidra function bounds. Join: id to RVA through the database; RVA to name through the id, or through the RTTI vftable slot and the class header of the pinned trees. `python3 tools/mapping_check.py --base <main> --head <head>` checks the file format, duplicates, overlap, labels and the evidence file. No game bytes, disassembly or decompiler output are recorded here or in the entries.

## Negative results and limitations

- Held-back functions are counted above and not listed.
- Names are not verified. Class attribution of the `Class::Function<rva>` placeholders comes from a class-only placeholder and may be wrong.
- No body check was made for any id-joined name. A wrong id would give a wrong name; the RVA and extent remain correct.
- Counts describe this selection only. They are not a completion denominator.

## Reviewer and outcome

Not reviewed. No claim, pull request acceptance or match is made by this note.

## Entries

| RVA | size | name | name source |
|---|---|---|---|
| `0x26164c` | 12 | `TESImageSpaceModifiableForm::~TESImageSpaceModifiableForm` | MIT NG |
| `0x26d000` | 25 | `TESEffectShader::Function26d000` | GUESS |
| `0x26d310` | 52 | `BSParticleShaderGeometry::dtor` | meh321 |
| `0x2a3650` | 23 | `ImageSpaceModifierInstanceForm::Unk_25` | MIT NG |
| `0x2a5560` | 52 | `ImageSpaceModifierInstanceDOF::~ImageSpaceModifierInstanceDOF` | MIT NG |
| `0x2a5670` | 52 | `ImageSpaceModifierInstanceRB::dtor` | meh321 |
| `0x31def0` | 8 | `BGSImpactData::Function31def0` | GUESS |
| `0x321c28` | 9 | `TESModel::~TESModel` | MIT NG |
| `0x32dde4` | 9 | `BSTextureSet::~BSTextureSet` | MIT NG |
| `0xeed1f0` | 15 | `NiLight::Functioneed1f0` | GUESS |
| `0xef3520` | 24 | `NiSourceTexture::Unk_26` | MIT NG |
| `0xefd6e0` | 36 | `BSParticleShaderGeometry::Functionefd6e0` | GUESS |
| `0xf14c40` | 40 | `NiPSysData::Functionf14c40` | GUESS |
| `0xf14c70` | 40 | `NiPSysData::Functionf14c70` | GUESS |
| `0xf14d10` | 40 | `NiPSysData::Functionf14d10` | GUESS |
| `0xf14db0` | 46 | `NiPSysData::Functionf14db0` | GUESS |
| `0xf16610` | 52 | `NiSpotLight::dtor` | meh321 |
| `0xf1e680` | 19 | `NiBackToFrontAccumulator::IsEqual` | po3 |
| `0xf7eda0` | 19 | `NiLightDimmerController::RegisterStreamables` | meh321 |
| `0xf7edd0` | 19 | `NiLightDimmerController::IsEqual` | meh321 |
| `0xf7f090` | 18 | `NiLightDimmerController::Functionf7f090` | GUESS |
| `0xf9a8d0` | 45 | `NiPSysEmitterCtlr::SaveBinary` | meh321 |
| `0xf9aad0` | 19 | `NiPSysEmitterCtlr::Stop` | meh321 |
| `0xf9b770` | 28 | `NiPSysEmitterCtlr::GetInterpolatorID` | meh321 |
| `0xf9b800` | 24 | `NiPSysEmitterCtlr::GetInterpolator` | meh321 |
| `0xf9d960` | 27 | `BSPSysHavokUpdateModifier::LoadBinary` | meh321 |
| `0xf9da40` | 45 | `BSPSysHavokUpdateModifier::SaveBinary` | meh321 |
| `0xf9df50` | 48 | `BSPSysHavokUpdateModifier::PostLinkObject` | meh321 |
| `0xf9f3a0` | 44 | `NiPSysMeshEmitter::Functionf9f3a0` | GUESS |
| `0xf9fa10` | 52 | `NiPSysCylinderEmitter::dtor` | meh321 |
| `0xfa0900` | 52 | `NiPSysEmitter::dtor` | meh321 |
| `0xfa0950` | 44 | `NiPSysEmitterCtlr::Functionfa0950` | GUESS |
| `0xfa0a00` | 43 | `NiPSysModifierCtlr::SaveBinary` | meh321 |
| `0xfa0b10` | 48 | `NiPSysModifierCtlr::SetTarget` | meh321 |
| `0xfa1360` | 51 | `NiPSysModifier::Functionfa1360` | GUESS |
| `0xfa16d0` | 46 | `NiPSysMeshUpdateModifier::LoadBinary` | meh321 |
| `0xfa2b20` | 52 | `NiPSysUpdateCtlr::dtor` | meh321 |
| `0xfa4460` | 10 | `NiPSysAirFieldAirFrictionCtlr::Functionfa4460` | GUESS |
| `0xfa4540` | 52 | `NiPSysAirFieldAirFrictionCtlr::dtor` | meh321 |
| `0xfa4870` | 10 | `NiPSysAirFieldInheritVelocityCtlr::Functionfa4870` | GUESS |
| `0xfa4950` | 52 | `NiPSysAirFieldInheritVelocityCtlr::dtor` | meh321 |
| `0xfa5ed0` | 52 | `NiPSysAirFieldModifier::dtor` | meh321 |
| `0xfa6290` | 13 | `NiPSysAirFieldSpreadCtlr::Functionfa6290` | GUESS |
| `0xfa6390` | 52 | `NiPSysAirFieldSpreadCtlr::dtor` | meh321 |
| `0xfa6570` | 44 | `NiPSysAgeDeathModifier::LinkObject` | meh321 |
| `0xfa6b30` | 52 | `NiPSysAgeDeathModifier::dtor` | meh321 |
| `0xfa6e10` | 44 | `NiPSysBombModifier::LinkObject` | meh321 |
| `0xfa7c30` | 52 | `NiPSysBombModifier::dtor` | meh321 |
| `0xfa8520` | 33 | `NiPSysBoundUpdateModifier::Functionfa8520` | GUESS |
| `0xfa9970` | 52 | `NiPSysBoxEmitter::dtor` | meh321 |
| `0xfaa2d0` | 27 | `NiPSysColorModifier::LoadBinary` | meh321 |
| `0xfaa300` | 50 | `NiPSysColorModifier::LinkObject` | meh321 |
| `0xfaa390` | 45 | `NiPSysColorModifier::SaveBinary` | meh321 |
| `0xfac660` | 52 | `NiPSysDragFieldModifier::dtor` | meh321 |
| `0xfac8d0` | 44 | `NiPSysDragModifier::LinkObject` | meh321 |
| `0xfad2e0` | 52 | `NiPSysDragModifier::dtor` | meh321 |
| `0xfadec0` | 10 | `NiPSysEmitterDeclinationCtlr::Functionfadec0` | GUESS |
| `0xfaded0` | 10 | `NiPSysEmitterDeclinationCtlr::Functionfaded0` | GUESS |
| `0xfadf90` | 52 | `NiPSysEmitterDeclinationCtlr::dtor` | meh321 |
| `0xfae2c0` | 10 | `NiPSysEmitterDeclinationVarCtlr::Functionfae2c0` | GUESS |
| `0xfae2d0` | 10 | `NiPSysEmitterDeclinationVarCtlr::Functionfae2d0` | GUESS |
| `0xfae390` | 52 | `NiPSysEmitterDeclinationVarCtlr::dtor` | meh321 |
| `0xfae6c0` | 10 | `NiPSysEmitterInitialRadiusCtlr::Functionfae6c0` | GUESS |
| `0xfae6d0` | 10 | `NiPSysEmitterInitialRadiusCtlr::Functionfae6d0` | GUESS |
| `0xfae790` | 52 | `NiPSysEmitterInitialRadiusCtlr::dtor` | meh321 |
| `0xfaeac0` | 10 | `NiPSysEmitterLifeSpanCtlr::Functionfaeac0` | GUESS |
| `0xfaead0` | 10 | `NiPSysEmitterLifeSpanCtlr::Functionfaead0` | GUESS |
| `0xfaeb90` | 52 | `NiPSysEmitterLifeSpanCtlr::dtor` | meh321 |
| `0xfaeec0` | 10 | `NiPSysEmitterPlanarAngleCtlr::Functionfaeec0` | GUESS |
| `0xfaeed0` | 10 | `NiPSysEmitterPlanarAngleCtlr::Functionfaeed0` | GUESS |
| `0xfaef90` | 52 | `NiPSysEmitterPlanarAngleCtlr::dtor` | meh321 |
| `0xfaf2c0` | 10 | `NiPSysEmitterPlanarAngleVarCtlr::Functionfaf2c0` | GUESS |
| `0xfaf2d0` | 10 | `NiPSysEmitterPlanarAngleVarCtlr::Functionfaf2d0` | GUESS |
| `0xfaf390` | 52 | `NiPSysEmitterPlanarAngleVarCtlr::dtor` | meh321 |
| `0xfaf6c0` | 10 | `NiPSysEmitterSpeedCtlr::Functionfaf6c0` | GUESS |
| `0xfaf6d0` | 10 | `NiPSysEmitterSpeedCtlr::Functionfaf6d0` | GUESS |
| `0xfaf790` | 52 | `NiPSysEmitterSpeedCtlr::dtor` | meh321 |
| `0xfafac0` | 10 | `NiPSysFieldAttenuationCtlr::Functionfafac0` | GUESS |
| `0xfafad0` | 10 | `NiPSysFieldAttenuationCtlr::Functionfafad0` | GUESS |
| `0xfafb90` | 52 | `NiPSysFieldAttenuationCtlr::dtor` | meh321 |
| `0xfafec0` | 10 | `NiPSysFieldMagnitudeCtlr::Functionfafec0` | GUESS |
| `0xfafed0` | 10 | `NiPSysFieldMagnitudeCtlr::Functionfafed0` | GUESS |
| `0xfaff90` | 52 | `NiPSysFieldMagnitudeCtlr::dtor` | meh321 |
| `0xfb02c0` | 10 | `NiPSysFieldMaxDistanceCtlr::Functionfb02c0` | GUESS |
| `0xfb02d0` | 19 | `NiPSysFieldMaxDistanceCtlr::Functionfb02d0` | GUESS |
| `0xfb03a0` | 52 | `NiPSysFieldMaxDistanceCtlr::dtor` | meh321 |
| `0xfb0570` | 43 | `NiPSysGravityFieldModifier::SaveBinary` | meh321 |
| `0xfb0f30` | 52 | `NiPSysGravityFieldModifier::dtor` | meh321 |
| `0xfb1300` | 10 | `NiPSysGravityStrengthCtlr::Functionfb1300` | GUESS |
| `0xfb1310` | 10 | `NiPSysGravityStrengthCtlr::Functionfb1310` | GUESS |
| `0xfb13d0` | 52 | `NiPSysGravityStrengthCtlr::dtor` | meh321 |
| `0xfb1b90` | 52 | `NiPSysGrowFadeModifier::dtor` | meh321 |
| `0xfb1ec0` | 10 | `NiPSysInitialRotAngleCtlr::Functionfb1ec0` | GUESS |
| `0xfb1ed0` | 10 | `NiPSysInitialRotAngleCtlr::Functionfb1ed0` | GUESS |
| `0xfb1f90` | 52 | `NiPSysInitialRotAngleCtlr::dtor` | meh321 |
| `0xfb22c0` | 10 | `NiPSysInitialRotAngleVarCtlr::Functionfb22c0` | GUESS |
| `0xfb22d0` | 10 | `NiPSysInitialRotAngleVarCtlr::Functionfb22d0` | GUESS |
| `0xfb2390` | 52 | `NiPSysInitialRotAngleVarCtlr::dtor` | meh321 |
| `0xfb26c0` | 10 | `NiPSysInitialRotSpeedCtlr::Functionfb26c0` | GUESS |
| `0xfb26d0` | 10 | `NiPSysInitialRotSpeedCtlr::Functionfb26d0` | GUESS |
| `0xfb2790` | 52 | `NiPSysInitialRotSpeedCtlr::dtor` | meh321 |
| `0xfb2ac0` | 10 | `NiPSysInitialRotSpeedVarCtlr::Functionfb2ac0` | GUESS |
| `0xfb2ad0` | 10 | `NiPSysInitialRotSpeedVarCtlr::Functionfb2ad0` | GUESS |
| `0xfb2b90` | 52 | `NiPSysInitialRotSpeedVarCtlr::dtor` | meh321 |
| `0xfb57b0` | 11 | `NiPSysModifierActiveCtlr::Functionfb57b0` | GUESS |
| `0xfb57d0` | 20 | `NiPSysModifierActiveCtlr::Functionfb57d0` | GUESS |
| `0xfb58a0` | 52 | `NiPSysModifierActiveCtlr::dtor` | meh321 |
| `0xfb7660` | 52 | `NiPSysPositionModifier::dtor` | meh321 |
| `0xfb7880` | 19 | `NiPSysRadialFieldModifier::IsEqual` | meh321 |
| `0xfb8180` | 52 | `NiPSysRadialFieldModifier::dtor` | meh321 |
| `0xfb85c0` | 52 | `NiPSysResetOnLoopCtlr::dtor` | meh321 |
| `0xfb9080` | 52 | `NiPSysRotationModifier::dtor` | meh321 |
| `0xfb99b0` | 52 | `NiPSysSpawnModifier::dtor` | meh321 |
| `0xfb9ae0` | 38 | `NiPSysMeshEmitter::Functionfb9ae0` | GUESS |
| `0xfba0f0` | 52 | `NiPSysSphereEmitter::dtor` | meh321 |
| `0xfbbeb0` | 52 | `NiPSysTurbulenceFieldModifier::dtor` | meh321 |
| `0xfbc050` | 43 | `NiPSysVortexFieldModifier::LoadBinary` | meh321 |
| `0xfbc0b0` | 43 | `NiPSysVortexFieldModifier::SaveBinary` | meh321 |
| `0xfbcfc0` | 52 | `NiPSysVortexFieldModifier::dtor` | meh321 |
| `0xfbfc30` | 44 | `BSPSysInheritVelocityModifier::LinkObject` | meh321 |
| `0xfc0310` | 27 | `NiPSysVolumeEmitter::LoadBinary` | meh321 |
| `0xfc0340` | 44 | `NiPSysVolumeEmitter::LinkObject` | meh321 |
| `0xfc0390` | 45 | `NiPSysVolumeEmitter::SaveBinary` | meh321 |
| `0xfc08d0` | 52 | `NiPSysVolumeEmitter::dtor` | meh321 |
| `0xfc0930` | 45 | `NiPSysModifierFloatCtlr::LoadBinary` | meh321 |
| `0xfc0d60` | 13 | `NiPSysModifierFloatCtlr::InterpolatorIsCorrectType` | meh321 |
| `0xfc0d70` | 52 | `NiPSysModifierFloatCtlr::dtor` | meh321 |
| `0xfc0f20` | 44 | `NiPSysFieldModifier::LinkObject` | meh321 |
| `0xfc12e0` | 52 | `NiPSysFieldModifier::dtor` | meh321 |
| `0xfc1650` | 45 | `NiPSysModifierBoolCtlr::LoadBinary` | meh321 |
| `0xfc1a80` | 13 | `NiPSysModifierBoolCtlr::InterpolatorIsCorrectType` | meh321 |
| `0xfc1a90` | 52 | `NiPSysModifierBoolCtlr::dtor` | meh321 |
| `0xfe0f00` | 9 | `BSPSysArrayEmitter::Functionfe0f00` | GUESS |
| `0xfe13f0` | 11 | `BSPSysArrayEmitter::Functionfe13f0` | GUESS |
| `0xfe1410` | 42 | `BSPSysArrayEmitter::PostLinkObject` | meh321 |
| `0xfe5140` | 50 | `BSMultiBoundShape::~BSMultiBoundShape` | MIT NG |
| `0xff4f40` | 46 | `NiPSysEmitterCtlr::Functionff4f40` | GUESS |
| `0xff5020` | 19 | `BSPSysMultiTargetEmitterCtlr::RegisterStreamables` | meh321 |
| `0x1003710` | 52 | `BSPSysSubTexModifier::dtor` | meh321 |
| `0x1003990` | 43 | `BSPSysScaleModifier::SaveBinary` | meh321 |
| `0x14e7ec0` | 28 | `BSShaderProperty::CanMerge` | MIT NG |
| `0x14e8350` | 39 | `BSLightingShaderProperty::Function14e8350` | GUESS |
| `0x1507cc0` | 52 | `BSImagespaceShaderAlphaBlend::dtor` | meh321 |
| `0x1507d00` | 52 | `BSImagespaceShaderApplyReflections::dtor` | meh321 |
| `0x1507d40` | 52 | `BSImagespaceShaderBlur11::dtor` | meh321 |
| `0x1507d80` | 52 | `BSImagespaceShaderBlur13::dtor` | meh321 |
| `0x1507dc0` | 52 | `BSImagespaceShaderBlur15::dtor` | meh321 |
| `0x1507e40` | 52 | `BSImagespaceShaderBlur5::dtor` | meh321 |
| `0x1507e80` | 52 | `BSImagespaceShaderBlur7::dtor` | meh321 |
| `0x1507ec0` | 52 | `BSImagespaceShaderBlur9::dtor` | meh321 |
| `0x1507f00` | 52 | `BSImagespaceShaderBrightPassBlur11::dtor` | meh321 |
| `0x1507f40` | 52 | `BSImagespaceShaderBrightPassBlur13::dtor` | meh321 |
| `0x1507f80` | 52 | `BSImagespaceShaderBrightPassBlur15::dtor` | meh321 |
| `0x1507fc0` | 52 | `BSImagespaceShaderBrightPassBlur3::dtor` | meh321 |
| `0x1508000` | 52 | `BSImagespaceShaderBrightPassBlur5::dtor` | meh321 |
| `0x1508040` | 52 | `BSImagespaceShaderBrightPassBlur7::dtor` | meh321 |
| `0x1508080` | 52 | `BSImagespaceShaderBrightPassBlur9::dtor` | meh321 |
| `0x15080c0` | 52 | `BSImagespaceShaderCopy::dtor` | meh321 |
| `0x1508100` | 52 | `BSImagespaceShaderCopyCustomViewport::dtor` | meh321 |
| `0x1508140` | 52 | `BSImagespaceShaderCopyDynamicFetchDisabled::dtor` | meh321 |
| `0x1508180` | 52 | `BSImagespaceShaderCopyScaleBias::dtor` | meh321 |
| `0x15081c0` | 52 | `BSImagespaceShaderDepthOfField::dtor` | meh321 |
| `0x1508200` | 52 | `BSImagespaceShaderDepthOfFieldFogged::dtor` | meh321 |
| `0x1508240` | 52 | `BSImagespaceShaderDepthOfFieldMaskedFogged::dtor` | meh321 |
| `0x1508280` | 52 | `BSImagespaceShaderDistantBlur::dtor` | meh321 |
| `0x15082c0` | 52 | `BSImagespaceShaderDistantBlurFogged::dtor` | meh321 |
| `0x1508300` | 52 | `BSImagespaceShaderDistantBlurMaskedFogged::dtor` | meh321 |
| `0x1508340` | 52 | `BSImagespaceShaderDoubleVision::dtor` | meh321 |
| `0x15083d0` | 52 | `BSImagespaceShaderGreyScale::dtor` | meh321 |
| `0x1508410` | 52 | `BSImagespaceShaderHDRDownSample16::dtor` | meh321 |
| `0x1508450` | 52 | `BSImagespaceShaderHDRDownSample16LightAdapt::dtor` | meh321 |
| `0x1508490` | 52 | `BSImagespaceShaderHDRDownSample16Lum::dtor` | meh321 |
| `0x15084d0` | 52 | `BSImagespaceShaderHDRDownSample16LumClamp::dtor` | meh321 |
| `0x1508510` | 52 | `BSImagespaceShaderHDRDownSample4::dtor` | meh321 |
| `0x1508550` | 52 | `BSImagespaceShaderHDRDownSample4LightAdapt::dtor` | meh321 |
| `0x1508590` | 52 | `BSImagespaceShaderHDRDownSample4LumClamp::dtor` | meh321 |
| `0x15085d0` | 52 | `BSImagespaceShaderHDRDownSample4RGB2Lum::dtor` | meh321 |
| `0x1508610` | 52 | `BSImagespaceShaderHDRTonemapBlendCinematic::dtor` | meh321 |
| `0x1508650` | 52 | `BSImagespaceShaderHDRTonemapBlendCinematicFade::dtor` | meh321 |
| `0x1508690` | 52 | `BSImagespaceShaderISApplyVolumetricLighting::dtor` | meh321 |
| `0x15086d0` | 52 | `BSImagespaceShaderISBasicCopy::dtor` | meh321 |
| `0x1508710` | 52 | `BSImagespaceShaderISBlur::dtor` | meh321 |
| `0x1508750` | 52 | `BSImagespaceShaderISCompositeLensFlare::dtor` | meh321 |
| `0x1508790` | 52 | `BSImagespaceShaderISCompositeLensFlareVolumetricLighting::dtor` | meh321 |
| `0x15087d0` | 52 | `BSImagespaceShaderISCompositeVolumetricLighting::dtor` | meh321 |
| `0x1508810` | 52 | `BSImagespaceShaderISCopySubRegionCS::dtor` | meh321 |
| `0x1508850` | 52 | `BSImagespaceShaderISDebugSnow::dtor` | meh321 |
| `0x1508890` | 52 | `BSImagespaceShaderISDepthOfFieldBlurHCS::dtor` | meh321 |
| `0x15088d0` | 52 | `BSImagespaceShaderISDepthOfFieldBlurVCS::dtor` | meh321 |
| `0x1508910` | 52 | `BSImagespaceShaderISDisplayDepth::dtor` | meh321 |
| `0x1508950` | 52 | `BSImagespaceShaderISDownsample::dtor` | meh321 |
| `0x1508990` | 52 | `BSImagespaceShaderISDownsampleCS::dtor` | meh321 |
| `0x15089d0` | 52 | `BSImagespaceShaderISDownsampleIgnoreBrightest::dtor` | meh321 |
| `0x1508a10` | 52 | `BSImagespaceShaderISDownsampleIgnoreBrightestCS::dtor` | meh321 |
| `0x1508a50` | 52 | `BSImagespaceShaderISExp::dtor` | meh321 |
| `0x1508a90` | 52 | `BSImagespaceShaderISIBLensFlares::dtor` | meh321 |
| `0x1508ad0` | 52 | `BSImagespaceShaderISLightingComposite::dtor` | meh321 |
| `0x1508b10` | 52 | `BSImagespaceShaderISLightingCompositeMenu::dtor` | meh321 |
| `0x1508b50` | 52 | `BSImagespaceShaderISLightingCompositeNoDirectionalLight::dtor` | meh321 |
| `0x1508b90` | 52 | `BSImagespaceShaderISMinify::dtor` | meh321 |
| `0x1508bd0` | 52 | `BSImagespaceShaderISMinifyContrast::dtor` | meh321 |
| `0x1508c10` | 52 | `BSImagespaceShaderISParallaxMaskBlurHCS::dtor` | meh321 |
| `0x1508c50` | 52 | `BSImagespaceShaderISParallaxMaskBlurVCS::dtor` | meh321 |
| `0x1508c90` | 52 | `BSImagespaceShaderISPerlinNoise2DCS::dtor` | meh321 |
| `0x1508cd0` | 52 | `BSImagespaceShaderISPerlinNoiseCS::dtor` | meh321 |
| `0x1508d10` | 52 | `BSImagespaceShaderISSAOBlurH::dtor` | meh321 |
| `0x1508d50` | 52 | `BSImagespaceShaderISSAOBlurHCS::dtor` | meh321 |
| `0x1508d90` | 52 | `BSImagespaceShaderISSAOBlurV::dtor` | meh321 |
| `0x1508dd0` | 52 | `BSImagespaceShaderISSAOBlurVCS::dtor` | meh321 |
| `0x1508e10` | 52 | `BSImagespaceShaderISSAOCameraZ::dtor` | meh321 |
| `0x1508e50` | 52 | `BSImagespaceShaderISSAOCameraZAndMipsCS::dtor` | meh321 |
| `0x1508e90` | 52 | `BSImagespaceShaderISSAOCompositeFog::dtor` | meh321 |
| `0x1508ed0` | 52 | `BSImagespaceShaderISSAOCompositeSAO::dtor` | meh321 |
| `0x1508f10` | 52 | `BSImagespaceShaderISSAOCompositeSAOFog::dtor` | meh321 |
| `0x1508f50` | 52 | `BSImagespaceShaderISSAORawAO::dtor` | meh321 |
| `0x1508f90` | 52 | `BSImagespaceShaderISSAORawAOCS::dtor` | meh321 |
| `0x1508fd0` | 52 | `BSImagespaceShaderISSAORawAONoTemporal::dtor` | meh321 |
| `0x1509010` | 52 | `BSImagespaceShaderISSILComposite::dtor` | meh321 |
| `0x1509050` | 52 | `BSImagespaceShaderISSILRawInd::dtor` | meh321 |
| `0x1509090` | 52 | `BSImagespaceShaderISSimpleColor::dtor` | meh321 |
| `0x15090d0` | 52 | `BSImagespaceShaderISSnowSSS::dtor` | meh321 |
| `0x1509110` | 52 | `BSImagespaceShaderISTemporalAA::~BSImagespaceShaderISTemporalAA` | po3 |
| `0x1509150` | 52 | `BSImagespaceShaderISTemporalAA_UI::dtor` | meh321 |
| `0x1509190` | 52 | `BSImagespaceShaderISTemporalAA_Water::dtor` | meh321 |
| `0x15091d0` | 52 | `BSImagespaceShaderISUnderwaterMask::dtor` | meh321 |
| `0x1509210` | 52 | `BSImagespaceShaderISUpsampleDynamicResolution::dtor` | meh321 |
| `0x1509250` | 52 | `BSImagespaceShaderISVolumetricLightingBlurHCS::dtor` | meh321 |
| `0x1509290` | 52 | `BSImagespaceShaderISVolumetricLightingBlurVCS::dtor` | meh321 |
| `0x15092d0` | 52 | `BSImagespaceShaderISWaterBlend::dtor` | meh321 |
| `0x1509310` | 52 | `BSImagespaceShaderLocalMap::dtor` | meh321 |
| `0x1509350` | 52 | `BSImagespaceShaderMap::dtor` | meh321 |
| `0x1509390` | 52 | `BSImagespaceShaderNoiseNormalmap::dtor` | meh321 |
| `0x15093d0` | 52 | `BSImagespaceShaderNoiseScrollAndBlend::dtor` | meh321 |
| `0x1509410` | 52 | `BSImagespaceShaderNonHDRBlur11::dtor` | meh321 |
| `0x1509450` | 52 | `BSImagespaceShaderNonHDRBlur13::dtor` | meh321 |
| `0x1509490` | 52 | `BSImagespaceShaderNonHDRBlur15::dtor` | meh321 |
| `0x15094d0` | 52 | `BSImagespaceShaderNonHDRBlur3::dtor` | meh321 |
| `0x1509510` | 52 | `BSImagespaceShaderNonHDRBlur5::dtor` | meh321 |
| `0x1509550` | 52 | `BSImagespaceShaderNonHDRBlur7::dtor` | meh321 |
| `0x1509590` | 52 | `BSImagespaceShaderNonHDRBlur9::dtor` | meh321 |
| `0x15095d0` | 52 | `BSImagespaceShaderRadialBlur::dtor` | meh321 |
| `0x1509610` | 52 | `BSImagespaceShaderRadialBlurHigh::dtor` | meh321 |
| `0x1509650` | 52 | `BSImagespaceShaderRadialBlurMedium::dtor` | meh321 |
| `0x1509bd0` | 13 | `BSImagespaceShaderAlphaBlend::Unk_0D` | GUESS |
| `0x1509be0` | 13 | `BSImagespaceShaderApplyReflections::Unk_0D` | GUESS |
| `0x1509fe0` | 13 | `BSImagespaceShaderCopy::Unk_0D` | GUESS |
| `0x1509ff0` | 13 | `BSImagespaceShaderCopyCustomViewport::Unk_0D` | GUESS |
| `0x150a000` | 35 | `BSImagespaceShaderCopyDynamicFetchDisabled::Unk_0D` | GUESS |
| `0x150a030` | 35 | `BSImagespaceShaderCopyScaleBias::Unk_0D` | GUESS |
| `0x150a060` | 13 | `BSImagespaceShaderDepthOfField::Unk_0D` | GUESS |
| `0x150a070` | 35 | `BSImagespaceShaderDepthOfFieldFogged::Unk_0D` | GUESS |
| `0x150a0a0` | 50 | `BSImagespaceShaderDepthOfFieldMaskedFogged::Unk_0D` | GUESS |
| `0x150a0e0` | 35 | `BSImagespaceShaderDistantBlur::Unk_0D` | GUESS |
| `0x150a110` | 50 | `BSImagespaceShaderDistantBlurFogged::Unk_0D` | GUESS |
| `0x150a1a0` | 13 | `BSImagespaceShaderDoubleVision::Unk_0D` | GUESS |
| `0x150a1b0` | 13 | `BSImagespaceShaderFXAA::Unk_0D` | GUESS |
| `0x150a1c0` | 35 | `BSImagespaceShaderGreyScale::Unk_0D` | GUESS |
| `0x150a1f0` | 35 | `BSImagespaceShaderHDRDownSample16::Unk_0D` | GUESS |
| `0x150a300` | 35 | `BSImagespaceShaderHDRDownSample4::Unk_0D` | GUESS |
| `0x150a400` | 35 | `BSImagespaceShaderHDRTonemapBlendCinematic::Unk_0D` | GUESS |
| `0x150a470` | 13 | `BSImagespaceShaderISApplyVolumetricLighting::Unk_0D` | GUESS |
| `0x150a480` | 13 | `BSImagespaceShaderISBasicCopy::Unk_0D` | GUESS |
| `0x150a490` | 13 | `BSImagespaceShaderISBlur::Unk_0D` | GUESS |
| `0x150a4a0` | 35 | `BSImagespaceShaderISCompositeLensFlare::Unk_0D` | GUESS |
| `0x150a4d0` | 50 | `BSImagespaceShaderISCompositeLensFlareVolumetricLighting::Unk_0D` | GUESS |
| `0x150a510` | 35 | `BSImagespaceShaderISCompositeVolumetricLighting::Unk_0D` | GUESS |
| `0x150a540` | 13 | `BSImagespaceShaderISCopySubRegionCS::Unk_0D` | GUESS |
| `0x150a550` | 13 | `BSImagespaceShaderISDebugSnow::Unk_0D` | GUESS |
| `0x150a680` | 35 | `BSImagespaceShaderISDisplayDepth::Unk_0D` | GUESS |
| `0x150a6b0` | 50 | `BSImagespaceShaderISDownsample::Unk_0D` | GUESS |
| `0x150a730` | 35 | `BSImagespaceShaderISDownsampleIgnoreBrightest::Unk_0D` | GUESS |
| `0x150a760` | 35 | `BSImagespaceShaderISDownsampleIgnoreBrightestCS::Unk_0D` | GUESS |
| `0x150a790` | 13 | `BSImagespaceShaderISExp::Unk_0D` | GUESS |
| `0x150a7a0` | 13 | `BSImagespaceShaderISIBLensFlares::Unk_0D` | GUESS |
| `0x150a7b0` | 35 | `BSImagespaceShaderISLightingComposite::Unk_0D` | GUESS |
| `0x150a7e0` | 50 | `BSImagespaceShaderISLightingCompositeMenu::Unk_0D` | GUESS |
| `0x150a820` | 13 | `BSImagespaceShaderISLightingCompositeNoDirectionalLight::Unk_0D` | GUESS |
| `0x150a830` | 13 | `BSImagespaceShaderISMinify::Unk_0D` | GUESS |
| `0x150a840` | 35 | `BSImagespaceShaderISMinifyContrast::Unk_0D` | GUESS |
| `0x150a990` | 35 | `BSImagespaceShaderISPerlinNoise2DCS::Unk_0D` | GUESS |
| `0x150a9c0` | 13 | `BSImagespaceShaderISPerlinNoiseCS::Unk_0D` | GUESS |
| `0x150a9d0` | 35 | `BSImagespaceShaderISSAOBlurH::Unk_0D` | GUESS |
| `0x150aa00` | 35 | `BSImagespaceShaderISSAOBlurHCS::Unk_0D` | GUESS |
| `0x150aa30` | 35 | `BSImagespaceShaderISSAOBlurV::Unk_0D` | GUESS |
| `0x150aaa0` | 13 | `BSImagespaceShaderISSAOCameraZ::Unk_0D` | GUESS |
| `0x150aab0` | 13 | `BSImagespaceShaderISSAOCameraZAndMipsCS::Unk_0D` | GUESS |
| `0x150aac0` | 35 | `BSImagespaceShaderISSAOCompositeFog::Unk_0D` | GUESS |
| `0x150aaf0` | 35 | `BSImagespaceShaderISSAOCompositeSAO::Unk_0D` | GUESS |
| `0x150ab20` | 50 | `BSImagespaceShaderISSAOCompositeSAOFog::Unk_0D` | GUESS |
| `0x150ab60` | 35 | `BSImagespaceShaderISSAORawAO::Unk_0D` | GUESS |
| `0x150ab90` | 13 | `BSImagespaceShaderISSAORawAOCS::Unk_0D` | GUESS |
| `0x150aba0` | 50 | `BSImagespaceShaderISSAORawAONoTemporal::Unk_0D` | GUESS |
| `0x150abe0` | 13 | `BSImagespaceShaderISSILComposite::Unk_0D` | GUESS |
| `0x150abf0` | 13 | `BSImagespaceShaderISSILRawInd::Unk_0D` | GUESS |
| `0x150ac00` | 13 | `BSImagespaceShaderISSimpleColor::Unk_0D` | GUESS |
| `0x150ac10` | 13 | `BSImagespaceShaderISSnowSSS::Unk_0D` | GUESS |
| `0x150ac20` | 13 | `BSImagespaceShader::GetShaderMacros` | po3 |
| `0x150ac30` | 35 | `BSImagespaceShaderISTemporalAA_UI::Unk_0D` | GUESS |
| `0x150ac60` | 35 | `BSImagespaceShaderISTemporalAA_Water::Unk_0D` | GUESS |
| `0x150ac90` | 35 | `BSImagespaceShaderISUnderwaterMask::Unk_0D` | GUESS |
| `0x150acc0` | 13 | `BSImagespaceShaderISUpsampleDynamicResolution::Unk_0D` | GUESS |
| `0x150ae30` | 13 | `BSImagespaceShaderISWaterBlend::Unk_0D` | GUESS |
| `0x150ae40` | 13 | `BSImagespaceShaderLocalMap::Unk_0D` | GUESS |
| `0x150ae50` | 13 | `BSImagespaceShaderMap::Unk_0D` | GUESS |
| `0x150ae60` | 35 | `BSImagespaceShaderNoiseNormalmap::Unk_0D` | GUESS |
| `0x150ae90` | 35 | `BSImagespaceShaderNoiseScrollAndBlend::Unk_0D` | GUESS |
| `0x150aec0` | 35 | `BSImagespaceShaderNonHDRBlur11::Unk_0D` | GUESS |
| `0x150aef0` | 35 | `BSImagespaceShaderNonHDRBlur13::Unk_0D` | GUESS |
| `0x150af20` | 35 | `BSImagespaceShaderNonHDRBlur15::Unk_0D` | GUESS |
| `0x150af50` | 35 | `BSImagespaceShaderNonHDRBlur3::Unk_0D` | GUESS |
| `0x150af80` | 35 | `BSImagespaceShaderNonHDRBlur5::Unk_0D` | GUESS |
| `0x150afb0` | 35 | `BSImagespaceShaderNonHDRBlur7::Unk_0D` | GUESS |
| `0x150afe0` | 35 | `BSImagespaceShaderNonHDRBlur9::Unk_0D` | GUESS |
| `0x150b010` | 35 | `BSImagespaceShaderRadialBlur::Unk_0D` | GUESS |
| `0x150b040` | 35 | `BSImagespaceShaderRadialBlurHigh::Unk_0D` | GUESS |
| `0x150b070` | 35 | `BSImagespaceShaderRadialBlurMedium::Unk_0D` | GUESS |
| `0x150b1a0` | 35 | `BSImagespaceShaderReflectionsDebugSpecMask::Unk_0D` | GUESS |
| `0x150b1d0` | 13 | `BSImagespaceShaderReflectionsRayTracing::Unk_0D` | GUESS |
| `0x150b1e0` | 13 | `BSImagespaceShaderRefraction::Unk_0D` | GUESS |
| `0x150b1f0` | 35 | `BSImagespaceShaderTextureMask::Unk_0D` | GUESS |
| `0x150b220` | 13 | `BSImagespaceShaderVolumetricLighting::Unk_0D` | GUESS |
| `0x150b230` | 35 | `BSImagespaceShaderWaterBlendHeightmaps::Unk_0D` | GUESS |
| `0x150b260` | 35 | `BSImagespaceShaderWaterDisplacementClearSimulation::Unk_0D` | GUESS |
| `0x150b290` | 35 | `BSImagespaceShaderWaterDisplacementNormals::Unk_0D` | GUESS |
| `0x150b2c0` | 35 | `BSImagespaceShaderWaterDisplacementRainRipple::Unk_0D` | GUESS |
| `0x150b2f0` | 35 | `BSImagespaceShaderWaterDisplacementTexOffset::Unk_0D` | GUESS |
| `0x150b320` | 35 | `BSImagespaceShaderWaterDisplacementWadingRipple::Unk_0D` | GUESS |
| `0x150b350` | 35 | `BSImagespaceShaderWaterFlow::Unk_0D` | GUESS |
| `0x150b380` | 35 | `BSImagespaceShaderWaterRainHeightmap::Unk_0D` | GUESS |
| `0x150b3b0` | 35 | `BSImagespaceShaderWaterSmoothHeightmap::Unk_0D` | GUESS |
| `0x150b3e0` | 35 | `BSImagespaceShaderWaterWadingHeightmap::Unk_0D` | GUESS |
| `0x150b410` | 35 | `BSImagespaceShaderWorldMap::Unk_0D` | GUESS |
| `0x150b440` | 50 | `BSImagespaceShaderWorldMapNoSkyBlur::Unk_0D` | GUESS |
| `0x150b480` | 5 | `ImageSpaceEffect::IsActive` | MIT NG |
| `0x150b4b0` | 30 | `BSImagespaceShaderMap::Unk_0B` | GUESS |
| `0x150b4d0` | 30 | `BSImagespaceShaderNoiseNormalmap::Unk_0B` | GUESS |
| `0x150b4f0` | 30 | `BSImagespaceShaderNoiseScrollAndBlend::Unk_0B` | GUESS |
| `0x150b530` | 21 | `BSImagespaceShaderCopyScaleBias::Unk_0A` | GUESS |
| `0x150b550` | 30 | `BSImagespaceShaderMap::Unk_0A` | GUESS |
| `0x150b570` | 30 | `BSImagespaceShaderNoiseNormalmap::Unk_0A` | GUESS |
| `0x150b590` | 30 | `BSImagespaceShaderNoiseScrollAndBlend::Unk_0A` | GUESS |
| `0x1519980` | 30 | `BSLightingShaderProperty::Function1519980` | GUESS |
| `0x151ca80` | 24 | `BSLightingShaderProperty::AcceptsEffectData` | MIT NG |
| `0x151d520` | 9 | `BSLightingShaderProperty::GetBaseTexture` | MIT NG |
| `0x151d550` | 13 | `BSLightingShaderProperty::QMaterialAlpha` | MIT NG |
| `0x151d560` | 13 | `BSLightingShaderProperty::SetMaterialAlpha` | MIT NG |
| `0x151db90` | 10 | `BSGrassShaderProperty::GetRenderPasses_ShadowMapOrMask` | po3 |
| `0x151de70` | 7 | `BSGrassShaderProperty::Function151de70` | GUESS |
| `0x151de80` | 7 | `BSGrassShaderProperty::Function151de80` | GUESS |
| `0x151e3f0` | 49 | `BSShaderAccumulator::FinishAccumulating` | po3 |
| `0x15209f0` | 19 | `BSShaderAccumulator::Function15209f0` | GUESS |
| `0x1520c90` | 20 | `BSShaderAccumulator::Function1520c90` | GUESS |
| `0x1520d70` | 12 | `BSShaderAccumulator::StopGroupingAlphas` | po3 |
| `0x1521150` | 14 | `BSShaderAccumulator::Function1521150` | GUESS |
| `0x152ada0` | 9 | `BSEffectShaderProperty::GetBaseTexture` | MIT NG |
| `0x152ade0` | 10 | `BSEffectShaderProperty::QMaterialAlpha` | MIT NG |
| `0x152adf0` | 17 | `BSEffectShaderProperty::SetMaterialAlpha` | MIT NG |
| `0x1530870` | 35 | `BSImagespaceShaderLensFlareVisibility::Unk_0D` | GUESS |
| `0x1535980` | 19 | `BSParticleShaderGeometryEmitter::Function1535980` | GUESS |
| `0x1535f80` | 8 | `BSParticleShaderCollisionEmitter::Function1535f80` | GUESS |
| `0x1535f90` | 14 | `BSParticleShaderCollisionEmitter::Function1535f90` | GUESS |
| `0x1536280` | 13 | `BSParticleShaderRayEmitter::Function1536280` | GUESS |
| `0x154af70` | 7 | `BSLightingShader::Function154af70` | GUESS |
| `0x1565300` | 12 | `ImageSpaceEffect::~ImageSpaceEffect` | MIT NG |
| `0x157af20` | 29 | `BSLightingShaderPropertyFloatController::Function157af20` | GUESS |
| `0x157b070` | 15 | `BSLightingShaderPropertyFloatController::GetCtlrID` | meh321 |
| `0x157b590` | 15 | `BSLightingShaderPropertyUShortController::GetCtlrID` | meh321 |
| `0x157ba30` | 42 | `BSLightingShaderPropertyColorController::Function157ba30` | GUESS |
| `0x157bb80` | 15 | `BSLightingShaderPropertyColorController::GetCtlrID` | meh321 |
| `0x157c0f0` | 29 | `BSEffectShaderPropertyFloatController::Function157c0f0` | GUESS |
| `0x157c240` | 15 | `BSEffectShaderPropertyFloatController::GetCtlrID` | meh321 |
| `0x157c700` | 38 | `BSEffectShaderPropertyColorController::Function157c700` | GUESS |
| `0x157c850` | 15 | `BSEffectShaderPropertyColorController::GetCtlrID` | meh321 |
| `0x1582070` | 12 | `BSShaderResourceManager::Function1582070` | GUESS |
| `0x1582100` | 12 | `BSShaderResourceManager::Function1582100` | GUESS |
| `0x1582120` | 12 | `BSShaderResourceManager::Function1582120` | GUESS |
| `0x1582140` | 12 | `BSShaderResourceManager::Function1582140` | GUESS |
| `0x1582160` | 12 | `BSShaderResourceManager::Function1582160` | GUESS |
| `0x1582180` | 12 | `BSShaderResourceManager::Function1582180` | GUESS |
| `0x15821a0` | 12 | `BSShaderResourceManager::Function15821a0` | GUESS |
| `0x1582250` | 12 | `BSShaderResourceManager::Function1582250` | GUESS |
| `0x1582270` | 12 | `BSShaderResourceManager::Function1582270` | GUESS |
| `0x1582290` | 12 | `BSShaderResourceManager::Function1582290` | GUESS |
| `0x1582550` | 12 | `BSShaderResourceManager::Function1582550` | GUESS |
| `0x1582600` | 12 | `BSShaderResourceManager::Function1582600` | GUESS |
| `0x1582620` | 12 | `BSShaderResourceManager::Function1582620` | GUESS |
| `0x1582640` | 12 | `BSShaderResourceManager::Function1582640` | GUESS |
| `0x1582660` | 12 | `BSShaderResourceManager::Function1582660` | GUESS |
| `0x15826f0` | 12 | `BSShaderResourceManager::Function15826f0` | GUESS |
| `0x1582710` | 12 | `BSShaderResourceManager::Function1582710` | GUESS |
| `0x1582730` | 30 | `BSShaderResourceManager::Function1582730` | GUESS |
| `0x1582760` | 45 | `BSShaderResourceManager::Function1582760` | GUESS |
| `0x15827a0` | 12 | `BSShaderResourceManager::Function15827a0` | GUESS |
| `0x1582870` | 12 | `BSShaderResourceManager::Function1582870` | GUESS |
| `0x1582890` | 25 | `BSShaderResourceManager::Function1582890` | GUESS |
| `0x15828b0` | 7 | `BSShaderResourceManager::Function15828b0` | GUESS |
| `0x15828c0` | 9 | `BSShaderResourceManager::Function15828c0` | GUESS |
| `0x15829a0` | 12 | `BSShaderResourceManager::Function15829a0` | GUESS |
| `0x15829c0` | 12 | `BSShaderResourceManager::Function15829c0` | GUESS |
| `0x15896a0` | 38 | `BSLightingShader::GetVertexTechnique` | po3 |
