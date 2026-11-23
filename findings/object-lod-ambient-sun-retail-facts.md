Transfer status: UNREVIEWED

# Finding: daytime ambient, sun and colour output for distant object LOD

## Answer

| Question | Answer |
|---|---|
| 1. Which Lighting records can the standard pass request? | **Verified, conditional.** The standard selector gives technique 13 (`LODOBJECTS`) or 15 (`LODOBJECTSHD`) from the BTO property flags. In the checked stock meshes, technique 13 pairs with 28-byte vertices and VS key `0d000000`. Technique 15 pairs with 32-byte vertices and VS key `0f000001`. The matching base PS keys are `0d000001` and `0f000001`. The cutout predicate changes them to `0d100001` and `0f100001`, respectively. G01 scopes these results to the ordinary selector and lists the extra compiled records. |
| 2. What supplies ambient and sun? | **Verified.** The common Lighting geometry writer uploads `WTHR.DALC` ambient rows and the primary directional light. It transforms the slopes and light direction to model space on the stock branch. Sun RGB comes from `WTHR.NAM0`, multiplied by light fade and the active image-space sunlight scale. Near Lighting shares the writer. Object records omit the screen-space receiver shadow mask. |
| 3. Can it use point lights, and how does the PS combine the terms? | **Verified, conditional.** The native pass can upload up to seven points from a populated list. The ordinary exterior fallback skips the stock BTO root at primary-scene child 2. Stock admission through another path is **unverified**. The PS sums sun, points, ambient and two additive RGB terms, then multiplies by diffuse and vertex RGB. Fog and the per-channel upper bound follow. |

| Item | Evidence record |
|---|---|
| Status | OBSERVED for verified claims. Inferred and unverified claims are marked. Static only. |
| Author / human operator | A Sol research run, `gpt-6.2-sol` via Codex (not the reviewer below) / Taylor. |
| Reviewer | A separate `gpt-6.2-sol` run via Codex, fresh context. See "Independent review" below. |
| Date | 2026-11-23 CST, which is 2026-11-23 UTC. The independent review began at 14:42 CST. |
| Build | `sse-steam-1-7-104`, retail `1.7.104.0`, Steam build 24914197. Measured executable SHA-256 `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f` equals the asserted pin in [builds/target.json](../builds/target.json). |
| Principal function RVAs | `0x151a160` (pass selection), `0x1547d20` (shader selection), `0x1549550` (per-geometry constants), `0x413767` (Sky update fragment), `0x416490` (directional ambient weather mix), `0x14ec3b0` (ambient cache), `0x41bd90` (sun update), `0x1569550` (pass light list), `0x154bb90` (point values), `0x1548820` (material constants), `0x154c010` (scene fog). Descriptive function labels are GUESS. |
| Sources and revisions | Operator's pinned executable and retail shader package. `Skyrim - Shaders.bsa` SHA-256 `fd1ba630f443353ed21ed4ca0380968f9c7091c8434518ea3cc79bc6d38c18e7`. Member `shadersfx/shaders011.fxp` SHA-256 `72cfc73eb0938d5949f0b3a8683722a33b671a34b41b750ba138de8d154c5fbc`. Published cross-checks and generated layouts use `21e02cc3ab1b1555f76a96aafdbd44ec2619beba`. |
| Source exposure | Mixed. Pinned native binary analysis, shipped shader bytecode, shipped BTO mesh metadata and INI receipts, earlier published findings, and public generated layouts. No downstream or sibling implementation source was used. |
| Name provenance | The native feature table supplies `LODOBJECTS` and `LODOBJECTSHD`. `Feature::kLODObjectsHD` and named generated native layouts and fields below are CRASHLOGGER_PDB(59818@2026.10.24). Descriptive native function labels are GUESS. |
| Intended recipient | Skyrim Research department lead for boundary review under [docs/clean-room.md](../docs/clean-room.md). Proposed use is Mudcrab issue #946, item 14. Maintainer transfer decision is pending. |

Addresses are RVAs for image base `0x140000000`. VS and PS mean vertex and pixel shader. `bN[i]` means constant buffer N, float4 element i. `saturate` bounds its input to [0,1]. **Verified** means re-read at the cited static source. **Inferred** means a deduction with assumptions. **Unverified** means the evidence leaves the claim open. The document contains facts and formulas only. Nothing game-derived is in this file except counts, constant slots, formulas, shader keys, RVAs and the pinned hashes.

## Question and method

The requester reported that distant object LOD looks too bright at noon after adding normal-atlas lighting. Their isolation had the strongest response to directional ambient, then sun, with no measurable point response at that pose. The static question is which records and inputs retail can use. The analysis checks the saved 16 VS and 20 PS from Lighting group 6, the native selector and upload paths, and the weather and scene producers. Prior findings provide anchors. The reported pose supplies no retail constant, pass or light-list measurement.

## Observations

### G01. Material, geometry and pass selection

**Verified.** The stock BTO Lighting property uses serialized material type 0. The factory at `0x1524370` creates the ordinary Lighting material. This material type is independent of the technique. The standard technique selector uses combined runtime property bit 34 for 13 and bit 63 for 15. The latter test has priority if both are set. The base and DLC serialized lower word is `0x80400000`. The two Creation Club archives use `0x80000300`. Both populations use upper `0x00000005` for 13 and `0x80000021` for 15. The generated `Feature.h` includes `kLODObjectsHD = 15` and omits entry 13. The native table contains both labels. Evidence at `0x15188a7`, `0x151ad44–0x151ad61`, `0x1589648` and the BTO census in #948 G07.

**Verified.** The paired shape and property census covers 2,428 Lighting properties across 1,109 BTOs in `Skyrim - Meshes1.bsa`, `ccbgssse067-daedinv.bsa` and `cckrtsse001_altar.bsa`. Each counted technique-13 property pairs with a 28-byte vertex layout and a zero colour descriptor nibble. Each counted technique-15 property pairs with a 32-byte layout and nibble seven. The standard selector and stage transforms give the following conditional keys from those serialized inputs.

| Technique | Count | Vertex stride | VS key | PS key, cutout clear | PS key, cutout set |
|---|---:|---:|---|---|---|
| 13 | 1,603 | 28 bytes | `0d000000` | `0d000001` | `0d100001` |
| 15 | 825 | 32 bytes | `0f000001` | `0f000001` | `0f100001` |

The stage table also contains `0d000001` and `0f000000` as VS keys. The native colour input is independent of the technique input. Use of those crossed VS keys by stock geometry is **unverified**. The standard selector has no game-hour test. Context bypasses and property overrides below can change the requested technique. Evidence is the paired BTO census and `0x15191d4–0x15191ef`, `0x151a956–0x151a989`, `0x151ad44–0x151ad61` and `0x15896a0–0x15896e1`.

**Verified.** The attachment at `0x15191d4–0x15191ef`, called at `0x505d67`, sets property bit 37 from the geometry descriptor's bits 24–27. The 32-byte stock layout includes vertex colour. That property bit supplies VS key bit 0. The 28-byte layout omits colour and its VS supplies white. PS key formation sets bit 0 in either layout. Evidence at `0x151a956–0x151a989`, `0x15896a0–0x15896e1`, and the VS input signatures. The BTO alpha-property setup enables alpha test, disables alpha blend, selects compare code 4 and sets reference byte 128. The standard pass can set cutout for this alpha property when the early-Z byte `0x3336405` or the pass-context predicate is set. The builder also sets cutout on the separate `0x0c000000` property-mask case with bit 41 clear. The stock serialized flags clear that mask. Evidence at `0x151a5b4–0x151a5ea`, `0x151a8fc–0x151a92d`, `0x151aa7f–0x151aa9e` and #675 B1/B4.

**Verified.** Context byte `0x20d9668` can bypass technique selection, forcing prefix zero on this route. Later tests can override 13/15 for property bits 56, 61, the conjunction of 23 and 41, or bit 17. Stock serialized flag words clear those override conditions. Material and pass state can route a draw through other paths. The key lookup at `0x1547d20` derives stage-specific keys through `0x15896a0` and `0x15896d0` and uses exact record lookup at `0x1579120`. The point count bits do not survive either stage transform. The standard object selector contains no game-hour test. Evidence at `0x151ab46–0x151ab58`, `0x151ad64–0x151adbd` and `0x151ae2e–0x151ae5e`.

| Extra compiled case | VS suffixes for either prefix | PS suffixes for either prefix | Native predicate or limit |
|---|---|---|---|
| `0x8000` | `008000`, `008001` | `008001`, `108001` | Property bit 23, or the conjunction at `0x151ab20–0x151ab42` of the active pass mask and property bits 32 and 18. |
| `0x40000` | `040000`, `040001` | `040001`, `140001` | Property bit 55 under the LOD mask at `0x151ae2e–0x151ae58`. That mask also clears raw bit 14. |
| Both | `048000`, `048001` | `048001`, `148001` | Both predicates must supply their bits and the technique must survive overrides. |
| Auxiliary with `0x8000`, with or without projection | `008000`, `008001`, `048000`, `048001` | `208001`, `248001` | Raw `0x200000` must reach PS with raw `0x200` clear. The branch at `0x151abc3–0x151ad16` can set the former alone with property bit 14, a material-table match and the `0x20d6ce8` enable byte. |

**Verified.** The table plus the base row accounts for every compiled record in these techniques. The common auxiliary branch at `0x151aa9e–0x151aaf0` adds `0x200200`. Its conditions exclude the ordinary stock flags. Both stage transforms keep the resulting `0x200`, and that route alone produces no exact compiled object match in the table. This distinguishes an available record from a native request. The compiled auxiliary records omit the cutout variant. The projected bind acts on the raw projected bit and supplies the slot-12 overlay from `0x20d6920` (`0x154a530–0x154a61a`). Settings `bEnableProjecteUVDiffuseNormals:Display` and `bEnableProjecteUVDiffuseNormalsOnCubemap:Display` instead affect the overlay parameter lane (`0x154a0de–0x154a116`, `0x154c600–0x154c6f6`). Their image defaults are one and zero. Low through Ultra set the first to `0, 1, 1, 1`. `bEnableSnowRimLighting:Display` starts at one and controls the auxiliary upload enable lane at `0x1549273–0x15492b7`.

**Confidence: high** for the stock predicates, stage transforms and compiled set. **Unverified.** Any stock daytime producer that adds the extra flags or reaches the auxiliary request. A traced property mutation or context-specific pass would change the reachability conclusion. Live key selection remains open.

### G02. Directional ambient weather inputs and model-space upload

**Verified.** On the exterior weather branch, Sky mode 3 uses the current weather at `Sky+0x48` and optional previous weather at `+0x50`. The branch requires the two alternate lighting lookups to return null. The `WTHR.DALC` loader fills four consecutive 32-byte day-part entries at weather `+0x7f8`. Each contains six packed directional RGBs, one additional packed RGB and one float power. The constructor initializes the six directional RGBs to white, the additional RGB to black and power to 1.0. The 64-bit store at `0x203eb5` sets the sixth RGB at entry `+0x14` to `0x00ffffff` and the additional RGB at `+0x18` to zero. Evidence at `0x413751–0x413794`, `0x413917–0x413947`, `0x3085e2–0x3085fa`, `0x203ed0`, `0x307e4b–0x307e65` and `0x203e90–0x203ec4`.

**Verified.** For ordered climate endpoints, the day-part colour weights follow the table. The `CLMT.TNAM` timing bytes use ten-minute units. Let A be sunrise begin less `fDaytimeColorExtension`, floored at zero. B is sunrise end, C is sunset begin, and D is sunset end plus the extension, capped at 23.99 hours. The setting defaults to 0.5 hour. The shipped climate example in #812 G02 has A/B/C/D of 5/10/16/21 hours at that default.

| Game hour | Day-part mix within each weather |
|---|---|
| At or before A, or at or after D | Night |
| A to the midpoint of A and B | Linear night to sunrise |
| Midpoint of A and B to B | Linear sunrise to day |
| B through C | Day |
| C to the midpoint of C and D | Linear day to sunset |
| Midpoint of C and D to D | Linear sunset to night |

**Verified.** The serialized day-part indices are sunrise 0, day 1, sunset 2 and night 3. If the selector's first index has time weight `t`, the corresponding four weights are `q×t`, `q×(1−t)`, `(1−q)×t` and `(1−q)×(1−t)`. They apply to the two current entries followed by the two previous entries. The ordinary current-only path sets `q=1`. With both weathers, the base `q` is elapsed game hours, including midnight wrap when needed, divided by transition duration. The duration interpolates between `fWeatherTransMin` and `fWeatherTransMax` using the incoming `WTHR.DATA` byte at `+0x667` divided by 255. Image defaults are 0.01 and 0.25 hour, and the weather constructor defaults that byte to zero. The acceleration branch uses `q0 + (q−q0)×(1+fWeatherTransAccel)`, with stored anchor `q0` and setting default 4.0. Above one, the completion branch clears previous weather and sets `q=1`. Evidence at `0x2a5b52`, `0x2a5ba5`, `0x419ab0`, `0x419bb0`, `0x416760–0x416a06`, `0x412c8a–0x412d82`, `0x307e95–0x307eac` and setting fields `0x209e5a0`, `0x209e708`, `0x209e720` and `0x209e738`. The shared schedule also feeds the `NAM0` mixer in G03.

**Verified.** The DALC mixer at `0x416490` converts each RGB byte with the float32 reciprocal of 255 and applies the four weights. It preserves the serialized order of the six faces. This is numeric normalization, with no nonlinear colour transform in this path. The mixed RGB inputs are dimensionless. They lie in [0,1], to float precision, for convex weights. For channel `c`, let `F0…F5` be its mixed directional colours in serialized order. The cache builder at `0x14ec3b0–0x14ec686` produces the following coefficients for a world-space normal.

| Coefficient | Value per channel |
|---|---|
| X, Y, Z slopes | `(F1−F0)/2`, `(F3−F2)/2`, `(F5−F4)/2` |
| W intercept | `(F0+F1+F2+F3+F4+F5+G[c])×0.1666666716337204` |

`G` is a separate RGB operand at `0x331d6f0..0x331d6f8`. It is zero in the image. The effective value and any runtime writers are **unverified**. The mixer also blends the seventh RGB and float power. The builder stores them separately and floors the cached power to one. These lanes do not enter the three rows in the checked upload. Evidence at `0x4164e0–0x416743` and `0x14ec68e–0x14ec6e4`.

**Verified.** The geometry entry at `0x1549550` uses model space when its raw pass bit 1 is clear on these techniques. It rotates each world slope into model space using the geometry rotation and preserves W. Equivalently, with `R` mapping model directions to world directions, the uploaded slope is `Rᵀ × slope_world`. The upload packs one float4 per RGB channel at `PS b2[11..13]`. The other branch packs the cached world slopes directly. The stock object PS supplies the model-space lighting normal from the atlas and its interpolated basis. It dots each row with `(N.x,N.y,N.z,1)`. The checked path uses no view-space normal, extra day/night multiplier, image-space sunlight scale or shadow visibility factor for DALC. Evidence at `0x15495a4–0x15495c1`, `0x15496ca–0x1549ab1`, `0x1549ba6–0x1549efb` and the group 6 object records.

**Confidence: high** for the exterior weather branch, interpolation, cache formula and upload. **Unverified.** Live climate cache timing, forced or interrupted weather routing, exceptional endpoint order, the effective value of `G`, and the directional ambient source at the reported pose. A source or draw receipt that resolves those inputs would close these limits.

### G03. Sun direction, weather colour and image-space scale

**Verified.** Zero-based `WTHR.NAM0` row 4 supplies directional light RGB. The generic mixer uses the G02 day-part and weather weights, divides the channel bytes by 255 and caps the result at one. The weather constructor initializes the table to black. Row 4 goes to `Sky+0xd8`, then to `NiLight.diffuse` at `0x41c835–0x41c84f`. Row 3 goes through `Sky+0xcc` to `NiLight.ambient`. The DALC upload in G02 reads its own cache. Evidence at `0x30849d–0x308509`, `0x307e81–0x307e90`, `0x4133bd–0x413491` and `0x41c815–0x41c84f`.

**Verified.** In the current-weather-only branch, a flash scalar at `Sky+0x1c8` is multiplied by `fWeatherFlashDirectional` for row 4 and `fWeatherFlashAmbient` for row 3. The respective image defaults are 1.0 and about 0.3. A positive adjustment is bounded above at one, then added to each normalized channel. When current weather exists, each adjusted channel is clamped between zero and its cap byte divided by 255. The cap bytes are in serialized `WTHR.DATA` at offsets 12–14, runtime `+0x670..672`. They default to zero. Evidence at `0x413440–0x41346c`, `0x414cf0–0x414eef`, `0x308396–0x3083e1` and `0x307e95–0x307eac`.

**Verified.** The ordinary exterior sun update derives a path coordinate from climate timing and game hour. Its dawn boundary is the sunrise midpoint less half `fSunAlphaTransTime`. Its dusk boundary is the sunset midpoint plus half that setting, whose default is 2.0 game hours. Between ordered boundaries the coordinate drops linearly from +1 toward −1. On the night interval it rises linearly from −1 toward +1, including the wrap across midnight. The update scales this coordinate by `fSunXExtreme`, default 400. Given the resulting coordinate X, the components for the local rotation's first column are proportional to:

| Component | Value |
|---|---|
| X | `−X × fSunDirXExtreme / fSunXExtreme` |
| Y | `−fSunYExtreme × fSunDirXExtreme / fSunXExtreme` |
| Z | `fSunZExtreme` |

The image defaults of `fSunDirXExtreme`, `fSunYExtreme` and `fSunZExtreme` are 400, 25 and −100. The update normalizes the vector. These are path parameters. The normalized direction is dimensionless. A later branch can replace the rotation. The neighboring sun/glare state update uses `WTHR.DATA` byte `+0x668` and day alpha. The ordinary RGB copy above is independent of that arithmetic. Evidence at `0x41c048–0x41c52c` and `0x41c815–0x41c854`.

**Verified.** Four `WTHR.IMSP` form references at weather `+0x7d8` supply the image spaces. The loader stores them at `0x3086ef–0x3086fc` and `0x308cb3`. The constructor defaults them to null. The selector at `0x415660` applies the ordered-endpoint schedule in G02. The weather blend at `0x4158d0` accumulates the selected data with the day-part and weather weights. Missing references use fallback forms. The ordinary blend can bind its data as the base at `0x4121d2`. The override path binds data at `0x9a052e–0x9a0554`. The active copy at `0x14eec10` selects the override when present, otherwise the base. It copies the resulting data into the manager at `+0xc8` through `0x1536f80`. The copied sunlight scale at manager `+0xe0` comes from `TESImageSpace.Hdr.SunlightScale` in `IMGS.HNAM` at form `+0x38`. Its constructor default is approximately 1.8 at `0x1536a72`.

**Verified.** The common active image-space data can receive a modifier after that copy. The path at `0x2a75ec` calls `0x14eeca0`, which passes the active data to `0x15370b0`. At `0x15371ca–0x15371ec` a modifier moves the active sunlight scale L toward `L × multiplier + additive` by its weight. The multiply and add lanes are identified by the generated `TESImageSpaceModifier` HDR layouts, `CRASHLOGGER_PDB(59818@2026.10.24)`. The Lighting upload uses the resulting dimensionless scale. The checked upload adds no object-specific multiplier or clamp. The selected image space, modifier values, effective light fade and final bound scale remain **unverified** for the reported draw.

**Verified.** The geometry writer uses the first light selected by the pass, as described in G04. At `0x1549ab6–0x1549ba1`, `PS b2[1].xyz = NiLight.diffuse × NiLight.fade × SunlightScale`. The `NiLight` initializer sets fade to 1.0 at `0xeed180`. The direction at `PS b2[0].xyz` is normalized `−NiDirectionalLight.worldDir`. That field at light `+0x140..148` receives the first world rotation column at `0xf045c0`. The model-space path applies the inverse geometry direction transform before normalization. The alternative keeps the direction in world space. The checked upload contains no view rotation or additional day/night term, LOD multiplier or receiver shadow multiplier.

**Verified.** Ordinary near Lighting and the two object LOD techniques use the same primary-light and DALC upload code and scales. The selected light can differ with pass and scene state. The ordinary exterior branch selects the scene sun wrapper or its shadow-directional wrapper. The setup sends the same non-null light to both wrappers when the shadow wrapper exists. Evidence at `0x150f469–0x150f47f`, `0x150f55e–0x150f561` and vtables `0x1b4ca30` and `0x1b4e5f8`. Slot `+0x10` in each vtable resolves to `0x1576ad0`, which stores the light pointer at wrapper `+0x48` at `0x1576af2`. Cascade hold and interpolation use separate wrapper vectors. The Lighting direction upload reads the light's `worldDir` field. The cloud-light override depends on property bit 52. The 20 object pixel shaders omit the screen-space receiver shadow-mask sample from `t14`. See #806 §§3–4 for the near shadow-receiver controls and object-record comparison.

**Confidence: high** for the ordinary weather feed, shared writer and object PS arithmetic. **Unverified.** Effective fade and overrides for the reported draw, exceptional climate inputs and the selected image-space form at that pose. A traced override or draw receipt would establish those values.

### G04. Point-light admission, draw list and constants

**Verified.** Stock BTOs attach below child 2 of the primary shadow scene. Setup assigns the scene to index 0 and attaches `LODRoot` as its child 2. The land node is the first child of `LODRoot` and becomes `TES.lodLandRoot`. The object LOD manager attaches its BTO root below this land node. It then attaches the payload below the BTO root. The separately named `ObjectLODRoot` is scene child 3 and supplies `TES.objRoot`. Evidence at `0x655b39–0x655b9a`, `0x656042–0x65612c`, `0x6555ee–0x655688`, `0x19f61a`, `0x19f6c2`, `0x515b45–0x515b8c`, `0x515e24–0x515e38`, `0x505755–0x50576f` and `0x6563f6–0x65645e`.

**Verified.** The light-driven update at `0x150e400` rejects a light with flag bit 0 or fade below approximately 0.05. It dispatches ordinary wrappers to `0x1513290`. The primary-scene fallback traverses children 3 and 6 and then checks eligible portal roots. It omits child 2. The non-primary fallback scans all children. Explicit-target, room and portal branches are separate. Evidence at `0x150e400–0x150e4ff`, `0x15134d6–0x1513504` and `0x151398f–0x1513fb9`.

**Verified.** The traversals can add a light after geometry eligibility and a sphere test. The test is `distance(lightPosition + offset, boundCenter) − boundRadius < lightRadius`. Directional lights and the bit-11 case can bypass the sphere test. The recursive walk skips children with bit 0 set and skips zero-fade children when bit 11 is clear. Its optional filter requires bit 26, bit 11 or the explicit-target bypass. Evidence at `0x1577480` and `0x150f0c0`. The geometry admission check at `0x14e8350` tests the light's `affectLand` field when property bit 14 or 46 is set. Both bits are clear in the stock object flags.

**Verified.** Other scene update paths can supply property lists independently of the ordinary light-driven fallback. Registration at `0x150e780` populates the scene arrays at `+0x1c8` and `+0x1e0`. The update at `0x150d6a0–0x150d813` consumes them. Its branches call `0x150ee90` for eligible geometry or `0x150ed00` for a node. The geometry path can test parent-associated or scene active lights and append to the property at `0x15765d0`. The candidate sort used by `0x150e860` orders higher wrapper luminance first, using `+0x10` in the comparator at `0x1512370–0x1512398`. The checked direct calls from BTO attachment and geometry setup do not reach the registration helpers. **Unverified.** Indirect calls and stock BTO reachability through registration, explicit-target or portal traversal. The child-2 exclusion covers the ordinary fallback.

**Verified.** The standard object pass calls the common selector at `0x1569550` with capacity 16 (`0x151a88c`). Its first entry is the scene sun or shadow-directional sun. Property bit 52 can select the cloud light. Eligible shadow entries precede ordinary property-list entries. A separate selector argument enables the shadow-candidate scan. With that scan enabled, the candidate normally needs a matching property `activeLightMask` bit. The object pass in mode `0x16` can also admit the index through its first-person mask bit. The selector proceeds to the ordinary property-list append even when the shadow-candidate scan is disabled. Evidence at `0x151a84a–0x151a874`, `0x15695d7–0x1569644` and `0x15696e0`. For ordinary entries the selector skips wrapper byte `+0x5c == 0xff` and light flag bit 0, then uses property-array order. The helper at `0x15690f0` handles duplicate suppression and the insertion fence. The helper at `0x1569780` compacts null entries. The builder encodes a point count capped at seven and a shadow-list count capped at four (`0x151a932–0x151a954`). The stage keys omit those count bits. The upload writes the counts to `PS b2[29].xy`, clears both seven-entry arrays and calls the point writer when the point count is nonzero (`0x1549fdc–0x154a087`). The object PS reads X for the loop limit and has no receiver-mask consumer of Y.

| PS input | Native producer |
|---|---|
| `b2[15+i].xyz` | On the model-space branch, the point writer adds the render offset to `NiAVObject.worldTranslate` and applies the inverse geometry transform. On the world-space branch, it subtracts the render origin from world translation and then adds the render offset. Evidence at `0x154bc6b–0x154bdba`. |
| `b2[15+i].w` | `NiPointLight.radius.x` in world units, divided by geometry scale on the model-space path. |
| `b2[22+i].rgb` | `NiLight.diffuse × NiLight.fade × BSLight.lodDimmer`. RGB and the two multipliers are dimensionless. |
| `b2[29].x` | Native encoded point count. The compiled shader loops in index order up to the lower of this count and seven. |

**Verified.** The point writer is at `0x154bb90`. It takes its render offset from scene `+0x2e8` in modes `0x11/0x16`, or from global `0x331c458` otherwise. The placed-light form initializer converts `TESObjectLIGH.LightData.LightColor` RGB bytes to floats with `1/255`. Form flag bit 2 selects a negative sign. The radius comes from form `+0xe4` and can use a reference-dependent radius from `0x2ffd70`. A nonpositive finite effective radius becomes approximately 0.1 world units. Evidence at `0x2744ce–0x27455a` and `0x2746a2–0x27470d`. **Unverified.** Reference transforms before the light's world transform, live dimmers, and coordinate equality on projected draws. The base VS supplies its model position for the loop. The projected VS supplies a transformed position plus the separate `VS b2[14].xyz` offset.

**Confidence: high** for the fallback exclusion, conditional native list consumption and shader arithmetic. **Unverified.** Stock BTO admission by a different traversal and a nonzero retail point list for the reported draw. A proven registration path to a stock BTO property would establish native admission. A draw receipt could establish the actual list and coordinate alignment.

### G05. Additive terms, fog and outputs

**Verified.** All 20 checked object PS use the atlas-derived lighting normal N for sun, points and directional ambient. The base diffuse and vertex colours multiply the accumulated lighting and additive terms. Projected detail can alter N. All five projected technique-15 PS can alter diffuse RGB, and the overlay variants can also alter the effective diffuse. Evidence is the group 6 records in G01 and #948 G03/G05.

| Order | Slot and producer | Effect on target 0 RGB |
|---|---|---|
| 1. Sun | `PS b2[0..1]`, G03 | Initialize with `saturate(dot(N, sunDirection)) × sunRGB`. The dot is bounded to [0,1]. |
| 2. Points | `PS b2[15..28]` and `b2[29].x`, G04 | Add point RGB times the saturated normal dot and `1 − saturate(distance/radius)²`. The normal dot and distance input to the square are bounded to [0,1]. |
| 3. Ambient and property emission | Ambient rows `b2[11..13]`, G02. Emission `b2[4].yzw` from Lighting property RGB at `+0xf0` times multiplier at `+0xf8` (`0x1549f3a–0x1549f9c`). | Add the emissive RGB to the three ambient row dots with `(N,1)`, then add that sum to the accumulator. The ambient dots are unsaturated. The emitter is independent of N. |
| 4. Shader-object additive RGB | `b1[8].x` from shader object `+0xcc`. RGB comes from `+0xd0` if the byte at `+0xf0` is set, or `+0xe0` otherwise (`0x154936f–0x15493c6`). | Add scalar times RGB independently of N. Multiply the resulting accumulator by effective diffuse RGB, then vertex RGB, to obtain lit RGB `L`. |
| 5. Fog and output arithmetic | Interpolated fog colour and strength `(Cf,F)`, and pixel constants listed below. | Form `M = L + F × (Cf−L)`, then `Q = L−k×M` and `E = S×Q`. Target 0 RGB is the channel-wise minimum of `L` and the multiply-add `Q×S+B`, followed by subtraction of `T×E`. |

**Verified.** The shader-object scalar, both RGB vectors and the selector initialize to zero (`0x154730c–0x1547321`, `0x154742f–0x1547436`). The BTO loader reads serialized emission RGB and multiplier at `0x15188e0–0x151893c`. All 2,428 Lighting properties in the three previously inventoried archives, across 1,109 BTOs, store RGB `(0,0,0)` and multiplier `1.0`. The two additive terms multiply by diffuse and vertex RGB with the light terms. Both are independent of the normal dot products. The records contain no direct sun or point specular term in target 0.

**Verified.** The shared fog writer at `0x154c010` selects the scene through byte `0x20d6970` and reads its fog property. Atmosphere can attach the property to scene 0 and writes near/far RGB. A scalar update flag gates writes of near, far, power and max. Weather feeds the colour and distance ramps described in corrected #812 G01–G03. The writer puts `(near/(far−near), 1/(far−near), power, max)` in `VS b0[1]` and near/far RGB in `VS b0[2..3]`. For the zero-distance pair it uses `(5000000, 0.1, 1, 0)`. With no selected fog property it leaves the fog vectors unwritten. The VS measures length of clip-space XYZ before dividing by W. It saturates the linear input, applies the power, caps the result at max, and uses that strength to interpolate near and far RGB. It interpolates the resulting colour and strength in `COLOR1` to the PS. Evidence at `0x40b959–0x40b991`, `0x40ba9c–0x40bb46`, `0x154c020–0x154c1b3` and all 16 object VS.

| Output control | Producer |
|---|---|
| `k = PS b0[0].w` | The fog writer copies float `0x20d694c`. Its image initial value is `0.8333333134651184`. The pinned image has later writes. |
| `B = PS b0[1].x` | Cached `fLightingOutputColourClampPostLit:General` at `0x343640c–0x3436414`, image setting default 1.0 at `0x20d8d00`. The common bind reads the cache at `0x1548614–0x15486b9`. |
| `S = PS b12[42].y` | Zero with bit 1 set in the frame-constant writer's flag argument. One otherwise. |
| `T = PS b12[42].z` | One with bit 2 set in that argument. Zero otherwise. The two flags are written at `0x100b327–0x100b349` and bound at `0x101080d–0x1010825`. |

**Verified.** The fog blend operates on lit RGB. The per-channel upper minimum precedes the last frame-flag subtraction. The `fGamma:Display` divide at `0x100b317` writes X of `PS b12[42]` at `0x100b31f`. All 20 checked object PS read Y and Z of that vector. Their target-0 RGB arithmetic has no explicit gamma or exposure conversion and no final saturation. The sun RGB already includes the active image-space sunlight scale from G03. The bound formats, fixed-function output and later frame processing remain **unverified**.

| Output | Native source and shader effect |
|---|---|
| Target 0 alpha and cutout | Diffuse alpha is multiplied by `b2[3].z`. The geometry writer uses property alpha at `+0x30` and also applies material `+0x14c` when the high bit of pass byte `+0x1e` is set. The builder can set property alpha to material `+0x80` times pass fade at `0x151a465–0x151a4aa`. The cutout keys discard when alpha is strictly below `b11[0].x`. The native cache is the reference byte times property alpha, truncated then divided by 255. The upload uses the cache when enable byte `0x20cfcb4` is nonzero. Otherwise it uploads zero. Evidence at `0x1578930–0x157896f` and `0x101118d–0x10111ab`. |
| Target 2 | When `b2[7].z > 0.00001`, target 2 copies target 0. Otherwise it packs normal XY and puts the cubic smoothstep of atlas alpha, times `b2[7].w`, in W. The edges are `b2[7].x−0.00001` and `b2[7].y`. The writer at `0x154a79f–0x154a810` supplies X from `fSpecMaskBegin:Display` (0.1) and Y from that value plus `fSpecMaskSpan:Display` (0.0). It supplies Z from selector `0x3436408`. The W scale uses the draw-scaled `specularLODFade` when raw bit `0x200` is set. The other branch uses zero as its fade input. Pass writes set the selector at `0x151f9b5` and `0x152046c` and clear it at `0x151fb1a` and `0x1520513`. |
| Target 3 on the four auxiliary records | `b1[13]` supplies the two angular powers and their scale and enable inputs (`0x1549267–0x15492b7`). The defaults are intensity 0.3, geometric exponent 3 and lighting-normal exponent 2. `bEnableSnowRimLighting` can zero the enable lane. The gated angular product reaches target 3 X through luminance weights. Y carries the overlay mask. The angular product leaves target 0 unaffected. |

**Confidence: high** for the record formulas, slot mapping and immediate upload sources. **Unverified.** Later writers of the shader-object additive values, the live emissive inputs, the frame flag selections and downstream auxiliary-target use. A traced producer or draw capture could resolve those inputs without changing the static order.

### G06. Scope of earlier finding #806 section 4

**Verified.** The #806 independent-review summary for §4 needs the archive scope stated in §4 itself. The cleared receive/cast bits apply to the properties counted in `Skyrim - Meshes1.bsa`. All 36 Creation Club Lighting properties counted in #948 G07 have lower word `0x80000300`, which sets bits 8 and 9. Those are 28 properties across 26 meshes in `ccbgssse067-daedinv.bsa` and eight across five meshes in `cckrtsse001_altar.bsa`. Evidence is a fresh serialized flag census of those two archives and the flag loader at `0x1518860` and `0x14e7390–0x14e73df`. The two flag names are `kReceiveShadows` and `kCastShadows`, CRASHLOGGER_PDB(59818@2026.10.24). This PR amends §4 of #806 with the same scope. See the amendment in that file.

**Confidence: high** for the serialized flag words in the three archives. **Unverified.** The live flags, pass admission and caster membership for the Creation Club meshes. A different archive or a live property mutation could change the effective flags. The 20 checked object Lighting PS still omit `t14` as specified in G03.

## Interpretation and alternatives

**Verified.** Retail's standard two techniques share the near Lighting ambient and sun upload. The atlas normal changes the directional response in the shader. The ambient dot contains a constant intercept as well as directional slopes. The usual sun dot bounds only the angular term, and the light RGB carries the weather, fade and sunlight scale. Both additive colours enter before diffuse multiplication and independently of the normal. Fog and the post-lit upper bound act on the combined result.

**Inferred.** A difference in weather mix, decoded normal or basis, selected light and sunlight scale, vertex tint, additive input, or fog/output state can change the noon result with the same shader family. The reported term isolation does not identify which of these differed. The standard light-driven fallback supplies no points through the stock BTO's root. Other native admissions remain open as scoped in G04.

## Relation to earlier findings

- **#675** (object and tree LOD): its B1 and B4 property and alpha facts are the anchors for the cutout predicate in G01. This finding gives no correction to #675.
- **#806** (sun shadows): G03 and G06 depend on its §§3–4. This PR amends #806 §4 only, in the same PR, to scope the cleared shadow bits to the base archive and to add the 36 Creation Club properties that set them. Its base counts and 24-permutation result stay.
- **#812** (exterior fog): G02 and G05 reuse its climate schedule and fog ramps. This finding gives no new correction to #812.
- **#816** (object LOD segments): it concerns segment eligibility and suppression. This finding makes no claim about whether a segment reaches a draw.
- **#822** (terrain LOD shading): it covers the separate terrain LOD records. This finding covers the two object LOD techniques and gives no correction to #822.
- **#946** (terrain LOD versus near landscape): its fog-gate and shader-object attribution agree with G05 in the overlapping claims. This finding gives no correction to #946.
- **#948** (object LOD normal atlases): it supplies the atlas-derived lighting normal and the BTO census used here. This finding adds the ambient, sun, point-light and output terms and gives no correction to #948.
- **#979** (near technique 19 order): its light accumulator, vertex tint and fog-bound order agree with G05 for the object records. This finding gives no correction to #979.

Published corrections stay in force.

## Negative results and limitations

- **Verified.** The 20 checked object PS omit the receiver-mask sample. Their target-0 RGB expressions contain no additional sun or point specular term, explicit gamma or exposure conversion, or final saturation.
- **Unverified.** A live key and pass, effective INIs, resource views, draw constants, frame flags, downstream processing and the resulting brightness. The work is static only. Visible noon brightness is therefore unverified.
- **Unverified.** The live draw inputs: key, pass, light list, weather mix, selected image space, modifier values, light fade and frame flags.
- **Unverified.** An alternate route populating a stock BTO's light list (alternate point admission), and the runtime sources or accesses beyond the scoped chains above.
- **Unverified.** Caster-list membership and live flags of the Creation Club meshes. See G06.

## Independent review

Reviewer: `gpt-6.2-sol` via Codex, in a separate run from the author. Static review outcome: one confirmed group (G06) and five groups requiring corrections (G01–G05). The reviewer saved the initial findings before opening the full draft. A search had exposed excerpts from the author handoff, so the G04 fallback/root check is a targeted reproduction. Live key selection, alternative stock point-light admission and visible brightness remain unverified. Transfer status: UNREVIEWED.

Result: **1 confirmed (G06), 5 corrected (G01–G05), 0 rejected.** The reviewer matched all saved object LOD shader payloads (16 VS and 20 PS) to the shipped records. This file already contains the corrected wording.

| Group | Verdict | Main correction |
|---|---|---|
| G01. Material, geometry and pass selection | Corrected | Technique 13 pairs with the 28-byte layout and technique 15 with the 32-byte layout. The crossed VS keys are separate compiled cases. |
| G02. Directional ambient weather inputs | Corrected | The constructor sets the six directional RGBs to white and the additional RGB to black. |
| G03. Sun direction, weather colour and image-space scale | Corrected | A modifier can adjust the active sunlight scale before the Lighting upload. |
| G04. Point-light admission and constants | Corrected | The shadow-candidate gate is separate from the property-list append. Both point-position offsets are spelled out. The primary fallback root exclusion was reproduced. |
| G05. Additive terms, fog and outputs | Corrected | The native cutout cache can upload zero when disabled. Target 2 W applies only on the packed-normal branch. The gamma lane is unused by these records. |
| G06. Scope of #806 section 4 | Confirmed | The two Creation Club archives set both serialized shadow bits. #806 section 4 is amended to scope its verdict. |

Source exposure of the review: mixed. The reviewer used the local pinned executable, the shipped shader and mesh archives, published findings and generated name layouts. This is a static review. It is not match evidence for any function, and it does not decide transfer eligibility.

Reviewer and outcome: Reviewed independently by `gpt-6.2-sol` via Codex. Outcome: 1 confirmed, 5 corrected, 0 rejected. Static evidence only. Transfer status: UNREVIEWED.
