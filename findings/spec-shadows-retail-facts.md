Transfer status: UNREVIEWED

# Finding: retail shadows end to end (SPEC-3)

## Answer

Static only. No game run, no frame capture and no visual claim.

| Question | Answer | Mark |
|---|---|---|
| When does the sun cast shadows? | Only when a per-frame "sun shadows off" byte is 0. The byte is 1 in an interior cell, and in a world space whose DATA flag byte has bit `0x40` or `0x20`. Then the sun cascade is not updated, culled, accumulated or drawn. | gates V2; result derived from them (I) |
| Sun maps | 2 cascades by default. `D16_UNORM` array, square, edge `iShadowMapResolution`. Orthographic fit to the camera slice. Vertex depth is clamped at the near plane. | V2 |
| Who casts into the sun maps? | World object lists without the LOD, sky and weather subtrees, plus the portal graph's always-render list, which holds the actor nodes. Blended and faded geometry does not cast. | V2 (run-time link of the graph I) |
| Raster depth bias in shadow-map draws | Ordinary casters: depth-bias mode 0 (`DepthBias` 0, slope 0). Decal casters: mode 10 (sun on) or 11 (sun off). All receiver bias is a constant in the mask shaders. | V2 |
| Local lights | Spot: one perspective map. Hemisphere: one paraboloid. Omni: two paraboloid halves in **one** array slice. No cube map. At most 4 mask channels per frame, sun included. | V2 |
| How shadows reach the frame | One screen mask (`R8G8B8A8_UNORM`). Each shadow light writes one channel with a full-screen draw. Lighting multiplies the light term by that channel. | V2 |
| Can this be implemented? | Yes for the default configuration (sun, focus maps, spot, hemisphere, omni, mask, Lighting use), with the interim implementer choices of section 14B for the points that retail evidence does not settle. Non-default filters and settings are not covered. | — |

| Evidence record | |
|---|---|
| Status | OBSERVED where V1 or V2. INFERRED where marked I. Static only. |
| Authors / human operator | Sonnet 5.5 author run, Sonnet 5.5 independent reviewer run, Sonnet 5.5 blind second binary-check run and Sonnet 5.5 finalizer run (all `claude-sonnet-5-5`, each a separate fresh context). A Sol run was not available. Operator: the Skyrim Research department lead. |
| Reviewer and outcome | The reviewer found the first draft not implementable as written and supplied corrections. The second check confirmed the cascade fit and the mask channels and corrected the caster rules. The finalizer applied both sets, re-read the points where they differed and the load-bearing facts that had one run (section 17). **The merged wording of this file had no further independent review.** |
| Date | 2026-11-26 CST. |
| Build | `sse-steam-1-7-104`, retail `1.7.104.0`, Steam build 24914197. Measured SHA-256 of `SkyrimSE.exe` `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f` equals the pin in `builds/target.json`. The read helpers assert it. |
| Shader package | `shadersfx/shaders011.fxp`, SHA-256 `72cfc73eb0938d5949f0b3a8683722a33b671a34b41b750ba138de8d154c5fbc` (group 7 is the utility group). |
| Sources and revisions | The pinned executable. Shipped shader records (utility group, grass group). The five shipped INI files: `Skyrim_Default.ini` `61c151bc60d5d737dad3d65a99a48d9bb8b50812b6b9f1f993323f0337813fa8`, `Low.ini` `f045a0165b9d09d167ea11a228401e21c517497d0a333939db0a2e9ab7a25c9b`, `Medium.ini` `e5cb56c29c28a0e57055b75bf3153c6e7d8510100f656b490fadd3b9bdffc5fe`, `High.ini` `2413dc2f7cbf4551d9c6686780dfd20664c68604cab764604e30daa648606f95`, `Ultra.ini` `10dc00f0dae7783e2f904eabf68be09e4c2460ec1edd30a6231f22b47b847000` (hashes as recorded in #1248). Published findings #806, #1052, #1073, #1248, #1258, #1268 on `main`; SPEC-1 (pull request #1274, head `76dede6056`) and SPEC-2 (pull request #1276, head `5aa64f67fd`), both open and `UNREVIEWED`. Committed CrashLogger name and layout tables. |
| Source exposure | Mixed: binary and shader analysis of the operator's own install, shipped INI text, public generated names. **No value was read from any game plugin.** No plugin world-space or form name is given. No decompiler text and no disassembly appears here. A reader of this file must not claim to be unexposed to the binary analysis. |
| Name provenance | Function names with "(PDB)" are `CRASHLOGGER_PDB(59818@2026.10.24)`. Three of those names do not fit their bodies: `0x153b680` (`CalculateAndDrawShadowCasterLights`) creates render targets; `0x1539b10` (`BSShadowParabolicLight_RenderImpl`) is the mask draw loop for all light kinds; `0x155d270` (`BSShadowParabolicLight::RenderCascade`) renders a map slice for all light kinds. All other names are GUESS. Setting names are the image's own strings. A name is not evidence of behaviour. |
| Intended recipient | Skyrim Research department lead, for boundary review under `docs/clean-room.md`. Proposed downstream use: the Mudcrab shadow implementation. Maintainer transfer decision pending. |

## Question and method

**Question.** How do retail shadows work, from the per-frame sun gate to the mask that Lighting reads?

**Method.** Static analysis only. No game run, no frame capture and no comparator run.

* The runs read the pinned executable of build `sse-steam-1-7-104` and the shipped shader package. They used local reader scripts and local disassembly, and they decoded shader records locally and offscreen. The scripts and raw output are private and stay in `.local/`.
* The utility and grass shader records, the five shipped INI files, the committed CrashLogger tables and the earlier findings are listed in the evidence record above.
* An author run wrote the draft. An independent reviewer run, with a fresh context, spot-checked claims and recomputed worked examples.
* A blind second binary-check run, with a fresh context, saved its own results before it read the draft.
* A finalizer run applied both correction sets. It re-read the points where those runs differed and load-bearing facts that had one run (section 17). It recomputed the worked examples by script.
* The amendments that this work made to other findings are listed in section 15 and in those files.

**Confidence.** The confidence of each claim is its mark. The verification ledger (section 16) has 52 rows in this version of the file:

* 42 rows are **V2** (checked twice, by two different runs).
* 8 rows are **V1** (checked once): L12, L14, L18, L25, L33, L38, L46 and L52.
* 1 row is mixed **V2 / V1**: L27.
* 1 row is **I** (inferred): L49.
* No ledger row is **U**. Section 14A lists the open items. The choices of section 14B are not retail facts.
* All the runs of this specification are `claude-sonnet-5-5`. Agreement between them is not independent proof. The finalizer did not re-read every V2 row that rests on a published finding or on an earlier run. The merged wording had no further independent review.
* Overall confidence: **medium**, as a static reading. The overall level was set on 2026-11-27, when this section was added, from the marks and limits in this file. No new binary read supports this section. Transfer status stays UNREVIEWED.

## 0. How to read this file

| Mark | Meaning |
|---|---|
| **V2** | Verified in the binary, shader bytes or shipped files by two different runs. |
| **V1** | Verified by one run only. |
| **I** | Inferred. A deduction with stated assumptions. |
| **U** | Unverified or open. |

Run keys, used in section 16: **S3** author; **V** reviewer; **K** blind second check; **F** finalizer; **M** #806; **C** #1052; **P** #1073; **R** #1248; **G** #1258; **D** #1268; **N** SPEC-1; **H** SPEC-2; **B** the run behind the 2026-11-26 amendments in pull request #1274. A claim in a formula block takes the mark of its section 16 row unless the text says otherwise.

Addresses are RVAs (image base `0x140000000`), code and data alike. `cbN[i]` is a pixel constant buffer N, float4 element i (vertex buffers are named as such). `sat(x)` limits x to [0,1]. `res` is `iShadowMapResolution`. A utility shader "record" is the group 7 shader record with that key.

### 0.1 Interfaces to SPEC-1 and SPEC-2

| This file needs | From | This file gives | To |
|---|---|---|---|
| Frame order around the shadow steps: clear, depth prepass, depth copy, **shadow mask**, first lighting stage | SPEC-2 section 1 | The content of the mask | SPEC-2 stage 1 |
| Camera depth (device depth) and the matrix from screen position and depth to camera-relative position | the renderer; retail uses pixel `cb12[32..35]` and `cb12[43..44]` | — | — |
| The Lighting sum, specular, tail and composite | SPEC-1 sections 6 to 8, SPEC-2 | The factor `ms` (sun) and `mi` (shadow lights) | SPEC-1 section 6.1 |
| Mask sample coordinates `uv14` and the rule "channel `trunc(cb2[2][i])` for the first `min(cb2[29].y, 4)` point lights" | SPEC-1 section 6.1 | `cb2[2][i]` is the mask channel index of that shadow light (section 6.2) | SPEC-1 |
| Which lights are point lights of a geometry, and their order | SPEC-1 section 2.6, #1073 | Which lights are shadow casters | SPEC-1 |

## 1. Pipeline map

Implement in this order.

| # | Stage | What happens | Address | Section | Mark |
|---|---|---|---|---|---|
| 1 | Sun gate | Write the byte "sun shadows off" for this frame | `0x657c90`, store `0x65803b`; called at `0x656f33` | 10 | V2 |
| 2 | Light queue | Process queued light adds and removes | call `0x656ff4` | 6 | V1 |
| 3 | Shadow setup | Clear the caster array. If the byte is 0: update the sun cascade cameras, set up focus maps, give the sun caster entry 0 and mask channel 0, run sun culling. Then run the local light selector. | `0x1537fd0` (call `0x657024`); selector `0x15389b0` (called at `0x1538381`) | 4, 6, 7 | steps V2; frame position V1 |
| 4 | Shadow maps | Each caster-array light renders its map slices | `0x1538430` (call `0x65716a`) | 5 | V1 for the frame position |
| 5 | Depth prepass, focus stencil, depth copy | Camera depth; focus objects are marked in the stencil | `0x1538fa0` (call `0x657213`) | 7, SPEC-1/2 | V2 |
| 6 | Shadow masks | Request the mask clear, then one full-screen draw per caster | `0x1539a70` → `0x1539b10` (call `0x65721a`) | 8 | V2 |
| 7 | Consumers | Lighting, grass, two image-space draws | — | 9 | V2 |

## 2. Settings

Compiled values and shipped values. "—" means that no shipped INI sets the key. Preset columns: Low / Medium / High / Ultra. All values: **V2**. The "use" column takes the mark of the section that describes the use.

| Setting (`:Display`) | Compiled | `Skyrim_Default.ini` | Presets | Value field | Use |
|---|---|---|---|---|---|
| `iNumSplits` | 2 | — | — | `0x20d9050` | cascade count, array size |
| `fShadowDistance` | 8000 | — | 3000 / 3000 / 8000 / 10000 | `0x20d9458` | split `D`; active distance outdoors |
| `fInteriorShadowDistance` | 3000 | — | — | `0x20d9038` | active distance indoors |
| `fFirstSliceDistance` | 1250 | 2000 | — | `0x20d9470` | first split |
| `fSplitOverlap` | 100 | — | — | `0x20d94e8` | split overlap |
| `iShadowMapResolution` | 2048 | — | 1024 / 2048 / 2048 / 4096 | `0x20d9008` | all shadow map edges, filter radius |
| `bUse16BitsDepthTarget` | 1 | — | — | `0x20d73c8` | shadow map format |
| `uShadowFilterType` | 3 | — | — | `0x20d6b68` | mask permutation |
| `fPoissonRadiusScale` | 4 | — | — | `0x20d9150` | filter radius in texels |
| `iShadowMaskQuarter` | 4 | — | — | `0x20d7308` | mask size = screen × value / 4 |
| `fShadowBiasScale` | 1 | — | — | `0x20d9080` | overwritten for the sun and for local lights |
| `fShadowDirectionalBiasScale` | 0.3 | — | — | `0x20d9518` | sun cascade 0 bias |
| `iEnableShadowCastingFlag` | 2 | — | — | `0x20d6d00` | cast-flag rule, secondary sun map |
| `bDrawLandShadows` | 0 | — | — | `0x207b840` | cast flag of full-cell land |
| `iNumFocusShadow` | 4 | — | 1 / 2 / 4 / 4 | `0x20d9068` | focus target limit |
| `fMaxFocusShadowMapDistance` | 450 | — | — | `0x20d9198` | focus range and fade |
| `ffocusShadowMapDoubleEveryXUnit` | 450 | — | — | `0x20d9020` | focus map size |
| `bDirShadowMapFullViewPort` | 1 | — | — | `0x20d94d0` | cascades use the whole slice |
| `bDisableShadowJumps` | 1 | — | — | `0x20d9500` | sun direction hold path |
| `fSunStaticTimeUpdateScale` | 0.1 | — | — | `0x20d94b8` | hold progress rate |
| `fSunUpdateThreshold` | 0.5 | — | — | `0x20d9488` | read at light construction; used only with jumps enabled |
| `fSunShadowUpdateTime` | 1 | — | — | `0x20d94a0` | used only with jumps enabled |
| `bShadowsOnGrass` | 1 | — | — | `0x20d6a78` | binds the mask for grass |
| `fShadowClampValue` | 0.3 | — | — | `0x20d6d48` | grass shadow floor |
| `bTreesReceiveShadows` | 1 | — | — | `0x20b0a80` | tree receive flag (effect U) |
| `bDisableHighTreeShadow` | 1 | — | — | `0x20d67f8` | skips high trees in some cull passes (passes U) |
| `fMaxHeightShadowCastingTrees` | 5000 | — | — | `0x20d67e0` | height limit for the row above |

**Which first-slice value applies.** `Skyrim_Default.ini` is a first-run template: it is copied to `Skyrim.INI` when that file does not exist, and the image never reads settings from it directly (#1052 G02, one published finding, static). A new install therefore gets `fFirstSliceDistance` = 2000. 1250 applies only when the key is absent. This file uses `S` = 2000 as the default configuration. A user's own files can change any value.

`Skyrim_Default.ini` also holds `iShadowMapResolutionPrimary` and `fShadowLODMaxStartFade`; the image has no such strings (**V2**). No preset file has a key that turns point-light shadows on or off (**V1**, search for "Shadow", "Focus", "Slice").

## 3. Shadow-map resources

| Depth target | Size | Slices | Content | Mark |
|---|---|---|---|---|
| 2 | `res × res` | `iNumSplits` | sun primary cascades (the mask samples this) | V2 |
| 3 | `(res>>3) × (res>>3)` | `iNumSplits` | sun secondary maps (section 5.4) | V2 |
| 4 | `res × res` | 8 | slices 0–3: local shadow lights; slices 4–7: focus maps | V2 |
| Mask: render target 18 (`kSHADOW_MASK` (PDB)) | `W·q/4 × H·q/4`, `q = iShadowMaskQuarter` | 1 | `R8G8B8A8_UNORM` | V2 |

Format of targets 2–4: with `bUse16BitsDepthTarget` = 1, texture `R16_TYPELESS`, depth view `D16_UNORM`, read view `R16_UNORM`. With 0: `R32_TYPELESS` / `D32_FLOAT` / `R32_FLOAT`. No stencil. Depth clear value 1.0, depth only, at the start of each slice that a light binds (value read at `0x1010f8c`). Formats and clear: **V2**.

Local slice allocation: a free mask starts at `0xF` (`0x20d8ff8`). A local light takes the lowest free slice of target 4 when it first renders and returns it after the mask pass. **V2**.

## 4. Sun: direction, splits, cascade fit, light cameras

### 4.1 Held direction

At the defaults (`bDisableShadowJumps` = 1) the shadow direction is held. A progress value belongs to the sun light. At each update, if the progress is above 1.0, or the camera-moved flag of this update is set, the held direction is replaced by the sun light's current direction (the first column of its world rotation, the direction of travel, normalized) and the progress becomes 0. Otherwise the progress rises by `T / max(fSunStaticTimeUpdateScale, 1e-6)` and the held direction stays. **V2** (R, F). The moved flag is set when the camera's world position differs by more than 0.01 from the position at camera `+0xd4`; by the public node layout that is the previous-frame world position (**I**). So a moving camera takes the current direction at once (**I**). `T` is element 3 of a per-frame timer array (section 15, C7); that it is a frame time is **I**. With the setting 0, a second path uses `fSunUpdateThreshold` and `fSunShadowUpdateTime` and blends. Call the held travel direction `d`.

### 4.2 Splits

```text
n      = camera near;   F = min(A, camera far);   A = active shadow distance (section 6.5)
D      = fShadowDistance;  S = fFirstSliceDistance;  N = iNumSplits;  O = fSplitOverlap
t0     = min(D/N, max(S, 500)) / D
t_i    = t0 + (1 − t0) · i/(N − 1)                       (N ≥ 2)
base_i = 0.5 · ( n·(F/n)^t_i + n + (F − n)·t_i )
far_i  = base_i + O
near_0 = n;      near_(i+1) = far_i − 2·O
```

`t0` uses the exterior `D` even when `A` is the interior distance. Cascade selection and blending in the mask use `near_i` and `far_i` (section 8.3). **V2**.

### 4.3 Cascade fit (function `0x157f080`) — V2

**Slice that is fitted.** Cascade 0 is fitted to the camera frustum between distances `n` and `far_0`. Each later cascade `i` is fitted between `far_(i−1)` and `far_i`. It is **not** fitted from `near_i`. The blend band `[near_1, far_0]` is therefore in front of the slice that cascade 1 was fitted to (example B). `near_i` and `far_i` are used for two camera-depth planes of the cascade and for the shader.

**Corners.** Eight points, relative to the camera position: for each of the two distances `v`, the four combinations `v · (f ± t_r·r_c ± t_u·u_c)`. `f`, `r_c`, `u_c` are the camera forward, right and up axes. `t_r` and `t_u` are the camera frustum's **right** and **top** values (not applied when the camera is orthographic). Left and bottom are not read, so the frustum is treated as symmetric.

**Light axes.** `R = normalize(d × U)`, `V = normalize(R × d)`, with `U` = (0,1,0), an image value at `0x20ced58`. `d`, `V`, `R` are the light camera's forward, up and right axes. A zero cross product gives a zero vector.

**Anchor (stabilisation).** With the main camera position `C`:

```text
P = Σ_{e in {d, V, R}}  e · step · floor( (C · e) / step )
step = trunc(w) if w ≥ 1, else 1/trunc(1/w);   w = unitsPerTexel of the cascade descriptor
```

With the default full viewport, `w` stays at its initial value 1.0, so `step` = **1 game unit**. This is not one shadow texel. The window extents come from the camera-relative corners, so they do not change when only the camera position changes, and they do change when the camera turns. No other texel snapping was found on the default path.

**Window.** The light camera is orthographic, at `P − 15000·d`, looking along `d`. Each corner is placed at `P + corner` and projected into a placeholder camera (near 10, far 15000):

```text
x = corner · R;   y = corner · V;   depth_from_camera = corner · d + 15000
left, right = min x, max x        bottom, top = min y, max y
pz     = (depth_from_camera − 10) / 14990           (orthographic depth: (depth − near)/(far − near))
near_L = 14980 · min pz − 20
far_L  = 14980 · max pz + 20
```

The window uses the raw floating-point bounds: no rounding to texels and no sphere fit. The viewport is the whole slice, `res × res`. With `bDirShadowMapFullViewPort` = 0 a different path shrinks the viewport and changes `w`; that path is not described here (**U**).

### 4.4 Light cameras, map orientation and sampling matrices — V2

**Camera axes.** A light camera takes its axes from the columns of a world rotation: **column 0 forward, column 1 up, column 2 right**. Maps are drawn the standard Direct3D way: the camera's up is toward row 0 of the target. Depth range 0 to 1, near = 0.

**Near clamp.** Every camera raises its near value to at least `far / 10000` and at least 0.1 (camera constructor values; set at `0xeefae0`).

**Projections.** Orthographic: `x = 2(X − l)/(r − l) − 1`, same form for y, depth `(F − n)/(f − n)`. Perspective: the standard form, depth `f·(F − n)/((f − n)·F)`.

**Sampling matrices.** Before the engine builds a sampling matrix it swaps the frustum top and bottom (`0x155d426`–`0x155d4f8`). For an orthographic non-paraboloid map it then applies scale (0.5, 0.5, 1) and offset (0.5, 0.5, 0) (`0x155d605`–`0x155d68c`). It also widens an orthographic frustum when the map uses only part of the slice (section 7). Spot and paraboloid matrices do not get the scale step; their mask shaders apply 0.5 themselves. The upload makes each matrix relative to the main camera (`0x15683c4`–`0x1568567`). So the shader input `p` is camera-relative and the world point is `C + p`. A local light uses the matrix of its first (front) map (`0x1568759`).

Sun cascade matrices have three rows `M`. `P` is the anchor of 4.3, and `C` is the main camera position:

```text
w = p + C − P
x = w·R,  y = w·V,  depth = w·d + 15000
q = ( (x − left)/(right − left),  (top − y)/(top − bottom),  (depth − near_L)/(far_L − near_L) )
```

Local light matrices have four rows `M`. `L` is the light position and `w = C + p − L`. The light-node axes give `X = w·right`, `U = w·up` and `F = w·forward`.

| Case | Result `q` | Terms and conditions |
|---|---|---|
| Spot sampling: `M·p`, after the divide by `F` | `( X/(F·tan h),  −U/(F·tan h),  f·(F − n)/((f − n)·F) )` | `n` = clamped near clip, `f` = far value (6.1), `h` = half angle |
| Paraboloid sampling: `M·p` | `( X, −U, (F − 0.1)/0.9 )` | divide value 1; `row2 · p = (F − 0.1)/0.9` |
| Paraboloid map draw, front half | `( X,  U, (F − 0.1)/0.9 )` | vertex input to the formula of 5.5 |
| Paraboloid map draw, back half | `( X, −U, (F − 0.1)/0.9 )` | vertex input to the formula of 5.5 |

The paraboloid depth axis is **not** the raw view depth. The camera is orthographic with window −1..1, near 0 (raised to 0.1) and far 1. So the third component is `(F − 0.1)/0.9` game units in the map draw and in the mask lookup alike. X and U stay in game units.

## 5. Shadow-map generation

### 5.1 Which objects reach the sun maps

The scene root has these children: 0 sky, 1 weather, 2 `LODRoot` (with `LandLOD`, `DistantRefLOD`, `WaterLOD`), 3 the world object root (node name `ObjectLODRoot` in the image; the start-up code passes it as the object root of the world manager). `0x65e610` builds two sets of scene lists:

* **Not sun casters by these lists:** children 0, 1, the children of `LODRoot`, and children 6 and 7. The main view draws them.
* **Sun culling input, first part** (the per-job lists at `0x3436270`; branch read for a view that can see unbound space): children 0 and 1 of the world object root as whole nodes; then, for each cell node, its sub-nodes **except 0, 1 and 4** (and except 2 when the current world space flag bit `0x40` is set), expanded to their children (from the second child for sub-node 6). Hidden nodes (flag bit 0) are skipped. **V2**.
* **Sun culling input, second part: the portal graph's always-render list.** Actor references attach to cell sub-node 0 (`0x2d7997`–`0x2d79c9`). The list builder skips that sub-node because it enters by this second list. Cell registration with a portal graph (`0x2bd290`, `TESObjectCELL::RegisterWithPortalGraph` (PDB)) adds these nodes to the graph's always-render array (graph `+0x58`, public field name `alwaysRenderChildren`; add function `0xfda750`): cell sub-node 0; child 5 of the main shadow scene node; for an exterior cell whose world space flag byte has bit `0x40`, up to four children of cell sub-node 2; and cell sub-node 4. An exterior cell without its own graph uses the world space's graph. The sun culling receives the array of the **view's** portal graph (`0x15380d3`–`0x15380f6`) and dispatches it after the per-job lists (`0x157efd9`–`0x157f000`). **V2**. So **actors cast sun shadows**. That the view's graph is the registered graph at run time is **I**. Sub-node 3, and an extra step for interior cells, were not read (**U**). Per-actor cull flags, the first-person player model and a captured sun draw were not checked (**U**).

So **terrain, object and tree LOD cast no sun shadow** by these paths: the builder takes world casters from child 3, and the children of `LODRoot` go to the non-sun list (**V2**). That all LOD block meshes hang under `LODRoot` is **I**.

### 5.2 Culling

* One pass over the lists uses a camera and a plane set built from the whole range `[n, F]` (convex hull of the eight corners seen along `d`; the plane meaning is **I**). Each cascade then re-culls the collected geometry with the hull planes of its own slice (`0x157ed80`, `0x157ead0`, `0x155cea0`). **V1**.
* No caster distance setting was found. Casters nearer to the light than `near_L` are flattened onto the near plane by the depth clamp (5.5). That the culling planes keep them is **I**.
* Local lights: if the light has its own restricted object list, only that list; else the whole world object root (child 3, actors included). Room and portal visibility apply (`0x155cff6`–`0x155d070`). **V1**.

### 5.3 Per-geometry rules (`0x151b1e0`, lighting properties; shadow modes 13 spot, 14 sun and focus, 15 paraboloid) — V2

A geometry gets **no** shadow-map pass if any of these holds:

1. **fade value × material alpha < 1.** The fade value is the float at `+0x130` of the fade node (property `+0x60`). Material alpha is the float at `+0x80` of the material (property `+0x78`). The property's own alpha is not read. (The only exception is a stipple path of the depth mode 12, not a shadow mode.)
2. Property flag bit 2 or bit 15 is set (names U; bit 15 is the refraction flag in public tables).
3. The geometry's alpha property enables blending (the decal case of rule 4 excepted).
4. It has a decal flag (bit 26 or 27) and does **not** have all of: flag bit 32, flag bit 18 and alpha blending. The pass builder rejects the flag-18 case (`0x151b380`–`0x151b3c0`); pass registration drops every other such decal for shadow accumulators (`0x151ec10`). So a decal casts only with bits 18 and 32 and alpha blending.

**Cast flag** (property flag bit 9). If it is clear:

| `iEnableShadowCastingFlag` | Sun cascades (mode 14) | Focus maps (mode 14) | Local lights (modes 13, 15) |
|---|---|---|---|
| 1 | not drawn | not drawn | not drawn |
| 2 (default) | drawn **only into the secondary map** (pass group 15) | **drawn normally** | **drawn normally** |
| other | drawn normally | drawn normally | drawn normally |

The sun-only branch needs a byte of the sun accumulator that `0x157eb60` sets for every cascade; focus accumulators do not set it.

With `bDrawLandShadows` = 0, full-cell land is created without the cast flag (#806). So at default settings **near terrain does not cast into the sun cascades that the mask samples**; it can cast into focus and local light maps if it is in their lists. **V2** for the flag and the rule; the combined result is a derivation.

**Technique bits** added to the property's base utility bits: `0x4000` shadow map; `+0x8000` clamped (sun, focus); `+0x10000` paraboloid; `0x80` alpha test when the geometry's alpha property enables alpha testing; bit 27 for LOD objects (flags 34 or 63); decals add `0x20080`. Pass group hints: 7 → group 1; `0xB` (flag 61) → group 9; 3 (decals) → group 4; 8 (non-casters) → group 15; others batch by technique.

**Effect geometry** (`0x152a0a0`) returns passes only for mode 12, so it does not cast (**V1**). Grass, particle, water and tree property classes were not traced (**U**).

### 5.4 Render order and the secondary map

The sun render (`0x157ebb0`): if the setting is 2, first draw each cascade into target 3 with only pass group 15 and **no face culling**. Then draw each cascade into target 2 with the ordinary batches, groups 1 and 9 and the decal groups. Then draw the focus maps. The secondary map is **not** sampled by any decoded mask shader. Its consumer is **U** (volumetric lighting is the likely one, **I**). **V2** for the order.

### 5.5 Vertex and pixel output

| Map | Vertex position | Pixel stage | Mark |
|---|---|---|---|
| Sun and focus (record `0xc000` family) | light view-projection × world × position; **`z = max(z, 0)`**; no far clamp in the shader | none for opaque | V2 |
| Spot (`0x4000` family) | light view-projection × world × position | none for opaque | V2 |
| Paraboloid (`0x14002`) | see below; `Rad` = light radius, `s` = +1 front half, −1 back half | discards the back side | V2 |
| Alpha test | as above | `a = diffuse alpha × vertex alpha`; discard if `a < cb11[0].x` | V2 for the compare; source of the reference U |
| Tree animation | moves vertices before projection (records with bit 26) | — | V1, formula not given |

```text
paraboloid:  q  = clip.xyz / clip.w               = the vectors of 4.4: (X, ±U, (F − 0.1)/0.9), clip.w = 1
             k  = 0.5·s·clip.z + 0.5              discard the pixel if k < 0
             h  = normalize( normalize(q) + (0,0,s) )
             SV_Position = ( h.x/h.z , h.y/h.z , |q| / Rad , clip.w )
```

Paraboloid depth is `|q| / radius`. It is close to linear distance over radius; the third axis is stretched as shown in 4.4. Arithmetic: the front half keeps `F ≥ −0.8` and the back half keeps `F ≤ 1.0` (game units), so the halves overlap slightly.

### 5.6 Rasterizer state

The renderer builds a state table over fill 2 × cull 3 × **depth-bias mode 12** × scissor 2 (`0x102b6c0`). All entries use `FrontCounterClockwise` = 1, depth clip on, bias clamp −100. The viewport maximum depth is `1 − offset` for the current mode (`0x10110b2`–`0x10110d0`).

| Mode | `DepthBias` | `SlopeScaledDepthBias` | Viewport max-depth reduction |
|---|---|---|---|
| 0 | 0 | 0 | 0 |
| 1 | −3 | −0.4 | 1.5e−5 |
| 2 | −9 | −1.2 | 0 |
| 3 | −3 | −0.4 | 0 |
| 4 | 3 | 0.4 | 0 |
| 5 | 6 | 0.8 | 0 |
| 6, 8, 10 | −1 | −0.65 | 2.6e−5, 2.8e−5, 3.0e−5 |
| 7, 9, 11 | 0 | 0 | 1.5e−5, 1.7e−5, 1.9e−5 |

* **Ordinary casters** are drawn with mode 0: no hardware depth bias and no slope bias. The utility shader sets mode 1 only on mask paths and on a technique with bit 20; shadow-map techniques skip that write. The sun and light map render functions set no mode themselves. **V2** (static negative; the mode at entry was not observed at run time, and a write through a computed pointer is not excluded).
* **Decal casters** are the exception. The map render finish (`0x15206a0`, render flag `0x100` clear) calls the decal pass `0x151ff00`. For shadow accumulators it sets mode **10** when the sun byte is 0, or **11** when it is 1, draws decal geometry group 4, and restores 0 (`0x151ff57`–`0x15200a6`). Only decals that pass rule 4 of 5.3 can be in that group. **V2**. Mode 10 and 11 are the same pair that the camera decal passes choose from the sun byte (modes 6 to 11).

Which faces are culled for each caster class was not traced (**U**). No special front-face culling for shadows was found.

## 6. Local shadow lights

### 6.1 Kind and projection

| LIGH flag (public names) | Field of view | Object by angle | Map |
|---|---|---|---|
| spot shadow `0x400` (wins) | (form FOV + reference offset) × π/180 | below π: frustum light | 1 perspective slice |
| hemisphere `0x800` | π | π to below 2π: single paraboloid | 1 slice, whole `res × res` |
| omni `0x1000` | 2π | 2π or more: dual paraboloid | 1 slice: front half and back half, each `res × res/2` |

The kind follows the angle, so a spot with an angle of π or more becomes a paraboloid light. **V2**. The light also takes a falloff exponent and a near clip from the form (`+0xf0`, `+0xf8`) and a depth bias `b` from reference extra data type `0x91`; **`b` = 1.0 when the reference has none** (`0x16c9c0`). **V2**. No plugin value was read.

* **Spot** (`0x15872e0`, `0x1587bc0`): half angle `h = clamp(fov/2, 1°, 160°)`; square frustum `±tan h`; near = near clip (then the clamp of 4.4); far = light radius, unless a non-zero override is stored; position and rotation of the light node. Falloff exponent `e = max(falloff, 1)`. **V2**.
* **Paraboloid** (`0x1587f90`, `0x1588590`, `0x1588c80`): orthographic camera −1..1, near 0 (raised to 0.1), far 1, at the light with its rotation. The dual form splits the slice: texture rows `[0, res/2]` for the front half and `[res/2, res]` for the back half. **The back camera is the front camera with only the up axis (column 1 of the world rotation) negated** (`0x1588684`–`0x15886fd`). Forward and right do not change. It is a mirrored camera, so triangle winding on screen is reversed in the back half. The slice is cleared once. **V2**.

There is **no cube shadow map** for point lights in the traced paths (**V2**).

### 6.2 Admission, slots and channels

The selector walks the scene's active shadow-light array in index order. New lights are appended at the end (`0x150c810` → `0x15123a0`, **V1**). No distance or brightness sort was found. A light is admitted if all hold (**V2**):

1. fewer than 4 casters are counted so far (the sun counts as 1 when it runs);
2. its camera update succeeds (6.3);
3. it has a portal entry;
4. it shares a room, or unbounded space, with the view.

An admitted light gets the next caster-array entry and the next **mask channel index**: 0, 1, 2, 3 = R, G, B, A. The sun takes index 0 when it runs. So: sun on → at most **3** local shadow lights on G, B, A; sun off → at most **4**, the first on R. **V2**. The Lighting point-light writer copies that index to `cb2[2][i]` for shadow-slot light `i` (`0x154bda1`–`0x154bdb0`; **V2**: G, F). A rejected light returns its slices. That a rejected shadow light then lights nothing in that frame is **I**.

**Screen rectangle** (used as the mask scissor). It is the whole screen if the camera is closer to the light than radius + camera near (**V2**). Else it is the screen bound of a sphere of the light radius whose centre is moved one radius from the light toward the camera (`0x1538c15`–`0x1538e58`; the bound routine was not decoded; **V1**).

### 6.3 Camera test and distance rule — V2

The update fails if the light node is hidden or outside the view (frustum test). If the light's LOD-fade flag is set, it also fails when

```text
( |L − C|² − radius² ) · camera.lodAdjust ≥ A²
```

### 6.4 Defaults per preset

| Question | Answer | Mark |
|---|---|---|
| Are point-light shadows on or off per preset? | No preset key turns them on or off. A light casts when its form has a shadow flag (6.1) and it is admitted (6.2). | V1 |
| Cube map size | There is no cube map. One depth-array slice of `res × res` per light: 1024 / 2048 / 2048 / 4096 for Low / Medium / High / Ultra. An omni light uses two halves of `res × res/2`. | V2 |
| Slot order | Active shadow-light array order. No sort found. Channels in admission order. | order V2; append V1 |
| Number of shadow lights | 3 with the sun, 4 without. | V2 |

### 6.5 Active distance `A`

`A` = `fInteriorShadowDistance` while the interior byte `0x20d68f4` is set, else `fShadowDistance` (`0x14ebf00`). **V2**. This byte is **not** the "sun shadows off" byte of section 10. `A` drives: the far clamp `F` (sun), the radial fade constant, the local rejection above.

## 7. Focus shadows (extra detail maps for single objects)

* **Candidates** are rebuilt each frame (`0x65a400`): first the player model (distance 0) when present and not hidden; then further actors from a list that holds squared distances, ordered nearest first, while the squared distance is below `fMaxFocusShadowMapDistance²`; up to `iNumFocusShadow` entries in total. **V2**. The point from which the list distance is measured was not traced (**U**). They are collected when the sun runs; when it does not, only if a frustum-type shadow light is active (**V2**).
* **Owner.** The sun owns the focus maps when it runs. Otherwise a spot (frustum) light owns them: a light that had them in the previous frame keeps its claim, else the first admitted frustum light takes them (**V2**). With several spot lights the reset order in the selector (`0x1538a60`–`0x1538bdc`) can matter; that case was not traced further (**U**).
* **Camera** of focus object `i` (`0x155ca00`), with `c`, `r` = centre and radius of the object's bound:

```text
fwd, up = columns 0 and 1 of the owning light's first shadow camera (sun: cascade 0; spot: the spot camera)
rgt     = fwd × up
pos     = c − 1.1·r·fwd
window  = −r .. r in both directions;   near = 0.1·r (then the clamp of 4.4);   far = 2.2·r
sz      = 50 · 2^k,   k = max(0, (4·X − dist)/X),   X = ffocusShadowMapDoubleEveryXUnit,
          dist = camera to the object node
size    = min(res, trunc(sz))
slice   = 4 + i of target 4
```

  Position, window, near, far and the size formula: **V2**. The basis (`rgt = fwd × up`): **V1**. Only that object's node is accumulated (mode 14, clamped technique).
* **Sub-viewport.** The map uses only a square in the **lower-left** corner of the slice: `u ∈ [0, size/res]`, `v ∈ [1 − size/res, 1]`. **V2**. The map draw viewport uses `min(sz/res, 1)` (not truncated); the sampling matrix uses the integer `size` (**V1**; the difference is below one texel).
* **Sampling matrix** `F_i` (composition of the above with 4.4; **I** from V1 and V2 parts), with `w = C + p − pos`:

```text
F_i·p = (  (w·rgt + r)/(2r) · size/res,
           1 − (w·up + r)/(2r) · size/res,
           (w·fwd − near)/(far − near) )
```

* A spot owner renders its focus slices after its own map (`0x1587a4b`–`0x1587ac0`, **V1**).
* **Receiver.** The mask reads the camera depth **stencil** value `S` at the pixel; `S > 0` selects focus map `S − 1`. **Writer:** after the depth prepass, the camera depth pass draws each focus object `i` again with stencil reference `i + 1` and stencil mode 1 (`0x15392c0`–`0x1539368`; state applied at `0x1010fdf`). **V2**. Stencil mode 1 is: function ALWAYS, pass operation REPLACE, other operations KEEP, masks `0xFF`. The depth mode set there is test `LESS_EQUAL` without depth write (**V1** for the two state descriptions). So `S` = `i + 1` where object `i` is the visible surface. The same pass can change the camera projection (`0x1539173`–`0x1539245`; values **U**). The stencil clear was not traced; 0 elsewhere is **I**.
* **Fade** (`0x1566d1c`): `g = 1` if `D2 < 0.25·M²`, else `(M² − D2)/(0.75·M²)`, with `M = fMaxFocusShadowMapDistance` and `D2` the squared distance stored with the focus entry. The player entry stores 0, so its `g` is 1. **V2**.

## 8. The shadow mask pass

### 8.1 Target, clear and channel writes

* No depth target. The pass requests a clear of the mask target to **(R, G, B, A) = (1, 0, 0, 0) when the sun byte is 0, (0, 0, 0, 0) when it is not** (`0x1539a7a`–`0x1539b69`). **V2**.
* The renderer applies a requested clear at its next state flush. In this routine that is the first draw. With **no caster entry** the routine draws nothing and issues no clear itself (**V2**). Whether a later flush applies the pending clear is **U**. With the sun on there is always a first draw.
* One full-screen draw per caster-array light, in array order. The sun writes **R** only; a local light writes only its channel of 6.2 (colour write masks 5, 6, 7, 8 from the table at `0x1b436a0`). **V2**.
* The pass sets no blend mode of its own; with the clear above, replace behaviour is expected (**I**).
* Local draws are **scissored** to the light's screen rectangle. Outside it the channel keeps the clear value. **V2**.

### 8.2 Permutations, textures, samplers, constants

Technique = `0x2002 | type | focus | filter`: sun `0x200000`, spot `0x400000`, hemisphere `0x800000`, omni `0x1000000`; focus `0x100` (sun: when focus is enabled and at least one focus target exists; spot: when that light owns focus maps); filter bit 17, 18, 19 or 20 for `uShadowFilterType` 1, 2, 3, 4. **V2**. Defaults: sun record `0x282002`, or **`0x282102`** with focus targets; spot `0x482002` / `0x482102`; hemisphere `0x882002`; omni `0x1082002`.

| Slot | Content | Sampler |
|---|---|---|
| `t2` | camera depth | clamp, point |
| `t4` | shadow map array of the light (filter type ≠ 0) | clamp, **comparison, linear, `LESS`** |
| `t3` | the same array (filter type 0, manual compare) | clamp, point |
| `t5` | camera stencil (focus) | load |
| `t6` | target 4 array (sun focus) | clamp, comparison |

So one filtered tap returns the bilinear fraction of four texels where `reference < stored`. **V2**.

Pixel constants: `cb0[0]` = (1/width, 1/height, 0, 0) (V1). `cb0[1].z` = filter radius `ρ = fPoissonRadiusScale / res` in map UV (filter types 2–4, V2). Sun: `cb0[2]` = (`Far[0]`, `Far[1]`, `Far[2]`, `N`) where `Far[2]` holds a **copy of `Far[N−1]`** (so with N = 2 it is the value for `far_1`); `cb0[3]` = (`Near[0..2]`, 4). Each is a device depth `dz(v) = far_cam·(v − n)/(v·(far_cam − n))` of `far_i` or `near_i` (V2). Local: `cb0[2].x` = slice index (V2); `cb0[3].w` = 4, the focus slice base (V1). `cb2[2].y, .z` = biases; `cb2[3].z` = fade constant `B`; `cb2[3].x` = spot exponent `e` or paraboloid radius `Rad`; sun matrices `cb2[16..18]`, `[19..21]`, `[22..24]` (three rows per cascade); local matrix `cb2[16..19]`; focus matrices from `cb2[4]`, three rows each; `cb0[4]` = focus fades `g_i`.

**Bias constants** (`0x1568300` function): `y = b·0.00025·k`, `z = b/12000`, `k = fShadowDirectionalBiasScale` for the sun and 1.0 otherwise. The sun's `b` is 60.0. So the sun has `y` = 0.0045 and `z` = 0.005. The decoded local mask shaders read only `y` = `b·0.00025`. **V2**.

**Sample offsets** `o_j`, j = 0..15: sixteen fixed two-dimensional offsets, each component in [0, 1], stored as immediate data in the mask shader. They are the same in every decoded permutation; focus records store four selector rows before them (**V2**). The values are shipped shader data and this file does not reproduce them. An implementation that uses its own sixteen offsets keeps the formulas below, but its soft-edge pattern differs from retail.

Default filter (type 3): `PCF(c, σ, ref) = (1/16) Σ_j tap( c + (2·o_j − 1)·ρ, slice σ, ref )`. No rotation, no noise. Filter types 1, 2 and 4 were not decoded for this file (#1248 reports that one-tap and 3×3 forms exist).

### 8.3 Formulas — V2

Common to all mask draws:

```text
zd = t2 at the pixel
p  = world position relative to the camera:
     ndc = ( 2·u·cb12[44].x − 1,  2·(1 − v·cb12[44].y) − 1,  zd, 1 )      (u,v) = pixel UV
     h4  = cb12[32..35] · ndc;    p = h4.xyz / h4.w
s  = 1 − ( sat(|p|² / B) )^8                B = A² if the light's fade flag is set, else 1e8
```

The sun's fade flag is set by its constructor chain (#806). Every draw writes its result to all four components; the write mask of 8.1 selects the channel. Every draw discards when the result is below `cb11[0].x`.

**Sun.**

The rows apply in order. Row 1 is the case beyond the last far plane; rows 2 to 7 give the mask for the other pixels.

| # | Quantity | Condition | Rule |
|---|---|---|---|
| 1 | Beyond range | `zd > Far[2]` | `mask = 1` |
| 2 | Cascade index `c` | `zd ≤ Far[2]` | `c = 2` when `N ≥ 3` and `zd > Far[1]`; otherwise `c = 1` when `zd > Far[0]`; otherwise `c = 0` |
| 3 | Bias | by cascade | `bias(0) = y = 0.0045`;  `bias(1) = bias(2) = z = 0.005` |
| 4 | Cascade lookup | — | `q = M_c · p` (`q.xy` map UV, `q.z` map depth);  `L = PCF(q.xy, c, q.z − bias(c))` |
| 5 | Cascade blend | `c = 0` and `zd > Near[1]` | `L1 = PCF(from M_1 · p, slice 1, depth − z)`;  `m = sat((zd − Near[1]) / (Far[0] − Near[1]))`;  `L = lerp(L, L1, m²(3 − 2m))` |
| 6 | Focus term | focus record and stencil `S > 0`; `i = S − 1` | `Lf = (1/16) Σ tap( F_i·p .xy + (2·o_j − 0.5)·ρ, array t6 slice i + 4, F_i·p .z − 3·bias_used )`, with `bias_used` = `bias(c)`, or `z` if the blend ran;  `L = min( L, 1 + g_i·(Lf − 1) )` |
| 7 | Result | `zd ≤ Far[2]` | `mask = 1 + s·(L − 1)` (distance fades the shadow to lit) |

Note that the **sun** focus offsets use `2·o − 0.5`, not `2·o − 1`. With N = 3 there is no blend between cascades 1 and 2.

**Spot.**

```text
q     = (M·p).xyz / (M·p).w
L     = PCF(0.5·q.xy + 0.5, slice, q.z − b·0.00025)
value = L · ( 1 − |q.xy|^e )                       (|q.xy| in NDC; no other cone test)
if focus record (0x482102) and stencil S > 0:  i = S − 1
    Lf = (1/16) Σ tap( F_i·p .xy + (2·o_j − 1)·ρ, the light's array t4 slice i + 4, F_i·p .z − 3·b·0.00025 )
    value = min( value, 1 + g_i·(Lf − 1) )
mask  = value · s
```

**Hemisphere.**

```text
if 0.5·(row2 · p) + 0.5 ≥ 0:                      (row2 · p before the w divide)
    q = (M·p).xyz / w;   h = normalize( normalize(q) + (0,0,1) )
    L = PCF(0.5·h.xy/h.z + 0.5, slice, sat(|q| / Rad) − b·0.00025)
else L = 1
mask = L · s
```

**Omni.**

```text
back = 0.5·(row2 · p) + 0.5 < 0;     q = (M·p).xyz / w
h    = normalize( normalize(q) + (0,0, back ? −1 : +1) )
m    = 0.5·h.xy/h.z + 0.5;     uv = ( m.x,  back ? 1 − 0.5·m.y : 0.5·m.y )
ref  = sat(|q| / Rad) − b·0.00025
16 taps, taken in pairs (j, j+1) for even j.  x offset (2·o.x − 1)·ρ.  y offset (2·o.y − 1)·ρ, except:
    if uv.y < 0.5 and uv.y + max(|2·o_j.y − 1|, |2·o_(j+1).y − 1|) > 0.5, the y offset of that pair is 0
mask = (sum / 16) · s
```

The comparison in the y-offset rule adds the **unscaled** table distance (up to about 0.98) to `uv.y`. Arithmetic: for `uv.y` above about 0.314 every pair of the front half has a zero y offset. This is the shader as read.

For local lights the distance factor `s` multiplies the whole value: with distance from the camera the **light itself fades to zero**, not the shadow to lit.

## 9. Consumers of the mask

| Consumer | Rule | Mark |
|---|---|---|
| Near Lighting, sun | key bit 13: sun colour term (diffuse and specular) × `t14.x` | V2 |
| Near Lighting, shadow point lights | key bit 14: for shadow light `i < min(count, 4)`: light colour × `t14[cb2[2][i]]` (diffuse and specular); other lights × 1. Screen coordinate rule in SPEC-1 section 6.1 | V2 |
| Lighting pass choice | Bit 13 is set only if the interior byte `0x20d68f4` is 0 **and** the sun shadow light is among this frame's casters for the geometry (`0x1569745`–`0x1569766`) | V2 |
| Grass | mask bound at `t1` when `bShadowsOnGrass`; the pixel loads `m = t1.x` at its own pixel position; the directional diffuse term × `(m + c·(1 − m))`, not the ambient term. `c = cb2[21].w` = `fShadowClampValue` (write at `0x1522d44`; the per-geometry block goes to the vertex and pixel buffers) | formula and constant V2; bind on the setting V1 |
| Object LOD, terrain LOD, LOD noise | 24 tested Lighting records declare no mask | V2 (M) |
| Composite (`0x1542abe`) and one other image-space draw (`0x15413ee`) | bind the mask (`t5`, `t7`) | binding V2 (M); use U |
| Water | no binding of the mask texture field was found (the four references are grass, Lighting and the two image-space draws) | references V2 (M); other routes U |
| Trees | `bTreesReceiveShadows` sets the receive flag on a tree path (`0x43e609`) | V1; shader effect U |
| Tree LOD, effects, particles | not traced | U |

With a mask size other than the screen (`iShadowMaskQuarter` ≠ 4) the grass load uses unscaled pixel coordinates (**V1** code; visual effect U).

## 10. Interiors and flagged world spaces

### 10.1 The "sun shadows off" byte

| Item | Result | Mark |
|---|---|---|
| Location | byte `0x3436311` = field `+0x51` of a global block at `0x34362c0`, reached through the accessor `0x1537410` | V2 |
| Writer | `0x657c90`, store at `0x65803b`, once per frame from the main draw (`0x656f33`). Value 1 if the current interior cell pointer (world manager `+0xc0`) is non-null, **or** the current world space DATA flag byte (`+0xa0`) has bit `0x40` or bit `0x20`; else 0. No other store through the accessor or by direct address was found. A zero fill of the whole block runs at static start-up | V2 |
| Meaning of the two flag bits | names not verified | U |

### 10.2 What the byte does

| Routine | Byte 0 | Byte 1 | Mark |
|---|---|---|---|
| Shadow setup `0x1537fd0` (the called path) | sun (scene `+0x210`): camera update, focus setup, caster entries from 0 (one per map), channel index 0, sun culling | calls only virtual slot `0x0C` (byte offset `0x60`, return shadow maps) of that light | V2 |
| Selector `0x15389b0` | accumulates the sun; caster count starts at 1 | count starts at 0 | V2 |
| Mask clear colour | R = 1 | R = 0 | V2 |
| Function `0x1538860` (PDB `ResetCalculatedShadowCasterLights`) | same sun set-up from caster entry 0 | calls only virtual slot `0x0C` | V2. No static reference to it was found; the called path is `0x1537fd0`. That it is unused is I |
| Volumetric lighting | — | disabled by default | V2 (H) |
| Decal passes, camera and shadow-map | modes 6, 8, 10 | modes 7, 9, 11 (some also depend on byte `0x20d683a`) | V2 |
| `0x15377fd`, `0x153795d`, `0x1537ac9`, two sites in the depth pass | — | other effects (camera projection updates), not fully traced | U |

### 10.3 Result for an implementer

The statements below are derived (**I**) from the V2 gates. The only callers of the sun camera update found are the two gated sites. The sun wrapper is held at scene `+0x210`; its setter (`0x150f3d0`) was not seen to add it to the shadow-light array that the selector walks (scene `+0x148`, count `+0x158`) (**V1**). No frame was observed.

* **Interior cell:** no sun cascade, no sun caster entry, no sun mask draw. Near Lighting uses the unshadowed sun wrapper (bit 13 clear). The mask pass is still called. With at least one local shadow light it clears to 0 and draws those lights, which take channels R, G, B, A (up to 4). With none, see 8.1. `A` = `fInteriorShadowDistance`.
* **Flagged exterior world space:** the same for the sun and the mask; `A` = `fShadowDistance` (the interior byte is 0). Lighting leaves bit 13 clear because the sun is not a caster, so the sun lights without a shadow (**I**).
* Grass in such a frame still loads channel R. With a local shadow light on R it reads that light's mask, and R is 0 outside the light's rectangle, so the sun term drops to the floor `c` there. With no local shadow light it reads whatever the target holds (8.1, **U**). All of this is **I**; not observed.

## 11. Variant table

| Variant | Selector | Map | Mask draw | Status |
|---|---|---|---|---|
| Sun, no focus | sun on | §4, §5 | `0x282002`, §8.3 | specified |
| Sun with focus | focus targets > 0 | + §7 | `0x282102` | specified |
| Sun, 3 cascades | `iNumSplits` = 3 | same rules | tests `Far[1]`; no 1→2 blend | specified from shader; not a shipped value |
| Actor casters | actor nodes | portal always-render list, §5.1 | — | specified (static) |
| Filter type 0 | `uShadowFilterType` 0 | same | one tap, lit when `stored ≥ ref` (#1248) | partial |
| Filter types 1, 2, 4 | setting | same | not decoded | open |
| Spot, with and without focus | shadow flag `0x400` | §6.1, §7 | `0x482002` / `0x482102` | specified |
| Hemisphere | `0x800` | §6.1 | `0x882002` | specified |
| Omni | `0x1000` | §6.1 | `0x1082002` | specified |
| Interior / flagged world space | §10 | local only | local only | specified |
| Alpha-tested caster | alpha test | §5.5 | — | specified; reference value open |
| Blended or faded caster | §5.3 | not drawn | — | specified |
| Non-caster flag, setting 2 | §5.3 | secondary map only (sun); normal in focus and local maps | — | specified |
| Decal caster (bits 18 and 32, blended) | §5.3 | mode 10 / 11 | — | specified; vertex formula not given |
| Skinned and tree-animated casters | technique bits | — | — | vertex formulas not given |
| LOD casters (sun) | `LODRoot` subtree | not drawn | — | specified |
| Effect geometry | effect property | not drawn | — | V1 |
| Loading-menu lights | `fLoadingMenuShadowBias`, `iLoadingMenuShadowLightFlags` | — | — | not covered |

## 12. Worked examples

**All camera, light, geometry, sample-result and colour values in this section are invented examples.** They were computed by script from the formulas above in double precision. A retail frame uses float32.

Inputs for A–C: camera near `n` = 15 (assumed), camera position `C` = (1000.4, 2000.7, 150.2), forward (0,1,0), right (1,0,0), up (0,0,1), half-extents at distance 1: 0.80 and 0.45; sun travel direction `d` = (0, 0.6, −0.8); `res` = 2048.

### A. Splits (example only)

| Case | `S` | cascade 0 `[near, far]` | cascade 1 `[near, far]` |
|---|---|---|---|
| High, template `S` (default configuration) | 2000 | [15, 1141.667] | [941.667, 8100] |
| High, compiled `S` | 1250 | [15, 751.334] | [551.334, 8100] |
| Low and Medium | 2000 | [15, 959.816] | [759.816, 3100] |
| Ultra | 2000 | [15, 1133.532] | [933.532, 10100] |

Worked: High, `S` = 2000: `t0` = 2000/8000 = 0.25; `base_0` = 1041.667; `far_0` = 1141.667; `near_1` = 941.667; `far_1` = 8100.

### B. Cascade fit (example only, High, `S` = 2000)

`R` = (1,0,0). `V` = (0, 0.8, 0.6). Dots of the camera position: `d` 1080.26, `V` 1690.68, `R` 1000.4 → floored 1080, 1690, 1000 → anchor `P` = (1000, 2000, 150). Light camera at (1000, −7000, 12150). `C − P` = (0.4, 0.7, 0.2).

| | cascade 0 | cascade 1 |
|---|---|---|
| fitted camera distances | 15 → 1141.667 | 1141.667 → 8100 |
| window x | [−913.33, 913.33] | [−6480, 6480] |
| window y | [7.95, 1221.58] | [605.08, 8667.00] |
| `near_L`, `far_L` | 14963.60, 16095.27 | 15233.82, 22770.81 |
| texel size (x, y) | 0.892, 0.593 | 6.33, 3.94 |
| filter radius (4 texels) | 3.57, 2.37 | 25.31, 15.75 |
| bias in world units (bias × depth range) | 0.0045 × 1131.67 = 5.09 | 0.005 × 7537.00 = 37.7 |

Blend-band consequence: at camera distance 941.667 the lowest visible point has `y` = 499.1 relative to the camera (499.8 relative to the anchor), below cascade 1's window start 605.08. Such pixels sample cascade 1 outside its window (clamp sampler). Arithmetic only.

### C. Receiver compare (example only)

Receiver at camera-relative (0, 500, −100), cascade 0. `w = p + C − P`: `x` = 0.4, `y` = 340.68, light depth = 15380.26. Map `u` = 0.50022, `v` = 0.72584. Map depth = (15380.26 − 14963.60)/1131.67 = 0.36818. Reference = 0.36818 − 0.0045 = 0.36368.

* Caster 3 units nearer the light: stored 0.36553. `0.36368 < 0.36553` → lit.
* Caster 8 units nearer: stored 0.36111. Test fails → shadowed.
* The threshold here is 5.09 units.

### D. Filtered value, blend, fade, Lighting multiply (example only)

16 tap results sum to 10.75 → `L` = 0.671875. Pixel at camera distance 1000: `m` = (1/941.667 − 1/1000)/(1/941.667 − 1/1141.667) = 0.33298; weight `m²(3 − 2m)` = 0.25879. With `L1` = 0.5: `L` = 0.627395. Radial distance 1100, `B` = 8000²: `s` ≈ 1.0 → mask R = 0.627395 before 8-bit storage; stored 160/255 = 0.62745.

Radial fade `s` for the sun at `A` = 8000: r = 4000 → 0.99998; 5000 → 0.99946; 6000 → 0.98998; 7000 → 0.88193; 7600 → 0.55987; 8000 → 0.

Lighting, with the unrounded mask: `N·L` = 0.8, sun colour (1.2, 1.1, 0.9) → sun term = (0.60230, 0.55211, 0.45172). Then SPEC-1 sections 6 and 7.

### E. Local lights (example only)

* Bias: `b` = 1 → 0.00025. Paraboloid with radius 500: 0.125 units of `|q|`.
* Spot value: PCF 0.75, `|q.xy|` = 0.6, `e` = 1, camera distance 2000, `A` = 3000 → `s` = 0.99848; mask = 0.75 × 0.4 × 0.99848 = 0.29954.
* Spot projection: `h` = 40°, near 5, far 500, light-space `X` = 60, `U` = 30, `F` = 200 → `q` = (0.35753, −0.17876, 0.98485); UV (0.67876, 0.41062); reference 0.98460; cone `1 − |q.xy|` = 0.60027 (e = 1).
* Omni lookup: `Rad` = 500, light-space `X` = 100, `U` = −50, `F` = −180 → `q` = (100, 50, −200.111), `|q|` = 229.226, back half; `uv` = (0.38354, 0.77911); reference = 0.45845 − 0.00025 = 0.45820. The back-half map draw puts the same point at the same UV.
* Omni in Lighting: PCF 13/16, `s` = 0.99848 → channel 0.81126. Point light with colour (2.0, 1.5, 1.0), `N·l` = 0.5, distance 200 of 500 (attenuation 0.84): contribution = (0.68146, 0.51110, 0.34073).
* Rejection indoors: distance 3200, radius 500, `lodAdjust` 1, `A` = 3000: 3200² − 500² = 9 990 000 ≥ 9 000 000 → rejected (if the fade flag is set).

### F. Focus and grass (example only)

* Focus fade at 300 units: `g` = (450² − 300²)/(0.75 × 450²) = 0.74074.
* Map size at 0 / 200 / 450 / 900 / 1800 units: 800 / 587 / 400 / 200 / 50 pixels. At 200 units the map covers `u ∈ [0, 0.28662]`, `v ∈ [0.71338, 1]`.
* Grass: `m` = 0 → 0.3; `m` = 0.5 → 0.65.

## 13. One end-to-end formula (default settings)

The sun gate and the distance factor are:

```text
sunOn   = not interiorCell and not (worldFlags & 0x60)
s(p, B) = 1 − ( sat(|p|² / B) )^8
```

The mask channels then have these values. A local light `j` is counted in admission order. It uses channel `k = j + (sunOn ? 1 : 0)`, inside its screen rectangle.

| Value | Applies | Definition |
|---|---|---|
| `m_0` (sun) | `sunOn`, camera depth beyond `far_1` | `m_0 = 1` |
| `m_0` (sun) | `sunOn`, otherwise | `m_0 = 1 + s(p, A²) · ( Lsun(p) − 1 )` |
| `Lsun` | sun term | cascade PCF with `bias_c`, smoothstep blend of cascade 0 into 1, then min with the sun focus term |
| `v` | local light `j` | `v = L_j(p) · cone_j(p)`; for a spot the cone is `1 − \|q.xy\|^e`, else 1 |
| `v` with focus | light `j` owns focus maps and stencil `S > 0` | `v = min( v, 1 + g · (Lf − 1) )` (8.3) |
| `m_k` | local light `j` | `m_k = max( v · s(p, B_j), 0 )`; `B_j = A²` if the light's fade flag is set, else 1e8 |
| any channel | outside the rectangle, and unused channels, when the mask pass draws at least once (8.1) | the clear value (0) |

The Lighting colour is:

```text
colour = Albedo · [ sat(N·Ls) · SunColour · (bit13 ? m_0 : 1)
                    + Σ_i sat(N·l_i) · C_i · att_i · (shadow light i ? m[cb2[2][i]] : 1)
                    + ambient + emission ] · VertexColour
```

The same factors multiply the specular light colours (SPEC-1 section 6.2). Then SPEC-1 section 7 (tail) and SPEC-2 (composite to display).

**Hidden sun node.** If bit 0 of the flag word of the sun light node is set, the cascade update returns early with a success result (`0x157f0fb`, `0x15816c6`) and does not rebuild the cameras. The caster-list build ignores the result, and no later gate on culling, map draws or the mask draw was found (**V2** for the early return and the ignored result). The visual result is **U**. #1268 G06 found no writer of that bit.

## 14. Open items and interim implementer choices

### 14A. Open items (retail facts that are missing)

| # | Item | What would close it |
|---|---|---|
| O1 | Run-time proof that the view's portal graph carries the actor entries; the sub-node 3 and interior steps of the registration; actor cull flags; first-person model | a captured sun draw |
| O2 | Caster face culling per class; two-sided casters | trace the batch renderer's cull choice; or captured states |
| O3 | Depth-bias state at map-draw time (static only) | one captured shadow-map draw |
| O4 | Focus stencil clear value; depth-pass projection change values; origin of the candidate distance; several spot owners | read the depth pass and the actor list builder |
| O5 | Consumer of the secondary sun map (target 3) and of the far-depth copy (#1248 G4) | find the readers |
| O6 | Meaning of the cull hull planes; that casters before `near_L` survive culling | read the plane builder |
| O7 | Cascade viewport shrinking path (`bDirShadowMapFullViewPort` = 0) | decode that path |
| O8 | Filter types 1, 2, 4 | decode their records |
| O9 | Composite and image-space use of the mask; water, tree LOD, effect receivers | shader reads |
| O10 | Alpha reference values (mask discard and caster alpha test) | trace the constant writer |
| O11 | Grass, particle, water and tree casters; precipitation, volumetric and loading-menu shadow paths | separate items |
| O12 | Run-time: camera near and far, the timer of 4.1, which lights are admitted in a real scene | capture |
| O13 | Source of the LOD-fade flag of placed local lights; local caster lists; vertex formulas of skinned, tree and decal casters | read the light creation and caster accumulation paths |
| O14 | Mask content in a frame with no caster entry | capture, or trace the later state flush |

### 14B. Interim implementer choices — **not retail facts**

These choices make the default configuration buildable. None is a claim about retail behaviour. Replace each when the open item closes.

| For | Interim implementer choice |
|---|---|
| O2 caster faces | Cull back faces; draw both faces for two-sided materials. Flip the cull side in the mirrored back paraboloid half. |
| Map depth test | Ordinary less-or-equal depth test against the cleared slice. |
| O6 caster culling | Cull casters against each cascade's volume extended toward the light, so that casters before `near_L` stay. |
| O10 | Caster alpha test: the material's alpha-test threshold. Mask discard reference: 0 (a UNORM target clamps negative values anyway). |
| Screen position (8.3) | With no dynamic resolution use `cb12[44].x` = `cb12[44].y` = 1, and build `p` with your own inverse view-projection. |
| 4.1 timer and start | Use the frame time in seconds for `T`. Take the current direction on the first frame. |
| Secondary map (O5) | Omit it; no decoded mask shader samples it. |
| O14 | Clear the mask to (0, 0, 0, 0) in a frame with no caster. It changes only grass in a flagged world space with no local shadow light. |
| Filters (O8) | Implement type 3 only. |
| 6.2 rectangle and order | Any screen bound that covers the light sphere. Keep lights in the order they were added. |
| O13 | Treat the LOD-fade flag of placed lights as set. Give a local light all casters within its radius. Deform skinned and animated casters the same way as the main pass. |
| Focus (O4) | Clear the stencil to 0 each frame. Draw the stencil marks with the same projection as the depth prepass. Candidates: the player, then the nearest actors within range. With several spot lights, give focus to last frame's owner if it is admitted, else to the first admitted spot. |
| Mask size | Keep the mask at screen size. |

## 15. Corrections to earlier findings

All are static. Each is scoped to the text named.

| # | Earlier text | Correction | Mark |
|---|---|---|---|
| C1 | #806 section 5 left the writer of byte `0x3436311` unverified. #1248 (answer 3b, G7) reports no direct store and leaves the interior result unknown. #1258 G08 and #1268 (item 40, G07) say that the interior sun mask pass or cascade is not shown to be off. | The byte has a writer through an accessor (section 10). It is 1 in interior cells and in flagged world spaces, so the **sun cascade and the sun mask draw do not run** there. The mask pass is still called (local lights only). The literal statement "no direct store" stays true. The 2026-11-26 amendment of pull request #1274 states the same result. This supersedes the open interior result of #1248 G07 and the "not shown to be off" statement of #1258 G08. | writer and gates V2; "does not run" I |
| C2 | #1248 G1 gives interior cascade rows "if the sun cascade update runs in that interior". | By C1 the condition is not met in an interior. Those rows do not occur by this path. `A` indoors still drives local lights. | **I** |
| C3 | #1248 G3: "`Near[3]` is not read by the five decoded shaders." | Records `0x202102` and `0x282102` read it: it is the focus slice base (4.0). | V2 |
| C4 | #1248 G3: default permutation `0x282002`. | Only with no focus target. With focus enabled and at least one target it is `0x282102`, which adds the focus term. | V2 |
| C5 | #1248 answer 1a, G2 ("`near_i` and `far_i` are the slice ends of cascade `i`", and the sentence about the slice of cascade `i + 1`) and the interpretation paragraph. | The `near_i` read builds a camera-depth plane. The fit corners for `i ≥ 1` are at `far_(i−1)` and `far_i`. The shader selection and blend rules of #1248 stay right. | V2 |
| C6 | #1248 G5: a local light receives `b/4000` and `b/12000`. | Clarification, not an error: both are written; the decoded local mask shaders (spot, spot with focus, hemisphere, omni) read only `b/4000`. | V2 |
| C7 | #1248 G8: the progress numerator `0x20d68dc` has no static writer. | It is element 3 of a four-float array at `0x20d68d0` that the frame loop fills through a pointer (`0x658d24`–`0x658d58`). Its unit stays unverified. | V2 |

Not errors, but now answered: #806 section 4 (which LOD meshes enter sun caster lists: none by the traced lists, 5.1); #806 section 4 (where a clear-cast-flag geometry goes at setting 2: the secondary map, 5.3); #1248 G5 item (b) (rasterizer bias: mode 0 for ordinary casters, modes 10 and 11 for decal casters); SPEC-1 open item O6, mask production (this file). SPEC-1's channel rule is unchanged; note that a local light can own channel R when the sun is off.

## 16. Verification ledger

| ID | Claim | Mark | Runs |
|---|---|---|---|
| L01 | Setting compiled defaults and shipped values | V2 | C, S3, V |
| L02 | Two cascades, 2048² primary, 1/8 secondary, edges from `res` | V2 | M, S3 |
| L03 | D16 / D32 formats, 8-slice target 4, slot use, mask format and size rule, clear 1.0 | V2 | S3, V, K |
| L04 | Split formula and `near_i`, `far_i` | V2 | M, R, S3, V, K |
| L05 | Held sun direction | V2 | R, V, F |
| L06 | Cascade fit, 1-unit snap, window, near/far formulas, orthographic depth | V2 | S3, V, K, F (depth form) |
| L07 | Sun caster lists, LOD exclusion, cell sub-node skips | V2 | S3, V, K |
| L08 | Actor route: registration list and sun dispatch | V2 | V, K, F |
| L09 | Rejection rules 1–4 and the mode 12 exception | V2 | K, F (rules 2, 3 also S3, V) |
| L10 | Cast-flag table, secondary group, focus behaviour, land | V2 | S3, V, K, F |
| L11 | Technique bits and group hints | V2 | S3, V |
| L12 | Effect geometry does not cast | V1 | K |
| L13 | Map shaders (clamp, spot, paraboloid, back discard, alpha compare) | V2 | S3, V, K; paraboloid F |
| L14 | Tree-animation caster vertex rows exist | V1 | S3 |
| L15 | Rasterizer table (12 modes) | V2 | S3, K, F |
| L16 | Ordinary casters use mode 0 | V2 | S3, K, F |
| L17 | Decal casters use mode 10 / 11 | V2 | K, F |
| L18 | Viewport max depth `1 − offset` | V1 | F |
| L19 | Camera axes (columns), sampling swap, texture matrix, camera-relative upload, front-map choice | V2 | V, F |
| L20 | Paraboloid near clamp 0.1 and the resulting depth axis | V2 | K, F |
| L21 | Light kind rules | V2 | M, S3, K |
| L22 | Spot camera, omni split, bias default, no cube map | V2 | S3, V, K |
| L23 | Back paraboloid camera: only the up axis negated | V2 | V, F |
| L24 | Selector test order, no sort, 4 limit, channel order and letters | V2 | M, S3, V, K, B |
| L25 | Append order of new lights | V1 | S3 |
| L26 | `cb2[2][i]` = channel index of shadow light `i` | V2 | G, F |
| L27 | Screen rectangle: full-screen rule V2; shifted-centre bound V1 | V2 / V1 | V, K |
| L28 | Local distance rejection and active distance | V2 | M, R, D, V, K |
| L29 | Focus candidates, order, count | V2 | V, K, F |
| L30 | Focus owner (sun, else frustum light) | V2 | V, K, F |
| L31 | Focus camera window, position, near, far, size, fade | V2 | S3, V, K, F |
| L32 | Focus sub-viewport (lower-left) | V2 | V, F |
| L33 | Focus camera basis; viewport rounding; spot render of focus slices; stencil and depth state description | V1 | F |
| L34 | Focus stencil writer, reference `i + 1`, mode 1 | V2 | V, F |
| L35 | Mask clear colour, order, one draw per light, write masks, scissor, deferred clear | V2 | S3, V, K, B |
| L36 | Technique and filter bits, textures, comparison `LESS` linear | V2 | R, S3, V, K |
| L37 | `Far`/`Near` constants, `Far[2]` copy, bias constants | V2 | R, S3, K, F |
| L38 | `cb0[3].w` = 4 for local lights; `cb0[0]` content | V1 | F; S3 |
| L39 | Sample offsets (values not reproduced), filter radius | V2 | S3, V, K, F |
| L40 | Sun shader formulas including sun focus | V2 | M, R, S3, V, K |
| L41 | Spot, hemisphere, omni formulas | V2 | S3, V, K, F (omni) |
| L42 | Spot focus formula | V2 | V, K, F |
| L43 | Lighting consumption and the bit 13 rule | V2 | N, R, G, D, S3, V, B |
| L44 | Grass formula and constant | V2 | S3, V, K, F (constant) |
| L45 | LOD Lighting records declare no mask; four binding references | V2 | M |
| L46 | Tree receive flag; `bShadowsOnGrass` bind condition; unscaled grass load | V1 | S3 |
| L47 | Sun byte location and writer | V2 | H, S3, V, K, B |
| L48 | Byte gates the sun setup and selector; decal mode choice; `0x1538860` | V2 | N, M, S3, V, K, B |
| L49 | Sun cascade does not run in an interior or flagged world space | I (from L47, L48) | — |
| L50 | Timer array writer (C7) | V2 | V, F |
| L51 | Hidden sun node: early success return, result ignored | V2 | V, K |
| L52 | Local caster lists and range-hull culling (5.2) | V1 | S3 |

## 17. Second checks by the finalizer

| Point | Finalizer result |
|---|---|
| Actor sun route | Re-read the registration routine, the add function, the actor attach and the sun dispatch. Agrees. |
| Focus stencil writer | Re-read the depth pass loop, the state apply and the state table creation. Agrees. |
| Spot focus formula | Decoded record `0x482102` again. Agrees. |
| Depth bias | Listed every direct write of the mode global, checked pointer-based accesses to the state block, read the mode finish, the decal pass, the utility branches and the viewport use. Mode 0 for ordinary casters and modes 10 / 11 for decal casters agree. |
| Camera axes, map orientation, local matrices | Re-read the view and projection builder, the sampling matrix construction and the upload. Agrees. The two reviews differed on the paraboloid depth axis: the near clamp applies to both the map draw and the sampling matrix, so the axis is `(F − 0.1)/0.9`. |
| Back paraboloid camera | The two reviews differed. The re-read shows that only column 1 is negated. |
| Focus viewport | The two reviews differed. The viewport conversion and the matrix widening both put the map in the lower-left corner. |
| Blocked decals, fade test | Re-read rules 1–4 and the registration filter. Agrees with the second check. |
| Worked examples | All recomputed by script. The omni example changed with the depth axis. The anchor offset is in example C. One proposed last-digit change in example D did not reproduce in double precision and was not adopted. |

## Interpretation and alternatives

**Inferred.** Retail sun shadows are a plain two-cascade design. Their softness comes from a fixed 16-point comparison filter with a radius of four map texels. All receiver bias for ordinary casters is a constant per light. Terrain and distant LOD do not shadow at default settings. Actors enter by the portal always-render list.

**Alternatives.** The cascade-1 coverage gap (example B) may be hidden by the light-space bounds in many sun directions. The 1-unit anchor instead of a texel snap may show as edge shimmer. Neither was observed.

## Negative results and limitations

* Static only. No run, capture, comparator result or visual result supports any statement. This file is not match evidence for any function.
* Writer searches use direct addresses, the accessor and data pointers. An aliased or computed pointer write can be missed (depth-bias mode, the sun byte, the focus list).
* Several routines were read only where a claim needs them. "No sort", "no distance cull" and "no snapping" mean none in the routines named.
* No plugin value was read. A user's INI files can differ from the compiled and shipped values.
* A V2 mark means two runs of the same model family agreed on a static reading. It is not independent proof.

## Reviewer and outcome

Author draft, one independent review and one blind second binary check by separate Sonnet 5.5 runs, merged by a further Sonnet 5.5 finalizer run (Sol unavailable). Outcome of the review: not implementable as first written; the corrections of the review and of the second check are applied here. The merged text had no separate review. This does not decide transfer eligibility (`docs/clean-room.md`). Transfer status: UNREVIEWED.
