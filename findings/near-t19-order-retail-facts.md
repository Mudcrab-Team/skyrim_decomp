Transfer status: UNREVIEWED

# Finding: diffuse, vertex tint and alpha order in near terrain technique 19

| Item | Evidence record |
|---|---|
| Status | OBSERVED for verified claims. INFERRED and UNVERIFIED items are marked. Static only. |
| Author | The Sol research run, `gpt-6.2-sol` via Codex (not the reviewer below). |
| Human operator | Taylor. |
| Reviewer | A separate `gpt-6.2-sol` run via Codex, fresh context. See "Independent review" below. |
| Date | 2026-11-23 CST, which is 2026-11-23 UTC. The author ran from 11:27 to 11:36 CST. The independent review ran from 11:36 to 11:46 CST. |
| Reviewed draft SHA-256 | `b4cba65ad35c9265863375090b60386bbf04a9315d200f42aef05ab5424fc91d` |
| Build | `sse-steam-1-7-104`, retail `1.7.104.0`, Steam build 24914197. Executable SHA-256 `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f`, equal to the pin in [builds/target.json](../builds/target.json). Both runs asserted the equality. |
| Shader records | Lighting group 6 of `shaders011.fxp`. Technique 19: both VS keys and all 18 PS keys. Technique 8 controls: all 18 PS keys and the two VS keys. Technique 8 uses the same low key bits with high byte `08`. The two technique 8 VS payloads are byte-identical to the two technique 19 VS payloads. The author decoded 40 records. The reviewer decoded 38 distinct payloads. |
| Native address | Only the gate writer at `0x1548abd–0x1548afe` is cited. It comes from #946 G08 and #947 G02. All addresses are RVAs. |
| Source exposure | Binary analysis. Both runs used the operator's pinned executable for identity and the shipped Lighting shader package from the operator's retail install. Both runs decoded the shipped shader bytecode statically. Prior reviewed findings #822, #946 and #947 supplied anchors. No downstream implementation source and no sibling implementation was used. |
| Name provenance | GUESS for descriptive labels. This file takes no field, enum or type name from the public generated tables. If a later edit adds one, it must carry the label CRASHLOGGER_PDB(59818@2026.10.24). Shader semantics, constant slots and texture slots come from the decoded shader records. |
| Intended recipient | The Mudcrab department, for terrain work, after boundary review under [docs/clean-room.md](../docs/clean-room.md). The evidence describes shader inputs and outputs on the pinned build. |

**Verified** identifies a static read of the shader records. **Inferred** identifies an interpretation of those facts. **Unverified** identifies missing evidence. VS means vertex shader record. PS means pixel shader record. Nothing game-derived is in this file except counts, constant slots, formulas, shader keys and the pinned hashes.

## Answer

**COLOR0 RGB multiplies the distant contribution, including at full blend weight.** In technique 19 PS, the order is: land noise on the distant RGB, blend toward the distant RGB, diffuse light, vertex tint, then fog bounds and highlights. Alpha follows a separate path and has no RGB tint term.

In the table, `N` is the near layer RGB mixture. `B` is the slot-13 distant sample. `I` is the diffuse light accumulator. `V` is `COLOR0.rgb`. Multiplication of RGB values is component-wise.

| Order | Technique 19 RGB input and result | What COLOR0 touches and what survives at `w = 1` | Parallel target 0 alpha |
|---|---|---|---|
| 1. Land noise | Modulate `B.rgb` by `m = 0.37 + 0.833333 × mixedRed`, from the slot-15 red sample. | The factor and the distant sample do not depend on vertex tint. | The same `m` multiplies `B.a`. |
| 2. Blend | `C = lerp(N, m × B.rgb, w)`, with `w = TEXCOORD7.w × PS b1[0].z`. | The diffuse colour becomes `m × B.rgb` at full weight. | Multiply `m × B.a` by `w`. |
| 3. Diffuse lighting | Multiply `C` by `I`. | The full-weight product is `m × B.rgb × I(1)`. | Multiply the weighted alpha by `PS b2[3].z`. |
| 4. Vertex tint | Multiply the lit RGB by `V`. | `L(1) = m × B.rgb × I(1) × V`. | Multiply by `COLOR0.a`. RGB tint adds no alpha term. |
| 5. Fog bounds and highlights | Form a fog-dependent upper bound on the lit, tinted diffuse. The three plain keys use that bound for the final fog-dependent subtraction. The other 15 keys add the enabled highlights to the diffuse bound, then use the combined RGB for a second upper bound and the final fog-dependent subtraction. | The first bound uses the tinted diffuse RGB. The highlight terms enter as separate additions. The second bound can affect the output even when those additions are zero. | Alpha bypasses these stages. |
| Technique 8 control | Multiply the near-layer mixture by diffuse light and then by `COLOR0.rgb`. Apply the same fog-dependent bound and highlight sequence as the corresponding technique 19 key. | Tint applies to lit near layers. There is no slot-13 or slot-15 distant blend. | Target 0 alpha is zero. |

## Review verdicts

| Group | Verdict | Main correction |
|---|---|---|
| G01. RGB blend, diffuse light and tint | Confirmed | None. |
| G02. Fog bounds and highlights | Confirmed | The review asks for the bounds to be spelled out. The Answer table does this. |
| G03. Target 0 alpha | Corrected | The zero-weight claim needs a finite product of distant alpha and the noise factor. |
| G04. Permutations, vertex records and technique 8 | Corrected | The technique 8 label needs the conditions of #947 G01. The mask sentence is scoped to the active light inputs. |

## Question and method

Does the retail near terrain transition apply vertex tint to the distant contribution, and where do alpha and highlights enter? The author verified the shipped shader archive and the existing Lighting extract against hashes from earlier byte-for-byte checks. The author checked each technique 19 and technique 8 payload against its package record. The author decoded all 40 scoped records with an offline FXC decoder. The author traced all three RGB lanes and alpha to target 0. The check compared the term structure, including branches and light-loop dependencies. It also checked both VS signatures and their colour outputs.

The shipped `Skyrim - Shaders.bsa` SHA-256 is `fd1ba630f443353ed21ed4ca0380968f9c7091c8434518ea3cc79bc6d38c18e7`. Its Lighting package member `shaders011.fxp` has SHA-256 `72cfc73eb0938d5949f0b3a8683722a33b671a34b41b750ba138de8d154c5fbc`. Baselines are #946 at `021abdd766ae66514631cab081afdeda8e825b7c` ([terrain-lod-vs-near-retail-facts.md](terrain-lod-vs-near-retail-facts.md)), #947 at `f8b468152faac993af627052a7ace330f1cc1867` ([terrain-seam-keys-retail-facts.md](terrain-seam-keys-retail-facts.md)), and #822 at `e37cab1e148b5587cba1cb41b7f3c08a948e56f8` ([terrain-lod-shading-retail-facts.md](terrain-lod-shading-retail-facts.md)).

## Observations

### G01. RGB blend, diffuse light and tint

**Verified.** The PS forms `N` from the six weighted layer samples in slots 0–5. The distant sample `B` comes from slot 13. The shader derives `mixedRed` from slot-15 red at three times the distant UV. With `e = saturate((0.55 × sum(B.rgb) − 0.4) × 1.666667)`, `mixedRed = lerp(noiseR, 0.37, 0.8 × e² × (3 − 2e))`. Literals are rounded as shown. The noise modulation affects the distant term before the blend. The RGB dataflow is

`L = ((N + w × (m × B.rgb − N)) × I) × COLOR0.rgb`.

The diffuse light accumulator includes directional and point lights, directional ambient, property emission, and the shader-object additive term. The blend also affects the lighting normal, so `I(1)` denotes this pass's light accumulator evaluated at full weight. With `w = 1`, the pre-fog diffuse is algebraically `m × B.rgb × I(1) × COLOR0.rgb`. The executed multiply-add can round the difference and interpolation. The endpoint identity is algebraic.

**Evidence.** All 18 technique 19 PS keys (listed in G04). The independent review reproduced the six-layer sum, the noise formula and UV scaling, the blend gate, the light product and the final diffuse tint on all RGB lanes. **Confidence: high.** A different shader package or a replacement shader would need a new binding and trace.

### G02. Fog bounds and highlights

**Verified.** Per RGB channel define `E(X) = PS b12[42].y × (X − PS b0[0].w × lerp(X, COLOR1.rgb, COLOR1.a))` and `D = min(E(L) + PS b0[1].x, L)`. The three keys without highlights emit `D − PS b12[42].z × E(L)`. The 15 highlight keys form `U = D + H` and emit `min(E(U) + PS b0[1].z, U) − PS b12[42].z × E(U)`. Here `H` is the enabled standard or layer-dependent highlight, the rim term, or their sum. Each term is added after the diffuse bound. No `COLOR0` component enters `H` directly. At full weight the same tail uses `L(1)` and evaluates any enabled highlights with their own inputs. The bound is an upper minimum. It is not a lower clamp and not a saturation of the final target value. Fog is not only a terminal linear interpolation.

**Evidence.** All 18 technique 19 keys. The review confirmed both equations. This includes the rim-only keys and keys whose highlight evaluates to zero. **Confidence: high.** A draw trace would establish the live inputs to these terms.

### G03. Target 0 alpha

**Verified.** `alpha = (((B.a × m) × w) × PS b2[3].z) × COLOR0.a`. At `w = 1` the weight is unity and the other factors remain. At effective `w = 0`, target 0 alpha is zero when the other factors and the product `B.a × m` are finite. The factor `m` depends on the distant sample RGB and the noise sample. No `COLOR0.rgb` lane enters any written output alpha in these records. Target 0 alpha does not feed target 0 RGB. `COLOR0.a` does not enter target 0 RGB.

**Evidence.** All 18 technique 19 PS keys. **Confidence: high** for the scoped formula. **Unverified.** The bound vertex alpha, the resource view, the blend state and the target alpha write of a live draw.

### G04. Permutations, vertex records and technique 8

**Verified.** All 18 technique 19 PS use the same RGB tint placement, noise and blend order, and alpha rule. There are no exceptions to those rules. The fog and lighting variants are below. All keys are hexadecimal.

| Technique 19 PS keys | Highlight bits and tail |
|---|---|
| `13000001`, `13004001`, `13006001` | Neither highlight bit. One fog-dependent bound and the final subtraction. |
| `13000201`, `13004201`, `13006201` | `0x200`, standard highlight, then the second bound and the final subtraction. |
| `13020001`, `13024001`, `13026001` | `0x20000`, rim, then the second bound and the final subtraction. |
| `13020201`, `13024201`, `13026201` | `0x20200`, standard and rim, then the second bound and the final subtraction. |
| `13200201`, `13204201`, `13206201` | `0x200` plus `0x200000`, layer-dependent highlight path, then the second bound and the final subtraction. |
| `13220201`, `13224201`, `13226201` | `0x20200` plus `0x200000`, layer-dependent highlight path and rim, then the second bound and the final subtraction. |

The receiver variants have neither mask bit, `0x4000` for the point-mask path, or `0x6000` for the point-mask and sun-mask paths. Actual mask use depends on the active light inputs. They preserve the order. The `0x200000` keys alter the layer lighting path and add target 3.

**Verified.** VS `13000001` and `13000201` forward all four mesh `COLOR0` lanes unchanged to the same-named outputs. They compute the fog colour and factor in `COLOR1` and the radial distance factor in `TEXCOORD7.w` separately from `COLOR0`. The PS multiplies `TEXCOORD7.w` by its own constant gate `PS b1[0].z` before it uses the product for RGB and alpha. The gate writer is at `0x1548abd–0x1548afe` (#946 G08, #947 G02). All technique 19 PS interpolate the colour. The corresponding technique 8 VS payloads are byte-identical to these two. All 18 technique 8 PS follow the technique 8 row of the Answer table, including the corresponding highlight and mask cases.

**Verified in #947 G01.** With effective terrain LOD, the settled full-grid updater on a 5 × 5 exterior grid assigns technique 8 to the center and its four cardinal neighbours on the ordinary selector. During the temporary transition override, the center is the sole eligible cell assigned technique 8 by that updater. **Unverified.** The technique selected for the reported draw.

**Confidence: high** for the shader results and for the scoped selector claim carried from #947. **Unverified.** Which permutations draw at a visible seam.

## Interpretation and alternatives

**Verified, algebraic.** At effective `w = 1`, the distant diffuse term still includes `COLOR0.rgb`. A tint below one reduces a channel whose untinted distant diffuse term `m × B.rgb × I(1)` is positive. The four separate LOD vertex shader records in #822 G02 supply white `COLOR0`.

**Unverified.** The actual near tint, its contribution to the visible seam, and the sign and size of any change in the final pixels. Those depend on the draw inputs, fog and other RGB terms, and the render state.

## Relation to earlier findings

- **#822** (terrain LOD shading): its white `COLOR0` (G02) and its LOD formula and alpha rule (G05) describe the four separate LOD records and still hold in that scope, so this finding gives no new correction to #822.
- **#946** (terrain LOD versus near landscape): the near results here agree with its G01–G06 and G08 in the overlapping claims, and this finding gives no correction to #946.
- **#947** (terrain seam keys): the near pixel gate here agrees with its G02, and this finding gives no correction to #947.

Published corrections stay in force. For the producer of `PS b1[8]` named in #822 G05, use the attribution in #946 G04 to the Lighting shader object. The property emissive input is `PS b2[4].yzw`. #947 G03 already corrects the #822 G08 early remap restore in accumulation modes 25 and 26. That remap is separate from the near pixel gate. The corrected #946 G08 gate writes Z from the global enable byte.

## Independent review (2026-11-23 CST, 2026-11-23 UTC)

Reviewer: `gpt-6.2-sol` via Codex, fresh context, separate run. The reviewer did not author the finding. Review window: 11:36 to 11:46 CST on 2026-11-23. Source reviewed: the draft of this finding (SHA-256 above), against the pinned image `sse-steam-1-7-104` (measured SHA-256 equals the pin in [builds/target.json](../builds/target.json)), the shipped shader archive and the Lighting package. Exposure of the review: binary analysis. The reviewer decoded 38 distinct shipped payloads and traced each output lane with its own check. The reviewer sealed its independent results (11:41:58 CST) before it opened the draft and the author's handoff (11:42:03 CST). All 38 payload identities agreed with the author's evidence. This is a static finding review. It is not match evidence for any function. It does not decide transfer eligibility ([docs/clean-room.md](../docs/clean-room.md)).

Result: **2 confirmed (G01, G02), 2 corrected (G03, G04), 0 unverified groups, 0 rejected.** The review reproduced all 18 technique 19 PS, all 18 technique 8 PS and both technique 19 VS. This file already contains the corrected wording.

- G03 needed an endpoint qualification. The zero-weight claim holds only when the product of distant alpha and the noise factor is finite. Finite inputs alone can overflow that product.
- G04 needed a selection-scope qualification. The Answer table called technique 8 the inner cross without the settled-grid conditions of #947 G01. The row is now labelled a control, and the conditions appear in G04.
- The review also asked for the fog bounds to be spelled out (Answer row 5, G02), for the mask sentence to be scoped to the active light inputs, and for the seam interpretation to be limited to the diffuse intermediate. The draft sentence that tied the full-weight tint to a reported darker near draw had no live evidence and is removed.

## Negative results and limitations

**Verified, scoped.** The near shader results agree with published #946 G01–G06 and G08 in the overlapping claims, and with #947 G02 for the pixel gate. The corrected #946 G08 gate writes Z from the global enable byte. #822 G02's white `COLOR0` describes the separate LOD draw.

**Unverified.** The visible seam effect of the full-weight tint. The live draw keys, the bound resources and views, the mesh tint and alpha, the blend and depth state, the fog inputs, and the final pixels at the seam. No game launch, render capture, GPU capture or live constant read was made. This finding is static only. A review verdict is not match evidence, and transfer eligibility is not decided. Transfer status: UNREVIEWED.

## Reviewer and outcome

The independent Sol review reproduced all 18 technique 19 pixel shaders, all 18 technique 8 pixel shaders, and both technique 19 vertex shaders. G01 and G02 were confirmed. G03 needed an endpoint qualification and G04 needed a selection-scope qualification. Live seam behavior remains unverified. Transfer status is UNREVIEWED.
