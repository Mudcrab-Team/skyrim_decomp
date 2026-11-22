Transfer status: UNREVIEWED

# Finding: exterior fog in Skyrim Special Edition

Status: OBSERVED where verified. INFERRED and UNVERIFIED items are marked. Static only.

Author: a `gpt-6.2-sol` research run via Codex (not the reviewer below).  
Human operator: Taylor.  
AI assistance / model: `gpt-6.2-sol` via Codex.  
Date (UTC): 2026-11-22.  
Target build id: `sse-steam-1-7-104`, retail `1.7.104.0`. The measured image SHA-256 `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f` equals the pin in [builds/target.json](../builds/target.json). Both runs measured the hash and asserted equality.  
Principal function RVAs (descriptive labels are GUESS): `0x308290` (weather load), `0x2a59f0` (climate load), `0x412810` (weather transition), `0x413a30` (fog scalars), `0x416760` and `0x414cf0` (colour weights and mixing), `0x40b740` (atmosphere update), `0x154c010` (Lighting fog constants), and `0x665740` (scene far limit).  
Source exposure: The author and reviewer inspected the pinned executable, `Skyrim.esm`, the shipped shader archive and five shipped INI templates from the operator's install. Both consulted the generated public layout names. The author also consulted earlier object LOD research for context. The author used no sibling decompilation and no downstream implementation source.  
Intended recipient: Skyrim Research department lead for boundary review. The proposed downstream use is Mudcrab's exterior fog work (issue #891). The maintainer's transfer decision is pending.

Name provenance: Field labels from `FogData`, `Sky`, `BSFogProperty` and `SceneGraph` are CRASHLOGGER_PDB(59818@2026.10.24) names, taken from the public generated tables at `origin/main` revision `ec7d97417850ffafb8c7cdba44c6c9d26b10bc73`. Setting names, shader technique names and image type names come from the retail inputs. Descriptive function labels are our own names and are GUESS.

Evidence addresses are VAs in the pinned image, base `0x140000000`. **Verified** means re-read at the cited source. **Inferred** identifies a conclusion with a missing binding. **Unverified** identifies missing evidence. Every group is static only. Transfer remains subject to [docs/clean-room.md](../docs/clean-room.md).

## Question and method

How do exterior weather fields produce fog on ordinary geometry, distant objects, and terrain? The evidence covers record loading, day-part and weather mixing, scene fog state, Lighting setup, 47 shader records, and compiled and shipped settings.

The master SHA-256 is `e198c3b85e5e48e0c92a6580d8f66e644256b68d812ee32b61735cf9b753df73`. The shader records come from the `shadersfx\shaders011.fxp` archive member, SHA-256 `72cfc73eb0938d5949f0b3a8683722a33b671a34b41b750ba138de8d154c5fbc`. The containing `Skyrim - Shaders.bsa` has SHA-256 `fd1ba630f443353ed21ed4ca0380968f9c7091c8434518ea3cc79bc6d38c18e7`.

## Observations

### G01. Weather record fields

**Verified, static only.** Each of the 84 scanned `WTHR` records in `Skyrim.esm` has a 32-byte `FNAM` subrecord. Its eight float32 values are day near, day far, night near, night far, day power, night power, day max, and night max. The loader stores them at weather offsets `+0x678` through `+0x694`. The exterior scalar mixer reads all eight. Far is the ramp endpoint, power controls the exponent, and max caps fog strength in G04. These eight values supply no separate weather high-clip field. Evidence at `0x14030894b–0x1403089ab` and `0x140413b17–0x140413cee`, with the `FogData` layout (CRASHLOGGER_PDB(59818@2026.10.24)).

**Verified, static only.** `NAM0` supplies packed colours to the weather table at `+0x698`. Each row stores sunrise, day, sunset, and night. Fog near uses zero-based row 1 and fog far uses row 12. Among the 84 records, the counts are 72 at 272 bytes, 11 at 224 bytes, and one at 208 bytes. Both fog rows fit in all three lengths. Evidence at `0x140308366`, `0x14030849d–0x140308509`, and `0x1404133e0–0x140413491`, with the day-part selection in G02.

**Confidence: high** for the scanned master and the traced loader and mixer. Record overrides and other formats remain **unverified**.

### G02. Time of day and weather transitions

**Verified, static only.** The first four `CLMT.TNAM` bytes give sunrise begin, sunrise end, sunset begin, and sunset end. Each unit is one sixth of an hour. The scalar and colour paths use cached endpoints. When those caches reflect the climate and extension, the endpoints are as follows.

| Endpoint | Hours |
|---|---|
| `A` | Sunrise begin less `fDaytimeColorExtension`, floored at zero |
| `B` | Sunrise end |
| `C` | Sunset begin |
| `D` | Sunset end plus `fDaytimeColorExtension`, capped at `23.99` |

The compiled extension is `0.5` hour at `0x14209e5a0`. The master climate record `0x00000812` has timing bytes `33, 60, 96, 123`. With the compiled extension, its endpoints are `5, 10, 16, 21` hours to the precision shown. Evidence at `0x1402a5b52/0x1402a5ba5` and `0x140419ab0/0x140419d00/0x140419d50/0x140419bb0`.

**Verified, static only.** The weather scalar branch requires current weather, Sky mode 3, and two null alternate lighting lookups. For ordered, distinct endpoints and game hour `h`, the day weight is `(h−A)/(B−A)` for `A < h < B`, one for `B ≤ h ≤ C`, and `(D−h)/(D−C)` for `C < h < D`. Otherwise the weight is zero. The branch uses this same weight for near, far, power, and max. For each field and each weather, the result is the weighted blend of its day and night values. If previous weather exists, the result is `q × current + (1−q) × previous` after each weather's day/night blend. The references are at `Sky+0x48/+0x50` and `q` at `+0x1b8` (`Sky` is a CRASHLOGGER_PDB(59818@2026.10.24) name). Evidence at `0x140413a36–0x140413cee`.

**Verified, static only.** With both weather references present, the generic fog colour path uses the same `q` with separate day-part weights. The table gives chronological colour endpoints within each weather, with linear blends over each half of sunrise and sunset.

| Interval | Colour endpoints |
|---|---|
| `A` to midpoint of `A,B` | Night to sunrise |
| Midpoint of `A,B` to `B` | Sunrise to day |
| `B` through `C` | Day |
| `C` to midpoint of `C,D` | Day to sunset |
| Midpoint of `C,D` to `D` | Sunset to night |
| At or before `A`, or at or after `D` | Night |

The selector puts sunrise first on both sunrise halves and sunset first on both sunset halves. For first-entry weight `t`, the weights on the four channel bytes are `q×t`, `q×(1−t)`, `(1−q)×t`, and `(1−q)×(1−t)`. The helper multiplies their sum by the float32 reciprocal of 255 and caps the resulting channel at one. Special adjustments for rows 3 and 4 leave the fog rows on this generic path. Evidence at `0x140416760–0x140416a06`, `0x1404133bd–0x140413491`, `0x140414cf0–0x140414eea`, and `0x140ef2e80–0x140ef2ead`.

**Verified, static only.** With both weather references on the base transition path, `q` is elapsed game hours divided by the transition duration. The elapsed time can include a 24-hour wrap. The duration interpolates from `fWeatherTransMin` to `fWeatherTransMax` with weight equal to the incoming weather byte at `+0x667` divided by 255. The compiled duration endpoints are `0.01` and `0.25` hour. With current weather alone, the base weight is one. The acceleration branch computes `q0 + (q−q0) × (1 + fWeatherTransAccel)`, with stored anchor `q0` and compiled acceleration `4.0`. For finite weights, the completion branch clears the previous reference and sets `q=1` when its input weight exceeds one. At equality a previous reference can remain with zero weight. Evidence at `0x140412c8a–0x140412d82` and `0x14209e708/720/738`.

**Confidence: high** for the stated ramps, channel cap, and transition arithmetic. Forced and interrupted transition routing, cache timing at a climate change, and coincident or unordered endpoints remain **unverified**.

### G03. Scene fog state and Lighting constants

**Verified, static only.** The atmosphere can attach its fog property (`BSFogProperty`, CRASHLOGGER_PDB(59818@2026.10.24)) to scene index 0. With a property present, the atmosphere sets property flag bit 0 when finite far exceeds near. The scalar update flag gates copies of near, far, power, and max to property offsets `+0x50/+0x54/+0x84/+0x88`. The near and far RGB copies to `+0x38/+0x44` occur whether or not that scalar flag is set. Lighting selects a scene using the byte at `0x1420d6970` and reads that scene's fog property. When the selected scene has no property, the fog writer returns without updating its fog vectors. Evidence at `0x14040b959–0x14040b991`, `0x14040ba9c–0x14040bb46`, `0x1414ec040–0x1414ec055`, and `0x14154c020–0x14154c035`.

**Verified, static only.** For finite endpoints other than the zero pair, let `r = 1/(far−near)`. The fog writer uses the following constant locations in the checked shader headers and bodies.

| Stage and location | Source |
|---|---|
| VS `b0[1]` | `(near×r, r, power, max)`. With both endpoints zero the vector is `(5000000, 0.1, 1, 0)`. |
| VS `b0[2].xyz`, `b0[3].xyz` | Near RGB, far RGB |
| PS `b0[0]` | The same near vector as VS `b0[2]`. W comes from the float at `0x1420d694c`, initialized in the image to `0.8333333134651184`. |
| PS `b0[1].x` | Cached `fLightingOutputColourClampPostLit:General`, compiled `1.0` at `0x1420d8d00`. |

The reciprocal path divides by zero for equal nonzero finite endpoints. All 22 checked VS headers select float offsets `4/8/12` through shader-object bytes `+0x5d/+0x5e/+0x5f`. All 25 checked PS headers select offsets `0/4` through bytes `+0x53/+0x54`. Each checked PS uses the W of `b0[0]`. Its RGB components are unused in those records. The W source has native writes after initialization. Evidence at `0x14100fcb1–0x14100fcd5`, `0x141010081–0x1410100b2`, `0x14154c03f–0x14154c1b3`, `0x141b44ea0`, `0x141548614–0x1415486b9`, `0x141547454–0x14154745c`, `0x140106da0–0x140106da8`, and `0x14037ac7f–0x14037ac8f`.

**Confidence: high** for the static writes and slot correspondence. Active scene, live constants, and the rendered result for degenerate endpoints remain **unverified**.

### G04. Fog applied to a pixel

**Verified, static only.** All 22 checked Lighting vertex shaders use the following ramp. Let `d` be the Euclidean length of clip-space XYZ before division by W. The terrain inputs to this length are described in G05.

```text
s  = saturate(d × VS b0[1].y − VS b0[1].x)
F  = min(exp2(log2(s) × VS b0[1].z), VS b0[1].w)
Cf = nearRGB + F × (farRGB − nearRGB)
```

Saturate bounds `s` to `[0,1]`. For positive finite `s` and finite power, the exponent expression is a power ramp. Power one gives a linear ramp before the upper cap. The cap also affects the near/far RGB blend. This fog expression has no separate height or sun-direction term. The resulting `(Cf,F)` travels in `COLOR1` with perspective-correct interpolation. The checked records use register 9, 12, or 13 for this semantic, depending on the key.

**Verified, static only.** All 25 checked pixel shaders use the interpolated values in the fog blend, then apply further RGB processing. Let `L` be the lit RGB input after vertex colour multiplication. Let `k = PS b0[0].w`, `B = PS b0[1].x`, `S = PS b12[42].y`, and `T = PS b12[42].z`. The following algebra describes each channel of target 0 RGB for surviving pixels.

```text
M = L + F × (Cf − L)
E = S × (L − k × M)
target 0 RGB = min(E + B, L) − T × E
```

Here `M` is an intermediate. The native slot-12 writer supplies `S=0` when bit 1 of its flag argument is set, and one otherwise. It supplies `T=1` when bit 2 is set, and zero otherwise. Evidence is the keys in G05 and the ordinary comparison keys `VS 00000000`, `VS 00000001`, and `PS 00000001`. The slot-12 writer and binding are at `0x14100b299`, `0x14100b327–0x14100b349`, `0x14100b408–0x14100b50d`, and `0x14101080d–0x141010825`.

**Confidence: high** for the checked shader expressions and the static slot-12 flag mapping. Runtime flag choices, scene constants, exceptional power inputs, and later frame processing remain **unverified**.

### G05. Object and terrain LOD

**Verified, static only.** The pinned image binds Lighting to package group 6. The technique table names 13 and 15 `LODOBJECTS` and `LODOBJECTSHD`. The following list covers every entry for those two techniques in group 6. Each prefix combines with each suffix to give a checked key.

| Stage | Key prefixes | Six-digit suffixes per prefix |
|---|---|---|
| VS, 16 records | `0d`, `0f` | `000000`, `000001`, `008000`, `008001`, `040000`, `040001`, `048000`, `048001` |
| PS, 20 records | `0d`, `0f` | `000001`, `008001`, `040001`, `048001`, `100001`, `108001`, `140001`, `148001`, `208001`, `248001` |

For these object vertices and the two ordinary comparison vertices, the fog length uses the same clip XYZ emitted for rasterization. The checked object pixels use the same blend and subsequent target 0 RGB expression as the ordinary comparison. Evidence is the group 6 loader at `0x1414ea7c3–0x1414ea872`, the technique table at `0x141589648`, and the enumerated shader records.

**Verified, static only.** Terrain techniques 9 (`LODLANDSCAPE`) and 18 (`LODLANDNOISE`) use the same constant locations and fog expressions. Their four vertex entries are `09000004, 09040004, 12000004, 12040004`. Their four pixel entries are `09000005, 09040005, 12000005, 12040005`. These lists cover both terrain techniques in group 6. Terrain can adjust vertex Z before projection, so that adjustment contributes to the projected XYZ used for fog. A separate post-projection bias changes emitted `SV_Position.z`. For finite pre-bias clip Z, that bias is `0.5 × saturate((z−70000) × 0.0001)`. The fog length uses pre-bias clip Z.

**Inferred.** The common Lighting setup and constant locations support a shared scene fog source for these ordinary, object LOD, and terrain LOD techniques. **Unverified.** Active shader pairings and constants at particular draws. The ordinary sample covers two of the 20 VS and one of the 2292 PS records with technique high byte zero. Other techniques, shader groups, packages, and sky-family passes remain unverified. The sky, cloud, sun and moon fog formulas remain unverified.

**Confidence: high** for the enumerated records and **medium** for the active binding. A draw capture could establish the binding and effective values for each mesh class.

### G06. Settings and scene far-distance override

**Verified, static only.** When the gate byte at `0x1420b3368` is zero, the fog scalar update obtains a limit `L` from world `SceneGraph` (CRASHLOGGER_PDB(59818@2026.10.24)) virtual slot `+0x1f0`. It replaces far with `L`. For finite endpoints, the near update follows the float32 order represented by `min(L, near − ((far−L)/(far−15)) × (near−15))`, using the original near and far. The division has no separate guard for prior far equal to 15. The image initializes the gate to one. Two direct reads appear at `0x140413e86` and `0x14051626f`. Evidence at `0x140413e86–0x140413ef1`, world scene locator `0x143230740`, vtable `0x141914b00`, and float `15.0` at `0x1420cf9b0`. **Unverified.** The gate's runtime writer and the play configurations that open it.

**Verified, static only.** The getter at `0x140665740–0x140665834` can return a custom distance or a fixed alternate value of `20480` directly. Its remaining branches select a candidate. The eligible worldspace branch starts at Max and returns `Min + Pct × (candidate−Min)`. The fallback starts at `353840` and bypasses this scaling. In Sky mode 1, a positive applicable cell value can cap either candidate before the scaling decision. The INI-backed values can reach fog endpoints through the zero-gate path.

| Setting | Compiled value | Value field |
|---|---|---|
| `fNoLODFarDistanceMin:Display` | 100 | `0x1420cf968` |
| `fNoLODFarDistanceMax:Display` | 10240 | `0x1420cf980` |
| `fNoLODFarDistancePct:Display` | 1.0 | `0x1420cf998` |
| `bFogEnabled:Weather` | 1 | `0x14209e858` |
| `bDo30VFog:Display` | 1 | `0x1420d6a00` |
| `bSAOApplyFog:Display` | 1 | `0x1420d8868` |

**Verified, static only.** The `bSAOApplyFog` value reaches a separate flag and shader setup at `0x141541f0a–0x141541f11` and `0x141542cf8`. **Unverified.** A link from these three booleans to the checked exterior Lighting expressions.

**Verified, static only.** None of `Skyrim_Default.ini`, `Low.ini`, `Medium.ini`, `High.ini`, or `Ultra.ini` contains a case-insensitive match for fog, clip, sunrise, sunset, `NoLODFarDistance`, `WeatherTrans`, `DaytimeColorExtension`, or `fLightingOutputColourClampPostLit`. An ASCII setting-name scan of `.data` and `.rdata` found no floating-point setting with literal form `f…Fog…:Section`. **Unverified.** Other names, indirect consumers, and overrides in user INIs.

**Confidence: high** for the byte gate, the arithmetic, the compiled values, and the five template scans. Runtime setting coverage remains **unverified**.

### G07. Interior overlap

**Verified, high confidence, static only.** In Sky modes 1 and 2 with no alternate lighting override, the current-cell or fallback-template branch writes the shared scalar slots. For finite inputs, far defaults to `163840` outside `(0,163840]`. Near defaults to far times `0.17000001668930054` outside `(0,far]`. The branch copies power and max from the same source. Evidence at `0x140413cf7–0x140413e86`. **Unverified.** The active interior draw binding.

## Interpretation and alternatives

The checked Lighting path evaluates a projection-dependent curve at vertices and interpolates both fog strength and fog RGB for the pixel calculation. A per-pixel depth or world-space radial calculation would change this input. The weather max limits vertex fog strength. The gated scene far override can change CPU endpoints before the shader ramp.

## Negative results and limits

The static shader comparison covers 22 vertex and 25 pixel records. No game launch, render capture, live constant read or visual comparison was performed. Live shader selection, particular draw constants, effective user INIs, final frame output, and other fog paths remain **unverified**. This finding is not match evidence for any function. Keep listings and other game-derived material in `.local/`. None is published here.

## Independent review (2026-11-22)

Reviewer: `gpt-6.2-sol` through Codex, high effort, fresh context, separate run. The reviewer did not author or draft this finding. Date: 2026-11-22.
Source reviewed: the draft of this finding, against the pinned image `sse-steam-1-7-104` (measured SHA-256 equals the pin in [builds/target.json](../builds/target.json)), the shipped master, the shader archive, the five shipped INI templates and the generated public layout names at `ec7d97417850ffafb8c7cdba44c6c9d26b10bc73`. Exposure of the review: mixed (retail executable, shipped assets, generated names, the draft). Method: the reviewer re-read the pinned sources and decoded and checked all 47 selected shader records against an independent package walk. This is a static finding review. It is not match evidence for any function. It does not decide transfer eligibility ([docs/clean-room.md](../docs/clean-room.md)).

The draft carried one wrong digit in the generated-name revision hash. This file uses the value that Git resolves. The observations above already include the corrected text.

| Group | Verdict | One-line status |
|---|---|---|
| G01. Weather record fields | Confirmed | The eight scalar fields, four colour day parts, and two fog colour rows agree with the master and native reads. |
| G02. Time of day and weather transitions | Corrected | Scope the weather blend, add the per-channel RGB cap, and state the strict transition completion threshold. |
| G03. Scene fog state and Lighting constants | Corrected | Identify the active scene lookup, the null return, and the pixel constants alongside the vertex constants. |
| G04. Fog applied to a pixel | Corrected | The vertex ramp and intermediate blend hold. All 25 checked pixel shaders process that blend further before target 0 RGB. |
| G05. Object and terrain LOD | Corrected | All stated LOD keys passed. Terrain fog includes the conditional pre-projection Z change and excludes the emitted clip Z bias. |
| G06. Settings and scene far-distance override | Corrected | Preserve the float32 update order and identify which far-getter branches use the INI scaler. |
| G07. Interior overlap | Confirmed | The cell/template branch writes the shared scalar slots. The live interior draw binding remains unverified. |

Summary: 2 groups confirmed, 5 corrected, 0 rejected.

## Reviewer and outcome

Reviewed independently on 2026-11-22 by `gpt-6.2-sol` (Codex, high effort, fresh context), separate from the author. Outcome: 2 confirmed (G01, G07), 5 corrected (G02 to G06), 0 rejected. Static only. A review verdict is not match evidence, and transfer eligibility is not decided. Unverified: live draw bindings and bound values, including the active scene, shader key pairing and per-draw constants; visible and rendered results, including degenerate endpoints and final frame output; the sky, cloud, sun and moon fog paths; other Lighting techniques, shader groups and packages beyond the enumerated records; the runtime producer of the far-override gate byte and the configurations that open it; forced and interrupted weather transition routing, cache timing at a climate change, and coincident or unordered endpoints; other `NAM0` formats and record overrides; any link from `bFogEnabled`, `bDo30VFog` and `bSAOApplyFog` to the checked Lighting expressions; indirect settings consumers, other setting names and user INI overrides; runtime slot-12 flag choices and exceptional power inputs; the active interior draw binding.
