Transfer status: UNREVIEWED

# Finding: ordinary exterior HDR path, image-space inputs and SunlightScale reach

## Answer

| Question | Answer |
|---|---|
| 1. What is the ordinary exterior HDR path? | **Verified, static only** for the format and the pass list. **Inferred:** Lighting writes the scene to `kMAIN` (target 1). The pass that writes it was not traced here. The format of `kMAIN` is `R11G11B10_FLOAT` (DXGI 26) by default. It is `R16G16B16A16_FLOAT` (DXGI 10) when `bUse64bitsHDRRenderTarget` is set (G02). The HDR effect runs a 4-tap downsample of its input, a luminance step, a downsample chain until the target is 1 or 2 pixels on a side, a 16-tap adapt pass, a bloom blur and one tonemap pass (G03). The tonemap pixel shader applies, in order: luminance tonemap, bloom add, saturation, tint, brightness and contrast, saturate and a power of `1/fGamma`. The fade variant then blends toward a fade colour (G05). The adapt pass keeps two lagging averages. The tonemap scales luminance by their ratio. The steady-state exposure ratio is 1 if both averages reach the same target (G04). Static only. No visual result is claimed. |
| 2. Which records and settings feed it? | **Verified.** IMGS `HNAM` (9 floats), `CNAM` (3), `TNAM` (4) and `DNAM` (4) fill a 0x50-byte data block. Each weather supplies four IMGS (day parts). The block is a weighted sum with the day-part and weather weights of the DALC mixer (G07, G08). IMAD modifiers then lerp the 12 HDR and cinematic floats toward `x×mult+add` and add tint and fade (G08). Settings: `fReinhardWhiteScale` 1.1, `fFilmicWhiteScale` 1.4, `bUseFilmicCurve` 0, `fGlobalEyeAdaptSpeedScale` 2.0, `fGlobalEyeAdaptStrengthScale` 0.4, the three `fGlobal*Boost` values 0 and `fGamma` 1.0 (G06). The image has no `bDoHighDynamicRange` and no `fHDR*` setting (G10). |
| 3. Which techniques get SunlightScale? | **Verified for the listed readers.** The Lighting per-geometry setup writes sun RGB = `NiLight.diffuse × NiLight.fade × SunlightScale`. Every Lighting technique that reaches it gets this product. Earlier findings (#946, #1003) checked terrain LOD, object LOD and near objects. A second Lighting function and the Effect shader write the same product. Grass gets raw `NiLight.diffuse`, `NiLight.ambient` and the light direction. It gets no fade and no SunlightScale. Water multiplies diffuse by fade and two material factors. It reads no SunlightScale. Sky uses `k × SkyScale`. Particle and distant-tree sun sources are **unverified** (G09). |

| Item | Evidence record |
|---|---|
| Status | OBSERVED for verified claims. Inferred and unverified claims are marked. Static only. No runtime trace. No visual result is claimed. |
| Author | A research run of `claude-sonnet-5-5` (Claude Sonnet 5.5), department task for Mudcrab issue #796, item 18. Not the reviewer below. |
| Human operator | Taylor. |
| Reviewer | A separate fresh-context run of `claude-sonnet-5-5`. A Sol run was not available because of usage limits. See "Independent review". |
| Date | 2026-11-24 CST. The author ran from 01:32 to 02:01 CST. The independent review ran from 02:03 to 02:22 CST. A third Sonnet run applied the review corrections from 02:23 CST and re-read the corrected addresses. |
| Build | `sse-steam-1-7-104`, retail `1.7.104.0`, Steam build 24914197. Measured executable SHA-256 `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f` equals the asserted pin in [builds/target.json](../builds/target.json). The helper of each run asserted the hash. |
| Principal function RVAs | `0x14edbf0` (post-process driver), `0x153d120` (HDR render), `0x153cab0` (HDR setup), `0x153d860` (HDR parameter update), `0x153b680` (render-target setup, GUESS), `0x2a62b0` (IMGS loader), `0x2a6650` (IMGS record initialiser, GUESS), `0x1536a40` (IMGS block constructor, GUESS), `0x1536ac0` (weighted accumulate, GUESS), `0x15370b0` and `0x1537310` (modifier apply, GUESS), `0x1536ff0` (tint and fade normaliser, GUESS), `0x4158d0` and `0x415660` (weather image-space blend and day-part selector), `0x1583400` (blur effect setup), `0x1549550` (Lighting per-geometry setup), `0x154b770` (second Lighting function), `0x1557090` (Effect shader geometry), `0x1522870` (grass frame setup, GUESS). |
| Sources and revisions | The operator's pinned executable. `Skyrim - Shaders.bsa` SHA-256 `fd1ba630f443353ed21ed4ca0380968f9c7091c8434518ea3cc79bc6d38c18e7`. Member `shadersfx/shaders011.fxp` SHA-256 `72cfc73eb0938d5949f0b3a8683722a33b671a34b41b750ba138de8d154c5fbc` (79 groups). The shipped `Skyrim_Default.ini`, `Low.ini`, `Medium.ini`, `High.ini` and `Ultra.ini`. Their full SHA-256 values are in the compiled INI defaults finding (#1052). Published layouts and names from the generated CrashLogger PDB files on `origin/main`. Earlier published findings #806, #812, #822, #946 and #1003. |
| Source exposure | Mixed. Pinned native binary analysis, shipped shader bytecode decoded locally, shipped INI files, earlier published findings and public generated layouts. No value read from a game plugin appears in this file. No downstream or sibling implementation source was used. No raw listing or disassembly is quoted here. |
| Name provenance | Type, field and function names marked `CRASHLOGGER_PDB(59818@2026.10.24)` come from the generated tables: `ImageSpaceEffectHDR::Render`, `::UpdateParams`, `TESImagespaceManager::PostProcessing`, `ImageSpaceEffectBlur::Setup`, `TESImageSpace::ReadFromFileStream`, `TESImageSpace::HDRData`, `ImageSpaceBaseData`, `ImageSpaceData`, `ImageSpaceModData`, `RENDER_TARGET` enumerators, `NiLight` fields and `BSImagespaceShader*` class names. Other function labels are GUESS. Field names of the image-space block (EyeAdaptSpeed and the others in G07) come from the generated layouts. The engine prints two of them under other labels (G07). |
| Intended recipient | Skyrim Research department lead for boundary review under [docs/clean-room.md](../docs/clean-room.md). Proposed use is Mudcrab issue #796. Maintainer transfer decision is pending. |

Addresses are RVAs for image base `0x140000000`. VS and PS mean vertex and pixel shader. `cbN[i]` means constant buffer N, float4 element i. `saturate` bounds its input to [0,1]. **Verified** means re-read at the cited static source. **Inferred** means a deduction with assumptions. **Unverified** means the evidence leaves the claim open. The document contains facts and formulas only. The numbering of groups skips G11. Shipped image-space record values live in the game plugin and are read there, not in the executable. This file holds none of them.

## Question and method

The requester asks three questions. What is the ordinary exterior HDR path? Which data feed it? Which lit techniques receive the image-space sunlight scale?

Method. I read the pinned image through a private local listing. I extracted the shipped shader package. I decoded the 70 image-space records (groups 9 to 78) locally and offscreen with the existing Wine and SDK disassembler. I mapped groups to shader classes by constructor order and checked the map against record content. I re-read each setting value that I cite against the binary.

## Observations

### G01. Frame order and the HDR gate

**Verified.** The post-process driver `0x14edbf0` runs three stages. First it renders the active effects in manager slots 0 to 7. When manager flag `usesLDR` (`+0x210`) is set, slots 3 to 7 are deferred. Then it renders one effect for the HDR stage. It picks slot `0x1e` (30) when byte `0x20d75e4` is nonzero and slot `0x22` (34) when it is zero. Then it renders the deferred slots and, if present, the dynamic-resolution upsample at manager `+0x1f8`. Evidence at `0x14edc41–0x14edcde`, `0x14edd46–0x14edd68`, `0x14edf04–0x14edf6d` and `0x14edf9c`.

**Verified.** Byte `0x20d75e4` has image value 1. The console command `ToggleHDR` (short name `thdr`, help text "Toggles the hdr on or off") flips it. The command record is at `0x2093e70` and the handler at `0x37d4e0`. The HDR effect object, class `ImageSpaceEffectHDR` (vtable `0x1b443c8`, `CRASHLOGGER_PDB(59818@2026.10.24)`), is registered at slot 30 (store at `0x14ef0d4`). **Inferred.** Slot 34 is the non-HDR alternative. Its class was not resolved here.

**Unverified.** The identity of slots 0 to 7, the default state of `usesLDR`, and whether a stock exterior frame uses the deferred branch.

**Confidence: high** for the gate. **Medium** for the stage order, which the independent review only partly re-read. A runtime frame capture would settle slot identity and `usesLDR`.

### G02. Scene colour target format

**Verified.** The render-target setup `0x153b680` builds the target descriptions. It reads `bUse64bitsHDRRenderTarget:Display` (value field `0x20d7380`, compiled default 0) at `0x153b6e2`. It selects format value `0x1a` (26) when the setting is zero and `0x0a` (10) otherwise (`0x153b6fa–0x153b6ff`). Values 26 and 10 are DXGI `R11G11B10_FLOAT` and `R16G16B16A16_FLOAT`. The descriptor for target 1 (`kMAIN`) takes this format with width and height from `0x33363c4` and `0x33363c8` (stores at `0x153b783–0x153b797`, create call near `0x153ba73`). Targets 2 (`kMAIN_COPY`) and 3 (`kMAIN_ONLY_ALPHA`) use the same descriptor (create calls near `0x153baa8` and `0x153bac1`). Target names are `RENDER_TARGET` enumerators, `CRASHLOGGER_PDB(59818@2026.10.24)`.

**Verified.** The shipped presets set the setting to 0 in `Low.ini`, `Medium.ini` and `High.ini`, and to 1 in `Ultra.ini` (line 16 of each). `Skyrim_Default.ini` has no entry.

**Verified.** The same format register is stored in the descriptors of targets 22 (`kHDR_BLURSWAP`) and 24 (`kHDR_BLOOM`) in the same function. Those two descriptors have a width and height of about one quarter of the full size. The width also takes a global factor at `0x20d7308`, which I did not trace. **Unverified.** The formats of the other targets in the function (they carry fixed format values), and the active setting for a given play session. The format limits are properties of the formats: the 11-bit and 10-bit float channels hold no sign and no alpha.

**Confidence: high** for the selection rule and the preset values. A device-level resource dump would confirm the format in use.

### G03. HDR effect chain

**Verified.** The class `ImageSpaceEffectHDR` holds nine shader slots. Setup `0x153cab0` fills them from the manager effect table: slot 2 tonemap (manager index 55), slot 3 fade tonemap (56), slot 4 `ISHDRDownSample4` (58), slot 5 `ISHDRDownSample4RGB2Lum` (60), slot 6 `ISHDRDownSample16Lum` (59) and slot 8 `ISHDRDownSample16LightAdapt` (64). Evidence at `0x153cb4e`, `0x153cc61`, `0x153cd67`, `0x153ce71`, `0x153cf72` and `0x153d05e`. The shader names are `BSImagespaceShader*` strings in the image.

**Verified.** Render `0x153d120` makes five draws, in this order:

1. The slot 4 step (`ISHDRDownSample4`, 4 taps). Its first constant has `cb2[0].x` = 1, so the shader takes the clamped, dynamic-resolution UV path (`0x153d259–0x153d303`). **Inferred.** It reads the effect input colour and writes the first small target. The target identities were not traced.
2. The downsample loop. The first step uses slot 5 (`ISHDRDownSample4RGB2Lum`). Later steps use slot 6 (`ISHDRDownSample16Lum`) until both dimensions are at most `n`. The size limit `n` is 2 when `bUseMultipleLuminanceReferences:Display` (default 1) is set and byte `0x343635d` is zero. Otherwise `n` is 1 (`0x153d321–0x153d33d`). Each step divides each dimension by 4, rounded up (`0x153d35d–0x153d3ab`).
3. The adapt step with slot 8 (`ISHDRDownSample16LightAdapt`).
4. The bloom blur. The shader is picked by `trunc(BloomBlurRadius) − 1`, clamped to 0 to 6, from seven manager effects at indices 23 to 29 (`0x153d610–0x153d62d`, `0x153d685–0x153d689`). **Inferred.** Those seven are the blur and bright-pass effects. Their exact identity was not resolved. The step stores `BloomThreshold` plus `fGlobalBloomThresholdBoost` (or the map boost when byte `0x343635e` is set) to `0x20d9544`, and `BloomScale` to `0x20d9548` (`0x153d64c–0x153d668`).
5. The tonemap draw. The plain tonemap (slot 2) is used when the fade amount at manager `+0x118` is zero or less. The fade tonemap (slot 3) is used when it is above zero.

Targets involved are `kHDR_BLOOM` (24), `kHDR_DOWNSAMPLE0` (26), `kHDR_DOWNSAMPLE1` (27) and `kHDR_BLURSWAP` (22).

**Verified.** Groups of the shipped package map to these shaders in constructor order, and record content agrees: group 26 tonemap, 27 fade tonemap, 28 `DownSample16`, 29 `DownSample4`, 30 `DownSample16Lum`, 31 `DownSample4RGB2Lum`, 32 `DownSample4LightAdapt`, 33 `DownSample4LumClamp`, 34 `DownSample16LightAdapt`, 35 `DownSample16LumClamp`, 36 to 42 `ISBlur3` to `ISBlur15`, 43 to 49 `ISNonHDRBlur3` to `15`, 50 to 56 `ISBrightPassBlur3` to `15`. Every record has one VS and one PS. All 12 checked VS payloads are the same record, SHA-256 prefix `6a98eaf8`. The `LumClamp` PS payloads have the same bytes as the plain variants: group 33 equals 29 (`1abfac94`) and group 35 equals 30 (`1e13dda0`). So the clamp variants differ only in resources or state, not in shader arithmetic. PS payload prefixes: group 26 `1def29cc` (1,876 bytes), 27 `78197820` (1,932), 31 `8c90ec91`, 32 `f290f4ff`, 34 `675f8c78`, 50 `52ca4306`.

**Verified.** The PS record header maps constant index to constant-buffer position in dwords. For group 26 the indices 1, 2 and 3 map to 8, 12 and 16, which are `cb2[2]`, `cb2[3]` and `cb2[4]`. Index 0 maps to `cb2[0]`. Group 27 adds index 4 at 20 (`cb2[5]`). For group 32 and 34 index 2 maps to 8 (`cb2[2]`).

**Unverified.** The native texture-slot to register map for the tonemap. The constructor registers sampler names in the order `Image`, `Blend`, `Avg`. By arithmetic role, register `t1` is the colour that is tone mapped, `t0` is the texture added with a weight and `t2` holds the adapted pair (G05). Which native name holds the scene and which holds the bloom is not established. The tonemap shader samples `t1` at the clamped, dynamic-resolution UV always. It samples `t0` that way only when `cb2[0].x` is above 0.5. That fits `t1` being the scene target, but it is **inferred** and the texture names were not resolved.

**Confidence: high** for the shader map and the constants. **Medium** for the pass list and for slot identity. A runtime capture of the bound resources would settle the texture roles.

### G04. Eye adaptation

**Verified.** Luminance is `L = 0.2125 R + 0.7154 G + 0.0721 B`. Slot 5 writes the weighted sum of four taps of `L` to RGB (equal channels). Slot 6 averages 16 taps of the first channel into all three channels. Tap offsets and weights come from constant-buffer elements that native code fills.

**Verified.** The adapt shader (groups 32 and 34) reads the new average `n` from the chain and the previous pair `p` from the previous adapted texture. For each of two channels `i` it computes `Δ = n − p`, `step = sign(Δ) × min(|Δ|, max(|Δ × r_i|, 1/256))` and `out = p + step`. If the new average is NaN, it keeps `p`. Channel x uses rate `r_x = cb2[2].w`. Channel y uses `r_y = cb2[2].z`. Output Z passes the third input channel. All three input channels carry the same value in the checked chain, so both channels aim at one target `L̄`. The only magnitude limits in the shaders are the `1/256` floor and the `|Δ|` bound. There is no minimum or maximum luminance clamp in the three adapt-related shaders.

**Verified.** The parameter update (`0x153daeb–0x153dbe3`) sets, with `S = fGlobalEyeAdaptSpeedScale × EyeAdaptSpeed`, `K = fGlobalEyeAdaptStrengthScale × EyeAdaptStrength` and `E = 30 × T`:

| Rate | Formula |
|---|---|
| `r_y = cb2[2].z` | `1 − max(1 − 0.01 × S, 0)^E` |
| `r_x = cb2[2].w` | `1 − max(1 − 0.01 × S / K, 0)^E` |

`T` is the float at `0x20d68d4`. Its image value is 0. It is element 1 of four floats at `0x20d68d0` that the loop at `0x2c65e6–0x2c661a` refills through a function pointer at `0x33d3d08`. While the menu path holds a nonzero field at `0x219e5c0+0x160`, `T` is replaced by `fConstHDRAdaptTimerForMenu:Display` (0.3) (`0x153daf2–0x153db09`). **Unverified.** What `T` measures. **Inferred.** It is a per-frame time step. The rates depend on `T`. With `T = 1/60`, so `E = 0.5`, and the compiled defaults of the block constructor (`EyeAdaptSpeed` 3.0, `EyeAdaptStrength` 3.5, so `S = 2.0 × 3.0 = 6` and `K = 0.4 × 3.5 = 1.4`), the formulas give `r_y ≈ 0.030` and `r_x ≈ 0.022` per frame. That arithmetic assumes `T`.

**Verified.** The tonemap divides: `Ls = L × Avg.y / Avg.x` (G05). At steady state, with equal targets, `Avg.y / Avg.x = 1` and the shader applies no net exposure scale. **Inferred.** Brightness changes of the target make `y/x` differ from 1 for some frames, because `r_y` and `r_x` differ. Static only. A capture of the adapted texture would confirm both channel values.

**Unverified.** What fills the first-frame adapted texture, whether the console command `ClearAdaptedLight` (help text "Clears the HDR adapted light texture") resets it to a value other than zero, and the real value of `T`.

**Confidence: high** for the shader arithmetic and the rate formulas. **Medium** for the steady-state reading, because it depends on both channels receiving equal targets, which the checked shaders show but a runtime texture would confirm.

### G05. Tonemap, cinematic and fade pixel shader (group 26, group 27)

**Verified.** The PS arithmetic, for scene colour `c` (register `t1`), bloom colour `b` (register `t0`) and adapted pair `A` (register `t2`):

| Step | Operation |
|---|---|
| 1 | `L = max(0.2125 c.r + 0.7154 c.g + 0.0721 c.b, 1e-5)`. `Ls = L × A.y / A.x`. |
| 2, Reinhard (`cb2[2].z ≤ 0.5`) | `Lt = Ls × (1 + Ls × W2) / (1 + Ls)`, `W2 = cb2[2].y`. |
| 2, filmic (`cb2[2].z > 0.5`) | `x = max(Ls − 0.004, 0)`, `Lt = (x(6.2x + 0.5) / (x(6.2x + 1.7) + 0.06))^2.2 × cb2[2].y`. |
| 3 | `colour = c × Lt / L + b × saturate(cb2[2].x − Lt)`. Bloom enters after the luminance tonemap, with a weight that falls to zero when `Lt` reaches `cb2[2].x`. |
| 4 | `L1 = luminance(colour)`. Saturation: `colour = L1 + cb2[3].x × (colour − L1)`. |
| 5 | Tint: `colour = colour + cb2[4].w × (L1 × cb2[4].rgb − colour)`. It uses `L1` from step 4. |
| 6 | Brightness and contrast: `colour = cb2[3].z × (cb2[3].w × colour − A.x) + A.x`. |
| 7 | `colour = saturate(colour)`, then `colour = colour^(cb12[42].x)`. |
| 8, group 27 only | `result = colour + cb2[5].w × (cb2[5].rgb − colour)`. |

The native update writes these constants (`0x153d8ca–0x153dae6`, evidence of slots in G03):

| Constant | Value |
|---|---|
| `cb2[0]` | zero, so the clamped-UV path is off. |
| `cb2[2].x` | `ReceiveBloomThreshold` (IMGS `HNAM`, struct `+0x10`). |
| `cb2[2].y` | Reinhard: `1 / (fReinhardWhiteScale × White)^2`. Filmic: `H(x_w)^(−2.2)` with `x_w = max(fFilmicWhiteScale × White − 0.004, 0)` and `H(x) = x(6.2x + 0.5) / (x(6.2x + 1.7) + 0.06)`. |
| `cb2[2].z` | `bUseFilmicCurve` as 0 or 1. |
| `cb2[3]` | `(Saturation + fGlobalSaturationBoost, 0, Contrast + fGlobalContrastBoost, Brightness + fGlobalBrightnessBoost)`. The map variants of the brightness and contrast boosts replace them when byte `0x343635e` is set. Saturation has no map variant. |
| `cb2[4]` | `(tint R, G, B, tint amount)` read from the manager working block at `+0xfc`, `+0x100`, `+0x104` and `+0xf8`. The RGB is the value that the block holds when this update runs. The base-data copy multiplies the RGB by the tint amount (G07). The normaliser divides it again (G08). Whether the normaliser runs before this update is **unverified**. |
| `cb2[5]` | `(fade R, G, B, fade amount)` from manager `+0x11c..+0x124` and `+0x118`. The fade shader is used when `+0x118 > 0`. |
| `cb12[42].x` | `1 / fGamma:Display`. The frame-constant writer divides 1.0 by `fGamma` and stores the result in a frame buffer slot (`0x100b314–0x100b31f`). **Inferred.** That this slot is `cb12[42].x` (the #946 and #1003 findings state the same mapping). |

**Verified.** The exponent `2.2`, the constants `6.2`, `0.5`, `1.7`, `0.06` and `0.004`, and the `−2.2` in the white normalization are float32 constants read at RVAs `0x1b44420` (6.2), `0x1b5be14` (0.5), `0x1814564` (1.7), `0x1b44418` (0.06), `0x1b5bdcc` (0.004) and `0x1b44424` (−2.2). The branch on `bUseFilmicCurve` is at `0x153da05–0x153da61`.

**Unverified.** The output alpha channel in the tonemap shaders (it carries arithmetic on a 1.0 start value; I did not use it), the path where `cb2[0].x > 0.5`, and the native names of `t0` and `t1` (G03).

**Confidence: high** for the arithmetic order and constants. A frame capture would confirm which texture is bound where.

### G06. Settings and compiled defaults for this path

**Verified.** I re-read each value at its value field in the pinned image with the local helper. The values match the compiled INI defaults finding (#1052).

| Setting (section Display) | Compiled default | Value field | Role in this path |
|---|---|---|---|
| `bUse64bitsHDRRenderTarget` | 0 (bool) | `0x20d7380` | Format of targets 1 to 3 (G02). |
| `bUseFilmicCurve` | 0 | `0x20d7dc8` | Selects the tonemap curve (G05). |
| `fReinhardWhiteScale` | 1.1 | `0x20d7de0` | White point multiplier, Reinhard branch. |
| `fFilmicWhiteScale` | 1.4 | `0x20d7df8` | White point multiplier, filmic branch. |
| `fGlobalSaturationBoost` | 0 | `0x20d7cf0` | Added to IMGS Saturation. |
| `fGlobalBrightnessBoost` | 0 | `0x20d7630` | Added to IMGS Brightness. |
| `fGlobalContrastBoost` | 0 | `0x20d7cd8` | Added to IMGS Contrast. |
| `fGlobalMapBrightnessBoost`, `fGlobalMapContrastBoost` | 0.25, −0.3 | `0x20d7d50`, `0x20d7d38` | Replace the brightness and contrast boosts when byte `0x343635e` is set (**inferred** a map-menu state, from its writers at `0x99c451` and `0x99c473`). The same byte selects the bloom-threshold variant. |
| `fGlobalBloomThresholdBoost`, `fGlobalMapBloomThresholdBoost` | 0, 0.25 | `0x20d7d08`, `0x20d7d20` | Added to IMGS BloomThreshold before the bright pass (G03 and G12). |
| `fGlobalEyeAdaptSpeedScale` | 2.0 | `0x20d7d80` | Multiplies IMGS EyeAdaptSpeed (G04). |
| `fGlobalEyeAdaptStrengthScale` | 0.4 | `0x20d7d98` | Multiplies IMGS EyeAdaptStrength (G04). |
| `fConstHDRAdaptTimerForMenu` | 0.3 | `0x20d7d68` | Time term while a menu path is active (G04). |
| `bUseMultipleLuminanceReferences` | 1 | `0x20d7db0` | Sets the chain stop size (G03). |
| `fGamma` | 1.0 | `0x20d0348` | Output exponent is `1/fGamma` (G05). Other code writes this field at `0x3778a7`, `0x65cc77` and `0x9ab660`. The writers' semantics were not traced. |

**Verified.** The shipped presets contain only `bUse64bitsHDRRenderTarget` from this list. A text search of the five shipped INIs for `hdr`, `adapt`, `bloom`, `tonemap`, `gamma`, `saturation`, `contrast` and `brightness` found only that key. `bImageSpaceEffects:Display` (default 1, value field `0x20d6a18`) has no direct reader of its value field in the full listing.

**Confidence: high** for the values and roles. A runtime read of the live setting objects would show overrides from the user's INI.

### G07. IMGS record to engine data

**Verified.** The loader `0x2a62b0` reads `HNAM` (36 bytes) into form `+0x20`, `CNAM` (12 bytes) into `+0x44`, `TNAM` (16 bytes) into `+0x50` and `DNAM` (16 bytes) into `+0x60`. These land as one 0x50-byte block at form `+0x20` (struct offsets 0x00 to 0x4f). A legacy `ENAM` (56 bytes) is read into the same block with a different layout and a fix-up (`0x2a652b–0x2a65bd`). Field names are `TESImageSpace::HDRData`, `ImageSpaceBaseData`, `Tint` and `DepthOfField`, `CRASHLOGGER_PDB(59818@2026.10.24)`.

| Struct offset | Field | Compiled default (block constructor `0x1536a40`) |
|---|---|---|
| 0x00 | EyeAdaptSpeed | 3.0 |
| 0x04 | BloomBlurRadius | 7.0 |
| 0x08 | BloomThreshold | 0.6 |
| 0x0c | BloomScale | 0.5 |
| 0x10 | ReceiveBloomThreshold | 0.15 |
| 0x14 | White | 0.15 |
| 0x18 | SunlightScale | 1.8 |
| 0x1c | SkyScale | 1.5 |
| 0x20 | EyeAdaptStrength | 3.5 (the record initialiser sets 3.0, see below) |
| 0x24, 0x28, 0x2c | Saturation, Brightness, Contrast | 0.9, 1.5, 1.1 |
| 0x30 to 0x3c | Tint amount, R, G, B | 0, 0, 0, 0 |
| 0x40 to 0x4c | DepthOfField words | 0, 0, 0 and `0x40000000` at 0x4c |

**Verified.** The `HNAM` copy is a plain 36-byte move, so the serialized order equals the struct order.

**Verified.** Two routines set compiled defaults. The block constructor `0x1536a40` (it initialises the manager's own block and the temporary used by the loader) sets the values in the table above. The record initialiser (`TESImageSpace` vtable slot 4, `0x2a6650`) sets the same values for the record's HNAM, CNAM and TNAM fields except `EyeAdaptStrength`, which it sets to 3.0 (record `+0x40`). It does not set the word at record `+0x6c` (struct `+0x4c`), which the block constructor sets to `0x40000000`. The record's DNAM words are zero in the initialiser.

**Verified.** The copy `0x14eec10` selects the override data (manager `+0xb0`) when it is not null, otherwise the base data (`+0xa8`), and copies it into the manager at `+0xc8` through `0x1536f80`. That copy also premultiplies tint RGB (struct `+0x34..+0x3c`) by the tint amount and stores the amount at `+0x98` (`0x1536fa6–0x1536fdc`). The console commands `SetHDRParam` and `SetCinematicParam` call `0x14eeb20`. When no console data exists it allocates 0x50 bytes, copies the current base data into them and installs the copy as manager `+0xc0` and as the override at `+0xb0` (`0x14eeba9–0x14eebe1`). The commands then store into struct offsets 0x04 to 0x3c (`0x376934–0x3769a6`, `0x37675c–0x376864`). So a console edit overrides the weather data.

**Verified.** `PrintHDRParam` (function range `0x3769c0–0x376bc7`) prints these block fields: speed and strength (`+0x00`, `+0x20`); bloom radius, threshold and scale (`+0x04`, `+0x08`, `+0x0c`); two values labelled "Target Luminance" (`+0x10`, `+0x14`); "Sunlight Scale" and "Sky Scale" (`+0x18`, `+0x1c`); saturation, brightness and contrast (`+0x24`, `+0x28`, `+0x2c`); the four tint values (`+0x30` to `+0x3c`); and the global boost and eye-adapt scale settings. The format strings are at `0x1841850`, `0x1841888`, `0x18418c8`, `0x18418e8`, `0x1841918`, `0x1841958`, `0x1841988`, `0x18419b0` and `0x1841a00`. The engine therefore labels `+0x18` and `+0x1c` Sunlight Scale and Sky Scale. It labels `+0x10` and `+0x14` "Target Luminance", which differs from the `ReceiveBloomThreshold` and `White` names used in this finding.

**Verified.** The executable holds no shipped image-space record values. The shipped values live in the game plugin and are read there. This finding gives none of them.

**Confidence: high.** A runtime dump of the manager block would confirm the active values.

### G08. Weather blend and modifier rules

**Verified.** The weather image-space blend `0x4158d0` clears the 0x50-byte destination at `0x31df470`, then adds weighted copies of up to four IMGS blocks with `0x1536ac0`, which computes `dst[i] += w × src[i]` for all 20 floats (offsets 0x00 to 0x4c) (`0x1536b8c–0x1536c16`). The four weights are `q×m`, `(1−q)×m`, `q×(1−m)` and `(1−q)×(1−m)`. `m` is the current-weather share (`Sky +0x1b8`). `q` is the interpolation between the two selected day parts. The IMGS for each day part is `WTHR.IMSP` index 0 to 3 at weather `+0x7d8`. The day-part selector `0x415660` applies the ordered endpoint schedule in the DALC mixer finding (#1003 G02). If a weather has no form for a day part, the blend uses form `0x167` (`0x4156c2`, `0x415934`). Weights and index choice evidence at `0x415993–0x415a40` and `0x415ac4–0x415b42`. The independent review did not re-derive `q`.

**Verified.** The blend has no nonlinear step. Each field, including the tint RGB and amount, is a weighted average of IMGS fields (for weights summing to 1).

**Verified.** Image-space modifier data (IMAD) applies after the copy. Function `0x15370b0` takes weight `w`, a mult array and an add array. For the 12 HDR and cinematic floats it sets `x ← x − w × (x − (x × mult + add))`. For tint it sets `amount_sum += a`, `rgb_sum += a × rgb`, and keeps the largest amount at `+0x98`. The same form for the second block at struct `+0x50..` handles the fade amount and RGB, keeping the largest amount at `+0x9c` (`0x1537310`). The normaliser `0x1536ff0` then sets amount to the stored maximum and divides each colour by the summed amount. So tint and fade colour are the amount-weighted mean, and the amount is the largest contribution. The UpdateParams reads of tint and fade (G05) take whatever the manager working block holds when they run. If the normaliser ran after the last base copy or modifier apply, they are the normalised values. The frame order is **unverified**. Wrappers at `0x14eeca0`, `0x14eece0` and `0x14eed00`. The normaliser wrapper `0x14eed00` is called from `0x658cf6`, `0x964b39` and `0x98a15f`.

**Unverified.** The per-frame order of the base copy, the modifier apply, the normaliser and the HDR update. The stock use of fade (stock exterior frames likely have fade 0). The set of IMAD records that touch the exterior.

**Confidence: high** for the arithmetic of the blend and of the apply. **Medium** for the frame order. A runtime trace of the manager block across one frame would settle the order.

### G09. Where SunlightScale and related scales are read

**Verified.** The manager's SunlightScale (`+0xe0`, struct `+0x18`) and SkyScale (`+0xe4`, struct `+0x1c`) have the following direct readers. The scan covered every load of the manager pointer `0x33d40a0` (257 loads in the independent re-scan) and tracked the register that holds the pointer. It lists the reads of those offsets.

| Reader | Receives | Formula |
|---|---|---|
| Lighting per-geometry setup `0x1549550` (read at `0x1549aee`; unwind range `0x15496ca–0x1549c14`) | All Lighting techniques that reach the shared per-geometry setup. Terrain LOD, object LOD (techniques 13 and 15) and near objects were checked in earlier findings (#946, #1003) and not re-read here. | `PS b2[1].rgb = NiLight.diffuse × NiLight.fade × SunlightScale`. |
| Second Lighting function `0x154b770` (`0x154b7af`) | Writes the same product. | `SunlightScale × NiLight.fade × NiLight.diffuse`. Direct calls and data pointers to it were not found. **Unverified:** how it is reached. |
| Effect shader geometry `0x1557090` (`0x1557450`) | Effect shader group 5, lit effect path. | `SunlightScale × NiLight.fade × NiDirectionalLight.effectColor`. |
| Sky shader function `0x15525b0` (`0x155296c`) | Sky shader group 4. | `k × SkyScale` into one constant, and `k` into another (`k` at `0x20d694c`). The write is zero for two shader modes (6 and 1). |
| CPU function around `0x726250` (`0x726529`) | Not a shader. | `SunlightScale × a local value + another term`. Purpose not traced. |

**Verified.** Grass does not read SunlightScale. The grass frame setup `0x1522870` takes the scene sun light (`[0x20d68b0]+0x200`, then `+0x48`). It stores raw `NiLight.ambient` (`+0x110`), raw `NiLight.diffuse` (`+0x11c`) and the negated light direction (`+0x140`, `+0x144`, `+0x148`) into file-scope floats at `0x1433d4d90`, `0x1433d4d80` and `0x1433d4d70` (`0x1522a62–0x1522b3d`). The function reads no fade (`+0x134`). **Inferred (earlier grass finding).** Those floats reach `cb2[20]`, `cb2[19]` and `cb2[18]`, and the lit grass PS multiplies the sum of the sun and ambient terms by `cb2[16].w`, which is `k`. The independent review did not re-read the later copy or the PS. A byte at `0x20d68f5` selects a constant alternative (not re-read).

**Verified.** Water setup `0x154ddd0` (`0x154e25c`) multiplies `NiLight.diffuse` by `NiLight.fade` and two further factors from other objects. It does not read SunlightScale. The particle shader copies fields from a source object (`0x157a063–0x157a0ab`). I did not resolve whether that is a sun colour. A scan of the distant-tree shader range found no light-colour read. Both are **unverified**.

**Verified.** Net effect for the same scene light: Lighting sun RGB is `SunlightScale` times grass sun RGB (before grass's `k`). **Unverified.** That a Mudcrab parity gap comes from this difference.

**Confidence: high** for the listed readers and the grass stores. **Medium** for completeness. The scan covers loads through the manager pointer in its own function. A reader that reaches the data through the base-data pointer (`+0xa8`) or through another copy of the block would not appear. A runtime watch on the manager block would close that gap.

### G10. Settings the request names that the image does not contain

**Verified.** The pinned image has no setting named `bDoHighDynamicRange` and no setting that starts with `fHDR`. A strings scan found these HDR-related names: `bUseWaterHDR`, `bDoTestHDR`, `bUse64bitsHDRRenderTarget`, `fConstHDRAdaptTimerForMenu`, `fGlobalEyeAdaptSpeedScale`, `fGlobalEyeAdaptStrengthScale`, `fGlobalBloomThresholdBoost`, `fGlobalMapBloomThresholdBoost`, `fReinhardWhiteScale`, `fFilmicWhiteScale`, `bUseFilmicCurve` and `bUseMultipleLuminanceReferences`. Console commands: `ToggleHDR`, `ToggleHDRDebug`, `ToggleHDRMultipleLuminance`, `SetHDRParam`, `PrintHDRParam`, `SetCinematicParam`, `ClearAdaptedLight`. **Unverified.** The meaning of `bDoTestHDR` (default 0) and `bUseWaterHDR` (default 1).

**Confidence: high** for absence in the image strings. The independent review found no hit for `bDoHighDynamicRange`, `fHDR`, `HighDynamic`, `DoHDR` or `bHDR`, in ASCII or UTF-16.

### G12. Output range scale `k` (value at `0x20d694c`)

**Verified.** The float at `0x20d694c` has image value 0.8333333 (grass leftovers finding). The `SetFramebufferRange` console command writes its reciprocal. Its readers in this path:

| Reader | Use |
|---|---|
| Grass PS | Final colour is multiplied by `k` (`cb2[16].w`). Inherited from the grass finding. The independent review did not re-read it. |
| Sky shader (`0x155296c`) | `k × SkyScale` in one constant and `k` in another. |
| Bright-pass setup (`0x1583c81–0x1583d32`) | The bright-pass constants carry `k` as a post-multiplier (`cb2[1].z`) and `1/k` as a pre-multiplier (`cb2[1].w`). The bright pass computes `Σ w_i × max(c_i × (1/k) − threshold, 0) × BloomScale`, then multiplies by `k`. Threshold is `BloomThreshold + boost` and scale is `BloomScale` (globals `0x20d9544` and `0x20d9548`, written at `0x153d658` and `0x153d668`). |
| Lighting PS | `k` enters the fog and output clamp expression (#1003 G05 and the exterior-fog finding #812). Re-read on the base object record: `out = min(L, Q × S + B) − T × Q × S` with `Q = L − k × M`, where `M` is the fogged colour. With no fog (`F = 0`), `S = 1`, `T = 0` and `B = 1` this is `out = L` while `k × L ≤ 1`, and `out = (1 − k) × L + 1` above that point. This is algebra on the decoded expression. |
| Tonemap PS | No `k` term. |

**Inferred.** The Lighting expression bends high values: for `k = 5/6` the slope above `L = 1.2` is 1/6. This is a consequence of the decoded arithmetic. Static only. **Unverified.** Whether `S`, `T` and `B` take the assumed values for a stock exterior frame.

**Confidence: high** for the value and the bright-pass use. **Medium** for the Lighting reading, because it assumes the frame flags. The other 15 `k` readers were not re-read.

## Interpretation and alternatives

**Verified (arithmetic only).** As decoded, the exterior colour that leaves the HDR effect depends on these steps. A luminance curve with white point `1.1 × White` (Reinhard, default) or `1.4 × White` (filmic). A bloom term weighted by `saturate(ReceiveBloomThreshold − Lt)`. Saturation, tint, brightness and contrast about the adapted `A.x`. A saturate and a power of `1/fGamma`. The adapt pass enters only through the ratio `A.y / A.x`. Lighting sun RGB carries `SunlightScale` and grass sun RGB does not. Lighting applies the `k` expression of the exterior-fog finding. This finding does not state how bright any scene looks. It does not state which of these terms explains a brightness difference in another project.

**Alternative.** If the two adapted channels differ at steady state in a real run (for example through the `1/256` floor), `y/x` may not be exactly 1. That would add a small constant exposure term. A runtime read of the adapted texture would test this.

## Relation to earlier findings

- **#806** (sun shadows): this finding makes no shadow claim and gives no correction to #806.
- **#812** (exterior fog): G12 reuses its Lighting `k` expression (`E = S × (L − k × M)`). The re-read agrees. This finding gives no correction to #812.
- **#822** (terrain LOD shading): this finding does not cover terrain shaders and gives no correction to #822.
- **#946** (terrain LOD versus near landscape): its `fGamma` divide at `0x100b317`, its slot mapping for `cb12[42].x` and its HDR descriptor format selection agree with G02, G05 and G12. This finding gives no correction to #946.
- **#1003** (object LOD ambient, sun and output): its SunlightScale product, IMAD modifier and `k` expression agree with G08, G09 and G12. This finding adds the SunlightScale readers outside Lighting and the HDR chain. It gives no correction to #1003.

Published corrections stay in force.

## Negative results and limitations

- **Verified.** No explicit minimum or maximum luminance clamp exists in the adapt-related shaders. The only magnitude limits are the `1/256` step floor and the `|Δ|` bound. A native clamp outside the shaders was not found in `UpdateParams`.
- **Verified.** The image has no `bDoHighDynamicRange` and no `fHDR*` setting (G10). `bImageSpaceEffects` has no direct reader of its value field.
- **Unverified (runtime).** The meaning of `T`, the first-frame adapted texture, the native names of the tonemap textures (`t0`, `t1`), manager effect slots 0 to 7 and 34, the default of `usesLDR`, the frame order of the modifier apply and normaliser, and the sun source of the particle and distant-tree shaders.
- **Unverified (runtime).** All visual results. Which weather and which `IMGS` apply to a given scene. Any runtime override of settings from the user's INI files. How the second Lighting function `0x154b770` is reached. These need a runtime trace: a resource dump, a constant-buffer capture at the HDR pass, an adapted-texture read, and a watch on the manager block.
- **Unverified.** The independent review did not re-read the technique-level reach of the Lighting setup (it rests on #946 and #1003), the grass PS multiply by `k`, the other 15 `k` readers or the derivation of `q`.
- **Verified.** The overlaps with earlier findings were re-read and agree: the `1/fGamma` constant, the SunlightScale product in the Lighting writer, the IMAD lerp, and the Lighting `k` expression (exterior-fog finding, `E = S × (L − k × M)`). Two items that earlier findings left unverified are now resolved: the active target format by setting (G02) and the pixel-side use of the global boosts (G05).

## Independent review

Reviewer: a separate fresh-context run of `claude-sonnet-5-5`. The reviewer is not the author. A Sol run was not available because of usage limits. The reviewer ran from 02:03 to 02:22 CST on 2026-11-24. It saved an independent extraction for the format, the HDR passes, the adaptation rule, the SunlightScale readers and the setting names before it read the body of the text under review.

Verdict: **8 confirmed, 3 corrected, 1 unverified and cut.** The reviewer checked about 70 statements that carry a number, an address or a formula. About 6 needed a change, which is an error rate of about 6 of 70. No error changed a headline conclusion. The shader dataflow, the format selection, the adapt rule and the SunlightScale reader list are correct. Function labels and cited address ranges needed the most care.

| Group | Verdict | Main point |
|---|---|---|
| G01 Frame order and HDR gate | Confirmed | The gate and the slot choice reproduce. The stage order was only partly re-read. |
| G02 Scene target format | Confirmed | One addition: targets 22 and 24 also take the selected format. |
| G03 HDR effect chain | Corrected | The render function makes five draws. The text under review omitted the slot 4 draw. |
| G04 Eye adaptation | Confirmed | Step rule, rate formulas and the missing clamp reproduce. |
| G05 Tonemap shader | Confirmed | Eight steps and constants reproduce. The `cb12[42].x` link and the tint order caveat are marked. |
| G06 Settings and defaults | Confirmed | All 16 values and value fields reproduce. One cross-reference fixed. |
| G07 IMGS record to engine data | Corrected | The record initialiser sets `EyeAdaptStrength` 3.0 and the block constructor sets 3.5. The `PrintHDRParam` evidence was wrong. |
| G08 Weather blend and modifier rules | Confirmed | The frame order is unverified, as stated. The normaliser caveat is added. |
| G09 SunlightScale reach | Corrected | The Lighting setup label and the grass evidence range were wrong. The reader list is correct. |
| G10 Absent settings | Confirmed | Zero hits for all five absent names. |
| G11 Summary of shipped plugin data | Unverified, cut | The group held game plugin data. The reviewer did not re-derive it. By project policy it is not in this file. |
| G12 Output scale `k` | Confirmed | The value and the bright-pass use reproduce. The grass use and 15 other readers were not re-read. |

**Independence lapse.** The reviewer disclosed one lapse. A search over local text files printed about ten lines of the text under review after the reviewer's own scan of the SunlightScale readers. The reviewer had already found the readers and the function list. The later sub-points on grass, water and particles were read after that glimpse. The reviewer re-read the grass code and treats that sub-point as partly anchored. The other sections were done before the body of the text under review was opened.

**Re-read of corrected items.** The author of the corrected text re-read the corrected and newly cited addresses against the pinned image before this file was written. All items that were re-read agree with the corrected text. The re-read items are the format select at `0x153b6e2`, the stores for targets 22 and 24, the five draws and the slot 4 draw, the chain size rule and the divide by 4, the two default sets (3.5 and 3.0), the `PrintHDRParam` strings, the SunlightScale reads at `0x1549aee`, `0x154b7af` and `0x1557450`, the grass stores, the absence of a fade read in the grass function, the six float constants of G05, the `fGamma` divide, the rate formula structure and the value of `k`.

Source exposure of the review: mixed. The reviewer used the local pinned executable, the shipped shader archive, the shipped INI files and generated name layouts. It did not open the game plugin. This is a static review. It is not match evidence for any function, and it does not decide transfer eligibility.

Reviewer and outcome: Reviewed independently by a separate fresh-context `claude-sonnet-5-5` run. Outcome: 8 confirmed, 3 corrected, 1 unverified and cut, 0 rejected. Static evidence only. Transfer status: UNREVIEWED.

## Amendment (2026-11-24, UNREVIEWED)

**Scope.** Only the statements that the sun source or the light read of the distant-tree shader is unverified. No other row changes. The source is [tree-lod-drawing-retail-facts.md](tree-lod-drawing-retail-facts.md), G06 and G09. **Verified, high. Static only.**

- **Answer row 3, last sentence.** "Particle and distant-tree sun sources are **unverified** (G09)." now reads: the particle sun source is **unverified** (G09). The distant-tree setup reads the raw `NiLight` ambient (`+0x110`), diffuse (`+0x11c`) and negated direction (`+0x140..+0x148`) of the scene sun light (`[[0x20d68b0]+0x200]+0x48`). It reads no SunlightScale and no light fade.
- **G09 prose.** "A scan of the distant-tree shader range found no light-colour read." The first scan of the distant-tree range missed the light read. The tree setup at `0x1558fd0` reads the raw ambient, diffuse and direction of the scene sun light. This is corrected by the tree LOD finding.
- **Open list.** "The sun source of the particle and distant-tree shaders" now reads "the sun source of the particle shader".

The original text above stays unchanged. The amendment supersedes it for these three statements only.

## Amendment (2026-11-25, UNREVIEWED)

**Scope.** Only the statements named below. Addresses are RVAs. **Verified unless marked. Static only. No visual result is claimed.** Sources: a second review of this finding by a separate fresh-context `claude-sonnet-5-5` run, and [hdr-frame-leftovers-retail-facts.md](hdr-frame-leftovers-retail-facts.md). A further fresh-context Sonnet 5.5 run (Sol was unavailable on a usage limit) reviewed that finding and the items below that came from the second review. It had read a memory note that summarised the author's claims before it re-derived them. It reproduced the facts of items 1, 2, 3, 5, 6, 10 and 11 and recomputed the numbers of items 2, 4 and 8. Items 7, 9 and 12 rest on facts that it also checked there. The merged wording of this amendment had no separate review.

1. **G02, targets 22 and 24 (correction).** The sentences "Those two descriptors have a width and height of about one quarter of the full size. The width also takes a global factor at `0x20d7308`, which I did not trace." are replaced by: "The descriptors of targets 22 (`kHDR_BLURSWAP`), 23 (`kLDR_BLURSWAP`) and 24 (`kHDR_BLOOM`) have width `W >> 2` and height `H >> 2`, with `W` and `H` the dwords at `0x33363c4` and `0x33363c8` (stores at `0x153b733` to `0x153b73c`, `0x153b7d2`, `0x153b805` and `0x153b848`). Targets 22 and 24 take the format value that the first paragraph of this group describes. Target 23 has the fixed format value 28. The global at `0x20d7308` is `iShadowMaskQuarter` (compiled default 4). It enters only the descriptor of target 18 (`kSHADOW_MASK`), whose width and height are `(iShadowMaskQuarter × W) >> 2` and `(iShadowMaskQuarter × H) >> 2`. Three sites read the global: the size computation (`0x153b6be`) and two sampler-state checks that compare it with 4 (`0x15226c5`, `0x1548727`)." Confidence: high.
2. **G04, the paragraph on `T`.** The text from "It is element 1 of four floats" to "It is a per-frame time step." is replaced by: "`T` is element 1 of four floats at `0x20d68d0`. The main update loop (`0x658d24–0x658d58`) refills them through the function at `0x65f530` (pointer at `0x33d3d08`), passing the flag byte `0x32303b3`. That byte equals `([0x219e5c0]+0x160 != 0)` (set at `0x658948`). For element 1 the function returns the float at `0x3275608` when the flag is 0, and 0.0 when the flag is nonzero (`0x65f58a–0x65f5c5`). The loops at `0x2c65e6` and `0x2c689c` always pass the flag 1, so they store 0.0 into element 1 after their `Main::Render` call. The HDR update replaces `T` by `fConstHDRAdaptTimerForMenu:Display` (0.3) when the same field is nonzero. The float at `0x3275608` is member `+0x18` of a frame-timer object at `0x32755f0`. `UpdateTimeManager` (`0x659d10`) passes the timer the elapsed time in milliseconds, from the clock (`0xce8430`) and the ticks-per-millisecond float at `0x32755e0`. The timer update (`0xce36b0`) converts to seconds with `× 0.001` and clamps a measured delta above 1/6 s to 1/6 s. It replaces the delta by `1 / iFPSClamp` when `iFPSClamp` is 1 to 199. It keeps the last 8 deltas (`iUnstableFrameTimeHistorySize`, when `bCompensateUnstableFrameTime` is set), uses `(sum − min(largest, 0.05) − smallest) / 6`, and multiplies by a global time multiplier (`0x20ccac8`, image value 1.0). So `T` is a time in seconds. The refill runs before `UpdateTimeManager`, so the HDR update reads the value of the previous frame. Numeric table, with `EyeAdaptSpeed` 3.0 and `EyeAdaptStrength` 3.5 (`S` = 6, `K` = 1.4): `T` = 1/60 gives `r_y` 0.030464 and `r_x` 0.021663. `T` = 1/30 gives 0.060000 and 0.042857. `T` = 0.3 gives 0.427005 and 0.325797. `T` = 0 gives 0 and 0."
3. **G04, step rule (addition).** The `1/256` floor applies even when the rate is 0. Each channel still moves by `min(|Δ|, 1/256)` per adapt draw.
4. **G04, steady state (addition).** For `K > 1` the `x` channel is slower than `y`. After a rise of the target, `Avg.y / Avg.x` is above 1 for some frames (for a step from 0.5 to 0.8 at `T` = 1/60 with the defaults: 1.0052, 1.0100, 1.0145, 1.0186, 1.0224, 1.0259 in frames 1 to 6). After a fall it is below 1. It returns to 1 when both reach the target.
5. **G03, tap tables (addition).** The luminance chain uses static tables that the setup `0x153cab0` copies into the shader constants (calls at `0x153cb93`, `0x153cca0`, `0x153cdac`, `0x153ceb2`). Slot 4 and slot 5: four taps at texel offsets (−1,−1), (1,−1), (1,1) and (−1,1), weight 0.25 each (table at `0x20d7410`). Slot 6 and slot 8: sixteen taps at offsets {−1.5, −0.5, 0.5, 1.5} in x and y, weight 0.0625 each (table at `0x20d7450`). The offsets multiply the texel size `(1/width, 1/height)` of the source. The luminance average is linear. It is not a logarithm. With the compiled defaults the chain ends at a 2 by 2 target, because byte `0x343635d` has no store in the executable. The setup also creates a 1 by 1 target after it. That target ends the chain only when `bUseMultipleLuminanceReferences` is 0.
6. **G03 and G05, texture roles and the adapt draw.** This replaces the G03 "unverified" paragraph on the texture-slot map and the G05 statement that the native names of `t0` and `t1` are unverified. The bind function `0x1554640` stores a texture in a slot of the effect and writes the filter flag into the texture (`0x1555120`). Slot 0 is the output. Slot `k` feeds register `t(k−1)`. The tonemap draw (`0x153d73c–0x153d789`) binds target 24 (`kHDR_BLOOM`, bilinear flag) to `t0`, the HDR effect input (the scene colour, point flag) to `t1`, and the persistent adapted-light handle at `0x20d7608` (bilinear flag) to `t2`. When the handle exists, the adapt draw replaces the final 16-tap luminance step. It binds the chain level above the final one to `t0` and the handle to `t1`, writes the alternate final target, and the output handle is then copied into `0x20d7608`. The bloom blur reads the first downsample (`kHDR_DOWNSAMPLE0`). **Inferred:** the bind flag is the draw-time filter of `t2`, with clamp addressing. The adapted texture is 2 by 2 texels at the default settings, so the tonemap value then varies across the screen between the two texel centres on each axis.
7. **G03, bloom blur.** This replaces "**Inferred.** Those seven are the blur and bright-pass effects. Their exact identity was not resolved." The seven effects at manager indices 23 to 29 are bright-pass-first blur effects of size `k` = 1 to 7. The bloom radius selects `k = clamp(trunc(BloomBlurRadius), 1, 7)`. The effect makes two passes into targets of size `(W >> 2) × (H >> 2)`: pass 0 is `ISBrightPassBlur(2k+1)` (vertical, offsets `(0, u/H)`), and pass 1 is `ISBlur(2k+1)` (horizontal, offsets `(u/W, 0)`), with `u` from −k to k texels. In these offsets `W` and `H` are the size of `kHDR_BLURSWAP`. The weights are static tables at `0x20d7640 + (k − 1) × 0xf0`. For `k` = 1: 0.1065067, 0.7869858, 0.1065067. For `k` = 3: 0.0366328, 0.1112807, 0.2167452, 0.2706822, 0.2167452, 0.1112807, 0.0366328. The seven tables are symmetric, zero beyond `±k`, and sum to 1 within `1e-6`. All seven are in the HDR frame leftovers finding. There is no mip pyramid.
8. **G05 table, step 6 (clarification).** `cb2[3].w` (`Brightness + fGlobalBrightnessBoost`) and `cb2[3].z` (`Contrast + fGlobalContrastBoost`) are multipliers, and the neutral value of both is 1.0. The pivot is `A.x`, the adapted luminance value, in scene units. The output alpha is not saturated in group 26. Worked example, Reinhard, `White` 1.0 (`cb2[2].y` = 0.8264463), `A` = (0.5, 0.5), saturation 1, brightness 1, contrast 1, tint amount 0, bloom 0, `fGamma` 1: input (0.5, 0.5, 0.5) gives (0.4710744, 0.4710744, 0.4710744). Input (2.0, 1.0, 0.25) gives (1.0, 0.9068539, 0.2267135). With brightness 0 both give (0, 0, 0). The example values are for checking only. They are not game data.
9. **New, input range of the tonemap (addition).** The three SAO/fog composite pixel shaders (trailing records 49, 51 and 53 of `shaders011.fxp`) write their output with a saturate on all four channels. The composite writes `kMAIN`. **Inferred:** for a pixel that only the lit pass and the composite wrote, the tonemap scene input is in [0,1] per channel. After the composite (`0x153a1ca`) the same frame runs the post-accumulation passes, a second accumulator render and the first-person view (`0x6577d1`) before the HDR stage (`0x6578d1`). **Inferred:** these can add light to `kMAIN`, which holds values above 1, so the tonemap scene input can exceed 1. **Unverified:** what the second accumulator draws, and the blend state and target of each pass.
10. **G05 and G08, frame order (narrowing).** This replaces the statements that the frame order of the normaliser and the HDR update is unverified. In the main update (`0x658870`) the order is: cross-fade clock step (`0x658bb7`), working-block clear and base copy (`0x658bc3`), the loop over the active modifier instances, the normaliser (`0x658cf6`), the refill of `T` (`0x658d24`), `Main::Render` (`0x659319`), `UpdateTimeManager` (`0x65932a`). In a pause frame (the pause counter is nonzero, or a second byte that the main update tests is nonzero) `UpdateTimeManager` runs right after the refill (`0x658d8f`) instead. A menu test can skip the steps from the clock step to the normaliser. The HDR update runs inside `Main::Render` and reads the working block of the same frame. The normaliser also follows the base copy in three other call pairs (`0x964b2c`/`0x964b39`, `0x98a153`/`0x98a15f`, `0x9a0548`/`0x9a0554`). With no modifier, the tint written to `cb2[4]` is the IMGS tint RGB and the IMGS tint amount. With tint amount 0 the normaliser does nothing and the tint has no effect. **Unverified:** the order of the sky update (reached from job code) against the frame-start copy, so the weather block may be one frame old.
11. **G04, `ClearAdaptedLight` and the first frame (narrowing).** This replaces the statement that the first-frame adapted texture and the effect of `ClearAdaptedLight` are unverified. The command handler (`0x377920`) calls `0x153d830`, which releases the texture of the handle at `0x20d7608` and sets its id to −1 (`0x15550d0`). A release also happens at the start of `0x153b680` (render-target rebuild), when the request byte `0x343635f` is set (the sky update sets it at `0x412024`), and through calls at `0x964b3f`, `0x967f97`, `0x98a164` and `0x99c030` (**inferred** menu and UI code). When the id is below 0 at the HDR render, the adapt draw is skipped and the handle is assigned the result of the full luminance chain of the current frame. The adapted pair is then `(n, n, n)` in every texel, with `n` the current average, so `Avg.y / Avg.x` is 1 for `n > 0` and the frame has no lag.
12. **G03, group index (bookkeeping).** The rule from manager index to group is not a constant offset: indices 55 and 56 map to groups 26 and 27, and index 64 maps to group 34. The blur effects at indices 65, 72 and 79 are the first of `ISBlur`, `ISNonHDRBlur` and `ISBrightPassBlur` (groups 36, 43 and 50; the constructor sites store the indices at `0x14f0d4c`, `0x14f105c` and `0x14f136c`). The identity of group 34 follows from its 16 taps, its rate constants in `cb2[2].zw` and its tap table index. No formula changes.

**Open lists after this amendment.** These entries of G03, G04, G05, G08 and "Negative results and limitations" are now answered: the meaning of `T` (item 2), the first-frame adapted texture (item 11), the native names of `t0` and `t1` (item 6) and the frame order of the modifier apply and normaliser (item 10). The adapted texture size is 2 by 2 (1 by 1 with `bUseMultipleLuminanceReferences` 0). Still open: manager effect slots 0 to 7 and 34, the default of `usesLDR`, all runtime values and visual results, and the constants `cb12[43]` and `cb12[44]` (dynamic resolution).

The original text above stays unchanged. This amendment supersedes it for the statements listed above only.
