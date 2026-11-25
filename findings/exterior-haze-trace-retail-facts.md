Transfer status: UNREVIEWED

# Finding: which term tints distant opaque geometry toward the fog colour in the ordinary exterior frame

## Answer

| Question | Answer |
|---|---|
| Which term tints a distant LDR opaque pixel (terrain, terrain LOD, object LOD, near objects) toward the fog colour? | **Verified, high (arithmetic and call order). Static only.** The tint is the blend term of a full-screen composite pass. It runs after the first accumulator stage (flags `0x41`-class, `T = 0`) and before the second accumulator stage (flags `0x40`-class, which adds `T = 1` for its sorted draws). The names "opaque" and "blended" for the two stages come from #1061 G01–G03. This run read only the flag bits. With the default settings the pass is `ISSAOCompositeSAOFog` (shader record 53 of the trailing block, G05). Per RGB channel: `out = saturate( k × ( (1−Fc) × A × L + Fc × Cfc ) )`. `L` is the scene colour from the first stage. When the SSR flag `cb2[10].z` is above 0.5 and the mask test passes, `L` also holds a clamped reflection term (G05). `A` is the AO factor. `Fc` is a per-pixel fog strength from the depth texture. `Cfc = nearRGB + Fc × (farRGB − nearRGB)`. The term that tints is `Fc × (Cfc − A × L)`. The same scale `k = 1/FramebufferRange` multiplies every pixel with depth below 0.999999. Pixels with depth of 0.999999 or more skip the fog and the `k` scale. The composite runs once per run of the world render function `0x1539f10` (one direct caller, `0x6576be`). Other camera, reflection or menu renders were not examined. |
| Why does the Lighting PS tail show no tint? | **Verified, high.** For (S,T) = (1,0) the PS tail returns `L − max(0, k×M − B)`. It uses the fogged value `M` only as an overflow limiter. It does not write the fogged colour. The earlier algebra is right. Reading it as "no fog in the frame" is wrong (G09). |
| Is the fog blend in the colour of opaque pixels a vertex-interpolated value? | **Verified for the decoded families, high. Static only.** For Lighting draws at (S,T) = (1,0) the interpolated `(Cf, F)` reaches target 0 only through the overflow limiter. The fog blend in the colour comes from the image-space composite. It computes `Fc` per pixel from the depth texture, with linear view depth and not the vertex `|clip.xyz|` distance. The interpolated `(Cf, F)` is written as colour only for T=1 draws. The effect and water pixel shaders (shader groups 5 and 8) blend the interpolated fog themselves. Distant tree, particle, sky and utility shaders were not shown to add or to omit fog. |
| Other candidates | (a) `L` is not already fogged: **verified**. (b) A separate pass after the colour stage: **yes, this is it**. (c) Water or height fog: **no height or sun-direction term** in the decoded fog records (Lighting VS and PS, composite records 49, 51 and 53, effect and water pixel tails). Distant tree, sky and particle shaders were not decoded for it. Water has its own fog reader (G07). (d) A different terrain branch: **no**. All checked PS records share the same tail (G01). |
| Setting dependence | **Verified.** The composite fog needs `bSAOApplyFog` (default 1) and a fog property for the scene. `bSAOEnable` (default 1) only selects which record runs. If `bSAOApplyFog` is 0 there is no composite fog (G04). The console command `ToggleFog` flips the same cached byte. |

| Item | Evidence record |
|---|---|
| Status | OBSERVED for verified claims. Inferred and unverified claims are marked. Static only. No game launch, no capture and no visual claim. |
| Author / human operator | A Sonnet 5.5 research run (`claude-sonnet-5-5`) / Taylor. |
| Reviewer | A separate fresh-context Sonnet 5.5 run (`claude-sonnet-5-5`). Sol was unavailable on usage limits. See "Independent review" below. |
| Date | 2026-11-24 CST. The author run took 02:35 to about 03:30. The independent review took 02:59 to 03:47. The corrections were applied from 03:48. |
| Build | `sse-steam-1-7-104`, retail `1.7.104.0`, Steam build 24914197. Measured executable SHA-256 `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f` equals the pin in [builds/target.json](../builds/target.json). |
| Main function RVAs (image base `0x140000000`; add it for a VA) | `0x1539f10` (main colour stage), `0x1541f40` (SAO and fog composite pass, GUESS), `0x1542c66` and `0x1543004–0x1543103` (composite fog constants), `0x154c010` (Lighting fog writer), `0x1548614` (its call), `0x1548626–0x1548656` (clamp upload), `0x100ae80` (frame constant writer), `0x158bb00`, `0x158bc40`, `0x158bd80` (composite constant upload), `0x14ec040` (scene fog property getter), `0x37d490` (`ToggleFog` handler). |
| Sources and revisions | Pinned executable. Shipped shader member `shadersfx/shaders011.fxp` (SHA-256 `72cfc73eb0938d5949f0b3a8683722a33b671a34b41b750ba138de8d154c5fbc`, the same member as #1003 and #1061) from `Skyrim - Shaders.bsa`. Shipped INI templates and the compiled setting defaults of the image. Published cross-checks: #812, #979, #1003, #1061. |
| Source exposure | Pinned native binary analysis and shipped shader bytecode (decoded offline). No plugin value is quoted. No sibling, downstream or leaked source. No decompiler text or disassembly appears below. Transfer needs review under [docs/clean-room.md](../docs/clean-room.md). |
| Name provenance | All function and group labels are GUESS. Class names (`BSWaterShader`, `BSGrassShader`, `BSEffectShader`, `BSDistantTreeShader`) come from RTTI in the pinned image. Effect names `ISSAOComposite`, `ISSAOCompositeSAO`, `ISSAOCompositeFog`, `ISSAOCompositeSAOFog`, `ISLightingComposite`, the console command `ToggleFog` (short `tfog`) and the setting names come from strings in the image. `BSFogProperty` follows the earlier findings and carries `CRASHLOGGER_PDB(59818@2026.10.24)`. |
| Reproduction | The trailing block of `shaders011.fxp` starts at byte 67608796 of the member, after the 79th group. It holds 93 DXBC records. Cut it at each `DXBC` signature by the size at `+24`. The first signature is at byte 67608848. Decode the records offline with the `fxc /dumpbin` tool. Records 49, 51 and 53 begin at member bytes 67672140, 67678920 and 67686096. |
| Intended recipient | Skyrim Research department lead for boundary review under [docs/clean-room.md](../docs/clean-room.md). Proposed use: Mudcrab PR #953 (issue #946 line). Maintainer transfer decision pending. |

Addresses are RVAs for image base `0x140000000`. **Verified** means re-read at the cited static source. **Inferred** means a deduction with stated assumptions. **Unverified** means not read or not resolvable statically. `cbN[i]` is constant buffer N, float4 element i. `PS bN[i]` and `cbN[i]` name the same slot of constant buffer N. `k`, `B`, `S`, `T`, `L`, `M`, `Q`, `F`, `Cf` follow #1003 G05 and #1061 G05. The document contains facts and formulas only.

## Question and method

The Mudcrab lead reports distance haze on opaque exterior geometry. Static question: which pass writes a fog-blended colour into the colour of opaque pixels, given that the Lighting pixel tail returns `L` at (S,T) = (1,0)? The lead found that near Lighting, terrain LOD and object LOD draw with (S,T) = (1,0), and that the PS tail then returns `L` for LDR input.

Method. The author re-decoded the PS tails of object LOD records `0d000001` and `0f000001`, near terrain `08000001` and `13000001` (techniques 8 and 19), and LOD terrain `09000005` and `12000005` (techniques 9 and 18). The author read the native writers of every constant the tail uses and searched the whole listing for readers of the scene fog property. The author found 93 DXBC records after group 78 of the Lighting package file that earlier runs had not decoded, decoded them, and traced the native pass that feeds the fog ramp records and its place in the main colour stage. The author evaluated the decoded arithmetic in float32 for an LDR example.

## Observations

### G01. The PS tail, re-decoded (all tails identical)

**Verified.** In all checked PS records (object LOD records of group 6, techniques 13 and 15, and the near and LOD terrain records of #979) the target 0 RGB tail is, per channel:

```text
L   = lit diffuse × vertex colour          (before fog)
M   = L + F × (Cf − L)                     (F, Cf = COLOR1.a, COLOR1.rgb from the VS)
Q   = L − k × M
out = min(L, S × Q + B) − T × S × Q
```

- `k` is `PS b0[0].w`. `B` is `PS b0[1].x`. `S` is `PS b12[42].y`. `T` is `PS b12[42].z`.
- Count check: every decoded record holds the `cb12[42].y … cb0[1].x` pair and the `cb12[42].z` operand. The 15 highlight keys of technique 19 and the object records with highlight terms repeat the fog bound as a second stage with `cb0[1].z`, so `cb0[0].w` appears twice in those files. The corrections run decoded 43 group-6 records again: 28 hold `cb0[0].w` once and 15 hold it twice.
- For (S,T) = (1,0): `out = L − max(0, k×M − B)`. For (S,T) = (1,1): `out = min(k×M, B)`. For S = 0: `out = min(L, B)`.
- Objects: `L` has no fog term in front of it. The fog colour and strength enter only through `M`. Nothing before the tail blends fog into `L`.

**Confidence: high.** This agrees with #1003 G05 and #1061 G05. No algebra error found.

### G02. Constant dataflow for the tail and for the VS fog

| Constant | Slot in shaders | Native writer | Value for a stock exterior |
|---|---|---|---|
| `k` | `PS b0[0].w` (all checked tails); VS `b0[2].w` (unused); composite `cb2[1].w` and `cb2[2].w` (G05); grass `cb2[16].w`; effect and sky constants | Fog writer `0x154c010`. It loads the float at `0x20d694c` at `0x154c07b` and stores `(nearRGB, k)` at the PS offset given by PS object byte `+0x53`, and at the VS offset given by byte `+0x5e`. One call site, `0x1548614`. | Image value `0.8333333` (`1/1.2`). Other stores: the `SetFramebufferRange` handler and the temporary `1.0` in `0x116ac80` (#1061 G06). |
| near fog RGB | `PS b0[0].xyz` (unused by these PS), VS `b0[2].xyz` | same writer, from fog property `+0x38/+0x3c/+0x40` | Weather colour, symbolic: `Wnear` (day row at noon, G03). |
| far fog RGB | VS `b0[3].xyz` | same writer, from `+0x44/+0x48/+0x4c` | `Wfar`. |
| fog scalars | VS `b0[1] = (near×r, r, power, max)`, `r = 1/(far−near)` | same writer, from `+0x50`, `+0x54`, `+0x84`, `+0x88`. Both distances zero gives `(5000000, 0.1, 1, 0)` (`0x1b44ea0`). | Weather scalars, symbolic: `near_f`, `far_f`, `p`, `m` (G03). |
| `B` | `PS b0[1].x` | `0x1548633–0x154863b`. It reads cache `0x343640c`. The cache is filled from setting `fLightingOutputColourClampPostLit:General` by `0x1547454–0x154745c` and by handler `0x106da0`. | Compiled default 1.0. |
| `PS b0[1].y`, `.z`, `.w` | not read by the single-stage tails. `.z` is the second bound of the two-stage records (G01) | `0x1548640–0x1548656` (`0x3436410` PostEnv, `0x3436414` PostSpec, zero). A second small writer is `0x154c1d0`. | 1.0, 1.0, 0. |
| `1/fGamma` | `PS b12[42].x` | frame writer `0x100ae80` (`0x100b317–0x100b31f`) | 1.0 at default `fGamma`. Not read by these tails. |
| `S` | `PS b12[42].y` | `0x100b327–0x100b334`: 0 if flag mask `0x2`, else 1.0 | **1.0** in the ordinary exterior colour pass (#1061 G01–G03). |
| `T` | `PS b12[42].z` | `0x100b33c–0x100b349`: 1.0 if flag mask `0x4`, else 0 | **0** in the first stage. **1** only for group 7 and the sorted list draws of the second stage (#1061 G03). |
| lane W | `PS b12[42].w` | `0x100b351–0x100b358`: 1.0 if flag byte sign bit | not read by these tails |

**Verified** (this run): the writer at `0x154c010` and its stores, the clamp upload at `0x1548626–0x1548656`, the three setting-copy sites and the four `b12[42]` lane stores. Image values `k = 0.8333333`, `B = PostEnv = PostSpec = 1.0`, `fGamma = 1.0` were read from the image. The PS constant offsets: the shipped headers of `0d000001`, `0f000001`, `08000001`, `09000005`, `12000005` and `13000001` hold dword offsets 0 and 4 in the bytes that map to object `+0x53` and `+0x54`. This agrees with the shader reading `b0[0].w` (dword 3) and `b0[1].x` (dword 4). The header-to-object-offset mapping is **inferred**.
**Taken from earlier findings, not re-read now:** the flag words (`0x41/0x51`, `0x40/0x41`, `F|4`) and the stage order inside the first and second stage (#1061 G01–G03), and the weather producers (#812 G01–G03).
**Confidence: high** for the slots and the writers. **Medium** for runtime values, which are unverified.

### G03. Fog inputs at noon, symbolic

**Verified for the reader side, taken from #812 G01–G03 for the producer side.** For a stock exterior at noon the climate day weight is 1 (between the end of sunrise and the start of sunset). The scene fog property then holds the day values of the current weather, blended with the previous weather by the transition weight `q`. Near fog RGB is the day colour of `NAM0` row 1. Far fog RGB is row 12. The scalars are the day near, far, power and max of the weather `FNAM` block. This finding does not repeat plugin values. Symbolic names: `Wnear` and `Wfar` (RGB in 0..1), `near_f`, `far_f`, `p`, `m`.
Derived ramps (same for the VS and the composite): `s = saturate(dist × r − near_f × r)`, `F = min(s^p, m)`, `Cf = Wnear + F × (Wfar − Wnear)`. Only the distance `dist` differs between the VS and the composite (G05).

**Confidence: high** for the ramp. **Unverified:** runtime weather values.

### G04. Where the fog pass sits in the frame

**Verified.** The main colour stage `0x1539f10` runs this order. Its one direct caller is `0x6576be`.

1. `0x153a02f`: camera set and finish slot, which runs the first stage (accumulator flags `0x41`-class, `(S,T) = (1,0)`). Taken from #1061 G02, plus a re-read of the call and the finish slot.
2. `0x153a0e5`: byte `0x343639c` = 0. `0x153a102`: call of the SAO and fog composite function `0x1541f40`. With `0x343639c` = 0 the function generates the SAO (camera-depth, minify, raw AO and blur effects) and exits through the jump at `0x1542981` before any composite code. The composite code is not reachable in this call.
3. `0x153a19b`: byte `0x343639c` = 1. `0x153a1ca`: call of `0x1541f40` again, with `0x71` and 1 as arguments. With `0x343639c` = 1 the jump at `0x1541fc1` goes to `0x1542986` and the function runs the composite. This is the composite call. There is no condition around it in `0x1539f10` except the code path itself.
4. `0x153a1ef`: the second stage (accumulator flags `0x40`-class, which adds `T=1` for its sorted draws).

So the composite runs once per run of `0x1539f10`, after the first accumulator stage and before the second accumulator stage. The names "opaque" and "blended" for the two stages come from #1061 G01–G03. This run read only the flag bits. Other camera, reflection or menu renders were not examined.

**Verified.** Variant selection in `0x1541f40` (`0x1542c6e`, `0x1542cf3–0x1542d06`, `0x15430de–0x15431f8`):

| `bSAOEnable` (object byte `+0x50`) | fog flag `dl` | effect run | matching shader record (G05) |
|---|---|---|---|
| 1 | 1 | `ISSAOCompositeSAOFog` (object `+0x28`, upload `0x158bd80`) | record 53 |
| 0 | 1 | `ISSAOCompositeFog` (object `+0x20`, upload `0x158bc40`) | record 51 |
| 1 | 0 | `ISSAOCompositeSAO` (object `+0x18`, upload `0x158bb00`) | record 49. No fog. No `k`. |
| 0 | 0 | a generic manager effect, index `0x22` (`0x15431f8–0x1543211`) | not decoded |

`dl` is 1 when the scene has a fog property (`0x14ec040` at `0x1542c66`) and byte `0x343639b` is non-zero. Byte `0x343639b` is a copy of `bSAOApplyFog:Display`, written at `0x1541f0a–0x1541f11`. The console command `ToggleFog` (short `tfog`, help text "Toggles the fog on or off") also flips it. Its handler at `0x37d490` stores the inverse of the byte at `0x37d4b5`. The command table names the handler. So `ToggleFog` switches this composite fog on and off. Byte `+0x50` is a copy of `bSAOEnable:Display` (`0x1541ea3`, `0x1541eea`). Compiled defaults: `bSAOEnable` = 1 and `bSAOApplyFog` = 1 (read from the image). With defaults the pass is `ISSAOCompositeSAOFog`.

**Inferred.** The match of effect object to shader record is by content: the three records differ exactly in the AO texture and the fog math, and the native selection follows the same two flags. The effect-to-record lookup itself was not traced.

**Confidence: high** for the order and the selection. `bSAOEnable` (byte `+0x50`) is read only in the composite branch. The first call does not read it. **Unverified:** the render target binding and the blend state of the composite draw (G08).

### G05. The composite shader arithmetic (records 49, 51, 53)

**Verified.** The three pixel records are at file offsets 67672140 (record 49, 6296 bytes), 67678920 (record 51, 6692 bytes) and 67686096 (record 53, 6952 bytes) of the member `shaders011.fxp`. Each has 80 header bytes before the DXBC. Their constant buffer 2 has 11 float4 entries, which equals the `0xb0` bytes the native upload copies (`0x158bd80` copies `0xb0`). Among the 93 trailing records, the only pixel records that contain both a log and an exp instruction are records 49, 51, 53 and two screen-space reflection records (59, 61). The other trailing records are vertex and compute shaders and further pixel records.

Per channel, record 53 (`ISSAOCompositeSAOFog`):

```text
C   = scene colour texture t0 (RGB). When the SSR flag cb2[10].z is above 0.5 and the
      mask test on t3 passes, C also receives a clamped reflection term
      min(C × cb2[10].y, max(0, ssr.rgb × ssr.a × cb2[10].x)) from t6 before the fog step.
A   = AO factor (t1), d = depth texture t2
d'  = 1.01×d − 0.01
z   = 2×N×F / ((N+F) − (2×d' − 1) × (F−N))            (N = cb2[3].x, F = cb2[3].y)
s   = saturate(z × cb2[0].y − cb2[0].x)
Fc  = min(s^cb2[0].z, cb2[0].w)
Cfc = cb2[1].rgb + Fc × (cb2[2].rgb − cb2[1].rgb)
out = Fc × (Cfc − A×C) + A×C                           (fogged, AO applied first)
out = out × cb2[1].w                                   (k)
rgb = (d < 0.999999) ? out : A×C                       (sky and far-plane pixels skip fog and k)
final = saturate( rgb × (1 − cb2[7].w) + sparkle term )
```

Record 51 (`ISSAOCompositeFog`) is the same without the AO term: `out = k × (C + Fc × (Cfc − C))`. Record 49 (`ISSAOCompositeSAO`) has no fog and no `k`: `final = saturate(A × C + …)`.

**Verified** details:
- `cb2[0] = (near×r, r, power, max)`, `cb2[1] = (nearRGB, k)`, `cb2[2] = (farRGB, k)`, `cb2[3] = (N, F, …)`. Native evidence: the block is built in `0x1541f40` at `0x1542d2e` (`cb2[3]`), `0x154303d` (`cb2[1]`), `0x154306c` (`cb2[2]`) and `0x15430cc` (`cb2[0]`). `N` and `F` are the floats at `+0x160` and `+0x164` of the object that the global `0x33d3d28` points to (`0x154298d`, `0x1542995`). Those offsets hold near and far in the camera frustum layout of #1061 G07. That the object is the same camera is **inferred**. The same fog property getter and the same offsets (`+0x38..+0x4c`, `+0x50`, `+0x54`, `+0x84`, `+0x88`) as the Lighting writer. `k` is the float at `0x20d694c` (`0x1543019`).
- The degenerate case differs from the VS: the composite takes the `(5000000, 0.1, 1, 0)` fallback whenever `far == near` (`0x154308b–0x1543097`). The Lighting writer takes it only when both are zero.
- `cb2[7].w` is byte `bSparklesOnly:Display` (default 0). So `1 − cb2[7].w = 1`.
- The snow and sparkle branch is gated by `cb2[5].w`, a flag byte whose image initial value is 1 (`0x20d6ce8`), and by the snow texture. The branch uses the `bToggleSparkles`, `bEnableImprovedSnow` and `fSparkles*` settings. For pixels with a zero snow mask in `t4` it adds nothing. The producers of `cb2[5].w`, `cb2[10]` and the mask texture were not traced. The snow path was not traced for snow pixels.
- `dp2(N,N ; F,F)` is `2×N×F`. For a standard D3D depth value and the projection described in #1061 G07, `z` equals the view-space depth along the camera axis. Example, `N = 15`, `F = 10240` (compiled defaults): `z / viewDepth` is 0.990 at depth 100, 0.991 at 1000, 0.995 at 5000 and 0.9998 at 10000 (the 1.01/−0.01 remap causes the small deviation). **Inferred** that the texture `t2` holds the raw hardware depth. The binding was not traced.
- The VS distance is `|clip.xyz|` (#1061 G07: `sqrt(x'² + y'² + z'²)` with `z' = F/(F−N) × (z − N)`). So the composite and the vertex distance differ. The composite uses axial depth. Off-axis pixels get a smaller `Fc` than the same point would get from the VS (**inferred**, static).

**Confidence: high** for the formula (read from the records). **Medium** for the depth interpretation. A capture of `t2` and `cb2[3]` would settle it. **Unverified:** SSR flag and mask.

### G06. Numeric evaluation, LDR example

Constants: `k = 0.8333333`, `B = 1.0`, `S = 1`, `T = 0` (first stage). Example values only, not plugin values: `L = 0.4`, `Cf = Cfc = 0.6` (near and far colour equal, all channels), `A = 1`. `F` in the PS and `Fc` in the composite are both set to the stated `F`. The calculation is float32, in the instruction order of the decoded records, without the SSR term. Both runs (author and corrections) gave the same table.

The PS tail is identical for object LOD `0d000001` and technique 19 `13000001` (and for 8, 9, 12, 15). So one column set applies to both.

| F | M | k×M | PS out (S=1, T=0) | PS out (T=1) | composite out, AO = 1 | composite out, AO = 0.8 | composite out, fog only (record 51) |
|---|---|---|---|---|---|---|---|
| 0.0 | 0.40000 | 0.33333 | 0.40000 | 0.33333 | 0.33333 | 0.26667 | 0.33333 |
| 0.5 | 0.50000 | 0.41667 | **0.40000** | 0.41667 | **0.41667** | 0.38333 | 0.41667 |
| 1.0 | 0.60000 | 0.50000 | **0.40000** | 0.50000 | **0.50000** | 0.50000 | 0.50000 |

- The PS alone gives 0.4 for every `F`: no tint. This confirms the lead's reading of the PS.
- After the composite, the opaque pixel gives 0.41667 at `F = 0.5` and 0.5 at `F = 1`. That is `k × (blend toward 0.6)`. It equals what a T=1 draw writes (`min(k×M, B)`). So blended and opaque geometry meet in the same result.
- A sky-class pixel (depth ≥ 0.999999) stays at `A × L` (0.4 at AO = 1) with no `k` scale and no fog.
- Limiter case (S=1, T=0, `F` = 0): `L = 1.0` gives 1.0, `L = 1.2` gives 1.2, `L = 1.5` gives 1.25 (`k×M = 1.25`, `B = 1`, so `1.5 − 0.25`). With `F = 1` and `Cf = 0.6` the `k×M` is 0.5 and `L = 1.5` stays 1.5.
- Brightness note: at `F = 0` the composite scales opaque pixels by `k` (0.4 becomes 0.33333). This matches the `k` pre-scale convention in the HDR finding (Lighting and sky outputs carry `k`).

**Confidence: high** for the arithmetic given the constants. The constants are examples. **Unverified:** runtime `F`, `A`, `Cf`.

### G07. Other readers of the weather fog fields and fog constants

**Verified.** Every direct caller of the scene fog property getter `0x14ec040` (9 sites). One more direct reader, `0x5285f2`, loads the property from the scene array at `0x20d68b0` (`+0x220`) without the getter.

| Site (RVA) | Function (GUESS label) | What it does with the property |
|---|---|---|
| `0x40b97c` | `Atmosphere::Update` (from #812) | Writes the property (producer). |
| `0x154c027` | Lighting fog writer | VS `b0[1..3]` and PS `b0[0]` (G02). |
| `0x1542c66` | SAO and fog composite | `cb2[0..2]` of the composite (G05). This is the fog blend in the colour of opaque pixels. |
| `0x154144f` | function starting at `0x1541210` (called at `0x14f3b54` with a new 0x18-byte object and three effect pointers). Its effect names match the `ISLightingComposite` strings. | Builds `(near×r, r, power, max)` and `(nearRGB, k)` for effects named with `FogParam` and `FogNearColor`. **Unverified** whether this path runs in the ordinary exterior frame. The matching pixel record (the 8-texture record of the trailing block, `ISLightingComposite`) has no fog ramp. It blends the fog texture `t4`: `lerp(colour, fog.rgb, fog.a)` times `k`, only when that texture is nonzero. The `FogParam` vector is not read by it. What writes the fog texture is unverified. |
| `0x154d86c` | `BSWaterShader` virtual slot 4 (RTTI) | Reads near/far RGB and the four scalars. Builds `(near×r, r, …)` and writes near and far RGB. Water has its own fog. |
| `0x15225f1`, `0x15233cb` | `BSGrassShader` virtual slot 2 and a helper | Writes `(nearRGB, k)` into global `0x33d4d50` (grass finding). The checked grass PS record (`2-ps-00`) has no fog math. It multiplies by `k` only. |
| `0x15568e1` | `BSEffectShader` virtual slot 2 | Writes `(nearRGB,k)`, far RGB and the scalars to its constants. |
| `0x1559058` | `BSDistantTreeShader` virtual slot 2 | Reads the property. Details not decoded. |
| `0x5285f2` | function `0x5282a0` | Far RGB multiplied by a three-float tint from `[[0x32303b8]+0x100]+0xcc` and stored with W = 1 in an object vector at `+0x1b8`. Consumer **unverified**. |

**Verified.** Shader group order follows the constructor sequence of the shader objects (BloodSplatter 0, DistantTree 1, Grass 2, Particle 3, Sky 4, Effect 5, Lighting 6, Utility 7, Water 8). The positions are inferred. Grass and Lighting agree with earlier findings. Only groups 5, 6 and 8 have a vertex fog ramp (saturate, log, exp, min). No pixel record outside group 6 has that pattern. The effect pixel tails interpolate the vertex fog as `lerp(colour, fogRGB, fogF)` and write it. The water pixel tails do the same and then multiply by `k` (`PS b0[1].w`). The Lighting tails do not write the interpolated fog colour at (1,0). The group 1 (distant tree) pixel record multiplies albedo by `cb0[0] × v.z + cb0[1]`, a vertex-driven tint that may carry fog. Its constants were not traced.

**Verified.** No decoded fog record reads a height value or a sun direction. The sky shader does not read the property through any site above. Its `k × SkyScale` constants are described in the HDR finding. The tonemap PS (groups 26, 27) has three texture inputs and no depth. The HDR finding found no `k` term there. No fog ramp was found in the pixel records of groups 9 to 78. Groups 70 to 73 (four textures, DOF family) tint toward a constant colour by a blur-amount ramp, not by fog distance. Group 65 is a height-to-normal filter.

**Unverified.** Whether grass draws before or after the composite. The grass PS already multiplies by `k`. If it draws before the composite, `k` would be applied twice. Not traced.

**Confidence: high** for the caller list. **Medium** for the labels. **Low** for items marked unverified.

### G08. Output target and blend state of the main draw

**Verified.** The PS writes target 0 RGB as in G01 and `target 0 alpha = tex alpha × cb2[3].z` (no fog in alpha). Target 1 holds motion vector lanes. Target 2 repeats target 0 or holds a normal pack (`cb2[7].z` selects). So the opaque pass does not carry a fog value to any later pass through the PS outputs.
**Observed. Meaning unverified.** Before the composite, `0x1541f40` stores 0 into six pairs of renderer state words (`0x20cfcbc/cfc`, `cc0/d00`, `cc4/d04`, `cc8/d08`, `ccc/d0c`, `cd0/d10`; `0x1542b18–0x1542c1d`). The Lighting setup writes 3 and 1 into the same words (`0x154852e–0x154858f`). The meaning of these words (blend or write mask) is unverified.
**Observed. Meaning unverified.** The composite call passes `0x71` as its second argument (`0x153a1ba`). The function uses it as an index into the render target table at `0x3331f40` (stride `0x30`, pointer at `+0xa70`) and stores the pointer into render target slot 0 of the renderer state (`0x15429b4–0x15429d9`, store at `0x20cfd40`). The identity of table entry `0x71` is unresolved here.

**Amendment (2026-11-24, UNREVIEWED).** Scope: the paragraph above only. The composite call passes `0x71` as its second argument (`0x153a1ba`). The function uses it as an index into the render target table at `0x3331f40` (stride `0x30`, pointer at `+0xa70`). It stores the pointer into the pixel shader resource array at `0x20cfd40` (code `0x15429b4–0x15429d9`), the first entry, shader slot `t0`. It is not a render target slot. The dirty-bit flush at `0x1010de0` passes `0x20cfd40 + 8 × slot` to the device context virtual at `+0x40` (`PSSetShaderResources`). The output target is set earlier in the same branch by the render-target setter `0x10155b0` (slot 0, target = the third argument 1, mode 3, call at `0x15429af`). Table entry `0x71` is the render target enumerator `kSNOW_SWAP` (113, `CRASHLOGGER_PDB(59818@2026.10.24)`), which the code fills from target 1 before the composite (compute copy `0x1540db0`, or the snow effect `0x1544ab0`). See `findings/live-k-composite-target-retail-facts.md` G03 and G04. The other statements of G08 are not contradicted.
**Unverified.** Whether the composite reads a copy of the scene colour, and its blend state. The decoded record reads the scene colour from `t0` and returns the full result, so a replace write is the consistent reading. This was not traced.

**Confidence: medium.**

### G09. Scope of earlier statements about the Lighting fog (static only)

The arithmetic of the Lighting pixel tail in #812 G04, #979 G02, #1003 G05 and #1061 G05 is correct. Each statement below is correct as scoped to the Lighting draws. Each needs a pointer to the later composite pass. None is an arithmetic error.

1. **#812 G04 and Interpretation** ([exterior-fog-retail-facts.md](exterior-fog-retail-facts.md)). The published text covers the Lighting vertex and pixel records. It says the later frame processing is unverified and that the Lighting path interpolates fog strength and colour "for the pixel calculation". At (S,T) = (1,0) that calculation returns L unless `k × M > B`. It does not write the fogged colour M. **Verified, high.** Scope: Lighting draws. A per-pixel depth fog is applied later by the composite (G04, G05).
2. **#1061 G05, Answer 4b and Interpretation** ([object-lod-frame-flags-retail-facts.md](object-lod-frame-flags-retail-facts.md)). "The fog does not change target 0 there" is correct and is scoped to target 0. It is not the fog of the finished frame. **Verified, high.** The #1003 file ([object-lod-ambient-sun-retail-facts.md](object-lod-ambient-sun-retail-facts.md)) G05 gives the same arithmetic and needs no change.
3. **#979 G02** ([near-t19-order-retail-facts.md](near-t19-order-retail-facts.md)). `D = min(E(L) + PS b0[1].x, L)` is an overflow limiter at (1,0): `D = L` where `k × lerp(L, Cf, F) ≤ PS b0[1].x`. It is not a fog blend there. **Verified, high.**
4. **#1061 G09**: "The `0x20d694c` scalar `k` enters only the PS." Among the Lighting constants this is correct (`VS b0[2].w` is written and not read). Other shader families and the composite read the same scalar (G02, G05). **Verified, medium** because the other readers were listed, not decoded.
5. **#812 G06** says a link from `bSAOApplyFog` to the checked Lighting expressions is unverified. **Verified, high:** there is none. `bSAOApplyFog` gates the composite fog (G04). The console command `ToggleFog` flips the same cached byte.

Per-draw, T=0, S=1: `out_PS = L − max(0, k×M − B)`. Per pixel after the composite with default settings, depth below 0.999999, no snow or sparkle, and the SSR term in `L` when enabled: `out = saturate(k × ((1−Fc) × A × L + Fc × Cfc))`. At depth 0.999999 or above: `out = saturate(A × L)`. T=1 draws: `out_PS = min(k×M, B)`.

**Confidence: high** for 1, 2, 3, 5. **Medium** for 4.

## Interpretation and alternatives

The lead's candidate (b) is right for the decoded families. The fog blend in the colour of opaque pixels is a deferred, depth-based composite. The Lighting PS only carries the fogged value `M` into the limiter, so that `k×M` stays below `B`. This explains why the VS still computes `(Cf, F)` for opaque draws although the PS does not write them.

Alternatives not excluded by static reading:
- `bSAOApplyFog` could be 0 in a user's INI, or `ToggleFog` could be active. Then no composite fog runs (G04 table). Opaque geometry then gets no distance haze from this pass. A runtime or INI check settles it. The five shipped INI templates contain no `bSAOApplyFog` line. Low, Medium, High and Ultra set `bSAOEnable=1`. So the compiled default `bSAOApplyFog` = 1 applies unless a user INI changes it.
- The `ISLightingComposite` family (deferred lighting composite) also reads fog constants. It is not shown to run in this frame (G07).
- The depth texture content (raw depth versus a remapped copy) changes `z` (G05).
- Distant tree, sky and particle shaders could add their own fog. They were not decoded for it (G07).

## Negative results and limitations

- No capture, no live constant read and no visual comparison. All claims are static.
- Not traced: the composite's render target, its blend state, the content of `t2` and `t0` (copy or direct), and whether the SAO call changes any state the composite reads.
- Not traced: grass draw order relative to the composite, and the grass double `k` question (G07).
- Not traced: the loader from effect class to shader record, the producers of the SSR, snow and sparkle parameters, the frame membership of the `ISLightingComposite` pass, and use of the fog property by distant tree, sky and particle shaders.
- Not decoded: the generic effect used when both settings are 0; the `ISLightingComposite` fog-texture writer; the DOF-style depth blend records; the snow and sparkle path for snow pixels; `cb2[4..10]` lanes other than those named.
- The record-to-effect match (G04) is by content. The native lookup was not read.
- Weather values are symbolic. The numeric example uses invented LDR values only.
- Whether `0x1539f10` runs for other cameras, reflection passes or menu renders is not examined.
- The earlier-finding statements in G09 are checked against the published text of #812, #979, #1003 and #1061.

## Independent review

Reviewer: a fresh-context Sonnet 5.5 run (`claude-sonnet-5-5`), separate from the author. Sol was unavailable on usage limits. The reviewer wrote its own results first (re-decoding 43 Lighting PS records, the composite records and the call order), then compared them with the draft. Static only.

Result: **4 confirmed (G01, G02, G03, G06), 4 corrected (G04, G05, G07, G09), 1 unverified (G08), 0 rejected.** This file contains the corrected wording. The Answer table was confirmed with scope corrections.

| Group | Verdict | Main correction |
|---|---|---|
| G01. PS tail | Confirmed | The "30 files once, 30 twice" count did not reproduce (28 and 15 in 43 decoded records). The bullet now says "every decoded record". |
| G02. Constants | Confirmed | Address notation: one convention (RVA) throughout. |
| G03. Weather inputs | Confirmed, reader side only | The producer side is taken from #812 and is labelled so. |
| G04. Frame order and selection | Corrected | The first call is SAO generation only. `ToggleFog` flips the same byte. "Opaque" and "blended" for the stages come from #1061. |
| G05. Composite arithmetic | Corrected | The composite input `L` includes a clamped SSR term. The snow and sparkle path is gated by `cb2[5].w`. |
| G06. Numeric example | Confirmed | None. |
| G07. Other readers | Corrected | Effect and water pixel tails apply the interpolated fog. `ISLightingComposite` blends a fog texture. The distant tree record carries a vertex tint. |
| G08. Target and blend | Unverified | Not contradicted and not traced. Retagged "Observed. Meaning unverified." |
| G09. Earlier statements | Corrected | Replaced. The earlier version quoted text that is not in the published files. The amendments are scope additions, not error corrections. |

After the review, a third run applied the corrections and re-read items in the pinned image and the shader records. All matched: the `ToggleFog` command strings and the handler store; the single direct caller of `0x1539f10`; the byte stores and the two calls of `0x1541f40` and the `0x71` argument; the jump that selects the composite; the fog flag test and the `bSAOEnable` byte read; the cache copy of `bSAOApplyFog` and the image defaults of both settings; the image value of `k` and the single fog writer call; the `far == near` fallback and its constant; the nine getter call sites and the extra direct read; the composite record SSR gate, mask test and clamp; the `cb2[5].w` gate and its image byte; the depth test, the `k` multiply and the `bSparklesOnly` term; the 43-record tail count; the trailing block offset, the 93 signatures and the three record offsets and sizes; and the effect names in the image. A float32 run of the PS tail and the composite for the example (`L` 0.4, fog colour 0.6, `F` 0.5 and 1.0, `k` 0.8333) agreed with the table in G06. The corrections run did not re-read the group order, the effect and water pixel tails, the `ISLightingComposite` record and the distant tree record in G07. Those items rest on the independent review.

Source exposure of the review: pinned native binary and shipped shader bytecode. This is a static review. It is not match evidence for any function, and it does not decide transfer eligibility.

Reviewer and outcome: Reviewed independently by a Sonnet 5.5 run. Outcome: 4 confirmed, 4 corrected, 1 unverified, 0 rejected. Static evidence only. Transfer status: UNREVIEWED.

## Amendment (2026-11-24, UNREVIEWED)

**Scope.** Only the distant-tree statements. The fog-composite arithmetic and the call order are unchanged. The source is [tree-lod-drawing-retail-facts.md](tree-lod-drawing-retail-facts.md), G06, G07 and G09. **Verified, high. Static only.**

- **Answer row 11, last sentence.** "Distant tree, particle, sky and utility shaders were not shown to add or to omit fog." now reads: the decoded distant-tree records (group 1, eight records) apply no fog. Neither the vertex nor the pixel shader reads a fog value. Particle, sky and utility shaders were not shown to add or to omit fog.
- **Answer row 12 (c) and the line "Distant tree, sky and particle shaders could add their own fog…".** Remove "distant tree" from both. The tree records were decoded.
- **G07 prose on group 1.** "a vertex-driven tint that may carry fog. Its constants were not traced." now reads: a per-draw tint, `atlas.rgb × (−dir.z × sun diffuse + ambient)`, from the scene sun light. It is not fog.
- **Row `0x1559058`.** "Reads the property. Details not decoded." now reads: reads the fog property and the scene sun light. It writes three fog vectors that no tree record reads, and the light constants that the pixel shader uses.
- **Not-traced list and the G07 row of the review summary.** "Use of the fog property by distant tree" is removed from the not-traced list. "The distant tree record carries a vertex tint" now reads: the distant tree record carries a per-draw sun tint and no fog.

The original text above stays unchanged. The amendment supersedes it for these statements only.
