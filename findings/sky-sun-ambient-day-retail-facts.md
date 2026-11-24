Transfer status: UNREVIEWED

# Finding: sky, sun, moon and ambient colour by game hour, and the sky objects and sky shader, in Skyrim Special Edition

Status: OBSERVED where verified. INFERRED and UNVERIFIED items are marked. Static only. No game launch, no capture, no visual claim.
Author: a Sonnet 5.5 research run (`claude-sonnet-5-5`). Not a reviewer.
Independent reviewer: a separate fresh-context Sonnet 5.5 run (`claude-sonnet-5-5`). Sol was unavailable on a usage limit. See "Independent review" below.
Human operator: Taylor.
Date: 2026-11-24 CST. The author run took 03:40 to about 05:02. The independent review took 05:15 to about 05:46. The corrections were applied afterwards.
Target build and SHA-256: retail `1.7.104.0`, Steam build 24914197, `sse-steam-1-7-104`, `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f`. The measured executable hash equals the pin in [builds/target.json](../builds/target.json). The local reader asserts that equality on every read.
Main function RVAs (image base `0x140000000`): `0x411ec0` (Sky::Update), `0x412810`/`0x41282c` (weather transition), `0x412df0` (colour update), `0x413a30`/`0x413a80` (fog scalars), `0x414cf0` (colour mixer), `0x416760` (day-part weights), `0x419ab0`/`0x419d00`/`0x419d50`/`0x419bb0` (schedule endpoints A, B, C, D), `0x41bd90` (Sun::Update), `0x40e0f0` (Moon::Update), `0x40d370` (moon phase), `0x41a4b0` (Stars::Update), `0x40c220` (Clouds::Update), `0x414780` (aurora fade), `0x40b950` (Atmosphere::Update), `0x15520e0`–`0x1553550` (BSSkyShader), `0x1552280` (technique setup), `0x1552190` (technique restore), `0x15525b0` (geometry setup), `0x1553550` (pass creation), `0x151ef40` and `0x151f540` (render stage A and B), `0x1521190` (batch draw), `0x1539f10` (main colour stage), `0x100a228` (render state flush), `0x102abd0`/`0x102b120`/`0x102b6c0` (state table creation).
Source exposure: pinned executable. Shipped shader member `shadersfx/shaders011.fxp` (SHA-256 `72cfc73eb0938d5949f0b3a8683722a33b671a34b41b750ba138de8d154c5fbc`) from `Skyrim - Shaders.bsa`, decoded offscreen with the existing Wine and `fxc /dumpbin` set up. Four shipped sky meshes, read only for block types and the sky-object-type field (`Meshes\Sky\Atmosphere.nif`, `Clouds.nif`, `Stars.nif`, `SkyrimAurora.nif`, from `Skyrim - Meshes1.bsa`). Committed CrashLogger PDB names. Published findings #812, #1003, #1073 and #1077. No plugin record value is quoted. The climate numbers in the one example in G02 are invented and marked "example only". No sibling or downstream source. No decompiler text or disassembly appears below. Transfer needs review under `docs/clean-room.md`.
Name provenance: function labels are GUESS unless a name is given with `CRASHLOGGER_PDB(59818@2026.10.24)`. The PDB label applies only to names taken from the generated files. That label covers `Sky`, `Sun`, `Moon`, `Clouds`, `Stars`, `Atmosphere`, `NiLight`, `NiDirectionalLight` field names, the sky function names (`Sky::Update`, `Sun::Update`, `Moon::Update` slot, `Clouds::Update`, `Stars::Update`, `Atmosphere::Update`, `BSSkyShader::ctor`, `BSSkyShaderProperty::GetRenderPasses`, `BSShaderAccumulator::*`) and `Sky__Mode`. Several PDB function names are wrong or only chunk labels. For example, the PDB name `Sky::UpdateClouds` at `0x414780` labels the aurora update (G08). This finding labels such functions by their behaviour (GUESS). Setting names, technique name strings (`BSSkySunOcclude` and the like), `BSSM_SKY*` strings and the texture path strings come from the pinned image. Colour row names (`SkyUpper`, `FogNear`, ...) come from the `Sky` PDB field names. The names `skyScale`, `sunlightScale` for HDR floats are community labels, not verified here.

**Verified** means re-read at the cited static source in this run. **Inferred** means a deduction with stated assumptions. **Unverified** means not read or not resolvable statically. `cbN[i]` is constant buffer N, float4 element i. `h` is the game hour in [0,24). `NAM0 row n` is zero-based. The example in G02 uses invented numbers, not retail data.

## Answer

| Question | Answer |
|---|---|
| 1. How do the `WTHR` colour sets, DALC and sun colour change with the game hour? | **Verified, high.** One day-part schedule drives all 17 `NAM0` rows, every cloud-layer colour and alpha, the DALC sets, the image-space forms and the volumetric-lighting forms. Endpoints: `A` = max(0, sunrise begin − `fDaytimeColorExtension`), `B` = sunrise end, `C` = sunset begin, `D` = min(sunset end + extension, 23.99). Slot order is sunrise 0, day 1, sunset 2, night 3. Night for `h ≤ A` and `h ≥ D`. Each of the two windows has two linear halves that meet on the slot colour at the window midpoint. Day for `B ≤ h ≤ C`. No smoothstep. Only rows 3 and 4 get the lightning flash. **Different rules** (G05): fog scalars (one linear ramp over each whole window), star alpha, sun disc and glare alpha, sun path, aurora (fixed hours), moon (angle), cloud scroll (speed bytes). |
| 2. Sun light direction, moon, night fade? | **Verified, high.** The sun path coordinate `u` runs +1 to −1 across [dawn start, dusk end] and −1 to +1 across the night, where dawn start = sunrise midpoint − half `fSunAlphaTransTime` and dusk end = sunset midpoint + half of it (raw climate bytes, no extension). Sun disc node translation = (`u`·`fSunXExtreme`, `fSunYExtreme`, `fSunXExtreme` − |X|). Light direction vector = (−X·kd, −`fSunYExtreme`·kd, `fSunZExtreme`) normalised, kd = `fSunDirXExtreme`/`fSunXExtreme`. The same light keeps moving at night. **No sun/moon light switch found.** No night fade of the light in `Sun::Update`; night dimming comes from the night slot of `NAM0` rows 4 and 3 and from the image-space form mix. Disc and glare alpha fade over the `fSunAlphaTransTime` window only. Moons are separate quads that do not light the scene (G06, G07). |
| 3. Sky objects, order, techniques, blend? | **Verified, high for shader arithmetic and stage order; medium for state tables.** The `Sky` shader has nine techniques (keys 0–8). The dome, the moon-and-star mask, the stars, the sun and moon discs and the clouds draw in **render stage A**, in that order, after the Lighting and other ranges and before the SAO and fog composite. Sun glare draws last in **stage B**, after the composite. Every sky VS writes clip z = clip w, so sky pixels land at depth 1.0 (clouds and masks are biased by a few depth units). The sky shaders contain no fog math. Cloud scroll and colour come from per-layer weather arrays (speed bytes, colours, alphas, layer mask, layer count). Details in G08–G11. |

| Item | Evidence record |
|---|---|
| Intended recipient | Skyrim Research department lead for boundary review under [docs/clean-room.md](../docs/clean-room.md). Proposed use: Mudcrab #653 and #903. Maintainer transfer decision pending. |
| Reproduction | Static only. Dump each cited address range of the pinned image with a disassembler and read the stated instructions. Read the setting objects and constants at the cited addresses. Decode group 4 of the shader member offline with the `fxc /dumpbin` tool. Parse the four shipped sky meshes for block types and the sky object type field only. Evaluate the G02 example from the stated formulas. |

## Question and method

Item 19 asks how Skyrim changes sun, ambient and sky colour with the game hour, how it derives the sun direction, and which sky objects draw with which shaders and states. I started from the published schedule (#812, #1003) and re-read it at the code. I then decoded every consumer of the colour rows I could find, the sun, moon, star, cloud and aurora updates, the nine sky shader records, the render state tables and the two render stages. I read the climate-dependent constants from the image. I used no plugin values.

## Observations

### G01. Per-frame order in `Sky::Update` and the Sky modes

**Verified.** `Sky::Update` (`0x411ec0`) stores the game hour at `Sky+0x1b0` from the calendar call at `0x411f67`. Sky mode is `Sky+0x1bc` (0 none, 1 interior, 2 sky dome only, 3 full; `Sky__Mode`). For mode 1 with the UI-hidden bit clear, it runs the colour update `0x412df0` (call `0x4121ff`), the fog scalar update `0x413a30` (`0x412207`), then `Atmosphere` (`+0x70`) and `Sun` (`+0x80`) only, and returns. Otherwise the order is: climate update `0x414fe0` (`0x41229e`; creates or deletes the moons), weather transition `0x412810` (`0x4122a6`), colour update `0x412df0` (`0x4122ae`), fog `0x413a30` (`0x4122b6`), wind (`Sky+0x18c` = weather `DATA+0x664`/255 mixed by `q`; `Sky+0x190` from `+0x675/+0x676`), `0x414180` (`0x412491`, not read), aurora fade `0x414780` (`0x412499`), then the objects' virtual `Update` (vtable slot 3) in this order: Atmosphere (`+0x70`), Stars (`+0x78`), Clouds (`+0x88`), Sun (`+0x80`), the aurora root update (`0x140ee0930` at `0x412520`), reference effects `0x4182d0` (`0x412528`), the moon phase check `0x40d370` (`0x412565`), Masser (`+0x90`) and Secunda (`+0x98`) updates (`0x4125fa`, `0x412613`), precipitation (`+0xa0`, `0x412626`), then the lightning flash decay (`0x41262b–0x412671`). The flash value at `Sky+0x1c8` falls linearly from 1 to 0 over `fWeatherFlashDuration` × 1000 ms. The routine also stores `Sky+0x138` (`NAM0` row 12, far fog colour) × 0.83333 into globals `0x1433d3e70..78` (`0x4126b9–0x4126d1`). The frame start reads those globals into the clear colour call at `0x656d8b–0x656daa`. The scale constant is the literal `0x141869de8` (0.83332998), not the `k` of #1003 G05.

**Confidence: high.** `0x414180` reads a handle list at `Sky+0x1c0` and weather bytes near `+0x66e`. The independent review classed it as the weather sound update (GUESS). It reads no colour and no hour window. **Unverified:** the `0x41ca50` call at `0x1539f97`. A runtime call trace would close it.

### G02. The colour day-part schedule

**Verified.** `0x416773–0x416a06` computes four weights and two slot indices from the hour. The endpoints come from helpers: `A` = `0x419ab0` (climate byte `+0x78` × 1/6 hour, minus `fDaytimeColorExtension`, floored at 0, cached at `0x1431e0da4`), `B` = `0x1431e0d98` (byte `+0x79`/6), `C` = `0x1431e0d9c` (byte `+0x7a`/6), `D` = `0x419bb0` (byte `+0x7b`/6 plus the extension, min with 23.99 at `0x141869df4`, cached `0x1431e0da8`). The caches refresh when flags `0x200/0x400/0x800/0x1000/0x2000/0x4000` in `Sky+0x1dc` are set. The slot index written is sunrise 0, day 1, sunset 2, night 3.

| Hour `h` | Slot pair (first index, second index) and weight `t` of the first |
|---|---|
| `h ≤ A` or `h ≥ D` | night, night, 1 |
| `A < h < M1`, `M1 = (A+B)/2` | sunrise (0) with night (3); `t = (h−A)/(M1−A)` |
| `M1 ≤ h < B` | sunrise (0) with day (1); `t = 1 − (h−M1)/(M1−A)` |
| `B ≤ h ≤ C` | day, day, 1 |
| `C < h < M2`, `M2 = (C+D)/2` | sunset (2) with day (1); `t = (h−C)/(M2−C)` |
| `M2 ≤ h < D` | sunset (2) with night (3); `t = 1 − (h−M2)/(M2−C)` |

The comparisons at the edges are: `h = A` gives night, `h = B` and `h = C` give day, `h = D` gives night. With `q` = `Sky+0x1b8` (1 when there is no previous weather), the four weights are `q·t`, `q·(1−t)`, `(1−q)·t`, `(1−q)·(1−t)`. They apply to (current weather slot first, current slot second, previous weather slot first, previous slot second), at `0x4169ca–0x416a01`. The mixer `0x414cf0` multiplies each packed RGB byte by its weight, sums, and multiplies by 1/255 (`0x141b5bdc8`). The path is linear in the hour. I found no smoothstep, no gamma and no extra curve. The transition fraction `q` is `(h − lastWeatherUpdate)` (+24 if the stored hour is later) divided by `fWeatherTransMin + (DATA byte +0x667 / 255) × (fWeatherTransMax − fWeatherTransMin)` of the incoming weather (`0x412cb0–0x412d04`). It is 1 with no previous weather and 0 with no current weather. A flag (`0x8`) applies `q = q0 + (q − q0)(1 + fWeatherTransAccel)` with `q0` at `Sky+0x1d8`. When `q` exceeds 1 the previous weather is cleared and `q` is set to 1 (`0x412d58–0x412d7f`). This agrees with #812 G02 and #1003 G02.

Example only, invented (not retail data). Take a climate with sunrise 6.0 to 9.0 and sunset 18.0 to 21.0 hours and the default extension: `A, B, C, D` = 5.5, 9, 18, 21.5. At `h` = 7 the pair is sunrise/night with `t` = 0.86. At `h` = 8 it is sunrise/day with `t` = 0.57. At `h` = 19 it is sunset/day with `t` = 0.57. These numbers are an example only. They are invented and are not retail data.

**Confidence: high.** **Unverified:** inputs of an unusual climate (unordered endpoints, `B > C`), exact-equality behaviour of floats, and the interrupted-transition paths.

### G03. Every `NAM0` row: role, destination, consumer, schedule

**Verified.** The row loop at `0x4133e0–0x413491` runs for rows 0 to 16. For each row it reads the four packed colours at weather `+0x698 + 16×row + 4×slot`, takes the two slot indices and four weights from G02, and calls `0x414cf0`. The result goes to `Sky + 0xa8 + 12×row`. All rows use the same weights. Row names are the `Sky` PDB field names.

| Row | Name (PDB field) | `Sky` offset | Consumer found in this run | Special rule |
|---|---|---|---|---|
| 0 | SkyUpper | `+0xa8` | `Atmosphere::Update` copies to global `0x143436630` (dome colour 3); moon shadow quad colour (G07) | none |
| 1 | FogNear | `+0xb4` | `Atmosphere::Update` copies to fog property `+0x38` (#812) | none |
| 2 | Unknown | `+0xc0` | none found | none |
| 3 | Ambient | `+0xcc` | `Sun::Update` → `NiLight.ambient` (`light+0x110`) of sun light | flash × `fWeatherFlashAmbient` |
| 4 | Sunlight | `+0xd8` | `Sun::Update` → `NiLight.diffuse` (`light+0x11c`); copied to `Sky+0x180` and to the third colour slot `light+0x128` | flash × `fWeatherFlashDirectional` |
| 5 | Sun | `+0xe4` | sun disc property colour (G06) | none |
| 6 | Stars | `+0xf0` | star property colours (G08) | none |
| 7 | SkyLower | `+0xfc` | global `0x143436620` (dome colour 2) | none |
| 8 | Horizon | `+0x108` | global `0x143436610` (dome colour 1) | none |
| 9 | EffectLighting | `+0x114` | sun light `effectColor` (`light+0x14c`) | none |
| 10 | CloudLODDiffuse | `+0x120` | cloud light diffuse (`cloudLight+0x11c`) | none |
| 11 | CloudLODAmbient | `+0x12c` | cloud light ambient (`cloudLight+0x110`) | none |
| 12 | FogFar | `+0x138` | fog property `+0x44` (#812); clear-colour global (G01) | none |
| 13 | SkyStatics | `+0x144` | `0x2d94b0` takes the address `GetSky()+0x144` (`0x2d9673`) and passes it to `0x14ebfd0` and `0x14ed030`. Those store the pointer in a shader property of the object's geometry (`+0xf0`, `SetFlag` 0x16). The path runs only when `0x2f62a0` returns true. The reading side of that pointer was not traced. | none |
| 14 | WaterMultiplier | `+0x150` | `TESWaterSystem::Update` copies to global `0x143435bd8` with w = 1 (`0x52a802–0x52a832`) | none |
| 15 | SunGlare | `+0x15c` | sun glare colour × `fSunGlareMultiplier`; also copied to global `0x143435c90` | none |
| 16 | MoonGlare | `+0x168` | moon disc property colour (G07) | none |

**Verified.** Flash. When the previous weather is null, the call for row 4 passes `fWeatherFlashDirectional` × `Sky+0x1c8` and for row 3 passes `fWeatherFlashAmbient` × `Sky+0x1c8`. The first cloud layer passes `Sky+0x1c8` in the same case. A positive value is capped at 1, added to every channel, then each channel is clamped to [0, cap byte/255] with the cap bytes at weather `+0x670..+0x672` (`DATA` bytes 12 to 14). A non-positive value only caps each channel at 1.0 through `0x140ef2e80`. The sun light row copies at `0x41c815–0x41c8b0` also feed a second light for clouds (`Sun+0x40`).

**Unverified.** The role of row 2. I found no read of `Sky+0xc0` in the functions that reference the Sky singleton (a scoped scan of the 50 functions). Row 13 has a consumer that stores its address (table above). What the reading side does with the colour is not decoded. Also unverified: any consumer outside the Sky functions that reads rows 3/4 or others through another path. I scanned `0x40a000–0x41e000`, the water system update and the consumers named in earlier findings. A search for a plain displacement misses a read made through the result of `GetSky`. This is how the first version of this finding missed the row 13 consumer.

**Confidence: high** for destinations and weights, **medium** for the row 2 cell.

### G04. Cloud layers: colour, alpha, speed, layer count, textures

**Verified.** The cloud colour loop (`0x413520–0x4136d4`) runs per layer `i` of the `Clouds` object (`numLayers` at `Clouds+0x510`). It uses the same four weights and slot indices as G02. Colour comes from weather `+0x260 + 16·i + 4·slot` (32 layers × 4 slots × 4 bytes). Alpha comes from weather `+0x460 + 16·i + 4·slot` (32 × 4 floats). The result goes to `Clouds+0x310 + 12·i` (colour) and `Clouds+0x490 + 4·i` (alpha). Alpha is the weighted sum of the four slot alphas. The accessors `0x3081f0` and `0x308250` clamp the layer index: an index at or above the layer count (weather `+0x7d0`) uses layer 0. If the count is not positive, the compiled fallback colours are used (slot 0 `0x5b4b46`, slot 1 `0x9b9b9b`, slot 2 `0x6c5953`, slot 3 `0x1c140f`) and the fallback alpha is 1.0.

**Verified.** The loader dispatch for weather subrecords (jump table at `0x308d60`, indexed by tag minus `BNAM`) places: `DNAM`, `CNAM`, `BNAM`, `ENAM` and the 32-slot `NNTX` texture tags at `+0x20 + 0x10·layer`; `PNAM` colours at `+0x260`; `JNAM` alphas at `+0x460`; `RNAM` (32 bytes) at `+0x220`; `QNAM` (32 bytes) at `+0x240`; `LNAM` (4 bytes) at `+0x7d0`; `NAM1` at `+0x660` (layer-disable bit mask). Layers without a texture tag get their mask bit set at the end of the load (`0x308d37–0x308d3a`). `ONAM` reads 32 bytes into `+0x220` and recodes the first four as (byte>>1)+0x7f.

**Verified.** Cloud scroll (`0x40c320–0x40c4eb`). For layer `i` and each weather, the byte `b` is `[+0x240 + idx]` for the first axis and `[+0x220 + idx]` for the second, with `idx = i` if `i` is below the `LNAM` count and 0 otherwise. If the weather has no count the default byte is `0x33`. The decoded speed is `−S + b × (2S/254)`, with `S` = `fWeatherCloudSpeedMax` (0.1; 254 from the literal 0.003937 at `0x141868708`). Current and previous weather mix with `q` and `1−q`. Each frame adds speed × 0.1 (`0x141b5bde4`) × the frame time argument to a per-layer 2-float table at `0x143436510` (32 entries). The sky shader reads that table as the cloud UV offset (`VS cb2[16].xy`, G09). So the first component takes `QNAM` and the second takes `RNAM`. `DATA` bytes at `+0x665` and `+0x666` have no direct-displacement reader in the listing. Unverified whether they are read some other way.

**Verified.** Layer property fields: `+0x98` and `+0xa0` are the current and previous weather textures, `+0xb8` is a fade factor (`max(q, …)` from `Sky+0x1b8`, `0x40ca7a–0x40ca86`). The pass builder (`0x1553614–0x15536c8`) picks the technique from them: factor ≤ 0 gives `Clouds` (id `0x5c000062`). Otherwise two non-default textures give `CloudsLerp` (`0x5c000063`) and one default texture gives `CloudsFade` (`0x5c000064`).

**Confidence: high.** **Unverified:** the number of layers a given weather uses beyond the `LNAM` clamp, and the `NNTX` letter-to-index map for indices above 9 (the code uses plain integer subtraction).

### G05. Schedules that differ from the colour schedule

**Verified.** All "A, B, C, D" below mean the same extended endpoints as G02 unless noted.

| Quantity | Endpoints | Rule |
|---|---|---|
| Fog scalars (near, far, power, max) | `A, B, C, D` | One weight `w`: `(h−A)/(B−A)` for `A<h<B`, 1 for `B≤h≤C`, `(D−h)/(D−C)` for `C<h<D`, else 0 (`0x413a80–0x413b17`). Value = `w·day + (1−w)·night`. This is one linear ramp over the whole window, unlike the colours. |
| Star alpha | `A, B, C, D`, midpoints `M1, M2` | 1 for `h ≤ A` and `h ≥ D`. `(M1−h)/(M1−A)` for `A<h<M1`. 0 for `M1 ≤ h ≤ M2`. `(h−M2)/(D−M2)` for `M2<h<D` (`0x41a750–0x41a7cb`). |
| Sun disc and glare alpha `α` | raw `SB, SE, TB, TE` (no extension) | `MR = (SB+SE)/2`, `MS = (TB+TE)/2`, `hT = fSunAlphaTransTime/2`. `α = 0` for `h < MR−hT` and `h > MS+hT`. Rising `(h−(MR−hT))/(2hT)` up to `MR+hT`. 1 until `MS−hT`. Falling to 0 at `MS+hT`. Exactly at the two outer edges the code returns 1 (`0x41c194–0x41c1e7`). |
| Sun path coordinate `u` | `Ds = MR−hT`, `De = MS+hT` | `u = 1 − 2(h−Ds)/(De−Ds)` for `Ds<h<De`. At night `u = 2t/(24−(De−Ds)) − 1` with `t = h−De` (or `h+24−De` before dawn) (`0x41c3cc–0x41c43e`). |
| Aurora alpha | fixed hours | `fAuroraFadeInStart` 19.5, `fAutoraFadeIn` 20.0, `fAuroraFadeOutStart` 5.0, `fAutoraFadeOut` 5.5 (typo is the image's). 0 for 5.5 ≤ h ≤ 19.5, rising to 1 at 20.0, 1 to 5.0, falling to 0 at 5.5. Multiplied by a weather factor. A weather flag (`DATA` byte 11, bit `0x10`, `+0x66f`) forces the day factor to 1 (`0x414860–0x4148d6`). |
| Moon | angle, not hour | G07. |
| Image-space forms and volumetric-lighting forms | `A, B, C, D` | `0x415660` calls the four endpoint helpers (`0x415741–0x415764`) and has the same half-window structure. It passes the same indices and weight to `0x4158d0` (image space, #1003 G03) and `0x415b80` (four forms per weather at `+0x8a8`, volumetric lighting helpers `0x1415308a0` and `0x141530a20`). Verified call and structure; the blend inside `0x415b80` was not decoded. |
| DALC sets | same as colours | `0x416490` receives the same weight block and indices (call `0x413944`). |

**Confidence: high** for every row except the last two image-space rows (medium).

### G06. Sun: position, light direction, colour, night behaviour

**Verified.** `Sun::Update` mode 3 (`0x41c01f–0x41c52c`):

- The disc and glare nodes get a local translation `(X, fSunYExtreme, |fSunXExtreme| − |X|)` with `X = u × fSunXExtreme` (`0x41c442–0x41c49d`, stored at node `+0x6c..+0x74`). The same triple goes to globals `0x143435c70..78`. At the dawn start and dusk end `u = ±1` and the height term is 0. Noon height is 400 with the defaults. The nodes keep moving at night (the night formula of G05 uses the same extreme).
- The directional light vector before normalisation is `(−X·kd, −fSunYExtreme·kd, fSunZExtreme)` with `kd = fSunDirXExtreme/fSunXExtreme` (`0x41c49d–0x41c4e3`). The normalised vector goes into the first column of the light's 3×3 local rotation (`0x41c4e8–0x41c52c`; template `0x1420ced98` is the identity). `#1003 G03` states the same. With the defaults the vector toward the light is `(X, 25, 100)/norm`, so its Z component is positive at every hour and the elevation is at least about 14 degrees at the window edges. Verified for the vector; the world orientation of the light's parent was not checked.
- Light colour. Ambient = `Sky+0xcc`, diffuse = `Sky+0xd8`, third colour slot = `Sky+0x180` (a copy of `Sky+0xd8`), effect colour = `Sky+0x114`. Cloud light ambient = `Sky+0x12c`, diffuse = `Sky+0x120`. The cloud light copies the sun light's rotation (`0x41c815–0x41c913`). No scale by hour is applied here.
- Sun disc property colour = `Sky+0xe4..` × `fSunBoost:Weather` (1.0), alpha = `α` (G05). Glare property colour = `Sky+0x15c..` × `fSunGlareMultiplier:Weather` (2.0), alpha = (Σ over current and previous weather of `DATA` byte `+0x668`/255 × weight × `α`) (`0x41c1f5–0x41c36d`).
- Glare size. The glare node scale `s` (`Sun+0x48`) moves toward the target `(1 − occlusion)²` of the sun occlusion query at `fSunReduceGlareSpeed` (4.0) per second. It does so only while the query is not fully occluded and the target is at least `fSunMinimumGlareScale` (0.25). Otherwise `s` falls at the same rate. The node is hidden when the decayed `s` is below 0.25, and `s` is then set to 0. The node scale written is `|s|` (`0x41c52f–0x41c62f`). The query geometry is drawn by a pass created in `0x1520db0` (called from `0x41c960` at `0x41ca0f`). Its colour write mask is zero (G10).
- Night. I found no sun/moon switch and no writer of the light's fade or intensity in `Sun::Update`, in `Sky::Update`, or in `0x4182d0`. Night dimming comes from the night slots of rows 3 and 4 (data) and from the image-space `SunlightScale` that the Lighting upload multiplies in (#1003 G03). Other writers of the scene sun wrapper were not enumerated.

**Interior modes.** Modes 1 and 2 build the light rotation from the cell lighting template angles instead (`0x41c63b–0x41c813`); not decoded further.

**Confidence: high** for formulas and constants; **unverified** for runtime light fade writers outside these functions and for the orientation of the sky root.

### G07. Moons (Masser and Secunda)

**Verified.** Phase: the climate byte `+0x7d` low 6 bits `L` is the phase length in days. `phase = floor((dayCount mod 8L) / L)` (`0x40d370–0x40d3bb`; day count from the calendar call at `0x140646000`), stored at `0x1431e0b88`, 0..7. Texture names are built as `Data/Textures/Sky/%s_%s.dds` with the moon name and the phase string. The strings per phase index are: 0 `full`, 1 `three_wan`, 2 `half_wan`, 3 `one_wan`, 4 `new`, 5 `one_wax`, 6 `half_wax`, 7 `three_wax` (`0x40d5a8–0x40d667`). A phase change sets the moon's texture update status (`Moon+0xc8`).

**Verified.** Position (`0x40e174–0x40e236`): each moon keeps an angle at `Moon+0xcc` in degrees. First use sets 90. Each frame adds `speed × 60 × Δh` (Δh = hour minus the stored hour, +24 if negative), then wraps into [0,360). Constants (image defaults): Masser `fMasserSpeed` 0.25, `fMasserZOffset` 35, `iMasserSize` 94. Secunda 0.3, 50, 40. So Masser turns 15 degrees per game hour and Secunda 18. The rotation matrix uses the angle and the ZOffset as a second angle (`0x40e4b1–0x40e583`). The axis convention was not decoded.

**Verified.** Disc alpha `αm(angle)` with start `P = fXAngleFadeStart` and end `Q = fXAngleFadeEnd`: 0 below `Q`, linear to 1 at `P`, 1 up to `180−P`, linear to 0 at `180−Q`, 0 above (`0x40e242–0x40e2c1`). Masser has `P = 55`, `Q = 45`. Secunda has `P = 55`, `Q = 40`. The moon is lit by hour only through its angle. The shadow (mask) alpha `αs` is `min(Stars alpha, profile)`. The profile ramps over `fXAngleShadowEarlyFade` (0.5) before `Q` and after `180−Q` (`0x40e2c5–0x40e339`).

**Verified.** Colours. The moon disc quad (`Moon+0x20`, sky object type 6) property colour is `Sky+0x168..` (`NAM0` row 16) with alpha `αm`. The shadow quad (`Moon+0x28`, type 7) property colour is `Sky+0xa8..` (row 0) with alpha `αs` (`0x40e5ce–0x40e709`). The type 7 technique writes no colour (G10), so that colour is not written by the mask technique. The phase texture goes on the disc quad's property slot `+0x98`. `Textures\Sky\MoonShadow.dds` goes on the shadow quad (`0x40de8e`). The quads are built at run time in `Moon::Init` (`0x40d930`) with property types 6 and 7 set at `0x40dc32` and `0x40dd56`. **Verified.** The moon is hidden when its alpha is 0 (`0x40e5c5`, `0x40e670`, `0x40e70b`).

**Verified.** Creation (`0x414fe0` at `0x415248–0x415400`): bit `0x80` of the climate byte `+0x7d` creates the object stored at `Sky+0x90` using the Masser settings and the name string `Masser`. Bit `0x40` creates the object at `Sky+0x98` using the Secunda settings and the name `Secunda`. The CrashLogger enum `MoonPhaseLength` labels `kMasser = 64` and `kSecunda = 128`. That label order is the reverse of this code (see G14).

**Confidence: high** except the rotation axis (unverified).

### G08. Stars and the aurora

**Verified.** Stars rotate about the axis `(fStarsRotateXAxis, fStarsRotateYAxis, fStarsRotateZAxis)` = (0, 0, 1) by `2π × fmod(dayCount + h/24, fStarsRotateDays)/fStarsRotateDays` with `fStarsRotateDays` = 4 (`0x41a8f1–0x41a9c0`). Star alpha follows G05. Star property colour is `Sky+0xf0..` (row 6) with the star alpha (`0x41a810–0x41a8d2`). Stars hide when the alpha is 0 or the colour equals the global `0x14331d6f0` triple.

**Verified.** The aurora and sky-statics model is a handle at `Sky+0x20` loaded from a path in the weather (`weather+0x878`). Its alpha follows the aurora row of G05. Its transform copies the sun root's translation when weather flag `0x20` of `DATA` byte 11 is set (`0x414a45–0x414a85`). The shipped `SkyrimAurora.nif` has three `BSTriShape` blocks with `BSEffectShaderProperty` and `NiAlphaProperty`. So the aurora goes through the Effect shader family, not the Sky shader.

**Confidence: high** for rotation and alpha. **Unverified:** the weather subrecord that supplies the model path, and the effect shader states.

### G09. The `Sky` shader: techniques and arithmetic

**Verified, high.** The package `shaders011.fxp` group 4 (zero-based; file offsets 113852 to 133004) has nine vertex and nine pixel records with keys 0 to 8. The shader-file loader `0x14ea2d0` builds the shader objects in this order: BloodSplatter, DistantTree, Grass, Particle, Sky (`BSSkyShader::ctor` at `0x14ea5c7`), Effect, Lighting, Utility, Water. It then calls the group reader `0x141578f50` once per shader in the same order (`0x14ea80c` to `0x14ea894`). So the fifth call, group 4, belongs to the Sky object. `BSSkyShader` has nine technique names in the same order (name function `0x1552d40`; strings at `0x141b480f0–0x141b48178`). The key lookup at `0x1552280` gives VS key = PS key = the technique index (`0x14158d440` and `0x14158d450` return their argument).

**Verified.** Technique index, pass id, creating property type and states of the pixel stage:

| Index | Name | Pass id | Property type that selects it | PS output (per channel) |
|---|---|---|---|---|
| 0 | SunOcclude | pass id 2 (ids outside the table map here) | made by `0x1520db0`, not by a property type | black, alpha 1 |
| 1 | SunGlare | `0x5c006072` | 1 | `dither + tex.rgb × c.rgb + 0`; alpha `tex.a × c.a` |
| 2 | MoonAndStarsMask | `0x5c00005f` | 7 | `tex`; `discard` when `tex.a − cb11[0].x < 0` |
| 3 | Stars | `0x5c000060` | 5 | `1.5 × (tex.rgb × c.rgb + y)`; alpha `tex.a × c.a × f` |
| 4 | Clouds | `0x5c000062` | 3 (fade factor ≤ 0) | `tex.rgb × c.rgb + y`; alpha `tex.a × c.a` |
| 5 | CloudsLerp | `0x5c000063` | 3 (two textures) | `mix(tex0, tex1, cb2[0].x)` then as Clouds |
| 6 | CloudsFade | `0x5c000064` | 3 (one texture) | alpha `tex.a × cb2[0].x × c.a`; colour as Clouds |
| 7 | Texture | `0x5c000061` | 0 and 6, and others | `tex.rgb × c.rgb + y`; alpha `tex.a × c.a` |
| 8 | Sky | `0x5c00005e` | 2 and 4 | `dither + c.rgb + y`; alpha `c.a` |

Here `c` is the interpolated vertex colour, `y = cb2[0].y`, and `f` is a vertex-stage factor. The type-to-technique map is from `0x1553582–0x1553711` (type 1 → SunGlare; 3 → clouds; 5 → Stars; 7 → MoonAndStarsMask; 2 and 4 → Sky; other types → Texture). The pass-id-to-index map is at `0x1552280–0x1552308` (table at `0x141552564`). `dither` is `0.03125 × tex_t2(pixel × 0.125).r − 0.0078125`, used by indices 1 and 8 only. Stars `f` is `saturate((dp4(cb2[6],pos) − cb2[12].z)/17)` computed in the VS (its meaning is unverified).

**Verified.** Vertex stage, all nine records: clip output is `(x', y', w', w')`, so NDC z = 1 for every sky vertex. The vertex colour `c` is `k × (v.x·C13 + v.y·C14 + v.z·C15)` with alpha `v.w × C13.w`, where `k = cb2[12].w` is the global float at `0x1420d694c` and `C13..C15` are `cb2[13..15]`. The sky setup reads that global at `0x1552964` and `0x1552990`. The file holds the initial value 0.8333333. One code path stores a reciprocal into the global at run time: the `SetFramebufferRange` console command (store at `0x37ac8f`, `1.0 / argument`). The interface draw `0x116ac80` stores the constant 1.0 at `0x116acfb` and stores the old value back at `0x116afb6`. So the run-time value can differ from the file value after that console command was run, and it is 1.0 while the interface is drawn. *(Amended 2026-11-24, UNREVIEWED: this sentence only. See `findings/live-k-composite-target-retail-facts.md` G01 and C2.)* It is the same global as the `k` of #1003 G05 and #1077. `0x15525b0` fills them by property type (jump table at `0x141552cb4`): types 0, 1, 3, 5, 6, 7 put the property colour (`property+0x88`, four floats) into `C13` and zero into `C14, C15`; type 2 (dome) puts the three globals `0x143436610/620/630` (rows 8, 7, 0; w = 1) into `C13, C14, C15`, so the dome vertex colour channels are blend weights for horizon, lower sky and upper sky; type 4 puts zero RGB and alpha 1. UV offsets for clouds come from `cb2[16].xy` (G04). Index 3 colour is `k × cb2[13].rgb`, no vertex colour. The dome VS also computes direction-based texcoords (acos form, ×501) that no pixel record reads.

**Verified.** `y = cb2[0].y = k × (float at ImageSpaceManager +0xe4)` for property types other than 1 and 6, and 0 for types 1 and 6 (`0x15528ee–0x15529a0`, manager `0x1433d40a0`). The pixel records add `y` to every colour channel. The float at `+0xe4` is the HDR float after `sunlightScale` (`+0xe0`, #1003 G03); `skyScale` is the community label and was not verified. The compiled default of the base HDR record constructor is 1.5 (`0x141536a6b`). The visual size of this term depends on image-space data, not on compiled constants. `cb2[0].x` is the property alpha at `+0xb8` for type 3 (inverted for `CloudsFade` when the fade-direction byte `+0xbe` is clear).

**Verified.** None of the nine VS and PS records reads a fog constant, a light constant or a shadow input. So the sky shader family applies no fog, no directional ambient and no sun light. This answers the open sentence "Sky, clouds, sun and moon fog formulas remain unverified" of #812 G05 for these nine techniques. The aurora uses a different family (G08).

**Confidence: high** for the arithmetic, the constant slots and the group identification (loader order above).

### G10. Render state set by the sky shader

**Verified.** The state caches at `0x1420cfc88` (depth mode), `0x1420cfc90` (stencil mode), `0x1420cfca0` (rasteriser depth-bias slot), `0x1420cfca8` (blend group), `0x1420cfcac` (alpha to coverage), `0x1420cfcb0` (colour write mask mode), `0x1420cfcb4` (alpha-test byte) and `0x1420cfcb8` (alpha reference float) are flushed at `0x100a228`. State object index formulas: depth-stencil `0x143330230 + 8·(stencil + 40·depth)`; rasteriser `0x1433309b0 + 8·(scissor + 2·(bias + 12·(3·fill + cull)))`; blend `0x143330e30 + 8·(2·(13·(2·group + a2c) + mask) + [0x1420d01d0])`. I read the table creation loops (`0x102b120`, `0x102b6c0`, `0x102abd0`):

- Depth mode: 0 test off; 1 test less-equal, no write; 2 write, always pass; 3 test less-equal and write; 4 test equal, no write; 5 test greater-equal, no write.
- Blend group: 0 off (one, zero); 1 source alpha, inverse source alpha; 2 source alpha, one; 3 colour (dest colour, inverse source alpha) with alpha (dest alpha, inverse source alpha); 4 dest colour, zero; 5 one, one; 6 one, inverse source alpha. All use the add operation.
- Colour write mask mode: 0 none; 1 RGB; 2 RGBA; 3 RG; 4 BA; 5 R; 6 G; 7 B; 8 A; 9 RT0 blue and RT1 RGB; 10 RT1 none; 11 RT1 to RT7 none; 12 RT2 to RT7 none (RT0 stays RGBA).
- Rasteriser depth bias slot: 0 (0, 0); 1 and 3 (−3, −0.4); 2 (−9, −1.2); 4 (3, 0.4); 5 (6, 0.8); 6, 8, 10 (−1, −0.65); 7, 9, 11 (0, 0). The numbers are (constant bias, slope-scaled bias); the clamp is −100 (`0x14180a3a8`).

**Verified.** `0x1552280` sets the following for each technique, and `0x1552190` restores blend group 0, mask mode 1, depth mode 3, alpha-test byte 0 and bias slot 0 after the draw:

| Technique | Depth mode | Blend group | Write mask mode | Bias slot | Other |
|---|---|---|---|---|---|
| 0 SunOcclude | 1 | 0 (restore value) | 0 (none) | 0 | — |
| 1 SunGlare | 0 (no test) | 2 (source alpha, one) | 11 (RT0 only) | 0 | — |
| 2 MoonAndStarsMask | 3 (test and write) | 0 | 0 (none) | 3 | alpha-test byte 1 |
| 3 Stars | 1 | 2 | 1 (RGB) | 0 | — |
| 4, 5, 6 Clouds family | 1 | 1 (alpha blend) | 1 | 2 | — |
| 7 Texture | 1 | 1; 2 for property types 0 and 6 (`0x152906c–0x1552c8a`) | 1 | 2 | — |
| 8 Sky | 1 | 1 | 1 | 0 | — |

So the sun disc (type 0) and the moon disc (type 6) blend with (source alpha, one). The moon shadow quad (type 7) writes depth only, shifted by slot 3 (a small negative bias), and the later star pass tests against it. That is **inferred** as the purpose (stars hidden behind the moon area); the state values are verified. I found no other writer of these caches between the sky pass lists in stage A except the pre-draw set in G11 (depth mode 3, alpha test on, reference `0x3f008081` ≈ 0.502).

**Confidence: high** for the state tables, **medium** for the combined per-draw state (other writers in the accumulator and per-property setup were not enumerated).

### G11. Draw order and the place in the frame

**Verified.** `0x1539f10` calls the first accumulator finish (stage A, `0x151ef40`) through `0x15152d0` at `0x153a02f`, then set-up calls, then the SAO and fog composite function `0x1541f40` at `0x153a1ca` (flag byte `0x14343639c` = 1), then the second finish (stage B, `0x151f540`) through `0x1515360` at `0x153a1ef`. The composite fog arithmetic and the depth ≥ 0.999999 skip are in #1077 (`findings/exterior-haze-trace-retail-facts.md`) and are not repeated.

**Verified.** The batch draw `0x1521190` takes `(first id, last id, flags, group)` and walks the pass-id list upward from the first id until an id passes the last id (`0x155fd85–0x155fda9`). The ascending order follows from the iteration test and from the list insertion, which keeps the active pass ids sorted (`0x1560e6a`; partial read). Stage A (`0x151ef40`) draws in this order: ids `1` to `0x5c00002f` (`0x151efc4`; the Lighting pass id is its technique + `0x2b`, `0x151a745`); a group list; ids `0x5c000030` to `0x5c00005c` (`0x151f020`); three more group lists; ids **`0x5c00005d` to `0x5c000064`, the sky ids** (`0x151f177`); a further group list; decal passes (`0x151fd60`, `0x151ff00`); then optional lists and, if flag bit 6 is set, the call to `0x153a6b0`. Within the sky range the id order is: dome (`5e`), moon and star mask (`5f`), stars (`60`), texture quads (`61`: sun disc, moon disc), clouds (`62`, `63`, `64`). Order inside one id follows the list order, which was not traced.

**Verified.** Stage B ends with `RenderEffects` (`0x151fb80`), the frame constant writer, and then the single draw of id `0x5c006072`, the sun glare, with all groups (`0x151fb45`). So the glare draws after the composite, with depth mode 0.

**Verified.** The sky draws after the Lighting passes of the same stage. Sky depth mode 1 tests less-equal against the depth buffer and writes no depth (mask technique excepted), so, from the state values alone, the sky fails the depth test wherever the scene wrote a nearer depth (static only). Sky vertices sit at NDC z = 1 (G09). Cloud (`−9` bias slot 2) and mask (`−3` slot 3) draws stay at or above about 0.9999995 of the depth range under a 24-bit depth model. That depth format was not checked; it is **inferred** that these pixels stay under the 0.999999 skip of the composite.

**Confidence: high** for the stage order and ids, **medium** for the list insertion (partial read) and for the depth-format-dependent bias statement.

### G12. Shipped sky meshes and property types

**Verified** (shipped files, structure only). `Meshes\Sky\Atmosphere.nif` has one `BSTriShape` with a `BSSkyShaderProperty` of sky object type 2. `Clouds.nif` has 29 `BSTriShape` blocks, each with a type-3 property. `Stars.nif` has four `BSTriShape` blocks, all type 5. `SkyrimAurora.nif` has three shapes with effect shader properties (no sky property). The sun disc, sun query, glare, moon disc and moon shadow quads are built in code (types 0, 0, 1, 6, 7; `0x41bbf0`, `0x41bc89`, `0x41bd1d`, `0x40dc32`, `0x40dd56`). No type 4 property was found in these meshes or in the code I read.

**Confidence: high.**

### G13. Compiled constants used (image values, re-read in this run)

| Name or role | Value | Address |
|---|---|---|
| `fDaytimeColorExtension` | 0.5 | `0x14209e5a0` |
| 1/6 hour per climate byte | 0.1666667 | `0x141869dd8` |
| endpoint cap | 23.99 | `0x141869df4` |
| `fWeatherTransMin` / `Max` / `Accel` | 0.01 / 0.25 / 4.0 | `0x14209e720` / `708` / `738` |
| `fWeatherFlashDirectional` / `Ambient` / `Duration` | 1.0 / 0.3 / 0.25 | `0x14209e768` / `780` / `750` |
| `fSunAlphaTransTime` | 2.0 | `0x14209e948` |
| `fSunXExtreme`, `fSunYExtreme`, `fSunZExtreme`, `fSunDirXExtreme` | 400, 25, −100, 400 | `0x14209e960`, `978`, `990`, `9a8` |
| `fSunBoost:Weather`, `fSunGlareMultiplier:Weather` | 1.0, 2.0 | `0x14209e900`, `0x14209e9c0` |
| `fSunReduceGlareSpeed`, `fSunMinimumGlareScale` | 4.0, 0.25 | `0x14209e930`, `918` |
| `fWeatherCloudSpeedMax` | 0.1 | `0x14209e540` |
| `fStarsRotateDays`; axes | 4.0; (0, 0, 1) | `0x14209e870`; `888`, `8a0`, `8b8` |
| Masser: start, end, early fade, speed, z offset, size | 55, 45, 0.5, 0.25, 35, 94 | `0x14209e5e8` to `0x14209e660` |
| Secunda: same order | 55, 40, 0.5, 0.3, 50, 40 | `0x14209e678` to `0x14209e6f0` |
| aurora fade (in start, in, out start, out) | 19.5, 20.0, 5.0, 5.5 | `0x14209e7e0`, `7f8`, `810`, `828` |
| sky `k` (initial file value; run-time global, see G09) | 0.8333333 | `0x1420d694c` |
| moon: degrees per speed unit; half circle; full circle; initial angle | 60; 180; 360; 90 | `0x141b5bec8`; `0x141b5bf44`; `0x141b5bf80`; literal `0x42b40000` |
| cloud speed decode; scroll scale | 1/254; 0.1 | `0x141868708`; `0x141b5bde4` |

**Confidence: high.** The settings may be overridden by INI or by other writers; I did not check them.

### G14. Label checks

**Verified.** (a) The CrashLogger enum `MoonPhaseLength` names `kMasser = 64` and `kSecunda = 128`. The creation code in G07 uses bit `0x80` for the object at `Sky+0x90` (`masser`, name string `Masser`) and bit `0x40` for the object at `Sky+0x98`. The enum labels for these two bits look swapped. This is a label question, not an earlier finding. (b) `NiLight.radius` (PDB, `+0x128`) receives the sunlight colour in `Sun::Update`. For point lights the point writer reads `radius.x` of the same slot (#1003 G04). Treat the slot as shared storage, not as a radius for directional lights.

**Confidence: high** for what the code writes; **unverified** which name a source would give the slot.

## Relation to earlier findings

- **#812** (`findings/exterior-fog-retail-facts.md`): I re-read its endpoint formula, day-part table, weather transition and fog weight at the code. They match G02 and G05.
- **#1003** (`findings/object-lod-ambient-sun-retail-facts.md`): I re-read its schedule and its light-direction statement ("first column" of the light rotation). They match G02 and G06.
- **#1073** (`findings/point-lights-selection-retail-facts.md`): I checked its call-site statement for `Sky::UpdateLightLODFadeDistances`. It matches the call sites `0x4121ff`, `0x4122ae`, `0x413280` and `0x4139da`.
- **#1077** (`findings/exterior-haze-trace-retail-facts.md`): G09 here answers its open point that sky fog was not decoded. The nine sky techniques contain no fog math. G11 here uses its composite order and does not repeat it.
- A separate hygiene PR amends published findings #812, #1003 and #946. This finding does not repeat their text.

## Interpretation and alternatives

The colour data reaches the shaders in three ways. Sky shader draws use rows 0, 7, 8 (dome), 5 and 15 (sun), 6 (stars), 16 (moon) and the cloud-layer colours as vertex-stage inputs scaled by `k`. The Lighting shaders use rows 3 and 4 and the DALC sets through the sun light and the Lighting upload. Fog uses rows 1 and 12 and the weighted scalars. All of these share one weight set, so a client that evaluates the schedule once per frame (G02 with the `q` mix) reproduces every colour consumer. The sun and moon alphas, the star alpha, the aurora and the cloud scroll need their own functions (G05).

**Inferred.** The additive `y` term of the sky pixel records raises dome, cloud and star colours by `k × (image-space float)`. I did not find what retail data holds in that float. A client that omits it would differ by an amount set by that data.

**Alternative.** The mask technique could serve another purpose than hiding stars. The state values do not prove the intent.

## Negative results and limitations

- **Unverified.** All runtime values: weather forms, climate bytes, image-space data, INI overrides, the live `q`, and the actual state at each draw.
- **Unverified.** The order of passes inside one id; whether other code reorders the pass lists.
- **Unverified.** The row 2 consumer, and the reading side of the row 13 pointer. `DATA` bytes `+0x665`, `+0x666`, `+0x669` have no direct-displacement reader in the listing (a read through an index would not appear).
- **Unverified.** The colour-write mask word at the first sky draw of a frame. The sky code does not set it for techniques 3 to 8, so it holds whatever the earlier batches left. The combined per-draw state (G10) rests on this.
- **Unverified.** The bodies of `0x4158d0` (image-space blend) and `0x415b80` (volumetric-lighting blend). I checked only that they receive the same indices and weights (G05).
- **Unverified.** The `k` value at run time (G09).
- **Unverified.** The rotation axes of the moons (the axis convention was not decoded) and of the sun light's parent; the aurora's effect-shader states; `0x41ca50`.
- No game launch, no capture, no visual comparison. The example in G02 uses invented numbers.

## Independent review

Reviewer: a fresh-context Sonnet 5.5 run (`claude-sonnet-5-5`), separate from the author. Sol was unavailable on a usage limit. The reviewer wrote its own results for all three questions first, from the pinned image and the shader member, before it opened the first version of this finding. It then compared them with that version and re-read the disputed items. Static only.

Result: **11 confirmed (G01, G02, G04, G05, G07, G08, G09, G10, G12, G13, G14), 4 corrected (G03, G06, G11, G15), 0 rejected.** This file contains the corrected wording.

| Group | Verdict | Main correction |
|---|---|---|
| G01 Update order and modes | Confirmed | `0x414180` was unread in the first version. It is the weather sound update (GUESS) and does not change the answer. |
| G02 Day-part schedule | Confirmed | None. |
| G03 `NAM0` rows | Corrected | Row 13 has a consumer. The first version's displacement search could not see a read made through the result of `GetSky`. Row 2 stays "none found" from a scoped scan. |
| G04 Cloud layers | Confirmed | None. |
| G05 Other schedules | Confirmed | The image-space and volumetric-lighting rows have only the call structure checked. |
| G06 Sun | Corrected | One sentence. The glare node hides when the decayed scale is below 0.25, not when the target is below 0.25. |
| G07 Moons | Confirmed | One wording change: "not written by the mask technique". The rotation axes stay unverified. |
| G08 Stars and aurora | Confirmed | None. |
| G09 Sky shader | Confirmed | The group binding is verified by the loader order. The first version tagged it inferred. |
| G10 Render state | Confirmed | Every table and per-technique row reproduced. |
| G11 Draw order | Corrected | The Answer table listed the objects in a misleading order. The corrected order is dome, moon-and-star mask, stars, sun and moon discs, clouds. The glare is last. |
| G12 Meshes | Confirmed | None. |
| G13 Constants | Confirmed | All 36 names and values. |
| G14 Label checks | Confirmed | None. |
| G15 Earlier findings (first version only) | Corrected | The first version's list of earlier statements to amend was incomplete. The scoped amendments go into a separate hygiene PR. This finding no longer carries that group. |

After the review, a third run applied the corrections and re-read 13 items in the pinned image: the row 13 read; the loader order of the nine group-reader calls; the glare scale decay; the `0x414180` reads; the moon creation bits; the endpoint helpers; the sun alpha branch structure; the glare draw id and call; the sorted pass-list insertion; the three stage calls and the sky id range; the water copy of row 14; the compiled values of the settings; and the `k` global. One item changed. The first version's note that `k` is "written at `0x152998c`" was wrong. G09 now gives the read addresses and the run-time writers.

Source exposure of the review: pinned native binary, shipped shader bytecode and shipped mesh structure. This is a static review. It is not match evidence for any function, and it does not decide transfer eligibility.

Reviewer and outcome: Reviewed independently by a Sonnet 5.5 run. Outcome: 11 confirmed, 4 corrected, 0 rejected. Static evidence only. Transfer status: UNREVIEWED.
