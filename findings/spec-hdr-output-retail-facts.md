Transfer status: UNREVIEWED

# Finding: from the lit scene to the displayed byte, the whole frame (SPEC-2)

## Answer

| Question | Answer |
|---|---|
| What does this file give? | One specification for everything between the lit first stage (the output of SPEC-1) and the byte that the swap chain receives. It gives the frame order, the composite interface, the blend modes, the HDR chain, the tonemap and cinematic terms, the image-space selection, the targets, gamma, the other post effects and their gates, the settings and worked examples. **Static only. No game run, no frame capture and no visual claim.** |
| Is it complete? | It is implementable for the ordinary frame, together with SPEC-1. "Whole frame" means the frame order and the HDR and output chain, not the inside of every pass. These internals are not covered: SAO and screen-space reflection (a later specification, "SPEC-5"), water, volumetric lighting, lens flare, depth of field and the other effects of section 8. Section 13 lists what is open. |
| Temporal anti-aliasing | **Out of scope** for an implementer of this specification. This file gives only its interface: the tonemap writes target 41, and the pass is treated as an identity step (section 8.2). |
| What changed against earlier text? | Six corrections, clarifications or resolutions (section 14). The main ones: the depth-of-field and blur slots run **after** the tonemap; temporal anti-aliasing runs after the tonemap by default; volumetric lighting is **on** by default outdoors; water colour passes draw after the composite. |

| Item | Evidence record |
|---|---|
| Status | Mixed. Each claim carries a mark (section 0). Section 15 lists the marks claim by claim. |
| Authors / human operator | Sonnet 5.5 author run, Sonnet 5.5 independent reviewer run, Sonnet 5.5 blind second binary-check run and Sonnet 5.5 finalizer run (all `claude-sonnet-5-5`, each a separate fresh context). A Sol run was not available. Operator: the Skyrim Research project lead. |
| Reviewer and outcome | The reviewer checked 48 load-bearing claims, found 44 confirmed and 4 in need of correction, and judged the draft implementable for the ordinary frame after corrections. The second check confirmed the default HDR chain, the recomputed examples and corrections C1, C2 and C5, and required further corrections. The finalizer applied both sets and re-read the items of section 15.2. **The merged wording of this file had no further independent review.** |
| Date | 2026-11-25 CST. |
| Build | `sse-steam-1-7-104`, retail `1.7.104.0`, Steam build 24914197. Measured SHA-256 of the executable `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f` equals the pin in `builds/target.json`. |
| Shader package | `shadersfx/shaders011.fxp`, SHA-256 `72cfc73eb0938d5949f0b3a8683722a33b671a34b41b750ba138de8d154c5fbc`. Pixel records of groups 26, 27, 29, 30, 31, 32, 34, 36 and 50 and the trailing records 49, 51 and 53 were decoded locally by one or more runs. |
| Shipped INI files | `Skyrim_Default.ini` `61c151bc…`, `Low.ini` `f045a016…`, `Medium.ini` `e5cb56c2…`, `High.ini` `2413dc2f…`, `Ultra.ini` `10dc00f0…`. Other INI files were not used, because they can be player files. |
| Source exposure | Mixed: pinned native binary analysis, shipped shader bytecode decoded locally and offscreen, shipped INI files, published CrashLogger name tables, earlier published findings, the SPEC-1 file, and the matched reconstructions of section 15.3. **No value was read from any game plugin.** No decompiler text and no disassembly appears here. A reader of this file must not claim to be unexposed to the binary analysis. |
| Name provenance | Class, shader, setting, console-command and render-target names are strings of the image, run-time type names of the image, or `CRASHLOGGER_PDB(59818@2026.10.24)`. Names of structure fields taken from community layouts are inferred. Other labels are GUESS. Subrecord names are public format names; their link to an offset follows SPEC-1 and #1059. |
| Intended recipient | The Skyrim Research project, for boundary review under `docs/clean-room.md`. Maintainer transfer decision pending. |

## Question and method

**Question.** What does retail do between the lit first stage and the byte that the swap chain receives?

**Method.** Static analysis only. No game run, no frame capture and no comparator run.

* The runs read the pinned executable of build `sse-steam-1-7-104` and the shipped shader package. They used local reader scripts and local disassembly, and they decoded shader records locally and offscreen. The scripts and raw output are private and stay in `.local/`.
* The runs also used the shipped INI files, the published CrashLogger name tables, earlier published findings, the SPEC-1 file and the matched reconstructions of section 15.3.
* An author run wrote the draft. It carried some claims over from published findings. Section 15 names the runs for each claim.
* An independent reviewer run, with a fresh context, checked claims against the image and the shaders and reproduced the worked examples.
* A blind second binary-check run, with a fresh context, saved its own results before it opened the draft. It recomputed the examples.
* A finalizer run applied both correction sets and re-read the items of section 15.2.
* The amendment at the end of this file states its own evidence.

**Confidence.** The confidence of each claim is its mark. The verification ledger (section 15.1) has 56 rows in this version of the file:

* 45 rows are **V2** (checked twice, by two different runs).
* 8 rows are **V1**: H13, H17, H20, H22, H27, H31, H32 and H46. Row H20 names two runs that checked different parts.
* 3 rows are **I** (inferred): H14, H36 and H54.
* No ledger row is **U**. Section 13 lists the open items.
* All the runs of this specification are `claude-sonnet-5-5`. Agreement between them is not independent proof. The finalizer did not re-read every V2 row that rests on a published finding or on an earlier run. The merged wording had no further independent review.
* Overall confidence: **medium**, as a static reading. The overall level was set on 2026-11-27, when this section was added, from the marks and limits in this file. No new binary read supports this section. Transfer status stays UNREVIEWED.

## 0. How to read this file

| Mark | Meaning |
|---|---|
| **V2** | Verified in the binary or shader bytes by two different runs. Section 15 names them. |
| **V1** | Verified by one run only. |
| **I** | Inferred. A deduction with stated assumptions. |
| **U** | Unverified or open. |

A claim without a mark in a table or formula block takes the mark of its section 15 row. Addresses are RVAs (image base `0x140000000`). `cbN[i]` is pixel constant buffer N, float4 element i. `sat(x)` limits x to [0,1]. `lum(c) = 0.2125 r + 0.7154 g + 0.0721 b`. `k` is the float at `0x20d694c`, image value 0.8333333 (1/1.2); a console command and a menu draw can change it. "mgr" is the image-space manager object (pointer at `0x33d40a0`); "mgr+N" is a byte offset in it. "Target n" is render target index n.

**SPEC-1** is `findings/spec-near-lighting-retail-facts.md` (pull request #1274; it was not on `main` when this file was written). This file takes these inputs from it:

| Input | SPEC-1 place |
|---|---|
| The lit scene: the value `O` that the first stage stored in `kMAIN` (target 1) for each pixel | sections 6, 7 and 9 |
| The fog colours and distances that feed the composite constants | section 8.2 |
| The depth copy and the clear colour | section 8.1 |
| SunlightScale and SkyScale (lighting inputs from the same image-space block) | section 2.4 |

Other published findings used: #1059 `exterior-hdr-path`, #1272 `hdr-frame-leftovers`, #1077 `exterior-haze-trace`, #1121 `live-k-composite-target`, #1052 `compiled-ini-defaults` and #1273 `lighting-features`.

## 1. Pipeline map

Implement in this order. "Default" means compiled setting defaults, an ordinary exterior gameplay frame and no menu.

| # | Stage | Writes | Default | Section | Mark |
|---|---|---|---|---|---|
| 0 | Frame start: image-space block copy, modifiers, normaliser, time step | mgr `+0xc8` block | on | 2 | V2 |
| 1 | Clear to `k × fog far colour`; depth prepass; depth copy; shadow mask; **first stage** (lit opaque, grass, sky except glare, decals) | `kMAIN` (1) | on | SPEC-1 | V2 |
| 2 | SAO generation; optional screen-space reflection and snow terms (inputs of stage 3) | own targets | SAO on, reflection on | 3 | V2 interface; internals U |
| 3 | **SAO and fog composite** | `kMAIN` | on | 3 | V2 |
| 4 | **Post-accumulation draws**: special groups, water (and an optional water resolve), sorted blended draws, sun glare | `kMAIN` (water: target 88 in one case) | on | 4 | calls V2; group contents U |
| 5 | Second accumulator, then first-person view | frame | on | 4 | order V2; content U |
| 6 | Compute SAO pass (only with `bSAO_CS_Enable`); no multiply onto the scene was found in the call chain | SAO target 46 or 47 | **off** | 4, 8 | call V2; target V1; scene use U |
| 7 | Volumetric lighting compute (a per-scene update also runs before the depth prepass) | volume targets | **on** outdoors (not in world spaces with flag `0x40` or `0x20`); off indoors by default | 8 | V2; names I |
| 8 | Lens flare sprites (additive) | target U | on if a flare exists | 8 | V2; target U |
| 9 | Indirect lighting (`bIndEnable`), image-based lens flare, then **additive composite** of lens flare and volumetrics | scene | indirect off; flare and volumetrics on | 8 | V2 |
| 10 | Image-space slots 0 to 2: world map, refraction, FXAA | temporary targets | only when active; FXAA **off** | 8 | V2 |
| 11 | **HDR effect**: downsample, luminance, adapt, bloom, tonemap with cinematic terms and gamma | target 41, or the final output | on | 5, 6 | V2 |
| 12 | Temporal anti-aliasing (interface only; treat as identity) | 42 or the final output | **on** | 8.2 | position V2; internals out of scope |
| 13 | Image-space slots 3 to 7: depth of field, (empty), radial blur, full-screen blur, double vision | LDR targets | only when active | 8 | V2 |
| 14 | Dynamic-resolution upsample | final output | off | 8 | V2 |
| 15 | Interface draw (`k` = 1.0 for its duration) | back buffer | on | 7 | V2 |
| 16 | Present: `R8G8B8A8_UNORM`, no sRGB view | display | — | 7 | V2 |

Call chain: world render `0x1539f10` → composite `0x1541f40` (call at `0x153a1ca`) → post-accumulation passes `0x151f540` (reached through the accumulator finish `0x151ef00`; that dispatch link was read less completely) → second accumulator (`0x153a320`) → first-person view (call at `0x6577d1`) → compute SAO `0x15436b0` (call at `0x6578c9`, conditional) → frame end `0x153ac00` (call at `0x6578d1`). Inside `0x153ac00`, in order: volumetric apply and blur (`0x153df60`, `0x15403f0`), lens flare sprites (`0x152ea20`), pre-effects (`0x14edfd0`), `TESImagespaceManager::PostProcessing` (`0x14edbf0`, input target 1). **V2**. The world render also calls `0x1541f40` earlier (`0x153a102`, while byte `0x343639c` is 0; an ambient-occlusion branch that was not traced), and screen-space reflection work (`0x153a6b0`) runs before the composite (**V1**).

## 2. Image space: the data that drive the output

### 2.1 The block (20 floats, 0x50 bytes)

| Offset | Field | Source | Constructor default |
|---|---|---|---|
| 0x00 | EyeAdaptSpeed | `HNAM` 1 | 3.0 |
| 0x04 | BloomBlurRadius | `HNAM` 2 | 7.0 |
| 0x08 | BloomThreshold | `HNAM` 3 | 0.6 |
| 0x0c | BloomScale | `HNAM` 4 | 0.5 |
| 0x10 | ReceiveBloomThreshold | `HNAM` 5 | 0.15 |
| 0x14 | White | `HNAM` 6 | 0.15 |
| 0x18 | SunlightScale (lighting input, SPEC-1) | `HNAM` 7 | 1.8 |
| 0x1c | SkyScale (sky input, SPEC-1) | `HNAM` 8 | 1.5 |
| 0x20 | EyeAdaptStrength | `HNAM` 9 | 3.5 (3.0 in a new record) |
| 0x24, 0x28, 0x2c | Saturation, Brightness, Contrast | `CNAM` | 0.9, 1.5, 1.1 |
| 0x30 to 0x3c | tint amount, R, G, B | `TNAM` | 0 |
| 0x40 to 0x4c | depth of field: strength, distance, range, mode word (a float) | `DNAM` | 0, 0, 0, 2.0 |

All **V2**.

### 2.2 Which block is the base

| Order | Rule | Mark |
|---|---|---|
| 1 | The frame copy takes the override block (mgr `+0xb0`) if set, else the base block (mgr `+0xa8`). Console image-space commands install an override. | V2 |
| 2 | Exterior cell, world space **without** a lighting template (name of that field **I**): base = the weather block (buffer at `0x31df470`). | V2 |
| 3 | Exterior cell with that field set, or interior cell: base = the cell image space (extra data type `0x56`); without one, the form with id `0x167`. | V2 |
| 4 | Interior cell with cell flag bit 8: base = the weather block. | V2 |
| 5 | Weather block: `Σ wj × block_j` over **all 20 floats**, weights `q·t, q·(1−t)` (current weather) and `(1−q)·t, (1−q)·(1−t)` (previous weather); `q` is the weather transition fraction and `t` the first day-part weight (SPEC-1 section 2.2: `q` is 1 without a previous weather). `block_j` is the weather's `IMSP` entry for that day part. A missing entry, or a missing current weather, gives its weight to form `0x167`. Without a previous weather no previous term is added. Sky mode 0 copies form `0x167`; modes 1 and 2 do no blend. | V2 |
| 6 | Rooms: the sky update sets the base from rooms when the previous or the current room has a room image space (or on a local reset flag). A side without one uses the current cell's block (rows 2 to 4). The result over all 20 floats is `(1 − m) × previous + m × current`, with `m = s²(3 − 2s)`, `s = clamp(elapsed / 3.0, 0, 1)` (float at `0x209e7c8`); `elapsed` grows by the frame-timer value each update. When `m > 0` the blend is written to the weather-block buffer (`0x31df470`) and becomes the base. When `m` is 0 the base is the current side's block. When neither room has an image space and no reset flag is set, this code leaves the base pointer unchanged. A move of the player into a cell also sets the base to the block of the new cell (#1272). | V2 |
| 7 | Underwater block (mgr `+0xb8`): the frame copy does **not** use it. The only readers found are the depth-of-field effect functions (`0x1551270`, `0x15512f0`, `0x1551b90`). | V2 (scoped search) |

### 2.3 Per-frame processing

Order inside the main update: cross-fade clock, clear the modifier accumulators and copy the base, apply the active modifiers, normalise, refill the time step, render. **V2**.

**Copy** (`0x1536f80`): copy the 20 floats; store the tint amount also at block `+0x98`; **multiply the tint RGB by the tint amount**. **V2**.

**Accumulator start values** (**V2**): after the copy, tint `stored` = `amountSum` = the base tint amount, and `rgbSum` = base amount × base RGB. Fade `stored`, `fadeSum`, `fadeRgbSum`, the blur, double-vision, radial and depth-of-field strengths and the value at `+0x94` start at 0.

**Modifier apply** (image-space modifier instances; `0x15370b0`, then `0x1537310`), for each active instance, with weight `w`:

```text
for each of the 12 floats x at offsets 0x00..0x2c (HNAM 9, CNAM 3):
    x = x − w × (x − (x × mult + add))
tint:  stored = max(stored, a);  amountSum += a;  rgbSum += a × rgb
fade:  storedFade = max(storedFade, f);  fadeSum += f;  fadeRgbSum += f × fadeRgb
blur radius, double vision:  keep the maximum
radial blur strength:  keep the maximum, with the radial parameters of that instance
depth-of-field strength:  keep the maximum, with the distance, range and mode of that instance
one further value (struct +0x94, meaning U):  keep the maximum
```

"Maximum" replaces the stored value only when the new one is strictly larger. The tint amount `a` and fade amount `f` of an instance are **not** multiplied by `w`. `a` and `f` are the values the instance delivers; its key curves and strength were not traced. **V2**.

**Normaliser** (`0x1536ff0`): if `amountSum > 0`: tint amount = stored maximum, tint RGB = `rgbSum / amountSum`. The same for the fade. If the final depth-of-field strength is 0, the four depth-of-field floats of the **copied base block** become the working values. **V2**.

Consequence: with no modifier, tint = the record amount and RGB. With modifiers, the base tint takes part in the mean as one contribution. **V2**.

Working values that the output chain reads: mgr `+0xc8..+0xf4` (floats 0x00..0x2c), `+0xf8..+0x104` tint, `+0x118..+0x124` fade amount and RGB, `+0x128` blur radius, `+0x12c` double vision, `+0x130` radial blur, `+0x14c..+0x158` depth of field. **V2**.

## 3. The composite and its interface (stage 3)

This section repeats the SPEC-1 composite. The SAO term `AO` and the screen-space reflection term are inputs; their production is not covered.

| Record (trailing block) | Selected when | Output |
|---|---|---|
| 53 SAO + fog (default) | `bSAOEnable` and fog (fog property present and `bSAOApplyFog`) | formula below |
| 51 fog only | fog, SAO off | the formula with `AO = 1` |
| 49 SAO only | no fog | `sat(AO × C)` — **no `k`** |
| generic copy effect | both off | not decoded (U) |

```text
C    = scene copy (kMAIN before the composite)
C   += refl     only if cb2[10].z > 0.5 and t3.z ≤ 0.00001 and t3.w > 0.00001
                refl = min( C × cb2[10].y , max( t6.rgb × t6.a × cb2[10].x , 0 ) )          (formula V1)
C   += t4.x × t4.y                                snow term, only if cb2[5].w ≠ 0
AO   = t1.x;  if cb2[5].w ≠ 0 and t4.y > 0.00001: AO = min(t1.x + cb2[8].x, 1)
d    = depth copy made after the depth prepass (not the colour-stage depth)
d'   = 1.01 d − 0.01;   z = 2 N F / ((N + F) − (2d' − 1)(F − N))
s    = sat(z × cb2[0].y − cb2[0].x);   Fc = min(s ^ cb2[0].z, cb2[0].w)
Cfc  = cb2[1].rgb + Fc × (cb2[2].rgb − cb2[1].rgb)
rgb  = d < 0.999999 ?  cb2[1].w × (AO×C + Fc × (Cfc − AO×C))  :  AO × C
out  = sat(rgb × (1 − cb2[7].w) + sparkle)        cb2[7].w = 0 normally
```

| Item | Rule | Mark |
|---|---|---|
| Constants | `cb2[0] = (near × r, r, power, max)`, `r = 1/(far − near)`; when `far = near` the writer gives `(5000000, 0.1, 1, 0)`. `cb2[1] = (near colour, k)`, `cb2[2] = (far colour, k)`. `cb2[3].x`, `.y` = camera near `N` and far `F`. Colours and distances: SPEC-1 section 8.2. | V2 |
| `t0` | A copy of the scene colour in target 113 (`kSNOW_SWAP`). Its format is **fixed** `R11G11B10_FLOAT`, also when `kMAIN` is 16-bit float. With the snow effect active, the copy is that effect's output (not decoded). | V2; snow path U |
| `t1`, `t2` | `t1` = AO, `t2` = the depth copy. | V2 |
| Output | `kMAIN`, no depth test and no depth write. A replace write (blending off) is **I**. | V2; replace I |
| Texture coordinates | All composite samples use the scaled and clamped UV of section 9 (dynamic resolution). | V2 |

So a pixel that only stages 1 and 3 wrote is in [0,1] after stage 3. All arithmetic **V2** except where marked.

**Interface to SAO and reflection work:** inputs are `AO` per pixel (its value on sky pixels is U), the reflection input `t6` with mask `t3`, and the snow mask `t4`. The output is the saturated RGB in `kMAIN`.

## 4. Draws after the composite (stages 4 to 9)

### 4.1 Blend modes: the complete table of the engine

The renderer creates one state table at start (`0x102abd0`) and selects an entry per draw (flush near `0x101114c`) with four values: blend **mode** 0 to 6 (`0x20cfca8`), alpha-to-coverage 0 or 1 (`0x20cfcac`), **write mask** 0 to 12 (`0x20cfcb0`) and a multi-target flag (`0x20d01d0`). All blend operations are ADD. These are all the modes the table holds.

| Mode | Colour: source factor, destination factor | Result colour | Alpha: source, destination | Can raise the destination? | Mark |
|---|---|---|---|---|---|
| 0 | blending off | `S` | — | replaces | V2 |
| 1 | SRC_ALPHA, INV_SRC_ALPHA | `S·a + D·(1−a)` | same | toward `S` | V2 |
| 2 | SRC_ALPHA, ONE | `D + S·a` | same | **adds light** | V2 |
| 3 | DEST_COLOR, INV_SRC_ALPHA | `S·D + D·(1−a)` | DEST_ALPHA, INV_SRC_ALPHA | yes, when `S > a` | V2 |
| 4 | DEST_COLOR, ZERO | `S·D` | ONE, ZERO | only when `S > 1` | V2 |
| 5 | ONE, ONE | `D + S` | ONE, ONE | **adds light** | V2 |
| 6 | ONE, INV_SRC_ALPHA | `S + D·(1−a)` | ONE, INV_SRC_ALPHA | adds when `S > D·a` | V2 |

| Write mask | Colour write | Mask | Colour write |
|---|---|---|---|
| 0 | target 0: none | 7 | target 0: B |
| 1 | target 0: RGB | 8 | target 0: A |
| 2 | target 0: RGBA | 9 | target 0: B; target 1: RGB |
| 3 | target 0: RG | 10 | target 1: none |
| 4 | target 0: BA | 11 | only target 0 (all channels) |
| 5 | target 0: R | 12 | only targets 0 and 1 |
| 6 | target 0: G | | |

Here "target 0, 1, 2" are the bound output slots of the draw, not render target indices.

| Rule | Text | Mark |
|---|---|---|
| Multi-target flag 0 | Only target 0 blends. Targets that a mask row does not name keep the all-channel write mask. | V2 |
| Multi-target flag 1, masks 0 to 8 | Targets 1 and 2 take a copy of the **whole** target-0 entry: the blend state **and the write mask**. So mask 1 writes RGB on targets 0, 1 and 2, and mask 0 writes none of them. Targets 3 to 7 keep the all-channel mask and do not blend. | V2 |
| Multi-target flag 1, masks 9 to 12 | The flag changes nothing. | V2 |
| Flag value | The setter `0x1010600` stores the inverse of its argument. The image value of the flag is 0. Section 4.3 row 6 sets it. | V2 |
| Alpha-to-coverage | It becomes 1 only on pass-state paths (`0x155fa30`, `0x155faa1`, `0x155ff40`) that test byte `0x33d3d17`. No direct writer of that byte was found; its image value is 0. | V1 |

### 4.2 Mode for a sorted draw (generic pass-state routine `0x1578ad0`)

The usual call (`0x15622c2`) runs per pass when render flag `0x4` is on, except for pass ids `0x5c000058` to `0x5c00005b` (`0x1521170`). Other call sites exist (`0x1557eb8`, `0x15605bf`, `0x1560cb9`). One run read that `0x15605bf` does not test that flag (it follows a geometry flag test at `0x156058e`); the conditions of the other two were not read.

`a_p` is the shader property alpha. Alpha-property flags: bit 0 blend, bits 1 to 4 source factor, bits 5 to 8 destination factor (NIF enumeration; names **I**).

1. If `a_p < 1` and bit 0 is clear: mode 1.
2. If `a_p ≥ 1` and bit 0 is clear: mode 0.
3. Else by (source, destination): (6,7) → 1; (6,0), (0,0), (6,9) → 2; (4,7) → 3; (1,2), (4,1) → 4. **Any other pair leaves the mode unchanged** (the mode of the previous draw stays).

The mapping and the flag and pass-id test of the usual call are **V2**; the other call sites **V1**. A serialized One/One pair therefore draws as SrcAlpha/One.

The effect shader setup (`0x1558160`) repeats a subset from its own stored factors: (6,7) → 1; (6,0), (6,9) → 2; (4,7) → 3; (1,2) → 4; other pairs unchanged. **V2**.

### 4.3 Order and blend of the draws after the composite

The post-accumulation function is `0x151f540` (rows 1 to 8). The rest of the frame follows.

| # | Draw | Blend mode / write mask | Adds light | Mark |
|---|---|---|---|---|
| 1 | Only when the water state `0x20d69d8` is 2 (fully under water, name I; one run read its writer `0x5299b0` as 0 above, 1 partly, 2 fully under): the sorted list of row 7 runs here instead | per draw | per draw | order V2; state values V1 |
| 2 | Geometry group 10 | mode 0 stored just before | U | order V2; contents U |
| 3 | **Water colour passes** (pass ids `0x5c000071` to `0x5c006071`; the first stage draws other water ids, and #1077 shows that the water shader applies fog itself) | Write mask 1. The water setup stores mode 2 when `((pass id − 0x5c000071) >> 11) & 15` is 1 to 7; else it stores no mode | mode-2 passes add (**I**: extra light passes) | V2 |
| 3a | Water resolve (`0x15466e0`, object mgr `+0x200`, called with target 88), only when byte `0x3436469` is set | not read | U | order V2; content U |
| 4 | Geometry group 11, then group 12 | write mask 0, then mask 1 | group 11 writes no colour | order and masks V2; contents U |
| 5 | Geometry group 7 | mode 1 and mask 11 stored; the per-draw routine can change the mode | per draw | V2; contents U |
| 6 | **No draw.** When byte `+8` of the object at mgr `+0x168` is set and render flag `0x40` is on: target 3 is bound to output slot 2 and target 85 to slot 1, and the multi-target flag is 1 for row 7. After row 7 they are released and the flag returns to 0. Otherwise write mask 11 is stored | — | — | V2 |
| 7 | **Sorted blended list**, in groups by depth (back-to-front direction **I**): Lighting, effect and particle passes | mode 0 stored before the list (`0x151f956`), then section 4.2; effect override; one particle setup path stores mode 2 (its condition U). With row 6 off: mask 11. With row 6 on: no new mask store before the list, so mask 1 from the earlier store applies (and the multi-target rule copies it to slots 1 and 2) | mode 1 blends; modes 2 and 3 add | V2 |
| 8 | **Sun glare** (sky pass id `0x5c006072`) | mode 2, mask 11; the setup also stores depth state 0 (V1) | **adds** | V2 |
| 9 | Second accumulator (`0x153a320`) | U | U | content U |
| 10 | First-person view | U (opaque and blended) | U | content U |
| 11 | Compute SAO pass `0x15436b0` (off by default), before `0x153ac00` | compute only; no blend store | no | order V2 |
| 11a | Volumetric apply and blur (compute; first step inside `0x153ac00`) | volume targets only | no | V2 |
| 12 | Lens flare sprites (`0x152ff50`, from `0x152ea20`) | mode 5, mask 1 | **adds** | mode V2; target U |
| 13 | Lens flare and volumetric composite (`0x1540ae0`) | mode 5 | **adds** | V2 |

When the resolve byte of row 3a is set, the water passes of row 3 draw into target 88 instead of target 1 (**V2**). The byte is computed at `0x151f5dd` to `0x151f641` from fields of the temporal anti-aliasing object, render flags and the water state. An implementation without temporal anti-aliasing that draws water into `kMAIN` follows the byte-clear path (**I**: the retail default value of the byte was not established).

A routine at `0x1543550` stores mode 4 and copies the compute SAO target onto a target, but no call, jump or data reference to it was found (**V2**, scoped search). Do not implement it as a frame step. Whether it can run is **U**.

For reference, in the first stage (before the composite) the sky setup uses mode 2 for stars and for sky object types 0 and 6 (sun disc and moon disc; names **I**), and mode 1 for the other drawn sky parts (**V2**). A full-screen blood effect object uses modes 4 and 5 (`0x152db90`, **V1**); its place in the frame is U.

**What this means for the tonemap input:** pixels written only by the composite are in [0,1]. Rows 3, 7, 8, 12 and 13 add by blend. Other rows after the composite can also write values above 1 by shader output (not traced). The default target format holds values above 1 (`R11G11B10_FLOAT`, no sign, no alpha). That values above 1 occur is **I**.

**The composite does not run again.** A draw after it applies its own fog and `k` in its shader (sorted Lighting: SPEC-1 section 7, `(S,T) = (1,1)`).

## 5. HDR chain (stage 11, `ImageSpaceEffectHDR::Render` `0x153d120`)

`ToggleHDR` (byte `0x20d75e4`, image value 1) selects the HDR effect (slot 30). With 0 the engine draws slot 34, an effect built on the copy shader. The effect input `c` is `kMAIN`, or the output of the last active slot 0 to 2 (all slots 0 to 7 when `usesLDR` is 0, section 8.1). **V2**.

### 5.1 Targets and formats

| Target | Size (render size `W × H`) | Format | Mark |
|---|---|---|---|
| `kMAIN` (1) | W × H | `R11G11B10_FLOAT` (26); `R16G16B16A16_FLOAT` (10) with `bUse64bitsHDRRenderTarget` | V2 |
| Downsample chain: `kHDR_DOWNSAMPLE0` (26) and next indices | level 0 `max(ceil(W/4), 2) × max(ceil(H/4), 2)`; each next level `/4` rounded up, minimum 2; plus an alternate target for the last level | the HDR format of row 1 | V2 |
| `kHDR_BLURSWAP` (22), `kHDR_BLOOM` (24) | `(W>>2) × (H>>2)` | HDR format | V2 |
| Adapted pair (handle at `0x20d7608`; it points to one of the two last-level targets) | 2 × 2; 1 × 1 with `bUseMultipleLuminanceReferences` 0 or byte `0x343635d` nonzero (no store of that byte was found, #1272) | HDR format | V2 |
| Target 41 (temporary tonemap output); target 42 (temporal output) | W × H | `R8G8B8A8_UNORM` (28) | V2 |

### 5.2 Draws

| # | Draw | Reads | Rule | Texture coordinates (section 9) |
|---|---|---|---|---|
| 1 | Downsample | `c`, bilinear | 4 taps at (±1, ±1) source texels, weight 0.25 each, per RGB channel → level 0 | **scaled and clamped** |
| 2a | First luminance step | level 0, bilinear | `Σ 0.25 × lum(tap)` over 4 taps (±1); written to R, G and B | plain |
| 2b | Further steps | previous, point | 16 taps at offsets {−1.5, −0.5, 0.5, 1.5}², weight 1/16 (first channel), until 2×2 (1×1) | plain |
| 3 | Adapt (replaces the last 2b step when a pair exists) | level above, bilinear; previous pair, point | section 5.3 | plain |
| 4 | Bloom, two passes | level 0 | section 5.4 | plain |
| 5 | Tonemap (or fade variant) | `c` point; bloom and pair bilinear | section 6 | scene **scaled and clamped**; bloom and pair plain |

The average is **linear** luminance. There is no logarithm and no minimum or maximum luminance. All **V2**.

### 5.3 Eye adaptation

Per draw, for each texel, with `n` the new 16-tap average and `p = (x, y)` the previous pair:

```text
Spd = fGlobalEyeAdaptSpeedScale (2.0) × EyeAdaptSpeed
Str = fGlobalEyeAdaptStrengthScale (0.4) × EyeAdaptStrength
Ex  = 30 × T
r_y = 1 − max(1 − 0.01 × Spd, 0) ^ Ex                 cb2[2].z
r_x = 1 − max(1 − 0.01 × Spd / Str, 0) ^ Ex           cb2[2].w
for i in (x, y):
    Δ    = n − p_i
    step = sign(Δ × r_i) × min(|Δ|, max(|Δ × r_i|, 1/256))
    p_i' = p_i + step                                 keep p_i when n is NaN
```

- **Step sign:** it comes from `Δ × r_i`. At rate 0 a channel does not move. **V2**.
- `T` = smoothed real frame time in seconds × time multiplier, from the previous frame. With the compiled defaults it is `(S − min(M, 0.05) − m) / 6` over the last 8 frame times (sum `S`, largest `M`, smallest `m`); a measured frame above 1/6 s counts as 1/6 s; `iFPSClamp` 1 to 199 gives a fixed step. While the pause counter is set, `T` = `fConstHDRAdaptTimerForMenu` (0.3). Some secondary render loops store 0. **V2**.
- **First frame or after a clear** (pair id below 0): the adapt draw is skipped and the pair becomes the current final luminance target: `x = y = n`. No smoothing. Triggers: `ClearAdaptedLight`, a render-target rebuild, a sky request flag and some menu render paths. **V2**.
- **Storage precision.** The pair is stored in the HDR format (**V2**). With the default 11-bit R and G channels the value spacing is 1/256 in [0.25, 0.5), 1/128 in [0.5, 1) and 1/64 in [1, 2). So the conversion can lose or enlarge a step of 1/256, and `y/x` need not reach exactly 1. This is format arithmetic (**I**); the hardware rounding and the real effect are **U**. Use the same format. Section 11 does not apply this.
- **Edge values.** With `n` = 0 on a first frame, the tonemap computes `L × 0 / 0`. The native rate code has no guard for `Str` = 0: with `Spd` > 0 and `Ex` > 0 the result is `r_x` = 1; with `Ex` = 0 both rates are 0. **V2** (code reading; no run).

### 5.4 Bloom

```text
kb = clamp(trunc(BloomBlurRadius), 1, 7)
Tb = BloomThreshold + fGlobalBloomThresholdBoost (0.0)      map screen: + fGlobalMapBloomThresholdBoost (0.25) instead
pass 0 (vertical, into kHDR_BLURSWAP):    o0(p) = k × BloomScale × Σ_{u=−kb..kb} w_|u| × max(L0(p + (0,u))/k − Tb, 0)
pass 1 (horizontal, into kHDR_BLOOM):     b(p)  = Σ_{u=−kb..kb} w_|u| × o0(p + (u,0))
```

Per RGB channel. `L0` is level 0; offsets are texels of `kHDR_BLURSWAP`; point filter (**I**). No mip pyramid. **V2**.

| kb | `w0; w1; …` (centre first; each later value applies at ±u) |
|---|---|
| 1 | 0.786985755; 0.10650672 |
| 2 | 0.402619928; 0.244201481; 0.054488569 |
| 3 | 0.270682156; 0.216745213; 0.11128068; 0.036632769 |
| 4 | 0.204163671; 0.180173829; 0.123831593; 0.066282138; 0.027630489 |
| 5 | 0.163967222; 0.151360765; 0.119064637; 0.079811372; 0.045588955; 0.022190502 |
| 6 | 0.137022808; 0.129617959; 0.109719232; 0.083108582; 0.05633172; 0.03416691; 0.018543981 |
| 7 | 0.117695801; 0.112988554; 0.099966809; 0.081512466; 0.061254777; 0.042423215; 0.027077802; 0.015928362 |

The tables are at `0x20d7640 + (kb−1) × 0xf0` (**V2**).

## 6. Tonemap, cinematic terms, fade (groups 26 and 27; constants from `0x153d860`)

Inputs per pixel: `c` scene (point; UV scaled and clamped as in section 9), `b` bloom (bilinear), `A = (x, y)` adapted pair (bilinear at the screen position).

```text
Sat  = Saturation + fGlobalSaturationBoost (0)
Bri  = Brightness + fGlobalBrightnessBoost (0)        map screen: fGlobalMapBrightnessBoost (0.25) instead
Con  = Contrast   + fGlobalContrastBoost (0)          map screen: fGlobalMapContrastBoost (−0.3) instead

1  Lm  = max(lum(c), 0.00001);     Ls = Lm × A.y / A.x
2  Reinhard (bUseFilmicCurve 0, default):
       P  = 1 / (fReinhardWhiteScale (1.1) × White)²
       Lt = Ls × (1 + Ls × P) / (1 + Ls)
   Filmic (bUseFilmicCurve 1):
       H(v) = v(6.2v + 0.5) / (v(6.2v + 1.7) + 0.06)
       P    = H(max(fFilmicWhiteScale (1.4) × White − 0.004, 0)) ^ (−2.2)
       Lt   = H(max(Ls − 0.004, 0)) ^ 2.2 × P
3  col = c × Lt / Lm + b × sat(ReceiveBloomThreshold − Lt)
4  L1  = lum(col);   col = L1 + Sat × (col − L1)
5  col = col + tintAmount × (L1 × tintRGB − col)                  L1 of step 4
6  col = Con × (Bri × col − A.x) + A.x
7  out = sat(col) ^ (1 / fGamma)
8  fade variant only (when fadeAmount > 0):  out = out + fadeAmount × (fadeRGB − out)
```

Constant slots: `cb2[2] = (ReceiveBloomThreshold, P, filmic flag, 0)`; `cb2[3] = (Sat, 0, Con, Bri)`; `cb2[4] = (tint RGB, amount)`; `cb2[5] = (fade RGB, amount)`; `cb12[42].x = 1/fGamma`.

All **V2**. Notes:

- The fade is applied **after** gamma, in display space.
- The contrast pivot is `A.x`, an adapted **scene** luminance, applied to tonemapped colour.
- No `k` appears in the tonemap.
- Neutral Saturation, Brightness and Contrast are 1.
- The shader writes an alpha value from the same arithmetic; it is not gamma-coded. Its consumer is U.

## 7. Output, gamma and the brightness slider

| Item | Rule | Mark |
|---|---|---|
| Tonemap destination | PostProcessing renders HDR into the **final output** only when temporal anti-aliasing is off, no slot 3 to 7 is deferred and no dynamic-resolution upsample is needed. Otherwise it renders into target 41 (`kIMAGESPACE_TEMP_COPY`), and later passes move the image to the final output. With compiled defaults temporal anti-aliasing is on, so the destination is target 41. | V2 |
| Final output id in gameplay | An argument of the frame draw (`0x656e60`). The normal path passes 0, the back buffer (call near `0x656a78`). A path for a menu with a frozen background passes 14, a menu background target (call near `0x656834`), which is then copied to 0. | V1; meaning of the paths I |
| Swap chain | `R8G8B8A8_UNORM` (28), two buffers; the back-buffer view has a null description, so no sRGB write. | V2 |
| Only gamma step found | Tonemap step 7, exponent `1/fGamma`. Compiled `fGamma` 1.0: **the tonemap output is written as it is**. | V2 |
| Brightness slider | The options handler stores `fGamma = fGammaMin + s × (fGammaMax − fGammaMin)` (0.6, 1.4) with slider value `s` (`0x9ab63a` to `0x9ab660`). A higher `fGamma` gives a smaller exponent, so a brighter mid-tone. A reset path stores the midpoint 1.0 (`0x65cc4c` to `0x65cc77`). A console command writes `fGamma` directly (`0x3778a7`). | V2 |
| Slider range of `s` | 0 to 1 | I |
| Byte conversion | `byte = round(255 × value)` | I (UNORM8 rule) |
| Interface | Drawn after the world frame; `k` is set to 1.0 for its duration. | V2 (#1121, SPEC-1) |
| Display gamma ramp, monitor colour management | Not searched. | U |

## 8. Other post effects: order, gates, defaults

### 8.1 `PostProcessing` (`0x14edbf0`)

1. If byte `0x20d6b7c` (image value 1) is set, find the last active slot of 0 to 7.
2. **`usesLDR` (mgr `+0x210`) is 1 by default**: the manager constructor stores it (`0x14ed449`). The one other direct writer found is the console command `TogglePostponeBlurryEffect` (`tpbe`, help text "Toggles postponing blurry effect after TAA", handler `0x380340`), which flips it. While it is 1, slots 3 to 7 are deferred. While it is 0, active slots 3 to 7 render before the HDR effect with slots 0 to 2. Depth-of-field effect code also reads the flag.
3. Render the active, not deferred slots in order, swapping input and temporary target.
4. Render the HDR slot into the final output or target 41 (section 7). **When it writes the final output directly, the routine returns here**: no temporal pass, screenshot copy, deferred slot or upsample runs.
5. Temporal anti-aliasing (object mgr `+0x1f0`, enable byte `+0x18` from `bUseTAA`), when enabled.
6. Screenshot copy when requested (target 75).
7. Render the active deferred slots 3 to 7 in order, alternating targets; the last one writes the final output when no upsample follows.
8. Dynamic-resolution upsample when the render scale is not 1.

All **V2**.

### 8.2 Temporal anti-aliasing: interface only

The internals are **out of scope** for an implementer of this specification. The interface:

| Item | Rule | Mark |
|---|---|---|
| Input | Target 41, the 8-bit tonemap output (after gamma and fade). | V2 |
| Output | The final output; or target 42 when a deferred slot or the upsample follows. | V2 |
| Identity assumption | Treat the pass as `output = input`. Section 11 and section 12 use this assumption. It is **not** a statement about the retail image: the retail pass mixes frames. | assumption |
| Not covered | History, weights, any effect of the temporal object on earlier stages (for example the water resolve byte of section 4.3, or projection changes). | U |

### 8.3 Slots and effects

| Slot / object | Effect | Active when | Default in an ordinary exterior frame | Position |
|---|---|---|---|---|
| 0 | world map | its enable byte (map screen, I) | off (I) | before HDR |
| 1 | refraction | byte `0x3698b31` set at run time (I: refractive geometry) | only with refraction | before HDR |
| 2 | FXAA | `bFXAAEnabled` | **off** (Low preset: on) | before HDR, on the HDR scene |
| 30 | HDR | `ToggleHDR` byte | **on** | — |
| mgr `+0x1f0` | temporal anti-aliasing | `bUseTAA` | **on** (Low preset: off) | after HDR |
| 3 | depth of field | `bDoDepthOfField` **and** (working DOF strength > 0 **or** (water state 1 or 2 and the underwater block exists with DOF strength > 0)) **and** an enable byte (constructor 1; `ToggleDOF` flips it) | **on when the image space `DNAM` strength or a modifier gives strength > 0** | after temporal anti-aliasing |
| 4 | none registered by the manager setup | — | — | — |
| 5 | radial blur | radial strength > 0 and `bDoRadialBlur` | off without a modifier | after depth of field |
| 6 | full-screen blur | blur radius > 0 | off without a modifier | after radial blur |
| 7 | double vision ("get hit") | double-vision value > 0 | off without a modifier | last |
| mgr `+0x170`, `+0x188` | volumetric lighting | section 8.4 | **on outdoors** (Low preset: off) | update before depth; compute and composite before post-processing |
| slot 32 | older volumetric effect object | created only with `bEnableVolumetricLighting` | not created (0) | — |
| mgr `+0x180` | image-based lens flare (shaders `ISIBLensFlares`, composite `ISCompositeLensFlare…`) | `bIBLFEnable` | **on** (Low preset: off) | before the flare and volumetric composite |
| `0x152ea20` | lens flare sprites | `bLensFlare` and a flare object exists | on (Low preset: off) | before the pre-effects |
| mgr `+0x1d8` | indirect lighting | `bIndEnable` | off | before image-based lens flare |
| mgr `+0x1d0` | compute SAO | `bSAO_CS_Enable` | off | before `0x153ac00` |
| composite input | screen-space reflection | `bScreenSpaceReflectionEnabled` | on (Low preset: off) | stages 2 and 3 |
| — | dynamic resolution | `bEnableAutoDynamicResolution` | off | last |

Slot identities and activity rules are **V2** unless a row says otherwise; "off (I)" and "only with refraction" rest on inferred triggers.

**Pre-effects (`0x14edfd0`), V2:** indirect lighting (returns its input when off) → image-based lens flare (builds the flare textures) → composite `0x1540ae0` (mode 5, onto the scene) → copy back to target 1 with slot 34 if the result is another target.

**Composite shader choice at `0x1540ae0`, V2:** volumetric and flare → `ISCompositeLensFlareVolumetricLighting`; volumetric only → `ISCompositeVolumetricLighting`; flare only → `ISCompositeLensFlare`; neither → no draw. "Volumetric" requires byte `0x3435f44` and the enable byte of object mgr `+0x170`. One run read the colour sources as `scene colour × volume.r` for the volumetric shader, `flare.rgb` for the flare shader and their sum for both (**V1**).

The internals of every effect in this section except HDR are open.

### 8.4 Volumetric lighting gate

| Step | Rule | Mark |
|---|---|---|
| Start-up | Byte `0x3435f44` has image value 0. Start-up code writes it from `bVolumetricLightingEnable` (compiled 1) (`0x1531009`, in a function with one direct call at `0x14ea91b`; "start-up" **I**). The same code writes the enable byte of object mgr `+0x170`. | V2 |
| Per scene | `0x15312d0` (call at `0x6571b3`, made only while byte `0x3435f44` is set) writes the enable bytes of both volumetric objects. It writes 0 when the map byte `0x343635e` is set (name I), or when `bVolumetricLightingDisableInterior` (compiled 1) is set and byte `0x3436311` is nonzero. Otherwise it writes 1. | V2 |
| The interior byte | `0x3436311` is field `+0x51` of the global state block at `0x34362c0` (accessor `0x1537410`). `0x657c90` stores it (`0x65803b`): 1 when the pointer at `+0xc0` of the object at `[0x32303b8]` is nonzero (community name: loaded interior cell), or when the current world space flag byte `+0xa0` has bit `0x40` or bit `0x20`; else 0. No other writer was found by direct reference. | V2 writer; names I |
| Console | `ToggleVolumetricLighting` (`tvl`) flips byte `0x3435f44` (`0x37bfac`). A volumetric prototype command (handler piece at `0x37c9ae`) writes 1 for its value 2 and 0 otherwise. | V2 |
| Consequence | With defaults: on outdoors, except in world spaces with flag `0x40` or `0x20`; off indoors. Weather data are also needed (I). | I (from the rows above) |

## 9. Variants of the output chain

| Variant | Selector | Change | Status |
|---|---|---|---|
| Reinhard | `bUseFilmicCurve` 0 | default | specified |
| Filmic | `bUseFilmicCurve` 1 | tonemap step 2 | specified |
| Fade | modifier fade amount > 0 | group 27, tonemap step 8 | specified |
| 64-bit HDR targets | `bUse64bitsHDRRenderTarget` (Ultra preset: 1) | formats of section 5.1; **the composite input copy (target 113) stays 11/10-bit** | specified |
| Single luminance reference | `bUseMultipleLuminanceReferences` 0 | 1×1 pair | specified |
| HDR off | `ToggleHDR` | copy effect, no tonemap, no gamma step (I) | gate specified |
| Deferred slots off | console `tpbe` (`usesLDR` 0) | slots 3 to 7 run before the HDR effect | order only |
| First frame or cleared pair | pair id below 0 | `x = y = n` | specified |
| Menu pause | pause counter | `T` = 0.3 | specified |
| Map screen | byte `0x343635e` (I: map) | bloom threshold, brightness and contrast boosts swap | specified |
| Composite records 51, 49 | section 3 | | specified |
| Interior | cell | image space from the cell; no volumetrics with the default setting; fog from cell data | specified |
| Underwater | water state | depth-of-field source; early sorted draw | partly (water effects U) |
| Temporal anti-aliasing | `bUseTAA` | section 8.2 | interface only |
| FXAA, depth of field, blurs, flares, volumetrics | section 8 | order and gate only | internals open |
| Dynamic resolution | constants `cb12[43]`, `cb12[44]`; shader flags | see below | arithmetic V2; constant values U |

**Dynamic-resolution texture coordinates.** The scaled and clamped form of a UV `(u, v)` is:

```text
u' = min( max(u × cb12[43].x, 0), cb12[44].z )
v' = min( max(v × cb12[43].y, 0), cb12[43].y )
```

| Draw | Which path with the default (dynamic resolution off) | Mark |
|---|---|---|
| Composite records 49, 51, 53 | **Always** the scaled form (no flag) | V2 |
| Tonemap scene sample (`t1` of groups 26 and 27) | **Always** the scaled form | V2 |
| First HDR downsample | The scaled form: the HDR render sets the shader flag `cb2[0].x` = 1 in every frame | V2 |
| Other HDR draws (luminance, adapt, tonemap bloom sample) | Plain UV (`cb2[0].x` = 0) | V2 |
| Bloom passes | Plain UV (these shaders take the scaled form when `cb2[1].x` < 0.5; the HDR render makes it 1) | V2 |

With dynamic resolution off, the scaled form must reduce to the plain UV (**I**; the constant values are open). So an implementation without dynamic resolution can sample with the plain UV.

## 10. Settings

Compiled defaults are values of the pinned image. "—" means that the file has no entry. Read order (#1052): preference settings come from `Skyrim.ini` then `SkyrimPrefs.ini`; others from `Skyrim.ini` then `SkyrimCustom.ini`. `Skyrim_Default.ini` is a first-run copy source for `Skyrim.ini` (#1052), so in a stock install its value is in force for the keys it holds unless a later file sets the key (static reading, no run). The launcher writes preset values into the player's preference file (I). All compiled values, field addresses and file cells are **V2**.

| Setting (section) | Compiled | `Skyrim_Default.ini` | Low | Medium | High | Ultra | Value field RVA |
|---|---|---|---|---|---|---|---|
| `bUse64bitsHDRRenderTarget` (Display) | 0 | — | 0 | 0 | 0 | 1 | `0x20d7380` |
| `bUseFilmicCurve` | 0 | — | — | — | — | — | `0x20d7dc8` |
| `fReinhardWhiteScale` | 1.1 | — | — | — | — | — | `0x20d7de0` |
| `fFilmicWhiteScale` | 1.4 | — | — | — | — | — | `0x20d7df8` |
| `fGlobalSaturationBoost` | 0 | — | — | — | — | — | `0x20d7cf0` |
| `fGlobalBrightnessBoost` / `fGlobalMapBrightnessBoost` | 0 / 0.25 | — | — | — | — | — | `0x20d7630` / `0x20d7d50` |
| `fGlobalContrastBoost` / `fGlobalMapContrastBoost` | 0 / −0.3 | — | — | — | — | — | `0x20d7cd8` / `0x20d7d38` |
| `fGlobalBloomThresholdBoost` / map | 0 / 0.25 | — | — | — | — | — | `0x20d7d08` / `0x20d7d20` |
| `fGlobalEyeAdaptSpeedScale` | 2.0 | — | — | — | — | — | `0x20d7d80` |
| `fGlobalEyeAdaptStrengthScale` | 0.4 | — | — | — | — | — | `0x20d7d98` |
| `fConstHDRAdaptTimerForMenu` | 0.3 | — | — | — | — | — | `0x20d7d68` |
| `bUseMultipleLuminanceReferences` | 1 | — | — | — | — | — | `0x20d7db0` |
| `iFPSClamp` (General) | 0 | — | — | — | — | — | `0x20b5b90` |
| `bCompensateUnstableFrameTime` / `iUnstableFrameTimeHistorySize` | 1 / 8 | — | — | — | — | — | `0x20b5830` / `0x20b5848` |
| `fGamma` / `fGammaMin` / `fGammaMax` (Display) | 1.0 / 0.6 / 1.4 | — | — | — | — | — | `0x20d0348` / `0x20bc7f0` / `0x20bc808` |
| `bSAOEnable` / `bSAOApplyFog` | 1 / 1 | — | 1 / — | 1 / — | 1 / — | 1 / — | `0x20d87a8` / `0x20d8868` |
| `bScreenSpaceReflectionEnabled` | 1 | — | 0 | 1 | 1 | 1 | `0x20d86b0` |
| `bUseTAA` | 1 | — | 0 | 1 | 1 | 1 | `0x20d8c28` |
| `bFXAAEnabled` | 0 | — | 1 | 0 | 0 | 0 | `0x20d6a90` |
| `bDoDepthOfField` (Imagespace) | 1 | — | 1 | 1 | 1 | 1 | `0x20d8ed8` |
| `bDynamicDOF` (Display) | 1 | — | — | — | — | — | `0x20b73c8` |
| `fDynamicDOFFarBlur` | 0.7 | 0.4 | — | — | — | — | `0x20d8f98` |
| `fDDOFFocusCenterweightExt` | 1.6 | 2 | — | — | — | — | `0x20b7410` |
| `fDOFMaxDepthParticipation` | 50000 | 10000 | — | — | — | — | `0x20d8a48` |
| `bDoRadialBlur` (Imagespace) | 1 | — | — | — | — | — | `0x20d9118` |
| `iRadialBlurLevel` (Imagespace) | 0 | 2 | — | — | — | — | `0x20d9130` |
| `bLensFlare` (ImageSpace) | 1 | — | 0 | 1 | 1 | 1 | `0x20d6eb8` |
| `bIBLFEnable` (Display) | 1 | — | 0 | 1 | 1 | 1 | `0x20d7e50` |
| `bVolumetricLightingEnable` | 1 | — | 0 | 1 | 1 | 1 | `0x20d70f8` |
| `iVolumetricLightingQuality` | 1 | — | 0 | 1 | 1 | 2 | `0x20d70c8` |
| `bVolumetricLightingDisableInterior` | 1 | — | — | — | — | — | `0x20d7128` |
| `bEnableVolumetricLighting` | 0 | — | — | — | — | — | `0x20d8ec0` |
| `bIndEnable` / `bSAO_CS_Enable` | 0 / 0 | — | — | — | — | — | `0x20d8ad8` / `0x20d8a60` |
| `bEnableAutoDynamicResolution` | 0 | — | — | — | — | — | `0x20b5878` |

The image has no `bDoHighDynamicRange` and no `fHDR…` setting. Other tuning settings for image-based lens flare, SAO, temporal anti-aliasing, volumetrics and depth of field exist; they belong to the internals.

## 11. Worked examples

**Every record value, pixel and draw below is invented (example only).** Constants are compiled defaults. Arithmetic is double precision with `k` as float32. Render-target storage rounding is not applied. Bytes use `round(255 × v)` (I). Temporal anti-aliasing is the identity step of section 8.2 and slots 0 to 7 are inactive. The finalizer recomputed every number from the formulas of this file with a new script.

### E0. Image-space block selection (example only)

`q` = 0.75, `t` = 0.8 → weights (current day, current sunset, previous day, previous sunset) = (0.60, 0.15, 0.20, 0.05). Invented blocks, in the order speed, radius, Tb, scale, receive, White, sun, sky, strength, saturation, brightness, contrast, tint amount, R, G, B:

| Block | Values |
|---|---|
| current day | 3, 5, 0.80, 0.90, 0.80, 1.00, 1.6, 1, 3.5, 1.10, 1.05, 1.10, 0.10, 1.0, 0.9, 0.8 |
| current sunset | 3, 5, 0.70, 1.10, 0.80, 1.20, 1.9, 1, 3.5, 1.20, 1.00, 1.15, 0.20, 1.0, 0.8, 0.6 |
| previous day | 2, 3, 0.90, 0.60, 0.70, 1.00, 1.4, 1, 3.0, 0.90, 1.10, 1.00, 0, 0, 0, 0 |
| previous sunset | 2, 3, 0.90, 0.60, 0.70, 1.10, 1.5, 1, 3.0, 0.90, 1.05, 1.00, 0, 0, 0, 0 |
| blend | 2.75, 4.5 (kb 4), 0.81, 0.855, 0.775, 1.035, 1.6, 1, 3.375, 1.065, 1.0525, 1.0825, 0.09, 0.75, 0.66, 0.57 |

Frame copy: tint amount 0.09, premultiplied RGB (0.0675, 0.0594, 0.0513). One modifier with weight 0.5: saturation `mult` 0.5 and `add` 0, every other `mult` 1 and `add` 0, tint amount 0.4 and colour (0.2, 0.4, 1.0). Result: saturation = 0.79875; amount sum 0.49; final tint amount **0.4**; final tint RGB = (0.301020, 0.447755, 0.921020).

### E1. Exterior noon, from an HDR pixel to bytes (example only)

Image space: EyeAdaptSpeed 3.0, EyeAdaptStrength 3.5, White 1.0, receive 1.2, Tb 0.8, BloomScale 0.8, radius 4.5 (kb 4), saturation 1.1, brightness 1.0, contrast 1.05, tint 0.1 × (1.0, 0.9, 0.8).

| Step | Value |
|---|---|
| first-stage pixel `O`; AO; `Fc`; `Cfc` | (0.966026, 0.680193, 0.437308); 0.9; 0.225018; (0.570587, 0.657842, 0.753922) |
| composite `sat(k × ((1−Fc)·AO·O + Fc·Cfc))` | (0.668483, 0.518708, 0.395551) |
| one additive draw, mode 2, source (0.4, 0.35, 0.25), alpha 0.5: scene `c` | (0.868483, 0.693708, 0.520551) |
| bloom, if the whole blur neighbourhood of level 0 has the value `c` | (0.161453, 0.021633, 0) |
| bloom, if only that one level-0 texel is bright (others below threshold): `k·Sb·w0²·max(c/k − Tb, 0)` | (0.006730, 0.000902, 0) |

The rows below use the flat-neighbourhood bloom. Adapted pair: previous (0.40, 0.40), current average `n` = 0.55, `T` = 1/60. Then `Spd` = 6, `Str` = 1.4, `r_x` = 0.021663, `r_y` = 0.030464 → pair (0.403906, 0.404570). The x step takes the 1/256 floor. Ratio `y/x` after frames 1, 10, 30, 60: 1.001642, 1.004498, 1.003819, 1.000000 (both reached 0.55; this ignores storage rounding).

| Step | Frame 1, Reinhard | Converged, Reinhard | Converged, filmic |
|---|---|---|---|
| `Lm`; `Ls` | 0.718363; 0.719543 | 0.718363; 0.718363 | same |
| `P`; `Lt`; `Lt/Lm` | 0.826446; 0.667287; 0.928899 | 0.826446; 0.666243; 0.927446 | 1.323235; 0.795146; 1.106885 |
| bloom weight | 0.532713 | 0.533757 | 0.404854 |
| after bloom | (0.892742, 0.655910, 0.483540) | (0.891648, 0.654924, 0.482783) | (1.026676, 0.776614, 0.576190) |
| after saturation | (0.912635, 0.652120, 0.462513) | (0.911531, 0.651134, 0.461780) | (1.047814, 0.772745, 0.552279) |
| after tint | (0.890752, 0.649350, 0.471766) | (0.889659, 0.648374, 0.471027) | (1.024563, 0.768848, 0.562275) |
| after brightness and contrast | (0.915095, 0.661623, 0.475159) | (0.906642, 0.653293, 0.467078) | (1.048291, 0.779790, 0.562889) |
| saturate, `fGamma` 1 | same | same | (1, 0.779790, 0.562889) |
| **bytes** | **(233, 169, 121)** | **(231, 167, 119)** | **(255, 199, 144)** |

| Variation of the converged Reinhard result | Output | Bytes |
|---|---|---|
| slider `s` = 0.75 → `fGamma` 1.2 | (0.921574, 0.701332, 0.530263) | (235, 179, 135) |
| fade 0.25 toward black | (0.679982, 0.489970, 0.350309) | (173, 125, 89) |
| no additive draw, no bloom | (0.630356, 0.478818, 0.353262) | (161, 122, 90) |
| sky pixel (depth ≥ 0.999999, sky value (0.526144, 0.640523, 0.828431), AO 1), no bloom | (0.488917, 0.593671, 0.769733) | (125, 151, 196) |

### E2. Interior (example only)

Image space: EyeAdaptSpeed 3.0, EyeAdaptStrength 3.5, White 0.8, receive 0.6, Tb 0.6, BloomScale 0.5, radius 4, saturation 1, brightness 1, contrast 1.2, no tint.

| Step | Value |
|---|---|
| `O`; AO; `Fc`; `Cfc` | (0.961737, 0.589320, 0.368039); 0.9; 0.142857; (0.168067, 0.207283, 0.246499) |
| composite `c` | (0.638268, 0.403525, 0.265942) |
| single-texel bloom | (0.002882, 0, 0) |
| pair: previous (0.2, 0.2), `n` 0.3, `T` 1/60 (both channels take the 1/256 floor) | (0.203906, 0.203906) |
| `Lm`; `P`; `Lt`; weight | 0.443488; 1.291322; 0.483182; 0.116818 |
| after bloom (= after saturation and tint) | (0.695732, 0.439642, 0.289744) |
| after contrast; **bytes** | (0.794097, 0.486789, 0.306912); **(202, 124, 78)** |
| first frame, `x = y = n` = 0.3: after contrast; bytes | (0.774878, 0.467571, 0.287693); (198, 119, 73) |

### E3. Menu pause (example only)

`T` = 0.3, EyeAdaptSpeed 3, EyeAdaptStrength 3.5: `r_x` 0.325797, `r_y` 0.427005; pair (0.40, 0.40) toward 0.55 → (0.448870, 0.464051).

### E4. Blend modes (example only)

Destination (0.5, 0.4, 0.3), source (0.8, 0.6, 0.2), alpha 0.25: mode 0 (0.8, 0.6, 0.2); 1 (0.575, 0.45, 0.275); 2 (0.70, 0.55, 0.35); 3 (0.775, 0.54, 0.285); 4 (0.40, 0.24, 0.06); 5 (1.3, 1.0, 0.5); 6 (1.175, 0.90, 0.425). The values are before storage in a target.

## 12. End-to-end formula

One pixel, default frame, temporal anti-aliasing as the identity step and slots 0 to 7 inactive:

```text
c0   = sat( d < 0.999999 ? k·[(1−Fc)·AO·(O+g) + Fc·Cfc] : AO·(O+g) )          stage 3
c    = blend_n(… blend_1(c0, draw_1) …, draw_n), then + lens-flare and volumetric additions      stages 4 to 9
L0   = down4(c);   n = avg16…(avg4(lum(L0)))
(x,y)= adapt((x,y)_prev, n, T)
b    = blurH( k·Sb·blurV( max(L0/k − Tb, 0) ) )
Lm   = max(lum(c), 1e−5);   Lt = curve(Lm·y/x, White)
q    = c·Lt/Lm + b·sat(R − Lt);   L1 = lum(q)
q    = L1 + Sat·(q − L1);   q = q + tA·(L1·tRGB − q);   q = Con·(Bri·q − x) + x
o    = sat(q)^(1/fGamma);   if fA > 0: o = o + fA·(fRGB − o)
byte = round(255·o)
```

`O` is the value that the first stage of SPEC-1 stored in `kMAIN` (with the unsigned default format a negative value stores as 0, **I**). `g` is the sum of the reflection and snow terms of section 3; the composite sparkle term and `cb2[7].w` are taken as 0. `R` is ReceiveBloomThreshold, `Sb` BloomScale. `Tb`, `Sat`, `Bri` and `Con` include the global boosts of sections 5.4 and 6. `tA`, `tRGB` are the working tint amount and RGB; `fA`, `fRGB` the working fade amount and RGB. In `Lm` and the later lines, `(x, y)` is the bilinear sample of the adapted pair at the screen position of the pixel, not one global value. Each intermediate target also rounds the value to its format; this formula does not.

## 13. Open items

| # | Open item |
|---|---|
| P1 | SAO generation, its value on sky pixels, screen-space reflection and sparkle terms, snow subsurface pass. |
| P2 | Contents of geometry groups 7, 10, 11 and 12. One run traced their sources with low confidence (**V1**): group 10 from water-property passes when water flag bit 0 (property `+0x88`) is set (`0x152ca62`); group 11 from utility-shader passes (`0x151afa7`, `0x151b14c`); group 12 from lighting passes moved when the property has an effect-shader data block with a texture (`0x151b0f0`); group 7 from lighting passes (`0x151aca4`) and effect-property pass copies (`0x1529fef`). Their gameplay meaning is unverified. |
| P3 | The second accumulator; the first-person draw state; whether first-person pixels get any fog or SAO. |
| P4 | Water pass internals and which water passes add light; inputs and outputs of the water resolve; the retail value of byte `0x3436469`; the condition of the particle mode-2 store; the sort key of the sorted list. |
| P5 | Render target of the lens flare sprites; place of the blood effect draw; indirect lighting pass state; whether the mode-4 compute SAO copy (`0x1543550`) can run. |
| P6 | Internals of volumetric lighting, image-based lens flare, depth of field (including dynamic focus and the mode word), radial blur, full-screen blur, double vision, refraction, FXAA and dynamic-resolution upsample. (Temporal anti-aliasing internals are out of scope.) |
| P7 | Who sets the world-map and refraction activity bytes; which weather data gate volumetrics; community names behind the interior byte rule. |
| P8 | Modifier instance curves and weights; the meaning of the modifier value at struct `+0x94`. |
| P9 | Order of the sky update against the frame-start copy (the weather block can be one frame old). |
| P10 | Sampler states at draw time; address mode of the adapted pair; the effect of render-target storage rounding, including the adapted pair (section 5.3) and target 41. |
| P11 | Meaning of the menu output path; alpha channel consumers; display gamma ramp; HDR-off output encoding. |
| P12 | Run-time values: player INI files, console changes, mods; plugin data (image spaces, modifiers, weathers) — not read. |
| P13 | Values of the dynamic-resolution constants `cb12[43]`, `cb12[44]`. |

## 14. Correction to earlier finding

Each row quotes the earlier text and gives the replacement. The earlier files stay in force for everything else.

| # | Earlier text | Found now | Kind and mark |
|---|---|---|---|
| C1 | #1059 G01: "**Unverified.** The identity of slots 0 to 7, the default state of `usesLDR`, and whether a stock exterior frame uses the deferred branch." and "**Inferred.** Slot 34 is the non-HDR alternative. Its class was not resolved here." The same items are listed as open in the #1059 amendment of 2026-11-25 and in its "Negative results and limitations". #1272 L08 leaves the identity of the earlier slots unresolved. | `usesLDR` is 1 from the manager constructor (the console command `tpbe` can flip it). So with defaults slots 3 to 7 (depth of field, empty, radial blur, full-screen blur, double vision) are deferred past the HDR effect; they do work only when active. Slots 0 to 2 are world map, refraction and FXAA. Slot 34 is an effect built on the copy shader (`ISCopy`). | Resolution of open items. V2 |
| C2 | #1272 L07: "it runs the volumetric-lighting effects (`0x153df60` and `0x15403f0`) only if byte `0x3435f44` and a manager object field are set (the image value of the byte is 0)." | The image value is 0, but start-up code writes the byte from `bVolumetricLightingEnable` (compiled 1). In an ordinary exterior frame with defaults the steps **run**. A per-scene disable exists; interiors take it by default (section 8.4). Console commands can change the byte. | Completion that changes the reading. V2 |
| C3 | #1272 L07: "It also calls `0x14edfd0` (not traced) and `NiCamera::UpdateLensFlareEffect` (`0x152ea20`)." | It runs indirect lighting, image-based lens flare and the additive lens-flare and volumetric composite into the scene, before PostProcessing. These add light to the HDR input. | Resolution of an open item. V2 |
| C4 | SPEC-1 section 1 row 15: "Second stage \| sorted blended draws, glare, second accumulator, first person". SPEC-1 section 8.1: "composite → second stage (sorted blended, sun glare) → second accumulator → first-person view → (volumetrics if enabled) → post-processing". | **Addition, not a wrong statement.** Water colour passes (with an optional resolve) and geometry groups 10, 11, 12 and 7 also draw after the composite, before the sorted list. After the first-person view come the optional compute SAO pass, the volumetric compute, the lens flare sprites, the pre-effects with the additive flare and volumetric composite, and then post-processing (section 4.3). | Incomplete list. V2 |
| C5 | SPEC-1 section 5: "The tonemap writes the back buffer when no later effect runs, else an 8-bit temporary copy (target 41)". | **Clarification, not a correction.** With compiled `bUseTAA` 1 a later pass **does** run in the default frame, so the default tonemap target is 41. | Clarification. V2 |
| C6 | SPEC-1 section 10: "The scene input is `kMAIN` when no earlier image-space slot is active (earlier slots are not covered)." SPEC-1 open item O15: "Image-space slots before HDR and any temporal filter; HDR input when they are active." | The earlier slots are 0 to 2: world map, refraction, FXAA. With defaults only refraction can be active in ordinary play, so the input is normally `kMAIN`; with the Low preset it is the FXAA output. Temporal anti-aliasing runs **after** the tonemap. | Resolution of an open item. V2 |

Dated amendments carry C1 to C3 into the #1059 and #1272 files. A dated amendment in pull request #1274 carries C4 to C6 and the narrowed items O4 and O16 into SPEC-1.

SPEC-1 items that this file narrows without a correction: section 8.4 ("That they add light to `kMAIN` is **I**") and O4 — the sorted list, sun glare, lens flare sprites and the flare and volumetric composite have additive blend stores (section 4.3); the final value is still shader-dependent. O12 — the dynamic-resolution coordinate arithmetic (section 9). O16 — the writer of byte `0x3436311` (section 8.4). The earlier correction of the eye-adaptation step sign (SPEC-1 C1) is carried in section 5.3.

## 15. Verification ledger

Runs: **A** author, **R** reviewer, **S** blind second check, **Z** finalizer. A published finding number stands for that finding's own author and reviewer. **P1** stands for the SPEC-1 runs.

### 15.1 Claims

| ID | Claim | Mark | Runs |
|---|---|---|---|
| H01 | Target formats of `kMAIN`, bloom and chain targets; swap chain | V2 | #1059, #1272, P1, Z |
| H02 | Image-space block layout and defaults | V2 | #1059, P1 |
| H03 | Base block selection and weather blend | V2 | #1059, #1272 |
| H04 | Missing weather fallback in the blend | V2 | R, Z |
| H05 | Room cross-fade: smoothstep, sides, fallbacks | V2 | #1272, R, Z |
| H06 | Underwater block read only by depth of field (scoped) | V2 | A, R, S |
| H07 | Frame order of copy, modifiers, normaliser | V2 | #1272 |
| H08 | Copy premultiply; 12-float rule; tint and fade accumulate and normalise | V2 | #1059, A, R, S, Z |
| H09 | Accumulator start values | V2 | R, Z |
| H10 | Maximum rules and depth-of-field base fallback; working offsets | V2 | A, R, S, Z |
| H11 | Composite arithmetic and depth source | V2 | #1077, #1121, P1, R, S, Z |
| H12 | Composite constants, bindings, target 113 format, no depth test or write | V2 | #1121, R, Z |
| H13 | Composite reflection term formula and mask | V1 | Z |
| H14 | Composite replace write | I | #1121 |
| H15 | Blend modes 0 to 6 and write masks | V2 | #1273 (0 to 4), A, R, S, Z |
| H16 | Multi-target copy of blend and write mask; flag setter | V2 | R, S, Z |
| H17 | Alpha-to-coverage condition | V1 | S |
| H18 | Sorted-draw mapping | V2 | #1273, A, R, S |
| H19 | Flag and pass-id test of the usual call | V2 | S, Z |
| H20 | Other call sites of the pass-state routine | V1 | S, Z (different parts) |
| H21 | Effect shader mapping; water mode 2; particle mode-2 store; sky modes; sun glare mode and mask | V2 | A, R, S |
| H22 | Sun glare depth state | V1 | S |
| H23 | Call order composite → post-accumulation → second accumulator → first person → frame end | V2 | #1272, P1, A, S, Z |
| H24 | Post-accumulation order, groups, masks, water ids, stores before the sorted list | V2 | #1272, A, R, S, Z |
| H25 | Water resolve position, byte and target 88 | V2 | S, Z |
| H26 | Water-blend step binds targets and the flag only | V2 | S, Z |
| H27 | Geometry group sources | V1 | S |
| H28 | Compute SAO called before the frame end | V2 | R, S, Z |
| H29 | Mode-4 routine has no found reference | V2 | S, Z |
| H30 | Lens sprite mode and mask; pre-effects chain; composite mode and shader choice | V2 | A, R, S, Z |
| H31 | Flare and volumetric shader colour sources | V1 | S |
| H32 | Blood effect modes | V1 | A |
| H33 | HDR effect draws, sizes, filters | V2 | #1059, #1272 |
| H34 | Targets 41 and 42 format | V2 | P1, R, S, Z |
| H35 | Adapted pair storage format | V2 | #1272, R, Z |
| H36 | Effect of storage precision on adaptation | I | R |
| H37 | Luminance weights and linear average | V2 | #1059, A, R |
| H38 | Adapt rates and `T` | V2 | #1059, #1272, P1 |
| H39 | Step sign from `Δ × r` | V2 | P1, A, R |
| H40 | Edge values of the rate code | V2 | R, Z |
| H41 | First frame | V2 | #1272, R |
| H42 | Bloom formulas | V2 | #1059, #1272, A, R |
| H43 | Bloom weight tables | V2 | #1272, R |
| H44 | Tonemap, cinematic, fade, constants | V2 | #1059, P1, A, R, Z |
| H45 | Tonemap destination branch and early return | V2 | A, R, S, Z |
| H46 | Final output id 0 or 14 | V1 | S |
| H47 | Gamma exponent and slider | V2 | P1, A, R |
| H48 | Slots 0 to 7 loop, deferral and global gate | V2 | #1059, A, R, S, Z |
| H49 | Slot identities, activity rules, temporal anti-aliasing position and targets | V2 | A, R, S, Z |
| H50 | `usesLDR` default and console writer | V2 | A, R, S, Z |
| H51 | Legacy volumetric effect gate (slot 32) | V2 | A, S |
| H52 | Volumetric start-up write, per-scene disable and interior byte writer | V2 | A, R, S, Z |
| H53 | Console writers of the volumetric byte | V2 | R, Z |
| H54 | Meaning of the interior byte inputs (field names) | I | S |
| H55 | Dynamic-resolution coordinate paths | V2 | R, Z |
| H56 | Compiled setting defaults and preset values of section 10 | V2 | #1052, A, R, S |

### 15.2 Second checks by the finalizer

The finalizer wrote its own reader script on a copy of the SPEC-1 finalizer reader, which asserts both hashes.

| Item | What was re-read | Result |
|---|---|---|
| Multi-target blend copy | state table creator `0x102abd0` with both jump tables; flush near `0x101114c`; setter `0x1010600` | Confirmed: blend and write mask are copied to slots 1 and 2 for masks 0 to 8 |
| Dynamic-resolution paths | pixel records of groups 26, 27, 29, 31, 34, 36, 50 and trailing records 49, 51, 53; flag stores in `0x153d120` and `0x15836d0` | Confirmed |
| Room cross-fade side | `0x411ff0` to `0x4121d2`, blend `0x1536c70` | Confirmed: `(1 − m) × previous + m × current` |
| Adapted pair precision | chain target creation `0x153c1b9` to `0x153c25b`; adapted handle assignment in `0x153d120` | Storage format confirmed. The precision effect stays inferred |
| Lens flare and volumetric chain | `0x153ac00`, `0x14edfd0`, `0x1540ae0`, `0x152ea20`, `0x6578c9`, `0x1543550` | Confirmed; sprite target stays open |
| Also re-read | `0x151f540`, water target choice `0x154d4e4`; `0x15312d0`, `0x65803b`, console writes; `0x380340`, `0x14ed449`; `0x14eec10`, `0x1536f50`, `0x1536ff0`, `0x15370b0`; `0x4158d0`; `0x14edbf0`; rate code `0x153daeb`; target creation for 41, 42, 113; `0x1521170`, `0x15622c3` | Agree with the text above |

Points where the reviewer and the second check differed, and the result:

| Point | Result |
|---|---|
| Row 6 and the water resolve of section 4.3 (the reviewer accepted the draft rows; the second check moved the resolve) | The second check is right. |
| Pass-state routine: "one other call" without the flag test | The named call `0x15605bf` exists; two further call sites exist, so the text lists three. |
| Accumulators "zeroed" against "tint starts at the base values" | Both are right: the tint accumulators are the copied base values; all other accumulators are cleared after the copy. |
| Interior byte: object name | Same byte and the same writer rule. |

### 15.3 Matched reconstructions used as support

These are `matched` entries of `data/progress.json` on `origin/main`. A match proves compiled code identity, not a name or a purpose. Names are the project's labels (GUESS unless community).

| RVA | Progress name | Support given |
|---|---|---|
| `0x14f4370` | `Function14f4370` | counts active slots 0 to 7 under the global gate |
| `0x14eedf0` | `Function14eedf0` | reads mgr `+0x211`, `+0x218` (screenshot block) |
| `0x150b480` | `ImageSpaceEffect::IsActive` (community) | base activity = effect byte `+8` (FXAA) |
| `0x14eeb00`, `0x14eeb10` | `Function14eeb00`, `Function14eeb10` | override (`+0xb0`) and underwater (`+0xb8`) setters |
| `0x153d830` | `Function153d830` | adapted-light release |
| `0x15550d0`, `0x1555120` | `Function15550d0`, `Function1555120` | texture handle release; filter field store |
| `0x153dc30` | `Function153dc30` | HDR effect deleting destructor; nine shader slots |
| `0x152b1b0` | `ImageSpaceShaderParam::Function152b1b0` | constant upload copy at `index × 16` bytes |
| `0x15832e0` | `Function15832e0` | blur effect constructor: size, bright-pass and HDR flags |
| `0x151ef00` | `BSShaderAccumulator::FinishAccumulatingPostResolveDepth` (community) | runs the post-accumulation passes for accumulator mode 0 |

## Interpretation and alternatives

A renderer differs from retail in these steps if it tonemaps with a logarithmic average, applies the bright-pass threshold to luminance, builds a bloom mip chain, applies the fade before gamma, encodes the output to sRGB, treats the contrast pivot as 0.5, limits the HDR input to 1 after the composite, or runs depth of field before the tonemap. This file does not say which difference explains any observed picture. The exposure ratio `y/x` is 1 at a steady state without storage rounding, so the absolute scale of the scene colour matters.

## Negative results and limitations

- Static only. No runtime trace, no frame capture and no visual claim.
- Writer and reader searches use direct references and data pointers. Indirect and aliased access can be missed. This limits "the one other writer found" (`usesLDR`), "no other writer" (interior byte), "only readers" (underwater block) and "no found reference" (`0x1543550`).
- The blend state of a draw can be inherited from the previous draw. The mode listed for a pass group is the last store found before it, not a captured state.
- Effect class names come from run-time type information; slot meaning follows the registration order in the manager setup (`0x14eee10`).
- Geometry groups 7, 10, 11 and 12 were not identified.
- Rows marked V2 on published finding numbers rest on those runs; the finalizer did not re-read all of them.
- The worked examples apply no render-target storage rounding.

## Reviewer and outcome

Author draft, one independent review and one blind second binary check by separate Sonnet 5.5 runs, merged by a further Sonnet 5.5 finalizer run (Sol unavailable). Outcome of the review: implementable for the ordinary frame after corrections; those corrections and the second check's corrections are applied here. The merged text had no separate review. This is not match evidence for any function and does not decide transfer eligibility. Transfer status: UNREVIEWED.

## Amendment (2026-11-26, from SPEC-4): frame clear colour

Transfer status: UNREVIEWED. Static only. This item comes from the SPEC-4 runs (sky objects and weather; Sonnet 5.5 author, independent review, blind second binary check and finalizer, `claude-sonnet-5-5`). The original text above stays unchanged. This amendment supersedes it for the statement named here only.

### Correction to earlier finding: section 3, row 1

Published: "Clear to `k × fog far colour`".

Corrected: the clear colour is the fog far colour × the **literal 0.83332998** (constant at `0x1869de8`), not `k`. All three sky update paths that write the clear-colour globals use the literal (`0x412253`, `0x412699`, `0x4127a9`); the frame start reads them (`0x656d8b`). With the file value of `k` the difference is about 3.3 × 10⁻⁶ of the colour value. After the console command `sfbr`, `k` changes and the clear colour does not. The rest of the row is unchanged. **V2**.
