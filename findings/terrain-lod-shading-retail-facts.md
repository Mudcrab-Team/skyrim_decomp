Transfer status: UNREVIEWED

# Finding: terrain LOD shading in Skyrim Special Edition

Status: OBSERVED where verified. INFERRED and UNVERIFIED items are marked. Static only.

Author: a `gpt-6.2-sol` research run via Codex (not the reviewer below).  
Human operator: Taylor.  
AI assistance / model: `gpt-6.2-sol` via Codex.  
Date (UTC): 2026-11-22.  
Target build id: `sse-steam-1-7-104`, retail `1.7.104.0`. Both runs measured SHA-256 `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f` and asserted equality with the pin in [builds/target.json](../builds/target.json).  
Principal function RVAs (descriptive labels are GUESS): `0x1a2360` (overlap bounds), `0x1011370` (binding), `0x1011750` (vertex layout), `0x102b910` (sampler table), `0x1523d20` (texture set), `0x1547d20` (technique selection), `0x1548820` (material setup), `0x15496ca` (geometry setup), and `0x154bb90` (point-light upload).  
Source exposure: The author and reviewer inspected the operator's pinned executable, shipped meshes, textures, shaders and INI templates from the operator's retail install. The author also consulted the earlier object LOD, sun-shadow and exterior fog findings for anchors. Both runs consulted the generated public layout names. The author used no sibling decompilation and no downstream implementation source.  
Intended recipient: Skyrim Research department lead for boundary review under [docs/clean-room.md](../docs/clean-room.md). The proposed downstream use is Mudcrab's terrain LOD shading work. The maintainer's transfer decision is pending.

Name provenance: The field label `landscapeNoiseTexture` is a CRASHLOGGER_PDB(59818@2026.10.24) name, taken from the public generated tables at `origin/main` revision `790aaeb65be00c5f5828f44ff0bf15ed7cc46dfa`. Shader technique names, shader constant names and INI setting strings come from the retail inputs. Descriptive function labels are our own names and are GUESS.

Evidence addresses below are VAs in the pinned image, base `0x140000000`. The principal list above gives the matching RVAs. **Verified** identifies a source-backed result in the stated scope. **Inferred** identifies an interpretation. **Unverified** identifies missing evidence. Every group is static only. Keep listings of the game files in `.local/`. This file contains only counts, offsets, addresses, constants and formulas.

## Question and method

Which assets and shader inputs govern distant terrain lighting? The review traces the land mesh links, DDS headers, shader records, native bindings, compiled settings, shipped INIs and near-terrain overlap. Its shader scope is Lighting group 6, techniques 9 and 18, which hold 4 VS and 4 PS records.

## Observations

### G01. Assets and shader coverage

**Verified.** Each of the 9,584 BTRs in `Skyrim - Meshes1.bsa` contains one `BSTriShape` linked to a `BSLightingShaderProperty`. Its texture set has the block's diffuse DDS at entry 0 and the matching `_n.DDS` at entry 1. Entries 2–8 are empty. The linked properties have material type 18 and flag words `0x80401000/0x00000003`.

**Verified.** The nine `Skyrim - Textures0.bsa` through `Skyrim - Textures8.bsa` archive indices resolve 18,692 of 19,168 distinct paths. The unresolved paths are the diffuse and normal pairs for 238 Markarth blocks. The stratified sample included 49 diffuse and 49 normal headers. Each sampled file has dimensions 256 × 256 and eight mip levels. The full census of the resolved headers gives these counts.

| Role | File count | DDS dimensions, mip levels and format |
|---|---:|---|
| Normal | 9,346 | 256 × 256, eight mips, DXT5 (BC3) |
| Diffuse | 9,326 | 256 × 256, eight mips, uncompressed 32-bit BGRX, zero alpha mask |
| Diffuse | 20 | 4 × 4, two mips, uncompressed 32-bit RGBA |

**Verified.** The loader at `0x1414ea872` selects Lighting group 6 of `shadersfx/shaders011.fxp`, SHA-256 `72cfc73eb0938d5949f0b3a8683722a33b671a34b41b750ba138de8d154c5fbc`. Group 6 contains 127 VS records and 6,924 PS records. The feature-name dispatch at `0x1415894b0–0x1415894d2` uses the table at `0x141589648` to identify the checked techniques. The table below lists every record under those two techniques. The author checked all 4 VS and all 4 PS records in it. The author did not check the other records of group 6 or any other shader group.

| Technique | VS key and package offset | PS key and package offset |
|---|---|---|
| 9 `LODLANDSCAPE` | `09000004` at 8865432 | `09000005` at 42866972 |
| 9 `LODLANDSCAPE` | `09040004` at 8868760 | `09040005` at 42870248 |
| 18 `LODLANDNOISE` | `12000004` at 9039976 | `12000005` at 51682256 |
| 18 `LODLANDNOISE` | `12040004` at 9043304 | `12040005` at 51685968 |

**Verified.** Corresponding VS payloads are identical across techniques for each value of the `0x00040000` bit. The native key setup at `0x141547d20–0x141547d9a` can remap 18 to 9 when the byte at `0x1420d681f` is zero. Below, “projected” means the records with that bit set.

**Confidence: high** for the scanned archive and package records. Resolution outside the nine texture archives, runtime views and active draw keys remain **unverified**.

### G02. Vertex layout and base UVs

**Verified.** The 9,584 linked land shapes all have descriptor `0x300000000405` and a 20-byte stride. The parsed vertex and index counts agree with the stored payload lengths. The native layout builder at `0x141011750–0x141011c5c` gives four float32 position components at byte 0 and two float16 `TEXCOORD0` components at byte 16. The descriptor contains no normal, tangent, colour or secondary UV attribute. All four VS records read position XYZ and UV0 XY and emit white `COLOR0`.

**Verified.** The base lookup coordinate is `UV0 × VS b1[2].zw + VS b1[2].xy`. The material writer at `0x141548f9d–0x141548fe3` supplies those offsets and scales. All 9,584 serialized transforms have offset `(0,0)` and scale `(1,1)`. Across their vertices, U ranges from approximately −0.0020084 to 1.0019531 and V from −0.0144424 to 1.00390625. One width-32 Deepwood Redoubt mesh uses U from 0 to 0.25 and V from 0.75 to 1.

**Inferred.** Subregion bounds support block-local atlas coordinates. **Confidence: high** for the layout and bounds. The purpose of stored position W outside the checked shaders and live material overrides remain **unverified**.

### G03. Slots, addressing and mip behaviour

**Verified.** Native loading at `0x141523dc7–0x141523de5` sends entries 0 and 1 to material fields `+0x48` and `+0x58`. Material setup binds them to `t0` and `t1`. Slot 0 also has a render-target source branch. Both PS samples use the same interpolated UV and implicit derivatives in all four records.

| Inputs | Address in the traced path | Filter and LOD limits |
|---|---|---|
| `t0/s0`, `t1/s1` | Technique setup selects wrap. BTR material setup applies serialized enum 0, clamp. | Enum 1, D3D11 `0x14`. Linear minification and magnification, point mip selection, bias 0, MinLOD `−FLT_MAX`, MaxLOD 0. |
| `t15/s15`, technique 18 | Wrap. | The same filter, bias and limits. |

**Verified.** Technique setup writes address enum 3 and filter enum 1 at `0x14154852e–0x141548591`. Material addressing takes its enum from `+0x70` at `0x1415492bd–0x141549369` and `0x14154c9a0–0x14154c9fd`. The sampler table at `0x14102b910–0x14102baf3` implements the listed limits. Context binding at `0x141011370–0x1410113f7` selects from that table. The descriptor limits sampling to the first mip exposed by the bound view, even though the base shader samples use derivatives. The technique 18 branch at `0x141548e5b–0x141548eb2` takes the noise texture from material `+0xb0` when present. It sets wrap and filter 1 regardless of pointer presence.

**Confidence: high** for the traced binding and sampler descriptor. The asset mip exposed through the view, replacement textures and any draw-time overrides remain **unverified**.

### G04. Normal decoding and space

**Verified.** All four PS records sample the block's normal resource at `t1/s1`. The signed vector is `Nraw = 2 × ((R,B,G) − 0.5)`. X comes from red, Y from blue and Z directly from green. Alpha is unused. The two base records use this vector directly. The two projected records normalize it before building the projected basis and mixing in detail.

**Verified.** The selected normal feeds the directional and point-light dot products and the directional ambient dots in G05. The projected records also use the normalized base to compute plane weights and the basis. For the auxiliary packing path, the shader transforms the selected normal by three interpolated rows in `TEXCOORD8..10` and normalizes it before packing. The VS builds those rows from `VS b2[0..2]` and `VS b12[0..2]`.

**Verified.** Both checked techniques take the same model-space branch in geometry setup. The PS key retains raw bit 1 when bit 2 is set, and the checked keys have bit 2 set and bit 1 clear. The branch constructs the inverse geometry world transform, negates the source light direction, applies the inverse as a direction transform, and normalizes the result into `PS b2[0].xyz`. The direction transform and normalization resolve to `D3DXVec3TransformNormal` and `D3DXVec3Normalize`. The separate RGB path writes `PS b2[1].xyz` after scaling the source colour. The geometry rotation also changes the directional ambient coefficients before upload to `PS b2[11..13]`. Evidence at `0x1415896d0–0x1415896e1`, `0x1415495a4–0x1415495c1`, `0x1415496ae–0x141549ab1`, and `0x141549ad1–0x141549ea4`.

**Inferred.** The model-space light upload and serialized normal flag `0x1000` support block model axes as the stored normal space. **Confidence: high** for the decode and native transforms, **medium** for the stored-axis interpretation. The offline bake convention and live per-block axes remain **unverified**.

### G05. Diffuse lighting, fog and output

**Verified.** The four PS records share this pre-fog order for finite inputs with valid normalization and light radii. `N` is the selected normal from G04 and `P` is interpolated `TEXCOORD4.xyz`. Constant locations below use pixel-stage slots unless marked otherwise.

| Order | Calculation and constant slots |
|---|---|
| 1 | Initialize the accumulator with `saturate(dot(N, b2[0].xyz)) × b2[1].xyz`. |
| 2 | Visit point lights in increasing index order below `min(b2[29].x, 7)`. For light `i`, form `D = b2[15+i].xyz − P`. Set `a = saturate(length(D)/b2[15+i].w)`. Multiply `saturate(dot(N, normalize(D)))` by `b2[22+i].rgb`. Multiply-add this RGB with attenuation `1−a²` into the accumulator. |
| 3 | Form the three directional ambient channels with `dot(b2[11+c], (N,1))` for channels `c=0,1,2`. Add `b2[4].yzw` to that ambient RGB before adding the result to the accumulator. |
| 4 | Multiply-add `b1[8].x × b1[8].yzw` into the accumulator. Multiply by effective diffuse RGB, then multiply by `COLOR0.rgb`. |

**Verified.** The input labels for direction, directional colour, point position and colour, directional ambient and `EmitColor` agree with the table at `0x141589128` and the four record headers. The material writer at `0x14154936f–0x1415493c6` fills `PS b1[8].x` from property `+0xcc`. It takes YZW from the RGB triple selected by the property's byte at `+0xf0`. Raw key bits 3–5 provide the point count. Geometry setup clears the point position and colour arrays, then calls `0x14154bb90` when the count is nonzero. On its model-space branch, this helper transforms point positions by the inverse coordinate transform and divides their radii by the geometry scale its caller passes. Evidence at `0x141549fdc–0x14154a087` and `0x14154bc13–0x14154bd02`.

**Verified.** The base VS records send the adjusted model position as `P`. The projected VS records send the model-transformed adjusted position plus `VS b2[14].xyz`. The upload at `0x14154a5e3–0x14154a61a` supplies this VS vector from `0x1433d3ee8`. Point positions and projected `P` have separately traced producers. Their alignment on a live draw and the population of draws with nonzero point lights remain **unverified**.

**Verified.** The four PS records contain no shadow-mask lookup. Let `L` be the lit RGB after vertex colour and `F` its interpolation toward `COLOR1.rgb` by `COLOR1.a`. Define `Q = L − PS b0[0].w × F` and `S = Q × PS b12[42].y`. The shader forms the clamp input `Q × PS b12[42].y + PS b0[1].x` with a separate multiply-add, takes the component-wise minimum with `L`, then subtracts `S × PS b12[42].z` with another multiply-add. Target 0 alpha is slot-0 sample alpha multiplied by `PS b2[3].z` and `COLOR0.a`. The checked VS sets vertex colour and alpha to one. Fog inputs and slot-12 flags are described in exterior fog G03–G05 (PR #812, `findings/exterior-fog-retail-facts.md`), which checked the same eight records.

**Verified.** Auxiliary output selection uses `PS b2[7].z > 0.00001`. If true, target 2 repeats target 0 and target 1 XY is `(1,0)`. Otherwise target 2 carries the packed normal XY, zero Z, and a W derived from `PS b2[7].x/.y/.w`. Target 1 XY then takes projected `POSITION1` less projected `POSITION2`, scaled by `(−0.5, 0.5)`. The divided XY projections use `PS b12[12,13,15]` and `PS b12[16,17,19]`, respectively. Target 1 ZW is `(0,1)` in both branches.

**Confidence: high** for shader order and native writes. Live light values, alignment, and the use of the auxiliary targets remain **unverified**.

### G06. Noise and projected detail

**Verified.** Let `B` be the base diffuse RGB and define `a = saturate((0.55 × sum(B) − 0.4) × 1.666667)` and `h = a² × (3−2a)`. Technique 18 samples red from `t15/s15` at `3 × UV`. Both of its records multiply `B` by `0.37 + 0.833333 × lerp(noiseR, 0.37, w)`. The weight `w` is `0.8h` in `12000005` and `h` in `12040005`. Technique 9 starts with `B`. Constants are rounded to the shown precision.

**Verified.** The projected records sample both `t12/s12` and `t13/s13` on the YZ, XZ and XY planes of `P`. Their respective coordinate scales are `PS b2[8].x` and `.w`. With `n = normalize(Nraw)`, the weight opposite axis `i` is `max(0.01, (7 × (abs(n[i]) − 0.2))³)` divided by the sum of all three weights. For each resource, accumulate weighted XZ first, then YZ, then XY. Interpolate from the slot-12 result toward the slot-13 result by `h`. Decode that RGB to signed components in RGB order and normalize. The basis uses `T = normalize((n.z, 0, −n.x))`, `normalize(T × n)` and `n`. The shader normalizes the transformed detail vector. Its squared length must satisfy `0.999 < length² < 1.001` to select the blend. The weight toward detail is `saturate(1.5 − s² × (3−2s))` where `s = saturate((Nraw.z − 0.95) × 19.999996)`. The selected blend feeds lighting directly. The fallback is `n`.

**Verified.** In both projected records, let `C` be the diffuse RGB after any noise adjustment and `p = 0.465 + 0.441h`. The colour targets differ by channel.

| Channel | Adjustment target |
|---|---|
| Red | `max(C.r, 2 × (0.078 + 0.270h))` |
| Green | `max(C.g, 2 × (0.098 + 0.281h))` |
| Blue | `max(C.b, 2 × (−0.035 + 0.441h))` if `p > 0.5`. Otherwise `min(C.b, 2p)`. |

Interpolate from `C` toward those targets by `0.30 + 0.20h`. The blue upper-branch target uses the shown `−0.035` offset directly. The checked records make no additional lookup of a parent or near-terrain texture.

**Verified.** The map initialization at `0x14099fda4–0x14099fe3f` loads the two projected normal resources into globals `0x1420d6920` and `0x1420d6928`. Their setting keys and compiled filenames are in G08. The writers at `0x1409a024a–0x1409a02af` and `0x1409a0783–0x1409a07f4` fill the scale vector at `0x1433d3ef8`. The geometry path at `0x14154a530–0x14154a61a` binds the resources at slots 12 and 13, writes wrap addresses and uploads this vector to `PS b2[8]`. These PS records read X and W. The two strength-related lanes do not feed their projected math.

**Confidence: high** for the shader arithmetic, resource initialization and mapped constant writers. Effective filter and mip state for slots 12 and 13, projected-key selection and bound views remain **unverified**.

### G07. Near-terrain overlap and depth

**Verified.** For a positive grid width, the native update starts from the centre cell plus or minus `floor(uGridsToLoad/2)` along each axis. Each cardinal probe checks one boundary cell with the other coordinate fixed at the centre cell. If it finds land and the finite predicate result is strictly below 1, that edge moves inward one cell. A missing cell or missing land leaves the edge in place. The native update converts inclusive maxima to exclusive cell edges and multiplies coordinates by 4096. The setter derives the centre and half extents. Lighting subtracts frame origin XY from the centre and 15 from each half extent before upload to `VS b0[0]`. Evidence at `0x1405162d6–0x1405162e0`, `0x1401a2360–0x1401a2506`, `0x1402ad340–0x1402ad390`, `0x1414ecb20–0x1414ecb7b`, and `0x141548597–0x141548607`.

**Verified.** All four VS records test whether the absolute XY difference between transformed position and rectangle centre is strictly less than both half extents. Inside, they subtract `230 + transformedZ/1e9` from local Z. Here `transformedZ` comes from the original position before the drop, using `VS b2[2]`. The projection uses the adjusted vertex. The VS separately adds `0.5 × saturate((clipZ−70000) × 0.0001)` to its emitted clip Z. Fog includes the local drop and excludes the later clip-Z bias. The four PS records have no overlap alpha fade, discard or explicit depth output.

**Inferred.** Lowering the LOD terrain can let detailed land cover it in the rectangle. **Confidence: high** for the bound and shader arithmetic, **medium** for this interpretation. The land predicate's live readiness meaning, BTR admission, ordering and final stencil and blend state remain **unverified**.

### G08. Settings and defaults

**Verified.** The pinned image initializes these settings. Among these keys, the five shipped INI templates contain only the four `fSplitDistanceMult` entries listed below.

| Setting | Compiled value | Checked relation |
|---|---|---|
| `bDisplayLODLand:LOD` | 1 at `0x1420b5e30` | Native reads at `0x1406537e8` and `0x14065db0b`. |
| `fLODLandDropAmount:LOD` | 230 at `0x1420b5e78` | Native copy to cache `0x1420d6848` at `0x140656132–0x14065613a`. |
| `fLODLandVerticalBias:LOD` | 0 at `0x1420b5e18` | Compiled value. |
| `uGridsToLoad:General` | 5 at `0x142079eb0` | Coverage rectangle at `0x1401a2360`. |
| `fSplitDistanceMult:TerrainManager` | 1.5 at `0x1420b33d8` | Cache at `0x140519af8`. Low 0.5, Medium 1.1, High 1.5, Ultra 1.5. |
| `fLandTextureTilingMult:Landscape` | 3 at `0x14207b868` | Land builder read at `0x1402b4052`. |
| `bLandSpecular:Landscape` | 1 at `0x14207b970` | Land builder read at `0x1402b364b`. |
| `iLandscapeMultiNormalTilingFactor:Display` | 4 at `0x1420d8e50` | Separate material branch at `0x141548db7`. |
| `fMipBias:Display` | 0 at `0x1420d6a60` | The traced sampler descriptor supplies its own zero bias. |
| `sWorldMapOverlayNormalTexture:MapMenu` | `Data\Textures\Terrain\WorldMapOverlay_n.dds` at `0x1420bc590` | Resource bound at slot 12 on the projected path. |
| `sWorldMapOverlayNormalSnowTexture:MapMenu` | `Data\Textures\Terrain\WorldMapOverlaySnow_n.dds` at `0x1420bc5a8` | Resource bound at slot 13 on the projected path. |
| `fMapMenuOverlayScale:MapMenu` | Approximately 0.000035 at `0x1420bc5f0` | Supplies `PS b2[8].x`. |
| `fMapMenuOverlaySnowScale:MapMenu` | Approximately 0.000045 at `0x1420bc608` | Supplies `PS b2[8].w`. |

**Verified.** The checked shaders use a literal 230 for the overlap drop and sample the slot-1 normal unconditionally. A direct-reference scan found the cache write for `fLODLandDropAmount`. The technique-remap byte at `0x1420d681f` clears on an eligible path and sets when a secondary object at `+0x78` exists. Its writes are at `0x14152084a`, `0x1415208a9` and `0x1415208d9`.

**Unverified.** The native drop cache's consumers, any connection from either drop or vertical bias setting to the VS literals, an INI toggle for the base normal lookup, and the meaning of the remap control input. **Confidence: high** for the defaults, template scan and traced references.

## Interpretation and limits

**Inferred.** The per-block normal supplies surface orientation at each sampled pixel, including variation within a triangle whose vertices carry only position and UVs. Technique 18 also varies diffuse RGB with noise. The projected keys add separate normal and colour processing.

**Unverified.** Other techniques and passes, texture fallback and views, effective draw state, and visual parity. Transfer remains subject to `docs/clean-room.md`.

## Independent review (2026-11-22)

Reviewer: `gpt-6.2-sol` through Codex, high effort, fresh context, separate run. The reviewer did not author or draft this finding. Date: 2026-11-22.
Source reviewed: the draft of this finding, against the pinned image `sse-steam-1-7-104` (measured SHA-256 equals the pin in [builds/target.json](../builds/target.json)), the shipped BTR meshes, texture archives, shader archive and five INI templates, and the generated public layout names at `790aaeb65be00c5f5828f44ff0bf15ed7cc46dfa`. Exposure of the review: mixed (retail executable, shipped assets, generated names, the draft). Method: the reviewer independently parsed the shader package, the BTR links, the DDS headers and the INI templates, decoded all eight selected shader records, and checked the native writers against the record header offsets. This is a static finding review. It is not match evidence for any function. It does not decide transfer eligibility ([docs/clean-room.md](../docs/clean-room.md)).

The observations above already include the corrected text.

| Group | Verdict | One-line status |
|---|---|---|
| G01. Assets and shader coverage | Corrected | All eight shader records agree with the exterior fog finding. The full DDS census finds 20 small diffuse files outside the sample. |
| G02. Vertex layout and base UVs | Corrected | Position and UV0 are the only vertex attributes. The complete UV range extends slightly outside `[0,1]`. |
| G03. Slots, addressing and mip behaviour | Confirmed | Diffuse and normal use `t0/s0` and `t1/s1`. Both traced samplers cap the view-relative mip at zero. |
| G04. Normal decoding and space | Corrected | X is red, Y blue and Z green. The normal also feeds point lighting, directional ambient and auxiliary packing. |
| G05. Diffuse lighting, fog and output | Corrected | The shader accumulation order is pinned. The native path populates the point-light arrays after clearing them when the point count is nonzero. |
| G06. Noise and projected detail | Corrected | The projected RGB adjustment uses separate channel targets. The resource defaults and both scale sources are traced. |
| G07. Near-terrain overlap and depth | Corrected | The edge conditions are established. The local Z drop is separate from the clip-Z bias. |
| G08. Settings and defaults | Confirmed | The nine compiled values and the four preset overrides agree. The shader drop literal has a separate evidence trail from the native cache. |

Summary: 2 groups confirmed, 6 corrected, 0 rejected.

## Reviewer and outcome

Reviewed independently on 2026-11-22 by `gpt-6.2-sol` (Codex, high effort, fresh context), separate from the author. Outcome: 2 confirmed (G03, G08), 6 corrected (G01, G02, G04, G05, G06, G07), 0 rejected. Static only. A review verdict is not match evidence, and transfer eligibility is not decided. Unverified: live draw state and bound values; the active draw key for a specific block; runtime texture fallback and runtime resource views; the complete BTR admission rule, including loaded-cell readiness and ordering; final stencil and blend states; visual parity; projected sampler filtering and mip state for slots 12 and 13; other shader groups, techniques and depth-only passes beyond the enumerated records; the bake convention and live axes of the stored normals.
