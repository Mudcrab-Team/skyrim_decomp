Transfer status: UNREVIEWED

# Finding: object and tree LOD in Skyrim Special Edition

Status: OBSERVED for the verified static rules below. Runtime outcomes are unverified where stated. Static only.

Author: MR-1, a `gpt-6.2-sol` run via Codex (not the reviewer below).  
Human operator: Taylor.  
AI assistance / model: `gpt-6.2-sol` via Codex.  
Date (UTC): 2026-11-21.  
Target build id: `sse-steam-1-7-104`. The measured image SHA-256 equals the pin in [builds/target.json](../builds/target.json).  
Main function RVAs: `0x519a80`, `0x51a6e0`, `0x518070`, `0x519cf0`, `0x51b040`, `0x51b320`, `0x505970`, `0x518fa0`, `0x50b670`, `0x50c410`, and `0x1558fd0`.  
Source exposure: mixed. Local static analysis used the pinned executable, shipped INIs, locally installed preferences, and retail mesh, texture, and shader archives. Name and layout checks used the project's generated CrashLogger PDB headers. The analysis used no Mudcrab source or sibling implementation.  
Sources and immutable revisions: the pinned image and generated metadata at revision `3b2d3051afa6`. Only names and layout metadata are cited from the generated headers.  
Intended recipient: Skyrim Research department lead for boundary review. The proposed downstream use is Mudcrab's retail-facts work. The maintainer's transfer decision is pending.

Name provenance: settings come from the INIs and image. Asset block types come from serialized type names. Native type labels come from image type metadata. `distantLODMult`, `TES.currentGridX/Y`, `BGSLargeRefData`, and `BSFadeNode.currentFade` are CRASHLOGGER_PDB(59818@2026.10.24) names. The generated headers were checked at revision `3b2d3051afa6`. Descriptive function labels are GUESS.

Tags: **Verified** marks a fact re-read in the pinned local sources. **Unverified** marks a claim the trace did not establish. Addresses are virtual addresses at image base `0x140000000`. The transfer review is governed by [docs/clean-room.md](../docs/clean-room.md).

## Summary

- **Cutout path (group B).** The shipped object LOD meshes (BTOs) contain no serialized alpha property. The native object setup attaches one with alpha test enabled, blending disabled, compare code 4 and reference byte 128. Both shipped material flag sets go to batch bucket 1 with that property. Of the ten pixel records in each of Lighting techniques 13 and 15, four (key bit `0x00100000` set) discard when sampled color alpha times the material alpha factor is strictly below the uploaded reference. Six have no discard. The reference is about 0.502 (128/255) at unit shader-property alpha. Whether a live main-color draw uses a cutout key, and with what blend state, is unverified.
- **Cull state (group B).** For bucket 1, the traced grouped draw selects back-face culling when its flags leave mask `0x108` clear. The material-driven route selects the same state for the shipped bit-36 setting under that mask condition. The actual draw flags and the last rasterizer write at a live main-color BTO draw are unverified.
- **Distance rule (group A).** Squared XY distance to node rectangles, with strict comparisons. Compiled values (equal to High) are 35000, 70000 and 250000 world units. Ordinary object selection has no fixed radius in cells or blocks.
- **Blocks and tree billboards (groups C and D).** Shipped BTOs are 4, 8 and 16 cells wide (none at 32). Large-reference data filters segments inside ordinary BTOs. Tree LOD uses a list-indexed atlas and fixed crossed quads, with a conditional 4 × 4 stipple fade.

## Question and method
Which distances, render states, block keys, and tree billboard rules does this retail build use? Static checks read the native settings, loaders, traversal and render paths, scanned shipped assets, and decoded selected shaders. Installed preferences record one local configuration.

## Observations

### A. Object LOD distance and handover

**A1 — Verified.** These settings in `[TerrainManager]` are linear distances in world units. The locally installed preferences match High for all three.

| Setting | Compiled | Low.ini | Medium.ini | High.ini | Ultra.ini |
|---|---:|---:|---:|---:|---:|
| `fBlockLevel0Distance` | 35000 | 15000 | 20000 | 35000 | 60000 |
| `fBlockLevel1Distance` | 70000 | 25000 | 32000 | 70000 | 90000 |
| `fBlockMaximumDistance` | 250000 | 100000 | 100000 | 250000 | 250000 |

The three settings are absent from `Skyrim_Default.ini`. Their compiled value fields are `0x1420b33f0`, `0x1420b3408`, and `0x1420b3420`. The cache routine at `0x140519a80` stores each value squared.

**A2 — Verified.** The traversal measures squared XY distance from its input position to the nearest point on the node's rectangle. Each axis extends from the signed origin cell to that cell plus the node width, with 4096 world units per cell. Distance is zero inside the rectangle and on its boundary. The test uses X and Y. A settings-refresh caller supplies the scene graph camera's translation. Another caller supplies a world-state position vector. Position inputs across all callers are unverified. Evidence at `0x14051a6e0–0x14051a7d1`, `0x14036ef81`, and `0x1401a66de`.

**A3 — Verified.** Let `D²` be the squared XY distance to the tested node. Let `M` be the worldspace multiplier at `+0x218` (`distantLODMult`, CRASHLOGGER_PDB(59818@2026.10.24)).

| Test | Comparison | Result of equality |
|---|---|---|
| Outer object limit | `D² < fBlockMaximumDistance²` | Out of range |
| Width-16 split toward width 8 | `D² < fBlockLevel1Distance² × M` | Coarse side of the distance test |
| Width-8 split toward width 4 | `D² < fBlockLevel0Distance² × M` | Coarse side of the distance test |

For positive `M`, the linear split distances scale by the square root of `M`. The outer limit uses the cached square directly. With High and `M = 1`, the split distances are 35000 and 70000 world units, and the outer limit is 250000. These are node-rectangle tests. A separate terrain branch uses `fSplitDistanceMult`, and large-reference overlap can affect traversal separately. Evidence at `0x1405181a7–0x1405181ae`, `0x14051828b–0x1405182be`, `0x140519d84–0x140519dc5`, and `0x140517da0`.

**A4 — Verified.** In the traced finer swap, the job attaches eligible child payloads before it requests detachment of the parent object layer. In the traced coarser swap, the job attaches the parent before it requests recursive detachment of the child object layers. The finer swap checks readiness. The outer limit can trigger detachment directly. Evidence at `0x14051b076–0x14051b08e`, `0x14051b0ba`, `0x14051b12c`, `0x14051b335`, `0x14051b391`, and `0x1405181c4`.

**A5 — Limits.** The two examined distance paths use the same split values. The traced swap jobs contain a readiness check and attach/detach calls. A separate hysteresis margin elsewhere, visible overlap, fade, and the time from threshold crossing to a rendered swap are unverified.

**Confidence: high** for the settings, distance rules, and call ordering. A runtime render-submission trace would establish frame timing.

### B. Object LOD shader and material

**B1 — Verified.** The 1078 shipped BTOs contain 2392 `BSSubIndexTriShape` geometry blocks and 2392 `BSLightingShaderProperty` records. The shader properties all have serialized type 0. The archive scan found zero serialized `NiAlphaProperty` blocks. The traced native setup attaches an alpha property with test enabled, blending disabled, compare code 4, and reference byte 128. The geometry attach path stores it in the field used by batch classification. Evidence at `0x140505b65–0x140505b96`, virtual slot `+0x138` at `0x141a70f88`, and `0x14026d430`.

**B2 — Verified.** Both material flag sets have lower flags `0x80400000`. The upper flags distinguish the two ordinary Lighting techniques on the standard selector path.

| Upper flags | Properties | Technique on the standard selector path | Batch bucket with the attached alpha property and these flags |
|---|---:|---|---:|
| `0x00000005` | 1583 | 13 (`LODOBJECTS`) | 1 |
| `0x80000021` | 809 | 15 (`LODOBJECTSHD`) | 1 |

The selector reads runtime flags and has context-dependent paths. Batch registration reads the runtime Lighting flags and the alpha property. Both shipped flag sets clear combined bits 36 and 54. An enabled alpha test puts these combinations in bucket 1. Evidence at `0x141518860`, `0x1414e7390–0x1414e73df`, `0x14151a1f5`, `0x14151ab52–0x14151ab58`, `0x14151ad44–0x14151ad61`, and `0x141560d39–0x141560d86`.

**B3 — Verified for the traced draw rule.** Both material sets select **back-face culling** in bucket 1 when the grouped draw's flags leave mask `0x108` clear. The normal accumulator path reaches grouped drawing and forwards its draw flags. The material-driven path also selects back-face culling for the shipped bit-36 setting under that mask condition. The native rasterizer table maps selector 0 to no culling, 1 to back-face culling, and 2 to front-face culling. Evidence at `0x14151ee90`, `0x14151ef40`, `0x141521274–0x141521289`, `0x14155fa5b`, `0x141560108`, `0x14155dfef–0x14155e023`, and `0x14102b753–0x14102b787`. Rasterizer bind paths include `0x14100a291–0x14100a2c0` and `0x14101102b–0x14101105a`.

**B4 — Verified for the examined pixel variants.** Lighting group 6 in `shadersfx/shaders011.fxp` contains ten pixel records for each of techniques 13 and 15. For each technique, four keys with bit `0x00100000` discard when sampled color alpha multiplied by the shader's material alpha factor is strictly below the uploaded reference. Equality passes. The other six keys contain no discard. The pass builder uses the runtime alpha property and pass context when setting the cutout key bit. The Lighting key translation preserves that bit. Evidence at `0x14151a5b4–0x14151a5ea`, `0x14151aa7f–0x14151aa9e`, `0x141547d20`, and `0x1415896d0`. Representative shader records `0x0d100001` and `0x0f100001` start at package byte offsets 49505000 and 50491912.

| Pixel variant, in either technique | Shader alpha discard |
|---|---|
| Key bit `0x00100000` set | Strict cutout test |
| Key bit `0x00100000` clear | No discard in the examined records |

**B5 — Verified reference calculation.** The per-pass calculation truncates the product of reference byte and shader-property alpha, then normalizes it to a 0–1 reference. At unit shader-property alpha the reference is approximately 0.502 (128/255). The shader applies a separate factor to sampled alpha. A separate native state branch applies when shader-property alpha is below one. Evidence at `0x141578930–0x14157896f`, `0x141578ad0`, `0x1415622eb`, and `0x141011178–0x1410111c0`.

**Confidence: high** for the property, conditional cull rule, and shader variants. The actual draw flags, registered bucket, last rasterizer selector, and bound rasterizer descriptor at a live main-color BTO draw are unverified. The live pixel key, blend descriptor, reference and material alpha factor determine whether that draw applies the cutout test and what samples it keeps.

### C. Object blocks and large references

**C1 — Verified.** Object LOD uses a quadtree over exterior cells. Each cell is 4096 world units wide. A split produces four half-width quadrant nodes. A BTO key contains the worldspace, width in cells, and signed origin cell X and Y. The logical path is `Data/Meshes/Terrain/<world>/Objects/<world>.<width>.<x>.<y>.BTO`. Evidence at `0x140519b54–0x140519be5`, `0x140504da0`, `0x140504f90`, and `0x14051cab0`.

| Width in cells | Width in world units | Shipped BTOs in the scanned mesh archives |
|---|---:|---:|
| 4 | 16384 | 744 |
| 8 | 32768 | 248 |
| 16 | 65536 | 86 |
| 32 | 131072 | 0 |

**C2 — Verified.** The twelve shipped `LODSettings/<world>.LOD` records are 16 bytes each. They contain two signed 16-bit origin coordinates and three 32-bit widths. These widths describe the root, minimum node width, and maximum LOD width. The initializer sets the object and tree minimum widths to 4 separately. Evidence at `0x14051cd40–0x14051ce08` and `0x1405159cb–0x140515a0b`.

| Worldspace | Origin X, Y | Root width | Minimum width | Maximum width |
|---|---|---:|---:|---:|
| Tamriel | -96, -96 | 256 | 4 | 32 |
| DLC2SolstheimWorld | -64, -64 | 256 | 4 | 32 |
| DLC01FalmerValley | -16, -13 | 32 | 4 | 32 |

**C3 — Verified.** The ordinary object distance rule in §A uses world-unit distances to node rectangles. No fixed radius in cells or blocks appears in that rule. Near and large-reference grid tests operate separately. Both grids are centered on the current grid cell (`TES.currentGridX/Y`, CRASHLOGGER_PDB(59818@2026.10.24)). For a grid of `N` cells on each axis, the grid extends from `center − floor(N/2)` to that boundary plus `N`. Endpoint equality counts as overlap in both grid tests. Evidence at `0x140519ab0–0x140519aea`, `0x140517afb–0x140517ba1`, and `0x140518950–0x140518a11`.

The compiled `uGridsToLoad` is 5. The compiled `uLargeRefLODGridSize` is 9. The shipped Low through Ultra presets use 5, 7, 9, and 11 for the large-reference grid. Their center-to-outer-cell offsets are 2, 3, 4, and 5 cells per axis. The near default offset is 2 cells. Evidence at `0x142079eb0` and `0x14207b628`.

**C4 — Verified.** Of the scanned BTOs, 721 carry `BSDistantObjectLargeRefExtraData`. The two grid overlaps set separate node flags. On an existing object payload, the traced path uses those flags and the extra data to filter cell-local geometry segments. The segment lookup packs cell X in the upper 16 bits and cell Y in the lower 16 bits. The filter checks loaded cell state and per-worldspace data (`BGSLargeRefData`, CRASHLOGGER_PDB(59818@2026.10.24)). Evidence at `0x140517b4b–0x140517c4a`, `0x140518fa0`, `0x14051907e–0x14051922c`, and `0x140ff6800–0x140ff6850`.

**Confidence: high** for block widths, asset keys, grid tests, and the segment-filter path. The full-reference takeover conditions, plugin record import into the runtime tables, and draw timing are unverified.

### D. Tree LOD billboards

**D1 — Verified.** Tree LOD uses width-4 BTT blocks, a per-worldspace LST list, and a per-worldspace DDS atlas. The strict load gate compares squared XY node distance with `fTreeLoadDistance²`. The compiled linear distance is 75000 world units. Low ships 12500. Medium, High, and Ultra ship 75000. The setting is absent from `Skyrim_Default.ini`. The locally installed preferences match High for this setting. Evidence at `0x140518427–0x140518440`, `0x1420b3438`, and `0x14051cb50–0x14051cbc0`.

**D2 — Verified.** An LST has a four-byte count followed by 32 bytes per entry. The BTT group type is a zero-based index into the worldspace's list. The selected entry supplies width, height, and UV rectangle coordinates. The loader checks the index against the entry count. Tamriel's rectangles vary in width and placement within the atlas. Evidence at `0x14050acd0`, `0x14050b670–0x14050b85f`, `0x14050b8b0`, and `0x14050c4fc–0x14050c5ad`.

| Worldspace list | Entries |
|---|---:|
| Tamriel | 34 |
| DLC2SolstheimWorld | 36 |
| DLC1HunterHQWorld | 13 |
| DLC01FalmerValley | 8 |
| DeepwoodRedoubtWorld | 5 |
| SkuldafnWorld | 9 |
| Sovngarde | 15 |
| DLC01SoulCairn | 0 |
| DLC2ApocryphaWorld | 0 |

All seven nonempty lists have 1024 × 1024 atlases in the shipped texture archives. The Solstheim DDS header specifies DXT5 (BC3) and 11 mip levels. The other six headers specify 32-bit uncompressed BGRA and 10 mip levels.

**D3 — Verified.** Each instance uses two upright perpendicular quads with the same UV rectangle. The quads extend half the listed width to each side and from zero to the listed height. Stored world X and Y become block-local positions using the block origin and 4096 units per cell. Stored Z is carried through. The runtime packs translation, scale and angle components for the vertex shader. All four examined tree vertex variants use the fixed crossed geometry and rotate it by the instance's stored angle. Evidence at `0x14050b79f–0x14050b85f`, `0x14050c4fc–0x14050c63b`, and `0x14050c7d1–0x14050c851` and in the four group 1 vertex records. The census found 386 BTTs. All parsed group keys are in range. Six BTTs contain bytes after the parser's declared records. Their role is unverified. One parsed instance is outside its filename's cell rectangle.

**D4 — Verified for the examined shader variants.** The tree shader occupies group 1. Native tree setup enables alpha test with compare code 4 and reference byte 128. This alpha property disables blending. Keys `1`, `0x10000`, and `0x10001` discard for sampled atlas alpha strictly below the shader reference. Key `0` has no discard. Keys `1` and `0x10001` also use a repeating 4 × 4 screen-space threshold pattern. Evidence at `0x1414ea81d`, `0x141558fd0`, and `0x14050c33f–0x14050c379`, and in the four group 1 pixel records.

The instance fade starts at 1. With `bEnableStippleFade` enabled and a resolved node of the checked fade-node type, the traced near-grid update uses `1 − BSFadeNode.currentFade` (CRASHLOGGER_PDB(59818@2026.10.24)). The compiled default for that setting is 1. The coverage shader uses fade `F`, an input weight `W`, and threshold `T` from the screen pattern. For nonnegative screen coordinates, the table index is `4 × (trunc(screenX) mod 4) + (trunc(screenY) mod 4)`. The test discards when `F + W × (0.5 − T) − 0.5 < 0`. The traced upload supplies `W = −1`. For that weight the test is algebraically equivalent to `F + T − 1 < 0`. Lowering `F` reduces or preserves coverage for this test. At `F = 1`, the stipple test keeps every sample. The atlas alpha test still applies. Evidence at `0x14050b821–0x14050b826`, `0x140518564–0x140518571`, `0x14050be1c–0x14050beb1`, `0x14050c7a5`, `0x14050c85f–0x14050c872`, and `0x1420d6cd0`.

**Confidence: high** for atlas data, fixed crossed geometry, and conditional shader rules. The active pass for each instance, timing of the visible handover, and complementary coverage with full-reference geometry are unverified.

## Negative results and limits

The results describe static code and shipped assets for the pinned build. Runtime frame ordering, visual overlap, and timing are unverified. The installed preferences are one local configuration. This finding is not match evidence for any function. Keep listings and other game-derived material in `.local/`. None is published here.

## Independent review (2026-11-21)

Reviewer: GPT 6.2 Sol (`gpt-6.2-sol`) through Codex, high effort, fresh context, separate run. The reviewer did not author or draft this finding. The review was arranged by the skyrim-research department lead (Claude Sonnet 5.5), which also did not draft the finding. Date: 2026-11-21.
Source reviewed: the draft of this finding, against the pinned image `sse-steam-1-7-104` (measured SHA-256 equals the pin in [builds/target.json](../builds/target.json)), its native listing, the retail shader and asset archives, and the generated CrashLogger metadata at `3b2d3051afa6`. Exposure of the review: mixed (retail executable and its native listing, shipped assets, generated metadata, the draft). No Mudcrab source or sibling implementation was used. Method: the reviewer re-derived conditions and data dependencies from the native code, parsed the shipped archives and decoded the relevant shader records independently. This is a static finding review. It is not match evidence for any function. It does not decide transfer eligibility (`docs/clean-room.md`).

The observations above already include the corrected text.

| Group | Verdict | One-line status |
|---|---|---|
| A. Object LOD distance and handover | Confirmed | Compiled defaults, preset values, strict squared XY tests, worldspace scaling and attach-before-detach order agree. Visible handover remains unverified. |
| B. Object LOD shader and material | Corrected | Both stock flag sets enter alpha-test bucket 1 with the attached property. The grouped draw selects back-face culling when its `0x108` mask is clear. Cutout varies by pixel key. |
| C. Object blocks and large references | Confirmed | Shipped BTO widths are 4, 8 and 16 cells. The traced ordinary distance rule has no fixed block radius. Large-reference filtering acts on segments within BTOs. |
| D. Tree LOD billboards | Confirmed | Atlas indexing and fixed crossed quads agree. Two pixel variants apply the 4 × 4 stipple with conditional fade input. Full-reference handover remains unverified. |

Summary: 3 groups confirmed, 1 corrected, 0 rejected.

## Reviewer and outcome

Reviewed independently on 2026-11-21 by GPT 6.2 Sol (Codex, high effort, fresh context), separate from author MR-1. Outcome: 3 confirmed, 1 corrected, 0 rejected. Static only. A review verdict is not match evidence, and transfer eligibility is not decided. Unverified: the live main-draw rasterizer, shader and blend bindings; visible handover timing; full-reference takeover; frame overlap, fade and hysteresis.
