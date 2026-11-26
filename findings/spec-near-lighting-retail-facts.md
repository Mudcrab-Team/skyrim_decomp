Transfer status: UNREVIEWED

# Finding: near (non-LOD) lighting from record byte to screen byte (SPEC-1)

## Answer

| Question | Answer |
|---|---|
| What does this file give? | One specification for ordinary near Lighting. It gives the input colours, the pixel formulas, the variants, the fog composite, the HDR steps, the output step, constants, input bindings and worked examples. **Static only. No game run, no frame capture and no visual claim.** |
| Is it complete? | It is implementable for the opaque and sorted-blended Lighting paths and for the variants that the variant table marks "specified". It does **not** cover every variant. Section 12 lists what is open and which variants are not covered. |
| What changed against earlier published text? | Three scoped corrections (section 13): the eye-adaptation step sign at rate 0, a wording clarification of the weather flash clamp, and one inference about decal fog. |

| Item | Evidence record |
|---|---|
| Status | Mixed. Each claim carries a mark (section 0). The marks are listed claim by claim in section 14. |
| Authors / human operator | Sonnet 5.5 author run, Sonnet 5.5 independent reviewer run, Sonnet 5.5 second binary-check run and Sonnet 5.5 finalizer run (all `claude-sonnet-5-5`, each a separate fresh context). A Sol run was not available. Operator: the Skyrim Research department lead. |
| Reviewer and outcome | The reviewer found the first draft not implementable as written and supplied corrections. The second check confirmed the exterior sun chain and the SkyScale rules and corrected four statements. The finalizer applied both sets and re-read the items of section 15. **The merged wording of this file had no further independent review.** |
| Date | 2026-11-25 CST. |
| Build | `sse-steam-1-7-104`, retail `1.7.104.0`, Steam build 24914197. Measured SHA-256 of the executable `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f` equals the pin in `builds/target.json`. |
| Shader package | `shadersfx/shaders011.fxp`, SHA-256 `72cfc73eb0938d5949f0b3a8683722a33b671a34b41b750ba138de8d154c5fbc` (79 groups; group 6 is Lighting, group 4 is Sky). |
| Source exposure | Mixed: pinned native binary analysis, shipped shader bytecode decoded locally and offscreen, shipped preset INI files (text search), published CrashLogger name and layout tables, and earlier published findings of this repository. **No value was read from any game plugin.** No decompiler text and no disassembly appears here. A reader of this file must not claim to be unexposed to the binary analysis. |
| Name provenance | Type, field and render-target names are `CRASHLOGGER_PDB(59818@2026.10.24)` or strings of the image. NAM0 row names are the Sky field names of the same tables. Subrecord names (`XCLL`, `LGTM`, `NAM0`, `FNAM`, `IMSP`, `HNAM`, `XLIG`, `XRDS`, `XEMI`) are public format names; their link to an offset is **inferred** unless a row says otherwise. Sky object type names are inferred. Other labels are GUESS. |
| Intended recipient | Skyrim Research department lead, for boundary review under `docs/clean-room.md`. Maintainer transfer decision pending. |

## 0. How to read this file

| Mark | Meaning |
|---|---|
| **V2** | Verified in the binary or shader bytes by two different runs. |
| **V1** | Verified by one run only. |
| **I** | Inferred. A deduction with stated assumptions. |
| **U** | Unverified or open. |

A claim without a mark in a table or formula block takes the mark of its section 14 row. Addresses are RVAs (image base `0x140000000`). `cbN[i]` is pixel constant buffer N, float4 element i. `VS cbN[i]` is the vertex buffer. `sat(x)` limits x to [0,1]. `⊙` is a per-channel product. Colours are RGB triples. "Record `0x201`" is the group 6 shader record with that key.

Published findings used (each has its own author and reviewer):

| Number | File in `findings/` |
|---|---|
| #812, #1077 | `exterior-fog-retail-facts.md`, `exterior-haze-trace-retail-facts.md` |
| #946, #963, #979 | `terrain-lod-vs-near-retail-facts.md`, `landscape-normal-frame-retail-facts.md`, `near-t19-order-retail-facts.md` |
| #948 | `object-lod-normal-atlas-retail-facts.md` |
| #1003 | `object-lod-ambient-sun-retail-facts.md` |
| #1059, #1272 | `exterior-hdr-path-retail-facts.md`, `hdr-frame-leftovers-retail-facts.md` |
| #1073, #1245 | `point-lights-selection-retail-facts.md`, `light-flicker-time-base-retail-facts.md` |
| #1080 | `sky-sun-ambient-day-retail-facts.md` |
| #1121 | `live-k-composite-target-retail-facts.md` |
| #1258, #1268 | `interior-point-light-look-retail-facts.md`, `interior-light-small-items-retail-facts.md` |
| #1273 | `lighting-features-retail-facts.md` |
| #806, #1248 | `sun-shadows-retail-facts.md`, `sun-shadow-remainder-retail-facts.md` |

## 1. Pipeline map

Implement in this order.

| # | Stage | Input | Operation | Constant slot | Address or record | Mark |
|---|---|---|---|---|---|---|
| 1 | Colour schedule | game hour, climate times, weather transition | four linear weights (section 2.2) | — | `0x416760`, `0x412cb0` | V2 |
| 2 | Weather colour mix | NAM0 rows | `Σ wj × byte × 1/255`, upper limit 1 | `Sky+0xa8+12×row` | `0x4133e0`, `0x414cf0`, `0xef2e80` | V2 |
| 3 | Interior cell colours | `XCLL` or `LGTM` bytes | byte × 1/255 | `Sky+0xcc/0xd8/0xb4/0x138` | `0x2bbe40`, `0x2bbf30`, `0x2bc1b0`, `0x2bc240` | V2 |
| 4 | Image-space block | IMGS blend, modifiers, override | section 2.4 and 10 | manager `+0xc8` | `0x415660`, `0x4158d0`, `0x14eec10` | V2 |
| 5 | Sun | colour, fade, SunlightScale, direction | section 2.3 | `cb2[1]`, `cb2[0]` | `0x41c835`, `0x1549ab6`–`0x1549ba1` | V2 |
| 6 | Directional ambient | DALC | mean and half differences | `cb2[11..13]` (`cb2[14]` seventh colour) | `0x14ec3b0`, `0x1549e89` | V2 |
| 7 | Point lights | colour, fade, dimmer, radius, list | section 2.6 | `cb2[15+i]`, `cb2[22+i]`, `cb2[29]` | `0x274390`, `0x1569550`, `0x154bb90` | V2 |
| 8 | Emission, material | NIF values or emittance source | sections 2.7, 2.8 | `cb2[4].yzw`, `cb1[4]`, `cb2[3]` | `0x1549f3a`, `0x1548fe8` | V2 |
| 9 | Depth prepass | scene geometry | draw depth, then **copy the depth buffer** | depth target 7 | `0x1538fa0`, `0x15399df` | V2 |
| 10 | Shadow masks | — | screen mask texture (not specified here) | `t14` | — | U |
| 11 | Vertex shader | mesh attributes, fog property | section 3 | `VS cb0[1..3]`, `VS cb1[2]`, `VS cb2[6]` | VS records, `0x154c010` | V2 |
| 12 | Lighting pixel shader, first stage | sections 2 to 6 | light sum, albedo, tail with `(S,T) = (1,0)` | section 4 | group 6 records | V2 |
| 13 | Colour target | PS target 0 | `R11G11B10_FLOAT`, or `R16G16B16A16_FLOAT` by setting | `kMAIN` (1) | `0x153b6e2` | V2 |
| 14 | SAO and fog composite | scene copy, AO, depth copy, fog | section 8 | composite `cb2` | `0x1541f40`, trailing records 49/51/53 | V2 |
| 15 | Second stage | sorted blended draws, glare, second accumulator, first person | Lighting tail with `(S,T) = (1,1)` | — | `0x153a1ef`, `0x6577d1` | order V2; blend into `kMAIN` I |
| 16 | Luminance and adaptation | `kMAIN` | section 10 | adapted 2×2 | `0x153d120` | V2 |
| 17 | Bloom | quarter-size copy | threshold, separable blur | `kHDR_BLOOM` | `0x1583400` | V2 |
| 18 | Tonemap | scene, bloom, adapted, image space | section 10 | `cb2[2..4]`, `cb12[42].x` | `0x153d860`, group 26 | V2 |
| 19 | Output | tonemap result | UNORM8 write, no sRGB view | back buffer | `0x1012280`, `0x10124da` | V2 |

## 2. Inputs: from record byte to constant

### 2.1 Absolute scale

There is **no light unit**. A light colour byte becomes `byte/255`. No gamma or sRGB conversion was found on light, ambient, fog or vertex colours (**V2** for the traced producers). Textures are sampled with the file format; that albedo is therefore "used as stored" is **I** (other texture paths were not excluded). The scale factors are only those in section 7.

### 2.2 Day-part weights and weather transition (exterior)

`A = max(0, sunriseBegin − E)`, `B = sunriseEnd`, `C = sunsetBegin`, `D = min(sunsetEnd + E, 23.99)`. Climate `TNAM` bytes are in 10-minute units. `E = fDaytimeColorExtension` (compiled 0.5 h). `h` is the game hour, `M1 = (A+B)/2`, `M2 = (C+D)/2`.

| Hour | First part, weight `t` | Second part, weight `1−t` |
|---|---|---|
| `h ≤ A` or `h ≥ D` | night, 1 | — |
| `A < h < M1` | sunrise, `(h−A)/(M1−A)` | night |
| `M1 ≤ h < B` | sunrise, `1 − (h−M1)/(M1−A)` | day |
| `B ≤ h ≤ C` | day, 1 | — |
| `C < h < M2` | sunset, `(h−C)/(M2−C)` | day |
| `M2 ≤ h < D` | sunset, `1 − (h−M2)/(M2−C)` | night |

Four weights: `q·t`, `q·(1−t)` (current weather), `(1−q)·t`, `(1−q)·(1−t)` (previous weather). `q` is the weather transition fraction (`Sky+0x1b8`): 1 without a previous weather, 0 without a current weather. `q` = elapsed game hours since the last weather update / transition duration; the duration is `fWeatherTransMin + (incoming DATA byte at +0x667 / 255) × (fWeatherTransMax − fWeatherTransMin)`; above 1 the previous weather is dropped. An acceleration branch exists (`q0 + (q − q0)(1 + fWeatherTransAccel)`). **V2** (#1003, #1080).

### 2.3 Sun (exterior) and interior key light

```text
cb2[1].rgb = D × NiLight.fade (1.0) × SunlightScale_active          no clamp
exterior:  D = min(1, Σj wj × NAM0[4][partj, weatherj].rgb / 255)
interior:  D = XCLL directional colour / 255 (or lighting template colour)
```

The pixel shader uses `sat(N·cb2[0]) × cb2[1] × t14.x`; `t14.x` applies only on keys with bit 13.

| Step | Rule | Mark |
|---|---|---|
| Exterior storage | `NAM0` row 4 ("Sunlight"): per day part one dword, bytes R, G, B and an unused byte. Day-part order 0 sunrise, 1 day, 2 sunset, 3 night. Weather offset `+0x698 + 16×row + 4×part`. | V2 |
| Decode | Weighted byte sum, then × 1/255. Linear in the hour. No sRGB decode, gamma or curve. Upper limit 1 per channel. | V2 |
| Lightning | Only when the flash amount is above 0 (rows 3 and 4, no previous weather): add the amount (capped at 1), then limit each channel to [0, `DATA` bytes 12..14 / 255] of the current weather. | V2 |
| Light write | `Sun::Update` stores `Sky+0xd8` into `NiLight.diffuse` (`0x41c835`). It does not write the fade. | V2 |
| Light fade | `NiLight.fade` starts at 1.0. No other writer for the sun light was found in the sky, sun or cell paths (static search; indirect writes are not excluded). | V2 (scoped) |
| Interior source | `XCLL` directional colour (struct `+0x4`). Inherit bit `0x2` with a lighting template takes the template colour. Cell without lighting data: black. | V2 |
| Interior fade float | The `XCLL` **directional fade** (struct `+0x1c`, inherit bit `0x40`) is **not applied**: its getter (`0x2bc0c0`) has no call, jump or data pointer, and no other read was found by pattern search. | V2 (scoped) |
| Interior direction | `XCLL +0x14` (XY angle A) and `+0x18` (Z angle B) are unsigned degrees; inherit bit `0x20`. Light travels along `(cosA cosB, −sinA cosB, sinB)`. `cb2[0] = (−cosA cosB, sinA cosB, −sinB)`. | V2; parent frame I |
| Interior shadow | Bit 13 is never set in interiors. | V2 |
| Exterior direction | `Ls = normalize(u × fSunXExtreme × kd, fSunYExtreme × kd, −fSunZExtreme)`, `kd = fSunDirXExtreme / fSunXExtreme`. Compiled: X 400, Y 25, Z −100, `kd` 1, so `Ls ∝ (400u, 25, 100)`. With `MR`, `MS` the raw sunrise and sunset midpoints, `hT = fSunAlphaTransTime / 2` (compiled 2.0 / 2), `Ds = MR − hT`, `De = MS + hT`: for `Ds < h < De`, `u = 1 − 2(h − Ds)/(De − Ds)`; at night `u = 2t/(24 − (De − Ds)) − 1`, `t = h − De` (or `h + 24 − De` before dawn). The same light keeps moving at night. A later branch can replace the rotation (#1003). | V2; parent frame U |
| Room lighting templates | When a current or previous room has a lighting template, sun, ambient, DALC and fog colours come from the templates and blend from previous to current. | outline V2; timing (3 s smoothstep) and fallbacks V1 |
| Exterior lighting override | In some sky modes a set exterior lighting override (`Sky+0x28`) replaces the weather colours. | V1 |

### 2.4 SunlightScale and SkyScale

Both come from the active image-space block: `HNAM` float 7 is SunlightScale (block offset `0x18`), float 8 is SkyScale (offset `0x1c`).

| Case | Rule | Mark |
|---|---|---|
| Exterior, normal | `WTHR.IMSP` names four image spaces (one per day part). The block is `Σ wj × block_j` over all 20 floats with the weights of 2.2. | V2 |
| Missing image space or weather | The engine default image space, form id `0x167`, takes that weight. Its values are plugin data. | V2 |
| Sky mode 0 | The block of form `0x167`. Modes 1 and 2 do no weather blend. | V2 |
| Record without `HNAM` | Constructor values stay: SunlightScale 1.8, SkyScale 1.5. | defaults V2; "stays" I |
| Interior cell; exterior whose world space has a lighting template | The cell image space (extra type `0x56`), or `0x167`. An interior cell with cell flag bit 8 uses the weather block. | V2 |
| Modifiers (IMAD) | After the frame-start copy, for each active instance with weight `w`: `x ← x − w × (x − (x × mult + add))` for the 12 HDR and cinematic floats. | V2 |
| Override | A console or script image space replaces the base block. | V2 |

**SkyScale readers and use.** The only shading read found is the Sky shader setup (`0x155296c`): `y = k × SkyScale` into sky `cb2[0].y`, with `y = 0` for sky object types 1 and 6. The term is **additive**. It does not reach lit geometry, DALC, sun, point lights, fog or the composite or tonemap constants (**V2**; reads through unknown aliases are not excluded). It reaches other passes only through sky pixels in `kMAIN`.

| Sky object type (name inferred) | Pixel record | Output colour |
|---|---|---|
| 0 (sun disc) | 7 | `tex × v + y` |
| 1 (sun glare) | 1 | `tex × v + dither + y`, with `y = 0` |
| 2 (dome), 4 (sky quad) | 8 | `v + y + dither` |
| 3 (clouds) | 4, 5 or 6 | `tex × v + y` (records 5, 6 blend or fade the texture) |
| 5 (stars) | 3 | `1.5 × (tex × v + y)` |
| 6 (moon disc) | 7 | `tex × v + y`, with `y = 0` |
| 7 (moon-and-star mask) | 2 | the texture only, discard by alpha. It receives `y` but **does not read it**. |

`v` is the interpolated vertex output colour; the vertex shaders scale the sky colour by `k`. For the dome, `v.rgb = k × (c.r × row8 + c.g × row7 + c.b × row0)` with vertex colour `c` and NAM0 rows 8 ("Horizon"), 7 ("SkyLower"), 0 ("SkyUpper"). For clouds the colour is `k` × vertex colour × the weather cloud-layer colour (#1080 G04, G09). **V2**.

### 2.5 Directional ambient (DALC)

- Six colours F0..F5 in record order, plus a seventh colour and a power. Exterior: `WTHR.DALC`, four day parts, mixed with the weights of 2.2 after `byte/255`. Interior: `XCLL` struct `+0x28..+0x3c`, or the template with inherit bit `0x1`; no lighting data: zero.
- Face order: F0 = −X, F1 = +X, F2 = −Y, F3 = +Y, F4 = −Z, F5 = +Z in the space of the world normal. Which world direction the editor calls "up" is **I**.
- Cache (`0x14ec3b0`): per channel `sx = (F1−F0)/2`, `sy = (F3−F2)/2`, `sz = (F5−F4)/2`, `w = (ΣF + G)/6` with `G = 0` in the image.
- Constants: `cb2[11] = (sx.r, sy.r, sz.r, w.r)`, `cb2[12]` green, `cb2[13]` blue. `Am = (cb2[11]·(N,1), cb2[12]·(N,1), cb2[13]·(N,1))`. On non-skinned geometry the slopes are rotated into model space (same world-space result).
- No scale and no clamp. Along an axis the result is not the face colour: `N = +Z` gives `mean + (F5−F4)/2`. It is a linear fit and can leave [0,1].

All **V2** (#1003, #1258, #1268). The flat cell ambient colour (`XCLL` ambient, NAM0 row 3) does not enter the near Lighting shader.

### 2.6 Point lights

| Step | Rule | Mark |
|---|---|---|
| Colour | `LIGH` colour bytes (form `+0xe8`) × 1/255. Form flag bit 2 (Negative): × −1/255. Stored in `NiLight.diffuse`. | V2 |
| External emittance, membership | A light reference in the cell's emittance list (it has `XEMI`, or its model has an external-emittance property). | V1 |
| External emittance, value | Every frame `diffuse = (LIGH colour / 255) ⊙ E`. The Negative sign is not applied again. Source `LIGH`: its colour / 255. Source region: the region weather's NAM0 row 9 ("EffectLighting") with the day-part weights, **multiplied by the sky weather fraction `q`** (the per-light path passes no previous weather), then the flash rule; weather form `0x15e` when the region has none. No source: a default source object, else `E = (1,1,1)`. | V2 |
| Emittance colour stored on a region | The emissive path (2.7) uses the colour stored on the region object. It is computed with the same weather as current and previous, so it has full weight. | V2 |
| Base fade | `NiLight.fade = FNAM fade (form +0x108) + reference offset` (extra type `0x91`, `+0x14`; read as `XLIG` is **I**). An offset equal to the largest float returns the largest float. A set flag byte of that extra (`+0x20`) stores fade 0. No clamp. | V2 |
| Radius | `R = LIGH radius + reference radius offset` (extra `0x59`, read as `XRDS`); `R ≤ 0` → 0.1. | V2 |
| Upload | `cb2[22+i] = diffuse × fade × lodDimmer`. No clamp. `cb2[15+i].xyz` = position, `.w` = radius. Position is in model space (non-skinned) or world minus render offset (skinned). In model space the radius is divided by the geometry scale, except techniques 1 and 16 (divisor 1; effective world radius `R × scale` is I). | V2 |
| Selection | List = [sun] + [shadow-slot lights] + [ordinary lights in list order]; capacity 16; points used = `min(total − 1, 7)`. Entries with the culled state or NiLight flag bit 0 are skipped. **No nearest or brightest sort at the cut.** | V2 (#1073) |
| Admission | A geometry list holds a light only after an attach. Conditions: the light's wrapper scope; `affectLand`, or a property with neither flag 14 nor 46; geometry-centric path: sphere overlap, `distance(light, bound centre) − bound radius < R`; light-centric path: a culling test, plus NiLight flag bit 0 clear and fade ≥ 0.05. A light outside the camera frustum or past the fade end is skipped by the selector. Queued nodes with bound radius below 150 visit candidates by `(d − boundRadius)/R`, largest first. The final order is attach history. | V2 (#1073) |
| Distance dimmer | For a light with the fade flag that is in the frustum: `q = d² − R²` (camera to light centre). `q < begin²` → 1; else `end² = 0` → 1; else `q > end²` → 0 and culled; else `1 − (q − begin²)/(end² − begin²)`. `begin`, `end` are distances from: room lighting template; else cell (`XCLL +0x50/+0x54`, exact zero replaced by settings; template on inherit bit `0x400`); else exterior lighting override; else `fLightLODStartFade` and that plus `fLightLODRange` (shipped default INI 3500; compiled range 500). | V2 (#1073) |

**Flicker and pulse** (**V2**, #1073, #1245). `LIGH` flag bit 3 = flicker; bit 7 or 8 = pulse; bit 6 alone does nothing here. They change `NiLight.fade` and the light's local translation only. They run only within `fFlickeringLightDistance` (1024) of the player. `base` is the fade above; `I = 0.5 × intensity amplitude`; `p` = the `LIGH` period clamped to [0,1]; `dt` = smoothed real frame seconds × time multiplier; `Am` = movement amplitude.

```text
pulse:    P += dt × p; if P > 2π: P −= 2π
          fade = base × (1 − I + I × cos P)
          translate = Am × (cos P, sin P, sin P × cos P)
flicker:  A += dt × p × U(1.1, 13.1);  B += dt × p × U(1.2, 13.2);  C += dt × p × U(1.3, 19.3)
          U = uniform random per frame; each phase subtracts 2π once when above 2π
          n = ((sin(1.3B + 0.65) + 1)/12) × (sin(1.1A + 1.87) + 1) + 0.2 × sin(3C + 0.9),  limited to [−1, 1]
          fade = base × (1 − I + I × n)
          s1 = sin(A + 1.7);  s2 = sin(B + 0.5);  s3 = sin(C + 0.3)
          M = 0.5 × Am × s1 × s2;  M = 0 if Am + M ≤ 0
          translate = (M × s1, M × s2, M × s3)
start:    P = A = B = 0;  C = 16 / R²   (compiled attenuation settings)
```

Retail reads sine and cosine from 512-entry tables with a truncated index. The range of `n` is [−0.2, 0.5333].

### 2.7 Emission

| Step | Rule | Mark |
|---|---|---|
| Source | NIF emissive colour (3 floats) and emissive multiple. No conversion. | V2 |
| Own-emit gate | The loader stores the file colour only with file flag bit 22 (own emit). Otherwise the property keeps its constructor colour (black; the zero value is inferred) unless something repoints it. | V2 |
| External emittance (flag bit 29) | The colour pointer is replaced by the source colour and own emit is cleared. The file colour is not multiplied in. The multiple stays. | V2 |
| Upload | `cb2[4].yzw = colour × multiple`. No clamp, no global scale. | V2 |

### 2.8 Material values and vertex colour

| Item | Rule | Mark |
|---|---|---|
| Specular colour, strength, glossiness, alpha | NIF floats, loaded without scale (material `+0x38`, `+0x8c`, `+0x88`, `+0x80`). | V2 |
| `cb1[4]` | `xyz` = specular colour × strength, `w` = glossiness (the exponent). | V2 |
| `cb2[3].y` | Specular distance fade: 1 near the camera, linear to 0 between `fSpecularLODFadeStart` 0.09 and `End` 0.10 of a distance value whose producer is open. Beyond End the specular flag is ignored. | rule V2; input U |
| `cb2[3].z` | Property alpha = material alpha × pass fade. | V2 |
| Vertex colour | Four bytes, input format `R8G8B8A8_UNORM`. Passed through unchanged. A key without bit 0 outputs (1,1,1,1). | V2 |

## 3. Vertex stage and bindings

### 3.1 Vertex inputs and pixel inputs

Vertex inputs: `POSITION` (float4), `TEXCOORD0`, `NORMAL` (4 values), `BINORMAL` (4 values), `COLOR0`; skinned records add blend weights and indices. **Pixel register numbers differ between records. Bind by semantic.**

| Pixel semantic | Content | Mark |
|---|---|---|
| `TEXCOORD0` | `uv × VS cb1[2].zw + VS cb1[2].xy` (landscape: `.zw` is the distant UV) | V2 |
| `TEXCOORD4` | lighting-space position `p` | V2 |
| `TEXCOORD1..3` | frame rows (absent in non-skinned model-space-normal records) | V2 |
| `TEXCOORD5` | `eye − p` (non-skinned: `VS cb2[6] − position`). Present for specular, soft, rim, back or bit 17, and techniques 1, 11, 16 | V2 |
| `TEXCOORD6`, `TEXCOORD7` | landscape layer weights; `TEXCOORD7.w` distant factor (technique 19) | V2 |
| `TEXCOORD8..10` | rows for the packed normal output (target 2) | V2 |
| `POSITION1`, `POSITION2` | current and previous position for motion vectors | V2 |
| `COLOR0` | vertex colour | V2 |
| `COLOR1` | fog colour `Cf` (rgb), strength `F` (w) | V2 |

Examples: record `0x1` has `COLOR0` in `v11` and `COLOR1` in `v12`. Record `0x201` has them in `v12` and `v13`, with `TEXCOORD5` in `v6`. Record `0x5` has them in `v8` and `v9`.

### 3.2 Tangent frame (not model-space normals)

```text
Nv = 2 × NORMAL.xyz − 1
Tv = 2 × BINORMAL.xyz − 1
Bv = (POSITION.w, 2 × NORMAL.w − 1, 2 × BINORMAL.w − 1)      POSITION.w is used raw
n  = 2 × t1.rgb − 1                                          no Z rebuild
N  = normalize(Bv × n.x + Tv × n.y + Nv × n.z)
TEXCOORD1 = (Bv.x, Tv.x, Nv.x);  TEXCOORD2, TEXCOORD3 = the y and z components
```

Non-skinned records do not renormalise or rotate the three vectors. Skinned records rotate each vector by the blended bone rows and normalise each one. **V2**.

For land quadrant meshes the native builder stores `(Bv.x + 1) × 0.5` in `POSITION.w` while the vertex shader uses it raw (#963 G05, G08; **V2**). If the input layout reads it as a plain float, the red-channel vector of a slope is not the stored tangent (**I**).

**Lighting space.** Skinned: world minus render offset. Non-skinned: model space (sun direction, light positions and DALC slopes are transformed). An implementation in world space with a world normal gives the same result for uniform scale (see the radius note for techniques 1 and 16).

### 3.3 Vertex fog

```text
dist = length(clip.xyz)                       before the divide by w
s    = sat(dist × r − near × r),  r = 1/(far − near)
F    = min(s ^ power, max)
Cf   = nearRGB + F × (farRGB − nearRGB)
```

`VS cb0[1] = (near×r, r, power, max)`, `VS cb0[2]` and `cb0[3]` = near and far colour. When near and far are both 0 the writer gives `(5000000, 0.1, 1, 0)`. With no fog property it writes nothing. `clip` is the retail D3D clip position (`z_clip = F_cam/(F_cam − N_cam) × (z_view − N_cam)`, not reversed depth). **V2** (#812, #1077).

## 4. Constants and settings

| Name | Slot | Value or source (compiled defaults) | Mark |
|---|---|---|---|
| `k` | PS `cb0[0].w`; composite `cb2[1].w`, `cb2[2].w` | 0.8333333 (1/1.2). A console command and a menu draw can change the global. | V2 |
| `B` | `cb0[1].x` | `fLightingOutputColourClampPostLit` 1.0 | V2 |
| `B2` | `cb0[1].z` | `fLightingOutputColourClampPostSpec` 1.0 | V2 |
| `(S, T)` | `cb12[42].y`, `.z` | first stage (1,0); sorted blended draws (1,1) | V2 |
| Sun | `cb2[0].xyz`, `cb2[1].xyz` | section 2.3 | V2 |
| Shadow channels | `cb2[2][i]` | channel of `t14` for shadow-slot light `i` | V2 |
| Fades | `cb2[3].x`, `.y`, `.z` | environment fade, specular fade, property alpha | V2 |
| Emission | `cb2[4].yzw` | section 2.7 | V2 |
| DALC | `cb2[11..13]`, `cb2[14]` | section 2.5; `cb2[14].xyz` seventh colour, `.w` power floored to 1 | V2 |
| Points | `cb2[15..21]`, `cb2[22..28]`, `cb2[29].x`, `.y` | position and radius, colour, count, shadow-light count | V2 |
| Additive term | `cb1[8]` | `x × yzw`; zero at start-up; run-time writers open | V2 start value |
| Material | `cb1[1].rgb`, `cb1[2]`, `cb1[4]` | tint colour; environment scale and mask flag; specular | V2 |
| Alpha reference | `cb11[0].x` | section 6.3 | V2 |
| Shadow mask UV | `cb0[2]` (PS), `cb12[43]`, `cb12[44]` | values not traced | formula V2; values U |
| Rim (snow) | `cb1[13]` | intensity 0.3, exponents 3 and 2; `.w` gate | V2 |

## 5. Textures, targets and gamma

| Slot | Content | Rule | Mark |
|---|---|---|---|
| `t0` | diffuse | as stored | V2 binding; "no decode" I |
| `t1` | normal; alpha = specular mask | `n = 2×rgb − 1`, no Z rebuild | V2 |
| `t2` | model-space-normal keys: specular mask in `.r` | | V2 |
| `t3`, `t4`, `t5`, `t6`, `t12` | by variant (section 6) | | V2 |
| `t14` | screen shadow mask | section 6.1 | V2 |

- The traced DDS path passes force-sRGB = 0, so the view format is the file format (legacy DXT headers map to UNORM). Other texture creation paths were not excluded. A file with a DX10 `_SRGB` format would be sampled as sRGB (**I**).
- No 2.2, 1/2.2, 2.4 or 1/2.4 float constant occurs in the 6,924 group-6 pixel records, and a token scan found no gamma or sRGB conversion (**V2** for that scope; a square or square-root approximation would not show in these scans).
- Empty slots (#1273 G09, **V2**): normal-map default (128,128,255,255) for base and normal; white for glow; black for height and for a missing model-space specular map; zero cube for the environment cube. A missing environment mask gives `h = 0`. Property bit 20 forces a black base map. Landscape keys first bind black to all 16 pixel slots, then layer diffuse `t0..t5` and normal `t7..t12`.
- Sampler filter, address mode, anisotropy and mip bias are open.
- Scene target `kMAIN`: `R11G11B10_FLOAT` (26) by default; `R16G16B16A16_FLOAT` (10) with `bUse64bitsHDRRenderTarget` (compiled 0; the shipped Ultra preset sets 1). The 11/10-bit float format has no sign and no alpha, so a negative value stores as 0 (**I**).
- Swap chain: `R8G8B8A8_UNORM` (28), two buffers; the back-buffer view has a null description, so no sRGB write. **V2**.
- The tonemap writes the back buffer when no later effect runs, else an 8-bit temporary copy (target 41) (**V2**). That the normal gameplay call is the one with output id 0 is **I**.
- **Only gamma step found:** the tonemap exponent `1/fGamma` (`cb12[42].x`). `fGamma` compiled 1.0. The options slider writes `fGamma = fGammaMin + s × (fGammaMax − fGammaMin)` with 0.6 and 1.4; a reset stores 1.0; the console can set it. **V2**. A display gamma ramp was not searched.

## 6. Lighting pixel shader

### 6.1 Plain opaque case (technique 0, record `0x00000001`)

```text
n  = 2 × t1.rgb − 1
N  = normalize(v3·n, v4·n, v5·n)                    TEXCOORD1..3, section 3.2
p  = TEXCOORD4
S  = sat(N · cb2[0].xyz) × cb2[1].xyz × ms          ms = t14.x with bit 13, else 1
P  = 0;  for i in 0 .. min(cb2[29].x, 7) − 1:
         d  = cb2[15+i].xyz − p
         a  = 1 − sat(|d| / cb2[15+i].w)²
         C' = cb2[22+i].xyz × mi
         P += sat(N · normalize(d)) × C' × a
Am = (cb2[11]·(N,1), cb2[12]·(N,1), cb2[13]·(N,1))
Σ  = (S + P) + (Am + cb2[4].yzw)
Σ  = Σ + cb1[8].x × cb1[8].yzw
L  = t0.rgb × Σ × vc.rgb
alpha = t0.a × cb2[3].z × vc.a
```

No clamp acts on any colour, on `Σ` or on `L`.

**Shadow mask** (keys with bit 13, or bit 14 with a shadow count above 0):

```text
s    = (SV_Position.xy × cb12[44].xy) × cb0[2].xy + cb0[2].zw
uv14 = clamp(s × cb12[43].xy,  0,  (cb12[44].z, cb12[43].y))
mi   = t14[j], j = trunc(cb2[2][i])     for i < min(cb2[29].y, 4) on bit-14 keys
mi   = 1                                for all other point lights
```

In a record with bit 14 and without bit 13, the sample happens only when the shadow count is above 0. That `uv14` is the screen position of the pixel is **I**. All formulas **V2**.

### 6.2 Specular (bit 9) and ambient specular (bit 17)

```text
E     = normalize(TEXCOORD5)
g     = cb1[4].w
Cs'   = cb2[1].xyz × ms
spec  = sat(N·normalize(E + cb2[0]))^g × Cs'
        + Σi sat(N·normalize(E + li))^g × C'i × ai            li = normalize(cb2[15+i] − p)
Spec  = spec × m × cb2[3].y × cb1[4].xyz                      m = t1.a (t2.r on model-space-normal keys)

Aspec = sat(rows·(N, 0.15)) × cb2[14].xyz × (1 − sat(N·E)) ^ cb2[14].w
        rows = cb2[11..13]; sat acts per channel
```

`Spec` has no `N·L` factor, no diffuse texel and no vertex colour. `Aspec` has no albedo and no mask. Both are added **between** the two output stages. Bit 9 follows property flag bit 0 or 41. **V2**.

### 6.3 Alpha test, screen door, hair decals

| Rule | Text | Mark |
|---|---|---|
| Bit 20 is set | for a blended pass with alpha-property test bit 9; or for a decal (flag 26 or 27) with flag bit 41 clear. While byte `0x3336405` is nonzero (image 0) every alpha-tested property gets it. | V2 |
| Test | `alpha = t0.a × cb2[3].z × vc.a`; discard if `alpha < cb11[0].x`. `cb11[0].x = trunc(threshold byte × property alpha)/255`, 0 when the test is off. | V2 |
| Opaque, non-decal, alpha-tested | Normally no bit 20; the cut comes from the depth prepass and an equal-depth first stage (prepass shader not decoded). | I |
| Screen door (bit 23) | Discard if `cb2[3].z < T[4·(x mod 4) + (y mod 4)]`, `T` = (0.003922, 0.533333, 0.133333, 0.666667, 0.8, 0.266667, 0.933333, 0.4, 0.2, 0.733333, 0.066667, 0.6, 0.996078, 0.466667, 0.866667, 0.333333). Alpha output and test then use `t0.a × vc.a`. | V2 |
| Hair decal (technique 6, bit 15) | Discard if `alpha < 4/255`; `alpha2 = sat(1.05 × alpha)` is the output; discard if `alpha2 < cb11[0].x`. | V2 |

## 7. Output tail and the absolute-scale formula

```text
M  = L + F × (Cf − L)

One stage (no bit 9, no bit 17):
  Q   = L − k × M
  O   = min(S × Q + B, L) − T × S × Q

Two stages (bit 9 or bit 17):
  X1  = min(S × (L − k × M) + B, L)
  Y   = X1 + Spec + Aspec
  M2  = Y + F × (Cf − Y);  Q2 = Y − k × M2
  O   = min(S × Q2 + B2, Y) − T × S × Q2
```

| Draws | `(S,T)` | Result |
|---|---|---|
| First stage (opaque, decals, alpha-tested) | (1,0) | one stage `min(L − kM + B, L)`. The colour carries no fog while `kM ≤ B`; the composite adds fog and `k`. |
| Sorted blended draws (second stage) | (1,1) | one stage `min(k × M, B)`; two stages `min(B2, k × M2)`. Fog and `k` act inside the shader. |

With `F = 0` and `L > B/k = 1.2`, the first-stage one-stage output is `B + (1−k) × L` (slope 1/6). Example only: `L = 1.5` gives 1.25.

**From record byte to screen byte** (opaque pixel that only the first stage and composite record 53 wrote, no screen-space reflection or sparkle term):

```text
1. L     = Tex ⊙ Vc ⊙ [ sat(N·Ls)·D·SunlightScale·ms + Σi sat(N·li)·Ci·ai·mi + Amb(DALC/255) + Em + Add ]
2. O     = min(L − k·M + B, L)                          (specular: O = min(Y − k·M2 + B2, Y))
3. c     = sat( k·[(1−Fc)·AO·(max(O,0) + g) + Fc·Cfc] )  if d < 0.999999, else sat( AO·(max(O,0) + g) )
4. col   = c·Lt/Lm + bloom·sat(R − Lt),  Lm = max(lum(c), 1e−5),  Lt = curve(Lm · A.y/A.x);  then saturation, tint, brightness and contrast about A.x
5. byte  = round( 255 · sat(col) ^ (1/fGamma) )
```

`D`, `Ci` and `Em` are the section 2 values (`Ci` = `cb2[22+i]` = colour × fade × dimmer, with the emittance factor). `max(·,0)` stands for the unsigned target format (**I**; not for the 16-bit float target). `g` is the snow term. `d` and `Fc` are in section 8; `R`, `A` and `curve` in section 10. `round` is the assumed UNORM8 conversion (**I**).

Consequences (arithmetic): with `Fc = 0`, `AO = 1`, `g = 0` and `d < 0.999999` the composite stores `min(1, k × O)`. Without specular and with `k × M ≤ B`, `O = L`, so it stores `min(1, 0.8333333 × L)`. A specular pixel stores `min(1, k × O)` where `O` includes `Spec`. Record 49 (no fog) has no `k`.

## 8. Depth, fog composite and the HDR input

### 8.1 Frame order

Depth prepass → **depth copy** → shadow mask → first stage (lit opaque, sky objects, decals) → composite → second stage (sorted blended, sun glare) → second accumulator → first-person view → (volumetrics if enabled) → post-processing. **V2**.

**The composite depth `d` is not the colour-stage depth buffer.** It is the copy that `RenderDepth` makes after the depth prepass and before the first colour stage (`0x15399df`; the call at `0x657213` precedes the world render at `0x6576be`). A second copy site inside the first stage (`0x151f2c2`) is skipped in this frame because its flag bit is clear. A pixel that no prepass draw wrote keeps the cleared depth: it gets no fog and no `k`. Which geometry the prepass draws is **U**. **V2** for the binding.

The frame clear colour is `k × fog far colour` (**V2**).

### 8.2 Fog colour and distances

| Item | Exterior | Interior |
|---|---|---|
| Near colour | NAM0 row 1, mix of 2.2, /255, upper limit 1 | `XCLL` fog near bytes /255, or template (inherit bit `0x4`) |
| Far colour | NAM0 row 12, same rule | `XCLL` struct `+0x48` (bit `0x4`). At load a far colour with four zero bytes takes the near colour (cell and template) |
| near, far, power, max | `WTHR.FNAM` day and night sets, one linear ramp `w`: `(h−A)/(B−A)` for `A<h<B`; 1 for `B≤h≤C`; `(D−h)/(D−C)` for `C<h<D`; else 0. Value `w×day + (1−w)×night`; weathers then mix with `q` | `XCLL` near (bit `0x8`), far (`0x10`), power (`0x100`), max (`0x200`). `far ≤ 0` or `> 163840` → 163840. `near ≤ 0` or `> far` → `far × 0.17`. No lighting data: power 1, max 1 |
| Camera-distance override | While byte `0x20b3368` is 0, **both** paths replace `far` by a scene limit `Lim` and set `near' = min(Lim, near − ((far − Lim)/(far − 15)) × (near − 15))` from the old values. The image value of the byte is 1, so the step is skipped | same |
| Property | `Atmosphere::Update` copies near RGB to fog property `+0x38`, far RGB to `+0x44`, scalars to `+0x50/+0x54/+0x84/+0x88`, without scale. It installs the property in every sky mode | same |

All **V2** (#812, #1077, #1080 and the runs of this file). No SkyScale, sun direction or height term enters the fog.

### 8.3 Composite records

| Record | Selected when | Formula |
|---|---|---|
| 53 SAO + fog | `bSAOEnable` and fog (fog property present and `bSAOApplyFog`) | below |
| 51 fog only | fog, SAO off | same without `AO` |
| 49 SAO only | no fog | `sat(AO × C)`: **no `k`**, no fog |
| generic effect `0x22` | both off | not decoded |

Compiled `bSAOEnable` = 1 and `bSAOApplyFog` = 1; the shipped presets keep `bSAOEnable` = 1. So record 53 is the default in exterior and interior. `ToggleFog` flips the fog flag. **V2** (selection by record ordinal: medium-high).

```text
C    = scene copy (kMAIN before the composite)
C   += screen-space reflection term               only if cb2[10].z > 0.5 and a mask test passes
C   += t4.x × t4.y                                snow term g, only if cb2[5].w ≠ 0
AO   = t1.x;  if cb2[5].w ≠ 0 and t4.y > 0.00001:  AO = min(t1.x + cb2[8].x, 1)
d    = depth copy, raw hardware value
d'   = 1.01 d − 0.01
z    = 2 N F / ((N + F) − (2d' − 1)(F − N))        N = cb2[3].x, F = cb2[3].y (camera near, far)
s    = sat(z × cb2[0].y − cb2[0].x);  Fc = min(s ^ cb2[0].z, cb2[0].w)
Cfc  = cb2[1].rgb + Fc × (cb2[2].rgb − cb2[1].rgb)
rgb  = d < 0.999999 ?  cb2[1].w × (AO×C + Fc × (Cfc − AO×C))  :  AO × C
out  = sat(rgb × (1 − cb2[7].w) + sparkle)          cb2[7].w = "sparkles only" = 0 normally
```

`cb2[0] = (near×r, r, power, max)`, `cb2[1] = (near colour, k)`, `cb2[2] = (far colour, k)`. If `far == near` the composite writes `(5000000, 0.1, 1, 0)`. The composite uses the axial depth `z`; the vertex fog uses the clip-space length. `AO` comes from the SAO pass, which this file does not define.

### 8.4 Sky pixels and later draws

- Sky objects draw in the colour stage with depth 1.0. **I:** the depth copy therefore holds the cleared value on them, so the composite writes `sat(AO × sky result)`; `k` is already in the sky shader result. Sun glare draws after the composite. AO on sky pixels is **U**.
- After the composite, the sorted passes, the second accumulator and the first-person view draw into the frame. That they add light to `kMAIN` is **I**; the format holds values above 1, so the tonemap input can exceed 1 on those pixels (**I**). For composite-only pixels the tonemap input is in [0,1].

## 9. Variants

### 9.1 Technique and key

Pixel key = `technique << 24 | (raw & (0xfffffe05 | ((raw >> 1) & 2))) | 1`. When several predicates hold, the highest one wins. Priority, highest first: eye 16 (flag 17) > 14 (flags 23 and 41) > tree anim 12 (61) > multilayer parallax 11 (56) > LOD HD 15 (63) > LOD objects 13 (34) > LOD land noise 18 (33) > landscape LOD blend 19 (46) > landscape 8 (14) > parallax occlusion 7 (28) > hair 6 (18) > face tint 5 (21) > face 4 (10) > parallax 3 (11 and not 28) > glow 2 (38) > environment 1 (7) > none 0. Technique 7 becomes 0 while `bEnableParallaxOcclusion` is 0 (compiled 0). `bSimpleLighting` (compiled 0) forces 0. **V2** (#1273).

| Raw bit | Meaning | Set when |
|---|---|---|
| 0 | vertex colour | flag 37 |
| 1 | skinned (pixel key keeps it only with bit 2) | flag 1 |
| 2 | model-space normals | flag 12 |
| 9 | specular | flag 0 or 41; or the object snow rule |
| 10, 11, 12 | soft, rim, back | flags 57, 58, 59 |
| 13, 14 | sun mask, local masks | shadow state |
| 15 | projected UV; on technique 6 hair decal | flag 23; or decal with flags 32 and 18 |
| 16 | anisotropic | flag 53 |
| 17 | ambient specular | not traced in every case |
| 20 | alpha test | section 6.3 |
| 21 | snow | snow rules with `bEnableImprovedSnow` |
| 22 | character light | flag 40 |
| 23 | screen door | fade condition |

### 9.2 Variant table

| Variant | Selector | Change from the plain opaque case | Status |
|---|---|---|---|
| Plain opaque | technique 0 | sections 6, 7 | specified |
| Vertex colour off | bit 0 clear | `vc = (1,1,1,1)` | specified |
| Skinned | flag 1 | skinned frame and lighting space (section 3.2) | specified; skinning itself not described |
| Model-space normals | bit 2 | Not skinned: `N = 2 × (t1.r, t1.b, t1.g) − 1`, no normalise. Skinned: that vector through the frame rows, then normalise. Mask `t2.r` | specified, V2 |
| Specular, ambient specular | bits 9, 17 | section 6.2, two stages | specified, V2 |
| Sun and local shadow masks | bits 13, 14 | section 6.1 | sampling specified; mask production open |
| Blended | **non-decal** pass with alpha-property blend bit 0, or property alpha < 1 | Sorted second stage, `T = 1`; not touched by the composite. Blend by (src,dst) factors: (6,7) → SrcAlpha/InvSrcAlpha; (6,0), (0,0), (6,9) → SrcAlpha/One (so One/One draws as SrcAlpha/One); (4,7) → DestColor/InvSrcAlpha; (1,2), (4,1) → DestColor/Zero; other pairs keep the mode; alpha < 1 without bit 0 → SrcAlpha/InvSrcAlpha. Blended decals stay in the first stage. Fading objects can use other draw groups | specified, V2; sort key and target open |
| Environment | technique 1 | `V = normalize(TEXCOORD5)`; `R = 2(N·V)N − V`; `m = t1.a + h × (t5.r − t1.a)`, `h = cb1[2].y`; `E = t4(R).rgb × m × cb1[2].x × cb2[3].x`; `L = A × Σ × vc + E × Σ`; `A = t0.rgb` without bit 15. `E` has no albedo and no vertex colour. Beyond `fEnvmapLODFadeEnd` (0.10) the technique is dropped unless flag 60 is set. One vertex record shows `V` and `N` in world space | specified, V2; frame of other vertex variants medium |
| Glow | technique 2 | `Σ = S + P + Am + cb2[4].yzw × t6.rgb + Add`. Only emission uses the glow map | specified, V2 |
| Alpha test, screen door, hair decal | section 6.3 | | specified, V2 |
| Decal | flag 26 or 27 | section 9.3 | specified for grouped decals, V2 |
| Parallax | technique 3 | `V = normalize(TEXCOORD5)` in model space; `uv' = uv + V.xy × (0.08 × t3.r(uv) − 0.04)`; `t0`, `t1` at `uv'`. A parallax pass without specular, soft, rim, back or bit 17 does not get `VS cb2[6]` written | specified, V2; that last case U |
| Face | technique 4 | `a = t0.rgb`; `Df = (t4.rgb + (1/255, 0, 1/255)) × 255/64`; `A = Df × (a² + 2 t3.rgb a (1−a))`; `L = A × Σ × vc` | specified, V2 (without soft term) |
| Face tint | technique 5 | `A = (a² + 2 c a (1−a)) × (259/256, 255/256, 259/256)`, `c = cb1[1].rgb`; `L = A × Σ × vc` | specified, V2 |
| Hair | technique 6 | `L = a × Σ × (1 + vc.g × (c − 1))`, `c = cb1[1].rgb`; vertex RGB is not used otherwise; specular is not tinted | specified, V2 (without anisotropy) |
| Eye | technique 16 | Vertex: `Ne = normalize(skinned position − skinned eye centre)`, centre `= lerp(centre0, centre1, TEXCOORD2.x)`. Sun and points use `N`, ambient uses `Ne`; `R = 2(Ne·V)Ne − V`; `E = t4(R) × m × cb1[2].x × cb2[3].x`, `m` as environment; `L = a × Σ × vc + E × Σ` | specified, V2 |
| Near landscape | technique 8 | Weights `w0..w3 = TEXCOORD6.xyzw`, `w4, w5 = TEXCOORD7.xy`, not renormalised. `albedo = Σ wi t[i].rgb`; `n = Σ wi (2 t[7+i].rgb − 1)`; `m = Σ wi t[7+i].a`; exponent `g = Σ_{i<4} wi cb1[11][i] + w4 cb1[12].x + w5 cb1[12].y`; frame as 3.2; `L = albedo × Σ × vc`; `Spec` uses this `m` and `g`. Target 0 alpha is 0 | specified, V2 (not bit 21) |
| Near landscape with distant blend | technique 19 | `s = TEXCOORD7.w × cb1[0].z`; `Bd = t13(TEXCOORD0.zw)`; `nr = t15.r(3 × TEXCOORD0.zw)`; `e = sat((0.55 (Bd.r+Bd.g+Bd.b) − 0.4) × 1.666667)`; `mr = lerp(nr, 0.37, 0.8 e² (3 − 2e))`; `md = 0.37 + 0.833333 mr`; `albedo19 = lerp(albedo, md × Bd.rgb, s)`. Before the frame: normal `x(1−s)`, `y(1−s)`, `z + s(1−z)`; specular mask × `(1−s)`. Then light, vertex colour and tail as above. Target 0 alpha `= Bd.a × md × s × cb2[3].z × vc.a` | specified, V2 (not bit 21) |
| Snow (object) | bit 21 | section 9.4 | colour and target 3 specified; snow subsurface open |
| Refraction | flag 2 or 15 | No Lighting pass | selection V2; frame effect not covered |
| LOD (techniques 9, 13, 15, 18) | — | **excluded**; see #822, #946, #1003 | excluded |

**Not covered:** projected UV albedo (bit 15 outside hair), soft, rim (outside snow), back, anisotropic and character lighting, multilayer parallax (11), tree animation (12), technique 14, parallax occlusion, landscape snow-layer keys (bit 21 on techniques 8 and 19), effect shader, water, grass, tree and particle shaders, runtime-created decals, wetness.

### 9.3 Decals

| State | Non-blended decals (draw groups 3 then 2) | Blended decals (group 4) |
|---|---|---|
| Stage | first stage, after the opaque lit lists and sky, before the composite | same |
| Depth | LESS_EQUAL, **write on** | LESS_EQUAL, **write off** (a render flag `0x20` gives write on and no bias change) |
| Colour write | all targets except target 1 | **target 0 only**. A blended decal whose property has Z-write flag 32 instead writes target 0 without alpha and all other targets |
| Raster bias, byte `0x3436311` = 0 (image value) | bias −1, slope −0.65, clamp −100; viewport MaxDepth reduced by 2.6e-5 (group 3) or 2.8e-5 (group 2) | same bias; MaxDepth reduced by 3.0e-5 |
| Byte `0x3436311` nonzero | bias 0, slope 0; MaxDepth reduced by 1.5e-5 or 1.7e-5 | bias 0; 1.9e-5 |
| Byte `0x20d683a` = 0 (image 1) | no bias and no reduction | not affected |

All **V2**. Which gameplay frame has byte `0x3436311` nonzero is open. Per-pass blend for decals depends on stage flags and was not traced. **Fog:** the composite reads the depth copy made before the colour stage, so a decal's colour-stage depth write is not seen by the composite (**V2**). Whether the prepass draws decals is **U**.

### 9.4 Snow

- **Object snow rule** (`bEnableImprovedSnow`, compiled 1): key bits 9 and 21 are set when the property has none of flags 33, 34, 46, 63 and either (a) flag 60 (Snow) is set **and flag 61 (TreeAnim) is clear**, or (b) flag 30 is set. Flag 30 with projected UV (flag 23) also sets key bit 19. **V2**.
- Colour: the light sum equals the plain sum. In a record with bits 9 and 21 and no projected UV, `Spec` is **not** added to the colour. The record still runs two output stages with nothing added between them (`Y = X1`). **V2** for records `0x200001` and `0x200201`.
- Rim: `rim = cb1[13].x × (1 − sat(Ng·e))^cb1[13].y × (1 − sat(N·e))^cb1[13].z` when `cb1[13].w > 0.00001`. `Ng` is the normalised third column of the frame; `e` is the view vector in specular records and `(1,1,1)/√3` in the record without specular.
- Target 3: `x = dot(rim [+ Σ point specular], (0.3, 0.59, 0.11))`, without sun specular, mask or material colour; `y = t0.a`. The composite adds `g = x × y` and uses `y` for the AO lift.

## 10. HDR chain: image space, adaptation, bloom, tonemap

Image-space block order: EyeAdaptSpeed, BloomBlurRadius, BloomThreshold, BloomScale, ReceiveBloomThreshold, White, SunlightScale, SkyScale, EyeAdaptStrength (`HNAM`); Saturation, Brightness, Contrast (`CNAM`); tint amount and RGB (`TNAM`). Constructor defaults: 3.0, 7.0, 0.6, 0.5, 0.15, 0.15, 1.8, 1.5, 3.5 (3.0 in a new record), 0.9, 1.5, 1.1, tint 0. Room image spaces cross-fade with a 3 s smoothstep. The HDR effect runs while byte `0x20d75e4` is 1 (`ToggleHDR`). The scene input is `kMAIN` when no earlier image-space slot is active (earlier slots are not covered). **V2**.

`lum(c) = 0.2125 r + 0.7154 g + 0.0721 b`, linear.

1. **Downsample.** 4 taps at offsets (±1, ±1) source texels, weight 0.25, bilinear, into level 0 of size `max(ceil(W/4), 2) × max(ceil(H/4), 2)`.
2. **Luminance chain.** The first step takes 4 taps (±1) of `lum` (bilinear). Later steps take 16 taps at offsets {−1.5, −0.5, 0.5, 1.5}², weight 1/16 (point). Each step divides each axis by 4, rounded up, minimum 2, until 2×2 (1×1 when `bUseMultipleLuminanceReferences` is 0).
3. **Adapt.** When an adapted pair exists, the adapt draw replaces the last 16-tap step. It reads the level above bilinearly and the previous pair `p` by point. For channel `i` of `(x, y)`, with `n` the new average:

```text
Δ    = n − p_i
step = sign(Δ × r_i) × min(|Δ|, max(|Δ × r_i|, 1/256))
p_i' = p_i + step                        keep p_i if n is NaN

Spd = 2.0 × EyeAdaptSpeed;  Str = 0.4 × EyeAdaptStrength;  Ex = 30 × T
r_y = 1 − max(1 − 0.01 × Spd, 0) ^ Ex
r_x = 1 − max(1 − 0.01 × Spd / Str, 0) ^ Ex
```

   **At rate 0 a channel does not move**: the sign comes from `Δ × r_i`. `T` is the smoothed real frame time in seconds (0.3 while the pause counter is set; 0.0 after certain refill loops). On the first frame or after a clear, `x = y = n`. No luminance minimum or maximum. **V2**.

4. **Bloom.** Source is level 0. Targets are `(W>>2) × (H>>2)`. `kb = clamp(trunc(BloomBlurRadius), 1, 7)`. Pass 0 (vertical): `o0 = k × BloomScale × Σ_i w_i × max(c_i/k − Tb, 0)`; pass 1 (horizontal): `b = Σ_j w_j × o0_j`. `Tb = BloomThreshold + fGlobalBloomThresholdBoost` (0; map 0.25). Weights, centre first, each later value used at ±u:

| kb | weights |
|---|---|
| 1 | 0.786985755; 0.10650672 |
| 2 | 0.402619928; 0.244201481; 0.054488569 |
| 3 | 0.270682156; 0.216745213; 0.11128068; 0.036632769 |
| 4 | 0.204163671; 0.180173829; 0.123831593; 0.066282138; 0.027630489 |
| 5 | 0.163967222; 0.151360765; 0.119064637; 0.079811372; 0.045588955; 0.022190502 |
| 6 | 0.137022808; 0.129617959; 0.109719232; 0.083108582; 0.05633172; 0.03416691; 0.018543981 |
| 7 | 0.117695801; 0.112988554; 0.099966809; 0.081512466; 0.061254777; 0.042423215; 0.027077802; 0.015928362 |

5. **Tonemap** per pixel: scene `c` (point), bloom `b` (bilinear), adapted `A = (x, y)` (bilinear at the screen position).

```text
Lm = max(lum(c), 1e−5);  Ls = Lm × A.y / A.x
Reinhard (default):  Lt = Ls × (1 + Ls × W2) / (1 + Ls),   W2 = 1 / (fReinhardWhiteScale 1.1 × White)²
Filmic (bUseFilmicCurve):  x = max(Ls − 0.004, 0);  H(x) = x(6.2x + 0.5) / (x(6.2x + 1.7) + 0.06)
                           Lt = H(x)^2.2 × H(xw)^(−2.2),  xw = max(1.4 × White − 0.004, 0)
col = c × Lt / Lm + b × sat(ReceiveBloomThreshold − Lt)
L1  = lum(col);  col = L1 + Saturation × (col − L1)
col = col + tintAmount × (L1 × tintRGB − col)
col = Contrast × (Brightness × col − A.x) + A.x
col = sat(col) ^ (1/fGamma)
fade variant:  col = col + fadeAmount × (fadeRGB − col)
```

Saturation, Brightness and Contrast include the global boosts (0 by default); their neutral value is 1. The contrast pivot is `A.x`, an adapted scene luminance. With no modifier, the tint is the record colour and amount. **V2**.

6. **Output:** section 5. LDR effects after the tonemap are not covered.

## 11. Worked examples

All record values are **invented (example only)**. Constants are compiled defaults. Arithmetic is double precision with `k` as float32; render-target storage rounding is not applied. The finalizer recomputed every number from the formulas above with a new script.

Common surface: diffuse texel bytes (128,102,76); normal texel (128,128,255), alpha 64; vertex colour (255,230,204,255); identity frame; no emission, additive term or snow.

| Quantity | Value |
|---|---|
| `t0.rgb` | (0.501961, 0.400000, 0.298039) |
| `n`; `N` | (0.003922, 0.003922, 1.000000); (0.003922, 0.003922, 0.999985) |
| vertex RGB | (1.000000, 0.901961, 0.800000) |
| `t1.a` | 0.250980 |

### Example A: interior pixel (example only)

`XCLL` directional (80,90,110), toward the light (0,0,1) (XY = 0, Z = 270). DALC F0..F5 = (40,40,50), (40,40,50), (30,30,40), (50,50,60), (20,16,12), (60,70,90). Cell SunlightScale 2.0. Point light: colour (255,160,80), `FNAM` 1.5, offset 0.25, radius 256, distance 128, unit direction (0.6, 0, 0.8), dimmer 1. Fog: near (40,50,60), far (60,70,80), near 100, far 5000, power 1, max 0.9; clip length 800.

| Step | Value |
|---|---|
| directional / 255; `cb2[1]` = × 1.0 × 2.0 | (0.313725, 0.352941, 0.431373); (0.627451, 0.705882, 0.862745) |
| sat(N·Ls); sun term | 0.999985; (0.627441, 0.705871, 0.862732) |
| DALC mean | (0.156863, 0.160784, 0.197386) |
| slopes X; Y; Z | (0,0,0); (0.039216, 0.039216, 0.039216); (0.078431, 0.105882, 0.152941) |
| `Am` | (0.235447, 0.266819, 0.350478) |
| light / 255; `cb2[22]` = × 1.75 × 1 | (1, 0.627451, 0.313725); (1.750000, 1.098039, 0.549020) |
| att; sat(N·l); point term | 0.75; 0.802341; (1.053072, 0.660751, 0.330376) |
| `Σ` | (1.915960, 1.633441, 1.543586) |
| `t0 × Σ`; `L` = × vertex RGB | (0.961737, 0.653377, 0.460049); (0.961737, 0.589320, 0.368039) |
| vertex `F`; `Cf` | 0.142857; (0.168067, 0.207283, 0.246499) |
| `O`, first stage (`kM ≤ B`, so `O = L`) | (0.961737, 0.589320, 0.368039) |
| same pixel drawn blended, `T = 1`: `min(kM, B)` | (0.706963, 0.445619, 0.292230) |

Rec.709 luminance shares of the three terms of `Σ`: sun 0.415, point 0.427, ambient 0.158.

Specular (bit 9; example only: specular colour (1,1,1), strength 1, glossiness 30, view (0,0,1), fade 1):

| Step | Value |
|---|---|
| N·H sun; ^30 | 0.999985; 0.999539 |
| N·H point; ^30 | 0.949909; 0.214021 |
| `Spec` | (0.227906, 0.221317, 0.238550) |
| `Y = X1 + Spec`; `O` (first stage) | (1.189643, 0.810637, 0.606589) |
| same pixel drawn blended: `min(B2, k × M2)` | (0.869753, 0.603703, 0.462623) |

### Example B: the same surface outdoors, 12:00 and 18:00 (example only)

Climate: sunrise 5.0 to 7.0, sunset 17.0 to 19.0, so `A` 4.5, `B` 7, `C` 17, `D` 19.5. One weather (`q = 1`). `NAM0` row 4 day (230,215,190), sunset (200,120,70); row 1 day (150,170,190), sunset (170,120,110); row 12 day (130,160,200), sunset (150,110,120). DALC day F0..F5 = (90,90,100), (110,105,100), (95,95,105), (105,100,100), (60,55,45), (130,150,180); sunset (100,70,60), (60,50,60), (75,60,65), (80,60,60), (45,35,30), (80,80,120). SunlightScale day 1.6, sunset 1.9. `FNAM` day (1000, 80000, 0.5, 0.8), night (500, 40000, 0.6, 0.9). Clip length and axial depth both 5000, AO 1, no point lights, sun mask 1.

| Step | 12:00 | 18:00 |
|---|---|---|
| weights | day 1 | `M2` = 18.25; sunset 0.8, day 0.2 |
| row 4 mix / 255 | (0.901961, 0.843137, 0.745098) | (0.807843, 0.545098, 0.368627) |
| SunlightScale; `cb2[1]` | 1.6; (1.443137, 1.349020, 1.192157) | 1.84; (1.486431, 1.002980, 0.678275) |
| `Ds`, `De`; `u` | 5, 19; 0 | 5, 19; −0.857143 |
| `Ls` | (0, 0.242536, 0.970143) | (−0.957657, 0.069829, 0.279317) |
| sat(N·Ls); sun term | 0.971079; (1.401400, 1.310004, 1.157678) | 0.275831; (0.410003, 0.276653, 0.187089) |
| DALC mean | (0.385621, 0.388889, 0.411765) | (0.307190, 0.263399, 0.288889) |
| slope X | (0.039216, 0.029412, 0) | (−0.054902, −0.025490, 0) |
| slope Y | (0.019608, 0.009804, −0.009804) | (0.011765, 0.001961, −0.009804) |
| slope Z | (0.137255, 0.186275, 0.264706) | (0.082353, 0.107843, 0.194118) |
| `Am` | (0.523104, 0.575314, 0.676428) | (0.389372, 0.371148, 0.482965) |
| `Σ` | (1.924504, 1.885319, 1.834106) | (0.799375, 0.647801, 0.670054) |
| `L` | (0.966026, 0.680193, 0.437308) | (0.401255, 0.233716, 0.159762) |
| fog ramp `w`; near, far, power, max | 1; 1000, 80000, 0.5, 0.8 | 0.6; 800, 64000, 0.54, 0.84 |
| fog near RGB | (0.588235, 0.666667, 0.745098) | (0.650980, 0.509804, 0.494118) |
| fog far RGB | (0.509804, 0.627451, 0.784314) | (0.572549, 0.470588, 0.533333) |
| vertex `F` | 0.225018 | 0.231296 |
| `O` (`kM ≤ B`, so `O = L`) | = `L` | = `L` |
| composite `s`; `Fc` | 0.050633; 0.225018 | 0.066456; 0.231296 |
| `Cfc` | (0.570587, 0.657842, 0.753922) | (0.632840, 0.500734, 0.503188) |
| `(1−Fc)·O + Fc·Cfc` | (0.877045, 0.675164, 0.508552) | (0.454820, 0.295476, 0.239195) |
| **tonemap input** | **(0.730871, 0.562637, 0.423793)** | **(0.379016, 0.246230, 0.199329)** |
| sun mask 0: `L` | (0.262578, 0.207564, 0.161282) | (0.195450, 0.133904, 0.115154) |
| sun mask 0: tonemap input | (0.276571, 0.257404, 0.245530) | (0.247180, 0.182292, 0.170754) |

Tonemap of these two pixels (example only: White 1.0, neutral saturation, brightness and contrast, no tint, no bloom, steady `x = y = 0.30`, ReceiveBloomThreshold 0.5):

| Step | 12:00 | 18:00 |
|---|---|---|
| `Lm` = `Ls` | 0.588376 | 0.271066 |
| `Lt`; `Lt/Lm` | 0.550550; 0.935711 | 0.261033; 0.962988 |
| output | (0.683884, 0.526465, 0.396548) | (0.364988, 0.237117, 0.191952) |
| bytes | (174, 134, 101) | (93, 60, 49) |

### Example C: interior composite, adaptation and tonemap (example only)

Pixel of Example A, fog as there, `z` = 800, AO 0.9.

| Step | No specular | With specular |
|---|---|---|
| `r`; `s`; `Fc` | 1/4900; 0.142857; 0.142857 | same |
| `Cfc` | (0.168067, 0.207283, 0.246499) | same |
| `(1−Fc)·AO·O + Fc·Cfc` | (0.765921, 0.484230, 0.319130) | (0.941734, 0.654960, 0.503155) |
| tonemap input | (0.638267, 0.403525, 0.265942) | (0.784779, 0.545800, 0.419295) |
| same pixel with `d ≥ 0.999999`: `sat(AO × O)` | (0.865563, 0.530388, 0.331235) | — |

One adaptation step (previous pair (0.20, 0.20), current average 0.30, EyeAdaptSpeed 3.0, strength 3.5, so `Spd` 6, `Str` 1.4):

| `T` | `Ex` | `r_x` | `r_y` | new `(x, y)` |
|---|---|---|---|---|
| 1/60 | 0.5 | 0.021663 | 0.030464 | (0.203906, 0.203906): both steps take the 1/256 floor |
| 0 | 0 | 0 | 0 | (0.200000, 0.200000): no movement |
| 0.3 | 9 | 0.325797 | 0.427005 | (0.232580, 0.242701) |

Tonemap of the no-specular pixel with the `T = 1/60` pair (White 1.0, ReceiveBloomThreshold 0.5, Saturation 1.1, Brightness 1.0, Contrast 1.1, tint 0.1 × (1.0, 0.9, 0.8), bloom sample (0.010, 0.008, 0.006), `fGamma` 1):

| Step | Value |
|---|---|
| `Lm`; `y/x`; `Ls` | 0.443488; 1; 0.443488 |
| `W2`; `Lt`; `Lt/Lm` | 0.826446; 0.419841; 0.946678 |
| bloom weight | 0.080159 |
| colour + bloom; `L1` | (0.605036, 0.382650, 0.252242); 0.420504 |
| after saturation | (0.623489, 0.378864, 0.235416) |
| after tint | (0.603190, 0.378823, 0.245515) |
| after brightness and contrast (pivot 0.203906) | (0.643119, 0.396315, 0.249676) |
| saturate, power 1 | (0.643119, 0.396315, 0.249676) |
| back buffer bytes | (164, 101, 64) |

### Example D: sky pixel and byte decode (example only)

Rows 8, 7, 0 = (180,200,220), (140,170,215), (80,120,190); dome vertex colour (0, 0.5, 0.5); SkyScale 0.2; dither 0. `v = (0.359477, 0.473856, 0.661765)`, `y = 0.166667`, stored `(0.526144, 0.640523, 0.828431)`.

| Byte | Retail `/255` | An sRGB decode (not retail) |
|---|---|---|
| 64 | 0.250980 | 0.051269 |
| 128 | 0.501961 | 0.215861 |
| 192 | 0.752941 | 0.527115 |

## 12. Open items

| # | Open item |
|---|---|
| O1 | Run-time values: player INI files, console changes (`sfbr`, `ToggleFog`, `ToggleHDR`, HDR parameters), mods. |
| O2 | The SAO pass that makes `AO`; its value on sky pixels. |
| O3 | Screen-space reflection and sparkle terms; snow subsurface pass; technique 14; projected UV; landscape snow-layer keys (#963 G03). |
| O4 | Blend states, targets and content of the passes after the composite (sorted list and its sort key, second accumulator, first person, volumetrics, glare, lens flare). Tonemap input above 1 is inferred. Composite blend group (0 is inferred, #1121). |
| O5 | Depth prepass: membership (terrain, objects, alpha-tested, decals, grass), the alpha cut shader and its depth shift. |
| O6 | Sun and local shadow mask production and the shadow-slot light selection gates (see #806, #1248); mask UV constant values; whether the interior sun cascade runs. [Amended 2026-11-26: see the last amendment.] |
| O7 | Script, effect or console writers of the sun light fade or colour; meaning of the light extra byte `+0x20`; default emittance source object; emittance-list membership; emittance with a negative light. |
| O8 | Room lighting templates field by field; exterior lighting override; the lighting-template path for exterior world spaces. |
| O9 | Run-time writers of the additive term `cb1[8]`; character, soft, rim, back, anisotropic lighting; multilayer parallax; effect-shader and water surfaces; grass and tree shading. |
| O10 | Distance input of the specular, environment and decal fades. |
| O11 | World orientation of the sun parent node; the later branch that can replace the exterior sun rotation; editor names of DALC faces. |
| O12 | Sampler states; other texture creation paths; DX10 sRGB files; display gamma ramp; LDR effects after the tonemap; dynamic-resolution constants. |
| O13 | Order of the sky update against the frame-start image-space copy (the weather block can be one frame old). |
| O14 | Later writers of the emissive colour after the own-emit gate; runtime-created decals. |
| O15 | Image-space slots before HDR and any temporal filter; HDR input when they are active. |
| O16 | Parallax view constant on non-specular passes; which frame has decal byte `0x3436311` nonzero; decal per-pass blend. [Amended 2026-11-26: see the last amendment.] |
| O17 | Plugin data: image-space, weather, cell and light values (not read). |

## 13. Corrections to earlier findings

### C1. Correction to earlier finding: eye-adaptation step at rate 0 (#1059 G04 and its amendment item 3; #1272 L02)

Published in #1059 G04: "`step = sign(Δ) × min(|Δ|, max(|Δ × r_i|, 1/256))`". Published in the #1059 amendment of 2026-11-25, item 3: "The `1/256` floor applies even when the rate is 0. Each channel still moves by `min(|Δ|, 1/256)` per adapt draw." Published in #1272 L02: "With `T = 0` both adapt rates are 0, and each channel moves only by the `1/256` floor per adapt draw."

Found: the adapt pixel shaders (groups 32 and 34) take the step sign from the product `Δ × r_i`, not from `Δ`. The sign of 0 is 0. The native parameter update gives exactly `r_x = r_y = 0` for `T = 0`.

Replacement: "`step = sign(Δ × r_i) × min(|Δ|, max(|Δ × r_i|, 1/256))`. At rate 0 the channel does not move. For a nonzero `Δ × r_i` the 1/256 floor applies, bounded by `|Δ|`. With `T = 0` neither channel moves."

For a positive rate the old and the new form give the same result. **V2** (the review run and the finalizer run; groups 32 and 34 and `0x153daeb`–`0x153dbe3`).

### C2. Clarification of #1003 G03, weather flash clamp

#1003 G03 says, inside the flash paragraph, that "each adjusted channel is clamped between zero and its cap byte divided by 255". The sentence can be read to apply also when the adjustment is not positive. It states the cap of one for the adjustment earlier, and it is **ambiguous, not wrong**. In the image the cap-byte clamp runs only when the adjustment is positive and a current weather exists; otherwise only the upper limit 1 applies (`0x414e2a`, `0x414ee7`, `0xef2e80`). Clarification: "When the flash adjustment is positive and a current weather exists, each adjusted channel is limited to [0, cap byte/255]. Otherwise each channel is limited above at 1." #1080 already states this rule. **V2**.

### C3. Correction to earlier finding: fog on decals (#1273 G08)

Published (**Inferred** there): "A non-blended decal writes depth, so the composite fogs it at its own depth. A blended decal writes no depth, so it takes the fog of the depth already there."

Found: the composite reads the depth copy made after the depth prepass and before the first colour stage (#1121 G04, re-read). Replacement: "The composite reads the depth copy made before the colour stage. It does not see the colour-stage depth write of a decal. Every decal pixel takes the fog of the depth in that copy. Whether the depth prepass draws decals is unverified." Binding **V2**; prepass membership **U**.

### Notes that are not errors

- #1258 G01 left the value stored when helper `0x300310` is true untraced: it is 0.0.
- #1059 answer row 3 says "Sky uses `k × SkyScale`". The term is additive (section 2.4; #1080 G09 states this).

## 14. Verification ledger

Runs: **A** author, **R** reviewer, **S** second check, **Z** finalizer. A published finding number stands for that finding's own author and reviewer.

| ID | Claim | Mark | Runs |
|---|---|---|---|
| L01 | Light, DALC, fog and vertex colour bytes become byte/255 without gamma | V2 | #1003, #1080, #1258, R, S |
| L02 | Traced DDS path: file format view, force-sRGB 0 | V2 | #1258, A, R |
| L03 | Albedo is used as stored on all paths | I | — |
| L04 | NAM0 mix, day-part weights, weather weights, upper limit 1 | V2 | #1003, #1080, S, Z |
| L05 | Weather transition fraction and duration | V2 | #1003, #1080 |
| L06 | Flash clamp rule | V2 | #1080, R, S |
| L07 | SunlightScale source, default form, modes, cell path, modifiers, override | V2 | #1059, #1272, A, S |
| L08 | SkyScale source, shading reader, additive use | V2 | #1059, #1080, S, R |
| L09 | Sky types 1 and 6 get `y = 0`; type 7 record does not read `y` | V2 | R, S, Z |
| L10 | Sun upload product and negated direction | V2 | #1003, R, S |
| L11 | Sun fade 1.0 and no other writer found | V2 | #1003, A, S |
| L12 | `XCLL` directional fade not applied (scoped search) | V2 | A, R, S |
| L13 | Exterior sun path formula | V2 | #1003, #1080 |
| L14 | Interior sun colour and angles | V2 | #1258, #1268 |
| L15 | Room lighting templates replace colours (outline) | V2 | A, S |
| L16 | Room template blend timing and fallbacks | V1 | S |
| L17 | Exterior lighting override replaces weather colours | V1 | S |
| L18 | DALC face order, cache, upload | V2 | #1003, #1258, #1268 |
| L19 | `LIGH` colour ±1/255 | V2 | #1258, R, S |
| L20 | Fade sum, largest-float case, zero case | V2 | #1073, R, S |
| L21 | The reference fade extra is `XLIG` | I | — |
| L22 | Radius rule and model-space division | V2 | #1258, #1073, R, S |
| L23 | Distance dimmer and begin/end source | V2 | #1073 |
| L24 | Flicker and pulse | V2 | #1073, #1245 |
| L25 | Light admission, list order, cut at 7 | V2 | #1073 |
| L26 | Light emittance product and default (1,1,1) | V2 | A, R, S |
| L27 | Region emittance: row 9, factor `q` on lights, full weight on the region colour | V2 | S, Z |
| L28 | Emittance-list membership rule | V1 | A |
| L29 | Emissive pointer replacement; own-emit gate | V2 | A, R, S |
| L30 | Material values loaded without scale; `cb1[4]` | V2 | #1258, A, S |
| L31 | Vertex colour format, pass-through, white without bit 0 | V2 | #948, A, R, S, Z |
| L32 | Pixel inputs bind by semantic | V2 | R, Z |
| L33 | Tangent frame assembly, raw `POSITION.w` | V2 | #963, R, Z |
| L34 | Skinned frame: rotate and normalise each vector | V2 | R, Z |
| L35 | Model-space normal decode and mask | V2 | #1258, R, Z |
| L36 | Plain light sum, attenuation, no clamp, alpha | V2 | #1258, A, R, Z |
| L37 | Specular formula | V2 | #1258, R, Z |
| L38 | Shadow mask coordinates and channel constant | V2 | #1258, R, Z |
| L39 | One-stage and two-stage tail | V2 | #1258, R, Z |
| L40 | Ambient specular | V2 | #1258, R, Z |
| L41 | Vertex fog formula and constants | V2 | #812, R, Z |
| L42 | `k`, `B`, `B2` defaults | V2 | #1121, #1258, S |
| L43 | Technique predicates and key bits | V2 | #1273 |
| L44 | Blended selector and blend modes | V2 | #1273, #1077 |
| L45 | Alpha test, screen door, hair decal | V2 | #1273, R, S |
| L46 | Decal depth write and colour write masks | V2 | #1273, R, Z |
| L47 | Decal bias modes, bytes and gating | V2 | #1273, R, S, Z |
| L48 | Object snow rule with TreeAnim condition | V2 | #1273, S, Z |
| L49 | Snow colour, stages, target 3, rim | V2 | A, R, S, Z |
| L50 | Environment and glow | V2 | #1273 |
| L51 | Parallax, eye, face, hair | V2 | #1273 |
| L52 | Landscape technique 8 | V2 | #1273, #946, #963 |
| L53 | Technique 19 blend, noise, normal, alpha | V2 | #979, #963, Z |
| L54 | Land `POSITION.w` consequence on slopes | I | #963 |
| L55 | Composite arithmetic, records 49, 51, 53 | V2 | #1077, A, R, S, Z |
| L56 | Composite depth is the post-prepass copy | V2 | #1121, R, Z |
| L57 | Composite record selection and defaults | V2 | #1077, S |
| L58 | Interior fog colours, fallback, distances, property install | V2 | A, R, S, Z |
| L59 | Exterior fog ramp and colours | V2 | #812, #1080 |
| L60 | Camera-distance override acts on both paths, skipped by default | V2 | #812, R, Z |
| L61 | Clear colour `k × fog far` | V2 | #1080, S |
| L62 | Sky pixels take the no-fog composite branch | I | #1077, #1080, #1121 |
| L63 | Later draws add to `kMAIN`; input above 1 | I | #1272 |
| L64 | Target formats, swap chain, null view | V2 | #1059, A, R, S |
| L65 | Output id 0 is the gameplay path | I | A, R, S |
| L66 | Tonemap writes back buffer or copy 41 | V2 | A, S |
| L67 | Gamma exponent, slider, reset | V2 | A, R, S |
| L68 | No gamma conversion found in group 6 (scan scope) | V2 | #1258, R, S |
| L69 | Image-space block fields and defaults | V2 | #1059 |
| L70 | Downsample and luminance chain, sizes and filters | V2 | #1059, #1272 |
| L71 | Adapt rates and meaning of `T` | V2 | #1059, #1272, Z |
| L72 | Adapt step sign from `Δ × r` | V2 | R, Z |
| L73 | First-frame adaptation | V2 | #1272 |
| L74 | Bloom | V2 | #1059, #1272 |
| L75 | Tonemap steps | V2 | #1059, R |

## 15. Second checks by the finalizer

The finalizer wrote its own reader that asserts both hashes.

| Item | What was re-read | Result |
|---|---|---|
| Adapt step sign | PS groups 32 and 34; `0x153daeb`–`0x153dbe3` and the constant setter | Confirmed: sign of `Δ × r`; `r_x = cb2[2].w`, `r_y = cb2[2].z`; both 0 at `T = 0` |
| Region emittance weight | `0x416760`, `0x416a20`, `0x2ba15e`–`0x2ba4de` | Confirmed: factor `q` on the light path; full weight on the region colour |
| Decal bias by byte | `0x1537410`, `0x151fd60`, `0x151ff00`, `0x102b680`, rasterizer mode table, viewport store | Confirmed. The "accumulator byte `+0x51`" and "byte `0x3436311`" named by the two earlier runs are the same byte. Byte `0x20d683a` gates only the two opaque groups |
| Decal depth and write masks | depth-state table `0x102b120`, write-mask table `0x102abd0`, mode stores `0x151f17c`–`0x151f243`, per-draw overrides `0x1549657`, `0x154a712` | Confirmed: non-blended write depth; blended test only and write target 0 |
| Object snow rule | `0x151aa2c`–`0x151aaf0` | Confirmed, including the TreeAnim condition on case (a) |
| Composite depth | `0x1539f65`, `0x15399b5`–`0x15399df`, call order, `0x151f28f`, composite slot bind `0x1542a1a` | Confirmed |
| Pixel inputs, tangent frame | records PS `0x1`, `0x5`, `0x201`; VS `0x0`, `0x3`, `0x201` | Confirmed |
| Two-stage formula | PS `0x201`, `0x20001` | Confirmed |
| Shadow mask | PS `0x4001`, `0x6201` | Confirmed |
| Camera-distance fog gate | `0x413cf2`–`0x413ef9` | Confirmed: weather and cell branches both reach it |
| Moon-and-star mask | sky PS records 1 to 8; type switch `0x155358c`; record map `0x15522a8`; `0x1552964` | Confirmed |
| Sky before decals | first-stage draw order `0x151f160`–`0x151f248` | The sky pass window draws before both decal calls |
| Also re-read | composite record 53; records `0x200001`, `0x200201`, `0x13000001`; interior fog distance rules `0x413d50` | Agree with the text above |

## Interpretation and alternatives

A renderer that decodes colours as sRGB, uses a flat ambient colour, clamps light colours, uses a constant sun scale, applies average-luminance auto exposure, reads fog depth from the colour-stage depth, or encodes the output to sRGB differs from retail in those steps. This file does not say which step explains any observed picture. The steady-state exposure ratio `A.y/A.x` is 1 when both adapted values reach the same target, so the absolute scale of the scene colour matters.

## Negative results and limitations

- Static only. No runtime trace, no frame capture, no visual claim.
- "No gamma" statements cover the traced producers, loaders and shader scans.
- Caller and reader searches use direct references and data pointers. Indirect and aliased access can be missed.
- Rows marked V2 on published finding numbers rest on those runs; the finalizer did not re-read all of them.
- The worked examples exercise no dimmer, flicker, bloom filter, screen-door or alpha-test path.

## Reviewer and outcome

Author draft, one independent review and one second binary check by separate Sonnet 5.5 runs, merged by a further Sonnet 5.5 finalizer run (Sol unavailable). Outcome of the review: not implementable as first written; the corrections are applied here. The merged text had no separate review. This is not match evidence for any function and does not decide transfer eligibility. Transfer status: UNREVIEWED.

## Amendment (2026-11-25, from SPEC-2): draws after the composite, tonemap destination and HDR input

**Scope.** The statements named below. Addresses are RVAs. Static only. No visual result is claimed. Source: `spec-hdr-output-retail-facts.md` (SPEC-2), sections 4, 5, 8 and 14. SPEC-2 is `Transfer status: UNREVIEWED` and its merged wording had no separate review. Evidence: the SPEC-2 author, reviewer, second binary check and finalizer runs (all `claude-sonnet-5-5`); the marks below are SPEC-2 marks.

### Correction to earlier finding

1. **Section 1 row 15 and section 8.1 (C4: addition, not a wrong statement).** "Second stage | sorted blended draws, glare, second accumulator, first person" and "composite → second stage (sorted blended, sun glare) → second accumulator → first-person view → (volumetrics if enabled) → post-processing" are incomplete lists. The order is: composite → geometry group 10 → water colour passes (pass ids `0x5c000071` to `0x5c006071`, with an optional water resolve) → geometry groups 11, 12 and 7 → sorted blended list → sun glare → second accumulator → first-person view → compute SAO pass (off by default) → volumetric compute → lens flare sprites → indirect light, image-based lens flare and the additive flare and volumetric composite → post-processing. When the water state is 2, the sorted list runs before geometry group 10 instead. The contents of the numbered geometry groups are unverified. **V2** for the order.
2. **Section 5 (C5: clarification, not a correction).** "The tonemap writes the back buffer when no later effect runs, else an 8-bit temporary copy (target 41)" is correct. With compiled `bUseTAA` 1 a later pass **does** run in the default frame, so the default tonemap destination is target 41. Temporal anti-aliasing then writes the final output, or target 42 when a later slot or an upsample follows. In section 1 row 19, the back buffer receives the result after that pass. The worked examples of section 11 give back-buffer bytes only if that pass is an identity step. **V2**.
3. **Section 10 and open item O15 (C6: resolution of an open item).** "The scene input is `kMAIN` when no earlier image-space slot is active (earlier slots are not covered)." The earlier slots are 0 (world map), 1 (refraction) and 2 (FXAA). With defaults only refraction can be active in ordinary play, so the input is normally `kMAIN`; with the Low preset it is the FXAA output. Temporal anti-aliasing runs **after** the tonemap. Slots 3 to 7 (depth of field and blurs) run after the HDR effect while the manager flag `usesLDR` is 1, which is its default. **V2**.

### Open items that SPEC-2 narrows (not corrections)

4. **Section 8.4 and O4.** The sun glare, the lens flare sprites, the flare and volumetric composite, some water passes and some sorted passes have additive blend stores (**V2** for the stores). The render target of the lens flare sprites is open. That values above 1 reach the tonemap stays **I**.
5. **Section 9.3 and O16.** Byte `0x3436311` is stored at `0x65803b` (function `0x657c90`): 1 when the pointer at `+0xc0` of the object at `[0x32303b8]` is nonzero (community name: loaded interior cell), or when the current world space flag byte `+0xa0` has bit `0x40` or bit `0x20`; else 0. **V2** for the writer; the names are **I**.

**Confidence: high** for items 1 to 3. The original text above stays unchanged. This amendment supersedes it for the statements named here only.

## Amendment (2026-11-26, UNREVIEWED): open item O6, the sun shadow caster gate

**Scope.** Open item O6, the part "whether the interior sun cascade runs". It also answers the part of O16 about the decal byte. Addresses are RVAs. Static only. No game run, no frame capture and no visual claim. The original text above stays unchanged, except for the markers on O6 and O16.

**Evidence.** One fresh Sonnet 5.5 run (`claude-sonnet-5-5`) on the pinned image. The measured executable SHA-256 equals the pin. Its task stated the claim to check. It saved its binary results before it read the requester's note. No independent review covered this text. The marks follow section 0. The writer rule had two earlier runs and this run read it again (**V2**). The new gate statements have one run (**V1**). Names marked [PDB] are `CRASHLOGGER_PDB(59818@2026.10.24)`.

### The byte

1. Byte `0x3436311` is field `+0x51` of the global block at `0x34362c0` (accessor `0x1537410`). Function `0x657c90` stores it at `0x65803b`. `Main::Draw` [PDB] calls that function (`0x656f33`) before it builds the shadow caster list (`0x657024`). The value is 1 for a loaded interior cell. It is also 1 when flag byte `+0xa0` of the current world space has bit `0x40` or bit `0x20`. Else it is 0. **V2**; the cell and world-space field names are **I**.
2. The image value is 0. No other store was found. Computed-address stores are not excluded. **V1**.
3. The byte has 13 read sites. Nine direct compares: `0x15377fd`, `0x153795d`, `0x1537ac9`, `0x1538051`, `0x15388b5`, `0x15389fa`, `0x153917c`, `0x153937e`, `0x1539a9d`. Four reads through the accessor: `0x6571ab` (volumetric), `0x151fdaf`, `0x151fe1f` and `0x151ff5e` (decals). **V1**.

### Effect on the sun shadow

| Step | Byte 0 | Byte nonzero | Mark |
|---|---|---|---|
| Caster list build, `0x1537fd0` (`Main::QueueListAccumulationJobs` [PDB]) | The sun shadow light (scene `+0x210`, class `BSShadowDirectionalLight`) gets its camera update (virtual slot `0x10`), the optional focus setup, caster array entries from entry 0 (one for each of its shadow maps), a caster number, a mask bit and the directional culling | Only virtual slot `0x0C` of that light (`ReturnShadowmaps` [PDB]), when the light exists. The light gets no caster entry | V1 |
| Shadow selector, `0x15389b0` | Calls the sun accumulate virtual (slot `0x09`). The caster count starts at 1 | No sun call. The caster count starts at 0 | V1 |
| Local shadow lights (same selector, limit of 4 counted casters) | At most 3 beside the sun | At most 4, from entry 0 | V1 |
| Shadow mask pass, `0x1539a70` (`RenderShadowmasks` [PDB]) | The first component of its clear colour is 1.0. The other three are 0 | The first component is 0.0. The other three are 0 | V1 |

- The mask pass runs when byte `0x20d6811` is nonzero (image value 1) or the caster count is above 0.
- The caster render loop (`0x1538430`) and the mask loop (`0x1539b10`) visit only caster array entries. With an empty array they draw nothing. Whether the clear then executes is **U**. The link from the clear colour to the mask sample `t14.x` is **U**.
- Function `0x1538860` (progress name `ResetCalculatedShadowCasterLights`) contains the same gate. No direct call, jump, address load or data pointer to it was found. Only its unwind data names it. So use `0x1537fd0` as the per-frame site. **V1**; that the function is unused is **I**.
- The caster entry setter `0x150fe80` has four direct callers: the sun site in `0x1537fd0`, the sun site in `0x1538860`, the local-light loop of the selector, and `UI3DSceneManager::Render` [PDB] on a different scene node. **V1**. No other path that adds the sun light was found. **I**.

### Answer to the interior part of O6

| Case | Static result | Mark |
|---|---|---|
| Loaded interior | The interior sun cascade does **not** run in a normal frame. The sun shadow light is not updated, accumulated, culled, put in the caster array, rendered or resolved into the mask. Local shadow lights continue | I (from the V1 gates) |
| World space with flag `0x40` or `0x20` | The same byte gives the same result: no sun shadow map and no directional mask pass | I (from the V1 gates) |
| Which world spaces carry those flags | Not read. This needs plugin data | U |
| Other consumers of the mask in those frames (water, grass, LOD, effect shaders) | Not checked | U |

**Near Lighting.** The section 2.3 statement "Bit 13 is never set in interiors" stays true. In a flagged exterior world space, byte `0x20d68f4` is 0. The light selector `0x1569550` keeps the sun-mask flag only when the object at scene `+0x210` is among the caster entries that it reads for the geometry. The sun is not a caster there, so bit 13 is not set. Then `ms = 1`: the sun term is unshadowed, not black. **I** (from the code reading of one run).

### Two different bytes

| Byte | Rule | Controls |
|---|---|---|
| `0x20d68f4` | Set from the interior cell only (one store, `0x14ebf00`). No world-space flag | Active shadow distance, key bit 13 (`0x151a64f`), water pass key bit |
| `0x3436311` | Loaded interior, or world space flag `0x40` or `0x20` | Sun shadow caster, mask clear colour, decal raster and depth state (section 9.3), volumetric disable (SPEC-2 section 8.4), camera projection updates |

**O16.** From rule 1, the decal byte is nonzero in a loaded interior and in a flagged world space. **I** for the game frames. The other parts of O16 stay open.

### Name of the byte

The reconstruction unit `bsshader/ShadowSceneNode_R5B2CasterReset` names this byte `lightsFrozen`. That name is a guess, and the evidence does not support it. No read or store shows a freeze. The byte is a location rule, and the writer computes it again in each world draw. A description that follows the evidence is "no sun shadow caster: loaded interior, or world space flag `0x40` or `0x20`". A possible name is `isInteriorOrFlaggedWorld` (**GUESS**). This amendment changes no reconstruction file.

**Confidence: high** for the writer and the gates. **Medium** for "no other path adds the sun". A found writer or caller, or a runtime watch that shows a sun cascade draw in a loaded interior, would change this.

## Amendment (2026-11-26, from SPEC-4): frame clear colour and sky pixel outputs

Transfer status: UNREVIEWED. Static only. These items come from the SPEC-4 runs (sky objects and weather; Sonnet 5.5 author, independent review, blind second binary check and finalizer, `claude-sonnet-5-5`). The original text above stays unchanged. This amendment supersedes it for the statements named here only.

### Correction to earlier finding: the frame clear colour (section 8.1 and ledger L61)

Published in section 8.1: "The frame clear colour is `k × fog far colour` (**V2**)." Ledger L61: "Clear colour `k × fog far`".

Corrected: the clear colour is the fog far colour (`NAM0` row 12 in the sky object; indoors, the cell fog far colour in the same sky field) × the **literal 0.83332998** (constant at `0x1869de8`). It does not use `k`. All three sky update paths that write the clear-colour globals use the literal (`0x412253`, `0x412699`, `0x4127a9`); the frame start reads them (`0x656d8b`). #1080 G01 already states the literal. With the file value of `k` the difference is about 3.3 × 10⁻⁶ of the colour value. After the console command `sfbr`, `k` changes and the clear colour does not. **V2**.

### Addition to section 2.4: sky pixel outputs

Besides the colour in the table of section 2.4, every sky pixel shader writes output 1 = screen motion `(current − previous) × (−0.5, +0.5)` and output 2 = the constant `(0.5, 0.5, 0, 0)`. **V2**.
