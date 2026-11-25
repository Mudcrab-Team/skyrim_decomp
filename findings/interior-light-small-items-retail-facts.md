Transfer status: UNREVIEWED

# Finding: DALC face order, interior key-light direction and interior sun shadow

## Answer

Static only. No game run. No capture. Items 41, 45 and 40 of the Mudcrab research list.

| Item | Answer | Tag / confidence |
|---|---|---|
| **41. Which of the six DALC colours is the positive axis?** | The six colours keep their serialized order from the record to the pixel shader. Call them F0 to F5 in record order. The ambient cache builder makes slope X = (F1 − F0)/2, slope Y = (F3 − F2)/2 and slope Z = (F5 − F4)/2. The near Lighting pixel shader (one decoded record) computes `mean + N · slope`. So **F0 = −X, F1 = +X, F2 = −Y, F3 = +Y, F4 = −Z, F5 = +Z**, in the space of the normal N. N is in world axes on the world branch. N is in model axes on the stock branch, where the slopes are rotated by the geometry rotation. Worked example: for N = +Z with F0 to F3 equal to m, F4 = a and F5 = b, the result is (2m − a + 2b)/3. F5 has weight 2/3. F4 has weight −1/3. The committed type tables name the six colours x.max, x.min, y.max, y.min, z.max, z.min in record order, so the first colour of each pair is named `max`. The first colour is the engine's negative-side colour. The names do not show which side `max` means. This run read no plugin and no editor. | Verified (binary), high. Editor names and the meaning of `max`: unverified. |
| **45. Interior key-light direction (world sign)** | The two cell angles are unsigned integers in degrees. XY angle A builds R1 = [[cosA, sinA, 0], [−sinA, cosA, 0], [0, 0, 1]]. Z angle B builds R2 = [[cosB, 0, −sinB], [0, 1, 0], [sinB, 0, cosB]]. The sun light's local rotation is R1 × R2. The light direction `worldDir` is the first column: **worldDir = (cosA·cosB, −sinA·cosB, sinB)**. This is the direction in which the light travels. The upload negates it. The vector in `PS b2[0]` points **toward the light**: (−cosA·cosB, sinA·cosB, −sinB). **For Z = 90°, the light travels along +Z. The uploaded toward-light vector is −Z. This puts the key light below the scene. This is unverified against a capture.** For a light above the scene, sinB must be negative, for example B = 270°. For A = 90° and B = 0, worldDir = (0, −1, 0) and the uploaded vector is (0, +1, 0). | Verified (construction), high. Parent frame of the sun node: inferred, medium. Sign on screen: unverified. |
| **40. Does the sun cascade and mask run in an interior?** | The cascade update, the shadow selector, its accumulate virtual and the mask pass `RenderShadowmasks` contain no branch on the interior byte `0x1420d68f4` or on the current cell. The interior byte has two effects on the sun path. It selects the active shadow distance. It also clears near Lighting key bit 13 and selects the plain sun wrapper in the near Lighting light selector. The cascade update returns early only if bit 0 of the flag word of the sun's own `NiDirectionalLight` is set. That bit starts clear. `Sun::Update` never writes the flag word of the light. In sky mode 0 it writes no flag word at all. In sky modes 1 and 2 it sets bit 0 on the two sky mesh nodes. In sky mode 3 it also writes `Sun+0x08`. A scan found no writer of bit 0 on the light. The scan is not a proof. So the cascade and the mask pass are **not shown to be off** in an interior. The near Lighting sun term does not use the mask in an interior, because key bit 13 is never set there (reading from #1258 G08). Other consumers of the mask: not checked. Draw behaviour: unverified. | Verified for the code paths read. Medium for "it runs". Unverified: executed draws. |

| Item | Evidence record |
|---|---|
| Status | OBSERVED for verified claims. Inferred and unverified claims are marked. Static only. No capture. |
| Author / human operator | A Sonnet 5.5 research run (`claude-sonnet-5-5`) for the department operator. A later Sonnet 5.5 run applied the review corrections and re-read key items. |
| Reviewer | A separate fresh-context Sonnet 5.5 run (`claude-sonnet-5-5`). Sol was unavailable on a usage limit. See "Independent review". |
| Date | 2026-11-25 CST. Author run from 15:13. Independent review 15:42 to about 16:02. Corrections applied after 16:02. |
| Build | `sse-steam-1-7-104`, retail `1.7.104.0`, Steam build 24914197. Measured executable SHA-256 `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f` equals the asserted pin in [builds/target.json](../builds/target.json). |
| Principal function RVAs | `0x14ec3b0` (ambient cache builder), `0x203ed0` (DALC record loader), `0x2bc790` (cell DALC fetch), `0x2bbfe0` and `0x2bc050` (cell angle getters), `0x2bc020` and `0x2bc090` (cell angle setters), `0x416490` (weather colour mixer), `0x41bd90` (sun update), `0x1549550` (per-geometry Lighting upload), `0xf045c0` (directional light world data), `0x15a8050` (sine and cosine pair), `0x1d6580` (3×3 multiply), `0x150f3d0` (scene sun setter), `0x1539a70` (shadow masks), `0x15389b0` (shadow selector), `0x157f080` (cascade camera update), `0x157ead0` (accumulate), `0x151a160` (pass builder), `0x1569550` (pass light selector). Function labels are GUESS unless a CrashLogger name appears. |
| Source exposure | Pinned native binary analysis. One decoded shipped near Lighting pixel-shader record was read as text for its constant rows and its sun dot product. No shader text is reproduced here. Committed CrashLogger type and name tables on `origin/main`. **No value was read from any game plugin.** This file holds no record field value and no example cell value. No decompiler text and no disassembly appears below. No downstream or sibling source was used. |
| Name provenance | Names marked `CRASHLOGGER_PDB(59818@2026.10.24)`: `INTERIOR_DATA` (`directionalXY` at `+0x14`, `directionalZ` at `+0x18`, the directional ambient block at `+0x28`), `BGSDirectionalAmbientLightingColors`, `Directional`, `MaxMin<Color>` (`max`, `min`), `Sun` (`SkyObject::root` at `+0x08`, `sunBaseNode` at `+0x10`, `sunGlareNode` at `+0x18`, `light` at `+0x38`, `cloudLight` at `+0x40`), `NiAVObject::flags`, `NiDirectionalLight::worldDir`, `ShadowSceneNode` (`sunLight` at `+0x200`, `cloudLight` at `+0x208`, `sunShadowDirLight` at `+0x210`), and the function names `Sun::Update`, `BSShadowDirectionalLight::UpdateCamera`, `RenderShadowmasks`, `UpdateNiCameraTransform` and `VATS::SetVATSLight`. All other function labels are GUESS. |
| Intended recipient | Skyrim Research department lead for boundary review under [docs/clean-room.md](../docs/clean-room.md). Proposed use: Mudcrab research items 41, 45 and 40. Maintainer transfer decision pending. |

Code addresses (functions and evidence ranges) are RVAs for image base `0x140000000`. Global data addresses are VAs. `PS b2[i]` is constant buffer 2, float4 element `i`. **Verified** means re-read at the cited static source. **Inferred** means a deduction with assumptions. **Unverified** means the evidence leaves the claim open. The document holds facts and formulas only.

## Question and method

Item 41: which of the six DALC colours is the positive side of each axis, and in which space. Item 45: how the engine builds the interior directional light direction from the two cell angles, and its sign. Item 40: whether the sun cascade update and the mask pass run in an interior, and what sets bit 0 of the flags of the sun light.

Method: native range reads of the functions above, compiled constants read from the pinned image, the committed type tables, and listing searches. The searches ran with and without the `0x` prefix. A numeric script rebuilt the closed formulas from the decoded matrices. It asserts that the matrix product equals the closed form.

## Observations

### G01. DALC face order and axis signs (item 41)

**Verified.** The cache builder `0x14ec3b0` takes a pointer to six consecutive RGB float triples (stride 12 bytes, F0 first) and a pointer to a seventh colour. For each channel it stores `(F1 − F0) × 0.5`, `(F3 − F2) × 0.5` and `(F5 − F4) × 0.5` as the three slopes. It stores `(F0 + … + F5 + G) × 0.16666667` as the intercept. `G` is a zero colour at `0x14331d6f0` (image value 0, no store found). The constants are `0.5` at `0x141b5be14` and `0.1666666716` at `0x141869dd8`. Both were read. The slopes sit per channel at `0x1420d6978` to `0x1420d6998`. The intercepts sit at `0x1420d699c` to `0x1420d69a4`. Evidence at `0x14ec3ba–0x14ec686`.

**Verified.** The pixel shader evaluates one dot product per channel: `dot((slopeX, slopeY, slopeZ, intercept), (N.x, N.y, N.z, 1))`. The rows come from `PS b2[11]`, `b2[12]` and `b2[13]`. This was read in the decoded near Lighting record `00000001` (#1003 G02). In that record, `N` is the normalised normal that the sun term also uses. The sun term is `saturate(N · b2[0])`. `b2[0]` points toward the light (G04). A positive component of N therefore moves the result toward the odd-index face of that axis.

**Verified.** As the engine evaluates the cube:

| Face index (serialized order) | Axis side | Slope it enters |
|---|---|---|
| F0 | −X | slope X, with a negative sign |
| F1 | +X | slope X, with a positive sign |
| F2 | −Y | slope Y, with a negative sign |
| F3 | +Y | slope Y, with a positive sign |
| F4 | −Z | slope Z, with a negative sign |
| F5 | +Z | slope Z, with a positive sign |

For a normal exactly along an axis, the result is not the face colour. For N = +X it is `(4·F1 − 2·F0 + F2 + F3 + F4 + F5)/6`. For N = −X it is `(4·F0 − 2·F1 + F2 + F3 + F4 + F5)/6`. The same pattern holds for Y and Z. Equal colours on one pair give no slope on that axis.

**Verified.** The record order is the memory order in all three producers. No permutation exists between the record bytes and the builder input.

1. The interior fetch `0x2bc790` copies the seven packed RGB dwords at cell lighting struct `+0x28` to `+0x40` to the seven output triples. The destination index arithmetic reduces to the identity for entries 0 to 5. Entry 6 goes to the separate pointer. The float at `+0x44` goes to the power output.
2. The cell record handler reads the 0x60-byte `XCLL` subrecord raw into that struct (`0x2b8933–0x2b8985`).
3. The weather and lighting-template `DALC` loader `0x203ed0` reads 0x20 raw bytes (seven colours and one float). It swaps bytes only on the big-endian path.
4. The weather mixer `0x416490` loops over the seven colour indexes. It reads source dword `weather + 0x7f8 + 4·(i + 8·slot)` and writes output triple `i` at `sky + 0x200 + 12·i`. Entry 6 goes to `sky + 0x248`. The weights do not depend on `i`. #1003 G02 states the same.

**Verified.** The cell colour bytes are read as R, G, B in byte order (byte 0 first) and divided by 255 (`0x141b5bdc8` = 0.003921569).

**Interpretation, medium.** The committed type tables (`CRASHLOGGER_PDB(59818@2026.10.24)`) describe the six colours as `Directional { MaxMin<Color> x, y, z }` with `MaxMin<Color> { max, min }`. In record order the colours are named x.max, x.min, y.max, y.min, z.max, z.min. The first colour of each pair is named `max`. The evaluator above gives the first colour the negative side, because the slope is the second colour minus the first. The names are labels from the debug table. They do not show which world side `max` means. This run read no plugin and no editor. If `max` means the positive side, retail applies each pair swapped, or the labels are mirrored. Only a capture of a cell with two very different colours on one pair can settle this. The engine rule above holds whatever the label is. Use of these names here is name use only: `CRASHLOGGER_PDB(59818@2026.10.24)`.

**Confidence: high** for the index-to-axis table in the space of the evaluated normal. **Unverified:** the editor field names, the meaning of `max`, and which world direction is "up" for +Z. The Z-up reading is **inferred** from the sky frame (G05).

### G02. Space of the evaluation (item 41)

**Verified.** The per-geometry upload `0x1549550` reads the cache rows. On its model-space branch it multiplies each channel's slope triple by the transpose of the geometry rotation: uploaded slope = Rᵀ × slope in world axes. The intercept stays unchanged (`0x1549bd5–0x1549e83`). On the other branch it copies the slopes unchanged, in world axes. The stock object and near paths use the model-space branch (#1003 G02), with the model-space normal from the pixel shader. The two forms give the same lighting for the same surface. So the table in G01 holds in world axes whatever the branch, when N is in the matching space.

**Confidence: high.** The branch selector itself is taken from #1003 G02. This run did not re-read it.

### G03. Worked example (item 41)

**Verified (arithmetic from the verified formula).** Take one colour channel. F0 = F1 = F2 = F3 = m, F4 = a and F5 = b. A surface with its normal along +Z in world space gets `(4m + a + b)/6 + (b − a)/2 = (2m − a + 2b)/3`. F5 (odd index, +Z) has weight 2/3. F4 has weight −1/3. The other four have weight 1/6 each. With m = 0.5, a = 0.8 and b = 0.2, the result is 0.2, so the F5 colour dominates. A normal along −Z gives 0.8. For a horizontal normal, the Z slope adds nothing. For N = +X the result is the mean, 0.5. The sum is not saturated. A negative weight can drive a channel below zero. No clamp exists before the pixel-shader tail (#1258 G02).

A second example, recomputed for this file: F0 to F5 = 0.2, 0.6, 0.1, 0.3, 0.4, 0.0. The slopes are 0.2, 0.1 and −0.2. The intercept is 0.26667. For N = +X the result is 0.46667. It is not F1 = 0.6. For N = +Z the result is 0.06667. It is not F5 = 0.

**Confidence: high.** Both examples were checked numerically.

### G04. Interior key-light direction: construction (item 45)

**Verified.** `Sun::Update` (`0x41bd90`, `CRASHLOGGER_PDB(59818@2026.10.24)`) handles sky modes 0, 1 and 2 with one code shape. Mode 0 is at `0x41be35–0x41c00b`. Modes 1 and 2 are at `0x41c63b–0x41c7fc`. With a current interior cell (`TES+0xc0` non-null), it calls the cell getters `0x2bbfe0` (value at cell lighting struct `+0x14`, PDB name `directionalXY`) and `0x2bc050` (`+0x18`, `directionalZ`). Without a cell it reads the Sky lighting template (`Sky+0x28`) through two template getters (`0x295700` and `0x295730`) and builds the same matrices. Each cell getter returns a 32-bit unsigned integer. Each getter returns the template value instead when inherit flag bit 5 (`0x20`, struct `+0x58`) is set and the template pointer exists (`0x2bbfe0–0x2bc07b`).

**Verified.** The code converts each value as an unsigned 64-bit integer to float and multiplies it by `0.01745329238` (`0x1418121c8`, read). So the stored unit is **degrees**. The record load and `Sun::Update` apply no clamp and no wrap other than sine and cosine. The two cell setter functions (`0x2bc020` and `0x2bc090`) limit the stored value to 360 with an unsigned compare. The setters are not on the load path. A stored number above 360 from a record would therefore pass unchanged to sine and cosine. A negative stored number would convert as a very large unsigned value (**inferred** risk). This run read no plugin value.

**Verified.** The pair function `0x15a8050` returns (sin x, cos x) in its two lanes. Its short path returns (x, 1 − x²/2) when |x| is below 1.22e-4. Its general path computes the sine of x and of |x| + π/2. The constants are read: `0x141b53ac0` = 1.2207e-4, `0x141b53ad0` = 1.5707964, `0x141b53ab0` = 0.5.

**Verified.** With A the XY angle in radians and B the Z angle in radians:

- R1 (from A) has rows (cosA, sinA, 0), (−sinA, cosA, 0), (0, 0, 1). In the column-vector convention this is a rotation by −A about Z (`0x41c696–0x41c6cd`).
- R2 (from B) has rows (cosB, 0, −sinB), (0, 1, 0), (sinB, 0, cosB). In the column-vector convention this is a rotation by −B about Y (`0x41c746–0x41c7b1`).
- The function `0x1d6580` computes out = first argument × second argument. This is the standard row-major product. The call passes R1 first and R2 second. The result goes to the local rotation of the sun light at light `+0x48` to `+0x68` (`0x41c7c5–0x41c7fc`; mode 0: `0x41bfc4–0x41bfda`).
- The first column of R1 × R2 is (cosA·cosB, −sinA·cosB, sinB).

**Verified.** `NiDirectionalLight::UpdateWorldData` (`0xf045c0`) copies the first column of the **world** rotation (world rotate `+0x7c`, `+0x88`, `+0x94`) to `NiDirectionalLight::worldDir` (light `+0x140` to `+0x148`). The Lighting upload `0x1549550` loads `worldDir` and flips the sign of each component with the sign mask at `0x141b5c730` (`0x1549b28–0x1549b6e`). It then calls two imported helper thunks before it sets `PS b2[0]`. On the stock branch, the first thunk (`0x15a9c96`) receives the negated vector and a 3×3 matrix. The second thunk (`0x15a9c90`) receives the constant-slot address and the vector. #1003 G03 states that the stored direction is normalised. This run did not resolve the imported helpers. It cannot confirm the normalisation or the exact transform. The sign and the column rule do not depend on them.

**Verified (closed form).** Assume that the world rotation equals the local rotation. Then:

- `worldDir = (cosA·cosB, −sinA·cosB, sinB)`. This is the direction in which the light travels.
- The uploaded direction toward the light is `(−cosA·cosB, sinA·cosB, −sinB)`.

The numeric check reproduces these for the eight (A, B) pairs of G05. The exterior path uses the same chain. It builds a vector (−p, −25, −100) from image constants and stores it as the first column of a matrix (`p` = 400 at `0x14209e960`, `25` at `0x14209e978`, `−100` at `0x14209e990`, `400` at `0x14209e9a8`; read). A helper at `0x2b6540` (not read) comes before the store. In the exterior the first column points down, and the uploaded toward-light vector points up. This agrees with the sign statements of #1003 and #1248: **first column = direction of travel, uploaded vector = its negation.**

**Confidence: high** for the matrices, the product order, the column and the negation. **Medium** for "world rotation = local rotation" (G05).

### G05. Worked examples, defaults and limits (item 45)

**Verified (arithmetic, recomputed for this file).**

| XY angle A | Z angle B | worldDir (travel) | uploaded (toward the light) |
|---|---|---|---|
| 0° | 0° | (1, 0, 0) | (−1, 0, 0) |
| 90° | 0° | (0, −1, 0) | (0, 1, 0) |
| 180° | 0° | (−1, 0, 0) | (1, 0, 0) |
| 270° | 0° | (0, 1, 0) | (0, −1, 0) |
| any | 90° | (0, 0, 1) | (0, 0, −1) |
| any | 270° | (0, 0, −1) | (0, 0, 1) |
| 45° | 315° | (0.5, −0.5, −0.707) | (−0.5, 0.5, 0.707) |

**Z = 90°.** The light travels along **+Z**. The uploaded vector, which points from the scene toward the light, is **−Z**. So the key light is below the scene. This is **unverified against a capture**. The result does not depend on A. For a light above the scene, sinB must be negative. The setters limit B to 360. So B between 180° and 360° puts the light above the scene.

**Verified.** Edge cases of the same code. A cell with no lighting block gives A = B = 0, because the getters return 0. Then worldDir = (1, 0, 0). With no cell and no template, the code starts from an identity matrix and sets the matrix entries at positions 3 and 6 to −0.7853982 (`0xbf490fdb`, at `0x41c7d6` and, for mode 0, at `0x41bfe2`). The first column is then (1, −0.785, −0.785). The uploaded vector, if it is normalised, points toward (−1, 0.785, 0.785) after normalisation.

**Inferred, medium.** The light is attached to the Sun root node (`Sun+0x08`) with `AttachChild` (`0x41bab0–0x41babe`). The world rotation equals the local rotation only if the parent chain has an identity rotation. This run did not decode the writers of the Sun root's rotation. `Sun::Update` writes only translation and scale on the Sun root. The exterior path gives a down-pointing first column in the same local frame. Both facts support a frame without a Z flip. A yaw in the parent chain is not excluded.

**Unverified.** The rotation sign against a live capture or the editor display. A capture of one interior with a known XY and Z angle would settle it. The Z range that the editor offers is not read.

**Confidence: high** for the algebra. **Medium** for the world frame. **Unverified** for the on-screen sign.

### G06. The sun light object and its flag word (item 40)

**Verified.** The cascade update (`0x157f080`, `BSShadowDirectionalLight::UpdateCamera`, `CRASHLOGGER_PDB(59818@2026.10.24)`) loads `[wrapper+0x48]` and tests bit 0 of the dword at `+0xf4` of that object (`0x157f0f7–0x157f102`). It returns early when the bit is set. The setter virtual `0x1576ad0` stores the light pointer to wrapper `+0x48` (`0x1576af2`). The scene setter `0x150f3d0` installs that pointer into the sun wrapper `scene+0x200` and the shadow wrapper `scene+0x210` (`0x150f469`, `0x150f561`). Its only caller (`0x65c1bc`, inside `Main::PostReloadInit`) passes `Sky+0x80` (Sun), then `+0x38` (`Sun::light`). So the tested object is **the sun's `NiDirectionalLight` itself**. It is not a parent. It is the same object in every cell type. If the passed pointer is null, the setter creates a black default light (static only). This sharpens the wording "the light's attached object" in #1248 G07.

**Verified.** `NiAVObject::flags` is at `+0xf4`. The constructor chain sets it to zero, then applies `|= 0xE` and `&= ~0x10` (`0xee1181–0xee11ad`). A new light therefore has bit 0 clear. The `NiDirectionalLight` and `NiLight` constructors (`0xf04570`, `0xeed140`) do not change the flags.

**Verified.** `Sun::Update` never writes the flag word of the light. It writes the `+0xf4` word of only these objects. In sky mode 3, it writes the Sun root (`Sun+0x08`, bit 0 := NOT bit 5, `0x41c029–0x41c042`). In sky mode 3 it also writes the sun base node and the glare node (`Sun+0x10` and `Sun+0x18`, `0x41c5bd–0x41c62f`). In sky modes 1 and 2 it sets bit 0 on those two nodes (`0x41c803` and `0x41c80e`). Sky mode 0 reaches `0x41c815` directly from `0x41bfdd` and `0x41c00b`. It skips the flag writes at `0x41c803` and `0x41c80e`. So in sky mode 0 (cell present, or no lighting source) it writes no flag word. None of the writes targets `Sun+0x38` (light) or `Sun+0x40` (cloud light).

**Verified (negative scan, limited).** Only `Main::PostReloadInit` reaches the light through `Sky+0x80`, then `+0x38`. This is a scan of eight-line windows over the saved listing, plus the seven references to the Sky singleton `0x143230518`. The image holds 371 read-modify-write stores to `[reg+0xf4]` with an immediate. About 211 use the immediate 1 or −2. This run did not attribute most of them to objects. A scan for a bit-0 store after a load from `[reg+0x48]` found one function, `VATS::SetVATSLight`. It is not the sun wrapper. The colour-stage function `0x1539f10` and the two render functions at `0x1537ab0` and `0x1537b10` clear or set bit 0 on the object at global `0x1434362d8`. They restore the old bit. The interior point-light finding (#1258 G08) left this object unidentified. This run reads it as the render camera. That reading is inferred, medium. The render function `0x1537420` (`UpdateNiCameraTransform`, `CRASHLOGGER_PDB(59818@2026.10.24)`) reads the world translation of the same object (`+0xa0` to `+0xa8`). It stores the negation in the camera-position globals at `0x143436318` to `0x143436320` (`0x15374c1–0x1537510`).

**Inferred, medium.** No writer of bit 0 on the sun light exists on the paths read. So bit 0 stays clear. The cascade update then does not return early in an interior or anywhere else. The scan cannot exclude writes through aliased pointers, block copies, virtual calls or scene-graph passes that this run did not read.

**Confidence: high** for the object identity, the default flags and the `Sun::Update` writes. **Medium** for "nothing else sets it". A writer found through a differently shaped access, or a runtime watch of the word, would change this.

### G07. Interior entry conditions of the sun shadow and mask passes (item 40)

**Verified.** The shadow selector (`0x15389b0`, called from the list-accumulation job at `0x1538381`) works on `scene+0x210`. When byte `0x143436311` is zero, it calls the accumulate virtual of that wrapper (vtable `0x141b4e5f8`, slot `+0x48` = `0x157ead0`). It then sets its running count to one (`0x1538a0b–0x1538a5b`). It tests no interior flag, no cell data and no light colour. At its end it stores the count to `0x143436300` (`0x1538ee0`). The accumulate routine (`0x157ead0`) loops over the cascade slots. It has no interior test. The byte `0x143436311` has nine reads and no direct store. Its image value is 0 (#1248 G07).

**Verified.** `RenderShadowmasks` (`0x1539a70`) returns at once unless byte `0x1420d6811` is nonzero or the count at `0x143436300` is greater than zero (`0x1539a7a–0x1539a9b`). It has no reference to the interior byte `0x1420d68f4` or to the Tes singleton `0x1432303b8`. No reference to that singleton exists anywhere at or above RVA `0x1400000`. The image holds five references to the interior byte. They are the distance setter `0x14ebf00` and its twin `0x14ebf40`, the pass builder (`0x151a64f`), the water property key (`0x152c972`: it sets key bit 5, `0x20`, when the byte is nonzero) and an image-space setup read (`0x1541434`, use not traced).

**Verified.** The distance setter writes the global `0x1434869a8`. It stores `fInteriorShadowDistance` (3000 compiled, read at `0x1420d9038`) when the interior byte is set. Otherwise it stores `fShadowDistance`. The cascade update reads `0x1434869a8` (`0x157f12a`). So the cascade update has no interior branch, but it takes a different distance in an interior. The setting names are strings of the pinned image. This run did not re-read the strings.

**Verified (from #1258 G08; the pass builder and the selector were re-read here).** The pass builder sets a local flag to 1 only when the interior byte is 0 (`0x151a64f–0x151a65d`). The builder sets raw key bit 13 only when that flag is nonzero (`0x151aa20–0x151aa27`). The light selector only clears the flag. With the flag at 0 (interior) the selector uses the plain sun wrapper `scene+0x200`. With the flag at 1 it uses the shadow-directional wrapper `scene+0x210`. Bit 13 selects the pixel shaders that multiply the sun term by the mask sample `t14.x`. That last statement is #1258 G08's reading of the decoded pixel-shader records. This run did not decode those records again. So in an interior the near Lighting sun term does not read the sun mask, although the mask pass is not shown to be off.

**Verified.** `Sun::Update` in the interior modes still writes the cell directional colour to `NiLight.diffuse` and the flat cell ambient to `NiLight.ambient` (`0x41c815–0x41c84f`). It keeps the light object in the scene wrapper. So the cascade update has a light with a valid direction (G04) in an interior.

**Interpretation, medium.** By static reading, an interior runs the sun cascade setup and the mask pass each frame whenever byte `0x143436311` is zero. The shader families that still request the mask consume the result. This run did not check whether any family does so in an interior. Water, grass, LOD and volumetric effects are open. No test of a black or absent cell directional light exists before the shadow work.

**Confidence: high** for "no interior branch on these paths". **Medium** for "it runs". **Unverified:** executed draws, the live value of byte `0x143436311` and of byte `0x1420d6811`, and consumers outside near Lighting.

### G08. Scope notes for earlier findings

**No numerical or sign correction is needed.** The sign and column statements of #1003 G03 hold. The face-order statement of #1258 G09 ("which face is the positive axis was not verified") was true when written. G01 here answers it. The open points of #1248 G07 and #1258 G08 are narrowed by G06 and G07.

Two **clarifications**, not corrections:

1. The "light's attached object" of #1248 G07 is the sun's light itself (`[wrapper+0x48]`, the object `SetSunLight` received).
2. The object at `0x1434362d8`, which #1258 G08 left unidentified, is read as the render camera (inferred, medium).

Two **scoped notes** for #1258:

1. #1258 G08 says `Sun::Update` sets bit 0 on the two sky mesh objects "in its interior branch". It does so in sky modes 1 and 2. In sky mode 0 it writes no flag (G06).
2. Optional sentence for #1258 G09: "The statement that the positive axis was not verified is now answered by the interior-light small-items finding G01: the first colour of each pair is the negative side, in the space of the normal that the pixel shader uses."

## Interpretation and alternatives

- The face table has one simple reading. The first colour of each pair is the negative axis. The alternative is that the editor labels are mirrored. The binary cannot tell these two apart. The debug-table names `max` and `min` do not settle it.
- The direction formula assumes a rotation-free parent. A rotated parent would rotate the whole answer. The exterior consistency argument makes this unlikely but does not prove it.
- Sky mode 0 builds the same rotation. The nodes that show the sun disc are not hidden there. This does not change the light.
- A light below the scene at Z = 90° is a surprising result for a key light. The missing capture matters for any user of this result. Check this item first.

## Negative results and limitations

- Static only. No capture, no runtime watch and no editor.
- No plugin value was read. No example cell value or record field appears in this file.
- The sign of the XY and Z rotations against the editor display is unverified.
- The parent frame of the sun node is inferred. The writers of the Sun root's rotation were not decoded. A yaw there would rotate the answer.
- The imported helper thunks `0x15a9c90` and `0x15a9c96` were not resolved. They may normalise or transform the uploaded vector. The sign and the column rule do not depend on them. The exact uploaded length is not shown.
- Writers of flag bit 0 on the sun light are not proven absent. The scan is a pattern search over a listing. Aliased pointers, block copies and virtual calls could still write it.
- Other consumers of the sun mask in an interior (water, grass, LOD, volumetric effects) were not checked. The effect of the image-space read of the interior byte (`0x1541434`) was not traced.
- Key bit 13 and its pixel-shader meaning come from #1258 G08. This run did not decode those records again.
- One decoded pixel-shader record supports the ambient evaluation. Other near Lighting families were not swept.
- The exterior helper at `0x2b6540` was not read.

## Relation to earlier findings

- **#1003** (object LOD ambient, sun and colour output): G01 to G03 here agree with its G02 and G03. They cover the DALC cache builder, the order kept through the weather mixer, and the negated first column of the sun direction. This finding adds the sign of each axis, the angle types and the matrices. No correction to #1003.
- **#1248** (sun shadow remainder): G06 and G07 here answer parts of its G07. The tested object is the sun light itself. The interior byte changes the shadow distance. See G08 for the two clarifications. No numerical correction.
- **#1258** (interior point-light look; open pull request when this file was written): G01 here answers the face-order point of its G09. G06 here identifies the object at `0x1434362d8` and narrows its statement about `Sun::Update` flag writes. G07 here re-reads its key-bit-13 chain. No numerical correction.

## Independent review

A separate fresh-context Sonnet 5.5 run reviewed the author's draft. Sol was unavailable on a usage limit. The reviewer saved its independent results for items 41, 45 and 40, one after the other, **before it read the draft and the author's handoff**. Its input list also names published #1003 and #1248, the committed type tables and an earlier private draft of #1258. The record does not show whether it read that earlier draft before its independent results. The reviewer's agreement on points that draft also states (key bit 13, the object at `0x1434362d8`) is therefore weaker. The reviewer rebuilt these areas from the binary: the record loaders and the weather mixer, the cache builder and its global layout, the evaluator and the upload branches, one decoded pixel-shader record, the angle getters and setters, the matrices and the product order, the world-data copy, the upload negation, the cascade update flag test, the flag writers, the interior byte readers and the key-bit logic. It then compared the draft group by group.

| Group | Outcome | Note |
|---|---|---|
| G01. Face order and signs (41) | Confirmed, one addition | Same formulas and table. The reviewer added the debug-table names `max` and `min`. Applied. |
| G02. Space of evaluation (41) | Confirmed | Sibling upload re-derived. The branch selector relies on #1003 G02. |
| G03. Worked example (41) | Confirmed | Both closed forms and weights checked by hand. |
| G04. Construction (45) | Corrected | The cell setters clamp the angles to 360. The normalisation of the uploaded vector was not re-read. Applied. |
| G05. Examples, defaults, limits (45) | Confirmed | Seven table rows and the Z = 90° result recomputed. The parent frame stays inferred. |
| G06. Sun light object and flag word (40) | Corrected | The wrong finding was cited for the object at `0x1434362d8`. Sky mode 0 writes no flag. Applied. |
| G07. Entry conditions (40) | Corrected | The wrong finding number was cited for key bit 13. "No interior test" needed the distance and key-bit scope. Applied. |
| G08. Earlier findings | Corrected | The same attribution points as G06 and G07. Applied. |

Result: 4 confirmed, 4 corrected, 0 rejected, 0 wholly unverified. The reviewer did not verify: the sun mask pass in an interior frame, the pixel-shader meaning of key bit 13 (taken from #1258), the imported helper thunks, the parent chain of the Sun root, the exterior helper at `0x2b6540` and other consumers of the sun mask.

After the review, a later Sonnet 5.5 run applied the corrections. It also re-read 17 key items in the pinned image. Each matched the text above.

1. The cache builder: slope formulas for all three axes and the intercept sum, with the constants 0.5 and 1/6.
2. The zero colour `G` at `0x14331d6f0` and its two neighbours (image value 0).
3. The cell fetch `0x2bc790`: the destination index equals the source index for entries 0 to 5. The bytes are read R, G, B and scaled by 1/255.
4. The `DALC` loader `0x203ed0`: a raw read of 0x20 bytes, with byte swaps only on the guarded path.
5. The weather mixer: source index `i + 8·slot`, destination `sky + 0x200 + 12·i`, and entry 6 at `sky + 0x248`.
6. The pixel-shader record: three `dp4` rows from `b2[11]` to `b2[13]` on the normalised normal, and `dp3_sat` of the same normal with `b2[0]`.
7. The angle getters: offsets `+0x14` and `+0x18`, and the inherit bit `0x20` at `+0x58`.
8. The angle setters: the clamp to 360 (`0x168`) with an unsigned compare.
9. The angle types and conversion: an unsigned 64-bit convert and a multiply by the constant at `0x1418121c8`.
10. The sine and cosine pair and its constants.
11. The two rotation matrices in `Sun::Update` (cell path and default path).
12. The 3×3 multiply: operand order and the first column of the product.
13. The world-data copy to `worldDir` and the sign flip at upload, with the two thunk calls.
14. The constructor flags (`|= 0xE`, `&= ~0x10`) and the cascade update bit-0 test.
15. The mode 0 jumps that skip the flag writes, and the default matrix entries of −0.7853982.
16. The `RenderShadowmasks` gates, the selector call and the interior byte in the key builder.
17. The worked examples: both ambient examples, the N = +X and N = −X closed forms, and the angle table, recomputed by script.

Source exposure of the review: pinned native binary and committed tables. One decoded shipped pixel-shader record was read as text. This is a static review. It is not match evidence for any function. It does not decide transfer eligibility.

Reviewer and outcome: Reviewed independently by a Sonnet 5.5 run. Outcome: 4 confirmed, 4 corrected, 0 rejected. Static evidence only. Transfer status: UNREVIEWED.
