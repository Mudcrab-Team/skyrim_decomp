Transfer status: UNREVIEWED

# Finding: near Lighting features beyond the plain permutation (environment map, glow, alpha, decals, parallax, eye, face, hair, refraction, landscape specular)

## Answer

Static only. No game run. No visual claim. Item 35 of the Mudcrab research list, "lighting technique features beyond plain". It includes Mudcrab issue #984.

`Σ` is the plain light sum: sun, point lights, directional ambient, property emission and shader-object additive RGB. `vc` is vertex colour. `L` is the lit colour that enters the output tail. `t0` is the base colour map and `t1` is the normal map. `A` is the albedo. On keys without bit 15 (projected UV), `A = t0.rgb`.

| Question | Short answer | Group |
|---|---|---|
| Which permutation? | Property flag bits select one technique id. A fixed priority applies. The material class only supplies textures and constants. | G01, G02 |
| Environment map | `L = A × Σ × vc + E × Σ`. `E = cube(R) × mask × envMapScale × envmapLODFade`. The mask is `t5.r` when the material mask pointer is non-null at setup. Else it is normal-map alpha. | G03 |
| Glow map and emission | Emission is `emissiveColor × emissiveMult`. The glow technique multiplies it by `t6.rgb`. It stays inside `Σ`, so albedo and vertex colour multiply it. | G04 |
| Alpha test | Discard when `alpha < ref`. `alpha = t0.a × propertyAlpha × vc.a`. `ref = trunc(threshold × propertyAlpha) / 255`. Screen-door fade keys use a different alpha. Hair decals add a fixed 4/255 cut and scale alpha by 1.05. | G05 |
| Blend, depth, cull | `NiAlphaProperty` source and destination factors map to a few fixed blend states. Two-sided comes from property bit 36. | G06 |
| Decals | Same shaders as other geometry. Rasterizer bias −1 with slope −0.65, plus a viewport max-depth reduction of 2.6e-5 to 3.0e-5. Non-blended decals write depth. Blended decals do not. Blended decals write only target 0 (one exception). | G07 |
| Fog on decals, blended and additive surfaces | Decals draw before the fog composite. Sorted transparent draws fog in the pixel shader. Lighting setup does not change fog for additive blending. | G08 |
| Empty texture slot | A fixed default per slot: flat normal, white, black, grey or a zero cube. Property bit 20 replaces the base colour with black. | G09 |
| Landscape specular | Land properties get the specular bit from `bLandSpecular` (compiled 1). Exponent and mask are blended by the six layer weights. | G10 |
| Parallax | One-step offset `uv + V.xy × (0.08 × t3.r − 0.04)`. `V` is the model-space view vector. No tangent-frame rotation applies. | G11 |
| Eye | Environment term with a sphere normal from the eye centre. Ambient also uses that normal. | G12 |
| Face, face tint, hair | A soft-light style tint of `t0`. Hair tint is weighted by vertex colour green. | G13 |
| Refraction | A refraction property gets a utility-shader pass and no Lighting pass. | G14 |

| Item | Evidence record |
|---|---|
| Status | OBSERVED for verified claims. Inferred and unverified claims are marked. Static only. No runtime capture. |
| Author / human operator | A Sonnet 5.5 research run (`claude-sonnet-5-5`) for the department operator. A later Sonnet 5.5 run applied the review corrections and re-read key items. |
| Reviewer | A separate fresh-context Sonnet 5.5 run (`claude-sonnet-5-5`). Sol was unavailable on a usage limit. See "Independent review". |
| Date | 2026-11-25 CST. Author run 16:46 to 17:11. Independent review 17:12 to 17:41. Corrections applied after 17:41. |
| Build | `sse-steam-1-7-104`, retail `1.7.104.0`, Steam build 24914197. Measured executable SHA-256 `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f` equals the asserted pin in [builds/target.json](../builds/target.json). |
| Principal function RVAs | `0x151a160` (pass builder), `0x1547d20` (technique setup), `0x15896a0`, `0x15896d0` (stage keys), `0x1548820` (material setup), `0x154c9a0`, `0x154cbf0`, `0x154cc50` (texture binds), `0x1549550`, `0x154a900` (geometry setup and restore), `0x1523f00`, `0x1524f10` and other class variants (default textures), `0x101d750` (default texture creation), `0x14ec0a0` (`BSShaderManager::GetTexture`), `0x15195d0` (`InitializeShader`), `0x153b3d0` (texture set slot write), `0x14e8480` (LOD fade), `0x1519140` (fade setting cache), `0x155ff40`, `0x1560d10`, `0x1562270`, `0x1578ad0`, `0x1578930` (pass state), `0x102abd0`, `0x102b120`, `0x102b680`, `0x102b6c0` (state tables), `0x151e4e0`, `0x1561610` (grouping), `0x151ef40`, `0x151fd60`, `0x151ff00` (first stage and decals), `0x1539f10` (`Main::RenderWorld`), `0x2b3380` (land property setup). Function labels are GUESS unless a CrashLogger name appears. |
| Sources and revisions | Pinned executable. Shipped shader package member `shadersfx/shaders011.fxp`, SHA-256 `72cfc73eb0938d5949f0b3a8683722a33b671a34b41b750ba138de8d154c5fbc`, from `Skyrim - Shaders.bsa`. Shipped `Skyrim_Default.ini`, `Low.ini`, `Medium.ini`, `High.ini`, `Ultra.ini`. Published cross-checks: [object-lod-ambient-sun-retail-facts.md](object-lod-ambient-sun-retail-facts.md) (#1003), [exterior-haze-trace-retail-facts.md](exterior-haze-trace-retail-facts.md) (#1077), [terrain-lod-vs-near-retail-facts.md](terrain-lod-vs-near-retail-facts.md) (#946), [near-t19-order-retail-facts.md](near-t19-order-retail-facts.md) (#979), [interior-point-light-look-retail-facts.md](interior-point-light-look-retail-facts.md) (#1258, with its 2026-11-25 amendment). |
| Source exposure | Pinned native binary analysis and shipped shader bytecode decoded locally and offscreen with an SDK disassembler under Wine. Renderer state-table routines and the default-texture routine ran in a private CPU emulator with stub callees (author run). Committed CrashLogger tables on `origin/main` for names and layouts. **No value was read from any game plugin.** No game mesh or texture archive was read. No decompiler text and no disassembly appears below. No downstream or sibling source was used. |
| Name provenance | CRASHLOGGER_PDB(59818@2026.10.24): property flag names and the `Feature` ids, class names `BSLightingShaderProperty`, `BSLightingShaderMaterial*`, `NiAlphaProperty` and the field names quoted. The generated flag enum keeps the names above bit 31 in order but without values. The bit numbers here follow that order, and the uses of bits 33 to 61 in the pass builder agree with it. Key-bit names are strings of the image. `NiAlphaProperty` blend factor names are public NIF format names (**inferred**). Other labels are GUESS. |
| Intended recipient | Skyrim Research department lead for boundary review under [docs/clean-room.md](../docs/clean-room.md). Proposed use: Mudcrab research item 35 and issue #984. Maintainer transfer decision pending. |

Addresses are RVAs for image base `0x140000000`, including global bytes. `cbN[i]` is pixel constant buffer N, float4 element i, unless the text says vertex. `sat` bounds to [0,1]. **Verified** means re-read at the cited static source. **Inferred** means a deduction with assumptions. **Unverified** means the evidence leaves the claim open. The document holds facts and formulas only.

## Question and method

Which Lighting permutations does an ordinary world frame use for these features? What selects them, and what does each one add? How do alpha test, blending, decals and emissive surfaces work? What is bound when a texture slot is empty?

Method: static reading of the pass builder, the three Lighting setup routines, the material default routines and the batch renderer, plus a decode of group 6 (Lighting) shader records. Group 6 holds 6,924 pixel records. The pixel constant slots named below were checked against the record header tables.

The author run traced which inputs feed each instruction. It covered technique 0 (2,292 records), technique 1 (1,152), 2 (576), 3 (72) and 8 (18), and a spread sample of techniques 4, 5, 6 and 16. The independent reviewer used its own token parser and interpreter with random inputs. It ran all records of techniques 0 to 6 and 16 (5,724) for the alpha rules, and the checks named in the groups. A dependency check or a random-input check is not a symbolic proof for every record. The full algebra was read in the base keys of each technique.

## Observations

### G01. Technique id and the predicates that select it

**Verified** (`0x151ab46–0x151adb8`). The builder takes the technique from the 64-bit property flag word (`BSShaderProperty` `+0x38`). Rules apply in order, and a later rule replaces an earlier one. The table lists them from highest priority to lowest.

| Technique | Name (image string) | Predicate (bit numbers) |
|---|---|---|
| 16 | Eye | bit 17 |
| 14 | MultiIndexTriShapeSnow | bits 23 and 41 both set |
| 12 | TreeAnim | bit 61 |
| 11 | MultiLayerParallax | bit 56 |
| 15 | LODObjectsHD | bit 63 |
| 13 | (LOD objects) | bit 34 |
| 18 | LODLandNoise | bit 33 |
| 19 | MultiTexLandLODBlend | bit 46 |
| 8 | MultiTexLand | bit 14 |
| 7 | ParallaxOcc | bit 28 |
| 6 | HairTint | bit 18 |
| 5 | FacegenRGBTint | bit 21 |
| 4 | Facegen | bit 10 |
| 3 | Parallax | bit 11 set and bit 28 clear |
| 2 | Glowmap | bit 38 |
| 1 | EnvMap | bit 7 |
| 0 | None | otherwise |

The technique name strings were not re-read by the reviewer.

**Verified.** A property with both the glow and environment bits uses technique 2 and gets no environment term from the technique. When `bSimpleLighting:Display` is nonzero (compiled 0), the builder uses technique 0. Technique setup replaces technique 7 by 0 while `bEnableParallaxOcclusion:Display` is zero (compiled 0, not in the five shipped INIs) (`0x1547d61–0x1547d71`). It replaces technique 18 by 9 only while byte `0x20d681f` is zero (image value 1).

**Verified, distance drop of features** (`0x151a28b–0x151a45f`, helper `0x14e8480`). The helper takes a distance-like value `a` from the object's fade node (`+0x144`) and a Start and End. A second value (`+0x148`) only controls a refresh marker. If `a > End`, the test fails. Else the fade is `clamp((a − End)/(Start − End), 0, 1)` when `a > Start`, and 1 otherwise.

| Feature | Compiled Start / End | On failure |
|---|---|---|
| Specular (`fSpecularLODFade*`) | 0.09 / 0.10 | flag bit 0 is ignored for this build of the pass (bit 41 stays) |
| Environment map (`fEnvmapLODFade*`) | 0.09 / 0.10 | unless bit 60 (snow) is set, flag bit 7 is ignored for this build, so another rule picks the technique |
| Decals, bits 26 or 27 (`fDecalLODFade*`) | 0.05 / 0.06; `Skyrim_Default.ini` has 0.45 / 0.5 | alpha factor 0, no pass. Skipped when bit 35 or 41 is set |
| Refraction (`fRefractionLODFade*`) | 0.025 / 0.03 | no pass. Skipped when bit 35 is set |

**Verified** (`0x151a22d`). The four distance rules in this table, and the pass fade of G05, are skipped when accumulator byte `+0xb9` is nonzero.

**Unverified.** The producer and units of the fade-node values. Which INI file values a player's setup applies. A second distance branch for decals that applies to one special fade node (`0x151a2ef–0x151a387`). Whether the NIF loader forces the flag bits to agree with the serialized shader type. The technique reads flags, and material setup reads class fields by technique.

**Confidence: high** for the predicates and order. **Medium** for the flag names above bit 31 (order-derived). What would change it: a capture of raw pass ids, or a second writer of the technique.

### G02. Key bits that matter here

**Verified** (`0x151a92d–0x151ab42`). Raw key = `technique << 24 | bits`.

| Raw key bit | Image name | Set when |
|---|---|---|
| 0 | none | flag bit 37 (vertex colours) |
| 1 | none | flag bit 1 (skinned) |
| 2 | `Msn` | flag bit 12 |
| 3–5, 6–8 | none | point-light count, shadow-light count |
| 9 | `Spec` | flag bit 0 or 41; also forced, together with bit 21, by an object snow rule |
| 10 / 11 / 12 | `Soft` / `Rim` / `Back` | flag bit 57 / 58 / 59 |
| 13 / 14 | none | sun shadow mask, local shadow masks |
| 15 | `Projuv`; `DWDecals` on technique 6 | flag bit 23; also a decal with flag bits 32 and 18 |
| 16 | `Aniso` | flag bit 53 |
| 20 | `Atest` | see G05 |
| 21 | `Snow` | snow rules (landscape: a layer snow value equal to 1) with `bEnableImprovedSnow` |
| 22 | `CharLight` | flag bit 40 |
| 23 | none | screen-door fade, see G05 |

**Verified** (`0x151aa9e–0x151aaf6`). With `bEnableImprovedSnow` nonzero, bits 9 and 21 are both set in two cases. Case (a): property flag bit 60 is set, and bits 33, 34, 46, 61 and 63 are clear. Case (b): property flag bit 30 is set, and bits 33, 34, 46 and 63 are clear. This rule tests no landscape bit (bit 14).

**Verified.** Vertex key = `(raw & 0x48007)`, plus bit 9 when any of raw bits 9, 11 or 17 is set, plus the technique (`0x15896a0`). Pixel key = `(raw & (0xfffffe05 | ((raw >> 1) & 2))) | 1`. So pixel bit 0 is always set, bits 3 to 8 drop, and bit 1 survives only together with bit 2 (`0x15896d0`).

**Confidence: high.** Not traced here: where raw bits 17 and 19 come from in every case.

### G03. Environment map (technique 1)

**Verified** (records `01000001`, `01000201`; vertex record `01000001`; all 1,152 technique-1 pixel records).

```text
V = normalize(TEXCOORD5)                 ; camera position − surface position, world space in VS 01000001
N = unit lighting normal from t1 (same frame as V in that pair)
R = 2·dot(N,V)·N − V
m = t1.a + h·(t5.r − t1.a)               ; h = cb1[2].y
E = t4.sample(R).rgb · m · cb1[2].x · cb2[3].x
L = A · Σ · vc.rgb + E · Σ               ; A = t0.rgb on keys without bit 15
```

| Slot | Content | Producer |
|---|---|---|
| `t4` (cube), `t5` | environment cube, mask | material `+0xa0`, `+0xa8` (`0x15489e3`) |
| `cb1[2].x` | `envMapScale` | material `+0xb0` |
| `cb1[2].y` | 1 if the material mask texture pointer is non-null, else 0 | `0x15489bb–0x1548a05` |
| `cb2[3].x` | `envmapLODFade` | property `+0x104`, uploaded for techniques 1, 11 and 16 (`0x154972c`) |

**Verified.** `E` does not depend on `t0` or vertex colour. `E` multiplies the same light sum that multiplies the albedo. This was checked on all 1,008 records without key bit 15, with any key-bit-17 term set to zero. With only emission lit, the added value is `E × emission` on all 1,152 records. So the environment term is scaled by the received light. That light includes ambient, emission, the additive term and any other term that the key adds into `Σ` (for example the character-light term of bit 22).

**Verified, projected UV.** Keys with bit 15 (`Projuv`) change the albedo `A`. In record `01008001`, the colour that multiplies `Σ` is a blend of the base map with a second projected source. That blend is not decoded here. `A = t0.rgb` must not be assumed on those keys.

Key bit 17 adds a further term after the first fog and clamp stage. It does not multiply `E` (see #1258, amendment A1). The environment term sits inside `L`, before the first stage, whose limit is `PostLit` (`cb0[1].x`). The specular term is added after that stage and does not multiply `E`. None of the 6,924 group-6 pixel records reads `cb0[1].y` (the `fLightingOutputColourClampPostEnv` lane).

**Verified** (`0xee4c3d`, `0x153b3fe`, `0x1524f10`). A zero-length serialized texture path is stored as a null string, so the slot stays null. The environment material fills only the cube. So a zero-length mask path gives `h = 0`. If a non-empty mask path is loaded and the load returns no object, the slot gets the flat-normal default (G09). Then `h = 1` and `m = 128/255`. Whether a load of an absent file returns no object is unverified. The eye material fills a null mask with the flat-normal default.

**Confidence: high** for the formula and the dependencies on keys without bit 15. **Medium** for the world-space frame in other vertex variants (one non-skinned vertex record read). What would change it: a technique-1 pixel record that combines `E` after the diffuse multiply (none found), or the skinned vertex records.

### G04. Glow map and property emission (technique 2, issue #984 emission multiplier)

**Verified** (`0x1549f3a–0x1549f9c`; record header slot). `cb2[4].yzw = emissiveColor × emissiveMult`. `emissiveColor` is the colour that the pointer at property `+0xf0` addresses. `emissiveMult` is property `+0xf8`. This upload has no flag test and no clamp.

**Verified** (record `02000001`; all 576 technique-2 pixel records).

```text
plain:  Σ = S + P + Amb + cb2[4].yzw + Add
glow:   Σ = S + P + Amb + cb2[4].yzw · t6.rgb + Add
L = A · Σ · vc.rgb      ; A = t0.rgb on keys without bit 15; hair differs, see G13
```

`S` is the sun term, `P` the point-light sum and `Amb` the directional ambient. `Add` is `cb1[8].x × cb1[8].yzw`. #1003 G05 states that `Add` is zero at start-up.

**Verified.** With only emission lit, the colour is proportional to `t6.rgb` on all 576 records. It is zero when `cb2[4].yzw` is zero.

**Verified.** `t6` is material `+0xa0` (`0x1548918`). Emission is not added after the albedo multiply. On keys without bit 15, black base colour gives zero emission in `L`. There is no separate additive emission output.

**Verified, negative.** Flag bit 29 (external emittance) and bit 22 (own emit) set no key bit in the Lighting pass builder. **Unverified:** the code that repoints `+0xf0` for external emittance, and its source colour.

**Confidence: high.** What would change it: a record of another technique that reads a glow map (not searched beyond techniques 0 to 3, 8 and samples).

### G05. Alpha test, property alpha and screen-door fade

**Verified** (`0x151a46c–0x151a4aa`, `0x1549f11–0x1549f33`). Property alpha (`+0x30`) = material alpha (`+0x80`) × the pass fade (fade node `+0x130`, times the decal fade). The fade is skipped (factor 1) when accumulator byte `+0xb9` is nonzero. One fading path for geometry without blending resets property alpha to material alpha (`0x151ac58–0x151ac68`). The geometry upload puts property alpha in `cb2[3].z`, times one more fade value on one pass mode.

**Verified** (records `00100001` and the sweeps). With the `Atest` key:

```text
alpha = t0.a · cb2[3].z · vc.a
discard if alpha < cb11[0].x
```

**Verified exception, hair decals** (technique 6 with key bit 15, `DWDecals`). All 192 such records carry `Atest`. Example: record `06108001` against `06100001`. With `alpha` as above (`t0.a × vc.a` with bit 23):

```text
discard if alpha < 4/255
alpha2 = sat(1.05 · alpha)        ; alpha output
discard if alpha2 < cb11[0].x
```

**Verified, scope.** All 5,724 pixel records of techniques 0 to 6 and 16 were run: 5,532 follow the base alpha, test and screen-door rules of this group. The other 192 follow the hair-decal rule. Other techniques were not checked.

**Verified** (`0x1578930–0x1578977`). The reference is `trunc(threshold × propertyAlpha) / 255`, with `threshold` the `NiAlphaProperty` byte `+0x32`. It is set when the pass is drawn in an alpha-test list. The upload gives zero when alpha test is off (from #1003 G05). The comparison is fixed: keep when `alpha ≥ ref`. The state setup reads only the alpha-property flag bits 0 (blend), 1 to 8 (factors) and 9 (test). It does not read the test-function bits.

**Verified** (`0x151a56c–0x151a5ef`, `0x151aa7f–0x151aa9a`). Call a pass **blended** when `materialAlpha × fade < 1` or alpha-property bit 0 is set. With byte `0x3336405` at its image value 0, the `Atest` key bit is set when one of these is true:

- The pass is blended and alpha-property bit 9 (test) is set.
- The property is a decal (flag bit 26 or 27) and flag bit 41 is clear.

When that byte is nonzero, any alpha-tested property also gets the bit. So an **opaque, non-decal, alpha-tested** surface normally gets no `Atest` key in the main Lighting draw. `Main::RenderWorld` sets accumulator byte `+0x5c` (`0x1539fb6`) and finishes that same accumulator (`0x153a02f`). With that byte set, the first stage draws its early lists with depth function EQUAL and no depth write (`0x151ef5a–0x151ef98`). It returns to test-and-write before group 0 (`0x151f0a2–0x151f0dd`). **Inferred.** The cutout of those surfaces comes from the earlier depth pre-pass. That pre-pass shader was not decoded.

**Verified** (records with key bit 23, for example `00900001`; all records of techniques 0 to 6 and 16). Key bit 23 adds a screen-door discard. Discard when `cb2[3].z < T[4·(x mod 4) + (y mod 4)]`, with pixel coordinates `x, y` and `T` = (0.003922, 0.533333, 0.133333, 0.666667, 0.8, 0.266667, 0.933333, 0.4, 0.2, 0.733333, 0.066667, 0.6, 0.996078, 0.466667, 0.866667, 0.333333). In those records the alpha output and the alpha test use `t0.a × vc.a`, without property alpha.

**Inferred.** The builder sets bit 23 from a fade condition: `bEnableStippleFade:Display` (compiled 1), a fade-node byte `+0x154`, fade below 1, and flag bit 19 clear. The same path for geometry without blending clears the condition again. The full set of draws that receive bit 23 was not enumerated.

**Confidence: high** for the discard formulas and the reference. **Medium** for the opaque cutout path (pre-pass not read). What would change it: a decode of the pre-pass records, or a runtime writer of byte `0x3336405`.

### G06. Blend state, cull and depth for ordinary and transparent geometry

**Verified** (`0x1578ad0–0x1578c75`). This runs per pass when render flag `0x4` is on and a pass-id test (`0x1521170`) is false (`0x156229a–0x15622c2`). The sorted draws of the second stage use that flag (from #1077).

1. If property alpha < 1, or alpha-property bit 0 is set, the routine picks a blend mode from the factors below. With property alpha < 1 and bit 0 clear, the mode is 1.
2. Else the mode is 0 (opaque).
3. Alpha-test enable follows alpha-property bit 9 when the pass is in an alpha-test list.

`src` = alpha flags bits 1 to 4, `dst` = bits 5 to 8. The factor names are **inferred** from the public NIF enumeration.

| (src, dst) | Names | Blend mode |
|---|---|---|
| (6, 7) | SrcAlpha, InvSrcAlpha | 1 |
| (6, 0), (0, 0), (6, 9) | SrcAlpha/One, One/One, SrcAlpha/InvDestAlpha | 2 |
| (4, 7) | DestColor, InvSrcAlpha | 3 |
| (1, 2), (4, 1) | Zero/SrcColor, DestColor/Zero | 4 |
| any other pair | | this routine does not change the mode |

**Verified** (state table built by `0x102abd0`). All operations are ADD.

| Mode | Colour source, destination | Alpha source, destination |
|---|---|---|
| 0 | blending off | |
| 1 | SRC_ALPHA, INV_SRC_ALPHA | SRC_ALPHA, INV_SRC_ALPHA |
| 2 | SRC_ALPHA, ONE | SRC_ALPHA, ONE |
| 3 | DEST_COLOR, INV_SRC_ALPHA | DEST_ALPHA, INV_SRC_ALPHA |
| 4 | DEST_COLOR, ZERO | ONE, ZERO |

So a serialized One/One pair draws as SrcAlpha/One. The default table variant blends render target 0 only. A second variant blends targets 0 to 2 and is selected around some second-stage draws (`0x1010600`). The reviewer did not check that selection site.

**Verified, batch lists.** Cull: flag bit 36 (two-sided) puts the pass in a list drawn with cull NONE. Else the cull is BACK (render flags `0x108` suppress the change) (`0x1560d4b–0x1560d86`, `0x155ff40`; rasterizer table `0x102b6c0`). Flag bit 54 picks a fifth list (alpha test, cull back).

**Verified** (`0x154a712–0x154a79f`). For non-decal draws, flag bit 32 (Z write) clear changes the depth state to test without write for that draw. Flag bit 31 (Z test) clear disables depth. The state is restored after the draw.

**Verified** (`0x151a920–0x151ac0c`, `0x151e5f0–0x151e842`, `0x15617d0`). A blended non-decal Lighting pass at full fade gets accumulation hint 1. The main accumulator puts it in a separate list that the second stage sorts and draws. Fading objects use other hints. **Unverified:** the sort key.

**Confidence: high** for the tables and the mapping. **Medium** for the claim that these are the only state writes on a given draw (effect and special paths were not all traced).

### G07. Decals

**Verified** (`0x151a920–0x151a92a`, `0x151e632–0x151e66d`). A decal is a property with flag bit 26 (decal) or 27 (dynamic decal). A non-blended decal gets hint 2 (draw group 3, only when accumulator byte `+0x12c` is set). A blended decal gets hint 3 (group 4). The technique and pixel key follow G01 and G02 like any other geometry. No decal-only key bit or tint constant was found, apart from bit 15 on hair (G02) and the forced `Atest` bit (G05). The hair bit-15 records change alpha only, as in G05. That comparison used one record pair.

**Verified** (first stage `0x151ef40`, append table slot 0 = `0x151e4e0`). Order: default lit lists; groups 9, then an id window, then groups 8, 1, 0, another window, group 13; then **decals**; later windows; then the fog composite (outside this routine); then the second stage. Group 3 draws first. A second opaque decal group follows (group 2, filled from an extra object list with hint 12). The blended group 4 follows.

| State | Non-blended decals (groups 3, 2) | Blended decals (group 4) |
|---|---|---|
| Depth | LESS_EQUAL, write on | LESS_EQUAL, write off (render flag `0x20` instead gives write on and no bias change) |
| Rasterizer bias | `DepthBias −1`, `SlopeScaledDepthBias −0.65`, clamp −100 | same values |
| Colour write | all targets written, except target 1 (state mode 10) | target 0 only (mode 11) |
| Blend | per-pass setup depends on the stage render flags; not traced for these groups | per-pass setup from the alpha property is forced on (render flag `0x4`) |

**Verified** (`0x102b680`, called at `0x1007e36` in renderer init; state flush `0x101106c–0x10110fa`). The depth bias has a second part. For a non-zero bias mode, the state flush sets the viewport `MaxDepth` to the current default maximum (image value 1.0) minus a per-mode value. That value is non-zero for all the decal modes below.

| Draw | Mode (raster bias −1, −0.65) | `MaxDepth` reduction | Mode with byte `0x3436311` nonzero (raster bias 0, 0) | Its reduction |
|---|---|---|---|---|
| Opaque decals, group 3 | 6 | 2.6e-5 | 7 | 1.5e-5 |
| Second opaque group 2 | 8 | 2.8e-5 | 9 | 1.7e-5 |
| Blended decals, group 4 | 10 | 3.0e-5 | 11 | 1.9e-5 |

So modes 7, 9 and 11 are not free of bias. When byte `0x20d683a` is zero (image value 1; a console command writes it), groups 3 and 2 use mode 0: no bias and no reduction. It gates only the opaque groups. Byte `0x3436311` has the image value 0. With render flag `0x20`, group 4 keeps the current bias mode.

**Verified** (`0x1549675–0x15496a9`). A hint-3 decal whose property also has flag bit 32 (Z write) replaces the write mode for its draw: target 0 colour without alpha, all other targets written.

**Inferred.** Target 1 is the motion-vector output (the records compute o1 from current and previous positions).

**Verified, scope.** Alpha: decals carry the `Atest` bit, and the reference is nonzero only when the alpha property enables testing (G05). Decal fade multiplies property alpha (G01).

**Unverified.** Runtime-created decals (projected geometry and simple temporary decals): their colours, emissive values and property flags were not traced.

**Confidence: high** for the order, depth, bias and masks of the grouped decal draws. **Medium** for "no decal tint term" (negative, static, Lighting only). What would change it: a frame capture, or the temporary-decal setup code.

### G08. Fog for decals, blended and additive surfaces (issue #984 fog treatment)

**Verified here** (call order, G07). Decals draw in the first accumulator stage. In `Main::RenderWorld`, the first-stage call (`0x153a02f`) precedes the composite call (`0x153a1ca`).

**From #1077, not re-read:** the first stage runs with `(S, T) = (1, 0)`, so the pixel tail returns `L` (limited) and does not write fog. A depth-based composite then fogs the frame. The sorted draws of the second stage run with `T = 1` and write `min(k × M, B)`, where `M = L + F × (Cf − L)`. The reviewer did not trace the identity of the second-stage call.

**Inferred.** A non-blended decal writes depth, so the composite fogs it at its own depth. A blended decal writes no depth, so it takes the fog of the depth already there.

**Inferred.** A blended Lighting surface in the sorted list, including an additive one (blend mode 2), outputs the fogged and scaled colour. The blend then multiplies it by source alpha and adds it. The fog colour is therefore part of the added colour.

**Verified, negative.** The Lighting technique, material, geometry and shared fog routines (`0x1547d20–0x15487be`, `0x1548820–0x15494e3`, `0x1549550–0x154bb90`, `0x154c010–0x154c1c6`) never read the blend-mode word `0x20cfca8`. So they do not switch the fog colour or strength for additive blending.

**Unverified.** The effect shader family (a different shader group). Many additive surfaces may use it, and this finding does not cover it.

**Confidence: medium.** What would change it: a writer of fog constants per blend mode outside these routines, or an effect-shader trace.

### G09. Empty and missing textures

**Verified** (creation routine `0x101d750`; global base `0x33363a0`). Compiled default textures, RGBA bytes:

| Default (image name) | Size | Value |
|---|---|---|
| `BSShader_DefNormalMap` | 16×16 | (128, 128, 255, 255) |
| `DefaultWhiteMap` | 1×1 | (255, 255, 255, 255) |
| `DefaultGreyMap` | 1×1 | (128, 128, 128, 128) |
| `BSShader_DefHeightMap` (also the "black" slot) | 16×16 | (0, 0, 0, 255) |
| `BSShader_DefCubeMap` | 4×4 | (0, 0, 0, 0) |
| `BSShader_DefFacegenDetail` | 16×16 | (64, 64, 64, 64) |

**Verified** (`0x1523f00` and the class variants; each fills only a null material pointer).

| Material slot | Default when null |
|---|---|
| Base colour `+0x48`, normal `+0x58` (all classes) | normal-map default (but see property bit 20 below) |
| `+0x60` with rim or soft lighting; `+0x68` with back lighting | normal-map default |
| `+0x68` when the property has specular (bit 0 or 41) and model-space normals (bit 12), if still null (back lighting did not fill it) | black |
| Environment: cube `+0xa0` | zero cube, so `E = 0` |
| Environment: mask `+0xa8` | stays null; setup binds the normal default and sets `cb1[2].y = 0`, so the mask is `t1.a` |
| Eye: cube; mask | zero cube; normal default (so the mask flag is 1 and `m` = 128/255) |
| Glow map `+0xa0` | white |
| Parallax and parallax-occlusion height `+0xa0` | black (`h = 0`, offset `−0.04 × V.xy`) |
| Face: tint `+0xa0`; detail `+0xa8`; third `+0xb0` | grey; facegen detail; black |
| Multilayer: `+0xa0`; cube `+0xa8`; mask `+0xb0` | normal default; zero cube; normal default |
| Landscape: layer maps, overlay `+0xf8`, noise `+0x100` | normal-map default |

**Verified** (`0x151968f–0x15196d5`). When property flag bit 20 is set, `InitializeShader` replaces the base colour map with the black default and sets its clamp mode to 3.

**Verified** (`0xee4c3d`, `0x153b3fe`). A zero-length serialized path gives a null path string. The texture set write then leaves the slot null, and the class fill in this table applies. The `GetTexture` fallback below applies only when a load is requested.

**Verified.** For techniques 8 and 19, technique setup first binds the black default to all 16 pixel texture slots (`0x1548064–0x15484e5`). Material setup then binds the layers that the material counts: layer `i` diffuse to slot `i + 1` and normal to slot `i + 8`, with the base maps in slots 0 and 7 (`0x1548b04–0x1548c69`).

**Verified** (`BSShaderManager::GetTexture`, `0x14ec0a0`). When a load returns no object, the routine logs a "TEXTURE ERROR" line. It returns the zero cube for a cube request and the normal-map default otherwise. A null path takes the same fallback. Two special marker path prefixes also give the normal default.

**Unverified.** Whether the loader returns null at run time for a file that is absent from disk (it may return a pending object). Which draws bind a different placeholder. Whether any shipped asset leaves the base colour slot empty was not checked.

**Confidence: high** for contents and fill rules. **Medium** for the missing-file behaviour.

### G10. Landscape specular (techniques 8 and 19)

**Verified** (`0x2b3600–0x2b3658`). Land property setup sets flag bits 14 and 8, bit 9 from the land shadow setting, bit 46 from a caller condition, and bit 0 from `bLandSpecular:Landscape` (compiled 1; not in the five shipped INIs). Bit 46 selects technique 19.

**Verified** (record `08000201`; all 18 technique-8 pixel records for colour). With layer weights `w0..w5` = `TEXCOORD6.xyzw`, `TEXCOORD7.xy`:

```text
albedo = Σ wi · t[i].rgb                  ; i = 0..5
n_ts   = Σ wi · (2·t[7+i].rgb − 1)
a      = Σ wi · t[7+i].a
g      = Σ_{i<4} wi · cb1[11][i] + w4·cb1[12].x + w5·cb1[12].y
spec   = ( pow(sat(N·Hsun), g)·Csun + Σlights pow(sat(N·Hi), g)·Ci·atti ) · a · cb2[3].y · cb1[4].xyz
L      = albedo · Σ · vc.rgb
```

`spec` is added after the first fog and clamp stage. The second stage then applies the `PostSpec` limit. `cb1[11]` and `cb1[12].xy` come from the six per-layer floats at material `+0x130..0x144` (CrashLogger field `textureIsSpecPower`). The reviewer did not re-read that material source. The algebra agrees with #946 G05.

**Verified, scope.** The specular formula is for keys without bit 21 (snow). With key bits 13 or 14, the sun term or the shadow-slot light terms also carry the screen mask (#1258 G08). The 6 non-snow records with `Spec` matched the formula with the mask set to 1. The 6 snow records with `Spec` differ.

**Unverified.** The technique-19 distance blend, the snow-layer variants, and the land material specular colour and power sources.

**Confidence: high** in the scope above.

### G11. Parallax (technique 3)

**Verified** (pixel and vertex records `03000001`; all 72 technique-3 pixel records).

```text
V   = normalize(TEXCOORD5)
h   = t3.r (sampled at uv)
uv' = uv + V.xy · (0.08·h − 0.04)         ; t0 and t1 are sampled at uv'
```

One sample, no iteration. `t3` is material `+0xa0` (`0x1548a07`). In both technique-3 vertex records (`03000001`, `03000201`; neither key has the skinned bit), `TEXCOORD5` is vertex `cb2[6]` minus the unmodified model-space vertex position. For a non-skinned pass, the geometry setup writes `cb2[6]` as the camera position in model space (`0x154a61f–0x154a657`). **Verified:** neither stage rotates `V` into the tangent frame, so the offset uses the model-space X and Y of the view direction.

**Verified, writer condition** (`0x154a0c8–0x154a0e5`, `0x154a61f`). That routine writes vertex `cb2[6]` only when the raw key has `Spec`, `Soft`, `Rim`, `Back` or bit 17, or the technique is 1, 11 or 16. A technique-3 pass with none of those bits does not get the slot written there. **Unverified:** what the slot holds at such a draw. A property that loses `Spec` by the distance rule of G01 can reach that state.

Parallax occlusion (technique 7) is forced to technique 0 with the compiled setting (G01). Multilayer parallax (technique 11) is not covered.

**Confidence: high** for the offset arithmetic and the space of `V` when the slot is written. **Medium** for the writer condition (one routine read). What would change it: another writer of vertex `cb2[6]`, or a capture of that constant on a non-specular parallax draw.

### G12. Eye (technique 16)

**Verified** (vertex `10000003`, pixel `10000001`; material setup `0x1548931`). The vertex shader takes `c = lerp(eyeCentre0, eyeCentre1, TEXCOORD2.x)` (vertex `cb1[0]`, `cb1[1]` from material `+0xb4` and `+0xc0`), skins it, and outputs `Ne = normalize(skinned position − skinned centre)`.

```text
sun and point diffuse use the normal-map normal N
ambient uses Ne
R = 2·dot(Ne,V)·Ne − V
E = t4(R) · m · cb1[2].x · cb2[3].x        ; m as in G03
L = t0.rgb · Σ · vc.rgb + E · Σ
```

**Verified.** All 192 technique-16 pixel records use the sphere normal for reflection and ambient, and `E` multiplies the light sum.

**Unverified.** No reader of the cached `fEyeEnvmapLODEnd` value (`0x20d6bd0`) was found by direct reference. The effect of `bUseEyeEnvMapping`.

**Confidence: high** for the base pair and for the two points checked on all records. **Medium** for other points in the variants.

### G13. Face, face tint and hair (techniques 4, 5, 6)

**Verified** (base keys `04000001`, `05000001`, `06000001`, `06000201`). `a = t0.rgb`.

```text
Facegen:   D = (t4.rgb + (1/255, 0, 1/255)) · 255/64
           base = D · (a² + 2·t3.rgb·a·(1 − a))
Face tint: base = (a² + 2·c·a·(1 − a)) · (259/256, 255/256, 259/256)      ; c = cb1[1].rgb
Face and face tint:  L = base · Σ · vc.rgb
Hair:      L = a · Σ · (1 + vc.g · (c − 1))                                ; c = cb1[1].rgb
```

| Slot | Content | Source |
|---|---|---|
| `t3` | face tint map | material `+0xa0` |
| `t4` | face detail map | material `+0xa8` |
| `t12` | third map; declared by 312 of the 456 face records, exactly those with the `Soft` bit | material `+0xb0` (`0x1548a52`) |
| `cb1[1]` | face tint and hair tint colour | material `+0xa0..0xa8` (`0x1548a93`) |

**Verified.** The face and face-tint albedo formulas hold on all 456 and 408 records. The hair vertex-green rule holds on all 576 records. Key-bit-17 terms were set to zero for these tests. Hair does not multiply RGB by vertex colour. Green is the tint weight. Alpha still uses vertex alpha, with the hair-decal exception of G05. The hair specular term of `06000201` is the standard half-vector term and is not tinted.

**Not covered.** Anisotropic hair terms, soft, rim, back and subsurface lighting.

**Confidence: high** for the rules above. **Medium** for terms that the tests did not cover.

### G14. Refraction

**Verified** (`0x151a415–0x151a45f`, `0x151a6bb–0x151a77e`). When flag bit 2 (temporary refraction) or bit 15 (refraction) is set, the builder emits one pass for the utility shader with accumulation hint 4 and skips the Lighting pass. The utility pass id carries variant bits for vertex colour, skinning, model-space normals, refraction falloff (bit 16) and flag bit 13. The distance rule of G01 can drop it.

**Unverified.** The utility shader output, where the main world frame consumes draw group 5 (a direct draw of that group was found only in the first-person view routine), and the image-space refraction combine. This feature is therefore only partly covered.

**Confidence: high** for the selection. **Low** for the frame effect.

## Interpretation and alternatives

**Inferred.** A renderer differs from the static retail rules above if it does any of these:

- It adds the environment sample after the diffuse multiply without the light sum.
- It adds emission after the albedo multiply.
- It compares an alpha-test reference that ignores property alpha.
- It draws One/One as pure One/One.
- It applies one fog path to both decals and sorted transparent surfaces.

This file makes no claim about how any of that looks.

Static reading does not exclude these alternatives: a property flag set that differs at run time from the serialized one; console-toggled bytes (`0x3336405`, `0x20d683a`, `0x20d681f`); INI values from the user's preference files; effect-shader or utility-shader draws for surfaces that look like Lighting features.

## Implementable now vs open

**Implementable now** (static, verified, with the scope in each group):

- Technique selection priority and flag predicates, compiled remaps and key bits.
- Environment map and eye formulas on keys without bit 15, with the mask selection of G03.
- Emission and glow inside the light sum.
- Alpha value, reference, discard, screen-door table and the hair-decal exception.
- Alpha-property factor to blend-state mapping, cull and per-draw depth override.
- Decal grouping, order within the first stage, depth and write masks, raster bias and viewport offset (default byte states).
- Class fill of empty texture slots, default texture contents and the property bit 20 override.
- Landscape specular (non-snow), parallax, face, face tint and hair base colour.

**Open:**

- The depth pre-pass that cuts opaque alpha-tested geometry (only the EQUAL-depth draw is verified).
- The projected-UV albedo blend; soft, rim, back, ambient-specular, anisotropy and snow terms.
- NIF flag normalisation; fade-node distance inputs; live INI and console byte values, including `0x3436311`.
- Whether a load of an absent file returns no object.
- The effect shader (additive surfaces), runtime decals, the external emittance source, the refraction frame path and the sorted-list order.

## Negative results and limitations

- Not covered: effect shader (additive glows and many decal-like surfaces), multilayer parallax, parallax occlusion, tree animation, soft, rim and back lighting, ambient specular, anisotropy, the projected-UV blend, snow, character light, wetness, LOD techniques (covered by other findings), runtime decals, the external emittance source, the refraction frame path, the depth pre-pass shader and the first-person view.
- Unverified: fade-node distance values, NIF flag normalisation, the pre-pass cutout, sorted-list order, the meaning of targets 1 and 2, and the live values of any INI setting or console byte.
- The author run checked techniques 4, 5, 6 and 16 by sample. The reviewer ran all their records only for the checks named in G05, G12 and G13.
- Record checks used decoded shader bytecode and random inputs. They are not a proof of every branch.
- No value from a plugin, mesh or texture file was read.
- Static reading gives code paths, constants and shader arithmetic. It does not give in-game values or appearance.

## Relation to earlier findings

- **#1077** (exterior haze trace), G08. That group records six renderer state word pairs (`0x20cfcbc/cfc` and following) and marked their meaning unverified. This finding closes that point (**G15b**). They are per-texture-slot sampler words. The Lighting texture bind routine writes the material clamp mode into `0x20cfcbc + 4 × slot` (`0x154c9a0`). The second array `0x20cfcfc + 4 × slot` holds the filter mode that setup writes per slot. At `0x154852e–0x1548591`, the 3 is the address mode and the 1 is the filter mode, for slots 0 and 1. That branch of technique setup runs for techniques 9 and 18. They are not blend or write-mask words. **Verified, high** for the per-slot indexing. **Inferred** for the enum meaning of the second array. This is not an error in #1077, and this change does not edit that file. G08 here also takes its two-stage fog statement from #1077.
- **#1258** (interior point-light look, with its 2026-11-25 amendment). No claim there is contradicted. Its amendment A4 already states that raw key bit 1 is the skinned flag, that bit 2 is the model-space-normal flag, and that the pixel key keeps bit 1 only with bit 2. One scope note (**G15a**): raw key bit 0 is the property vertex-colour flag (bit 37), and the pixel key transform forces pixel bit 0 to 1. So "bit 0 always set" is a statement about the pixel key only (G02). **Verified, high.** This finding adds the technique-specific environment, glow and alpha terms to its light sum.
- **#979** (near terrain technique 19 term order). It states the same order for the near landscape terms that G10 uses: vertex colour multiplies the lit near layers, and highlights enter after the first fog-dependent bound. Its keys with bit 21 (the snow bit of G02) alter the layer lighting path, which agrees with the snow scope in G10. This finding does not decode the technique-19 distance blend. No correction.
- **#946** (terrain LOD versus near landscape): the G10 algebra agrees with its G05. No correction.
- **#1003** (object LOD ambient and sun): G04 and G05 use its statements on `Add` and on the zero alpha reference. No correction.

## Independent review

A separate fresh-context Sonnet 5.5 run reviewed the author's draft. Sol was unavailable on a usage limit. The reviewer was not the author. It saved its independent results before it read the draft and the author's handoff. **Disclosure:** its brief listed the author's claims in summary. So the independent results knew the claimed answers, but not the author's evidence. The reviewer did not use the author's tools, work directory or decoded records. It extracted the shader package again and wrote its own shader parser and interpreter.

| Group | Outcome | Note |
|---|---|---|
| G01. Technique and predicates | Corrected (minor) | The distance rules are skipped when accumulator `+0xb9` is set. Technique name strings not re-read. Applied. |
| G02. Key bits | Corrected | The "(non-landscape)" qualifier of the snow rule had no support in the code. Replaced with the two cases. Applied. |
| G03. Environment map | Corrected (scope, wording) | Algebra confirmed. `t0` is not the albedo on projected-UV keys. The mask condition is "pointer non-null". Bit-17 term added. Applied. |
| G04. Glow and emission | Corrected (scope) | Confirmed, with the same projected-UV scope. Applied. |
| G05. Alpha | Corrected | Added the hair-decal rule (fixed 4/255 cut and 1.05 scale). Applied. |
| G06. Blend, cull, depth | Confirmed | Mapping, descriptors, cull lists and the Z override re-read. The second blend variant site and the sort key not checked. |
| G07. Decals | Corrected | Added the viewport `MaxDepth` reduction. The zero-raster-bias modes still shift depth. Applied. |
| G08. Fog treatment | Confirmed | The negative claim and the call order re-checked. Fog arithmetic rests on #1077 and #1258. |
| G09. Missing textures | Corrected | Added the property bit 20 black base, the specular condition on the black map, and empty path against failed load. Applied. |
| G10. Landscape specular | Confirmed | Scope note on snow keys and screen masks added. Material source not re-read. |
| G11. Parallax | Confirmed | Offset, space of `V` and writer condition re-derived. |
| G12. Eye | Confirmed | All 192 records. |
| G13. Face, tint, hair | Confirmed | All records, not only the sample. |
| G14. Refraction | Confirmed (selection only) | The frame effect stays open. |
| G15a. Note on a draft of #1258 | Corrected | The draft text was stale. #1258 had merged with amendment A4. Replaced by the note under "Relation to earlier findings". |
| G15b. Sampler words of #1077 | Confirmed | Per-slot indexing re-read. The filter enum meaning stays inferred. |

Result: 8 confirmed, 8 corrected, 0 rejected, 0 wholly unverified. No main environment-map, glow, alpha-reference, blend-mode, parallax, eye, face or hair formula was wrong. The corrections add missing terms and scope. The reviewer did not trace the depth pre-pass cut, the position of the fog composite relative to the sorted transparent draws, or sampler state enum meanings.

After the review, a later Sonnet 5.5 run applied the corrections. It also re-read these items in the pinned image and in records it decoded again. All matched the text above.

1. The accumulator `+0xb9` branch over the fade and distance rules.
2. The object snow rule: both flag masks and the two key bits.
3. The projected-UV record `01008001`: a blended albedo, not `t0`, multiplies the light sum.
4. The environment algebra on records `01000001` and `01008001`.
5. The mask flag from the material mask pointer.
6. The zero-length path branch, the texture set slot write and the environment fill of the cube only.
7. The alpha formula on `00100001` and the screen-door index and alpha on `00900001`.
8. The hair-decal rule on `06108001` against `06100001`, and the count of 192 bit-15 records, all with `Atest`.
9. The glow record `02000001`: only emission is multiplied by `t6`.
10. The viewport offset table, its caller, the state flush, the rasterizer bias table and clamp, the decal draw modes and the byte image values.
11. The property bit 20 override and its clamp mode.
12. The empty-slot defaults: the base fill, the specular and model-space-normal black fill, and the pixel values of five compiled default textures. The zero cube contents were not re-read.
13. The parallax formula on pixel and vertex record `03000001`.
14. The face counts (312 of 456 records declare `t12`, exactly the `Soft` set) and the 5,724 record total.
15. The technique-setup jump table: techniques 9 and 18 reach the sampler-word branch. The per-slot clamp-mode write.

The later run did not re-run the snow specular records. It read no plugin.

Source exposure of the review: pinned native binary, shipped shader package and committed name tables. This is a static review. It is not match evidence for any function, and it does not decide transfer eligibility.

Reviewer and outcome: Reviewed independently by a Sonnet 5.5 run. Outcome: 8 confirmed, 8 corrected, 0 rejected. Static evidence only. Transfer status: UNREVIEWED.
