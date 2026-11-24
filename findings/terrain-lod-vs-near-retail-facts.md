Transfer status: UNREVIEWED

# Finding: terrain LOD versus near landscape shading

| Item | Evidence record |
|---|---|
| Status | OBSERVED for verified claims. INFERRED and UNVERIFIED items are marked. Static only. |
| Author | The Sol research run, `gpt-6.2-sol` via Codex (not the reviewer below). |
| Human operator | Taylor. |
| Reviewer | A separate `gpt-6.2-sol` run via Codex, high effort, fresh context. See "Independent review" below. |
| Date | Review on 2026-11-22 CST (2026-11-23 UTC). The draft date is 2026-11-23 UTC. |
| Reviewed draft SHA-256 | `6df72d173607cb248adad28e7cc304b8b8bed91c623cf1040a8c15f7c1a3aeac` |
| Build | `sse-steam-1-7-104`, retail `1.7.104.0`. Executable SHA-256 `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f`, equal to the pin in [builds/target.json](../builds/target.json). Both runs asserted the equality. |
| Principal function RVAs | `0x1527270` (near material constructor), `0x511810` and `0x511890` (terrain noise load and lookup), `0x1547d20` (technique setup), `0x1548820` (material setup), `0x1549550` (geometry setup start; `0x15496ca` lies inside the routine), `0x154bb90` (point lights), and `0x154c010` (scene fog upload). All descriptive function labels are our own names and are GUESS. |
| Source exposure | Mixed. Both runs used the operator's pinned executable, the shipped shader package, the shipped asset headers and the shipped INI templates, from the operator's retail install. Prior reviewed findings supplied asset and native anchors. No sibling source was used. |
| Name provenance | Near technique labels match the generated `Feature` enum, CRASHLOGGER_PDB(59818@2026.10.24). LOD technique labels come from the pinned image. Near material field names taken from the public generated tables carry the label CRASHLOGGER_PDB(59818@2026.10.24) at each use below. Descriptive native function labels are our own and are GUESS. Setting names come from the image and the shipped INIs. All four technique IDs have records in the shipped shader package. |
| Intended recipient | Skyrim Research department lead for boundary review under [docs/clean-room.md](../docs/clean-room.md). Proposed downstream use: the Mudcrab terrain LOD seam work (issue #939). The maintainer reports brighter terrain LOD. The downstream team reports that the colour maps decode correctly and that both sides use the same sampling rule. This finding names no cause for the reported brightness. |

All addresses are RVAs for the pinned build at image base `0x140000000`. **Verified** identifies a static read at the cited source. **Inferred** identifies an interpretation of those facts. **Unverified** identifies missing evidence. Keep listings of the game files in `.local/`. Nothing game-derived is in this file except counts, field offsets, addresses, constants, formulas and shipped asset names.

## Review verdicts

| Group | Verdict | Main correction |
|---|---|---|
| Shader coverage | Confirmed | The eight VS and 40 PS records and the key scope reproduce. |
| G01. Diffuse, sampler and colour space | Corrected | Added the shipped formats and the traced file-view creation. Scoped the shader-only result. |
| G02. Noise, distant blend and projected detail | Corrected | Added the sign and range of the noise multiplier and distinguished the two projected weights. |
| G03. Fog and target 0 | Corrected | Gave both output equations and showed that the second clamp can matter with zero highlight. |
| G04. Lighting, normals and shadows | Corrected | Identified both additive RGB sources and the masked point channel select. |
| G05. Highlights and auxiliary targets | Corrected | Added the rim ambient factor and the special sun highlight. |
| G06. Vertex colour | Confirmed | Retained the mesh RGB versus literal white distinction. |
| G07. Settings and image space | Corrected | Resolved the gamma lane and the image-space format selection. |
| G08. CPU setup, alpha and overlap | Corrected | Corrected the transition-enable lane and scoped the depth and alpha result. |

## Question and method

Which terms can differ between the retail near landscape and terrain LOD draws at the seam? The reported brightness and the sampling check motivate the comparison. The seam and its cause remain **unverified** here.

The executable SHA-256 `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f` equals the build pin. The shader archive SHA-256 is `fd1ba630f443353ed21ed4ca0380968f9c7091c8434518ea3cc79bc6d38c18e7`. Its `shadersfx/shaders011.fxp` member SHA-256 is `72cfc73eb0938d5949f0b3a8683722a33b671a34b41b750ba138de8d154c5fbc`. The method compares the decoded stage inputs, samples, constant slots, and output dependencies. It checks native binding and setting reads where the call paths establish them.

Baseline sources are the corrected terrain LOD finding (#822, `e37cab1e148b5587cba1cb41b7f3c08a948e56f8`, [terrain-lod-shading-retail-facts.md](terrain-lod-shading-retail-facts.md)), exterior fog (#812, `61776bc2b47ef7fbebdafa8354ddbc044e00b6fc`, [exterior-fog-retail-facts.md](exterior-fog-retail-facts.md)), and placed LOD (#934, `bca9a154408a8e57bab22c820e73265c3404bb63`, [placed-lod-statics-retail-facts.md](placed-lod-statics-retail-facts.md)). The LOD inventory supplied native anchors. The shadow comparison also uses the reviewed sun-shadow finding ([sun-shadows-retail-facts.md](sun-shadows-retail-facts.md)).

This finding extends #822 by comparing its terrain LOD shading terms with the near landscape techniques. Where the two overlap (noise and projected detail, lighting, near-terrain overlap and depth), it cites the corrected #822 group. For the shared fog ramp and constant writes it cites the corrected #812 group.

### Shader coverage

**Verified.** Lighting group 6 of `shaders011.fxp` contains 127 vertex shader (VS) records and 6,924 pixel shader (PS) records. The comparison checks all 48 records for the four techniques below. Concatenate each two-digit hex prefix with each listed six-digit suffix to obtain the complete key. Native anchors are package loader `0x14ea872` and feature table `0x1589648`.

| Side | Technique | Prefix | VS records | PS records |
|---|---|---|---:|---:|
| Near | 8 `MultiTexLand` | `08` | 2 | 18 |
| Near transition | 19 `MultiTexLandLODBlend` | `13` | 2 | 18 |
| LOD | 9 `LODLANDSCAPE` | `09` | 2 | 2 |
| LOD noise | 18 `LODLANDNOISE` | `12` | 2 | 2 |

| Prefixes | VS suffixes | PS suffixes |
|---|---|---|
| `08`, `13` | `000001 000201` | `000001 000201 004001 004201 006001 006201 020001 020201 024001 024201 026001 026201 200201 204201 206201 220201 224201 226201` |
| `09`, `12` | `000004 040004` | `000005 040005` |

For each suffix, the VS payloads are byte-identical across the two near techniques and across the two LOD techniques. The payloads differ between the near and LOD pairs. “Projected LOD” below means the four LOD VS/PS records with bit `0x40000` set. The remaining 119 VS and 6,884 PS of group 6, including generic Lighting, object LOD and separate snow techniques, are outside this check. Other shader groups and other passes are outside the shading comparison.

## Side-by-side summary

| Term | Near terrain | Terrain LOD | Status |
|---|---|---|---|
| Diffuse source | Six weighted layers. Technique 19 also blends toward distant RGB. | One base diffuse map. Technique 18 modulates it with noise. | **Verified difference**, G01–G02 |
| Vertex tint | VS forwards vertex `COLOR0`. | VS supplies white `COLOR0`. | **Verified difference** in the input and **verified shared** RGB multiplication, G01 and G06 |
| Base gamma and gain | No separate diffuse gain or explicit sRGB conversion found beyond the terms listed here. | Same scoped result. | **Verified** for checked arithmetic. Bound view formats **unverified**, G01 |
| Base sampler setup | Slots 0 and 1 use filter enum 3 in the traced setup. | Slots 0 and 1 use enum 1, which caps the view-relative mip at zero. | **Verified native difference**. Draw-time overrides **unverified**, G01 |
| Land noise | Technique 8 omits noise. Technique 19 uses slot-15 noise on its distant RGB before blending. | Technique 9 omits noise. Technique 18 uses slot-15 noise directly on base RGB. Projected 18 changes the strength. | **Verified shared** resource route and base noise rule. **Verified difference** in placement and projected weight, G02 |
| Normals | Six weighted layer normals and an interpolated basis. Technique 19 flattens the tangent normal toward the distant edge. A flagged subset adjusts layer normals using diffuse alpha. | One R/B/G block normal. Base LOD uses the decoded vector directly. Projected keys normalize it and add projected detail and a separate RGB adjustment. | **Verified differences**, G02, G04 and G05 |
| Scene fog | Reads the shared fog vectors. Uses emitted clip XYZ for the vertex distance. | Same fog vectors and ramp. Distance includes the overlap Z drop and precedes the final clip-Z bias. | **Verified shared** inputs and diffuse formula. **Verified difference** in geometry input, G03 |
| Final fog and clamp stage | Six PS without highlights share the LOD output equation. 30 PS apply a second fog and clamp stage on diffuse plus highlights. | One output equation in all four PS. | **Verified shared** equation for ten PS. **Verified difference** for the 30 near highlight PS, G03 |
| Lights and emission | Sun, point attenuation, directional ambient, property emissive RGB and the Lighting shader object additive product. | Same diffuse terms and constant slots. Normal and position inputs differ. | **Verified shared** formulas and sun RGB writer. Live equality **unverified**, G04 |
| Light masks | Two sets of masked permutations per technique. One applies a sun mask as well as point masks. | No mask sample in the four checked PS records. | **Verified difference** in available keys, G04 |
| Highlights and auxiliary mask | Permutations add standard specular, a separate angular term, or a flagged layer adjustment and target-3 output. | The four records omit those near terms. | **Verified difference**, G05 |
| Auxiliary output selector | The same selector switches target 2 between target 0 and packed normal data. | Same rule, with LOD target 0 and normal inputs. | **Verified shared** selector, G05 |
| Alpha | Technique 8 emits zero. Technique 19 emits weighted distant alpha. | LOD emits scaled base-map alpha. | **Verified difference** in PS output. Effective blending **unverified**, G08 |
| Native setup and depth | Landscape material, layer arrays, near-specific flags and distant transition parameters. | LOD landscape material, block textures and LOD-only vertex depth adjustments. | **Verified differences**, G08 |
| INIs and image space | Land specular and cast settings affect near-land flags. Global image-space settings have separate consumers. | Terrain split, visibility and projected detail settings have LOD consumers. | **Verified** where linked. Live postprocessing and any seam effect **unverified**, G07 |

## Observations

### G01. Diffuse colour, multipliers and colour space

**Verified.** Near techniques 8 and 19 combine diffuse RGB from `t0..5` using the six weights in `TEXCOORD6.xyzw` and `TEXCOORD7.xy`. Technique 19 interpolates toward a separate distant sample after noise modulation (G02). Techniques 9 and 18 take base RGB from `t0/s0`. Projected LOD applies the independent channel adjustments in G02. The common diffuse stage multiplies the light accumulator by effective diffuse RGB, then multiplies RGB by `COLOR0.rgb`.

**Verified.** The checked base-colour expressions expose layer weights, transition weights, noise and projected adjustment where listed. The 40 PS records show no further diffuse-only scalar or explicit gamma or sRGB-to-linear transform in that stage. This statement covers arithmetic on the sampled values. Bound texture views and eventual output encoding remain **unverified**. Evidence is the complete key set above, with `08000001`, `13000001`, `09000005` and `12000005` as the base controls.

**Verified.** The checked base colour and normal PS lookups use implicit derivatives on both sides. Native setup supplies different filter states. The technique table at `0x15487c0` reaches the near branch at `0x1548064` for techniques 8 and 19, and the LOD branch at `0x154852e` for 9 and 18. The common setup writes filter enum 3 for slots 0 and 1 at `0x1547e56` and `0x1547e78`. The LOD branch overwrites both with enum 1 at `0x1548552` and `0x1548587`. The descriptor builder at `0x102b910–0x102baf3` maps 3 to anisotropic filter `0x55`, maximum anisotropy 16 and MaxLOD `FLT_MAX`. Enum 1 selects `0x14`, linear minification and magnification, point mip selection and MaxLOD zero. The near material loop applies wrap to layer slots at `0x1548bd7` and `0x1548c40`. Shipped BTR material address enum 0 maps to clamp for its block maps (corrected #822 G03). Actual bound views and draw-time overrides remain **unverified**.

**Verified.** The 46 distinct base-master landscape diffuse paths all resolve in the nine checked texture archives. Their headers are 23 legacy DXT1 and 23 legacy DXT5. The prior terrain LOD census resolves 9,326 BGRX and 20 RGBA diffuse headers. Neither census contains an explicit DX10 sRGB diffuse header. The traced legacy DDS creation route uses BC1_UNORM, BC3_UNORM, B8G8R8X8_UNORM and R8G8B8A8_UNORM for those formats. Its wrapper at `0x100dcc0–0x100dd22` supplies zero for the force-sRGB option. The texture and view receive the selected format at `0x101f334–0x101f504`. Both terrain binding paths use existing shader resource views. The LOD binding also has a render-target source branch.

**Verified, scoped.** The 40 PS records contain no additional diffuse-only gain or explicit gamma conversion on the sampled RGB after accounting for the layer weights, distant blend, noise and projected adjustment described here. G03 and G05 describe the later colour operations. **Unverified.** The bound texture views, the exposed mip ranges, the sampling and output conversions, and any replacement or draw-time overrides at the seam.

**Confidence: high** for the shader colour terms. Effective view formats, packed vertex colours and actual bound values could change the comparison of draw results.

### G02. Noise, distant blend and projected detail

**Verified.** Technique 8 and both technique 9 PS records omit the slot-15 sample. All 18 technique 19 PS records and both technique 18 PS records sample red from `t15/s15` at three times their distant/base UV. Let `B` be RGB from slot 13 for technique 19 or slot 0 for LOD. The values below are rounded to the shown precision.

```text
a = saturate((0.55 × sum(B) − 0.4) × 1.666667)
h = a² × (3 − 2a)
m = 0.37 + 0.833333 × lerp(noiseR, 0.37, w)
```

For technique 19 and `12000005`, `w = 0.8h`. For projected `12040005`, `w = h`. Technique 18 uses `m × B` as its noise-adjusted diffuse. Technique 19 interpolates from the near layer mixture to `m × B`, with weight `TEXCOORD7.w × PS b1[0].z`. The VS forms the distance factor from the XY distance `r` between vertex `POSITION0.xy` and `VS b2[7].zw`. It uses `1 − saturate((9625.599609 − r) × 0.000376)`. The distant UV uses transformed layer UV scaled by approximately `0.010417`, plus `VS b2[7].xy`, then flips V. Evidence is both near VS payloads and the complete technique 19 and 18 PS sets.

**Verified.** Slot 15 supplies a red value at three times the corresponding UV. The mix toward 0.37 uses `0.8h` in technique 19 and base technique 18, and `h` in projected technique 18. The multiplier `0.37 + 0.833333 × mixedRed` has outer bounds of about 0.37 and 1.20333 for sampled red in [0,1]. Its neutral mixed-red value is about 0.756. For positive RGB, the multiplier reduces the input below that threshold and increases it above the threshold. Near applies it to the distant source before blending. LOD applies it directly to the base RGB. The shipped noise DDS has a 512 × 512 legacy RGBA header with nine mips. Both paths can take the same cache at `0x31fd0a0`. The near update has a default fallback. LOD can skip a null bind.

**Verified.** The native path at `0x51c9f0` supplies `Textures\Terrain\Noise.dds`. The nine shipped texture archive indices locate one matching DDS in `Skyrim - Textures5.bsa`. Its header is 512 × 512 with nine mips. The eligible load at `0x51181e–0x511848` targets cache `0x31fd0a0`. The near-land lookup at `0x2b2d4e` calls `0x511890` and can populate near material `+0x100` at `0x2b2e39`. The LOD cache structure supplies material `+0xb0` at `0x511a45`. Binding uses these fields at `0x1548cc0–0x1548cd9` and `0x1548e5b–0x1548eb2`, respectively. The eligible near update falls back to shared default `0x3336448` when the noise lookup returns null (`0x2b2e42–0x2b2e57`). The LOD path skips the texture call when its noise field is null. Near material `+0xf8` supplies the distant slot 13. Which pointers and views reach a seam draw is **unverified**.

**Verified.** Both projected LOD PS records sample overlay normals on three planes in `t12/s12` and `t13/s13`, using coordinate scales from `PS b2[8].x/.w`. They weight the results by the normalized block normal and mix the overlays by `h`. Separately, with `C` the post-noise diffuse (or the base diffuse in technique 9) and `p = 0.465 + 0.441h`, they interpolate from `C` toward the following per-channel targets by `0.30 + 0.20h`.

| Channel | Target |
|---|---|
| Red | `max(C.r, 2 × (0.078 + 0.270h))` |
| Green | `max(C.g, 2 × (0.098 + 0.281h))` |
| Blue | `max(C.b, 2 × (−0.035 + 0.441h))` when `p > 0.5`, otherwise `min(C.b, 2p)` |

The full projected normal blend is in corrected #822 G06. The map writer and binding at `0x99fda4–0x99fe3f` and `0x154a530–0x154a61a` supply those resources. None of the 36 near PS records has this triplanar overlay and per-channel adjustment. The near special layer path is described in G05.

**Verified.** The RGB-driven smoothstep mixes the two projected overlays. A separate slope-driven weight based on the raw block normal's Z blends transformed detail with the block normal. The projected RGB adjustment has channel-specific bounds. Red and green can increase. Blue can decrease on its ceiling branch and can increase on its floor branch. **Unverified.** The active texture views, the noise strength and sign, and the projected key at the seam.

**Verified.** Near technique setup sets slot-15 wrap and filter enum 1 at `0x15484f8` and `0x1548519`. Its later noise bind can replace the address enum with near material `+0x70` through `0x154c9a0–0x154c9fd`. The LOD noise material path sets wrap and filter enum 1 after the eligible bind at `0x1548e87` and `0x1548ea8`. Noise tiling and strength are shader literals in both noise techniques. The compiled land texture tiling setting has a separate land builder read (G07). The checked noise path yields no setting-to-slot-15 strength link. **Confidence: high** for the noise math and eligible bindings. Draw selection, texture views and the live near blend weight remain **unverified**.

### G03. Fog and the lit-diffuse output

**Verified.** All eight VS records use the scene fog ramp and output its colour and factor in `COLOR1`. The common writer `0x154c010` is called at `0x1548614`. For a finite nonzero near/far pair, `VS b0[1] = (near/(far−near), 1/(far−near), power, max)`. `VS b0[2..3].xyz` carries near and far RGB. With both endpoints zero it writes `(5000000, 0.1, 1, 0)` to `b0[1]`. The writer returns without updating these vectors if the selected scene has no fog property. Equal nonzero endpoints reach the reciprocal with a zero denominator. Corrected #812 G03 describes the scene selection and all constant writes.

**Verified.** With `d` the length of pre-divide clip XYZ, both sides compute `s = saturate(d × VS b0[1].y − VS b0[1].x)` and `F = min(exp2(log2(s) × VS b0[1].z), VS b0[1].w)`. They interpolate near to far RGB by `F`. Near uses the emitted clip XYZ. LOD includes any local overlap drop and excludes the later clip-Z bias (G08). The ramp has no separate height or sun-direction term in this scope.

**Verified.** For each RGB channel, let `L` be lit tinted diffuse. Let `Q(X) = X − k × lerp(X,fogRGB,fogFactor)`, where `k` is `PS b0[0].w`. Let `S` and `T` be `PS b12[42].y` and `.z`. The six near PS without highlights and all four LOD PS emit `min(S × Q(L) + B,L) − T × S × Q(L)`, where `B` is the shared post-lit clamp in `PS b0[1].x`.

**Verified.** The 30 near highlight PS form `D = min(S × Q(L) + B,L)`. They add the highlight to obtain `U`, then emit `min(S × Q(U) + Bspec,U) − T × S × Q(U)`, where `Bspec` is the post-spec clamp in `PS b0[1].z`. These are algebraic expressions for the stated operation order. The second clamp can change the result with zero highlight. With zero fog factor, `k=5/6`, `S=1`, `T=0`, both clamp constants 1 and `L=1.5`, the first expression yields 1.25. The second yields approximately 1.2083.

**Verified.** The common scene selector is at `0x20d6970`. The common fog coefficient source at `0x20d694c` initializes to approximately 0.8333333. Its native writer can change it. The shared clamp cache at `0x343640c–0x3436414` feeds the upload at `0x1548619–0x1548656`. The slot-12 writer sets S to zero when flag bit 1 is set, otherwise one. It sets T to one when flag bit 2 is set, otherwise zero (corrected #812 G04). The checked RGB tails have no additional exposure or energy scale, explicit gamma, output-alpha feedback or final saturation. The near VS uses emitted clip XYZ for fog distance. The LOD VS uses the lowered vertex when inside the overlap rectangle and computes fog before the separate clip-Z bias. **Unverified.** The selected draw keys, flag arguments, fog values, render-target encoding and the effect at the seam.

**Confidence: high** for the shared ramp, slot sources and common stage. Live scene selection, fog register values and the effect of vertex geometry at the seam remain **unverified**.

### G04. Lighting, normals and shadow masks

**Verified.** Near uses the six layer normals at `t7..12`. The ordinary path decodes signed RGB as `2 × RGB − 1`, mixes by the diffuse layer weights, applies the interpolated basis and normalizes. Technique 19 first fades the weighted tangent normal toward `(0,0,1)` by its distant blend weight. The `0x200000` near subset can adjust each layer normal before the mix (G05). LOD starts with the slot-1 normal in signed R/B/G order. The two base LOD PS use the result directly. The projected keys normalize the block normal and can blend in the projected detail from G02. These normals feed diffuse sun, point and directional ambient terms. Normal alpha supplies a near specular input. It is unused by the four LOD PS.

**Verified.** The common pre-fog diffuse stage has the following terms. Shadow qualifiers below apply only to the corresponding near PS keys. Slots in this table are pixel-stage slots.

| Term | Static rule |
|---|---|
| Sun | `saturate(dot(N, b2[0].xyz)) × b2[1].rgb`. |
| Point lights | Up to `min(b2[29].x, 7)`. For light `i`, `D = b2[15+i].xyz − P` and `a = saturate(length(D)/b2[15+i].w)`. The diffuse contribution is `saturate(dot(N, normalize(D))) × b2[22+i].rgb × (1 − a²)`. |
| Directional ambient | Three rows `b2[11..13]`, each dotted with `(N,1)`. |
| Property emissive RGB | `b2[4].yzw`, the draw's lighting property RGB at `+0xf0` multiplied by the property's scalar at `+0xf8`. It is added to directional ambient. |
| Lighting shader object additive product | `b1[8].x × b1[8].yzw`. This term enters the accumulator before multiplication by the effective diffuse and vertex tint. |

**Verified.** The diffuse lighting sum adds the directional ambient RGB and the property emissive RGB to the sun and point accumulation. It then adds the product of a separate Lighting shader object colour and scalar. Effective diffuse RGB and vertex RGB multiply the accumulator. `PS b2[4].yzw` is RGB from the draw's lighting property at `+0xf0`, multiplied by the property's scalar at `+0xf8` by the common writer at `0x1549f3a–0x1549f9c`. The **Lighting shader object additive product** is `PS b1[8].x × PS b1[8].yzw`. The common uploader at `0x154936f–0x15493c6` copies the shader object's scalar at `+0xcc` and colour at `+0xd0` or `+0xe0`, selected by its byte at `+0xf0`. Its constructor zeroes those fields.

**Verified.** Near passes `POSITION0.xyz` as `P`. Base LOD passes its locally adjusted model position. Projected LOD passes the transformed adjusted position plus `VS b2[14].xyz` from a separate geometry upload (`0x154a5e3–0x154a61a`). LOD's checked keys reach the inverse-transform branch for sun direction and the rotated directional ambient rows, as described in corrected #822 G04. The point path at `0x1549fdc–0x154a087` clears the arrays and calls `0x154bb90` when the point count is nonzero. Geometry setup derives its model-space selector from the inverse of raw technique bit 1 at `0x15495a4–0x15495c1`. PS key formation can clear that bit when raw bit 2 is clear (`0x15896d0–0x15896e1`). Equality of live light lists, ambient weights, sun constants or emission is **unverified**. No separate LOD ambient gain occurs in the checked PS terms.

**Verified.** Geometry setup starts at `0x1549550`. Both terrain classes use the common sun RGB writer (`0x1549ad1–0x1549b22`), which multiplies the light colour by the light scalar and the render-global scalar. The point helper multiplies light RGB by the light scalar and per-entry scalar. The diffuse ambient dots use the common three-row cache at `0x20d6978`, with the geometry branch selecting whether to rotate it. Near PS keys alone leave the model-space selector open. Masked near point lights below `min(PS b2[29].y,4)` use their uploaded `PS b2[2]` channel indices. The masked sun path uses mask red. The four LOD PS omit these samples. **Unverified.** Live lighting property values, Lighting shader object values, transforms, masks, light lists and ambient constants at the seam.

**Verified.** Twelve PS per near technique sample the screen-space mask at `t14/s14` with bit `0x4000`. Six of those per technique also have bit `0x2000` and multiply sun RGB by mask red. The masked point path selects the mask channel from the uploaded `PS b2[2]` indices for eligible indices below `min(PS b2[29].y,4)`. It uses multiplier one for indices outside that range. The four LOD PS contain no mask sample. The native slot-14 bind depends on raw bit 14 and either raw bit 13 or the raw field masked by `0x1c0` at `0x15486c4–0x1548701`. The near builder sets receive bit 8 and gates cast bit 9 on `bDrawLandShadows` at `0x2b3610–0x2b3658`. The reviewed census counted 9,584 shipped BTR lighting properties with both bits clear. Mode-12 Z prepass and other caster admission gates are separate from these lighting receiver samples (reviewed sun-shadows finding, §5).

**Confidence: high** for shader terms, mask-key coverage and the cited native gates. The live point positions, constant values and shadow permutations selected at the seam remain **unverified**.

### G05. Specular, glossiness, angular terms and special permutations

**Verified.** Twelve PS per near technique have bit `0x200` and evaluate sun and point half-vector power terms. The six per-layer exponent weights come from `PS b1[11].xyzw` and `b1[12].xy`. Standard highlight inputs also include weighted layer-normal alpha, `PS b1[4].rgb` and `PS b2[3].y`. The layer exponent upload is at `0x1548cf7–0x1548d44`. The near property builder gates specular bit 0 on `bLandSpecular` (`0x2b364b–0x2b3658`).

**Verified.** Nine PS per near technique have bit `0x20000`, including keys without the standard specular bit. This separate rim term raises `1 − saturate(dot(N, normalize(TEXCOORD5.xyz)))` to the power in `PS b2[14].w` and uses `PS b2[14].xyz` for RGB. The `PS b0[1].z` post-spec clamp feeds 15 PS per near technique and zero LOD PS.

**Verified.** Six PS per near technique have bit `0x200000`. These keys perform per-layer tests driven by diffuse alpha and alter the layer normals. All 12 keys can resample the six normal maps using base UV multiplied by `PS b1[10].w`. They also use layer weights from `PS b1[9..10]` and angular inputs in `PS b1[13]`. G07 traces the normal resample scale. They also write target 3 XY with a luminance value and a weighted mask. The counts overlap. The four LOD PS omit those near highlight, layer adjustment and target-3 terms. The projected LOD keys have the distinct colour and normal overlay in G02.

**Verified.** The 18 near rim keys multiply their angular power and `PS b2[14].xyz` by a per-channel directional ambient factor. Each factor channel saturates the dot of an ambient row with the final lighting normal extended by 0.15. The diffuse ambient calculation instead uses an unsaturated dot with an extension of one. Near keys with the flagged layer path can replace the ordinary sun highlight with the geometry- and surface-angle calculation using `PS b1[13]`. The separate target-3 output uses luminance weights 0.30, 0.59 and 0.11 and a weighted mask. All 40 PS use the same auxiliary output selector. **Unverified.** The selected key and live highlight and auxiliary values at the seam.

**Verified.** All 40 PS use `PS b2[7].z > 0.00001` to copy target 0 into target 2 and set target 1 XY to `(1,0)`. Otherwise both sides pack the transformed normal in target 2 and use the projected position difference in target 1. The shared selector takes different data from each side's colour, normal and geometry paths. Live use of the auxiliary targets is **unverified**.

**Confidence: high** for key membership, inputs and the absence of these terms in the LOD records. **Unverified:** the full combination of the near special-term lanes, live glossiness and rim inputs, and which near key draws at the seam.

### G06. Vertex colour

**Verified.** Near VS `08000001`, `08000201`, `13000001` and `13000201` forward input `COLOR0`. The land loader recognizes `VCLR` at `0x2a92c0`, `0x2a9344`, `0x2ad7eb`, and `0x2ad864`. The accessor at `0x2b3a08–0x2b3a7c` reads loaded land storage `+0x2d48`, scales its RGB bytes by `1/255` and supplies one for alpha on that path. The full packing from that accessor to a bound seam vertex stream remains **unverified**.

**Verified.** The BTR layout has position and UV0 (corrected #822 G02). All four LOD VS records supply white `COLOR0 = (1,1,1,1)` without a mesh colour input. Both sides apply interpolated `COLOR0.rgb` to the lit diffuse. The actual near-land tint under the reported seam remains **unverified**.

**Confidence: high** for the VS/PS link and the accessor. An end-to-end vertex stream read would establish the live source bytes and format.

### G07. Settings, defaults and downstream image space

**Verified.** The table gives compiled values. Presets are in Low, Medium, High and Ultra order. Consumer claims are limited to the stated reads. Some entries govern geometry or pass selection and do not supply a brightness scalar.

| Setting or group | Compiled defaults and shipped overrides | Verified relation or limit |
|---|---|---|
| `fLandTextureTilingMult:Landscape` | 3 at `0x207b868` | Land builder read `0x2b4052`. Slot-15 noise uses a separate literal 3. |
| `iLandscapeMultiNormalTilingFactor:Display` | 4 at `0x20d8e50` | The flagged material path writes its reciprocal to `PS b1[10].w` at `0x1548db7–0x1548df4`. The twelve `0x200000` near PS records use that scale for the additional normal samples (G05). |
| `bLandSpecular:Landscape`, `bDrawLandShadows:Display` | 1 at `0x207b970`, 0 at `0x207b840` | Near construction reads the fields for specular and shadow casting. Shadow receive is a separate bit (G04). |
| `fSpecularLODFadeStart/End:LightingShader` | Approximately 0.09 and 0.10 at `0x20d6be0`, `0x20d6bf8` | Reads at `0x1519140/0x1519148`. Relationship to checked near highlight amplitude is **unverified**. |
| `bEnableImprovedSnow:Display` | 1 at `0x20d6ce8`. Presets 0 / 1 / 1 / 1. | Direct readers include `0x1519e85` and `0x1542e0d`. Its link to the selected near key is **unverified**. |
| `bEnableSnowMask`, `bEnableSnowRimLighting`, `fSnowRimLightIntensity` | 1, 1 and 0.3 at `0x20d8da8`, `0x20d8e38` and `0x20d8df0`. Rim geometry and normal power defaults are 3 and 2. | Flagged material branch reads rim inputs at `0x1549273–0x15492b7`. |
| `bDisplayLODLand:LOD` and `uGridsToLoad:General` | 1 at `0x20b5e30`, 5 at `0x2079eb0` | Native reads control LOD display and overlap grid, respectively (corrected #822 G07–G08). |
| `fLODLandDropAmount:LOD`, `fLODLandVerticalBias:LOD` | 230 at `0x20b5e78`, 0 at `0x20b5e18` | `0x656132–0x65613a` copies the drop setting to native cache `0x20d6848`. The VS has a literal drop and bias (G08). A setting-to-literal link is **unverified**. |
| `fSplitDistanceMult:TerrainManager` | 1.5 at `0x20b33d8`. Presets 0.5 / 1.1 / 1.5 / 1.5. | Terrain state read `0x519af8`. See reviewed sun shadows §5 for the three block-distance fields. This is a separate input from the shadow cascade splitter. |
| `sWorldMapOverlayNormalTexture`, `sWorldMapOverlayNormalSnowTexture`, `fMapMenuOverlayScale`, `fMapMenuOverlaySnowScale` | MapMenu defaults are `Data\Textures\Terrain\WorldMapOverlay_n.dds` and `Data\Textures\Terrain\WorldMapOverlaySnow_n.dds`. Scales are about 0.000035 and 0.000045. | Projected LOD uses these two resources and scalars (corrected #822 G06–G08). |
| `fNoLODFarDistanceMin/Max/Pct:Display` | 100, 10240 and 1 at `0x20cf968`, `0x20cf980`, `0x20cf998`. No entries in the five checked templates. | Can reach the shared scene fog endpoints through the gated far override at `0x413e86–0x413ef1` and `0x665740`. Corrected #812 G06 bounds the branches and the unverified gate. |
| `bFogEnabled:Weather`, `bDo30VFog:Display`, `bSAOApplyFog:Display` | All 1. | Corrected #812 G06 confirms compiled fields and a separate ambient occlusion path. Direct links to the checked exterior Lighting expressions are **unverified**. |
| `fLightingOutputColourClampPostLit/PostEnv/PostSpec:General` | All 1 at `0x20d8d00`, `0x20d8d18`, `0x20d8d30`. | Setup caches the three settings at `0x1547454–0x154747c` and uploads them on the eligible path at `0x154863b–0x1548656`. PostLit feeds the common diffuse stage. PostSpec feeds the checked highlight clamps through `PS b0[1].z`. |
| `iNumSplits`, `fShadowDistance`, `fFirstSliceDistance`, `iShadowMapResolution` | 2, 8000, 1250 and 2048. Base INI sets first slice to 2000. Preset shadow distances 3000 / 3000 / 8000 / 10000, resolutions 1024 / 2048 / 2048 / 4096. | Directional shadow setup uses these values. See reviewed sun shadows §1–§2. The checked LOD PS has no receiver mask sample. |
| `bLodZPrepass` | 1 at `0x20d6cb8` | Separate mode-12 pass gate at `0x151b42f–0x151b553`. |
| `fGlobalBrightnessBoost:Display`, `fGlobalMapBrightnessBoost:Display` | 0 at `0x20d7630`, 0.25 at `0x20d7d50` | Image-space setup selects one and adds it to an input scalar at `0x153d8fe–0x153d912`. The result reaches pixel constant vector 2 W via `0x153daa1–0x153dabb` and `0x152b170`. The final pixel transform and active seam value are **unverified**. |
| `fGamma:Display`, `bImageSpaceEffects:Display` | 1 at `0x20d0348`, 1 at `0x20d6a18` | Gamma has a reader at `0x100b317`. The reader divides a scalar by gamma before a constant write at `0x100b31f`. That write goes to slot-12 vector 42 X, which no terrain PS reads (see below). Image-space pass selection for these draws is **unverified**. |
| `fGlobalEyeAdaptStrengthScale:Display`, `fGlobalEyeAdaptSpeedScale:Display`, `fConstHDRAdaptTimerForMenu:Display` | 0.4, 2 and 0.3 at `0x20d7d98`, `0x20d7d80`, `0x20d7d68` | Native reads at `0x376b8c/0x376b9b` and `0x153db2d/0x153db38`. The image-space path uploads scaled adaptation parameters at `0x153db89` and a menu time term at `0x153db9a–0x153dbe3`. |
| `bUse64bitsHDRRenderTarget:Display` | 0 at `0x20d7380`. Presets 0 / 0 / 0 / 1. | Native read at `0x153b6e2`. The traced HDR descriptor selects a format (see below). Active terrain target format and postprocessing values are **unverified**. |
| `bUsePrecomputedNoise` | 0 | Reader `0x1542eb9`. A link to the terrain slot-15 texture is **unverified**. |
| `fMipBias:Display` | 0 at `0x20d6a60`. | The technique filters in G01 use the sampler builder's own zero bias. |

**Verified.** The gamma divide at `0x100b317` writes X of slot-12 vector 42 at `0x100b31f`. All 40 terrain PS read only Y and Z of that vector. This gamma divide therefore does not enter their target-0 expressions. The image-space brightness and adaptation settings have separate consumers. The traced HDR descriptor at `0x153b6e2–0x153b717` selects DXGI 26 (`R11G11B10_FLOAT`) with the setting off and DXGI 10 (`R16G16B16A16_FLOAT`) with it on. **Unverified.** The active terrain render target, the downstream pixel transform, and the effect of image-space routing in the reported frame.

**Verified, within the checked scope.** The compared land equations have no terrain-only diffuse brightness field. An ASCII name scan of the pinned image found no setting combining land, terrain or LOD with brightness, gamma, ambient, fog or exposure. The known global brightness, gamma, HDR and eye-adaptation fields have separate native reads. **Unverified.** Any per-draw differences in image-space routing or tone mapping for the reported scene. **Confidence: high** for the numeric defaults and cited reads, **medium** for the scoped settings coverage.

**Amendment (2026-11-24, UNREVIEWED).** **Scope.** Only the third cell of the settings-table row `bDisplayLODLand:LOD` and `uGridsToLoad:General` changes. The published text of that cell is: "Native reads control LOD display and overlap grid, respectively (corrected #822 G07–G08)." Read it as follows. `uGridsToLoad` is read by the coverage rectangle writer (corrected #822 G07). `bDisplayLODLand` has two native reads, which copy the byte to the runtime byte `0x33d3d45` (`0x6537e8`, `0x65db0b`; corrected #822 G08). The saved native listing contains no direct consumer of `0x33d3d45`, so an effect of `bDisplayLODLand` on LOD display is **unverified** ([terrain-block-edges-retail-facts.md](terrain-block-edges-retail-facts.md), G06). Everything else in G07 stands, including the compiled value 1 at `0x20b5e30`, the template scan, `uGridsToLoad` and the other table rows. Static only.

### G08. CPU setup, alpha, overlap and state

**Verified.** Near construction at `0x1527270` uses the `BSLightingShaderMaterialLandscape` vtable at `0x1b40220`. The LOD class `BSLightingShaderMaterialLODLandscape` has vtable `0x1b40298`. The material dispatch at `0x15494e4` routes decoded techniques 8 and 19 to `0x1548abd`, and 9 and 18 to `0x1548e00`. Near material setup binds arrays of diffuse and normal layers. It also prepares the distant resources and conditional parameter uploads. LOD setup binds the block diffuse and normal, and can bind the noise resource for technique 18. Near material field names `landBlendParams` at `+0x108`, `textureIsSnow[6]` at `+0x118`, and `textureIsSpecPower[6]` at `+0x130` are CRASHLOGGER_PDB(59818@2026.10.24). Native reads and uploads are at `0x1548abd–0x1548db7` and `0x15497cf–0x15497f0`.

**Verified.** The near block at `0x1548abd–0x1548afe` writes material texture offsets to XY and the texture fade field to W of `PS b1[0]`. It writes one in Z when the byte at `0x20d681e` is nonzero, and zero otherwise. The pinned image initializes the byte to one. The record header index at shader object `+0x58` resolves to float offset zero. The LOD setup at `0x1548e00–0x1548e3f` uses the same gate with its own XY/W fields. Technique 19 multiplies Z by the interpolated distant weight for colour and tangent-normal blending. Shader target-0 alpha differs between the techniques. The strict overlap test gates local Z lowering. The subsequent positive clip-Z bias applies independently of that test. **Inferred.** Depth can affect which surface contributes the visible pixel. **Unverified.** The current transition gate, blending, target writes, depth and stencil state, draw order, and the visible result at the seam.

**Verified.** Every PS for technique 8 writes target 0 alpha zero. Technique 19 writes distant slot-13 sample alpha multiplied by its noise multiplier, distant blend weight, `PS b2[3].z` and `COLOR0.a`. The four LOD PS write slot-0 sample alpha multiplied by `PS b2[3].z` and `COLOR0.a`. The LOD noise and projected terms do not affect this LOD alpha. A static census of the 9,584 shipped BTRs in `Skyrim - Meshes1.bsa` found zero serialized `NiAlphaProperty` blocks. This establishes the serialized input only. The effective blend mode, target-write mask, depth or stencil state, and ordering of the paired draws remain **unverified**.

**Verified.** The CPU near coverage rectangle uses the loaded-cell grid and four cardinal boundary probes. A probe can move an edge in one cell under the predicate and finite range established in corrected #822 G07. The CPU uploads centre minus frame origin XY and half extents minus 15 to `VS b0[0]` (`0x1a2360`, `0x14ecb20`, `0x1548597–0x1548607`). In the LOD VS, the strict rectangle test gates subtraction of `230 + transformedZ/1e9` from local Z. The source is pre-drop transformed Z. After projection, the VS adds `0.5 × saturate((clipZ−70000) × 0.0001)` to emitted clip Z. The four near VS have neither adjustment. The four LOD PS have no overlap alpha fade, discard or explicit depth output.

**Inferred.** The two LOD-only depth adjustments can affect which terrain surface is visible in an overlap. **Confidence: high** for the material branches, PS alpha, rectangle writer and shader depth rules. **Confidence: medium** for the visibility inference. **Unverified:** effective render states and draw visibility at the reported seam.

## Interpretation and alternatives

**Inferred.** A near vertex tint below one, or a shadow attenuation present on the near draw, can lower a near diffuse term when the corresponding LOD term uses white tint or no mask. This conclusion is conditional on the selected key and the sampler and constant values. Neither condition is established for the maintainer's seam.

**Inferred.** The normals, sun/ambient response, near transition weight, noise modulation and LOD projected tint can change the comparison even with matching decoded and sampled colour maps. Their direction and magnitude depend on the inputs. The common fog equations can produce different RGB because the vertices can carry different positions and lit diffuse inputs.

**Inferred.** The traced base sampler settings can change which texels or mips retail reads, even though both PS use derivative sampling. This static retail difference is separate from the downstream team's sampling check. The retail seam's bound mip ranges remain **unverified**.

**Unverified.** Which asymmetries are active in the reported scene, whether either draw receives a different postprocess treatment, and the cause of the reported brightness difference. This finding names no cause.

## Summary

**Verified, scoped.** The checked shader arithmetic and traced constant producers expose no standalone terrain-LOD brightness scalar. The six near PS without highlights and four LOD PS have the same output equation when their effective diffuse, lighting, tint and fog inputs agree. 30 near pixel shaders apply a second fog and clamp stage that can change RGB even with zero highlight. The two material classes can reach shared uploads with different inputs.

**Inferred.** Texture sampling, vertex tint, normal and mask response, noise, fog distance, draw visibility and the near highlight processing can contribute to a colour difference. **Unverified.** Their contributions and the cause of the reported brightness difference. The evidence is static and covers only the four named techniques and traced native paths.

## Negative results and limitations

- **Verified, scoped.** No shadow-mask sample, near specular or near angular term occurs in the four checked LOD PS records. No per-terrain exposure or explicit diffuse gamma conversion appears in the 40-record shader comparison.
- **Verified, scoped.** The two near techniques have the same checked key populations. The four terrain techniques account for all 48 decoded records used here. Other Lighting features and separate passes were not compared.
- **Unverified.** Live keys, land layer values and packed colour stream, resource views and sampler state, point counts and coordinate alignment, shadow masks, fog scene values, effective raster/depth/blend/stencil states, pass order, postprocessing and visible output.
- Static only. No live frame, GPU capture or image comparison was performed. These values and rules need boundary review before any transfer.

## Independent review (2026-11-22 CST, 2026-11-23 UTC)

Reviewer: `gpt-6.2-sol` through Codex, high effort, fresh context, separate run. The reviewer did not author the finding. Date: 2026-11-22 CST, which is 2026-11-23 UTC.
Source reviewed: the draft of this finding (SHA-256 above), against the pinned image `sse-steam-1-7-104` (measured SHA-256 equals the pin in [builds/target.json](../builds/target.json)), the shipped shader package, the shipped asset headers and INI templates, and the earlier reviewed terrain and fog findings. Exposure of the review: mixed (retail executable, shipped assets, generated names, the draft). Method: the reviewer independently walked the shipped shader package, decoded all 48 selected records, and checked the pinned native listing and the INI templates. It sealed its nine verdicts before it opened the author's handoff. This is a static finding review. It is not match evidence for any function. It does not decide transfer eligibility ([docs/clean-room.md](../docs/clean-room.md)).

The observations above already include the corrected text. A Claude Sonnet 5.5 worker only assembled this file from the corrected text and drafted nothing. The draft contains no apparent recovered source or disassembly byte sequence. Its fenced block is an algebraic description. The texture paths identify game assets.

| Group | Verdict | One-line status |
|---|---|---|
| Shader coverage | Confirmed | Lighting group 6 contains 127 VS and 6,924 PS records. The four techniques contain all 48 stated records. |
| G01. Diffuse, sampler and colour space | Corrected | The shader arithmetic agrees within scope. Shipped DDS formats and the file-view creation rule are now bounded. |
| G02. Noise, distant blend and projected detail | Corrected | The noise rule is shared by the two nonprojected noise techniques. The factor can increase or decrease sampled RGB. |
| G03. Fog and target 0 | Corrected | The ten no-highlight PS share the final output. The other 30 use a second fog and clamp stage on diffuse plus highlights. |
| G04. Lighting, normals and shadows | Corrected | The two additive RGB inputs have different CPU owners. Mask channels use an uploaded selector. |
| G05. Highlights and auxiliary targets | Corrected | The rim term also uses saturated, per-channel directional ambient. |
| G06. Vertex colour | Confirmed | Near forwards mesh RGBA. All four LOD VS write literal one in each lane. |
| G07. Settings and image space | Corrected | Gamma is uploaded to a lane the 40 terrain PS do not read. The HDR setting selects an image-space format. |
| G08. CPU setup, alpha and overlap | Corrected | The transition-enable lane is conditional. The depth and alpha asymmetries hold. |

Summary: 2 confirmed (shader coverage, G06), 7 corrected (G01, G02, G03, G04, G05, G07, G08), 0 rejected.

## Reviewer and outcome

Reviewed independently on 2026-11-22 CST (2026-11-23 UTC) by `gpt-6.2-sol` (Codex, high effort, fresh context), separate from the author. Outcome: 2 confirmed (shader coverage, G06), 7 corrected (G01, G02, G03, G04, G05, G07, G08), 0 rejected. Static only. A review verdict is not match evidence, and transfer eligibility is not decided. Transfer status: UNREVIEWED. Unverified:

- Active seam permutations: which near key and which LOD key draw at the seam, the live land layer values and the packed vertex colour stream.
- Texture views: the bound shader resource views, the exposed mip ranges, the sampler state and any draw-time overrides, and the sampling and output conversions.
- Blend and depth states: the effective blend mode, target-write masks, depth and stencil state, raster state and draw order of the paired draws.
- Postprocessing: the active terrain render target, the downstream pixel transform, image-space routing and tone mapping in the reported frame.
- Live constants and inputs: point counts and coordinate alignment, shadow masks, fog scene values, light lists, ambient constants and the near blend weight.
- The cause of the reported brightness difference. This finding names no cause. No live frame, GPU capture or image comparison was performed.
