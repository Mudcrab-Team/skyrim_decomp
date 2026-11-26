Transfer status: UNREVIEWED

# Finding: retail sky and weather end to end (SPEC-4)

## Answer

Static only. No game run, no capture, no visual claim.

| Question | Answer | Mark |
|---|---|---|
| How is a weather chosen? | A weighted integer roll over one list: the weather list of the current weather region, else the list of the climate. Without a weather-region change, an override or a set or force call, a weather holds for `1 + (255 − v) × 22 / 255` game hours (`v` = climate byte). After that the sky rolls again in each update until the result differs from the current weather. | V2 |
| How does a change blend? | One fraction `q` from 0 to 1 over 0.01 to 0.25 game hour (a byte of the incoming weather). No new change is applied while a previous weather exists, except in an update where sky flag `0x10` is set (a player teleport or cell transition, section 4.6). | V2 |
| What draws? | Before the fog composite: dome, moon masks, stars, sun and moon discs, and the cloud layers (29 with the shipped mesh; layer 28 is a low horizon ring, "fog ring" is a GUESS label and it has no fog input). After the composite: sun glare. Aurora and precipitation use other shader families (interface only). | order V2; rest per section |
| What does the image-space float in sky pixels mean? | It is `SkyScale` (image-space `HNAM` float 8). The pixel shaders add `k × SkyScale` to the colour of types 0 (sun disc), 2 (dome), 3 (clouds), 4 and 5 (stars). Glare (1) and moon disc (6) get 0. The moon mask (7) receives the value and does not read it. The occlusion query has no such term. | V2 |
| Is there a lightning bolt object? | The sky code draws none. Weather lightning is a thunder sound plus a 250 ms colour flash at full strength. | flash V2; "no bolt" is a scoped negative |

| Evidence record | |
|---|---|
| Status | OBSERVED where V1 or V2. INFERRED where marked I. Static only. |
| Authors / human operator | Four separate fresh-context Sonnet 5.5 runs (`claude-sonnet-5-5`): author, independent reviewer, blind second binary check, finalizer. A Sol run was not available. Operator: the Skyrim Research project lead. |
| Reviewer | Independent review and blind second binary check done. The finalizer applied their corrections and re-read disputed and single-run facts. The merged text had no separate review. |
| Date | 2026-11-26 CST. |
| Build | `sse-steam-1-7-104`. Measured SHA-256 of `SkyrimSE.exe` `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f` equals the pin in `builds/target.json`. The readers assert it. Shader package SHA-256 `72cfc73eb0938d5949f0b3a8683722a33b671a34b41b750ba138de8d154c5fbc` (also asserted). |
| Sources | The pinned executable; shader group 4 of the shipped package; installed sky meshes (the author read three; the reviewer four; the second checker read three, for the layer, dome and star claims) for shape counts, types, order, vertex colour and extents; compiled setting objects; public generated CrashLogger names and types; matched reconstructions on the main branch (section 17). Earlier findings #812, #1003, #1077, #1080 and #1121, and SPEC-1 (#1274) and SPEC-2 (#1276). #879, #1073 and #1245 are background only; no ledger row rests on them. Some earlier findings were used as quoted by #1080, SPEC-1 and SPEC-2 and were not re-read in full by every run. |
| Source exposure | Mixed: binary and shader analysis of the operator's own install. Matched reconstruction files were read; some are labelled `SIBLING(fo4-private)` and some use CommonLibSSE-NG declarations. No value was read from any game plugin. No plugin world or weather name is given. No decompiler text or disassembly appears here. A reader of this file must not claim to be unexposed to the binary analysis. |
| Name provenance | Class and field names are `CRASHLOGGER_PDB(59818@2026.10.24)` or image strings. Record subrecord tags are public format names; their link to an offset is read from the loader only where a row says so, else inferred. Other labels are GUESS. Several PDB function names are wrong: `0x40e140` (named `Sky::ResetWeather`) is a piece of the moon update; `0x414780` (`Sky::UpdateClouds`) is the aurora update; some pieces near `0x416760` and `0x4152xx` are chunk labels. |
| Intended recipient | The Skyrim Research project, for boundary review under `docs/clean-room.md`. Maintainer transfer decision pending. |

## 0. How to read this file

| Mark | Meaning |
|---|---|
| **V2** | Confirmed by two different runs. The ledger (section 17) names them. |
| **V1** | Read by one run only. |
| **I** | Inferred. A deduction with stated assumptions. |
| **U** | Unverified or open. |

Run keys: **S4** = SPEC-4 author. **R** = SPEC-4 independent review. **B** = SPEC-4 blind second binary check. **X** = SPEC-4 finalizer. **K** = #1080 (author and independent review). **N** = SPEC-1. **H** = SPEC-2. **F** = #812. **O** = #1003. **Z** = #1121. **M** = a matched reconstruction on the main branch. A claim without its own mark takes the mark of its section heading or table row.

Addresses are RVAs (image base `0x140000000`). `h` = game hour in [0,24). `k` = global float at `0x20d694c` (file value 0.8333333; run-time value 1.0 during the interface draw, `1/x` after console `sfbr x`). `sat(x)` limits x to [0,1]. `lum(c) = 0.2125 r + 0.7154 g + 0.0721 b`. "`W+0x…`" = byte offset in a `TESWeather` object; "`C+0x…`" = offset in a `TESClimate` object; "`Sky+0x…`" = offset in the sky object. "`b/255`" means byte × 0.00392157.

Text under "Interim implementer choices" (section 15) is **not** a retail fact.

## 1. Pipeline map

Implement in this order, once per frame.

| # | Stage | What happens | Address | Section | Mark |
|---|---|---|---|---|---|
| 1 | Sky update | Store hour. Sky mode 1 (interior) and no save load: colours, fog, atmosphere, sun and the clear colour only. Else: climate objects, **weather selection and `q`**, colours, fog, wind, thunder and flash trigger, aurora, atmosphere, stars, clouds, sun, reference effects, moon phase, moons, precipitation, flash decay, clear colour | `0x411ec0` | 4 to 8 | V2 |
| 2 | Camera follow | The `Sky` node and the `Weather` node copy the camera root translation. No rotation is written | `0x657c90` | 7 | V2 |
| 3 | Image space | The weather image-space block (holds SkyScale) is blended with the weather weights | SPEC-2 | 9 | V2 (H) |
| 4 | Clear | Colour = `NAM0` row 12 × 0.83332998 (a literal, not `k`) | `0x4126b9`, `0x656d8b` | 10 | V2 |
| 5 | Depth prepass, depth copy, shadow masks | No sky draw is expected; prepass membership was not enumerated | SPEC-1/2/3 | 10 | order V2; no sky draw I |
| 6 | Read sun occlusion results | Previous queries | `0x1539f97` → `0x41ca50` → `0x1520f70` | 8.5 | V2 |
| 7 | Stage A | Lit lists, grass groups, then sky pass ids `0x5c00005d`–`0x5c000064`, then decals | `0x151ef40` | 10 | V2 |
| 8 | SAO and fog composite | Sky pixels take the no-fog branch | `0x1541f40` | 10 | composite V2 (H); sky pixel branch I (N, H) |
| 9 | Stage B | Water, sorted blended list, **sun glare last** | `0x151f540` | 10 | V2 (H, K) |
| 10 | Issue sun occlusion query | Later in the world colour function; results are for later frames | `0x153a526` → `0x41c960` → `0x1520db0` | 8.5 | V2 |
| 11 | Post-processing | HDR and output | SPEC-2 | 10 | V2 (H) |

## 2. Input records (names and decode rules; no plugin values)

### 2.1 Climate (`CLMT`, object `TESClimate`)

| Data | Offset | Decode | Mark |
|---|---|---|---|
| Weather list (`WLST`) | `C+0x48` | **One** subrecord holds all entries; count = size / 12. Entry: weather form id, signed 32-bit chance, global form id (may be none). The loader builds the list in **reverse record order** and then gap-insertion sorts it by the **record** chance, largest first (`0x30a5d0`, `0x30a900`, comparator `0x30abd0`). First gap: 1 if `(count−1) / 9` (integer) is 0; else the first of 4, 13, 40, … that is larger than it. Each next gap is gap / 3 (integer). So equal chances keep reverse record order up to 9 entries; from 10 entries the gap sort can reorder equal entries, repeatably. A global does not change the order | V2 |
| Night sky model (`MODL`) | `C+0x20` | Path of the star mesh | V1 |
| Sun texture, glare texture (`FNAM`, `GNAM`) | `C+0x58`, `C+0x68` | Set on the sun disc and glare quads; a quad without a texture is hidden. Tag-to-offset link I | V1 |
| Timing (`TNAM`, 6 bytes) | `C+0x78` | sunrise begin, sunrise end, sunset begin, sunset end (each byte × 1/6 hour); **volatility** (`C+0x7c`); moon byte (`C+0x7d`: bits 0–5 phase length in days, bit 6 Secunda, bit 7 Masser) | V2 |
| Default of a new object | — | All timing 0, moon byte 3 | V2 (S4, R) |

### 2.2 Region weather (`REGN`)

The region data block of type 3 holds a weather list with the same 12-byte entries, the same loader and the same roll (**V2**). Each region data block has an override byte (data `+0x8`, from `RDAT` byte 4) and a priority byte (data `+0xa`, from `RDAT` byte 5; a value above 100 is not stored) (**V2**; the tag name is a public format name).

### 2.3 Weather (`WTHR`, object `TESWeather`)

| Data | Offset | Decode | Default of a new object (`0x309230`, V2) |
|---|---|---|---|
| Cloud textures (`00TX` … `L0TX`) | `+0x20 + 16·i` | layer `i` = first tag character − `'0'` (`L0TX` = 28) | none |
| Cloud speed V (`RNAM`), U (`QNAM`) | `+0x220`, `+0x240`, 32 bytes each | section 8.2 | all `0x7f` (speed 0) |
| Cloud colours (`PNAM`) | `+0x260 + 16·i + 4·slot` | packed, lowest byte = R | 0 |
| Cloud alphas (`JNAM`) | `+0x460 + 16·i + 4·slot` | float | 1.0 |
| Layer disable bits (`NAM1`) | `+0x660` | bit `i`; the loader also sets bit `i` for a layer without a texture | 0 |
| `DATA` byte 0 | `+0x664` | wind speed `b/255` | 0 |
| byte 3 | `+0x667` | transition duration (section 5) | 0 |
| byte 4 | `+0x668` | sun glare strength `b/255` | 0 |
| bytes 6, 7 | `+0x66a`, `+0x66b` | precipitation fade-in start, fade-out end | 0 |
| bytes 8, 9, 10 | `+0x66c`, `+0x66d`, `+0x66e` | thunder fade-in start, fade-out end, rarity | 0 |
| byte 11 | `+0x66f` | flags: 1 pleasant, 2 cloudy, 4 rainy, 8 snow, 16 permanent aurora, 32 aurora follows sun (PDB names) | 0 |
| bytes 12–14 | `+0x670` | lightning colour caps R, G, B | 0 |
| bytes 15, 16 | `+0x673`, `+0x674` | visual effect begin, end `b/255` | 0 |
| bytes 17, 18 | `+0x675`, `+0x676` | wind direction `b × 360/255` degrees, range `b × 90/255` degrees | 0 |
| Colour rows (`NAM0`) | `+0x698 + 16·row + 4·slot` | 17 rows, slots sunrise, day, sunset, night; bytes R, G, B | rows 0–13 zero; rows 14, 15, 16 white |
| Fog scalars (`FNAM`, 8 floats) | `+0x678`–`+0x694` | day near, day far, night near, night far, day power, night power, day max, night max (field order I, public layout); blend in section 6.4 | distances 0; powers and maxima 1.0 |
| Cloud layer count (`LNAM`) | `+0x7d0` | section 6.3 | 3 |
| Sounds (`SNAM`) | `+0x7a8` | list of (sound, type); type 1 precipitation, 3 thunder | empty |
| Image spaces (`IMSP`) | `+0x7d8` | 4 forms by day part | none |
| Aurora model | `+0x878` | path | none |
| Precipitation data (`MNAM`) | `+0x8c8` | shader particle geometry form | none |
| Visual effect | `+0x8d0` region (reference effect) | — | none |

Offset marks: `DATA` bytes 0, 3, 4, 11–14, `NAM0`, the cloud arrays and `LNAM` are **V2** (K, S4). `DATA` bytes 6–10 and 15–18 are **V2** (S4, R). Tag-to-offset links for model, precipitation and effect rows are **I**. No sky reader of `DATA` bytes 1, 2 and 5 was found; for bytes 1 and 2 no direct reader was found (U).

## 3. Settings

Compiled values were read from the image (**V2**). "Kind" tells where an override can come from. **GMST** = the object class of the row is the game setting collection's setting class, read from the class information of each object, so loaded data files can override it (**V2**, S4, R, B). **INI** = the name carries a section. An implementer must apply the loaded data and INI values; the compiled value is only the default.

| Name | Compiled | Kind | Use |
|---|---|---|---|
| `fDaytimeColorExtension` | 0.5 | GMST | day-part endpoints |
| `fWeatherTransMin`, `Max`, `Accel` | 0.01, 0.25, 4.0 | GMST | `q` |
| `fWeatherFlashDirectional`, `Ambient`, `Duration` | 1.0, 0.3, 0.25 | GMST | flash |
| `fRoomLightingTransitionDuration` | 3.0 | GMST | room image space |
| `fWeatherCloudSpeedMax` | 0.1 | GMST | cloud scroll |
| `fPrecipWindMult` | 500 | GMST | precipitation wind |
| `fSunAlphaTransTime` | 2.0 | GMST | sun disc and path |
| `fSunXExtreme`, `fSunYExtreme`, `fSunZExtreme`, `fSunDirXExtreme` | 400, 25, −100, 400 | GMST | sun position and light |
| `fSunReduceGlareSpeed`, `fSunMinimumGlareScale` | 4.0, 0.25 | GMST | glare |
| `fSunBaseSize:Weather`, `fSunGlareSize:Weather` | 425, 600 | INI | quad half sizes |
| `fSunBoost:Weather`, `fSunGlareMultiplier:Weather` | 1.0, 2.0 | INI | colour multipliers |
| `bPrecipitation:Weather`, `bFogEnabled:Weather` | 1, 1 | INI | `bPrecipitation`: with 0 the precipitation weather sound is not played (`0x41792c`, V1); another read (`0x411cef`) and the use of `bFogEnabled` were not traced |
| `bUsePrecipitationOcclusion:Display` | 1; Low preset 0 (#1052) | INI preference | occlusion map (interface) |
| `fStarsRotateDays`; axes X, Y, Z | 4.0; 0, 0, 1 | GMST | stars |
| `fMasser…`: AngleFadeStart, AngleFadeEnd, AngleShadowEarlyFade, Speed, ZOffset, `iMasserSize` | 55, 45, 0.5, 0.25, 35, 94 | GMST | moon |
| `fSecunda…` same order | 55, 40, 0.5, 0.3, 50, 40 | GMST | moon |
| `fAuroraFadeInStart`, `fAutoraFadeIn`, `fAuroraFadeOutStart`, `fAutoraFadeOut` | 19.5, 20.0, 5.0, 5.5 | GMST | aurora (spelling is the image's) |

No shipped INI in the compiled-defaults table (#1052) sets one of the `:Weather` rows above (**V1**, table search).

## 4. Weather selection

### 4.1 The roll (`0x30a3c0`) — V2

```text
for each entry:  c_i = entry has a global ? trunc(global value) : record chance
T = Σ c_i                                   (32-bit)
if T == 0:  no result
r = random32 mod T
walk the list in list order, skipping entries with c_i == 0:
    pick the first entry with  start ≤ r ≤ start + c_i − 1 ; else start += c_i
if none matches (possible only with unusual values): the weather of the last entry
```

A global value **replaces** the chance. Negative values are treated as unsigned numbers by the arithmetic (**I**; do not rely on it). The generator is a Mersenne-twister object. A list "contains" a weather only if the entry for it has a nonzero effective chance (**V2**).

### 4.2 State and inputs

| Field | Meaning |
|---|---|
| `Sky+0x40` climate; `+0x48` current; `+0x50` previous ("last"); `+0x58` default; `+0x60` override; `+0x68` stored sky region | pointers |
| `+0x1b0` hour; `+0x1b4` hour of the last applied weather change; `+0x1b8` `q`; `+0x1d8` `q0` (acceleration start; the PDB name of this word is different) | numbers |
| `+0x1bc` mode | 0 none, 1 interior, 2 dome only, 3 full |
| `+0x1dc` flags | `0x1` changed; `0x2` forced or loaded; `0x8` accelerate; `0x10` instant change for the next weather update; `0x20` moon phase check by day (section 8.4); `0x40` climate changed; `0x200`–`0x4000` time caches dirty; `0x100000` wind changed; `0x200000` override released; `0x400000` two weathers present. The full sky update clears `0x1`, `0x2` and `0x100000` at its end; the weather update clears `0x10` and `0x200000` |

**Region source** `R` (`0x412810`): if the player is in an interior cell and that cell has a sky region (cell extra data type 8), `R` is that region. Else `R` is the region held by the player region state (section 4.4), which can be none.

### 4.3 Selection rules (`Sky::UpdateWeather` `0x412810`) — V2

**When.** The rules run in each sky update with a climate, except in sky mode 1 without a save load. "Load" means bit 1 of the word at `+0x340` of the global object at `0x3223e18` is set; it is read here as "save load in progress" (**I**, see C12).

**Terms.**

- Hold time `H = (255 − v) × 22 / 255 + 1` game hours, `v` = climate volatility byte. `H` is in [1, 23].
- Age `e = h − lastChange`, plus 24 if `lastChange > h`. The hold is **expired** if `e > H`. So `e` counts one day at most.
- **Keep draw:** take `u` uniform in [0,1]; the draw succeeds if `u > e / H`. The success probability is `max(0, 1 − e/H)`.
- A **climate roll into default** rolls the climate list and stores the result as the default weather. If the roll gives no result, form `0x15E` is used.

**Rule S1, override expiry.** This rule is judged before all others. An override whose hold is expired ends, and this update counts as "released".

**Rule S2, candidate.** The first matching row gives the candidate weather.

| Case | Condition | Candidate | Stored state that changes |
|---|---|---|---|
| a | An override exists; or a load is running and a current weather exists | The override. It can be none, which means no change. No random draw | none |
| b | `R` differs from the stored sky region, or "released"; `R` is a region | A roll of the region list. But if the result differs from current, the region list contains current and a keep draw succeeds, the candidate is current | stored sky region = `R` |
| c | Same trigger as b; `R` is none | The default weather (a climate roll into default if there is none). Before that: if current differs from default, the climate list contains current and a keep draw succeeds, default = current | stored sky region = none |
| d | Hold expired; `R` is a region | A roll of the region list | none |
| e | Hold expired; `R` is none | A climate roll into default | default |
| f | Otherwise; `R` is a region | none | none |
| g | Otherwise; `R` is none | The default weather (a climate roll into default if there is none) | default if it was empty |

**Rule S3, empty start.** With no current weather and no candidate, the candidate is the default weather, else a climate roll into default.

**Rule S4, acceptance.** The candidate replaces the current weather only if it differs from current **and** (there is no previous weather, or flag `0x10` is set). Only flag `0x10` bypasses the previous-weather test; sky mode 1 does not. A rejected candidate is dropped, and flag `0x1` is cleared; the state changes of S2 stay. For an accepted candidate:

- If flag `0x10` is set or the sky mode is 1, the previous weather becomes none, and precipitation and clouds are reset. Else the old current weather becomes the previous weather.
- The candidate becomes current. `lastChange` becomes `h`, except during a load. Flag `0x1` is set.

**Rule S5, region memory.** After every accepted change, and in a load update that started with a current weather, **every** region of the loaded data stores a remembered weather: the current weather if its list contains it, else a roll of its own list.

**Rule S6, close.** `q` is computed (section 5), the image spaces are updated, and flags `0x10` and `0x200000` are cleared.

**Consequences** (derived from the rules; **V2** for the code order):

- `lastChange` moves only on an accepted change. So with an expired hold, a roll that returns the current weather leads to a new roll in the next update. With a stable list and no transition, the next weather `i ≠ current` occurs with probability `c_i / (T − c_current)`. A list that holds only the current weather never changes it.
- A region list replaces the climate list. The two are not merged.
- Without a region, the default weather reaches the screen as soon as S4 allows it.
- A region change during a transition stores the new region but drops its roll. The new region then waits for an expired hold or another region change (**I**).
- A transition lasts at most 0.25 hour with compiled settings, and `H` is at least 1 hour.

### 4.4 Region overrides (player region state, `0x779410`) — V2

The handler runs on a player cell event (event type 0; "cell entered" is I). The only static reference to it that was found is its virtual table slot, so no per-step caller was found (scoped; S4, X).

| Rule | |
|---|---|
| Exterior cell | The stored weather region is cleared first. An interior cell does not clear it, and interior cells have no region list, so an interior keeps the last stored region. |
| Candidates | The regions of the cell. Skip a region with bit 5 (`0x20`) of its form flags set, or whose world space is set and differs from the cell's. A region counts only if at least one of its areas contains the player position (the test stops at the first such area). It must have weather data. |
| Replacement | A candidate replaces the stored region if none is stored, or the stored one has no weather data. Else, if the new override byte is set and the stored one is not, it replaces. Else, if the override bytes differ, it does not. Else it replaces only if its priority is **strictly** higher. |
| Save | The stored region and its remembered weather are saved and restored. |

The position test uses the position at the cell event.

### 4.5 Climate, game start, save, interiors

| Case | Rule | Mark |
|---|---|---|
| Which climate | On a parent-cell change to an exterior cell: the world space's climate (`0x30dad0` walks to the parent world while the world has the "use parent climate" flag, bit `0x10` of `+0xa2`). An interior cell passes none, which keeps the current climate. With no climate at all: form `0x15F`. | V2 |
| Climate change | `SetClimate` (`0x414f00`) acts only if the new climate differs (or its force argument is set). It then resets the weather state and marks the time caches dirty. So the new weather appears without a transition. | V2 |
| Reset (`0x4154c0`) | Current, previous, default, override, sky region and `q0` cleared; flags `0x8` and `0x400000` cleared; clouds, precipitation and sounds reset. | V2 (M, X) |
| Weather at game start | After a reset there is no current weather. The first update uses the rules of 4.3 and S3. No previous weather exists, so `q` = 1. Scripts or a new-game setup can force another weather; not traced. | V2; scripts U |
| Save game | Saved: climate, current, previous, default, override, sky region, hour, last change, `q`, flags, `q0`, three words at `+0x174`, two at `+0x1a4`, mode, reference effects (`0x417b70`; reader `0x417da0`). A load sets flag `0x2`. Moon angles were not seen in this block. | V2 |
| Interior (mode 1) | No selection and no `q` update. `lastChange` stays. On return outside, the age counts from the old change, modulo 24 hours. | V2 |
| World map | At open (`0x9a03e0`) the game saves the player's stored region and the sky state (memory buffer; `0x410900` mode 0), sets sky mode 3 and forces the default-object "map weather" with override, if present. At close it restores the sky state from the buffer (`0x410900` mode 1) and the stored region. | V2 (B, X) |

### 4.6 Set, force, release and instant change

| Entry | Behaviour | Mark |
|---|---|---|
| Set weather (`0x415440`: weather `w`, override flag, accelerate flag; script `Weather.SetActive`, console `sw`) | With no current weather: same as force. Else with override: override = `w`. Without override: default = `w`, and both the sky region and the player's stored region are cleared (the latter until the next cell event). Rule S4 applies the change later, so it blends with `q`. | V2 |
| Accelerate argument | With a transition running and flag `0x8` clear: set `0x8`, `q0 = q`. With a transition already accelerated: no effect. With the argument and no previous weather: `0x8` and `q0` are cleared. | V2 |
| Console argument mapping | `sw` (handler `0x35ce90`): override = (integer argument ≠ 0); accelerate = (a thread-local byte is 0; meaning of the byte U). Script `SetActive`: first bool override, second bool accelerate. | V2 |
| Force weather (`0x415540`; console `fw` queues it, `0x35e4a0` → `0x669110`) | Reset. Then current = `w`, previous = none, `q` = 1, hour = lastChange = now. With the override argument: override = `w`, default = none. Without it: default = `w`, override = none. **The player's stored weather region is also cleared** (`0x415597`). Set flag `0x2`, clear flag `0x1`. | V2 (S4, R, B, X) |
| Why the region clear matters | Without it, a stored region would differ from the reset sky region, and the next update would roll over a forced non-override weather (rule S2 b). An interior cell with its own sky region still gives a region. | I |
| Release override (`0x4155f0`) | If an override exists: clear it and set flag `0x200000`. | V2 (M, S4) |
| Automatic release (rule S1) | An override ends after `H` hours counted from the last **accepted** change. Set weather does not move that time. So an override that is set when the current weather is already older than `H` is dropped in the next update and never shows. If the override equals the current weather, no change is accepted, so the old time counts and release can follow at once (**I** from the rules). A non-override set while the hold is expired and no region applies is replaced in the first update by a new climate roll, which can return the same weather. | V2 (B, X) |
| Instant change on teleport | `MoveToPositionInCell` sets flag `0x10` (`0x75eed3` → `0x411940`) when its last argument is set. Sources of a set argument: the player pending-move byte (`+0x690`), which move requests fill. Console fast travel, script `Game.FastTravel` and the script position move of the player request it; centre-on-cell sets it; one cell-transition function sets it and another passes it directly. At least two move requests carry 0, one of them built in map menu code (that this is map fast travel is a GUESS). A weather accepted in the next weather update then replaces the current one at once, also during a transition. That update clears the flag, with or without a change; an update that does not run (interior mode) leaves it set. Which flag an ordinary load door or map fast travel ends with was not traced. | flag V2 (M, B, X); listed set sources and one zero request V2 (B, X); map menu request V1 (X) |

## 5. Transition fraction

```text
if no current weather:   q = 0
elif no previous:        q = 1
else:
    D = fWeatherTransMin + (incoming DATA byte 3 / 255) × (fWeatherTransMax − fWeatherTransMin)
    q = e / D                             e = h − lastChange, +24 if negative
if flag 0x8:             q = q0 + (q − q0) × (1 + fWeatherTransAccel)
if q > 1:                clear flag 0x8; previous = none; q = 1; q0 = 0
```

**V2** (F, K, S4, B). `D` is in game hours. The acceleration flag is a sky flag set by a set-weather call, not a weather record flag. `q` has no lower clamp. A time jump of more than 24 hours is not counted (**I**).

## 6. Colours, fog and other scalars

### 6.1 Day-part weights — V2 (F, K, N, B)

```text
SB, SE, TB, TE = climate bytes / 6
A = max(0, SB − ext);  B = SE;  C = TB;  Dd = min(TE + ext, 23.99);   M1 = (A+B)/2;  M2 = (C+Dd)/2
slots: sunrise 0, day 1, sunset 2, night 3
h ≤ A or h ≥ Dd : (night, night),    t = 1
A < h < M1      : (sunrise, night),  t = (h−A)/(M1−A)
M1 ≤ h < B      : (sunrise, day),    t = 1 − (h−M1)/(M1−A)
B ≤ h ≤ C       : (day, day),        t = 1
C < h < M2      : (sunset, day),     t = (h−C)/(M2−C)
M2 ≤ h < Dd     : (sunset, night),   t = 1 − (h−M2)/(M2−C)
weights: w0 = q·t, w1 = q·(1−t) (current first, second slot); w2 = (1−q)·t, w3 = (1−q)·(1−t) (previous)
```

`ext` = `fDaytimeColorExtension`. Previous-weather terms are zero when there is no previous weather.

### 6.2 `NAM0` rows (`0x4133e0`, mixer `0x414cf0`) — V2 (K, N)

`row = min(1, Σ wj × byte_j / 255)` per channel, to `Sky + 0xa8 + 12·row`.

| Row | Name (PDB) | Consumer |
|---|---|---|
| 0 | SkyUpper | dome colour 3; moon mask quad colour (not written to colour) |
| 1 | FogNear | fog near colour |
| 2 | Unknown | none found (U) |
| 3 | Ambient | sun light ambient (flash × `fWeatherFlashAmbient`) |
| 4 | Sunlight | sun light diffuse and cloud light copy (flash × `fWeatherFlashDirectional`) |
| 5 | Sun | sun disc |
| 6 | Stars | stars |
| 7 | SkyLower | dome colour 2 |
| 8 | Horizon | dome colour 1 |
| 9 | EffectLighting | sun light effect colour |
| 10, 11 | CloudLODDiffuse, Ambient | cloud light |
| 12 | FogFar | fog far colour; clear colour (section 10) |
| 13 | SkyStatics | address stored in a shader property of some objects; reader U |
| 14 | WaterMultiplier | water system global |
| 15 | SunGlare | sun glare |
| 16 | MoonGlare | moon disc |

Other consumers of the same weights:

- **Directional ambient** (`DALC` colours): `Σ wj × colour_j` after `byte / 255`. How lit geometry uses them: SPEC-1.
- **Image-space block** (SunlightScale, SkyScale and the rest, 20 floats): `Σ wj × block_j` over all 20 floats, where `block_j` is the weather's `IMSP` form for that slot. A missing entry or a missing current weather gives its weight to form `0x167`. Without a previous weather no previous term is added. SPEC-2 says when a cell image space replaces this block (**V2**, H).
- Volumetric-lighting forms use the same weights; their blend body is U.

### 6.3 Cloud layer colour and alpha (`0x413520`)

For layer `i < numLayers`. `numLayers` is the layer count of the cloud object, taken from the cloud mesh (29 with the shipped mesh, at most 32). `LNAM` is the weather's own count.

- Layer index used in a weather: `i` if `i < LNAM`, else 0. With `LNAM ≤ 0`: fallback colours (slot 0 `0x5b4b46`, 1 `0x9b9b9b`, 2 `0x6c5953`, 3 `0x1c140f`; packed as `PNAM`, lowest byte = R, so slot 0 is R `0x46`, G `0x4b`, B `0x5b`) and alpha 1.0. **V2** (K; accessor `0x308250` matched; byte order R).
- **Black substitution** (**V2**, S4, R, B): only when a previous weather exists. Before mixing, a packed colour of 0 is replaced, in this order: current-first by previous-first, current-second by previous-second, then previous-first by current-first (after its replacement), previous-second by current-second (after its replacement). With no previous weather nothing is substituted. `NAM0` rows do not do this.
- Colour = mixer of section 6.2. Alpha = `Σ wj × alpha_j` (**V2**). Alpha is not substituted.
- Flash is applied to layer 0 only, and only with no previous weather (**V2**).

### 6.4 Fog scalars — V2 (F, K, N)

`w = (h−A)/(B−A)` on `A<h<B`; 1 on `[B,C]`; `(Dd−h)/(Dd−C)` on `C<h<Dd`; else 0. Value = `w·day + (1−w)·night` for each weather, then `q × current + (1−q) × previous`. These scalars do **not** use `wj`. Fog colours are rows 1 and 12. Application: SPEC-1.

### 6.5 Flash (colour side) — V2 (K, N, B)

Only when no previous weather exists and the flash amount `f > 0`: add `min(1, f × factor)` to each channel, then limit each channel to [0, cap byte / 255] with the caps of `DATA` bytes 12–14. A channel above its cap is lowered to the cap during a flash. With `f ≤ 0` the normal limit applies. Section 8.9 gives `f`.

### 6.6 Wind (sky mode 3, current weather present)

- Speed `Sky+0x18c = q × current byte0/255 + (1−q) × previous byte0/255` (no previous: current only). **V2** (K, B). It is copied to a shader global (`0x20d6818`) when it changes.
- Direction `Sky+0x190` is chosen only in an update with flag `0x1` or `0x2`, or during a load, from the current weather only (no blend): `base = byte17 × 360/255`, `R = byte18 × 90/255` degrees. If `R > 0`, draw four uniform offsets in [−R, R) and keep the one with the smallest magnitude; else offset 0. Direction = base + offset in radians, wrapped once into [0, 2π). **V2** (S4, R, B).
- A second global (`0x33d3d20`) receives the direction only in an update where the speed changes, and **before** a new direction is stored in that update, so it receives the older direction. A second writer in `0x413f10` has the same pattern. **V2** (R, B, X). World meaning of the angle: U.

## 7. Scene graph, meshes and depth

| Item | Rule | Mark |
|---|---|---|
| Root | A multi-bound node named `Sky`; the engine copies the camera root translation to it each frame (`0x657dd0`). No rotation is written, so sky axes are world axes (I). The root carries an alpha property with source alpha / inverse source alpha. | V2 (S4, R, B) |
| Weather node | A node named `Weather` (precipitation parent) follows the camera the same way. | V2 (S4, R, B) |
| Children | Atmosphere, stars, sun root, clouds root, moons root (parent of both moons), aurora. | V1 |
| Moons root transform | No transform write on the moons root was found (scoped static search). | V1 |
| Meshes | `Meshes\Sky\Atmosphere.nif` (one shape, sky type 2; radius about 500, height about 270). `Meshes\Sky\Clouds.nif` (29 shapes, type 3; radius about 500). Stars: climate night-sky model; the shipped default `Stars.nif` has four type-5 shapes with radius about 16. Aurora: weather model. Sun, glare, query and moon quads are built in code. Use the mesh files of the player's install. | V2 (shipped files) |
| Depth | Every sky vertex shader writes clip z = clip w, so every sky vertex has depth 1.0 before raster bias. Mesh size does not matter for depth. | V2 (K) |
| Scale | In the sky code range, node scale is written only for the occlusion query copy (0.04) and the glare node (section 8.5). | V2 (S4, X; scoped search) |

## 8. Objects

### 8.1 Atmosphere dome (type 2, technique Sky)

- Colour per vertex = `k × (r·row8 + g·row7 + b·row0)` with vertex colour `(r,g,b)`; alpha = vertex alpha (**V2**, K, N).
- The shipped dome carries these weights: horizon colour at the bottom, lower-sky colour at mid height, upper-sky colour at the top, mixed smoothly. Vertex alpha is 0 on the bottom rim and rises to full at a height of about 4 percent of the radius. Under that rim the clear colour shows through (**V2**, shipped mesh).
- `Atmosphere::Update` (`0x40b950`) also writes the fog property, in every mode that installs it. It copies the near and far fog colours in all cases. A byte at atmosphere `+0x30` gates the copy of the fog near, far, power and maximum scalars, and also an adjustment of the camera far value (**V2**, F, X). When that byte is set was not traced.

### 8.2 Clouds (type 3)

| Rule | Text | Mark |
|---|---|---|
| Layer index | The accepted geometry children of the clouds mesh root, in child order, up to 32. Shipped mesh: 29 layers, index 0 to 28; index 28 is the last child. | V2 (child order rule read by S4, B) |
| **Layer 28, horizon ring** | A vertical ring at the mesh radius from slightly below the horizon to about 3 degrees above it. Vertex alpha full at the bottom, 0 at the top. No special code was found: weather layer 28 gives its texture, colour, alpha and speed like any layer. If a weather's `LNAM` is 28 or less, colour, alpha and speed come from layer 0; without a texture for layer 28 the layer is disabled. Its colour is not the fog colour. | V2 |
| Vertex colour | Shipped cloud shapes have red = 1 and green = blue = 0, so output colour = `k × layer colour`; alpha = vertex alpha × layer alpha. | formula V2; mesh V2 |
| Scroll speed per axis | `s = −S + b × 2S/254`, `S = fWeatherCloudSpeedMax`. U uses `QNAM` (`+0x240`), V uses `RNAM` (`+0x220`). Index = layer if layer < `LNAM`, else 0; `LNAM ≤ 0` gives byte `0x33` on both axes. Mix `q·current + (1−q)·previous`. | V2 (K, B) |
| Offset | Per layer, per update: `offset += speed × 0.1 × frame time`. The offset accumulates (table `0x3436510`) and is added to the mesh UV. Modes 2 and 3 only. | V2 |
| Textures, steady | Slot A (property `+0x98`) = current weather texture; slot B (`+0xa0`) = the default texture; fade `f` = 0; a disabled layer is hidden. | V2 |
| Textures, in a transition | Slot A = outgoing (previous) texture, slot B = incoming; `f = max(q, 0.00001)`. Layer enabled only in the incoming weather: A = default, B = new, shown. Enabled only in the previous: B = default. Disabled in both: unchanged. | V2 |
| "Default" texture | One engine placeholder texture object, used as a marker (read as a black placeholder by B). A shown layer does not sample it in CloudsLerp or CloudsFade. | V2 (S4, R, B) |
| Technique | `f ≤ 0`: Clouds, samples slot A. Both non-default: CloudsLerp, `mix(A, B, f)` on RGBA. One default: CloudsFade; if A is default it samples B with alpha × `f`, else it samples A with alpha × `(1 − f)`. | V2 |

### 8.3 Stars (type 5)

- Alpha: 1 for `h ≤ A` and `h ≥ Dd`; `(M1−h)/(M1−A)` on `A<h<M1`; 0 on `[M1,M2]`; `(h−M2)/(Dd−M2)` on `M2<h<Dd` (**V2**, K, B).
- Hidden when alpha is 0 or row 6 is (0,0,0) (**V2**).
- Rotation: `θ = 2π × fmod(days + h/24, fStarsRotateDays) / fStarsRotateDays`. The node's local rotation is the axis-angle matrix about the normalised setting axis; for axis (0,0,1) it is rows `(c, s, 0)`, `(−s, c, 0)`, `(0, 0, 1)` with column vectors (angle, axis, matrix elements **V2**; column convention I).
- Colour = `k × row6` (no vertex colour). Pixel: `rgb = 1.5 × (tex.rgb × colour + y)`, `a = tex.a × alpha × e`.
- `e` is a **horizon fade**: `e = sat((z_v − z_eye) / 17)`, where `z_v` is the vertex height in the camera-relative world (**V2**, S4, R, B). `z_eye` is the eye height in the same space: the current view position minus the camera position adjustment (**V1**, R). With the camera-centred root, `e = sat(z_local / 17)` for the shipped mesh.

### 8.4 Moons (types 6 disc, 7 mask)

| Rule | Text | Mark |
|---|---|---|
| Existence | Climate moon byte: bit 7 → Masser, bit 6 → Secunda (the PDB enum labels are reversed). | V2 |
| Phase check | The check runs once per new game day while sky flag `0x20` is set, and in every update during a load. The constructor sets the flag. One time-skip loop (in `0x75a390`; that it is the serve-time path is a GUESS) clears it for its ticks and sets it again. The other callers of the sleep and wait tick do not. | V2 (B, X) |
| Phase | `L = byte & 63`; if `L ≠ 0`: `phase = floor((days mod 8L) / L)`. Both moons use the same phase. Texture `Textures\Sky\{moon}_{phase}.dds`, `moon` = `Masser` or `Secunda`; phase names 0 to 7: full, three_wan, half_wan, one_wan, new, one_wax, half_wax, three_wax. | V2 (K, M `0x40d370`) |
| Texture swap | The phase texture loads at once at creation in sky mode 2 or 3, on entry to those modes from none or interior (`0x4173f0`), and for a phase change during a load. A phase change in normal play loads only while both the disc alpha and the mask alpha are 0 or less. | V2 (B, X) |
| Angle `θ` (degrees) | First update after creation: `θ = 90 + speed × 60 × h`. Each later update: `θ += speed × 60 × Δh` (`Δh` +24 if negative). Wrap to [0,360). Masser 15°/h, Secunda 18°/h. The angle is session state, not a function of the date. | V2 |
| Quad | Square, half size `S` = size setting, vertices in local XY, vertex colour (1, 0, 0, 1), UV (0,0) at (−S, +S), (0,1) at (−S, −S), (1,0) at (+S, +S). The mesh node has local translation (0, 512, 0) and a +90° rotation about X, so the quad stands vertical at distance 512 along +Y, faces the origin, and has UV v downward. | V2 (S4, R, B; colour B, X) |
| **Rotation axes** | The moon root rotation is `M = Rx(θ) · Rz(φ)`, `φ` = ZOffset, with `Rz(φ)` rows `(cosφ, sinφ, 0)`, `(−sinφ, cosφ, 0)`, `(0,0,1)` and `Rx(θ)` rows `(1,0,0)`, `(0, cosθ, −sinθ)`, `(0, sinθ, cosθ)`; column vectors `world = M · local`. | elements V2; column convention I |
| Result | Centre = `512 × (sin φ, cos φ cos θ, cos φ sin θ)` (x east, y north, z up). It is above the horizon for 0 < θ < 180 and highest at θ = 90 with elevation `90 − φ` toward +x. It moves from the +y side to the −y side and stays at x > 0. | I (derived) |
| Angular half size | `atan(S/512)`: Masser 10.4°, Secunda 4.5°. The visible disc depends on the texture. | I |
| Disc alpha | `P` start, `Q` end: 0 below `Q`; `(θ−Q)/(P−Q)` to `P`; 1 to `180−P`; `((180−Q)−θ)/(P−Q)` to `180−Q`; 0 above and for θ > 180. | V2 |
| Mask alpha | `αs = min(star alpha, profile)`: the profile ramps from `Q − early` to `Q` and from `180−Q` to `180−Q+early`, and is 1 between. | V2 |
| Visibility | Both quads hidden when both alphas are 0 or less **or row 16 is (0,0,0)**; each quad is also hidden when its own alpha is 0. | V2 |
| Disc colour | `k × row16`, alpha = disc alpha; no `y` term. | V2 |
| **Mask texture and mask alpha** | The mask quad uses `Textures\Sky\MoonShadow.dds` (same size and placement as the disc). The mask pixel shader outputs the texture only: it ignores the vertex-stage colour and alpha, and its row-0 colour is not written. So `αs` only decides whether the mask draws (`αs > 0`). The shape of the depth mask comes from the texture alpha against the alpha reference (9.1). The mask writes nothing to colour output 0; it writes depth, and outputs 1 and 2, where the alpha test passes. | texture V2 (K, R, B); alpha use V2 (S4, R, B) |
| Light | Moons do not light the scene. No sun/moon light switch was found. | V2 scoped (K) |

### 8.5 Sun, sun light and glare

**Position and light** (**V2**, K, O, B):

```text
hT = fSunAlphaTransTime/2;  MR = (SB+SE)/2;  MS = (TB+TE)/2          (no extension)
Ds = MR − hT;  De = MS + hT
day   (Ds < h < De):  u = 1 − 2(h−Ds)/(De−Ds)
night:                u = 2τ/(24 − (De−Ds)) − 1,  τ = h − De  (h + 24 − De before dawn)
X = u × fSunXExtreme
disc and glare node translation = (X, fSunYExtreme, |fSunXExtreme| − |X|)
light vector = normalise(−X·kd, −fSunYExtreme·kd, fSunZExtreme),  kd = fSunDirXExtreme/fSunXExtreme
   written into the first column of the light's local rotation (the direction the light travels, I)
disc alpha α: 0 for h < MR−hT and h > MS+hT; rises over [MR−hT, MR+hT]; 1; falls over [MS−hT, MS+hT];
   exactly at the two outer edges the code returns 1
```

The disc direction and the light direction **differ**: the light's vertical component is fixed, the disc height is not (example E3). Do not derive one from the other. The same light keeps moving at night.

**Quads.** Both nodes are billboard nodes (face mode value 4; the community meaning "rigid face center" is I) under the sun root. Disc quad half size `fSunBaseSize` (425), glare half size `fSunGlareSize` (600), vertex colour (1, 0, 0, 1), UV as the moon. A copy of the disc quad with node scale 0.04 is the occlusion query geometry. At a translation distance of about 400 the quads are very large; the visible size comes from the textures. (**V2**, S4, R, B)

| Draw | Colour | Alpha | Adds `y`? |
|---|---|---|---|
| Disc (type 0, technique Texture) | `k × row5 × fSunBoost` | `α` | yes |
| Glare (type 1, technique SunGlare) | `k × row15 × fSunGlareMultiplier` | `Σ (DATA byte 4/255) × w × α` over current and previous, with `w = q` for current and `1 − q` for previous (**not** the day-part weights) | no |

(**V2**, K, N, B)

**Occlusion** (`0x1520db0`, `0x1520f70`; **V2**, S4, R, B):

- The query draws the small quad with technique SunOcclude (depth test, no depth write, nothing on colour output 0) inside a GPU occlusion query. Up to three slots exist. Slot 1 is issued after stage B of the main colour pass. A second call with slot 2 uses another camera and render target (`0x1537e99`; purpose U).
- Per finished slot: pixel count `n`; `value = 1` if `n = 0`, else `1 − min(n, 1500)/1500`.
- When all issued slots are ready: occlusion = the largest value over the slots; if the smallest pixel count is below 10, occlusion = 1. The value depends on the resolution.

**Glare node scale** (`0x41c52f`; **V2**, R, B, X for all branches):

```text
target = (1 − occlusion)²
step   = fSunReduceGlareSpeed × frame time        (unit of the time argument: seconds, I)
if occlusion < 1 and target ≥ fSunMinimumGlareScale:
      s = min(s + step, target);  node shown      (a rise is rate limited; a lower target is taken at once)
elif  s − step ≥ fSunMinimumGlareScale:
      s = s − step;  node shown                   (rate-limited fall)
else: node hidden;  s = 0
node scale = |s|
```

A rising node is shown even while `s` is below the minimum. The node scale changes the glare quad size, not its colour. A glare quad without a texture is also hidden. Example E5.

Lens flare of the weather: interface in SPEC-2 only.

### 8.6 Aurora (interface) — `0x414780`

- Active if the current or previous weather has an aurora model; else the aurora node is removed. When no aurora node exists, the current weather's model is loaded if present, else the previous one. An existing node is kept while the alpha stays above 0; a new model loads only after the node is removed. (**V2**, B, X)
- Weather factor: 1 with no previous weather, or when both have the same model path; else `q` if the current weather has a model of its own; else `1 − q`. (**V2**)
- Day factor: with weather flag 16, 1. Else 0 for 5.5 ≤ h ≤ 19.5; ramp to 1 over 19.5–20.0; 1 until 5.0; ramp to 0 over 5.0–5.5. (**V2**)
- Alpha = product; it is applied to the effect-shader base colour alpha of the whole model; the node is removed when the product is 0 or less. With weather flag 32 the model copies the sun root translation. (**V2**)
- Drawn by the Effect shader family (**V2**, K). Effect states: SPEC-2. Place in frame: sorted blended list (**I**).

### 8.7 Precipitation (interface) — `0x40eed0`, V2 (S4, R, B)

| Item | Rule |
|---|---|
| Data | `BGSShaderParticleGeometryData` of the weather: settings array index 9 particle type (0 rain, 1 snow), 10 box size (integer), 11 density (float; magnitude ≤ 0.0001 becomes 1.0). Index names are public (I). |
| Gate | Sky mode 3 and sky flag bit `0x4` clear; else both densities 0. |
| Thresholds | `tin = 0.999 × current byte6/255`; `tout = 0.999 × previous byte7/255 + 0.001` (0.001 with no previous). |
| Current density | `q > tin ? (q − tin)/(1 − tin) × density_current : 0` |
| Previous density | `q < tout ? (1 − q/tout) × density_previous : 0` |
| Objects | On a change or load, the old geometry becomes "previous"; a new one is built from the data with the wind angle and `fPrecipWindMult × wind speed`, attached to the `Weather` node. |
| Other consumers | Water splashes toggle with rain; an occlusion depth map (`bUsePrecipitationOcclusion`) exists (`0x40f890`, `0x40ea30`). |
| Not covered | Particle shader, particle counts, occlusion map, draw states. The particle draw in the sorted list is **I**. |

Initial values of the precipitation object (matched `0x40eda0`): box 4096, both densities 1.0.

### 8.8 Visual effect and sky statics (interface)

- Weather reference effect (mode 3): the current weather's effect starts when `q ≥ byte15/255`. The previous effect is removed when `q ≥ byte16 of the previous weather/255` (at once with no previous weather). On a change the current effect moves to "previous". (**V2**, S4, R, B)
- Sky statics (weather static list) toggle placed references; not covered (U).

### 8.9 Thunder and lightning (`0x414180`, sounds created at `0x4178d0`) — V2 (S4, R, B)

1. On a change or load, one sound entry per weather sound of the current weather is added. A global counter `N` counts the thunder entries (type 3) of all entries alive.
2. Sky modes 2 and 3. For each thunder entry that is not playing, at most once per 30 ms (system tick, I): draw `r`; fire if `r mod (byte10 × N) = 0`, where `byte10` is the rarity byte of the entry's weather. Rarity 0 would divide by zero in the code (section 15).
3. Fade amount `x`. Entry of the current weather: `tin = 0.999 × byte8/255`; `x = q ≥ tin ? (q − tin)/(1 − tin) : 0`. Entry of the previous weather: `tout = 0.999 × byte9/255 + 0.001`; `x = q < tout ? 1 − q/tout : 0`.
4. If `|x| > 0.0001`: play the sound with volume `x`; set `flash = x` and `flashStart = now`.
5. Later in the **same** sky update the decay step overwrites the value: if `flash > 0`, `flash = max(0, 1 − (now − flashStart)/(fWeatherFlashDuration × 1000))`. In the firing frame this is **1**. So the flash strength does **not** scale with `x`. The colour update of the next frame sees the decaying value that starts at 1.
6. The colour effect exists only with no previous weather (section 6.5). During a transition the sound plays and no colour changes.

No bolt geometry, model field or effect spawn for weather lightning was found in the sky update, the weather fields it reads, or the readers of `DATA` bytes 8–10 (scoped negative, S4 and B; scripts and data-driven effects, including the weather visual effect, are not excluded). `BSProceduralLightningController` exists as a mesh controller; no link from the weather code was found.

## 9. Techniques, shader arithmetic and render state

### 9.1 Pass selection (`0x1553550`) — V2 (K, B)

| Technique | Pass id | Sky object type | Pixel output (colour output 0) |
|---|---|---|---|
| 0 SunOcclude | 2 | query | black, alpha 1 |
| 1 SunGlare | `0x5c006072` | 1 | `rgb = d + tex.rgb × v.rgb + y`; `a = tex.a × v.a` |
| 2 MoonAndStarsMask | `0x5c00005f` | 7 | `tex`; discard if `tex.a < alpha reference` (the first stage stores 0.502, float `0x3f008081`, before the sky ids) |
| 3 Stars | `0x5c000060` | 5 | `rgb = 1.5 × (tex.rgb × v.rgb + y)`; `a = tex.a × v.a × e` |
| 4 Clouds | `0x5c000062` | 3 | `tex.rgb × v.rgb + y`; `tex.a × v.a` |
| 5 CloudsLerp | `0x5c000063` | 3 | `T = mix(tex0, tex1, f)`, then as 4 |
| 6 CloudsFade | `0x5c000064` | 3 | as 4 with `a = tex.a × g × v.a`, `g` = `f` or `1−f` (8.2) |
| 7 Texture | `0x5c000061` | 0, 6, others | as 4 |
| 8 Sky | `0x5c00005e` | 2, 4 | `rgb = d + v.rgb + y`; `a = v.a` |

`v` = vertex-stage colour: `k × (c.r·C13 + c.g·C14 + c.b·C15)`, `a = c.a × C13.a`, with `c` the mesh vertex colour. Types 0, 1, 3, 5, 6, 7: `C13` = property colour, `C14 = C15 = 0`. Type 2: `C13, C14, C15` = rows 8, 7, 0 with alpha 1. Type 4: zero RGB, alpha 1 (no mesh found). Stars: `v = k × C13`. Dither `d = noise(pixel/8).r / 32 − 1/128`.

**Every sky pixel shader also writes two more outputs** (**V2**, S4, R, B): output 1 = screen motion `(current − previous) × (−0.5, +0.5)` from current and previous clip positions, and output 2 = the constant `(0.5, 0.5, 0, 0)`.

### 9.2 The added term (SkyScale) — V2 (K, N, H, S4)

`y = k × SkyScale` in pixel constant `cb2[0].y`, for sky types 0, 2, 3, 4, 5, 7; `y = 0` for types 1 and 6. The type 7 shader does not read it. SkyScale is the float at image-space manager `+0xe4` = image-space working block offset `0x1c` = `HNAM` float 8 (PDB community field name "skyScale"). It is the **blended** value: the day-part and weather weights over the `IMSP` image spaces (or a cell image space where SPEC-2 selects it); image-space modifiers can then change it (it is one of the 12 modified floats). The constructor default is 1.5. It affects only sky pixels. It is additive, applied after the texture multiply and inside the ×1.5 of stars.

`cb2[0].x` = property fade (`+0xb8`) for type 3, inverted for CloudsFade fade-out.

### 9.3 State per draw

| Technique / type | Depth | Blend (colour) | Write mask mode set by the technique | Raster bias slot (constant, slope) | Mark |
|---|---|---|---|---|---|
| 8 Sky (dome) | test ≤, no write | src α, 1−src α | none set (inherited) | 0 | V2 |
| 2 Mask | test ≤ **and write**; alpha test on | off | **mode 0**: nothing on output 0; outputs 1 and 2 are written | 3 (−3, −0.4) | V2 |
| 3 Stars | test ≤, no write | src α, **one** | none set | 0 | V2 |
| 7 Texture, types 0 and 6 (discs) | test ≤, no write | src α, **one** | none set | 2 (−9, −1.2) | V2 |
| 4–6 Clouds; 7 other types | test ≤, no write | src α, 1−src α | none set | 2 | V2 |
| 1 Glare | **off** | src α, one | mode 11 (output 0 only) | 0 | V2 |
| 0 Occlude | test ≤, no write | — | **mode 0**: nothing on output 0 | 0 | V2 |

The bias pair is (constant depth bias, slope-scaled depth bias) with clamp −100. Negative means nearer. With a cleared depth of 1 and a less-or-equal test, the biased mask depth makes the later stars (bias slot 0) fail, and the discs and clouds (slot 2, nearer than slot 3) pass (**I** from the values). The unit of the constant term depends on the depth format (U).

After each technique the restore writes blend 0, write mask mode 1 (RGB of output 0), depth test and write, alpha test off and bias 0 (`0x1552190`, **V2**). In the write mask table, modes 0 and 1 restrict output 0 only; outputs 1 to 7 keep all channels (`0x102abd0`, **V2**, B, X).

**Write mask at the first sky draw** (**V2** static, S4, R, B): techniques 3 to 8 set no mask. On the ordinary path, the stores found before the sky ids leave mode **1**: the depth stage ends with mode 1 (`0x1539129`, `0x1539904`), the shadow mask stage ends with mode 1 (`0x1539ed4`), the shader restores found in this search store 1, and the first stage stores another mode only after the sky range (`0x151f18f`). Geometry groups drawn before the sky were not enumerated pass by pass. The multi-target flag is set only in later stages, and its image value is 0, so outputs 1 and 2 keep a full write mask: sky pixels write motion and the constant output. Run-time state was not observed.

**Samplers** (**V2**, S4, R, B): cloud, moon, sun and star textures use address enum 3 (wrap) and filter enum 1 (meaning bilinear, no mip blend; I). The dither noise texture is in slot 2 with address enum 3 (wrap) and filter enum 0 (point).

## 10. Frame order and interfaces to composite and HDR

1. Clear colour = `NAM0` row 12 × the literal 0.83332998 (`0x1869de8`), alpha 1. All three sky update paths that write it use the literal, not `k` (**V2**, K, R, X). With the file value of `k` the difference is about 3.3 × 10⁻⁶ of the row value; after `sfbr` it is not small.
2. Stage A ids, ascending (**V2**, K, B): dome `5e` → moon mask `5f` → stars `60` → discs `61` → Clouds `62` → CloudsLerp `63` → CloudsFade `64` (all `0x5c0000xx`). The mask writes depth before the stars test it (purpose "hide stars behind the moon" **I**). All lit geometry has drawn before, so the sky fails the depth test behind it (static only).
3. **Order inside one id.** Pass registration puts a pass at the head of its list (`0x155f024`, **V2**), so draws inside one list run in reverse registration order. There are five sub-lists by cull and alpha mode, drawn in ascending index (`0x155ff40`, `0x155fed0`, **V2**). Which sub-list each sky pass joins, and the registration order of the sky shapes, were not traced. If registration follows the child order, cloud layers in one list draw from the highest index to the lowest (**I**). Additive and depth-only draws do not depend on the order; blended clouds do.
4. Cloud techniques reorder layers during a transition: all plain-Clouds layers draw before all CloudsLerp layers, and those before all CloudsFade layers (**V2** from the id order).
5. Composite: it reads the depth copy made after the prepass (binding and formula **V2**, Z, H). That sky pixels keep the cleared value in that copy and take `out = sat(AO × scene)` with no fog and no second `k` is **I**. AO on sky pixels is U. The cloud and mask depth bias does not change this.
6. Stage B: sorted blended draws, then the sun glare alone (id `0x5c006072`), additive, no depth test (**V2**, K, H). The glare is not clipped by geometry; its visibility comes only from the occlusion value.
7. Scene target `R11G11B10_FLOAT` by default; no alpha is kept (**V2**, H). Glare and later additive draws can exceed 1.
8. HDR tonemap: SPEC-2. Nothing sky specific.

## 11. Variant table

| Variant | Selector | Change |
|---|---|---|
| Full sky | mode 3 | all of the above |
| Dome only | mode 2 | selection and colours run; wind, precipitation and reference effects do not |
| Interior | mode 1 | only colours, fog, atmosphere, sun and clear colour update; no selection (unless a load) |
| Loading a save | load bit | no random roll for a loaded current weather; region memory resynced; wind, sounds, textures rebuilt |
| No previous weather | `q = 1` | flash can colour the sky; clouds use technique Clouds |
| Transition | previous present | weather blend; cloud Lerp or Fade; no new change |
| Accelerated | flag `0x8` | section 5 |
| Teleport or transition | flag `0x10` | a change in the next weather update is immediate |
| Override | override set | no roll; timed release |
| Region present | region | region list instead of climate list |
| Moonless climate | moon bits clear | no moon objects |
| No aurora, precipitation or thunder data | fields empty | object absent |
| Glare hidden | section 8.5 | no glare draw |
| `sfbr` or interface | `k` change | sky colour and `y` scale with `k`; the clear colour does not |
| Water reflection | `bReflectSky:Water` | the reflection pass uses the sky root; not covered |

## 12. Worked examples

**All record values, random numbers, pixels and texture samples are invented (example only).** Settings are compiled values. `k` is the float32 file value.

### E1. Selection roll (example only)

Invented climate list: A 60, B 30, C 10 (sorted in that order). Volatility 100 → `H` = 155 × 22/255 + 1 = **14.3725 h**. Current weather B, age 15 h, no region, no transition. Random 2882400173 mod 100 = **73** → B (range 60–89): no change, `lastChange` unchanged, so the next update rolls again. Resulting distribution of the next weather: A 6/7, C 1/7.

### E2. Transition blend (example only)

Incoming byte 128 → `D` = 0.01 + 128/255 × 0.24 = **0.130471 h**. Age 0.05 h → `q` = **0.383228**. Day-part `t` = 0.75 → weights (0.287421, 0.095807, 0.462579, 0.154193). Row colours (current first, current second, previous first, previous second) = (200,150,100), (180,100,60), (100,100,100), (80,60,40) → row = **(0.522835, 0.424327, 0.340848)** (as bytes 133, 108, 87). Cloud alphas 1.0, 0.8, 0.4, 0.2 → **0.579937**. Accelerate called earlier at `q0` = 0.2: `q'` = 0.2 + (0.383228 − 0.2) × 5 = 1.116141 → above 1: the transition ends.

### E3. Sun, moon, stars, clouds, precipitation (example only)

| Item | Input | Result |
|---|---|---|
| Sun | `u` = 0.5 | node (200, 25, 200); direction toward the light (0.888889, 0.111111, 0.444444): about 26° high, disc about 45° |
| Masser | first update at `h` = 22 | θ = 90 + 330 = 420 → **60°**; centre (293.671, 209.703, 363.216); elevation 45.19°; 54.47° from +y toward +x; disc alpha 1 |
| Moon alpha | θ = 50 | Masser 0.5, Secunda 0.6667 |
| Stars | days 10, `h` 22 | θ = 262.5°; vertex 8.5 above the eye → `e` = 0.5 |
| Cloud speed | current byte 200, previous 51, `q` 0.383228 | speeds 0.057480 and −0.059843 → −0.014881; offset step at 1/60 s: −2.480e−5 |
| Precipitation | byte 100 for both thresholds | `tin` 0.391765, `tout` 0.392765; `q` 0.2: current 0, previous factor 0.490789; `q` 0.6: current factor 0.342360, previous 0 |

### E4. A sky pixel to bytes (example only)

SkyScale 0.2 → `y` = **0.166667**. Noise 0.25 → dither 0. Rows 8, 7, 0 = (180,200,220), (140,170,215), (80,120,190); row 12 (150,175,205). Dome vertex weights (0.6, 0.4, 0), alpha 0.8. One cloud layer: colour (200,205,215), layer alpha 0.9, vertex alpha 0.5, texture sample (0.9, 0.9, 0.9, 0.8). AO 1.

| Step | Value |
|---|---|
| clear = row12 × 0.83332998 | (0.490194, 0.571893, 0.669932) |
| dome `v` | (0.535948, 0.614379, 0.712418) |
| dome source `v + y + d` | (0.702614, 0.781046, 0.879085) |
| blend over clear, a 0.8 | (0.660130, 0.739215, 0.837254) |
| cloud `v = k × colour` | (0.653595, 0.669935, 0.702614) |
| cloud source `tex × v + y`; alpha 0.8 × 0.5 × 0.9 = 0.36 | (0.754902, 0.769608, 0.799020) |
| blend | (0.694248, 0.750157, 0.823490) |
| composite `sat(AO × C)` | same |

HDR step (SPEC-2 formulas, restated for this case): `Lm = max(lum(c), 0.00001)`, `Ls = Lm × A.y / A.x`, `P = 1/(1.1 × White)²`, `Lt = Ls(1 + Ls·P)/(1 + Ls)`, `col = c × Lt/Lm + bloom × sat(threshold − Lt)`, `L1 = lum(col)`, `col = L1 + Sat × (col − L1)`, `col = Con × (Bri × col − A.x) + A.x`, `out = sat(col)^(1/fGamma)`, byte = round(255 × out) (byte rounding I). Inputs (invented): White 1.0, threshold 0.5, saturation 1.1, brightness 1.0, contrast 1.05, no tint, no bloom, adapted pair `A` = (0.4, 0.4), `fGamma` 1, temporal pass treated as identity.

| Step | Without glare | With one glare draw |
|---|---|---|
| Glare: `v = k × (255,230,200)/255 × 2` = (1.666667, 1.503268, 1.307190); sample (0.25, 0.25, 0.25, 0.4); alpha 0.4 × 128/255 = 0.200784; dither 0 | — | source (0.416667, 0.375817, 0.326797) → scene (0.777908, 0.825615, 0.889106) |
| `Lm = Ls` | 0.743563 | 0.820055 |
| `P`; `Lt` | 0.826446; 0.688529 | 0.826446; 0.755929 |
| after saturation | (0.638297, 0.695245, 0.769941) | (0.713193, 0.761566, 0.825945) |
| after brightness and contrast | (0.650212, 0.710007, 0.788438) | (0.728852, 0.779645, 0.847242) |
| **bytes** | **(166, 181, 201)** | **(186, 199, 216)** |

### E5. Glare scale over nine updates (example only)

Frame time 0.05 (invented) → `step` = 4 × 0.05 = 0.2. Start `s` = 0, node hidden. Glare half size 600.

| Update | Occlusion | Target | Branch | `s` | Shown | Quad half size |
|---|---|---|---|---|---|---|
| 1 | 0 | 1.0000 | rise (limited) | 0.2000 | yes, although below 0.25 | 120.0 |
| 2 | 0 | 1.0000 | rise (limited) | 0.4000 | yes | 240.0 |
| 3 | 0.1 | 0.8100 | rise (limited) | 0.6000 | yes | 360.0 |
| 4 | 0.1 | 0.8100 | rise (limited) | 0.8000 | yes | 480.0 |
| 5 | 0.1 | 0.8100 | reaches target | 0.8100 | yes | 486.0 |
| 6 | 0.35 | 0.4225 | **immediate drop** | 0.4225 | yes | 253.5 |
| 7 | 0 | 1.0000 | rise (limited) | 0.6225 | yes | 373.5 |
| 8 | 1 | 0 | fall (limited) | 0.4225 | yes | 253.5 |
| 9 | 1 | 0 | 0.2225 < 0.25: hide | 0 | no | 0 |

A renderer that limits the fall in update 6 to one step would show 0.61 instead of 0.4225.

## 13. End-to-end chain

1. The climate (from the world space) and the weather region give one weighted list; the volatility byte gives how long a weather holds; a roll, a script or an override gives the current weather.
2. `q`, from game time and the incoming weather's byte, plus the day-part weight `t`, give four weights `wj`.
3. `wj` give the 17 colour rows, the cloud layer colours and alphas (29 layers with the shipped mesh), DALC and the weather image-space block with SkyScale (section 9.2 and SPEC-2 say when a cell image space replaces it). The fog colours are rows 1 and 12. The fog distances, powers and maxima do **not** use `wj`: they use their own day weight and `q` (6.4). Separate rules give sun, moons, stars, scroll, aurora, precipitation and flash.
4. Stage A draws, in order, dome, moon masks, stars, discs and clouds, all at vertex depth 1 (masks, discs and clouds with a raster bias). With `v` the vertex-stage colour and `y = k × SkyScale`: dome `v + y + dither`; mask: no scene colour (depth and the two extra outputs); stars `1.5 × (tex × v + y)` with the horizon fade in alpha; sun disc `tex × v + y`; moon disc `tex × v`; clouds `tex × v + y`. The composite saturates these pixels and adds no fog (I). After the composite the glare adds `tex × v + dither`; the occlusion result changes the glare node size, not its colour.
5. HDR tonemaps the scene with the same blended image space and writes bytes.

## 14. Open items

| # | Open |
|---|---|
| O1 | Order of sky passes inside one pass id: the registration order of the sky shapes and the sub-list that each pass joins. It matters for overlapping cloud layers. |
| O3 | Meaning of the second occlusion query slot and of its camera and target. |
| O4 | Run-time write mask at the first sky draw (static candidate: RGB). |
| O5 | AO on sky pixels; dither noise texture identity; sampler filter meaning. |
| O6 | Particle and effect shader states for precipitation, aurora and weather visual effects. |
| O7 | Volumetric-lighting form blend; lens flare internals; sky statics; readers of rows 2 and 13. |
| O8 | Source of the console `sw` accelerate byte; script force paths; new-game weather forcing. |
| O9 | Writer of sky flag bit `0x4` (precipitation off); flag `0x80` (hide sky). |
| O10 | Column-vector convention of the moon and star matrices; world meaning of the wind angle; billboard mode meaning; face culling of sky quads. |
| O11 | Water reflection path of the sky; interior sky (modes 1 and 2) light rotation from the cell template. |
| O12 | Run-time values: GMST overrides in data files, player INI files, console changes, mods. Plugin records were not read. |
| O13 | What dispatches the region handler; whether anything re-tests regions while the player stays in one cell. |
| O14 | `0x413f10` was read only for its wind writes. |
| O15 | Whether any code writes cloud, star, sun or moons root node transforms outside the ranges read. |
| O16 | Colour space of the sky texture views (sRGB decode or not). |
| O17 | Image-up direction of the sun billboards. |
| O18 | Unit and clamp of the update time argument (cloud scroll, glare step); initial value and any reset of the cloud offset table. |
| O19 | Whether an ordinary load door and map fast travel end with the instant-change flag set. |
| O20 | When the atmosphere byte `+0x30` is set. |

(O2, the order of equal-chance entries, is closed by section 2.1.)

## 15. Interim implementer choices (not retail)

These are suggestions to fill open points. **None is a retail fact.**

| Open point | Interim choice |
|---|---|
| Random source | Any uniform 32-bit generator. |
| Thunder rarity 0 | No flash and no thunder. |
| Which travel is instant | Treat player teleports and cell transitions as instant. |
| Occlusion without GPU queries | `occlusion = 1 − visible fraction` of the small quad from the depth buffer; hide fully when almost nothing is visible. |
| Cloud draw order | Highest layer index first within each technique; check against a capture. |
| Motion output | Write the camera motion at infinite distance; write (0.5, 0.5, 0, 0) to the second target only if your renderer has the same target. |
| Dither | Any 8×8 tiled noise in [0,1]. |
| AO on sky | 1. |
| Moon and star handedness | Use the matrices as written with column vectors; check one capture. |
| Sky texture colour space | Use the stored sample value without decode; check one capture. |
| Sun billboard | Face the camera; image up toward world up. |
| Frame time | Real seconds; start cloud offsets at 0 and wrap them by 1. |

## 16. Corrections to earlier findings

| # | Earlier text | Correction | Mark |
|---|---|---|---|
| C1 | #1080 G04: "`+0x98` and `+0xa0` are the current and previous weather textures". | In a transition `+0x98` holds the **outgoing** texture and `+0xa0` the **incoming** one; in the steady state `+0x98` holds the current texture. | V2 (S4, R, B) |
| C2 | #1080 G07: "First use sets 90. Each frame adds `speed × 60 × Δh`". | The first update yields `90 + speed × 60 × h` (the previous hour is taken as 0). | V2 (S4, R, B) |
| C3 | #1080 G01 and its review table: `0x414180` "not read", later "the weather sound update (GUESS)" that "does not change the answer". | It also triggers the lightning flash (sets `Sky+0x1c8` and its start time). The decay step then makes the strength 1. | V2 (S4, R, B) |
| C4 | #1080 G09: the meaning of the stars factor `f` is unverified. | It is the horizon fade of section 8.3. | V2 (S4, R, B) |
| C5 | #1080 G09 and SPEC-1 section 2.4 list one pixel output. | Sky pixel shaders also write a motion output and a constant output. Addition. | V2 (S4, R, B) |
| C6 | #1080 G01 and limitations: `0x41ca50` unverified. | It enables the sun occlusion tests and reads the query results. | V2 (S4, R, B) |
| C7 | #1080 G13: the constants "may be overridden by INI or by other writers; I did not check them". | The `fWeather*`, `fSun*`, `fMasser*`, `fSecunda*`, `fStars*`, aurora and `fDaytimeColorExtension` rows **without** a `:Weather` section are game settings; loaded data files can override them. The `:Weather` rows (`fSunBaseSize`, `fSunGlareSize`, `fSunBoost`, `fSunGlareMultiplier`) are INI settings. | V2 (S4, R, B) |
| C8 | #1080 G07: "The moon is hidden when its alpha is 0". | Also hidden when row 16 is zero. Addition. | V2 (S4, R, B) |
| C9 | #1080 G11: that sky pixels stay under the composite depth skip rests on the depth format (inferred). | The composite reads the prepass depth copy; if no sky draw writes that copy, the bias does not matter. | I (from Z, H) |
| C12 | #1080 G01: a "UI-hidden bit" that makes sky mode 1 run the full path. | The word is at `+0x340` of the global object at `0x3223e18`. That object is allocated with `0x348` bytes, the size of `BGSSaveLoadGame` in the public generated types. Read here as a load-in-progress bit. The identity stays inferred. | I |
| C13 | SPEC-1 section 8.1 and ledger L61: "The frame clear colour is `k × fog far colour`". SPEC-2 section 3 row 1: "Clear to `k × fog far colour`". | The clear colour is `NAM0` row 12 (interior: the cell fog far colour in the same sky field) × the literal 0.83332998, not `k`. All three update paths that write it use the literal. With the file value of `k` the difference is negligible; after `sfbr` it is not. (#1080 G01 already states the literal.) | V2 (K, R, X) |
| C14 | #1080 G10 technique table: write mask mode 1 for techniques 3 to 8. | The technique setup stores no mask for them. Mode 1 is the inherited state at the first sky draw; the restore writes it after each sky draw. | V2 (S4, R, B) |
| C15 | #1080 G06: the glare scale "moves toward the target `(1 − occlusion)²` … at `fSunReduceGlareSpeed` (4.0) per second". | Only a rise (and the fall branch) is rate limited. While the sun is not fully occluded and the target is at least the minimum, a lower target is taken at once. | V2 (R, B, X) |
| C16 | #1080 G10: write mask mode 0 is "none", and the moon mask quad "writes depth only"; G06: the query "colour write mask is zero". | Mode 0 closes colour output 0 only. Outputs 1 to 7 stay writable, and the mask and query pixel shaders write outputs 1 and 2. | V2 (B, X) |
| C17 | #1080 G02 and G04: cloud colours use the same mixer as the rows. | In a transition a packed cloud colour of 0 is first replaced by the other weather's colour (section 6.3). Addition. | V2 (S4, R, B) |

## 17. Verification ledger

| # | Claim group | Mark | Runs / address |
|---|---|---|---|
| L01 | Update order, sky modes | V2 | K, S4; `0x411ec0` |
| L02 | Interior skip of selection, load exception | V2 | S4, R, B; `0x4121d7` |
| L03 | Weighted roll, global replaces chance, list sort and equal-chance order | V2 | S4, R, B; order rule B, X; `0x30a3c0`, `0x30a5d0`, `0x30a900` |
| L04 | Selection rules, hold time, keep draw | V2 | S4, R, B, X; `0x412810` |
| L05 | Region handler, region source, no region list for interiors | V2 | S4, R, B; `0x779410`, `0x2bec60`, `0x2bf310` |
| L06 | Climate source, climate change, set, force, save, release | V2 | S4, R, B; release and reset also M; `0x414f00`–`0x415540`, `0x417b70` |
| L07 | `q`, acceleration | V2 | F, K, S4, B; `0x412cad` |
| L08 | Day parts, weights, `NAM0` mix, fog, flash colour | V2 | F, K, N, M, B |
| L09 | Cloud colour fallback and alpha | V2 | K, M `0x308250`; fallback byte order V1 (R) |
| L10 | Black substitution | V2 | S4, R, B; `0x413613` |
| L11 | Wind speed; direction rule; second global | V2 | K, S4; S4, R, B; R, B, X; `0x4122d5` |
| L12 | Settings values and GMST or INI kind | V2 | K, S4, R, B |
| L13 | Camera follow, node names, root alpha property | V2 | S4, R, B; `0x657dd0`, `0x655dbd` |
| L14 | Mesh layer count, layer 28 ring, dome alpha | V2 | S4, R, B; shipped meshes, `0x40bfd0` |
| L15 | Cloud scroll, texture slots, fade, technique choice | V2 | K, S4, R, B; `0x40c550`, `0x1552bdf`, `0x1553614` |
| L16 | Stars alpha, angle, matrix, horizon fade | V2 | K, S4, R, B; `0x41a4b0`, `0x41abd0`, sky vertex record 3. Eye definition V1 (R) |
| L17 | Moon phase, angle, alphas, quad, matrix | V2 | K, M, S4, R, B; `0x40d930`, `0x40e0f0` |
| L18 | Moon texture swap states; quad vertex colour | V2 | B, X; `0x412596`, `0x40deea`, `0x40daf2`, `0x41b55f` |
| L19 | Sun path, light, alphas, glare alpha | V2 | K, O, B |
| L20 | Sun quads, query, occlusion formula | V2 | S4, R, B; `0x41b290`, `0x1520db0`, `0x1520f70` |
| L21 | Glare scale rule | V2 | R, B, X; `0x41c52f` |
| L22 | Aurora factors; model load rule | V2 | K, S4, R; B, X; `0x414780` |
| L23 | Precipitation, visual effect, thunder, flash decay | V2 | S4, R, B; `0x40eed0`, `0x4182d0`, `0x414180`, `0x41262b`. "No bolt" is a scoped negative (S4, B) |
| L24 | Technique table, vertex colour, type map | V2 | K, N, S4, B |
| L25 | Extra pixel outputs | V2 | S4, R, B |
| L26 | SkyScale source and use | V2 | K, N, H, S4 |
| L27 | State table; write mask mode 0 and mode 1 targets | V2 | K, H, S4; B, X; `0x1552280`, `0x102abd0` |
| L28 | Write mask history at the first sky draw; samplers | V2 (static) | S4, R, B; noise sampler B, X |
| L29 | Id order, composite on sky, glare after composite | V2 (sky pixel branch I) | K, H, Z, B |
| L30 | Head insertion of passes; sub-list order | V2 (use by the sky I) | S4, R; B, X; `0x155f024`, `0x155ff40` |
| L31 | Moon phase check rule, flag `0x20` | V2 | B, X; `0x41252d`, `0x75a588` (the earlier author wording was wrong) |
| L32 | Region memory after every accepted change | V2 | B, X; `0x412c0d`–`0x412c88`, `0x24f820` |
| L33 | Instant-change flag: setter, listed set sources, clear (the map menu zero request is V1, X) | V2 | B, X; `0x411940` (M), `0x75eed3`, `0x743ec7`, `0x412dcb` |
| L34 | Forced weather clears the stored region; override and default rules | V2 | S4, R, B, X; `0x415540` |
| L35 | Late override dropped; late non-override re-rolled | V2 | B, X; `0x412864`–`0x412b57` |
| L36 | World map save, force and restore | V2 | B, X; `0x9a03e0`, `0x410900` |
| L37 | Clear colour literal | V2 | K, R, X; `0x412253`, `0x412699`, `0x4127a9`, `0x656d8b` |
| L38 | Atmosphere fog copy gate | V2 | F, X; `0x40b950` |
| L39 | Node scale writes in the sky code | V2 (scoped) | S4, X |
| L40 | No direct caller of the region handler | V2 (scoped) | S4, X |
| L41 | No transform write on the moons root | V1 (scoped negative) | S4; a heuristic search by X also found none |
| L42 | Climate model and sun texture fields; horizon-fade eye definition; `bPrecipitation` sound gate; compiled-defaults table search | V1 | S4 or R |

Matched reconstructions used (each confirms only its own function): `Sky::ResetWeather` `0x4154c0`, `Sky::ReleaseWeatherOverride` `0x4155f0`, `0x40d370` (moon phase), `0x416a20` (weather colour fetch), `0x419d00`/`0x419d50`, `0x411940` (flag `0x10`), `0x308250` (cloud alpha), `Sun::GetSunOcclusionPercent` `0x41ad30`, `Sun::GetSunPositionData` `0x41cbb0`, `Precipitation` constructor `0x40eda0`. `TESClimate::InitializeData` `0x2a5c10` is only mapped, not matched; section 2.1 rests on two binary reads.

Note on one reconstruction constant: the matched unit for `0x419d00`/`0x419d50` declares 1/255 (its header says that the value is a guess; a match does not prove a referenced constant). The image multiplies by 1/6 hour per climate byte (K, R). Do not copy the 1/255.

## Interpretation and alternatives

- The selection rules read as "hold, then force a change". An alternative reading, in which an unchanged roll resets the hold time, does not match the single store of the change time at an accepted change.
- Layer 28 could be seen as a fog effect because it sits on the horizon. No fog input was found for it.
- The moon path derivation assumes column-vector transforms and identity parent rotations.

## Negative results and limitations

- No game run, capture or visual comparison. No plugin data was read.
- Negative claims (no bolt object, no transform on the moons root, no direct caller of the region handler, scale writes) come from scoped static searches. Indirect and virtual access can be missed.
- Mesh facts come from the installed default meshes; mods can replace them.
- Water reflections, volumetrics, lens flare, particle and effect internals are outside this file.
- Rows marked V2 on published finding numbers rest on those runs; the finalizer did not re-read all of them.
- The worked examples apply no render-target storage rounding.

## Reviewer and outcome

Review chain, all separate fresh-context Sonnet 5.5 runs (`claude-sonnet-5-5`), static only, 2026-11-26; a Sol run was not available:

1. Author draft.
2. Independent review. Outcome: corrections required. One traced rule was wrong (glare scale, also in #1080), summary statements contradicted the body (weather change gate, chain), and omissions blocked implementation.
3. Blind second binary check. Its results were saved before it read the draft. Outcome: selection core sound; corrections to region memory, glare scale, the instant-change flag, moon texture swap, write masks and other points.
4. Finalizer. Applied both correction sets, restated section 4.3 as rules, re-read the disputed and single-run facts in the pinned image, and recomputed the examples. Where the author or the reviewer and the second check differed (moon texture swap, phase check flag, quad vertex colour), the finalizer's read agrees with the second check.

The merged text had no separate review. This is not match evidence for any function and does not decide transfer eligibility. Transfer status: UNREVIEWED.
