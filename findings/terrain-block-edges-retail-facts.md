Transfer status: UNREVIEWED

# Finding: exterior terrain block edges and handover

## Answer

| Question | Answer from the pinned retail inputs |
|---|---|
| 1. Which land indices draw at block edges? | The ordinary draw submits the full authored land index list at widths 4, 8, 16 and 32 cells. It includes vertical perimeter faces and uses the same list beside a different-tier neighbour. Some width-32 surface triangles overlap a neighbouring width-32 block in XY. See G01–G02. |
| 2. What does full-detail takeover suppress? | Width-4 water can omit an attached cell's indexed segment. Land keeps the complete list and lowers vertices inside a rectangle. A separate cell bitset controls whole-block visibility. Parent/child replacement exchanges whole block payloads. See G02–G03. |
| 3. Which resources reach the two draws? | Technique 19 gets distant colour from the terrain block selected at the near cell's centre, through the near material. Surface technique 18 uses its own BTR material. On the nonnull overlay branch, technique 19's distant colour sampler uses clamp with anisotropic filtering. Technique 18's block colour samplers use clamp with a view-relative mip-zero cap. Fallbacks are in G04. |

| Item | Evidence record |
|---|---|
| Status | OBSERVED for verified claims. Inferred and unverified claims are marked. Static only. No game launch, no capture and no visual claim. |
| Author / human operator | A Sol research run (`gpt-6.2-sol` via Codex) / Taylor. |
| Reviewer | A separate fresh-context Sonnet 5.5 run (`claude-sonnet-5-5`). Sol was unavailable on a usage limit. A first Sol review started and left no results. See "Independent review" below. |
| Date | 2026-11-24 CST. The author run took 00:52 to 01:23. The independent review took 05:15 to 05:47. A Sonnet 5.5 run applied the corrections from 05:48. |
| Build | `sse-steam-1-7-104`, retail `1.7.104.0`, Steam build 24914197. Measured executable SHA-256 `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f` equals the pin in [builds/target.json](../builds/target.json). |
| Principal native RVAs | `0x5111e0`, `0x5164c0`, `0x517da0`, `0x518ad0`, `0x518d40`, `0x51a9b0`, `0x51ac60`, `0xef1c30`, `0x100b530`, `0x100bcd0`, `0x155f050`, `0x1a2360`, `0x2b2c60`, `0x1548820`, `0x101f570`. All executable addresses below are RVAs. |
| Sources and revisions | Pinned executable. Shipped BTR meshes, one LOD settings member, textures, shader bytecode and INI templates, listed in the input table below. Published cross-checks: #816, #822, #946, #947 and #979, read from `origin/main`. |
| Source exposure | Locally owned retail executable, shipped BTR meshes, one LOD settings member, shipped shader bytecode, shipped textures and INI templates. Public generated layouts and published findings. No plugin record value or count is quoted. No sibling, downstream or leaked source. No decompiler text or disassembly appears here. Transfer needs review under [docs/clean-room.md](../docs/clean-room.md). |
| Name provenance | Descriptive function names are GUESS. Serialized names and runtime type names come from the retail inputs. Field names marked `CRASHLOGGER_PDB(59818@2026.10.24)` come from the committed generated tables. |
| Intended recipient | Skyrim Research department lead for boundary review under [docs/clean-room.md](../docs/clean-room.md). Proposed use: Mudcrab #948. Maintainer transfer decision pending. |

Addresses are RVAs for image base `0x140000000`. **Verified** means re-read at the cited static source. **Inferred** means a deduction with stated assumptions. **Unverified** means the static evidence leaves the claim open. The document contains facts and formulas only.

## Questions and method

Which triangles draw along a BTR edge, and how does the native path choose tiers? How do full-detail cells and replacement tiers affect LOD triangles? Which texture views and sampler states can the near and distant draws use at that edge?

The author read the pinned native path from streamed geometry to indexed submission, including the width-4 water segment table. The author followed the terrain traversal, swap jobs, loaded-grid rectangle and material binding. The author decoded indexed geometry for every `tamriel` BTR in the mesh archive. The author cross-checked the four LOD vertex/pixel pairs and the near technique 19 records against the native writers.

| Input | Identity |
|---|---|
| `Skyrim - Meshes1.bsa` | SHA-256 `d0e4a62fac342271c27aba5338296ddfe06de790448ebe6e9cf6df7460a4f7c0` |
| `LODSettings\Tamriel.lod` from `Skyrim - Meshes0.bsa` | 16 bytes, SHA-256 `ed9988623ee9a630d28ac183b4c72f611d6d82386e6e73b063c6c8a2560c17d3` |
| `Skyrim - Shaders.bsa` | SHA-256 `fd1ba630f443353ed21ed4ca0380968f9c7091c8434518ea3cc79bc6d38c18e7` |
| Extracted Lighting package `shaders011.fxp` | SHA-256 `72cfc73eb0938d5949f0b3a8683722a33b671a34b41b750ba138de8d154c5fbc` |
| Published baselines (commit hashes) | #816 `e552bc2342729b3993e1f53eec14da0f98947d12`, #822 `e37cab1e148b5587cba1cb41b7f3c08a948e56f8`, #946 `9783521e7820b8a9ca75ff253c2f15ecb004ed13`, #947 `f8b468152faac993af627052a7ace330f1cc1867`, #979 `21e02cc3ab1b1555f76a96aafdbd44ec2619beba` |
| Public layouts | `reconstruction/generated/crashlogger_pdb/types/` at commit `482e5c7a2d2ea0c664a01b1fbe4eadace6051c29` |

## Observations

### G01. Authored perimeter and complete land index lists

**Verified.** The 3,060 `tamriel` BTRs in `Skyrim - Meshes1.bsa` (of 9,584 BTRs for all worldspaces in that archive) each contain one land `BSTriShape` linked to a Lighting property. 1,937 of them also contain a separate water shape. The census below covers `tamriel` only. The local land transform uses zero translation, identity rotation and a scale equal to the block width in cells. The native XY origin uses the signed block origin multiplied by 4096 (`0x510e92–0x510fb2`). Each land shape has one 16-bit triangle list, descriptor `0x300000000405` and auxiliary index count zero. The land geometry has no segment table.

| Width in cells | BTRs | Total land triangles | Vertical perimeter faces | Vertical faces on interior cell planes | Other vertical faces |
|---:|---:|---:|---:|---:|---:|
| 4 | 2,304 | 4,192,762 | 319,084 | 41 | 2,055 |
| 8 | 576 | 1,188,877 | 88,490 | 50 | 1,501 |
| 16 | 144 | 299,584 | 23,744 | 7 | 215 |
| 32 | 36 | 73,603 | 8,410 | 0 | 290 |

**Verified.** Vertical means zero XY area and nonzero 3D area. A perimeter face lies in one of the four nominal block-edge planes (exact coordinate equality on all three vertices; a 0.01 world-unit tolerance adds 12 faces at width 32 and none at the other widths). Every block contains perimeter faces. At widths 4, 8 and 16, each perimeter face has a vertical edge with its top on the nonvertical surface vertex set and its bottom outside that set. Their drops are 1,000, 2,000 and 3,000 world units, respectively. At width 32, 7,231 of 8,410 perimeter faces have a vertical edge with the upper endpoint on the surface vertex set. Of these, 7,216 have a drop of 4,000 world units. Ten lower endpoints also occur in the surface vertex set.

**Verified.** Five width-32 blocks have 41 triangles with a vertex outside the nominal XY bounds (exact comparison). The draft counted 35 of them as nonvertical with a floating-point cross product. An exact rational test gives a positive XY area for all 41, and a few of them are slivers. All 41, and therefore all 35, have positive projected overlap with a triangle of a neighbouring width-32 block (exact rational test), across five neighbouring block pairs. The draft's count of 28 of 35 across four pairs did not reproduce in the review or in the correction run. The excess beyond the bound is small for most. 25 of the 41 exceed it by 0.01 world units or less, and 13 of those 25 are at floating-point noise level. Sixteen triangles in three blocks exceed it by more than 1 world unit. Nine of those exceed it by 128 world units and seven by 384 world units. This establishes authored XY overlap in the archive. Intent and three-dimensional surface coincidence remain **unverified**.

**Verified.** The following nonvertical surface heights differ at the same world XY location. Block labels are `(width, origin X, origin Y)` in cells. Heights are barycentric evaluations of the serialized positions at world Y = 3072, rounded to six decimal places.

| Asset comparison | Blocks | World X | World Z in block order |
|---|---|---:|---|
| Same-tier shared border | `(4,0,0)` and `(4,4,0)` | 16384 | −4381.333333 / −4409.655172 |
| Mixed-tier shared border | `(4,0,0)` and `(8,−8,0)` | 0 | −5929.777778 / −5938.285714 |
| Fine border inside covering parent asset | `(4,0,0)` and `(8,0,0)` | 16384 | −4381.333333 / −4449.788732 |

**Verified.** The native factory assigns geometry type 3 to `BSTriShape` (`0xef21b8–0xef21ca`). The stream method at `0xef1c30` passes the counts to the resource manager. The concrete `BSShaderResourceManager` is published at `0x14ea34d–0x14ea354`, with vtable RVA `0x1b4e7d8`. Its slot `+0x10` reaches `0x1582070 → 0x100b530`. That path reads the serialized vertex and index data and creates the index buffer (`0x100b68d`, `0x100b6fc`, `0x100b73c`). The traced post-stream operation applies no extra processing to a plain `BSTriShape`: the queried virtual slot `+0x68` returns null (`0x1582290 → 0x10194e0 → 0x101b9e0`, slot `+0x68 → 0x1b4ce0`). `BSSubIndexTriShape` does not override that slot either. The class is told apart by slot `+0x58`, which returns null for `BSTriShape` (`0x1b4d40`) and the shape itself for `BSSubIndexTriShape` (`0xff6bb0`).

**Verified.** The ordinary Lighting path reaches the type-3 dispatch at `0x155f1d4` through `0x15215b0 → 0x1560340 → 0x155f050`. The draw helper at `0x100bcd0` binds triangle-list topology and 16-bit indices. It issues an indexed draw with start index 0, base vertex 0 and index count `3 × triangleCount` (`0x100bd14–0x100bdaa`). The same list covers both the ground surface and authored perimeter faces. The four LOD vertex shaders take position and UV. Their checked branches have no neighbour-dependent vertex input or edge morph. The scoped ordinary path has no alternative edge range, generated skirt or stitching operation.

**Inferred.** The vertical perimeter triangles are authored skirts. Their shape and positions support that purpose, including at a fine edge beside a coarse block. The index submissions establish which geometry is eligible for rasterization. **Unverified.** Which faces cover visible samples, including culling and depth where two projected surfaces overlap.

**Confidence: high** for the asset counts and the ordinary land draw. **Confidence: medium** for the intended skirt role. An authoring record could establish intent. A different geometry type, replacement BTR, or separate pass needs its own trace.

### G02. Terrain tier selection and parent/child handover

**Verified.** Tamriel's configuration specifies origin `(−96,−96)`, root width 256, minimum width 4 and maximum drawable width 32. The read and manager writes are at `0x51cd40` and `0x5159dd–0x5159fd`. Nodes above the maximum are marked structural. The tree subdivides into four half-width children down to width 4 (`0x517648–0x517665`, `0x5176db–0x517784`). The lookup at `0x5164c0` selects an existing tier root by width 4, 8, 16 or 32.

**Verified.** Terrain request bit 0 reaches the terrain evaluator at `0x517cc2 → 0x517da0`. Its split predicate at `0x517eb0–0x517f66` uses these conditions in order.

1. The minimum-width node cannot split.
2. With the manager override byte `+0xa0` set, a node above the minimum splits if its width differs from the manager's width at `+0xa4`.
3. Otherwise, near-grid overlap bit 14 forces a split above the minimum. The overlap test includes touching bounds (`0x517add–0x517b4b`). The rectangle for bit 14 has side `uGridsToLoad` (cached copy at `0x320358c`, written by `0x519a80`) and is centred on the loaded-grid centre cell. It is the whole square, not the probe-shrunk coverage rectangle of G03. Bit 15 uses `uLargeRefLODGridSize` (cache `0x3203590`) the same way and does not enter these four steps.
4. Otherwise, the squared XY distance to the node rectangle must be strictly below the squared threshold. The threshold is `fSplitDistanceMult × width × 4096 / sqrt(2)` in real arithmetic. The native computation uses the half-diagonal in single precision. Distance is zero inside the rectangle (`0x51a6e0`).

The ordinary update passes the camera's world translation via SceneGraph `+0x128` and camera `+0xa0` at `0x627953`, `0x284162` and `0x1aae75`. The `camera`, `world` and `translate` names are CRASHLOGGER_PDB(59818@2026.10.24). `fSplitDistanceMult` is compiled to 1.5. Low, Medium, High and Ultra supply 0.5, 1.1, 1.5 and 1.5 (`0x20b33d8`, cache writer `0x519af8`). None of these split tests reads an adjacent node's tier.

**Verified.** An exterior CELL `TVDT` subrecord supplies a bitset tested by terrain node number (`0x2b8c0a–0x2b8d66 → 0x51d070`, test at `0x51cfc0`). In the enabled bitset path, the single-cell test reads the supplied cell's bit. A missing bitset allows the block, and an out-of-range bit in a present bitset returns false. The 3×3 test returns false only when all nine cells qualify for the test and all nine node-bit tests return false (`0x519eb5–0x51a040`). Either test returns true before lookup if gate byte `0x20b3369` is clear or bypass byte `0x3203341` is set. It also returns true for node numbers `0x62d`, `0x62e` or `0x632` with supplied cell X below −8 and Y above 22 (`0x519e5e–0x519eaf`). A null traversal cell or terrain-manager override supplies true for both results at the caller (`0x517ba9–0x517be1`, `0x517c95–0x517cc2`).

**Verified.** The 3×3 result gates the terrain update, with the width exception at `0x517e0c–0x517e19`. The single-cell result controls whole-shape cull bit 0 for land and water when the block is in the visibility update path (`0x517fac–0x51800c → 0x5117b0/0x5117e0`). False sets the bit and true clears it. The locked-width cache `0x3203584` also has load and unload branches at `0x517e0f–0x517ea6` and `0x518011–0x518053`. Structural traversal continues through nodes above the drawable maximum.

**Verified.** The scheduler and runner are at `0x51b540` and `0x51b560`. The finer job accepts absent child handles. Each present child handle must have `state & 0x70000000` equal to `0x30000000` or `0x40000000` (`0x51a930`). The coarser job requires a present replacement handle in one of those states (`0x51ac30`). The actual attach requires a loaded payload, its attached byte clear, and a nonnull chunk root (`0x51122b–0x51126b`).

- The finer job attempts to attach each present child before detaching the parent (`0x51aa0b`, `0x51aa77 → 0x5186a0`).
- The coarser job attempts to attach the parent before recursively unloading the children (`0x51ac75`, `0x51acd1 → 0x5188b0`).

**Verified, scoped.** A fine child next to a separate coarse neighbour draws its own full list once admitted. The covering parent and the child set exchange whole payloads. Neither job constructs an index strip from the parent's interior cell edges or passes a neighbour-dependent edge mode to the land draw. The near-grid overlap in tier selection and the shader coverage rectangle in G03 are separate tests.

**Confidence: high** for the ordinary split, visibility predicates, job prerequisites and call order. The selected tier, time between attach and detach, and submission of both tiers in one frame remain **unverified**. A frame trace would establish those states.

### G03. Full-detail overlap lowers land vertices and can omit water ranges

**Verified.** Width-4 water uses `BSSubIndexTriShape`. The census contains 1,444 such shapes across 1,375 width-4 BTRs. Each shape has 16 serialized segment slots. The 17,958 nonempty ranges cover the index lists consecutively. Their vertices stay within the cell assigned by slot `4 × dx + dy`, measured from the block origin. Each range gives a starting index and triangle count. The 5,146 empty ranges carry no triangles. The 410, 118 and 34 water-bearing blocks at widths 8, 16 and 32 each use a plain water shape without cell segments.

**Verified.** The ordinary traversal calls the water range updater when node mask `0x4` is set, water exists, and the width equals the minimum (`0x517fac–0x517fd0 → 0x518d40`). The block fields `land` at `+0x8`, `water` at `+0x10` and `chunk` at `+0x18` are CRASHLOGGER_PDB(59818@2026.10.24). With near-grid overlap bit 14 set, the updater resolves each slot's cell. It ignores a found cell when cell flag mask 8 is clear and thread-local byte `+0x5d8` is zero (`0x518e64–0x518ed1`).

**Verified.** The updater calls the attach-state predicate with its third argument true. A surviving cell with state byte `+0x44` equal to 6 or 7 disables that cell's nonempty water range. A missing cell or any other state enables the range (`0x518ed5–0x518f10 → 0x1a2200`). Outside near-grid overlap, the updater resets the shape's active ranges (`0x518f5f → 0xff6780`). The range helpers are at `0xff6800`, `0xff6830` and `0xff6850`. The segmented draw consolidates enabled runs and passes their start indices and triangle counts to the same indexed helper (`0x155f485–0x155f526 → 0x100bcd0`). Its whole-list override byte `0x332e440` initializes to zero. It is the terrain manager's map-mode mirror. Stores are at `0x9a045e` and `0x9a0646` (map enter and exit), at two small setters (`0x516c00` sets 1, `0x516c10` sets 0), at the manager's map-mode setter (`0x516e56` sets 1, `0x516e71` sets 0, both only when the manager has LOD) and at the manager update (`0x5160ff`, which clears the manager byte and the mirror when its guard call returns zero). When the override is set, the draw submits the complete list. This run did not trace whether the setters at `0x516c00` and `0x516c10` have callers on an ordinary exterior frame. That the override is clear on the ordinary path is **unverified**. #816 G04 describes the separate BTO object path.

**Verified.** The land shape keeps its complete index list. For a positive loaded-grid width, the rectangle starts at the centre cell plus or minus `floor(width / 2)` on each axis. Each cardinal edge probe reads one boundary cell on the centre row or column. The helper scans four quadrant slots. A quadrant qualifies if it has a shape count above zero, a first shape and a nonnull property pointer. The helper returns the first qualifying property's value at `+0x108`, or 1 if no quadrant qualifies. For finite values, a value below 1 moves the corresponding edge in by one cell. A missing cell or land leaves the edge in place. This probe reads different state from the water cell attach-state test. Evidence at `0x1a2360–0x1a2506` and `0x2ad340–0x2ad398`.

**Verified.** The CPU converts the inclusive maxima to outer cell edges and multiplies the coordinates by 4096. The upload to `VS b0[0]` uses the rectangle centre minus frame origin XY and half extents minus 15 (`0x14ecb20`, `0x1548597–0x1548607`). In VS keys `09000004`, `09040004`, `12000004` and `12040004`, strict per-axis membership gates a subtraction from local Z of `230 + pre-drop transformedZ / 1e9`. The emitted clip Z separately adds `0.5 × saturate((clipZ − 70000) × 0.0001)`. The latter applies independently of rectangle membership. The four corresponding LOD PS have no overlap-dependent discard, alpha fade or explicit depth output. This confirms the scoped land rule in #822 G07 and #946 G08.

**Inferred.** Lowering vertices can change raster coverage and allow detailed land to cover LOD inside the rectangle. The algorithm acts at vertices. A triangle can straddle the rectangle, so the test does not define a per-triangle or per-pixel cutout. Whole-payload replacement in G02 uses a different mechanism. **Unverified.** The full-detail land or water draw in a given frame, draw order, and which pixels survive depth, stencil and blending.

**Confidence: high** for water indices and attach-state eligibility, the finite rectangle predicate and the shader adjustment. **Confidence: medium** for the visibility interpretation. A paired frame trace would resolve effective render states and per-draw coverage.

### G04. Technique 19 and 18 resource producers and mip limits

**Verified.** The near updater queries the effective terrain manager at the individual near cell's centre (`0x2b2c60 → 0x5166e0 → 0x518ad0`). The lookup first requires the point to lie in the inclusive node box. It returns the ordinary handle's block when node bit 3 is clear and `state & 0x70000000` is `0x30000000` or `0x40000000`. Otherwise it searches children in order and returns the first nonnull result. The near call leaves the alternate map handle disabled. The texture getter at `0x511520`, with selector 0, returns the eligible block's Lighting diffuse at material `+0x48`. The updater supplies that texture to the eligible near quadrant's material field `+0xf8`. An existing nondefault overlay skips the quadrant refresh, including the noise and UV updates (`0x2b2d3c–0x2b2f99`). #947 G02 gives the node-relative UV origin and separate distance origin.

**Verified.** The BTR texture-set loader fills the block material's diffuse and normal fields from slots 0 and 1 (`0x1523d78–0x1523de5`). The ordinary binding routes below apply when the respective material and technique setup runs. A texture object supplies its view through texture `+0x48`, then resource `+0x10`. The near overlay and noise fields are `terrainOverlayTexture` and `terrainNoiseTexture`, from CRASHLOGGER_PDB(59818@2026.10.24).

| Binding | View producer | Sampler producer |
|---|---|---|
| Near technique 19 `t13/s13` | Near material `+0xf8` from the selected terrain block. A null material pointer skips the slot update. A nonnull texture without a render resource supplies a null view. | Technique setup primes the slot with a default view, wrap and filter enum 3. The nonnull overlay branch sets clamp enum 0. Filter enum 3 is anisotropic, D3D11 `0x55`, max anisotropy 16 and MaxLOD `FLT_MAX`. |
| Near technique 19 `t15/s15` | Near material `+0x100`, set by the terrain noise lookup or the shared near default. A null material pointer skips the slot update. | Setup selects wrap and filter enum 1. With a noise texture, material setup applies the material address enum at `+0x70`. Its constructor default is wrap. |
| BTR technique 18 `t0/s0`, `t1/s1` | The drawn block's own material diffuse `+0x48` and normal `+0x58`. Slot 0 has an alternate render-target branch when the material field at `+0x50` is not `−1`. | Technique setup selects wrap and filter enum 1. The shipped land property supplies clamp enum 0 for the file texture bindings. |
| BTR technique 18 `t15/s15` | The drawn block's material `+0xb0` when present. The terrain path can supply the same `Noise.dds` cache used by the near lookup. | Wrap and filter enum 1, including when the texture pointer is absent. |

**Verified.** Binding and sampler evidence is at `0x1548064–0x1548523`, `0x1548c6f–0x1548cd9`, `0x1548e5b–0x1548eb2`, `0x15492c6–0x1549369`, `0x154c9a0`, `0x1523637`, `0x1011370–0x10113f7` and `0x102b910–0x102baf3`. Filter enum 1 uses D3D11 `0x14`, linear minification and magnification with point mip selection, bias zero and MaxLOD 0. The sampler caps the mip index relative to its bound view. The PS samples use implicit derivatives. The noise cache is at `0x31fd0a0`, and the near default pointer is at `0x3336448` (#946 G02). The checked render path also reuses current material or technique state where applicable (`0x156037e–0x1560415`). The live view after a skipped update remains **unverified**. Projected LOD's slot 13 map normal is a separate binding (#947 G01).

**Verified.** The ordinary DDS wrapper requests no size cap and disables forced sRGB (`0x100dcc0 → 0x101ee90 → 0x101f570`). A zero DDS mip count normalizes to one. The initial uncapped load preserves asset mip zero. For a single 2D resource, the view uses MostDetailedMip 0 and the retained mip count (`0x101f334–0x101f443 → 0x101f504`). If initial creation returns `0x80070057` with requested cap zero and more than one mip, the loader retries with a feature-level size limit (`0x101fa47–0x101fb8f`). The fill on that route can skip leading asset mips (`0x101fbf0`, `0x101fd88–0x101fdd6`). The view's mip zero can then refer to a higher asset mip. This is a generic load fallback, independent of the block edge. The independent review did not decode the view descriptor mip fields. That sentence rests on the author alone.

**Verified, scoped.** The checked lookup, resource writers, sampler cache and shader samples expose no additional neighbour blend, border-address override, or mip switch based on distance to a block edge. The two routes choose resources independently. **Unverified.** Whether the near overlay and adjacent BTR point to the same resource at a particular seam, the purpose of any offline texel padding, runtime fallback occurrence, and the live mip and view.

**Confidence: high** for the producer and sampler paths. **Medium** for the DDS view rule (author only). A live paired draw would establish the actual resources, addresses, mip ranges and sampler states.

### G05. Restore branches of the technique-remap byte (repeats #947 G03)

**Verified.** This group repeats #947 G03 and adds no new branch. It also bears on #822 G08. #822 G08 describes the technique-remap byte (`0x20d681f`) as setting when a secondary object exists. That finding omits a condition for the early restore. In accumulation modes 25 and 26, a null entry field at `+0x10` bypasses the byte writes (`0x152083a–0x1520844`). An eligible handler clears the byte at `0x152084a`. Early restore at `0x15208a9` requires a nonnull secondary object at `+0x78` and bit 0 of its byte at `+0x26` set. With the bit clear, the handler takes the alternate pass and reaches the common restore at `0x15208d9`. A null secondary reaches that common restore directly. Normal mode 20 runs `0x15205c0 → 0x15215b0`. #947 G03 already records this correction to restore timing in the technique 18-to-9 remap.

**Downstream disposition.** This run did not check how Mudcrab uses the #822 G08 text. Downstream use is **unverified**.

**Confidence: high** for the restore branches and mode separation. Live resolved keys in the eligible accumulation passes remain **unverified**.

### G06. Scope correction to #946 G07 and #947 G01 (`bDisplayLODLand`)

**Verified.** Two published statements exceed the checked evidence.

- #946 G07, settings table row `bDisplayLODLand:LOD` and `uGridsToLoad:General`, third cell: "Native reads control LOD display and overlap grid, respectively (corrected #822 G07–G08)."
- #947 G01, settings paragraph: "`bDisplayLODLand` controls terrain LOD admission through the cache at `0x33d3d45` (#822 G08)."

The compiled setting is 1 at `0x20b5e30`. Two reads copy the byte to `0x33d3d45` (`0x6537e8–0x6537ef`, `0x65db0b–0x65db22`). Both reads sit in a settings cache refresh that also copies `bUseHardDriveCache`, two speed-tree mip bias settings and an actor alpha fade time. The saved full native listing contains those two stores and no other reference to `0x33d3d45`. No address-of, data or relocation reference reaches the setting object or the cached byte. An indirect consumer, generic by-name INI access or a runtime effect remains **unverified**. #822 G08's default and read sites still hold. The `uGridsToLoad` rectangle rule also still holds. In the traced terrain manager update, the node traversal and the coverage rectangle update are skipped when the byte at `0x20b3378` (`bUseNewTerrainSystem:TerrainManager`, compiled 1) or the byte at `0x20b3368` is zero (`0x51626f–0x516283`). No read of `bDisplayLODLand` or of `0x33d3d45` occurs in that routine.

**Scope of the amendments.** Only the two sentences above change. Everything else in #946 G07 and #947 G01 stands. That includes the compiled value 1 at `0x20b5e30`, the template scan, `uGridsToLoad` and the other table rows, and the bit 46 and bit 55 results. The two files carry dated amendments that point here. #822 G08 needs no amendment: it records only the compiled value and the two read sites.

**Confidence: high** for the default, direct reads and writes. An indirect reference or a controlled exact-build trace could establish an admission effect.

## Interpretation and alternatives

**Inferred.** The authored vertical faces can fill some differences between adjacent surface profiles. Projected overlap in the width-32 assets can also affect coverage. The evidence establishes neither a seamless edge nor which face is visible. Complete independent land draws, block payload replacement and the near-grid land depth adjustment account for the traced geometry paths. Cell-level indexed suppression applies to the width-4 water path.

## Negative results and limitations

- **Verified, scoped.** No neighbour-dependent land index switch, generated skirt, stitching pass or vertex morph appears in the traced ordinary exterior land path.
- **Unverified.** Handover timing: the selected tier, the time between attach and detach, and whether both tiers draw in one frame.
- **Unverified.** The live slot 13 filter state at draw time. Static code sets clamp and anisotropic filtering on the nonnull overlay branch. A runtime override was not excluded.
- **Unverified.** Whether the whole-list override byte `0x332e440` is clear on an ordinary exterior frame.
- **Not re-derived.** The child-selection rules in `0x518070` and `0x5183c0`, and the unload path in `0x5186a0` and `0x5188b0`. Only the job order is established.
- **Unverified.** Other passes, replacement or modified assets, live BTR admission, depth and stencil state, and visible seam coverage.
- **Unverified.** The actual paired texture views and mip selection, any offline border bake rule, and the cause of the reported seam. Analysis was static only.
- Counts cover `tamriel` only. The same structure appears in other worldspaces, but this finding does not give their numbers.

## Relation to earlier findings

- **#816 (object LOD, BTO path).** Unchanged. #816 lists `0x518d40` among its principal RVAs, but its text describes only the object path. `0x518d40` filters the width-4 water segments of the terrain block (G03). It is not the object LOD filter.
- **#822 (terrain LOD shading).** G07 and the vertex lowering rule hold (G03). G08's compiled value and read sites hold. G05 here repeats the restore correction already in #947 G03.
- **#946 (terrain LOD versus near).** G08 holds (G03). G07 gets a scoped amendment for the `bDisplayLODLand` claim (G06). The `uGridsToLoad` half of that row holds.
- **#947 (seam keys).** G03 holds and G05 here repeats it. G01 gets a scoped amendment for the `bDisplayLODLand` claim (G06).
- **#979 (near technique 19 order).** Unchanged. Its shader rules keep their published scope. G04 here covers the resource and sampler producers only.

## Independent review

Reviewer: a fresh-context Sonnet 5.5 run (`claude-sonnet-5-5`), separate from the author. Sol was unavailable on a usage limit. A first Sol review started and left no results. The reviewer wrote its own results first (own BTR parse, native reads and a setting trace), then compared them with the draft. Static only.

Result: **5 confirmed (G02, G03, G04, G05, G06), 1 corrected (G01), 0 rejected.** Four of the confirmed groups needed small wording edits. G06 needed exact scoped text. This file contains the corrected wording.

| Group | Verdict | Main correction |
|---|---|---|
| G01. Perimeter and land index lists | Corrected | The width-32 overlap count did not reproduce. The corrected count is below. The scope line, the vtable slot sentence and the perimeter tolerance were reworded. |
| G02. Tier selection and handover | Confirmed | Added the source of the bit 14 rectangle. |
| G03. Overlap and water ranges | Confirmed | The writer list of the override byte was incomplete. It is now complete for the stores found. Callers were not traced. |
| G04. Technique 19 and 18 resources | Confirmed | The summary row overstated clamp. The view descriptor was not independently decoded. |
| G05. Remap restore | Confirmed | Branches reproduce. The byte name now matches #947 G03. The group repeats #947 G03. |
| G06. `bDisplayLODLand` | Confirmed | The draft did not quote the text it corrects. Exact quotes and scoped amendments were added. |

After the review, a Sonnet 5.5 run applied the corrections and re-read items in the pinned image. All matched. The correction run re-read 15 items in the pinned image and recomputed the width-32 overlap. All matched. The split predicate order and the strict squared-distance test (`0x517eb0–0x517f66`). The water updater gate and its call (`0x517fac–0x517fd0`). The attach-state call and the disable and enable calls (`0x518ed5–0x518f10`). The state rules of `0x1a2200`. Both `bDisplayLODLand` reads and both stores to `0x33d3d45` (`0x6537e8`, `0x65db0b`). The saved listing shows only those two stores for `0x33d3d45`. The two skip bytes at `0x20b3368` and `0x20b3378` (`0x51626f–0x516283`). The cache copies of `uGridsToLoad`, `uLargeRefLODGridSize`, the locked-width cache and `fSplitDistanceMult` (`0x519a80`, `0x519af8`). All seven stores of the override byte `0x332e440` (`0x9a045e`, `0x9a0646`, `0x516c00`, `0x516c10`, `0x516e56`, `0x516e71`, `0x5160ff`). The attach and detach call order of both jobs (`0x51aa0b`, `0x51aa77`, `0x51ac75`, `0x51acd1`). The restore branches of the technique-remap byte (`0x152083a`, `0x152084a`, `0x15208a9`, `0x15208d9`). The slot 13 view chain and clamp write (`0x1548c6f–0x1548cba`). The setup loop limit of 16 slots and the slot 15 address and filter values (`0x15484dc–0x1548519`). The `TVDT` gate bytes, node numbers and cell thresholds (`0x519e5e–0x519eaf`). The `BSSubIndexTriShape` slot `+0x58` return of itself (`0xff6bb0`). The correction run did not re-read the `BSTriShape` side of that slot (`0x1b4d40`), the DDS view descriptor or the child-selection routines. Those items rest on the author and the independent review. The width-32 overlap was recomputed with exact rational arithmetic from the shipped meshes. The run found 41 outliers, positive overlap for all 41 across five block pairs, 25 within 0.01 world units, and 16 above 1 world unit in three blocks with a maximum of 384.

Source exposure of the review: pinned native binary, shipped BTR meshes and the saved native listing. This is a static review. It is not match evidence for any function. It does not decide transfer eligibility.

Reviewer and outcome: Reviewed independently by a Sonnet 5.5 run. Outcome: 5 confirmed, 1 corrected, 0 rejected. Static evidence only. Transfer status: UNREVIEWED.
