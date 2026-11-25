Transfer status: UNREVIEWED

# Finding: how distant tree LOD (BTT, LST and atlas) is drawn in Skyrim Special Edition

## Answer

Question 1: which shader and vertex data draw the distant trees? Question 2: which blocks draw, and at what distance? Question 3: how are trees lit and fogged? Question 4: how are the texture, alpha test and sampler set? All four answers are static and independently reviewed once. The table below states each answer and its tag.

| Question | Answer | Tag, confidence |
|---|---|---|
| 1a. Which shader draws trees? | The `DistantTree` shader, not a Lighting technique. Technique `0x5c00002e` (`BSSM_DISTANTTREE`) is the colour pass. Its shader keys are `0` or `0x10000`. Technique `0x5c00002f` (`BSSM_DISTANTTREE_DEPTH`) is a coverage and depth variant. Its shader keys are `1` or `0x10001`. The main accumulator (mode 0) selects `0x5c00002e`. Accumulator modes `0xc` to `0xf` select `0x5c00002f`. | Verified, high (G01, G02) |
| 1b. Vertex layout | A static mesh of 8 vertices: two upright quads that cross at right angles (`POSITION` float3, `TEXCOORD0` float2). Each instance has 16 half-floats (32 bytes): `TEXCOORD4 = (x, y, z, scale)` and `TEXCOORD5 = (cos θ, sin θ, fade, −1)`. `TEXCOORD6` and `TEXCOORD7` are zero. One shape holds at most 75 instances. | Verified, high for the packing. Medium for the element formats (G03) |
| 1c. Facing | **Yaw about the vertical (Z) axis only.** The VS rotates the scaled quad by the stored angle and adds the instance position. It has no camera-based basis. The tree does not face the camera. | Verified, high (G03) |
| 2a. Which block draws trees? | Width-4 BTT blocks only (4 cells by 4 cells). A block loads when the squared XY distance to its rectangle is strictly below `fTreeLoadDistance²`. It unloads when the same test fails. | Verified, high (G04) |
| 2b. Settings | `fTreeLoadDistance`: compiled 75000. Presets: Low 12500. Medium, High and Ultra 75000. `Skyrim_Default.ini` has no entry. `fTreesMidLODSwitchDist`: compiled 3600. `Skyrim_Default.ini` 9999999. The BTT tree code (`0x50a000–0x51cc00`) has no direct reader of it. Its three direct readers (`0x43e41e`, `0x43e42e`, `0x43e5ee`) belong to a manager that tests child nodes against the `NiSwitchNode` type record. The consumers of the two derived fields (square at manager `+0x80`, `(1 − value) / n` at node `+0x170`) were not traced. | Verified, high (load distance and values). **Inferred, medium** (reader class) (G04) |
| 2c. Fade and handover | The tree shader and the refresh code have no distance term. The fade is a 4 × 4 screen-space stipple on the instance fade `F`. The stipple discard is in the pixel records for keys `1` and `0x10001` only. The colour records have none. With `bEnableStippleFade` set (compiled default 1), and when a byte read through the reference's render data equals 7, `F = 1 − currentFade` of the reference's fade node. The instance is hidden (scale 0) when `F ≤ 0` or for two reference flags. The refresh runs only for blocks whose node overlaps the near-grid square (side `uGridsToLoad`, centred on the current grid cell), and only while the block is flagged dirty. The dirty flag is set when the shapes of a block are first built and by the marker `0x516750`. The roles of that marker's callers are unverified. | Verified for the rules, medium-high. Timing and the meaning of 7 unverified (G05) |
| 3a. Lighting | PS colour = atlas RGB × (`s` × sun diffuse + ambient). `s` is the z component of the negated, normalised stored direction of the scene light (−dir.z, no clamp). The vertex shader passes it to the pixel shader as a constant per draw. Reading −dir.z as the sine of the sun height is an **interpretation**. Diffuse, ambient and direction are raw `NiLight` fields of the scene sun light. The tree setup reads no SunlightScale, no light fade and no `k`. | Verified, high. The field identity (ambient `+0x110`, diffuse `+0x11c`, direction `+0x140`) is verified via #1059 (grass paragraph) and re-read here (G06) |
| 3b. Fog | **The tree VS and PS apply no fog.** The setup writes fog constants, but no tree record reads them. The tree pass is category 7 (group list 1). It is drawn in the first accumulator stage, which runs before the SAO and fog composite (stage order from #1061). Whether the composite covers tree pixels needs the tree colour pass to write the depth texture that the composite reads. That write was not verified. | Fog absence verified, high. Stage order inherited. Composite coverage unverified (G07) |
| 4a. UV | Per type from the LST entry: a rectangle `(u0, v0, u1, v1)`. Left vertices use `u0`, right `u1`, top `v0`, bottom `v1`. Both crossed quads use the same rectangle. | Verified, high (G03) |
| 4b. Alpha test | The PS discards when atlas alpha minus `cb11[0].x` is below 0 (keys `1`, `0x10000`, `0x10001`; equality passes). Key `0` has no discard. `cb11[0].x` is the global alpha reference of the renderer when the alpha-test enable byte (`0x20cfcb4`) is set. Otherwise it is 0. The tree shapes carry an alpha property with threshold byte 128. The generic pass code stores `trunc(threshold × property alpha) / 255` (0.502 at property alpha 1). The pass code takes that branch under a flag test whose value for the tree shader was not traced. | **Verified for the shaders. Medium for the constant at the draw** (G08) |
| 4c. Mip and sampler | Slot 0, clamp on U, V and W. The tree setup sets no filter. The renderer-init default for slot 0 is the anisotropic filter (D3D11 `0x55`, max anisotropy 16, mip bias 0, full mip range). Whether an earlier technique leaves another filter is unverified. | Inferred, low-medium (G08) |

## Evidence record

| Item | Evidence record |
|---|---|
| Status | OBSERVED for verified claims. Inferred and unverified claims are marked. Static only. No runtime trace. No visual result is claimed. |
| Author | A research run of `claude-sonnet-5-5` (Claude Sonnet 5.5), department task for Mudcrab item 22. It is not the reviewer below. |
| Human operator | Taylor. |
| Reviewer | A separate fresh-context run of `claude-sonnet-5-5`. A Sol run was not available because of a usage limit. See "Independent review". |
| Date | 2026-11-24 CST. The author ran from 06:34 to 06:58. The independent review started at 06:58, paused for a usage limit, resumed at 13:04 and ended at about 13:21. A third Sonnet run applied the review corrections from 13:21 and re-read items in the pinned image. |
| Build | `sse-steam-1-7-104`, retail `1.7.104.0`, Steam build 24914197. Executable SHA-256 `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f` equals the asserted pin in [builds/target.json](../builds/target.json). It was measured with `shasum -a 256`. The analysis helper of each run asserted the hash. |
| Principal function RVAs | `0x1558ed0` (tree shader constructor), `0x1558fd0` (technique setup, vtable slot 2), `0x1559470` (per-geometry setup), `0x1558cc0` (tree property `GetRenderPasses`), `0x1558dd0` (`GetRenderDepthPass`), `0x50b2b0` (tree shape builder), `0x50b670` (BTT group reader), `0x50acd0` (instance add), `0x50c410` (crossed quad builder), `0x50c6d0` (instance packer), `0x50bc80` (instance fade and hide refresh), `0x50bc00` (instance buffer re-pack), `0x5183c0` (tree tier update for one node), `0x517aa0` (node traversal), `0x516750` (block dirty marker), `0x50c100` (LST and atlas open), `0x43e330` and `0x43e4f0` (readers of `fTreesMidLODSwitchDist`). Function labels are GUESS unless the name provenance row says otherwise. |
| Sources and revisions | The operator's pinned executable. `Skyrim - Shaders.bsa` SHA-256 `fd1ba630f443353ed21ed4ca0380968f9c7091c8434518ea3cc79bc6d38c18e7`. Member `shaders011.fxp` SHA-256 `72cfc73eb0938d5949f0b3a8683722a33b671a34b41b750ba138de8d154c5fbc`. The shipped `Skyrim_Default.ini`, `Low.ini`, `Medium.ini`, `High.ini` and `Ultra.ini`. Published layouts and names from the generated CrashLogger PDB files on `origin/main`. Earlier published findings #675, #816, #948, #1059, #1061 and #1077. |
| Source exposure | Mixed. Pinned native binary analysis, shipped shader bytecode decoded locally, shipped INI files, earlier published findings and public generated layouts. No value read from a game plugin appears in this file. No downstream or sibling implementation source was used. No raw listing, bytecode or recovered implementation is quoted here. |
| Name provenance | `BSDistantTreeShader`, `BSDistantTreeShaderProperty`, `NiSwitchNode` and the shader name `DistantTree` come from RTTI or strings in the image. The technique names `BSSM_DISTANTTREE` and `BSSM_DISTANTTREE_DEPTH` come from the technique-name table in the image (`0x14eb6a0`; strings `0x1b31390`, `0x1b313a8`). `BSDistantTreeShaderProperty::GetRenderPasses`, `::GetRenderDepthPass`, `BSDistantTreeShader::ctor`, `BGSDistantTreeBlock::UpdateShaderProperties`, `RenderDepth` and `PrepareMainDepthPrepass` carry CRASHLOGGER_PDB(59818@2026.10.24). All other function and field names are GUESS. |
| Intended recipient | Skyrim Research department lead for boundary review under [docs/clean-room.md](../docs/clean-room.md). Proposed use is Mudcrab item 22. Maintainer transfer decision is pending. |

Addresses are RVAs for image base `0x140000000`. Add the base for a VA. **Verified** means re-read in the pinned image or in a shader record, with the address cited. **Inferred** means a deduction with stated assumptions. **Unverified** means the claim was not read or cannot be resolved statically. `cbN[i]` is constant buffer N, float4 element i. VS and PS mean vertex and pixel shader. The document contains facts and formulas only. Any transfer needs the boundary review in `docs/clean-room.md`.

## Question and method

How does retail draw distant tree LOD? The author decoded the four vertex and four pixel records of the tree shader. The author read the native setup of the tree shader, the pass selection of the tree property, the BTT reader, the instance packer, the tier update for one node and the instance fade refresh. The author also read the sampler constructor and the default slot states of the renderer. The author re-read the compiled defaults and the shipped INIs. The stage order of the first and second accumulator stage comes from #1061 and #1077.

## Observations

### G01. Technique, shader keys and pass selection

**Verified, high.** The constructor `0x1558ed0` builds the shader named `DistantTree` (string at `0x1b48f10`). It stores `this` in the global at `0x3486710` and uses vtable `0x1b48e98`. The technique-name table (`0x14eb6a0`) names id `0x5c00002e` `BSSM_DISTANTTREE` and id `0x5c00002f` `BSSM_DISTANTTREE_DEPTH` (strings `0x1b31390`, `0x1b313a8`). The shader file holds the four key variants as group 1. This identification rests on the key set, the decoded records and the constructor order in #1077 (positions inferred there). A traced group-index lookup was not done.

**Verified.** The accumulator registration routine calls the `GetRenderPasses` of the property (`0x1558cc0`) with the accumulator mode `[acc+0x150]` as its third argument (call at `0x151e5c0`, mode read at `0x151e5b3`). The function maps the mode to a technique:

| Mode (`r8`) | Result | Evidence |
|---|---|---|
| `0x10`, `0x11` | no pass for this property | `0x1558cca–0x1558cdb` |
| `0x1a`, `0x1b` | tail jump to a generic pass builder `0x14e7dd0` | `0x1558ce6–0x1558cf9` |
| `0xc` to `0xf` | technique id `0x5c00002f`, pass slot at property `+0xa0` | `0x1558cfe–0x1558d1a`, `0x1558d64` |
| all other modes, including the main accumulator mode 0 | technique id `0x5c00002e`, slot at property `+0x40` | `0x1558d88` |

Both techniques create the pass with category byte 7 (`0x1558d95`). `GetRenderDepthPass` (`0x1558dd0`) lazily builds the `0x5c00002f` pass at property `+0x98`. No direct caller of that slot was found in the render code.

**Verified.** The setup (`0x1558fd0`) turns the technique id into a shader key. Id `0x5c00002e` gives key 0. Id `0x5c00002f` gives key 1. Any other id gives key 0. If the byte at `0x3336405` is nonzero, bit 16 is added (`0x1558fef–0x155900b`, helper `0x1559660`). The vertex and the pixel record use the same key (`0x158dd00` and `0x158dd10` return their input). The setup returns false if either record is missing (`0x1559120`). It restores nothing (the restore slot is a bare return).

**Verified.** The byte `0x3336405` is the console toggle "Early Z" (`ToggleEarlyZ` handler `0x3802b0`, message string `0x1844120`). Its file value is 0. The function at `0x6e4c20` stores 1 at `0x6e4d16` and 0 at `0x6e4dca` around a block of render-target calls. The `1` window contains the interface-start hook (`0x116ac80`) and no call into the world draw. The UI 3D scene function saves and restores the byte (`0x989be9`, `0x98a060`). The first-stage finish routine skips two depth-state writes when the byte is nonzero (`0x151ef6a`, `0x151f0a8`). **Inferred:** in an ordinary world frame the byte is 0, so the colour pass uses key 0 (no alpha discard). Writers through indexed addressing were not excluded.

**Verified.** The image holds a Z prepass. It has the console toggle `ToggleZPrepassOutput` (flag `0x20d72e8`, file value 0), the profiler names `MainZPrepass` and `ZPrePassRender`, and the PDB-named `PrepareMainDepthPrepass` (`0x1537f60`) and `RenderDepth` (`0x1538fa0`). **Unverified:** which accumulator runs with modes `0xc` to `0xf`. `Main::ctor` stores mode `0xc` in two accumulators (`0x651901`, `0x651e06`) and `0x10`, `0x16` and `0x17` in others. **Inferred (low):** the key 1 and key `0x10001` records are the Z prepass variants of the tree. This agrees with key 0 having no alpha discard.

**Confidence: high** for the mode to technique map and the key rule. **Low** for which accumulator uses which mode. A frame trace would settle it.

### G02. The eight shader records

**Verified, high.** The shader file holds four vertex and four pixel records for the tree shader. All eight were decoded and compared with the saved decoded copies. The decoded text of each record is the same as in the earlier copies. Their start offsets and sizes agree with the saved record table.

| Key | VS record start, DXBC bytes | PS record start, DXBC bytes | Notes |
|---|---|---|---|
| `0` | 2728, 1152 | 7032, 940 | Colour. The PS has no alpha discard. |
| `1` | 3924, 912 | 8052, 1016 | Coverage: stipple discard, alpha discard, writes `clip.z / clip.w`. |
| `0x10000` | 4880, 1152 | 9148, 1032 | The VS decodes to the same text as key 0. The PS adds the alpha discard. |
| `0x10001` | 6076, 912 | 10260, 1016 | Both decode to the same text as key 1. |

Bit 16 changes only the colour pixel record: it adds the alpha discard. The stipple pixel records and the vertex records are the same with and without it.

**Verified.** The outputs of the colour PS (keys `0` and `0x10000`) are: target 0 RGB = atlas RGB × tint, alpha 1. Target 1 xy = the difference of two projected positions, each divided by w, times (−0.5, +0.5). This is a motion-vector form (**inferred** role, by comparison with the Lighting PS outputs in earlier findings). Target 2 = the constant (0.5, 0.5, 0, 0). The stipple records write one target: `clip.z / clip.w` in RGB and 0 in alpha.

**Confidence: high.** The basis is decoded text and record sizes. Static only. No byte-level comparison of records is claimed.

### G03. Vertex layout, packing and facing

**Verified, high.** The VS input signature (all four records) is `POSITION0` xyz, `TEXCOORD0` xy, `TEXCOORD4` xyzw, `TEXCOORD5` (xy used by the colour records, xyzw by the stipple records), and `TEXCOORD6` and `TEXCOORD7` declared but unused. The colour VS computes, per vertex: `p = vertex.xyz × scale`, then `x' = c·p.x − s·p.y`, `y' = s·p.x + c·p.y`, `z' = p.z`. It then adds the instance position and multiplies by `cb2[0..3]`. `(c, s)` are `TEXCOORD5.xy`. `TEXCOORD0.z` is `cb0[0].z` (G06). No camera position, camera axis or view matrix enters the facing. **Result: rotation about Z by the stored angle, fixed crossed quads.** The colour VS also outputs two more projected positions (`cb2[4..7]`, `cb2[8..11]`) for the motion-vector lanes. The stipple VS outputs `clip.z` and `clip.w` and passes `TEXCOORD5.zw` on.

**Verified.** The crossed mesh builder `0x50c410` makes 8 vertices and 12 indices. Let `hw` be 0.5 × the width of the list entry and `h` its height (entry fields `+4`, `+8`). Quad A spans x ∈ [−hw, +hw] at y = 0. Quad B spans y ∈ [−hw, +hw] at x = 0. Both span z from 0 to `h`. The UV rectangle is `u0`, `v0`, `u1`, `v1` at entry `+0xc`, `+0x10`, `+0x14`, `+0x18`. Left vertices use `u0`, right `u1`, top `v0`, bottom `v1` (`0x50c4cc–0x50c5ad`). The atlas list entries are 32 bytes in the file and 40 bytes in memory (table steps at `0x50b341`, `0x50c8dd`; #675 D2).

**Verified.** The BTT instance record is 32 bytes in the file (read at `0x50b79f`): X, Y, Z floats; a float at `+0xc` that is the angle; a float at `+0x10` that is the scale; and a 32-bit word at `+0x14` whose low 24 bits are kept (a reference identifier part, G05). A byte at `+0x1c` keeps bit 0 as an initial hide flag. X and Y subtract the block origin × 4096 (`0x50b7b0–0x50b7e6`). The in-memory instance entry is 20 bytes: the reference part, half(X), half(Y), half(Z), half(angle), half(scale), half(1.0) fade, and one flag byte (`0x50b7eb–0x50b850`, `0x50aebd`).

**Verified.** The packer `0x50c6d0` writes 16 half-floats per instance (`0x50c7e0–0x50c877`). Element `[0..2]` is the position. Element `[3]` is the scale (or 0 when the hide bit applies). Element `[4]` is cos(angle). Element `[5]` is sin(angle). Element `[6]` is the fade `F`. Element `[7]` is half(−1) (constant at `0x17e2820`). Elements `[8..15]` are zero. The cosine and sine come from the CRT thunks at `0x15a98e8` and `0x15a98ee`, applied to the half-decoded angle. **Inferred:** the half-float formats of the element declaration were not decoded. They agree with the VS reading float4 inputs and the 32-byte stride.

**Verified.** One shape holds at most 75 instances. The add routine opens a new shape when the current one has 75 (`0x50ad89`, `0x50ae6a`). The packer clips to 75 (`0x50c732`). The property constructor also stores 75 at `+0x88` (`0x1558ae9`). One shape exists per tree type key and per chunk of 75.

**Verified.** The bounding values of a shape come from block half-extents × a constant at `0x18215d4` (`0x50b3d9–0x50b407`). Their use in culling was not decoded.

**Confidence: high** for the shader, the packer and the mesh. **Medium** for the element formats. A draw trace would settle the formats.

### G04. Block selection, distances and settings

**Verified, high.** The tree layer works on nodes whose width equals the config value at `[config+0x2c]`. The initializer stores 4 there as a constant (`0x515a01–0x515a0b`). The tier function `0x5183c0` compares the node width with it (`0x51841e–0x518440`). The BTT path format is `Data\Meshes\Terrain\%s\Trees\%s.%i.%i.%i.BTT` (string `0x18e34a8`). It takes the world name, the width and the two signed block coordinates. The LST format is `Data\Meshes\Terrain\%s\Trees\%s.LST` (`0x18e34d8`). The atlas format is `Data\Textures\Terrain\%s\Trees\%sTreeLOD.DDS` (`0x18e3500`).

**Verified.** The load test is `thr > D²`. `D²` is the squared XY distance to the node rectangle (`0x51a6e0`). `thr` is the cached `fTreeLoadDistance²` at `0x320357c` (squared at `0x519ae6`, stored at `0x519b08`, compared at `0x518434`). The test is strict. A node at exactly the threshold does not load. The unload branch for a node with a loaded block runs when the same test fails (`0x5185a0–0x5185fc`). **The function has no separate unload margin.** The flag argument of the function selects between this path and a detach-all path (`0x518446`). The producer of that argument is **unverified**.

**Verified.** The same updater (`0x5183c0`) also visits nodes wider than the tree width. For such a node, the within-distance test returns a split request to the caller. Outside the distance, a wider node whose state flag (node bit 10) is set releases its own tree block. It then runs the same release on its four child slots. Only width-4 nodes load a block.

**Verified.** The compiled value of `fTreeLoadDistance` is 75000 at `0x20b3438`. The shipped presets are `Low.ini` 12500, and `Medium.ini`, `High.ini` and `Ultra.ini` 75000. `Skyrim_Default.ini` has no entry. At 4096 units per cell, 75000 units is about 18.3 cells. The shipped presets have no tree-specific INI key other than `fTreeLoadDistance`. `bEnableStippleFade` is absent from every shipped INI. Its compiled default is 1 (`0x20d6cd0`).

**Verified (negative).** `fTreesMidLODSwitchDist` (setting value at `0x20d6798`, compiled 3600) has exactly three direct readers. Two are at `0x43e41e` and `0x43e42e` (manager constructor `0x43e330`, which stores the square at manager `+0x80`; called once from `0x65570e`). The third is at `0x43e5ee` (`0x43e4f0`, which computes `(1 − value) / n` into a node field at `+0x170`, where `n` is a 16-bit field of a child object). `0x43e4f0` compares the runtime type of a child with the `NiSwitchNode` type record (`0x331c670`, initializer at `0xe505e` names it `NiSwitchNode`; compare at `0x43e53b`). The BTT tree code (`0x50a000–0x51cc00`) has no direct reference to the setting. `Skyrim_Default.ini` sets it to 9999999.0000. The compiled default (3600) is not the shipped value.

**Inferred (medium).** The direct readers belong to a manager that handles `NiSwitchNode` children. The class that owns `0x43e330` is not identified. The consumers of the two derived fields were not traced. This finding makes no claim about whether or how the setting affects BTT billboards, except that the BTT tree code has no direct reader.

**Confidence: high** for the width, the distance rule and the values. **Medium** for the owner of `fTreesMidLODSwitchDist`. A search for further readers through indirect addressing was not done.

### G05. Per-instance fade, hide and refresh

**Verified, high for rules.** The refresh `0x50bc80` visits every instance of every shape in a tree block. For each instance:

1. If the resolved flag (entry bit 1) is clear, it rebuilds a form identifier from the stored 24-bit part and each load-order index in turn. The indices run from the global at `0x31f4de4` up to the smaller of `0x31f4df8` and a count at `[[0x219ded8]+0xd80]` (`0x50bd16–0x50bd99`). It looks the identifier up (`0x1e5860`) and calls a form slot `+0x160`. It keeps the result only if the base form at `+0x40` has form-flag bit 6 set or form type `0x26` (`0x50bd76–0x50bd8a`). It sets entry bit 2 (searched). If it found a reference, it sets bit 1 and stores the full identifier (`0x50bd99–0x50bdb9`).
2. Fade defaults to 1.0 and hide to 0. If the reference exists, has a render node (form slot `+0x380`) and the node flag `+0xf4` bit 0 is clear, then two cases apply. With `bEnableStippleFade` set, when the byte at `[[ref+0x60]+0x44]` equals 7, `F = 1.0 − fadeNode.currentFade` (`+0x130` of the node returned by node slot `+0x28`). If `F ≤ 0`, hide = 1 (`0x50be1c–0x50be7d`). With `bEnableStippleFade` clear, hide = 1 when the same byte equals 7 (`0x50be7f–0x50be8c`).
3. Hide = 1 also when the form flags `0x820` (bits 5 and 11) are set on the reference (`0x50be8e–0x50be9a`).
4. The fade half goes to entry `+0xe`. A change marks the shape for re-pack (`0x50bea1–0x50beb7`). A hide change rewrites bit 0 of the flag byte (`0x50bebc–0x50becc`). A hide sets the "all visible" byte of the block (`+0x82`) to 0 (`0x50bed4`).

**Verified.** The packer zeroes the scale of an instance whose hide bit is set, unless the block byte `+0x82` is nonzero (`0x50c7c4–0x50c80e`). With `+0x82` set, the stored hide bits are ignored.

**Verified.** The tier function `0x5183c0` creates the shapes once (`0x518545`; it sets the block flag at node `+0x40` bit 13, which is the dirty flag). It calls the refresh only when node bit 14 is set (`0x518561–0x518571`). Node bit 14 means the node rectangle overlaps the near grid. The side of the near grid is `uGridsToLoad` (the value cached at `0x320358c`), centred on the current grid cell (`0x517afb–0x517b4b`). Otherwise the function writes the block byte `+0x82` = 1 (`0x518578–0x518587`). It then re-packs the instance buffers (`0x50bc00`, called at `0x51858f`) and clears the dirty bit. **For a block outside the near grid, the stored hide bits are ignored. The fade half stays at the last stored value (1.0 until a refresh changes it). No code that resets it was found.**

**Verified.** The dirty bit is also set by `0x516750`. That function takes a cell, finds the tree-level node that contains the cell centre and sets bit 13 (`0x5167f1`). Its callers include `0x1a81cf`, `0x2c1e29`, `0x2c7866`, `0x2d788b`, `0x2dbce2`, `0x2df489`, `0x2e1136`, `0x2f312f`, and `0x612fe0` through the wrapper `0x516740`. The role of each caller is **unverified**. Several PDB names near these addresses are not reliable.

**Inferred (medium).** An instance fades out while the full reference fades in, for a reference whose state byte equals 7. When the setting is off, the instance hides at once. The meaning of 7 is **unverified** (GUESS: a loaded or attached state). **Unverified:** whether anything marks the block dirty each frame during a fade, the number of frames of a handover, and the visual result. The shader side is in G02. With `F` below 1, a sample is kept when `F + T − 1 ≥ 0`. `T` is the entry `4·(x mod 4) + (y mod 4)` of a 16-value table. Its smallest value is 0.0039 and its largest is 0.996. At `F = 1` all samples pass. At `F = 0` all are discarded.

**Confidence: medium-high.** The rules are read. The trigger frequency and the byte meaning are open. A frame trace would settle the handover.

### G06. Lighting inputs of the tree shader

**Verified, high.** The colour PS formula is `rgb = atlas.rgb × (v.z × cb0[0].xyz + cb0[1].xyz)`. There is no saturate, no fog, no light fade and no `k`. `v.z` is `TEXCOORD0.z`, which the VS copies from `cb0[0].z`.

**Verified.** The setup `0x1558fd0` fetches the scene sun light as `[[0x20d68b0]+0x200]+0x48` (`0x1559215–0x1559228`). Grass uses the same chain (#1059). The setup writes these values with map-discard buffers:

| Target | Value | Evidence |
|---|---|---|
| VS `cb0[0]` | `(−dir.x, −dir.y, −dir.z, 1)`, where `dir` is the world direction of the light at light `+0x140..+0x148`, normalised. If its length is not above 1e-6, the vector is zero. | `0x1559252–0x15592b5`, `0x1559342–0x1559372` |
| PS `cb0[0]` | `(diffuse.rgb, 1)`: light `+0x11c..+0x124` | `0x1559303–0x155933d` |
| PS `cb0[1]` | `(ambient.rgb, k)`: light `+0x110..+0x118`. `k` is the global at `0x20d694c` (file value 0.8333333). | `0x15592be–0x1559300` |

**Verified.** The mapping from constant to register: the VS record loader reads the 32 header bytes into the shader object at `+0x48..+0x67` (`0x100fcb6–0x100fcd5`). Header byte `j` therefore lands at object `+0x48 + j`. The PS loader reads 64 bytes into `+0x40..+0x7f` (`0x10100a5–0x10100b2`), so byte `j` lands at `+0x40 + j`. The setup writes the light vectors at VS object `+0x57` and at PS objects `+0x40` and `+0x41`. In the tree records, VS header byte 15 is 0, and PS header bytes 0 and 1 are 0 and 4 (dword offsets). So VS `cb0[0]` and PS `cb0[0]` and `cb0[1]` are as in the table. The buffers bind as slot 0 for both stages (`0x15593d9–0x1559432`).

**Verified.** The tree PS never reads `k` (`cb0[1].w`). The `SunlightScale` pointer of the manager (`0x33d40a0`) has no load in `0x1558ed0–0x15596ff`. The light fade field (`+0x134`) is not read.

**Interpretation.** The scalar `s = −dir.z` can be read as the sine of the sun height. It is not clamped at night. The tint is the same for the whole shape and does not depend on a normal. The lighting is a raw `NiLight` sum. It is not the Lighting shader's `diffuse × fade × SunlightScale`. It matches the raw-field choice of the grass shader.

**Unverified.** If the sun light is missing, the setup skips the writes and the buffers keep undefined content (write-discard map). The runtime values of diffuse, ambient and direction (set by the sky update) were not traced.

**Confidence: high.**

### G07. Fog and the draw stage

**Verified, high.** None of the eight records reads a fog value. The VS fog inputs (written to its buffer at vectors 1 to 3 by `0x1559115–0x1559210`) are unused. The VS declares a buffer of one vector. The PS tail has no fog ramp and no blend with a fog colour. The setup reads the scene fog property (`0x14ec040`, call at `0x1559058`). It stores `(near×r, r, power, max)`, `(nearRGB, k)` and `(farRGB, 1)` into constants that no tree record reads.

**Verified.** The tree pass has category 7 (G01). The registration routine maps category 7 to group list 1 (table at `0x151e840`, entry at `0x151e6c7`). Stage order, inherited from #1061: the first accumulator stage draws group 1 after group 8 and before group 0, all at (S,T) = (1,0). The SAO and fog composite runs after the first stage (#1077, call `0x153a1ca`).

**Unverified.** Whether the composite covers tree pixels. The composite reads the depth texture. Coverage needs the tree colour pass to write that depth. The depth write was not verified.

**Confidence: high** for no own fog. **Medium** for the stage order (inherited). **Unverified** for composite coverage.

### G08. Alpha test and atlas sampling

**Verified.** The alpha property of the tree shapes is built at `0x50c2c2–0x50c37d`. The test is enabled (bit 9 set), blend is off (bit 0 cleared), the test function code is 4 (bits 10 to 12) and the threshold byte is 0x80. The property is stored in the global at `0x31f4e08` and attached to each tree shape (`0x50b4ce`).

**Verified.** In every record that discards on alpha (keys `1`, `0x10000`, `0x10001`), the PS samples the atlas and discards when `alpha − cb11[0].x < 0`. Equality passes. The stipple records read the alpha from the `w` channel. `cb11[0].x` is written at `0x1011178–0x10111c0` from the global `0x20cfcb8` when the byte `0x20cfcb4` is set. Otherwise it is 0. The batch renderer (`0x1560340`, call at `0x15605e3`) calls `0x1578930` with the pass alpha property. That function stores `trunc(threshold byte × property alpha) / 255` in the global (`0x1578930–0x157896f`). With byte 128 and alpha 1 the value is 128/255 = 0.50196. A second site stores the same value as a default (`0x151f156`). The call to `0x1578930` is on a branch guarded by a flag-byte test (`0x156058e`; the other branch calls `0x1562270`). The value of that test for the tree shader was **not traced**. This is a limit on the value at the draw.

**Inferred.** The buffer at `0x3331aa8` is the PS constant buffer 11 that the records read. The default alpha of the tree property is 1.0 (not re-read).

**Verified.** The atlas texture is loaded at `0x50c1d7–0x50c262` into the globals `0x31f4e00` and `0x3486718`. The setup binds its view into texture slot 0 (`0x155937d–0x15593bf`: texture `+0x48`, resource `+0x10`). It sets the slot 0 address enum to 0 (`0x15593bf–0x15593d9`; global `0x20cfcbc`). **It does not write the slot 0 filter enum** (global `0x20cfcfc`; no write in `0x1558ed0–0x15596ff`).

**Verified.** The sampler constructor `0x102b910` builds 6 address modes × 5 filter modes. Address enums: 0 = clamp on U, V and W; 1 = clamp U, wrap V; 2 = wrap U, clamp V; 3 = wrap all; 4 = border; 5 = mirror (`0x102b988–0x102ba0d`). Filter enums: 0 = point (D3D11 `0`, max LOD 0); 1 = `0x14` (linear min and mag, point mip, max LOD 0); 2 = `0x15` (trilinear, full range); 3 = `0x55` (anisotropic, max anisotropy 16, full range); 4 = `0x94` (comparison, anisotropy 16). Mip bias is 0 and minimum LOD is −FLT_MAX in all (`0x102b92b`, `0x102b945`). Renderer init sets slot 0 to address 0 and filter 3 (`0x1007ff0–0x100804d`).

**Inferred, low-medium.** Take the init state as the slot 0 state when the tree draws. Then the atlas is sampled with clamp and 16× anisotropic filtering over all mips (10 or 11 mips, #675 D2). Other techniques set other slot 0 filters (enum 1 for terrain LOD, enum 2 for grass), and the tree does not reset it. Whether those techniques restore the default is **unverified**. If filter 1 were left, only the top mip would be sampled. `fMipBias:Display` (compiled 0) is not an input to this sampler.

**Confidence: high** for the alpha rule in the shaders and the clamp. **Medium** for the alpha reference at the draw. **Low-medium** for the effective filter. A device trace would settle both.

### G09. Corrections to earlier findings

**Scope: `findings/exterior-hdr-path-retail-facts.md` (#1059) and `findings/exterior-haze-trace-retail-facts.md` (#1077).** Both findings need a correction only where they state or imply that the light and fog inputs of the tree shader are untraced. This pull request adds a dated amendment paragraph to each file. The amendments change no other row and no arithmetic.

| Earlier statement | Correction | Tag |
|---|---|---|
| #1059 row 3, the G09 prose and the open list: the sun source of the distant-tree shader is unverified, and "A scan of the distant-tree shader range found no light-colour read." | The tree setup `0x1558fd0` reads the scene sun light's ambient (`+0x110`), diffuse (`+0x11c`) and world direction (`+0x140`) at `0x1559252–0x155933d`. The light is the same one that grass uses (`[[0x20d68b0]+0x200]+0x48`). The setup uses raw fields. It reads no SunlightScale and no fade. | Verified, high |
| #1077 G07 prose: the group 1 pixel record "multiplies albedo by `cb0[0] × v.z + cb0[1]`, a vertex-driven tint that may carry fog. Its constants were not traced." Also: distant tree shaders "were not shown to add or to omit fog." | The tint is not fog. `v.z` is the z component of the negated, normalised light direction. `cb0[0]` is the sun diffuse and `cb0[1]` the ambient. The tree records contain no fog. The fog constants that the setup writes are not read by any tree record. | Verified, high |
| #1077 row at `0x1559058`: "`BSDistantTreeShader` virtual slot 2. Reads the property. Details not decoded." | The function reads the scene fog property and writes the three standard fog vectors. The tree VS and PS do not use them. It also reads the scene sun light and writes the light constants that the PS uses. | Verified, high |

## Interpretation and alternatives

- The tree billboard is a cheap crossed-quad impostor. It has a fixed yaw per instance and does not turn to the camera. Both quads are always present.
- Tree LOD lighting is a flat colour per draw. The value is the same for every vertex and pixel of a shape. It changes only with the sun direction and the two raw light colours.
- The handover is a stipple coverage fade per instance. The refresh runs only for blocks that overlap the near grid. Far blocks are not refreshed. Their hide bits are ignored. Their fade keeps the last stored value.
- Key bit 16 adds the alpha discard to the colour pixel record only. The state-value meanings in `0x151ef6a–0x151f0d6` were not decoded.
- A second, unseen reader of `fTreesMidLODSwitchDist` through indirect addressing is possible. The setting object has direct readers only at the three sites in G04.

## Relation to earlier findings

- **#675** (object and tree LOD, D1 to D4): this finding agrees on the crossed quads and the UV rectangle, the 4 × 4 stipple formula `F + T − 1`, the keys `0`, `1`, `0x10000` and `0x10001`, the alpha test code 4 with reference 128, and the load-distance rule. No error was found in D1 to D4. This finding adds the hide rule, the 75-instance chunk, the gating of the refresh by the near grid, the dirty marker, the lighting inputs and the fog absence.
- **#816** (object LOD segment order): it has no text about tree drawing. This finding gives no correction to #816.
- **#948** (object LOD normal atlases): it names tree LOD only as out of scope and defers to #675. This finding gives no correction to #948.
- **#1061** (frame flags): this finding inherits its stage order (group 1 after group 8 and before group 0 in the first stage). It gives no correction to #1061.
- **#1059** (HDR path and SunlightScale reach): this finding resolves its open item on the distant-tree sun source. A scoped amendment is added to #1059 in this pull request.
- **#1077** (haze trace): this finding resolves its open items on distant-tree fog and the group 1 tint. A scoped amendment is added to #1077 in this pull request.

Published corrections stay in force.

## Negative results and limitations

- **Unverified.** All statements are static. There is no frame, trace or screenshot. No visual result is claimed.
- **Unverified.** The effective slot 0 filter at the tree draw. The filter global has no write in the tree code, and other techniques set other filters.
- **Unverified.** Which accumulator runs modes `0xc` to `0xf`, and so which pass uses key 1 and key `0x10001`.
- **Unverified.** The depth write of the tree colour pass, and so the composite coverage of tree pixels.
- **Unverified.** The number of frames of a handover, the meaning of the byte value 7, whether anything marks a block dirty during a fade, and the purpose of the bit 0 hide flag in the BTT record.
- **Unverified.** The value of the flag-byte test that guards the alpha-reference path for the tree shader, and so the value of `cb11[0].x` at the tree draw.
- **Unverified.** The consumers of the two fields derived from `fTreesMidLODSwitchDist` (manager `+0x80`, node `+0x170`), and any indirect reader of the setting.
- **Unverified.** The element formats of the instance stream, the producer of the flag argument of the tier function, and the runtime mip range of the DDS view.
- The tree shaders were decoded for the four ordinary variants. Other shader groups can draw tree-like geometry. This finding does not cover them.
- No game plugin value is used. The reference identifier handling is an engine rule only.
- Archive counts and atlas formats come from #675. The BTT and LST archives were not re-scanned.
- The installed `Skyrim.ini` and `SkyrimPrefs.ini` are local files of the operator. Only `Skyrim_Default.ini` and the four presets are stated as shipped values.

## What would change confidence

A trace of one exterior frame would settle these items: the accumulator that draws each tree key, the sampler filter at the tree draw, the depth write and the composite coverage, the alpha reference at the draw, and the number of frames of a handover. A listing search for indirect readers would settle the single-reader claim for `fTreesMidLODSwitchDist`. A trace of the consumers of its derived fields would settle whether it affects BTT drawing at all.

## Group summary

| Group | Tag | Confidence |
|---|---|---|
| G01 Technique, keys, pass selection | Verified (mode map, key rule). Inferred (prepass link) | High / low |
| G02 Eight shader records | Verified | High |
| G03 Layout, packing, facing, UV | Verified | High (formats medium) |
| G04 Block selection, distances, settings | Verified. Reader class inferred | High / medium |
| G05 Instance fade, hide, refresh | Verified rules. Dirty-marker callers and meaning of byte 7 unverified | Medium-high |
| G06 Lighting inputs | Verified | High |
| G07 Fog and draw stage | Verified (no fog). Stage order inherited. Composite coverage unverified | High / medium / unverified |
| G08 Alpha and sampler | Verified (alpha in shaders, clamp). Inferred (constant at the draw, filter) | High / medium / low-medium |
| G09 Corrections to earlier findings | Verified | High |

## Independent review

Reviewer: a separate fresh-context run of `claude-sonnet-5-5`. The reviewer is not the author. A Sol run was not available because of a usage limit. The reviewer started at 06:58 CST on 2026-11-24, paused for the usage limit, resumed at 13:04 CST and ended at about 13:21 CST. It saved an independent extraction (technique ids, shader records, packing, distance rule, setting values, fade refresh, light setup and sampler state) before it read the body of the text under review. It then compared the draft claim by claim.

Verdict: **5 confirmed, 4 corrected.** The reviewer found no error in a number, an address or a formula. The four corrections changed wording where the draft said more than the evidence shows.

| Group | Verdict | Main point |
|---|---|---|
| G01 Technique, shader keys, pass selection | Confirmed | The mode map, the key rule and the technique names reproduce. One tightening of the Early-Z paragraph. |
| G02 Eight shader records | Confirmed | All eight records were decoded. Equal pairs and sizes reproduce. |
| G03 Layout, packing, facing, UV | Confirmed | Rotation about Z only, 16 halves, 75 maximum and the crossed mesh reproduce. |
| G04 Block selection, distances, settings | Corrected | "BTT tree LOD does not read it" was stated as a fact. The evidence is only the absence of a direct reader. The same updater also acts on wider nodes. |
| G05 Fade, hide, refresh | Corrected | "Every instance draws at fade 1 outside the near grid" is not shown. "Refresh needs a dirty mark from attach events" is stronger than the evidence. |
| G06 Lighting inputs | Confirmed | The formula and the constant mapping reproduce. "Direction to the sun" is an interpretation of a negated stored direction. |
| G07 Fog and draw stage | Corrected | "The composite therefore covers it" is not supported. The depth write of the tree pass is unverified. |
| G08 Alpha and sampler | Corrected | The alpha reference cell omitted two conditions: the enable byte, and a guarded branch that was not resolved. |
| G09 Correction to earlier findings | Confirmed | The quoted text of #1059 and #1077 matches `origin/main`. The reviewer found more places to amend. |

The reviewer also checked consistency with #675 (D1 to D4), #816 and #948. It found no conflict. It found no plugin-derived number in the draft.

**Re-read of corrected items.** The run that applied the corrections re-read the items below in the pinned image, in the saved listing and in the saved decodes of the shader records. It did not re-extract the records from the archive in this run. All items agree with the text.

1. The mode map and the technique ids in `GetRenderPasses` (`0x1558cca–0x1558d88`) and the category byte 7 (`0x1558d95`).
2. The key rule in the setup (`0x1558fef–0x155900b`): subtract `0x5c00002e`, map 0 to key 0 and 1 to key 1, set bit 16 when the byte at `0x3336405` is nonzero.
3. The 75-instance limit at four sites (`0x50ad89`, `0x50ae6a`, `0x50c732`, `0x1558ae9`).
4. The strict load test at `0x518434`: threshold greater than the squared distance, tested with `seta`.
5. The width constant 4 stored at `[config+0x2c]` (`0x515a01`, `0x515a0b`).
6. The compiled setting values: `fTreeLoadDistance` 75000 (`0x20b3438`), `fTreesMidLODSwitchDist` 3600 (`0x20d6798`) and `bEnableStippleFade` 1 (`0x20d6cd0`).
7. The shipped INI values: `Low.ini` 12500, `Medium.ini`, `High.ini` and `Ultra.ini` 75000, `fTreesMidLODSwitchDist` 9999999.0000 in `Skyrim_Default.ini`, and no `fTreeLoadDistance` entry in `Skyrim_Default.ini`.
8. The packer element order: position halves from entry `+4`, `+6` and `+8`, angle at `+0xa`, scale at `+0xc`, fade at `+0xe`, and the two trigonometric thunks (`0x50c7e0–0x50c877`).
9. The fade rule: the call through form slot `+0x380`, the node flag test at `+0xf4`, the setting byte test, the byte at `+0x44` compared with 7 (`0x50be1c–0x50be50`).
10. The 4 × 4 stipple rule in the key 1 pixel record: a 16-value table, the index `((x & 3) << 2) | (y & 3)` built with two bit-field inserts, and the discard when `W × (0.5 − T) + F − 0.5 < 0`. For `W = −1` this is `F + T − 1 < 0`.
11. The colour pixel formula in the key 0 record: `atlas.rgb × (v.z × cb0[0].xyz + cb0[1].xyz)` and no discard.
12. The sun light fetch chain in the setup (`0x1559215–0x1559228`).
13. The eight records: key, start offset and size agree with the saved record table. The key 1 and key `0x10001` pixel records and the key 0 and key `0x10000` vertex records are the same pairs.

Source exposure of the review: mixed. The reviewer used the local pinned executable, the shipped shader archive, the shipped INI files and generated name layouts. It did not open the game plugin. This is a static review. It is not match evidence for any function, and it does not decide transfer eligibility.

Reviewer and outcome: reviewed independently by a separate fresh-context `claude-sonnet-5-5` run. Outcome: 5 confirmed, 4 corrected, 0 rejected. Static evidence only. Transfer status: UNREVIEWED.
