Transfer status: UNREVIEWED

# Finding: near Lighting pixel shader for ordinary interior geometry: point-light colour limit, point specular, output domain, radius, interior sun and ambient

## Answer

Static only. No game run. No visual claim. Item 26, Mudcrab issue #955.

| Question | Answer | Tag / confidence |
|---|---|---|
| (1) Is the per-light colour clamped before upload or in the shader? | **No clamp at either place.** The point writer `0x154bb90` stores `NiLight.diffuse × NiLight.fade × BSLight.lodDimmer` per channel with plain multiplies. It has no min, max or compare on the colour. The point loop of every decoded near Lighting PS (4,092 records of techniques 0 to 3) has no saturate, min or max on a point-colour operand. So a product above 1.0 reaches the pixel sum unchanged. The first limit is later: the PS output tail soft-limits the lit colour, and the SAO and fog composite pass then does a hard `saturate` (see G05, G06). With no fog, an AO factor of 1 and the stock `k` and `B`, the pixel value stored after the composite is `min(1, k × L)`. `L` is the lit colour (sum of terms × diffuse × vertex colour). `L ≥ 1/k` (1.2) is stored as 1.0. **[Amended 2026-11-25: see A2 in the Amendment at the end.]** | Verified, high. Composite arithmetic: verified for records 49, 51, 53; blend state of the composite draw unverified. |
| (2) Point-light specular | Present in every PS key with bit `0x200` set (1,140 of the 2,292 technique-0 PS keys). Model: half-vector power. For each light `i` of the up to 7 (not first light only), and once for the sun: `spec_i = saturate(N·H_i)^g × C_i × att_i`, with `H_i = normalize(E + ℓ_i)`, `E` = the normalised view-vector input, `ℓ_i` = unit direction to the light, `g` = material `specularPower` (`cb1[4].w`), `C_i` = the point colour of G01, `att_i = 1 − saturate(d/r)²`. The sum is multiplied by the normal-map alpha, by the property `specularLODFade` (`cb2[3].y`) and by `cb1[4].xyz` = material `specularColor × specularColorScale`. **[Amended 2026-11-25: see A3 in the Amendment at the end.]** There is no `N·L` factor, no diffuse texture, no vertex colour. The result is added after the first fog and clamp stage, then a second fog and clamp stage runs with `PostSpec` as its limit. **[Amended 2026-11-25: see A1 and A3 in the Amendment at the end.]** The `Spec` key bit is set when property flag bit 0 or bit 41 is set; property bit 0 is cleared beyond a specular-LOD limit. It has no cell-type test. | Verified, high for the algebra. Medium for the view-vector meaning and the LOD input. **[Amended 2026-11-25: see A7 (view vector) in the Amendment at the end.]** |
| (3) Output domain of an interior frame | Order: Lighting PS tail (S=1, T=0 draws) → target kMAIN → SAO and fog composite (`saturate`, multiplies by `k` once at `Fc = 0`) → blended draws (T=1: `min(k·M, B)`) **[Amended 2026-11-25: see A1 in the Amendment at the end.]** → HDR effect (slot 30, gate byte default 1) → LDR effects. The interior frame **does** pass through the same HDR tonemap chain. No read of the interior byte `0x1420d68f4`, of the TES or Sky singletons, or of a cell type was found in the post-process driver, the HDR render, the colour-stage function or the composite function (details in G06). Only the image-space data source differs: for an interior cell the base block comes from the cell's own image-space link (a null link goes to a lookup of the form id `0x167`, an immediate in the executable; this looks like an error or default path and is unverified), not from the weather blend. The composite output is bounded to [0,1] per channel: records 49, 51 and 53 end in a saturating multiply-add (`mad_sat`). That bound holds for the value the composite writes. Draws that follow the composite into the same target (the second accumulator stage after the composite call) are not covered by it, and their blend state was not traced. So the HDR tonemap input is not shown to be at most 1 per channel at every pixel. The displayed value is therefore not the raw sum. For a pixel written only by the lit pass and the composite it is `saturate(k × …)` first, then the luminance tonemap, bloom, saturation, tint, brightness and contrast, `saturate`, power `1/fGamma`. **[Amended 2026-11-25: see A2 in the Amendment at the end.]** Default kMAIN format `R11G11B10_FLOAT` (26). | Verified for the pass order and the composite arithmetic, high. Tonemap input range at every pixel: not shown (C1). Draws after the composite, final target and back-buffer step: unverified. Composite fog flag in an interior: inferred. |
| (4) Radius use | Confirmed. `x = distance / R` with `R = LIGH.Radius + signed ref extra-data offset` (extra type `0x59` read at `0x16c300`, inferred XRDS). A non-positive sum becomes 0.1. On the model-space branch (raw pass bit 1 clear) the writer transforms the light position by the inverse model transform and divides `R` by the geometry transform's uniform scale (field `+0xac` of the transform block). **[Amended 2026-11-25: see A4 and A7 in the Amendment at the end.]** For pass technique ids 1 (EnvMap) and 16 (Eye) it replaces that scale by 1.0. On the other branch `R` is stored unchanged. No INI scale, no per-light multiplier, no falloff exponent reaches the PS. `att = 1 − saturate(x)²` per light (not `saturate(1 − x²)`: `x` is saturated first). The colour already holds the dimmer. | Verified, high. |
| (5) Interior directional light | The interior cell's directional light is the scene **sun** NiDirectionalLight (the Sky `Sun` object's light, installed by `ShadowSceneNode::SetSunLight` `0x14150f3d0` from the call at `0x65c1bc`). Colour = cell directional RGB / 255 × `NiLight.fade` × image-space `SunlightScale`. Direction from the cell directional angles (`0x41c63b` branch). The Lighting PS key for an interior has **no sun-mask bit** (key bit 13, sun × `t14.x`): the pass builder sets bit 13 only if the interior flag `0x1420d68f4` is zero. A geometry whose property flag bit 52 is set takes another sun wrapper (`scene+0x208`); ordinary interior geometry is assumed not to set it (unverified). So the interior sun is never multiplied by a shadow mask in the near Lighting PS. The `+0xf4` word is read as `NiAVObject::flags` (inferred, bit 0 read as app-culled). `Sun::Update` (`0x41bd90`) does not set bit 0 on the light in the interior branch. Whether the sun mask pass itself runs in an interior is not shown: the pass has no interior gate that I found. RF-LIGHT-GPU-010: the near Lighting pixel shader variants that multiply the sun term by the shadow mask (key bit 13) are never requested while the interior byte is non-zero. Other shader families (water, grass, LOD) and the mask pass itself were not checked. | Verified, high for the key-bit source. The `+0xf4` meaning: inferred. Sun-mask pass execution and other shader families: unverified. |
| (6) Ambient | The six-colour cell DALC data, collapsed to a linear function of the pixel normal: `mean(F0..F5) + Nx(F1−F0)/2 + Ny(F3−F2)/2 + Nz(F5−F4)/2` per channel. It is **not** a flat colour and **not** the cell flat ambient colour (that colour goes to `NiLight.ambient`, which the near Lighting setup never reads). Source for an interior cell: cell lighting struct `+0x28` (or its lighting template when inherit flag bit 0 is set). A cell without a lighting block gives six zero colours. Added in the same sum as sun, points, emissive and the additive term, **after** the sun and point terms are formed and **before** the multiply by diffuse and vertex colour. No scale, no clamp. | Verified, high. |

| Item | Evidence record |
|---|---|
| Status | OBSERVED for verified claims. Inferred and unverified claims are marked. Static only. No runtime capture. |
| Author / human operator | A Sonnet 5.5 research run (`claude-sonnet-5-5`) for the department operator. A later Sonnet 5.5 run applied the review corrections. |
| Reviewer | A separate fresh-context Sonnet 5.5 run (`claude-sonnet-5-5`). Sol was unavailable on a usage limit. Before it wrote its own independent section, the reviewer read a short memory summary of the author's conclusions. Its agreement on points that summary also states is therefore slightly weaker than a fully blind result. See "Independent review". |
| Date | 2026-11-25 CST. Author run 12:53 to 13:22. Independent review 13:23 to 13:41. Corrections applied afterwards. |
| Build | `sse-steam-1-7-104`, retail `1.7.104.0`, Steam build 24914197. Measured SHA-256 of the executable `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f` equals the asserted pin in [builds/target.json](../builds/target.json). |
| Principal function RVAs | `0x154bb90` (point writer), `0x1549550` (per-geometry Lighting upload), `0x1548820` (material constants), `0x1547d20` (shader key lookup), `0x15896a0` and `0x15896d0` (stage key transforms), `0x151a160` (pass builder), `0x1569550` (pass light list), `0x274bc0` (flicker, pulse, fade), `0x2ffd70` (reference radius), `0x14ec3b0` (DALC cache builder), `0x2bc790`, `0x2bbe40`, `0x2bbf30` (interior lighting getters), `0x412df0` and `0x41bd90` (Sky colour and Sun update), `0x14150f3d0` (scene sun light install), `0x2bf340` (cell image-space block getter), `0x14edbf0` (post-process driver), `0x153d120` (HDR render), `0x1539f10` and `0x1541f40` (colour stage and composite), `0x154c010` (fog and `k` writer), `0x1414e8480` (specular LOD fade helper). Function labels are GUESS unless a CrashLogger name appears. |
| Sources and revisions | Pinned executable. `Skyrim - Shaders.bsa` SHA-256 `fd1ba630f443353ed21ed4ca0380968f9c7091c8434518ea3cc79bc6d38c18e7`. Member `shadersfx/shaders011.fxp` SHA-256 `72cfc73eb0938d5949f0b3a8683722a33b671a34b41b750ba138de8d154c5fbc` (re-measured). Shipped `Skyrim_Default.ini`, `Low.ini`, `Medium.ini`, `High.ini`, `Ultra.ini` (text search only). Published cross-checks, read from `origin/main`: [object-lod-ambient-sun-retail-facts.md](object-lod-ambient-sun-retail-facts.md) (#1003), [point-lights-selection-retail-facts.md](point-lights-selection-retail-facts.md) (#1073), [exterior-hdr-path-retail-facts.md](exterior-hdr-path-retail-facts.md) (#1059), [exterior-haze-trace-retail-facts.md](exterior-haze-trace-retail-facts.md) (#1077), [live-k-composite-target-retail-facts.md](live-k-composite-target-retail-facts.md) (#1121), [sun-shadow-remainder-retail-facts.md](sun-shadow-remainder-retail-facts.md) (#1248), [sun-shadows-retail-facts.md](sun-shadows-retail-facts.md). |
| Source exposure | Pinned native binary analysis and shipped shader bytecode decoded locally and offscreen with an SDK disassembler run under Wine. Committed CrashLogger tables on `origin/main` for names and layouts. **No value was read from any game plugin.** This file holds no record field value, no example light colour or radius, no image-space value and no template colour. No decompiler text and no disassembly appears below. No downstream or sibling source was used. |
| Name provenance | Names marked `CRASHLOGGER_PDB(59818@2026.10.24)`: `BSLightingShaderProperty` (`specularLODFade` at `+0x100`, `emissiveColor`, `emissiveMult`), `BSLightingShaderMaterialBase` (`specularColor`, `specularPower`, `specularColorScale`), `NiAVObject.flags`, `NiLight` (`ambient`, `diffuse`, `radius`, `fade`), `BSLight` (`lodDimmer`), `INTERIOR_DATA` (field order), `BSLightingShader::GeometrySetupConstantPointLights`, `RenderShadowmasks`, `RENDER_TARGET`. The key bit names (`Msn`, `Spec`, `Soft`, `Rim`, `Back`, `Projuv`, `Aniso`, `Aspec`, `Wmap`, `Atest`, `Snow`, `BaseSnow`, `CharLight`, `DWDecals`) are strings of the pinned image (`0x141b4f9dc–0x141b4fa38`). **[Amended 2026-11-25: see A6 in the Amendment at the end.]** Bits 13 and 14 have no string; their roles below are from the PS code. All other function labels are GUESS. |
| Intended recipient | Skyrim Research department lead for boundary review under [docs/clean-room.md](../docs/clean-room.md). Proposed use: Mudcrab issue #955, item 26. Maintainer transfer decision pending. |

Addresses are RVAs for image base `0x140000000`. `cbN[i]` is constant buffer N, float4 element i. `N` is the unit lighting normal. `sat` bounds to [0,1]. **Verified** means re-read at the cited static source. **Inferred** means a deduction with assumptions. **Unverified** means the evidence leaves the claim open. The document holds facts and formulas only.

## Question and method

Mudcrab issue #955 reports that interior point lights look flat in game. Mudcrab needs six facts about the near (non-LOD) Lighting pixel shader for ordinary interior geometry: the per-light colour limit, the point specular term, the output domain, the radius use, whether the interior sun is shadowed, and the ambient source.

Method. Private local tooling decoded the shipped shader package offscreen and dumped single native ranges for reading. None of it is published. I decoded 4,092 Lighting PS records of techniques 0 (None), 1 (EnvMap), 2 (Glowmap) and 3 (Parallax) of group 6, plus more techniques where noted. I read about 12 records in full (keys `0x1`, `0x201`, `0x401`, `0x801`, `0x1001`, `0x4001`, `0x4201`, `0x6001`, and diffs against them) and checked the rest by instruction surveys. I followed the writer chain from the point writer to the light initialisers, and the Sky, cell and image-space chain for the interior. Nothing ran in the game.

## Observations

### G01. Point colour: the writer and the shader do not clamp (answers 1)

**Verified.** The point writer `0x154bb90` (`BSLightingShader::GeometrySetupConstantPointLights`, CRASHLOGGER_PDB(59818@2026.10.24)) takes the pass light list from entry 1, reads the wrapper's `+0x48` NiLight and writes `NiLight.diffuse(+0x11c..0x124) × NiLight.fade(+0x134) × BSLight.lodDimmer(+0x14)` per channel to the PS point-colour slots with `mulss` (`0x154bc23–0x154bc64`). The whole routine (`0x154bb90–0x154be02`) holds no min, max or colour compare. It also writes the position (`+0xa0` minus the render offset, or transformed by the inverse model transform) and the radius `+0x128`. The radius is divided by the transform scale only on the model-space branch (`0x154bcf6–0x154bcfe`, see G04).

**Verified.** The inputs are not capped at their sources. The placed-light initialiser converts the three LIGH colour bytes to floats with the constant `1/255` (`0x141b5bdc8`, read), or `−1/255` (`0x14181458c`, read) when form flag bit 2 (Negative) is set (`0x2744ce–0x274560`). So `diffuse` lies in [0,1] (or [−1,0]). `NiLight.fade` is stored unclamped: the creation store at `0x274a82` writes the value `0x300020` returns for the form fade field (plus an optional reference extra float, with a special case for the largest finite float), unless the helper `0x300310` returns true, in which case it writes the earlier register value, which I did not trace, and the per-frame pulse and flicker stores (`0x274f17`, `0x274fe1`) and the explicit-fade store (`0x274c1d`) write `base × (1 − I + I·n)` or the explicit value with no clamp. `lodDimmer` lies in [0,1] (#1073 G10). So the product can exceed 1.0 whenever `fade` does.

**Verified.** The ramp helper `0x275530` (callers `0x140a42850`, `0x140a42b57`, in script-function code) clamps its own progress float to [0,1] in extra data. That is not the NiLight `fade` field. A reset helper `0x2754e0` (caller `0x140a428de`) stores `1.0` into `NiLight.fade`. The callers are script routines (labels GUESS). **Unverified:** which events reach them, so a scripted enable or disable can replace the stored fade by `1.0`.

**Verified.** In the PS, the point colour is `cb2[22+i].xyz`. The accumulation is `acc += (sat(N·ℓ_i) × C_i) × att_i`, a `mul` then a `mad` (read in full or by diff in 8 records). A survey of the loop bodies of 4,092 records (techniques 0 to 3) found no saturate, min or max with a point-colour operand (0 hits), and every record has exactly one loop. The only saturates in the loops are on dot products, the attenuation input and the anisotropic terms. The same instruction-opcode loop signature repeats across techniques 0, 1, 2 and 3 for the same permutation bits (technique 0: 42 distinct signatures; technique 1: 32; 2: 16; 3: 4; identical hashes for matching bits).

**[Amended 2026-11-25: see A7 (all group-6 records) in the Amendment at the end.]**

**Verified.** The first limiter after the light sum is the PS output tail (G05). The second is the composite (G06).

**Confidence: high.** What would change it: a PS record outside the surveyed techniques that clamps inside the loop, or a second writer of the same constants. **Unverified:** records of techniques 4 and above (face, hair, eye and others; only 93 records of technique 4 decoded, see G10).

### G02. Term order and algebra of the standard Lighting PS (answers 4 and 6)

**Verified.** Base record `00000001` (technique 0, key bit 0 only). Inputs: `t0` diffuse, `t1` normal map, tangent-frame interpolants `v3..v5`, pixel position `v2`, vertex colour `v11` (rgb, alpha), fog `v12` (colour rgb, strength w). Constants: sun `cb2[0].xyz` (direction), `cb2[1].xyz` (colour), emissive `cb2[4].yzw`, ambient rows `cb2[11..13]`, points `cb2[15..21]` (xyz position, w radius), `cb2[22..28]` (colour), counts `cb2[29].xy`, additive `cb1[8]`.

```text
n_ts = 2·t1.rgb − 1
N    = normalize( (v3·n_ts, v4·n_ts, v5·n_ts) )
S    = sat(N·Ls) × Cs                                        ; Ls = cb2[0].xyz, Cs = cb2[1].xyz
P    = Σ_{i < min(cb2[29].x, 7)} sat(N·ℓ_i) × C_i × att_i   ; ℓ_i = unit(P_i − p), C_i = cb2[22+i].xyz
att_i = 1 − sat(|P_i − p| / R_i)²                            ; R_i = cb2[15+i].w
Am   = (cb2[11]·(N,1), cb2[12]·(N,1), cb2[13]·(N,1))
Em   = cb2[4].yzw
Ad   = cb1[8].x × cb1[8].yzw
Σ    = S + P + Am + Em + Ad                                  ; per channel, no clamp
L    = t0.rgb × Σ × v11.rgb                                  ; alpha = t0.a × cb2[3].z × v11.w
```

**[Amended 2026-11-25: see A3 (model-space-normal keys) and A7 (emissive, glow and environment-map keys) in the Amendment at the end.]**

The order of the adds is: sun term, point terms (added into the sun accumulator), then ambient plus emissive, then the additive term. All are summed before the diffuse and vertex multiplies. So ambient is a **peer** of the light terms, not a floor that the lights add to after tone steps. Nothing scales the ambient term (no per-interior factor, no clamp). The additive term `cb1[8]` comes from the shader object additive scalar and RGB (zero at start-up per #1003 G05).

**Verified.** `att` uses the saturated ratio `x = sat(d / R)` first and then `1 − x²` (`div_sat` then `mad(−x, x, 1)`), so a pixel at or beyond the radius gets attenuation 0 and the point term is exactly 0 there. The unit direction `ℓ_i` and the `N·ℓ_i` use `rsq` of the unclamped squared distance.

**Verified.** The count `cb2[29].x` (point count encoded by the pass builder as `min(total − 1, 7)`, #1073 G01) is clamped again to 7 in the PS. The shadow-slot count `cb2[29].y` is clamped to 4 in the shadowed variants (G08).

**Confidence: high** for record `00000001` and the variants read in full. The surveys back this for the loop structure of all 4,092 records. **Medium** for "all permutations share the same sum order": the rim, soft, back, aniso and snow variants add terms in the same places (read for `0x401`, `0x801`, `0x1001`), the others were surveyed only for the loop.

### G03. Point-light specular (answers 2)

**Verified.** Record `00000201` (key bits 0 and 9). Differences from the base record: the PS has an extra interpolant `v6` (view vector; direction to the camera is inferred from its use). `E = normalize(v6)` (`0x201`: `rsq` of `v6·v6`). For the sun and for each point light, with `g = cb1[4].w`:

```text
H_s    = normalize(E + Ls)            spec_s = sat(N·H_s)^g × Cs
H_i    = normalize(E + ℓ_i)           spec_i = sat(N·H_i)^g × C_i × att_i      (inside the same loop, i < min(cb2[29].x, 7))
Spec   = (spec_s + Σ spec_i) × t1.a × cb2[3].y × cb1[4].xyz
```

**[Amended 2026-11-25: see A3 (mask, normal, snow keys) and A7 (view vector) in the Amendment at the end.]**

`pow` is `exp(g × log(x))` (`log`, `mul`, `exp`). There is no `N·L` factor: a surface facing away from the light can still receive `N·H > 0`. The specular term is **not** multiplied by the diffuse texture or the vertex colour. It uses the same `att_i` and the same colour `C_i` as the diffuse point term (so it is not clamped either). The sun term is evaluated once and the point terms for **every** light of the up to 7, not the first only (one `log` inside the loop in all 1,140 spec records).

**Verified.** Where the inputs come from:

| PS input | Source |
|---|---|
| `cb1[4].xyz` | Material `specularColor` (`+0x38..0x40`) × `specularColorScale` (`+0x8c`), written when key bit 9 is set (`0x141548fe8–0x14154904e`) to the PS material slot at table byte `+0x59`. That this slot is the `cb1[4]` that the Spec records read is **inferred** from the only Spec-gated write of a colour and an exponent. Names `BSLightingShaderMaterialBase`, CRASHLOGGER_PDB(59818@2026.10.24). |
| `cb1[4].w` | Material `specularPower` (`+0x88`) (`0x141549052`). This is the glossiness exponent `g`. No INI scale or constant multiplies it in this writer. |
| `t1.a` | Normal-map alpha (specular mask). Same sample as the normal. |
| `cb2[3].y` | `BSLightingShaderProperty.specularLODFade` (`+0x100`), uploaded when key bit 9 is set (`0x14154a0a2–0x14154a0bd`). The pass builder computes it with the helper `0x1414e8480` from `fSpecularLODFadeStart` and `fSpecularLODFadeEnd` (compiled 0.09 and 0.10, cached at `0x1420d6bb8` and `0x1420d6bbc`; none of the five shipped INIs sets them). The result is 1 up to Start, falls linearly to 0 at End, and when the input exceeds End the builder clears property flag bit 0 (`0x14151a2cb`; bit 41 is not cleared there), so the PS key loses the Spec bit unless bit 41 keeps it. **Inferred:** that this helper's two input floats (object `+0x144`, `+0x148`) are the distance-like LOD values. Their producer is **unresolved**. |
| Clamp after the sum | The spec sum is added **after** the first fog and clamp stage: `out1 = min(S·Q + B, L)` as in G05, `out1' = out1 + Spec`. A second stage then runs on `out1'` with the limit `PostSpec` (`cb0[1].z`, setting `fLightingOutputColourClampPostSpec`, compiled 1.0): `out2 = min(out1', S·Q2 + B2)` with `Q2 = out1' − k·M2`. |

**[Amended 2026-11-25: see A1 (clamp stages), A3 (mask) and A7 (the `cb1[4]` slot) in the Amendment at the end.]**

**Verified.** The Spec bit in the raw key is set by the pass builder when property flag word bit 0 or bit 41 is set (`0x151a9a2–0x151a9bb`). Nothing in that code reads the interior flag or the cell. So specular exists in the interior whenever the property asks for it and the LOD helper keeps it. For key `0x201` the PS needs only `t0` and `t1`.

**Verified.** Other spec permutations (soft `0x601`, rim `0xa01`, aniso `0x10201`, shadowed `0x4201`, `0x6201` and others) share the loop signature of `0x201` for their spec part. The shadowed variants multiply the light colour by the shadow-mask channel before **both** the diffuse and the spec terms (G08).

**Confidence: high** for the algebra and the sources. **Medium** for the meaning of `v6` (VS output not decoded) and **low** for the LOD helper's input. What would change it: the VS record output that feeds `v6`, a trace of the geometry fields at `+0x144` and `+0x148`.

**[Amended 2026-11-25: see A7 (view vector) in the Amendment at the end.]**

### G04. Radius and attenuation, nothing else (answers 4)

**Verified.** The radius stored in `NiLight.radius.x(+0x128)` is `LIGH.Radius` (form `+0xe4`, an integer converted to float) plus the signed reference offset, from `0x2ffd70`: for a reference whose base object is a LIGH it sums the form radius and the float of reference extra-data type `0x59` (getter `0x16c300` reads `+0x10` of the entry, `0` if absent; `0x2ffe3c–0x2ffe60`). The string `XRDS` appears in the extra-data loader at `0x15c074`; the mapping XRDS to type `0x59` is **inferred**. The sum is cached at `[ref+0x68]+0x24`. In the initialiser (`0x2746a2–0x2746da`) a sum that is not above 0 is replaced by the constant at `0x141b5bde4`, which reads **0.1**. Flicker and pulse do not touch the radius (#1073 G06 to G09).

**Verified.** The writer copies the radius to the PS as `cb2[15+i].w`. On the model-space branch (raw pass bit 1 clear) it divides `R` by the geometry transform's uniform scale (field `+0xac` of the transform block, `0x14154a034`). For pass technique ids 1 (EnvMap) and 16 (Eye) it replaces that scale by 1.0 (`0x14154a02d–0x14154a059`; the technique id is the byte `0x01` or `0x10` in the top bits of the property word at `+0x94`). On the other branch `R` is stored unchanged. No INI value, per-light multiplier or falloff exponent enters either branch. The PS divides the distance by `cb2[15+i].w` with no other factor. The eleven settings of the `bLightAttenuation` group (`uLinearMethod`, `fLinearValue`, `fQuadraticValue`, `fLinearRadiusMult`, `fQuadraticRadiusMult` and others) fill `NiPointLight` fields at `+0x140..+0x148` (`0x274916–0x274a5a`). Neither the point writer nor the Lighting upload reads those fields for points; `+0x140..0x148` of the **sun** light is its direction. The image holds no `fLightRadiusScale`-like name: a string search of the image for `Light`, `Radius`, `Ambient` and `Interior` setting names found `fLightLODDefaultStartFade`, `fLightLODRange`, `fLightLODStartFade`, `fLightEnableDisableFadeTime`, the three `fLightingOutputColourClamp*` names, `fLightRecalcTimer`, `fLightRecalcTimerPlayer`, the `BudgetCaps` counts and `fInteriorShadowDistance`. None changes the radius. The two `uLightCount…Interior` budget settings have no reader of their value field in the saved listing (only their registration code).

**[Amended 2026-11-25: see A4 (meaning of the branch) and A7 (technique ids 1 and 16) in the Amendment at the end.]**

**Verified.** The PS attenuation is `1 − sat(d/R)²` (G02). It applies per light, after the dimmer (which is already inside `C_i`), and multiplies both the diffuse and the specular point term.

**Confidence: high.** What would change it: a runtime read of `NiLight.radius` for a placed light. **Re-read note.** #1073 G12 left three sub-claims unread (the 0.1 fallback source, the reference radius, the colour negation). All three are now re-read and agree. The ordinary value of the transform scale `+0xac` was not determined.

### G05. The PS output tail (answers 1 and 3)

**Verified.** The records I read in full (`00000001`, `00000201`, `00004001`, `00004201`, `00006001`) end with the same tail. The Spec records insert a second tail after the specular add (G03). A count of RGB `min` instructions in the 2,292 technique-0 records gives: non-Spec 654 with one and 498 with two; Spec 1,020 with two, 102 with one and 18 with none. Records with a different count (some Soft, Rim, Back, Snow and Aniso variants) were not read in full, so their tails are **unverified**. With `M = L + F·(Cf − L)` (`F` = `v12.w`, `Cf` = `v12.rgb`), `Q = L − k·M`, `k = cb0[0].w`, `B = cb0[1].x`, `S = cb12[42].y`, `T = cb12[42].z`:

**[Amended 2026-11-25: see A1 and A5 in the Amendment at the end.]**

```text
out.rgb = min(S·Q + B, L) − T·S·Q                     ; target 0 rgb
```

`k` is the copy of the global `0x20d694c` made by the fog writer `0x154c010` (image value `1/1.2 = 0.8333333`, no run-time writer except the console command and the interface draw, per #1077 and #1121). `B` is `fLightingOutputColourClampPostLit` (compiled 1.0, `0x1420d8d00`, cached at `0x14343640c`). The three clamp settings are all compiled 1.0 (`PostLit` `0x1420d8d00`, `PostEnv` `0x1420d8d18`, `PostSpec` `0x1420d8d30`) and go to `cb0[1].xyz`.

For the stock state (`S = 1`, `T = 0`) the tail is a soft limiter, not a fog blend: `out = min(L − k·M + B, L)`. With `F = 0`: `out = L` for `L ≤ B/k = 1.2`, and `out = B + (1 − k)·L` above (slope 1/6). With `F > 0` the fog colour only enters through the limiter. For the blended second-stage draws (`T = 1`) the tail gives `out = min(k·M, B)`, a hard limit at `B`.

**[Amended 2026-11-25: see A1 (two-stage records at `T = 1`) in the Amendment at the end.]**

**Confidence: high** (read from the records; the flag source of `S` and `T` is taken from #1003 G05).

### G06. After the PS: composite, HDR chain and format (answers 3)

**Verified.** The colour stage `0x1539f10` calls the composite function `0x1541f40` once (call at `0x14153a1ca`) after the first accumulator stage. The call is unconditional in that function and has no cell test (see the interior-byte paragraph below). The composite copies the scene to a texture (`t0`), reads the AO texture and the raw depth copy, and returns (records 49, 51, 53 of the trailing block of the shader package, decoded for #1077):

**[Amended 2026-11-25: see A6 (number of calls) and A2 (additions before this formula) in the Amendment at the end.]**

```text
rgb   = k × ( (1 − Fc) × A × C + Fc × Cfc )       ; depth < 0.999999, bSAOEnable = 1, fog flag = 1 (record 53)
final = saturate( rgb × (1 − cb2[7].w) + sparkle )   ; cb2[7].w = bSparklesOnly = 0
```

All three records (49 SAO only: no `k`, no fog; 51 fog only; 53 SAO and fog) end in `mad_sat o0` (records 49, 51 and 53 of the trailing block; last instruction of each record). The composite output is bounded to [0,1] per channel: records 49, 51 and 53 end in a saturating multiply-add (`mad_sat`). That bound holds for the value the composite writes. Draws that follow the composite into the same target (the second accumulator stage after the composite call) are not covered by it, and their blend state was not traced. So the HDR tonemap input is not shown to be at most 1 per channel at every pixel. Static only. At `Fc = 0` and `A = 1` the stored value is `min(1, k × out)`. With G05 this gives `min(1, k × L)` for all `L` for a pixel that only the lit pass and the composite wrote: the PS soft knee is then moot. The variant is record 53 when `bSAOEnable` (compiled 1) and the fog flag are set, record 51 when only fog is set, record 49 with no fog property, and a generic effect (`0x22`, not decoded) when both are off. The fog flag needs a scene fog property and `bSAOApplyFog` (compiled 1; not in the shipped INIs). In an interior the Atmosphere update runs (`Sky::Update` mode 1, calls at `0x412204–0x41221f`); that a fog property then exists is **inferred**.

**[Amended 2026-11-25: see A2 in the Amendment at the end.]**

**Verified.** The composite writes render target 1 (kMAIN) and reads a copy (#1077 G08, #1121). The blend state of the composite draw was not traced; a replace write is the reading that fits the shader (limitation carried over).

**Verified.** After the colour stages the post-process driver `0x14edbf0` (callers `0x14153ade7`, the frame, with input render target 1 = kMAIN, and `0x14098a179`, not traced) runs the active slot 0 to 7 effects, then the HDR effect, slot 30 when byte `0x20d75e4` is nonzero (image value 1, console `ToggleHDR`), else slot 34. It then runs the deferred effects and the dynamic-resolution upsample. The HDR effect chain is the one of #1059 (4-tap and 16-tap luminance downsample, adapt pass, bloom, one tonemap). The tonemap arithmetic, in order, per #1059 G05: luminance, Reinhard or filmic curve with the adapted pair `A.y/A.x`, bloom add, saturation, tint, brightness and contrast, `saturate`, power `cb12[42].x = 1/fGamma`, optional fade blend. **Verified.** No read of the interior byte `0x1420d68f4`, of the TES or Sky singletons, or of a cell type was found in the post-process driver `0x14edbf0`, the HDR render `0x153d120`, the colour-stage function `0x1539f10` and its caller region (`0x140656e60..0x14065791f`), or the composite function `0x1541f40` (which selects its fog record by the state index byte `0x20d6970`). The call to the composite is unconditional in `0x1539f10`. The caller region gates the HDR calls only through a local flag derived from the `+0xf4` bit 0 of an object, a parameter byte and a list compare, none of which is a cell test. The interior byte has five access addresses in the image: `0x14ebf00` (the only store; it also selects the shadow distance), `0x14ebf40` (twin routine), `0x14151a64f` (key bit 13), `0x14152c972` (water pass key bit `0x20`) and `0x141541434`. The last one sits in a fog-constant helper (`0x141541230..0x1415415da`, no caller found) that builds `(fog near RGB, k)` and `(near/(far−near), 1/(far−near), power, max)` and writes them to a different destination buffer when the byte is non-zero. Whether this helper runs on the composite path, and what the second buffer is, is **unverified**.

**Inferred.** The HDR effect output goes to the output render target argument of the driver when no deferred effect remains (`cmovne` at `0x1414edd42`), and otherwise to render target 41 (`kIMAGESPACE_TEMP_COPY`, CRASHLOGGER_PDB(59818@2026.10.24)). The description of render targets 41 and 42 in `0x153b680` uses the same descriptor (full size, DXGI format value `0x1c` = `R8G8B8A8_UNORM`; `0x153b73f–0x153b74f`, create calls `0x153bca4`, `0x153bcb7`). So the temporary copy that follows the tonemap holds 8-bit values (**inferred**: no other write to that descriptor between its start and the create calls was found). **Unverified:** the caller's output target for the frame (`0x153add8`) and the final copy to the back buffer, and whether any LDR effect after the tonemap changes the value.

**Inferred (hardware property).** `R11G11B10_FLOAT` stores no sign and no alpha: a negative lit value (negative-flag light) is written as 0 by the format, before the composite reads it.

**Confidence: high** for the composite saturate and the pass order. **Medium** for "the composite covers the interior frame" because the composite flag chain was read, not run. **Low** for the tonemap input range at every pixel (C1 above). What would change it: a capture of kMAIN before and after the composite in an interior, and the blend state of the draws after the composite.

### G07. Where the interior image space comes from (answers 3)

**Verified.** `Sky::Update` (`0x411ec0`) calls `0x1402bf340(cell)` at `0x14041219d` and `0x140412175` to get the image-space data block (form `+0x20`) for the current cell, then installs it as the manager base data through `0x1414eeaf0` at `0x4121d2` (when the Sky transition fraction is above 0 it first blends into `0x1431df470`, `0x4121ba`). `0x1402bf340` reads the cell flag word (`[cell+0x40]`): when bit 0 is set and bit 8 is clear (an interior cell) it takes the **cell's own image-space link** from the cell extra-data list (getter `0x16fa80`, `0x1402bf382–0x1402bf3ba`). When that lookup returns null the code looks up form id `0x167` and passes it to a helper before it uses `+0x20` (`0x1402bf390–0x1402bf3b5`); that branch looks like an error or default path and its result is **unverified**. When the flag word has bit 0 set **and** bit 8 set, or bit 0 clear without a world-space image-space entry, it returns the weather blend buffer `0x1431df470`. The editor meaning of bit 8 is not verified. The per-frame copy `0x14eec10` then copies the base or console override block into the manager (`+0xc8`), the IMAD modifiers apply, and the normaliser runs (`0x658bc3`, `0x658cf6`).

So the HDR block (eye adaptation, bloom, white point, saturation, brightness, contrast, tint, **SunlightScale**, SkyScale) of an interior is the cell's image-space record (IMGS HNAM, CNAM, TNAM, DNAM, read by `0x2a62b0`, #1059), not a weather value. No value of that record is read or given here.

**Confidence: high** for the source switch. **Unverified:** the editor names of cell flag bits 0 and 8, what the null-link branch returns, and what form `0x167` holds (values live in the plugin).

### G08. Interior directional light and the sun mask (answers 5)

**Verified.** The scene sun wrapper is installed by `0x14150f3d0`, whose only caller `0x14065c1bc` passes `Sky(0x143230518)+0x80 (Sun) → +0x38`, the Sun's NiDirectionalLight. The same object is the ordinary sun in every cell type. `Sky::Update` in the interior mode runs `Sun::Update` (`0x41bd90`, CRASHLOGGER_PDB(59818@2026.10.24)). Its interior branch (modes 1 and 2) builds the rotation from the cell directional angles (`0x2bbfe0` and `0x2bc050` of the cell lighting struct times a degree constant, `0x41c63b–0x41c7c5`), writes `NiLight.ambient` from `Sky+0xcc` and `NiLight.diffuse` from `Sky+0xd8` (`0x41c815–0x41c84f`), and sets flag bit 0 (app-cull) on the two **sky mesh objects** at `Sun+0x10` and `Sun+0x18` (labels GUESS, `0x41c803–0x41c80e`), not on the light object (`Sun+0x38`). `Sky+0xd8` is the cell directional colour: `0x2bbf30` returns the cell lighting colour bytes `+0x4` divided by 255, or the lighting template colour when inherit flag bit 1 is set, or 0 when the cell has no lighting data (`[cell+0x40]` bit 0 clear).

**[Amended 2026-11-25: see A6 (condition for a zero directional colour) in the Amendment at the end.]**

**Verified.** The Lighting upload sets the sun colour as `NiLight.diffuse × NiLight.fade × SunlightScale` (`0x141549ae5–0x141549b22`, #1003 G03), with `SunlightScale` the image-space value at manager `+0xe0` of the **current** block (G07). The interior sun colour is therefore: cell directional colour × `fade` (1.0 unless written; a Sun construction function stores 1.0 at `0x41ba66` and `0x41bb42`; I did not trace other writers) × `SunlightScale` of the cell image space.

**Verified. The interior sun is not shadow-masked in the near Lighting PS.** The pass builder `0x151a160` sets a boolean (`[rsp+0x50]`) from the interior flag byte `0x1420d68f4`: **1 when the byte is 0 (exterior), 0 when it is nonzero (interior)** (`0x14151a64f–0x14151a65d`). The boolean is passed to the light selector `0x1569550` as its sun-mode byte. The selector first takes scene `+0x208` instead of `+0x200` or `+0x210` when the geometry property flag word has bit 52 set (`0x1415695a0–0x1415695b0`). What that wrapper is was not traced. Ordinary interior geometry is assumed not to set that bit (**unverified**). Otherwise, with 0 the selector (`CalculateActiveNonShadowCasterLights`, CRASHLOGGER_PDB(59818@2026.10.24)) uses the plain sun wrapper `scene+0x200` and **never sets its output flag**; with 1 it uses the shadow-directional wrapper `scene+0x210` and sets the flag when that light is among the shadow casters (`0x1569583–0x1569598`, flag logic `0x156974e–0x156975f`, final store `0x15696d8`). The builder sets raw key bit 13 from that boolean (`0x14151aa20–0x14151aa27`). Key bit 13 selects the PS variants that multiply the sun term by `t14.x` (the screen-space shadow mask) — read in `00006001`: `sun = sat(N·Ls) × Cs × mask.x`. Raw key bit 13 is therefore **never** set in an interior. Of the 2,292 technique-0 PS records, 764 have bit 13 and 1,528 do not. An interior can only request the 1,528.

**Verified.** Key bit 14 is a separate switch: the first `min(cb2[29].y, 4)` lights of the point list (the shadow-slot lights) have their colour multiplied by one channel of `t14` before both diffuse and specular. The channel is chosen by the light's shadow-slot index: the point writer stores it per light from wrapper `+0x520` (`0x154bda1–0x154bdb0`), the PS reads it from `cb2[2]` through a constant lookup table indexed by the loop counter. So **shadow-casting local lights keep their masks in an interior**; only the sun mask is dropped. The builder sets bit 14 (`0x14151aa14`) from a flag that needs the context byte at `+0x178` and either a nonzero shadow-light count or the sun-mask boolean, with exceptions for some property flags (`0x14151a8ad–0x14151a8fc`; the exceptions were not traced). That is why bit 13 only occurs together with bit 14.

**Inferred.** The `+0xf4` word that the cascade update tests (the open point of #1248 G7) is read as `NiAVObject::flags` from the committed PDB layout (`NiAVObject` size `0x110`, `flags` after `worldBound`, CRASHLOGGER_PDB(59818@2026.10.24)). Bit 0 is read as the app-culled flag. `Sun::Update` sets bit 0 on the two sky mesh objects (`Sun+0x10`, `Sun+0x18`) in its interior branch, not on the light (`Sun+0x38`). Other writers of that bit on the sun light were not searched. The colour-stage function `0x1539f10` also sets bit 0 of `+0xf4` on the object at `[0x1434362d8]` for the duration of the first stage (it saves the old bit at entry). That object was not identified. The cascade update itself has no interior branch and the shadow-mask render function `0x1539a70` has no interior test (its gates are byte `0x1420d6811` and the count at `0x143436300`; the directional branch also reads byte `0x143436311`, zero in the image, no direct writer). So **the sun mask pass is not shown to be off in an interior**. For ordinary near Lighting geometry the PS variants that read its sun channel are never requested there.

**Confidence: high** for the key-bit claim (key bit 13 gated by the interior flag, re-read twice and by the reviewer). **Medium** for the meaning of byte `0x1420d68f4` (interior-cell-current: set to 1 at `0x1401a2d0d` right after `TES+0xc0` is stored, cleared by sibling routines, one caller passes `(TES+0xc0)!=0`). **Unverified:** whether the mask pass or shadow maps run for the sun in an interior; other consumers of the sun mask (water, grass and LOD shader families were not checked here); the effect of the other two interior-byte readers (`0x14152c972`, `0x141541434`).

### G09. Ambient for an interior cell (answers 6)

**Verified.** In `Sky::Update` mode 1 (`0x412df0`), with no room lighting template and `TES+0xc0` (the current interior cell) non-null (`0x41308d–0x413125`), the code calls the cell getters: `0x2bbf30` (directional colour to `Sky+0xd8`), `0x2bbe40` (ambient colour to `Sky+0xcc`: cell lighting struct `+0x0`, or the template colour when inherit bit 0 is set), and `0x2bc790`. The last one converts the **six directional ambient colours** of the cell struct (`+0x28..+0x3c`) and the specular colour and fresnel power (`+0x40`, `+0x44`) by bytes/255 into the same seven-colour layout that the exterior weather mixer fills, or (inherit flag bit 0 and a lighting template) calls the mixer `0x416fc0` with the template. Then it calls the cache builder `0x14ec3b0` (`0x41313b`). The same builder is used for the exterior (#1003 G02).

**Verified.** The builder (`0x14ec3b0–0x14ec686`) writes, to `0x1420d6978…0x1420d69a4`, per channel: slopes `(F1−F0)/2`, `(F3−F2)/2`, `(F5−F4)/2` and the intercept `(F0+F1+F2+F3+F4+F5+G)/6`, with `G` the zero colour at `0x14331d6f0..f8` (68 references, no store, image value 0). The Lighting upload copies those rows to `cb2[11..13]` (world-space slopes, or rotated to model space on the model-space branch) (`0x141549e89–0x141549efb`). The PS evaluates `row·(N,1)` (G02). A cell without a lighting block gives all six colours zero, and the seventh colour zero with power 1.0 (`0x2bcb04`). So the interior ambient is a **first-order approximation of the six-colour cube** (a mean plus a linear term in the normal), not a per-direction blend and not a flat colour. For a normal along the first axis the result is `mean + (F1−F0)/2`, which differs from the stored face colour `F1` unless the colours are symmetric. The face order is the serialized order. Which face is the positive axis was not verified.

**Verified.** The flat cell **ambient colour** goes to `NiLight.ambient` of the sun light (`0x41c815`). The near Lighting setup range `0x1547d20–0x154c000` has no load from a NiLight `+0x110..+0x118` (one `+0x118` load is a material field). So the near Lighting PS does not use the flat cell ambient colour. **Not checked here:** other shader families (grass reads `NiLight.ambient`, see the earlier grass work).

**Verified.** Nothing scales the interior ambient: no setting, no `SunlightScale`, no clamp between the cache and the PS (G02). The sun colour carries `SunlightScale`; the ambient rows do not.

**Confidence: high.** What would change it: a writer to the cache rows from another source (a second caller of `0x14ec3b0`: callers found at `0x41313b`, `0x4131fb`, `0x413278`, `0x4138f5`, `0x4139d2`, `0x41673f`, `0x9651ed`, `0x965239`; the last two are in the character-preview lighting routine, labels GUESS).

### G10. Permutation keys involved, and what was surveyed (answers 2)

**Verified.** The PS record key is `technique << 24 | bits`. The stage transform for the PS (`0x15896d0`) is `key' = (raw & (0xfffffe05 | ((raw >> 1) & 2))) | 1`: it drops the point-count bits (3 to 5) and shadow-count bits (6 to 8), so one record serves any light count. Bit meaning (names are image strings, roles from the code): bit 0 always set; bit 1 with bit 2 (model-space normals pair); bit 2 `Msn`; bit 9 `Spec`; bit 10 `Soft`; bit 11 `Rim`; bit 12 `Back`; bit 13 sun shadow mask (no string); bit 14 shadow-slot light mask (no string); bit 15 `Projuv`; bit 16 `Aniso`; bit 17 `Aspec`; bit 18 `Wmap`; bit 19 `BaseSnow`; bit 20 `Atest`; bit 21 `Snow`; bit 22 `CharLight`; bit 23 unnamed.

**[Amended 2026-11-25: see A4 (bits 1 and 2) in the Amendment at the end.]**

| Technique prefix (bits 24 to 29) | Image string | Group 6 PS records |
|---|---|---|
| 0 | None | 2,292 |
| 1 | EnvMap | 1,152 |
| 2 | Glowmap | 576 |
| 3 | Parallax | 72 |
| 4, 5, 6 | Facegen, FacegenRGBTint, HairTint | 456, 408, 576 |
| 11, 12, 14, 16 | MultiLayerParallax, TreeAnim, MultiIndexTriShapeSnow, Eye | 624, 372, 144, 192 |

The prefix names come from the name jump table at `0x1589a10` (read: id 0 `None`, 1 `EnvMap`, 2 `Glowmap`, 3 `Parallax`, 4 `Facegen`, 5 `FacegenRGBTint`, 6 `HairTint`, 7 `ParallaxOcc`, 8 `MultiTexLand`, 9 `LODLand`, 11 `MultiLayerParallax`, 12 `TreeAnim`, 14 `MultiIndexTriShapeSnow`, 15 `LODObjectsHD`, 16 `Eye`, 17 `Cloud`, 18 `LODLandNoise`, 19 `MultiTexLandLODBlend`).

Technique 0, bit 9 set: 1,140 records; bit 13 set: 764; bit 14 set: 1,528 (bit 13 only occurs together with bit 14). Examples of standard spec keys (hex, technique 0): `0x201`, `0x205`, `0x207`, `0x601`, `0xa01`, `0xe01`, `0x1201`, `0x4201`, `0x6201` (exterior only), `0x10201` (aniso), `0x20201`, `0x100201` (alpha test). Interior-eligible = bit 13 clear.

**Verified.** Survey results over techniques 0 to 3 (4,092 decoded PS records): every record has one `loop`; every record has the point-position and point-colour indexed reads (`cb2[r + 15]`, `cb2[r + 22]`); the `1 − x²` attenuation appears once per record; in the 1,140 technique-0 Spec records the in-loop `log` appears exactly once; in the records with bit 14 the texture `t14` is read, and in no other. Loop-body opcode signatures repeat across techniques for equal bits. 

**Verified (technique 0 only).** Records with bit 9 and extras: `0x200201`, `0x200001` (snow variants) read `cb1[4].w` but not `cb1[4].xyz`; `0x205` reads no `cb1[4].xyz`. These variants were not read in full. Of technique 4 (Facegen), 93 of 456 PS records were decoded before I stopped the job: all 93 have one loop and no saturate, min or max on a point-colour operand. **Unverified:** the rest of technique 4 and techniques 5 and above; other bit-17 permutations beyond the point loop.

**[Amended 2026-11-25: see A3 and A4 in the Amendment at the end.]**

**Verified.** The ambient-specular variants (bit 17, `0x20000`) were decoded for keys `00020001` and `00020201`. After fog stage 1 they add `sat(rows · (N, 0.15)) × cb2[14].xyz × (1 − N·E)^(cb2[14].w)` (rows = `cb2[11..13]`), together with the specular term. `cb2[14]` holds the seventh DALC colour and the power floored to 1 (written at `0x141549104` when key bit 17 is set). Other bit-17 permutations were surveyed only for the point loop. The bit-17 term is not multiplied by the diffuse texture or the normal-map alpha.

**[Amended 2026-11-25: see A4 (formula) in the Amendment at the end.]**

**Confidence: high** for the bit layout and counts. **Medium** for uniformity beyond the loop.

### G11. Correction to earlier finding: none to merged text; two scope notes

**No correction to a merged finding.** The claims of #1003 (object LOD) G03 to G05 and of #1073 (point lights) G01, G10 to G12 that this run re-read agree with the decoded records and code: colour `diffuse × fade × lodDimmer`, the radius source and the 0.1 fallback, the Negative-flag colour, the term order, the attenuation, the tail formula and `B`. The three #1073 G12 sub-claims its reviewer did not re-read are now re-read (G04).

**Scope note 1, #1059 (HDR path).** #1059 describes the tonemap input as the scene colour in kMAIN with no statement of its range. The composite (#1077 and #1121, records 49, 51, 53, `mad_sat`) bounds the value it writes to [0,1] per channel. That bound covers pixels written by the lit pass and the composite. It does not cover draws after the composite into the same target. This is a scope clarification, not an arithmetic error. That the composite ran in a given frame is **inferred**. The note applies to ordinary world frames, not to the interface draw or menu renders.

**Scope note 2, #1248 (sun shadow remainder) G7.** #1248 left the `+0xf4` bit and the interior-flag boolean at `0x14151a64f` open. The key-bit-13 source is resolved (G08). The `+0xf4` bit is read as `NiAVObject::flags` bit 0 (inferred, G08). What keeps the interior sun cascade update from returning early is **not** resolved. The open point "does an interior draw the sun cascade shadow" stays open. The two other interior-flag readers (`0x14152c972`, `0x141541434`) are still untraced for their effect. For ordinary near Lighting geometry the interior byte stops the sun-mask key bit (bit 13). This does not show whether the sun cascade pass runs in an interior.

## Interpretation and alternatives

**Verified.** In an interior the standard near shader gives each point light a diffuse term `sat(N·ℓ) × C × (1 − sat(d/R)²)` and, when Spec is on, a Blinn-style highlight with the same colour and attenuation. Lights are not limited per channel on the way in. The ceiling that bounds them, for pixels that only the lit pass and the composite wrote, is the composite `saturate` at `k × L ≥ 1`. Ambient is a peer term (a cell-specific mean plus a first-order directional term), and the sun term has no shadow mask.

**[Amended 2026-11-25: see A2 in the Amendment at the end.]**

**Inferred.** A renderer that clamps each light colour to 1 before the sum, that applies the HDR tonemap to unbounded sums, or that uses a flat ambient colour, differs from retail in the steps listed above. A renderer that uses `saturate(1 − x²)` or an exponent on the falloff differs in the shape of the point term. This file does not decide what Mudcrab should do, and it makes no claim about how a scene looks.

**Alternatives not excluded by static reading.**
1. The composite could be absent in a frame (settings or generic effect `0x22`), which removes the hard clamp and leaves the soft limiter of G05 before the tonemap.
2. The pass could pick a different PS (techniques 4 and above, other property flags). Only techniques 0 to 3 were surveyed fully.
3. The effective value of any INI or image-space field depends on files the game reads at run time (`fGamma`, `bSAOEnable`, `bSAOApplyFog`, the cell image space).

## Negative results and limitations

- **Verified, negative.** No clamp of a point colour in the writer or in any surveyed PS loop. No INI radius scale. No per-light multiplier. No falloff exponent. No `NiLight.ambient` read in the near Lighting setup range. No read of the interior byte, the TES or Sky singletons, or a cell type in the post-process driver, the HDR render, the colour-stage function or the composite function (G06). The one reader in a fog-constant helper is unresolved (G06).
- **Unverified.** The runtime values of `k`, `B`, `fGamma`, `bSAOEnable`, `bSAOApplyFog` in a given player's setup; the cell image-space values; the fade value reached by a scripted enable or disable (G01); the editor meaning of cell flag bits 0 and 8 (G07); the meaning of `v6` (G03); the input of the specular LOD helper (G03); whether the sun mask pass or sun shadow maps run in an interior (G08); the frame output target and the back-buffer step (G06); the blend state of the composite draw and of draws after it; the tonemap input range at every pixel (G06); the sun mask pass in an interior and the `+0xf4` bit (G08); the face order of the six ambient colours (G09); PS techniques 4 and above in full (G10); the two LDR effects after the tonemap.
- **Not claimed.** Any visual result, including whether interior lighting "looks flat". Flat, bright or dim are not static facts.
- Static reading gives code paths, constants and shader arithmetic, not in-game values.

**[Amended 2026-11-25: see A7 (meaning of `v6`) in the Amendment at the end.]**

## Relation to earlier findings

- **#1003** (object LOD ambient, sun and point-light output): G01 to G05 here agree with its G02 to G05. They cover the DALC cache builder (slopes `(F1−F0)/2`, mean over six), the sun colour `diffuse × fade × SunlightScale`, the point term and the PS tail. #1003 says the seventh colour and the power do not enter the three ambient rows for object LOD. The near Lighting ambient-specular variants (key bit 17) read them through `cb2[14]` (G10). The two findings describe different shader records. No correction to #1003.
- **#1059** (exterior HDR path): kMAIN default format, `k` and the slope of 1/6 above `L = 1.2` agree with G05 and G06 here. G11 scope note 1 and the optional sentence below add a range statement for the tonemap input. It is a scope note, not an arithmetic correction.
- **#1073** (point lights selection, flicker, dimmer): G01 here re-reads the colour `diffuse × fade × lodDimmer`. G04 here re-reads the 0.1 fallback, the reference radius offset and the Negative-flag colour that #1073 G12 left unread. All agree. G04 adds the divisor exception for technique ids 1 and 16.
- **#1121** (live `k`, composite target): the composite arithmetic and the kMAIN target agree with G06 here. The composite output bound and the unverified blend state of later draws are carried over.
- **#1248** (sun shadow remainder): G08 here resolves the effect of the interior byte at `0x14151a64f` on key bit 13. It does not resolve the `+0xf4` open point. See G11 scope note 2.
- **#806, #812, #946, #1061, #1077:** no conflict found in the overlapping claims (order of sun, points, ambient, emissive and additive terms; fog and tail).

Two optional scope sentences, only if the maintainer wants the cross-reference recorded:

- **#1059, G05 or G12:** "The kMAIN colour that reaches the tonemap is the output of the SAO and fog composite (`mad_sat`, hard clamp to [0,1]) for pixels written by the lit pass and the composite. Draws after the composite into kMAIN are not covered by that bound (#1121, interior point-light finding C1)."
- **#1248, G7:** "For ordinary near Lighting geometry the interior byte stops the sun-mask key bit (bit 13). This does not show whether the sun cascade pass runs in an interior."

Published corrections stay in force.

## Independent review

A separate fresh-context Sonnet 5.5 run reviewed this finding. Sol was unavailable on a usage limit. The reviewer was not the author. It re-derived six areas from the binary and the shader package before it opened the draft: the point writer and PS term algebra, the composite tail and interior gates, the radius arithmetic, the interior byte and key bit 13, the ambient rows and the sum order, and a lane-aware scan of all 4,092 PS records for clamps on the point colour. It then compared the draft group by group. Before its independent section, it read a short memory summary of the author's conclusions (disclosed in the header). Its agreement on points that summary states is slightly weaker than a fully blind result.

| Group | Outcome | Note |
|---|---|---|
| G01. Point colour, no clamp | Confirmed | Writer plain multiplies. Zero clamp operations on a point-colour lane inside the loop of all 4,092 records. Each record has one loop. |
| G02. Term order and algebra | Confirmed | Reproduced on keys `0x1`, `0x201` and `0x20001`. |
| G03. Point specular | Confirmed (algebra) | The builder rule for the Spec bit, the LOD helper and the material slot names were not re-read by the reviewer. |
| G04. Radius | Corrected (minor) | Writer divisor exception for technique ids 1 and 16. Applied. |
| G05. PS output tail | Confirmed | Formula and `min` counts reproduced. |
| G06. Composite and HDR chain | Corrected | Tonemap-input range scoped to the composite output (C1). Interior-byte reader in a fog-constant helper named (C2). Applied. |
| G07. Interior image-space source | Confirmed | `0x167` is an immediate in the executable. |
| G08. Interior sun and sun mask | Corrected (wording, scope) | Property bit 52 wrapper. "No sun shadow in interiors" narrowed. `+0xf4` meaning inferred. Applied. |
| G09. Interior ambient | Corrected (minor) | Axis example scoped to an unverified face order. Bit-17 decode added. Applied. |
| G10. Keys and survey | Confirmed | Counts and the stage key transform reproduced. |
| G11. Earlier findings | Corrected | Scope note 2 no longer claims the `+0xf4` point is resolved. Note 1 tightened. Applied. |

Result: 6 confirmed, 5 corrected, 0 rejected, 0 wholly unverified. Six answers: 1, 2, 4 and 6 confirmed. Answers 3 and 5 confirmed with scope corrections, which are applied above.

Not verified by the reviewer: whether the sun mask pass runs in an interior; what sets `+0xf4` bit 0 on the sun light; the blend state of the composite and of later draws; whether the fog-constant helper is live; the composite variant for an interior frame; kMAIN format and render targets 41 and 42 (taken from #1059); PS techniques 4 and above.

After the review, a later Sonnet 5.5 run applied the corrections. It also re-read 16 key items in the pinned image and the shader package: the writer's plain multiplies (no min, max or compare), the specular algebra on keys `0x201` and `0x20201`, the in-loop `log` count (1,140 of 1,140 specular records; none in the others), the absence of a clamp on the point colour in every technique-0 loop, the term order and the tail, the radius arithmetic and the 0.1 fallback constant, the colour bytes divided by 255 (and the negated constant), the composite records 49, 51 and 53 (each ends in `mad_sat`), key bit 13 and the interior byte, the sun-mask variant `0x6001`, the DALC mean and slope constants, the divisor exception for technique ids 1 and 16, the model-space branch flag, and the property bit 52 sun wrapper. All matched. The counts were recomputed from decoded records of the pinned package. Four records were decoded again and were byte-identical to the earlier decodes.

Source exposure of the review: pinned native binary and shipped shader package. This is a static review. It is not match evidence for any function, and it does not decide transfer eligibility.

Reviewer and outcome: Reviewed independently by a Sonnet 5.5 run. Outcome: 6 confirmed, 5 corrected, 0 rejected. Static evidence only. Transfer status: UNREVIEWED.

## Amendment (2026-11-25, UNREVIEWED)

**Amendment (2026-11-25, UNREVIEWED): second independent check of `interior-point-light-look-retail-facts.md`.**

Scope: only the items below. All other claims stay as published. Static only. Build `sse-steam-1-7-104`. Shader package `shaders011.fxp`, group 6. No plugin value is used. Source exposure: pinned native binary, shipped shader and texture archives, committed CrashLogger tables. Names marked `kSkinned` and `kModelSpaceNormals` are CRASHLOGGER_PDB(59818@2026.10.24).

**A1. Two-stage output tail (answers 2 and 3, G03, G05). Verified.** In records with a second stage (specular, or key bit 17):

```text
X1  = min(S*Q1 + B, L)                 Q1 = L - k*M1 ; no T term in stage 1
Y   = X1 + Spec (and the bit-17 term)
M2  = Y + F*(Cf - Y) ; Q2 = Y - k*M2
out = min(S*Q2 + B2, Y) - T*S*Q2       B2 = PostSpec
```

For `S = 1, T = 1` this gives `out = min(B2, k*M2)`. Snow records (A3) use the same two stages.

**A2. Composite value (answer 1, G06, interpretation). Verified for records 49, 51, 53.** Replace "With no fog" by "In composite records 51 and 53 with fog factor 0". The stored value `min(1, k × out)` then holds for a pixel with depth below 0.999999, with AO factor 1 (record 53) and with the additions below inactive. For a pixel without specular this equals `min(1, k × L)`. For a specular pixel `out` is the A1 result, which includes `Spec`. Record 49 (no fog property) has no `k`: it stores `saturate(out)` under the same conditions.

The records can also change the scene colour before the formula in G06: (a) when `cb2[10].z > 0.5`, a clamped reflection term from `t6`, gated by `t3`, is added; (b) when `cb2[5].w` is not 0, the product of the first two channels of `t4` is added, and in records with AO the factor becomes `min(A + cb2[8].x, 1)` where the second channel of `t4` is above 0.00001. Whether these are active in an interior was not traced.

**A3. Specular scope (answer 2, G03, G10). Verified by shader survey.**
- Model-space-normal keys (bit 2): without bit 1, `N = 2·(t1.r, t1.b, t1.g) − 1` with no normalisation; with bit 1, that vector is transformed by the frame rows and normalised. Specular records read the mask from `t2.r`, not from the normal-map alpha (204 technique-0 records).
- Snow keys (bit 21) with specular, technique 0: 408 records. The 264 without projected UV do not add `Spec` to the colour; they write its luminance to render target 3. The 144 with projected UV (bit 15) add it under a per-pixel selector and also write the luminance.

**A4. G10 correction. Verified.** Replace the sentence on `0x200201`, `0x200001` and `0x205` by: "The 264 technique-0 specular records that read `cb1[4].w` but not `cb1[4].xyz` are the snow records without projected UV. `0x200001` has no specular bit and reads no `cb1[4]`. `0x205` reads `cb1[4].xyz`." In the bit layout, replace "bit 1 with bit 2 (model-space normals pair)" by: "raw bit 1 is the property flag `kSkinned`, raw bit 2 is `kModelSpaceNormals`; the PS key keeps bit 1 only when bit 2 is set." In G04, "model-space branch (raw pass bit 1 clear)" therefore means not skinned; the other branch (skinned) works in world space minus the render offset. In the bit-17 formula read `(1 − sat(N·E))^(cb2[14].w)`.

**A5. G05 counts. Verified.** Replace the RGB `min` counts and the "tails are unverified" sentence by: "In technique 0, 576 non-specular records have one stage and 576 (all key bit 17) have two. All 1,140 specular records have two. Every record subtracts the `T` product once, after its last stage." (The earlier counts matched only one destination mask.)

**A6. Small wording. Verified.**
- Name provenance: `Atest`, `Snow` and `BaseSnow` are at `0x141b47504`, `0x141b4750c`, `0x141b47518`, outside the stated string range.
- G08: the directional colour is zero when cell flag bit 0 is clear (not an interior cell) or the cell lighting pointer `+0x68` is null.
- G06: the colour stage calls `0x1541f40` twice. The call at `0x14153a102` does SAO generation (#1077 G04); the composite is the call at `0x14153a1ca`.

**A7. Added facts (raise earlier tags; implementation inputs).**
- Verified: the specular view vector is `normalize(eye − position)`. The vertex shader forms `eye − position` from vertex constant `cb2[6]`; the geometry writer stores the eye position there in the lighting space (`0x14154a61f..0x14154a697`).
- Verified: the material writer's colour and exponent slot is PS `cb1[4]` (record header byte map).
- Verified: no clamp on a point colour in the loop of any of the 6,924 group-6 PS records; each has one loop.
- Verified: emissive constant is `emissiveColor × emissiveMult`. Glow-map keys multiply it by `t6`. Environment-map keys also add a cube reflection multiplied by the light sum.
- Verified for the traced path: DDS textures are created with the force-sRGB argument 0 (`0x14100dcc0`), so the file format is used. A sample of 577 shipped diffuse-looking textures held only DXT1 and DXT5 headers. No group-6 PS contains a gamma conversion. Inferred: albedo is used as stored (encoded) values. Other texture creation paths were not excluded.
- Inferred: for technique ids 1 and 16 on a not-skinned geometry with scale not 1, the position stays in model units while the radius is not divided, so the effective world radius is `R × scale`.
