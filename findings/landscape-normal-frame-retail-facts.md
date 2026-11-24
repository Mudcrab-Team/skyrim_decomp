Transfer status: UNREVIEWED

# Finding: normal-map decode and tangent frame of near landscape (techniques 8 and 19)

| Item | Evidence record |
|---|---|
| Status | OBSERVED for verified claims. INFERRED and UNVERIFIED items are marked. Static only. No game launch, no capture and no visual claim. |
| Author / human operator | A Sonnet 5.5 research run (`claude-sonnet-5-5`), not a Sol run / Taylor. |
| Reviewer | A separate fresh-context Sonnet 5.5 run (`claude-sonnet-5-5`). Sol was unavailable on a usage limit. See "Independent review" below. |
| Date | 2026-11-24 CST. The author run took 05:11 to 05:26. The independent review took 05:35 to 05:47. A third run applied the corrections and re-read items in the pinned image and the shader records from 05:48. |
| Reviewed draft SHA-256 | `3852c35410c4cde1acd1b9bfa8aac4fbb19088560afecb0b7d49c3a954b2ea30` |
| Build | `sse-steam-1-7-104`, retail `1.7.104.0`, Steam build 24914197. Measured executable SHA-256 `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f` equals the pin in [builds/target.json](../builds/target.json). All three runs asserted the equality. |
| Shader records | Lighting group 6 of `shaders011.fxp`. Near landscape PS keys `08xxxxxx` (technique 8) and `13xxxxxx` (technique 19), 18 keys each. VS keys `08000001`, `08000201`, `13000001`, `13000201`. LOD terrain: VS `09000004` and PS `09000005`, `09040005`, `12000005`, `12040005`. |
| Main function RVAs (image base `0x140000000`; add it for a VA) | `0x2b3ce0` (land template initializer, GUESS), `0x2b4f70` (land quadrant vertex builder, GUESS), `0x1548d4d–0x1548df4` and `0x1548f9d–0x1548fe3` (material upload), `0x15755b0` (material base constructor), `0x1549550` (geometry setup), `0x1011750` (input layout builder, from #822). |
| Source exposure | Binary analysis. The runs used the operator's pinned executable (a saved disassembly listing, read locally by address), and the shipped Lighting shader package decoded offline with the `fxc /dumpbin` tool. Published findings #822, #946, #947 and #979 supplied anchors. No sibling source, no downstream implementation source and no decompiler output was used. No game plugin data was read, and no plugin-derived number appears below. No disassembly or shader text appears below. |
| Name provenance | GUESS for all function labels and for the names "bitangent-slot" and "tangent-slot". Shader semantic names (`POSITION`, `NORMAL`, `BINORMAL`, `TEXCOORD`) come from the decoded records. `bEnableSnowMask` and `iLandscapeMultiNormalTilingFactor` come from #946 G07. `fLandTextureTilingMult` comes from the settings tables of #822 G08 and #946 G07. No name comes from a public generated table. |
| Intended recipient | Mudcrab #963 and PR #993 (terrain green sign), after boundary review under [docs/clean-room.md](../docs/clean-room.md). Maintainer transfer decision pending. |

**Verified** means re-read at the cited static source. **Inferred** means a deduction with stated assumptions. **Unverified** means not read or not resolvable statically. `PS bN[i]` is constant buffer N, float4 element i. `Nv`, `Tv`, `Bv` are the interpolated per-vertex frame vectors of G04. The document contains facts and formulas only.

## Answer

**Rule.** The rule holds in the model space of a near land quadrant, with axes +X east, +Y north and +Z up. These axes equal the world axes if the quadrant node adds only a translation. That was not traced. A near-landscape normal-map texel with **G > 0.5 tilts the lit normal toward +Y (north)**. **R > 0.5 tilts it toward +X (east).** Green is not negated. The tilt direction comes from the per-vertex frame (`Tv = Nv × Bv`, with `Bv` along increasing U at the vertex builder). It does not come from the sign of the V axis. The vertex shader builds the frame only from vertex attributes. The pixel shader has no handedness or mirror input. The builder and shaders read here have no per-cell mirror input either. So the rule holds for every quadrant. "Unmirrored" describes the consumer's axes. It is not an engine state.

| # | Question | Answer | Tag | Confidence |
|---|---|---|---|---|
| 1 | PS decode of the six layer normals (slots t7..t12) | Per layer, `n = (2R − 1, 2G − 1, 2B − 1)`. No channel swap, no green negation, no Z rebuild. Alpha is separate. The six layers are summed with the six mesh blend weights. Technique 19 then fades `x, y` by `(1 − s)` and `z` toward 1 with `s = TEXCOORD7.w × PS b1[0].z`. The 12 flagged keys (`0x200000`) replace `n` per layer by a reoriented-normal blend with a second sample at UV × `PS b1[10].w`. They do this only when the alpha-weighted test passes (`e_i > 0.00001`) and `PS b1[10].w ≠ 1` (G03). | verified | high |
| 2 | Frame | Per vertex, from the mesh. The VS builds three rows from vertex attributes. Tangent-space X maps to the stored "bitangent" vector `Bv`, Y to the stored "tangent" vector `Tv`, Z to the vertex normal `Nv`. The CPU builder sets `Nv` from the land normal data. `Bv` is the unit vector along increasing U, projected onto the plane perpendicular to `Nv`. `Tv = normalize(Nv × Bv)`. No derivatives in the PS. | verified | high |
| 3 | World tilt for G > 0.5 | `+Y` (north), which is also `+V` in the template UV table. U runs toward +X and V toward +Y in the builder's UV table (G06). The "+Y" result depends only on `Tv = Nv × Bv` and on `Bv` along +U. | verified (frame and builder UV table), inferred (land node transform, material UV scale and offset) | high |
| 3b | LOD terrain (techniques 9 and 18) | Different. The LOD normal map is read as a model-space map: `n = (2R − 1, 2B − 1, 2G − 1)` as `(x, y, z)`. No tangent frame. G > 0.5 raises the Z (up) component of the block normal. Blue carries Y. | verified | high |

**Worked example, flat cell.** Take `Nv = +Z`. Then `Bv = +X` and `Tv = +Z × +X = +Y`. The texel `(R, G, B) = (0.5, 0.75, 0.933)` decodes to `n = (0, 0.5, 0.866)`. The lit normal is `0·Bv + 0.5·Tv + 0.866·Nv = (0, 0.5, 0.866)`. It has unit length. It tilts 30 degrees from vertical toward +Y. The texel `(0.5, 0.25, 0.933)` gives `(0, −0.5, 0.866)`, a tilt toward −Y. The texel `(0.75, 0.5, 1)` gives `(0.5, 0, 1)`, which normalizes to `(0.447, 0, 0.894)`, a tilt toward +X.

**LOD difference.** For LOD terrain, a flat texel is `(R, G, B) = (0.5, 1.0, 0.5)`. It decodes to `(0, 0, 1)`. The texel `(0.5, 0.75, 0.5)` decodes to `(0, 0, 0.5)`. The base LOD keys do not normalize it (G09).

## Review verdicts

| Group | Verdict | Main correction |
|---|---|---|
| Answer block | Corrected | Scope and tags. The world-axis step needs the land node transform. Row 1 needed the `PS b1[10].w ≠ 1` condition. The no-mirror-input sentence was added. |
| G01. Per-layer decode | Confirmed | None. |
| G02. Technique 19 fade and frame space | Corrected | The sun-space sentence went beyond #946. It is now scoped. |
| G03. Flagged keys | Confirmed | None. |
| G04. Vertex shader frame | Confirmed | One tag note on the input formats. |
| G05. Land vertex builder | Confirmed | Condensed to rules for boundary hygiene. |
| G06. Layer UV | Confirmed | One sentence added: the frame sees the template UV direction. |
| G07. Rule and mirrored cases | Confirmed | None. |
| G08. Frame quirks | Confirmed | The layout-builder inference was added. |
| G09. LOD terrain | Confirmed | None. |

## Question and method

Mudcrab asks which way a retail near-landscape normal map tilts the lit normal, and in which frame. The question comes from a green-sign decision in Mudcrab PR #993. The method has four steps.

1. Decode the near PS and VS records of the shipped Lighting package. Read the normal decode, the weights, the fade and the frame rows.
2. Read the native land vertex builder in the saved listing. Read the position, UV, normal and tangent arithmetic.
3. Read the constants in the pinned image. Read the setting defaults and the material upload.
4. Evaluate worked examples by hand.

## Observations

### G01. Per-layer decode in the near PS (verified)

**Verified.** Layer `i` (0 to 5) reads its normal map from slot `t(7+i)` at the layer UV (`TEXCOORD0.xy`). Its diffuse map is slot `t(i)`. All six layers use the same UV. For sample `(R, G, B, A)` the ordinary decode is

`n_i = (2R − 1, 2G − 1, 2B − 1)`.

- Channel order stays R → X, G → Y, B → Z.
- No channel is negated. No `1 − G` term exists.
- Z is read from blue. It is not rebuilt from X and Y.
- Alpha `A_i` does not enter `n_i`. It is mixed with the same weights into a separate weighted alpha (specular input, #946 G05).

The mix is `N_ts = Σ w_i n_i`. The weights `w_0..w_3` come from the interpolated `TEXCOORD6.xyzw`. The weights `w_4, w_5` come from `TEXCOORD7.xy`. These are the mesh blend attributes. The mix is not normalized and not divided by the weight sum.

**Evidence.** PS `08000001` and `13000001` were read by hand by the author, the reviewer and the corrections run. The author's script check covered all 36 near PS. The corrections run re-counted the normal samples in all 36 decodes: 24 non-flagged records hold six, and 12 flagged records hold twelve (G03). The reviewer decoded six PS records and read four of them for the normal path. The algebra of the other records rests on the author's script check.

**Confidence: high.** What would change it: a different shader package, or a replacement shader.

### G02. Technique 19 fade and frame space (verified)

**Verified.** Technique 8 uses `N_ts` directly. Technique 19 first interpolates toward the unperturbed normal. With `s = TEXCOORD7.w × PS b1[0].z`:

- `x' = x (1 − s)`
- `y' = y (1 − s)`
- `z' = z + s (1 − z)`
- the weighted alpha is multiplied by `(1 − s)`.

Both techniques then form the lighting normal

`W = N_ts.x × Bv + N_ts.y × Tv + N_ts.z × Nv`, and `n̂ = W / |W|`.

`Bv`, `Tv` and `Nv` are the interpolated vertex vectors from G04. The sun, point-light and ambient terms use `n̂`. In the decoded PS this is three dot products with `TEXCOORD1..3` followed by one normalization. The frame vectors are in the model space of the mesh. The vertex shader does not apply the world matrix to them. Whether the sun direction used with `n̂` is also in model space for near keys is not settled here. #822 G04 traces the model-space branch for the LOD keys. #946 leaves the model-space selector open for near PS keys. If the quadrant node adds only a translation, model axes and world axes agree. **Unverified:** the quadrant node transform.

The auxiliary normal output (target 2) uses the unnormalized `N_ts` and three other rows (`TEXCOORD8..10`). That output is outside this item.

**Evidence.** PS `08000001`, `13000001` and the flagged pair. The flatten constant `(0, 0, 1)` appears in all 18 technique 19 PS and in no technique 8 PS (author script).

**Confidence: high.** Which key draws a given cell is unverified.

### G03. Flagged layer adjustment, keys with bit `0x200000` (verified)

**Verified.** Twelve near PS (six per technique) take a different path per layer. Let `D_i` be the diffuse sample and `α_i = D_i.a`. Define the effective alpha `e_i = (1 − c) + c α_i`, where `c = PS b1[10].z`. Let `k = PS b1[10].w`. Let `(R, G, B)` be the normal sample at the layer UV. Let `(R', G', B')` be the normal sample at `UV × k`.

The branch condition is `e_i > 0.00001` **and** `k ≠ 1`.

- **Branch not taken:** `n_i = 2 r_i − 1`, as in G01.
- **Branch taken:** reoriented normal blend. `t = (2R − 1, 2G − 1, 2B)`. `u = (−(2R' − 1), −(2G' − 1), 2B' − 1)`. Then `n_i = normalize(t · (t · u) − u · t.z)`. This equals the standard reoriented normal blend of the base normal `(2R − 1, 2G − 1, 2B − 1)` with the detail normal `(2R' − 1, 2G' − 1, 2B' − 1)`, scaled by the positive factor `t.z`. The detail normal's X and Y are negated inside that formula. This is the formula's usual form. It is not a green-only flip.

**Check by hand.** If the base normal is flat, `t = (0, 0, 2)`. The result is `2 (dx, dy, dz)`, where `d` is the decoded detail normal. The detail tilt keeps its sign. If the detail normal is flat, the result is the base normal. So the flagged path does not change the tangent-space convention.

The weighted mix of the `n_i`, the frame transform and the renormalization are as in G02. The per-layer `e_i` also enters a weighted mask that goes to target 3 and selects the highlight path (#946 G05). It does not change the normal.

**Constants.** The uploader at `0x1548d4d–0x1548df4` writes `c` as 1.0 when the byte at `0x20d8da8` (`bEnableSnowMask`, compiled default 1) is nonzero, else 0. It writes `k = 1 / (float)` of the dword at `0x20d8e50` (`iLandscapeMultiNormalTilingFactor`, compiled default 4), so `k = 0.25`. With these defaults `e_i = α_i`, and the detail sample is the same normal map at a four-times larger UV scale. If `c = 0`, the alpha test always passes and only `k ≠ 1` gates the blend.

**Evidence.** The author's script counted six blend markers and twelve normal samples in each flagged key. PS `08200201` and `13200201` were read by hand. The image values were re-read by the corrections run.

**Confidence: high** for the algebra. **Medium** for the live values of `c` and `k` (INI overrides and later writers not searched). Which draws use the flagged keys is unverified.

### G04. Vertex shader frame (verified)

**Verified.** In all four near VS the same instructions build three outputs from the vertex inputs. Name the attributes by their VS input slot. `POSITION.w` is `p_w`. `NORMAL = (a_x, a_y, a_z, a_w)`. `BINORMAL = (b_x, b_y, b_z, b_w)`. Then:

- `Nv = 2 (a_x, a_y, a_z) − 1`
- `Tv = 2 (b_x, b_y, b_z) − 1`  (the "tangent-slot" vector, which is `BINORMAL.xyz`)
- `Bv = (p_w, 2 a_w − 1, 2 b_w − 1)`  (the "bitangent-slot" vector)

`TEXCOORD1 = (Bv.x, Tv.x, Nv.x)`, `TEXCOORD2 = (Bv.y, Tv.y, Nv.y)`, `TEXCOORD3 = (Bv.z, Tv.z, Nv.z)`. The PS dots these three rows with the tangent-space normal. So the **normal map X (red) multiplies `Bv`, Y (green) multiplies `Tv`, Z (blue) multiplies `Nv`.** Note the unusual pairing. The red channel uses the vector stored in the "bitangent" slots (`p_w`, `a_w`, `b_w`).

The VS forwards `COLOR0` and the blend weights. It does not renormalize `Bv`, `Tv` or `Nv`. No row is negated. The four VS records give identical frame output (author script, hash equal).

The decode `2v − 1` for `NORMAL` and `BINORMAL` implies four unsigned-normalized bytes. This is inferred from the VS decode and from the builder's byte encoding in G05. The input layout entries were not read.

**Evidence.** VS `08000001`, `08000201`, `13000001`, `13000201`. The PS inputs `TEXCOORD1..3` arrive in the three registers that the PS dots with the normal.

**Confidence: high.**

### G05. Native land vertex builder: how `Nv`, `Bv` and `Tv` are generated (verified)

**Verified.** The land quadrant builder at `0x2b4f70` makes one 289-vertex (17 × 17) quadrant mesh. The vertex stride is 40 bytes. The vertex descriptor has position, UV, normal, tangent, colour and land-data attributes, and no skin attribute.

**Rule.**

- `Nv` is the land normal record read as signed bytes, divided by 127 and normalized.
- `Bv` is the unit vector along the direction of increasing U (U grows toward +X in the quadrant mesh). It is projected onto the plane perpendicular to `Nv`. The projected direction comes from a UV-derived tangent summed over the adjacent triangles of the 16 × 16 grid.
- `Tv = normalize(Nv × Bv)`. The cross-product order was checked component by component.
- The frame is right-handed (`Bv × Tv = Nv`).
- Everything is stored per vertex. The shader does not renormalize it.

**Position and quadrants.** `col` is the vertex index mod 17. `row` is the index ÷ 17. A vertex has `x = 128 col + X_q`, `y = 128 row + Y_q`, with the height from the quadrant's height table. `X_q = 2048 (q mod 2) − 2048` and `Y_q = 2048 (q ÷ 2) − 2048` for quadrant `q = 0..3`. So the quadrants are SW, SE, NW and NE of the cell. **Row increases with +Y.** The initializer writes `X_q` and `Y_q` at `0x2b4300–0x2b4349`. The builder reads them at `0x2b5146–0x2b5150`.

**Evidence.** The corrections run re-read the position loop, the per-triangle tangent accumulation (`0x2b5730–0x2b5953`), the per-vertex projection and cross product (`0x2b59b0–0x2b5bd0`), the signed-byte normal read and the stored bytes. All matched. Image constants: `1/127` at `0x1820e20`, `0.5` at `0x1b5be14`, `127.5` at `0x1820e30`, `1.0` at `0x1b5be28`.

**Confidence: high** for the rules. **Unverified:** the live vertex declaration format of `POSITION.w` (G08) and the node transform of the quadrant geometry (G07).

### G06. Layer UV from position (verified template, inferred defaults)

**Verified.** The template initializer at `0x2b3ce0` fills `u = col × s` and `v = row × s` for `col, row = 0..16`, with `s = fLandTextureTilingMult / 4`. That is `0.75` for the compiled default 3 (a float at `0x207b868`, read at `0x2b4052`). If the setting is zero the code uses 16 in its place. Per world unit this is `du/dx = dv/dy = tiling / 512`, which is `3 / 512` (one texture repeat per 170.67 units). `u` is zero at the quadrant's west edge and `v` is zero at its south edge. Each quadrant spans 12 repeats. All four quadrants and all cells use the same UV range. The tangent computation in G05 uses this template UV directly. So the frame sees U toward +X and V toward +Y whatever the material UV scale or offset is. Only the direction of the sampled layer UV depends on the inferred material defaults below.

The VS then forms `uv = UV0 × scale + offset` (`VS b1[2]`). The material upload at `0x1548f9d–0x1548fe3` copies offset and scale from the material. The base material constructor (`0x15755b0`) sets offset `(0, 0)` and scale `(1, 1)` for both UV sets. The set selector at `0x20d69d0` starts at 0 (three code sites toggle it).

**Inferred.** The near land property builder (`0x2b3410–0x2b36e0`) writes no offset or scale. Together with the defaults, this gives `uv = (u, v)` unchanged. Then **U increases toward +X and V increases toward +Y** in the sampled layer UV.

**Cross-check, inferred.** The technique 19 VS forms the distant-map UV as `(u', 1 − v')` from the scaled layer UV. The distant V falls as layer V rises. That agrees with layer V rising toward +Y if the distant map is north-up. This was not verified against the map.

**Confidence: high** for the template and the formula. **Medium** for "defaults unchanged at draw time" (no exhaustive search for other writers).

### G07. Derived rule and consumer cases (inferred from G01–G06)

**Rule.** With `Nv = +Z` (flat cell): `Bv = +X`, `Tv = +Z × +X = +Y`. The lit normal before renormalization is `W = (2R − 1) X̂ + (2G − 1) Ŷ + (2B − 1) Ẑ`. So G > 0.5 gives `W.y > 0`, a tilt toward +Y (north). G < 0.5 tilts toward −Y (south). R > 0.5 tilts toward +X (east). On a sloped vertex the same holds in the local frame. The G tilt points along `Nv × Bv`. `Bv` is the projection of the +U direction onto the plane perpendicular to `Nv`.

The worked examples are in the Answer. The corrections run recomputed all three by hand.

**Dependence on UV direction.** The engine does not derive `Tv` from the V direction. It derives `Tv` as `Nv × Bv` with `Bv` along +U. With U toward +X this puts green toward +Y for any V mapping. In the retail mapping V also grows toward +Y, so green points toward +V. A consumer that builds its frame from its own V axis must match this. Suppose the consumer's UV has V toward −Y, for example `uv = (x, −y) / tile`. Then retail green points toward **−V** in that UV space. The retail frame follows `Nv × Bv`.

**D3D note, inferred from the API convention (not read here).** In a Direct3D texture `V` grows toward later rows of the file. So "green toward +V" in the retail mapping is "green toward later rows". The row order of the shipped normal maps was not read.

**Model space and world space, unverified.** The PS works in the model space of the quadrant mesh. The vertex data is axis-aligned to the cell (G05). The quadrant node transform was not traced. "Tilt toward world +Y" assumes the land node adds no rotation. This is inferred.

**Confidence: high** that the engine frame gives this tilt for the vertex data described. **Medium** for the final world-axis statement until the node transform is read. A lit capture of a normal map with a known green gradient would confirm it.

### G08. Frame quirks, static only (inferred, medium)

**Verified, builder side.** The builder stores `(Bv.x + 1) × 0.5` in `POSITION.w`. The VS uses `POSITION.w` unchanged as `Bv.x` (G04). The other five frame components use `2 × byte − 1`. If the live input layout reads `POSITION.w` as a plain float, the red-channel vector is `((Bv.x + 1) / 2, Bv.y, Bv.z)` and not `Bv`. For a flat cell `Bv.x = 1` and the stored value is also 1, so the result is exact. For a slope `Bv.x < 1`, so the stored value is above `Bv.x`. The final normalization limits the effect. No sign changes.

The layout builder at `0x1011750` takes its first position-format branch when the vertex bit of the descriptor is set, whatever the full-precision bit says. #822 verified that this branch gives four float32 position components. The land descriptor has the vertex bit. So `POSITION.w` is very likely a float32 (inferred, medium-high). If it were not, `Bv.x` would read 1.0, which is the flat-cell value. Neither case changes a sign. The format table row was not read.

**Verified.** The frame bytes are truncated, not rounded (`× 127.5`, then convert). The normal bytes are stored as the signed value plus 128. A flat cell decodes to about `(−0.004, 1, −0.004)` for `Tv`, and similarly for `Bv`. The PS does not renormalize the interpolated frame.

**Confidence: high** for the builder arithmetic, **low** for the visible effect.

### G09. LOD terrain, techniques 9 and 18 (verified)

**Verified.** The four LOD PS read the block normal map from slot `t1`. The decode is `n = (2R − 1, 2B − 1, 2G − 1)` as `(x, y, z)`. No negation, no Z rebuild, no tangent frame. The LOD VS has only position and one UV as inputs. Base keys `09000005` and `12000005` use `n` for lighting without normalization. Projected keys `09040005` and `12040005` normalize it and add projected detail through a basis derived in the PS from `n` (#822 G06). The detail decode there is plain `2 × RGB − 1`.

**Rule.** For LOD: G > 0.5 raises the block-space Z component. B > 0.5 raises the block-space Y component. R > 0.5 raises X. A flat texel is `(R, G, B) = (0.5, 1.0, 0.5)`. A texel `(0.5, 0.75, 0.5)` gives `(0, 0, 0.5)`, half length. The base keys do not renormalize, so diffuse sun lighting is halved. The direction of block Y in world axes depends on the BTR vertex data and the block transform. That is unverified here (#822 G04 leaves the same point open).

**Evidence.** PS `09000005`, `09040005`, `12000005`, `12040005`, and the VS input signature. The reviewer and the corrections run each read the swizzle.

**Confidence: high.**

## Interpretation and alternatives

**Inferred, high.** For near land, the engine's green direction is `Nv × Bv`, with `Bv` along +U and `Nv` the land normal. For the retail UV mapping this is +Y (north) and +V. A consumer frame built as `T = ∂P/∂U`, `B = ∂P/∂V` with a green-positive-V decode gives the same world result only if V grows toward +Y in that frame. The consumer must choose the sign of green so that G > 0.5 tilts toward +Y in unmirrored Creation space.

**Alternative.** The retail frame could differ at draw time from the builder output. A later pass could rewrite the vertex stream, or a different vertex source could be used, for example cached or streamed land. No such pass was found. **Unverified.**

## Relation to earlier findings

- **#822** (terrain LOD shading): G04 gives the LOD decode `(R, B, G)`, the unnormalized base keys and no tangent frame. This finding agrees. It gives no correction.
- **#946** (terrain LOD versus near landscape): G04 and G05 give the six layers, `2 × RGB − 1`, the technique 19 fade and the flagged resample with `PS b1[10].w`. G07 gives the settings. This finding agrees and adds the frame, the exact flagged formula and the world direction. The model-space selector for near PS keys stays open there and here.
- **#947** (terrain seam keys) and **#979** (technique 19 term order): the fade term `w = TEXCOORD7.w × PS b1[0].z` agrees. No correction.

No earlier published sentence is wrong. Any later amendment of the near-key sun space needs its own scoped group.

## Independent review (2026-11-24 CST)

Reviewer: a fresh-context Sonnet 5.5 run (`claude-sonnet-5-5`), separate from the author. Sol was unavailable on a usage limit. Review window: 05:35 to 05:47 CST. The reviewer decoded shader records from the shipped package. It read the land builder, the UV table fill, the quadrant offsets, the uploader and the constructor in the saved listing. It saved its own results before it read the draft. Static only.

Result: **8 confirmed (G01, G03, G04, G05, G06, G07, G08, G09), 2 corrected (Answer block, G02), 0 rejected.** The reviewer confirmed the rule: G > 0.5 tilts toward +Y, R > 0.5 tilts toward +X, no green negation. This file contains the corrected wording.

- **Answer block.** The world-axis step needs the land node transform (inferred), so the row 3 tag was split. Row 1 needed the `PS b1[10].w ≠ 1` condition. The shaders and builder have no mirror input, and the Answer now says so.
- **G02.** The sentence on the sun direction in model space went beyond #946. It is replaced by a scoped sentence.
- **Other additions.** The G06 sentence on the template UV, the `fLandTextureTilingMult` name provenance, the G04 format note, the G08 layout-builder inference and the condensed G05 came from the review.

The reviewer decoded 6 of the 36 near PS: `08000001`, `13000001`, `08200201`, `13200201`, `08024001` and `13006201`. It read the first four in full for the normal path.

**Corrections run.** A third run applied the corrections. It re-read these items itself, against the pinned image and the shader decodes. All matched.

1. The image hash, equal to the pin.
2. The VS frame rows `TEXCOORD1..3` and their columns `(Bv, Tv, Nv)`, with no negation and no world matrix.
3. The VS layer UV formula and the forwarding of the weights.
4. The PS decode and weights of `08000001`, with no normalization before the frame transform.
5. The technique 19 fade in `13000001`.
6. The flagged branch in `08200201`: the gate, the sample at `UV × k`, the negations and the formula.
7. The LOD decode swizzle `(R, B, G)` in `09000005`, with no frame.
8. The builder's cross-product order `Nv × U`, component by component.
9. The per-triangle `∂P/∂U` formula and the unweighted accumulation.
10. The stored bytes: `U.y` and `U.z` in the `NORMAL.w` and `BINORMAL.w` slots, `Nv × U` in `BINORMAL.xyz`, and `(U.x + 1)/2` in `POSITION.w`.
11. The UV table fill: `u` from the column, `v` from the row, `s = tiling / 4` (the code divides 4 by the tiling value and then takes the reciprocal), with the image values 3, 4 and 16.
12. The quadrant offsets and the position loop: row grows with +Y.
13. The signed-byte normal read at `1/127` and the stored `+128` byte.
14. The uploader: `c` from the byte at `0x20d8da8` and `k = 1/(float)` of the dword at `0x20d8e50`, with the image defaults 1 and 4.
15. The worked examples, recomputed by hand: the unit length and 30 degrees, the `−Y` case, the `+X` case, the flat-base and flat-detail checks of the flagged formula, and the LOD half-length texel.

The corrections run did not re-read the live vertex declaration format, the land node transform, or the algebra of the other 32 near PS.

Source exposure of the review: pinned native binary and shipped shader bytecode. This is a static review. It is not match evidence for any function, and it does not decide transfer eligibility.

## Negative results and limitations

- **Static only.** No capture, no draw trace, no image comparison. No visual claim.
- **Assumed.** The land node adds only a translation. This was not traced. The world-axis statement depends on it.
- **Unverified.** The quadrant node rotation and scale. The live format of `POSITION.w`, `NORMAL` and `BINORMAL`. The live values of `bEnableSnowMask` and `iLandscapeMultiNormalTilingFactor`. Which keys draw a given cell. The file row order of shipped normal maps. Whether other code changes the material UV offset and scale of land materials. The land normal data values of a real cell: "up is +Z for a flat cell" is inferred from the signed-byte convention.
- **Decoded coverage.** The statement that all 36 near PS follow the same pattern rests on the author's script check. The reviewer decoded 6 records. The corrections run counted normal samples in all 36 and read 3 near PS and 1 LOD PS itself.
- **Not read.** Game plugin data. No plugin-derived number is used.
- **No correction to earlier findings.** See "Relation to earlier findings".

## Reviewer and outcome

The independent Sonnet 5.5 review confirmed the rule: G > 0.5 tilts toward +Y, R > 0.5 tilts toward +X, no green negation. It confirmed 8 groups and corrected 2 (Answer block, G02). Nothing was rejected. A third run applied the corrections and re-read 15 items. The world-axis statement still depends on the land node transform, which was not traced. Static evidence only. Transfer status: UNREVIEWED.
