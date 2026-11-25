Transfer status: UNREVIEWED

# Finding: sun shadow cascade overlap, shadow bias scales and the interior shadow distance

## Answer

Questions: (1) how `fSplitOverlap` is applied to the cascades, (2) where the two shadow bias scales enter, (3) what `fInteriorShadowDistance` does. The last row is a lead for Mudcrab #919.

| # | Question | Answer | Tag / confidence |
|---|---|---|---|
| 1a | Where does `fSplitOverlap` (`O`) enter the cascade bounds? | Each cascade covers the view-distance slice `[near_i, far_i]`. For every cascade `far_i = base_i + O`. For cascades after the first, `near_i = base_(i-1) - O`. The first cascade starts at the camera near distance with no overlap. The last far end is `F + O`. So overlap enters both ends of every internal boundary and the far end of the last cascade. It does not enter the near end of cascade 0. `base_i = 0.5 * (n * (F/n)^t_i + n + (F - n) * t_i)`. | Formula verified, high. Slice use of the two ends: inferred from reads, medium. |
| 1b | Is there a blend band between cascades? | Yes, but only between cascade 0 and cascade 1. The band is `[near_1, far_0] = [base_0 - O, base_0 + O]`. It is `2 * O` wide in view distance (200 at the default `O = 100`). The pixel shader weights cascade 1 against cascade 0 with a smoothstep `w = u²(3 - 2u)`. `u` is linear in depth-buffer value across the band. In view distance `u(v) = (1/near_1 - 1/v) / (1/near_1 - 1/far_0)`. There is no blend at a boundary after cascade 1. That boundary is a hard switch at `far_1`. | Shader and writer verified, high. Slot offsets: verified. Buffer identity of the constants: by fit, medium. `u(v)` form: derived, medium. |
| 1c | Exact split formula and inputs | `t0 = min(D/N, max(S, 500)) / D`, `t_i = t0 + (1 - t0) * i/(N - 1)` for `N >= 2`. `D` = `fShadowDistance`, `S` = `fFirstSliceDistance`, `N` = cascade count, `O` = `fSplitOverlap`, `F = min(A, cameraFar)`, `A` = active shadow distance, `n` = camera near. There is no `fSplitDistanceExp` setting in this image. | Verified, high. |
| 1d | Per-cascade near / far at defaults | Example with `n = 15` assumed (not traced) and camera far at least `A`. Exterior default (`D = A = 8000`, `N = 2`, `O = 100`). Compiled `S = 1250`: cascade 0 = [15, 751.3], cascade 1 = [551.3, 8100]. With `S = 2000` (the `Skyrim_Default.ini` value): cascade 0 = [15, 1141.7], cascade 1 = [941.7, 8100]. See G1 for presets and interiors. | Arithmetic from verified formula, high. `n = 15`: unverified. |
| 2 | `fShadowBiasScale` and `fShadowDirectionalBiasScale` | Both act only in the receiver (shadow-mask pixel shader) as a constant subtracted from the receiver's light-space depth before the shadow-map compare. Units: normalised cascade depth `[0, 1]`. No slope-scaled term and no normal offset in the five sun-mask shaders. The sun does not use `fShadowBiasScale` at all (a constructor overwrites the field with 60.0). `fShadowDirectionalBiasScale` scales only the cascade-0 constant. Sun at defaults: cascade 0 bias `y = 60 * 0.00025 * 0.3 = 0.0045`. Cascades 1 and 2 bias `z = 60 / 12000 = 0.005`. Both are per light, not per cascade (the shader picks `y` or `z` by cascade). | Verified, high for values and receiver use. Units: inferred, medium. Shadow-map generation: no use found, unverified for rasteriser state. |
| 3a | Where does `fInteriorShadowDistance` act? | It replaces `fShadowDistance` as the active distance `A` (and `A²`) while an "interior" flag is set. `A` feeds: the cascade far clamp `F = min(A, cameraFar)`, the radial fade of the sun mask (`B = A²`), the camera-distance rejection of local shadow-casting lights, and other reads listed in G6. It is not a caster cull distance in the code read. | Verified reads, high. Flag meaning: inferred, medium. |
| 3b | Do interiors use cascades? | The cascade update has no interior branch. Interior only changes `A`. Whether an interior draws the sun cascade shadow is unverified. The update returns at once when bit 0 of the flag word at `+0xf4` of the light's attached object is set, and what sets that bit was not traced. The sun light's enabled state in an interior was not traced either. | Verified (no interior branch), high. Draw behaviour: unverified. |
| 3c | Compiled default and shipped INI value | Compiled 3000 (value field `0x1420d9038`). None of the five shipped INIs sets it. | Verified, high. |
| #919 lead | Which settings does the sun shadow direction update read? | `bDisableShadowJumps` (compiled 1) selects the path. At 1 the cascade update uses `fSunStaticTimeUpdateScale` (0.1) with a run-time global that is likely a frame time. At 0 it calls a helper that uses `fSunUpdateThreshold` (0.5, cached as a cosine at light construction) and `fSunShadowUpdateTime` (1.0). At the compiled defaults the helper does not run, so `fSunShadowUpdateTime` is never read. The held direction is replaced when the progress passes 1.0 or the camera-position difference exceeds 0.01. | Which setting is read where: verified, high. Timing units and the stored position: unverified, low. |

| Item | Evidence record |
|---|---|
| Status | OBSERVED where verified. INFERRED where marked. Static only. No runtime trace, no capture and no visual claim. |
| Author / human operator | A Sonnet 5.5 research run (`claude-sonnet-5-5`) for the department operator. A later Sonnet 5.5 run applied the review corrections. |
| Reviewer | A separate fresh-context Sonnet 5.5 run (`claude-sonnet-5-5`). Sol was unavailable on a usage limit. See "Independent review" below. |
| Date | 2026-11-25 CST. The author run started at 11:44 and its evidence checks ended at about 12:00. The independent review ran from 12:01 to 12:15. The corrections were applied afterwards on the same day, with the re-reads listed in "Independent review". |
| Build | `sse-steam-1-7-104`, retail `1.7.104.0`, Steam build 24914197. Measured SHA-256 of `SkyrimSE.exe` `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f` equals the pin in [builds/target.json](../builds/target.json). The measured hash was checked before each read run, and again before the re-reads after the review. |
| Principal function RVAs | `0x157f080` (directional shadow camera update), `0x1566710` (utility-shader technique setup, holds the cascade constant writer), `0x1568300` (utility-shader function that holds the bias constant writer), `0x1568970` and `0x15676c8` chunk (fade constant writers), `0x14ebf00` (active shadow distance setter), `0x15389b0` (light selector), `0x1587bc0` and `0x1588590` (local light camera updates), `0x1581730` (sun direction helper). |
| Sources and revisions | The pinned executable. The five shipped INI files (SHA-256: `Skyrim_Default.ini` `61c151bc60d5d737dad3d65a99a48d9bb8b50812b6b9f1f993323f0337813fa8`, `Low.ini` `f045a0165b9d09d167ea11a228401e21c517497d0a333939db0a2e9ab7a25c9b`, `Medium.ini` `e5cb56c29c28a0e57055b75bf3153c6e7d8510100f656b490fadd3b9bdffc5fe`, `High.ini` `2413dc2f7cbf4551d9c6686780dfd20664c68604cab764604e30daa648606f95`, `Ultra.ini` `10dc00f0dae7783e2f904eabf68be09e4c2460ec1edd30a6231f22b47b847000`). Shipped pixel shader records from the retail shader archive. Committed CrashLogger tables on `origin/main` for names. Earlier findings `findings/sun-shadows-retail-facts.md` (#806) and `findings/compiled-ini-defaults-retail-facts.md` (#1052), both merged. |
| Source exposure | Pinned native binary analysis, five shipped INI files and shipped shader records. Public generated names. No downstream or sibling implementation source. **No value was read from any game plugin.** A plugin-supplied light bias exists in the code path of G5. Its value was not read. No decompiler text or disassembly appears below. No Mudcrab source path appears below. Transfer needs review under [docs/clean-room.md](../docs/clean-room.md). |
| Name provenance | Function names marked `CRASHLOGGER_PDB(59818@2026.10.24)` come from the committed generated tables (`BSShadowDirectionalLight::UpdateCamera`, `UpdateShadowDistanceAndInteriorFlag`, `RenderShadowmasks`, `ShadowSceneNode::ctor`, `ImageSpaceEffectVolumetricLighting::UpdateParams`, `Sky::Update`). All other names are GUESS labels. Setting names are the image's own strings. A PDB name is not evidence of behaviour. |
| Intended recipient | Skyrim Research department lead for boundary review under [docs/clean-room.md](../docs/clean-room.md). Proposed use: Mudcrab issue #857 (item 23 remainder). Maintainer transfer decision is pending. |

Addresses are virtual addresses in this image (base `0x140000000`). **Verified** means re-read at the cited address. **Inferred** marks an interpretation. **Unverified** marks a read that was not made or a run-time fact. Example numbers use stated inputs and the compiled or shipped values. The document contains facts and formulas only.

## Question and method

Mudcrab #857 / PR #961 asks how retail applies the cascade overlap, where the two bias scales enter, and what the interior shadow distance does. Earlier work supplied the global float `fSplitOverlap`, the producers of both bias scales, and the sun-mask fade. This run read the remaining pieces: the CPU code that turns cascade ends into pixel-shader constants, the five directional shadow-mask pixel shader records, the Lighting pixel shaders that read the mask at `t14`, every static read of the active distance and of the interior flag, and the selector tests for local lights.

Tools: private helpers that assert the image hash, a saved native listing, a per-range dump helper, and earlier shader decodes. New private helpers read compiled constants and vtable slots and ran the arithmetic. The listing was grepped with and without the `0x` prefix.

## Observations

### G1. Split distances: inputs, formula, example values

**Verified.** The cascade update `0x157f080` (name `BSShadowDirectionalLight::UpdateCamera`, `CRASHLOGGER_PDB(59818@2026.10.24)`) reads these inputs and no others:

* `D` = `fShadowDistance`, value field `0x1420d9458`, read at `0x14157ff1c`. The code reads `D` directly, even when the active distance is the interior one.
* `S` = `fFirstSliceDistance`, `0x1420d9470`, read at `0x14157ff24`. The image constant 500.0 (`0x141b5bfac`) is a floor.
* `N` = cascade count of the sun light object (field `+0x140`).
* `O` = `fSplitOverlap`, `0x1420d94e8`. Its only two reads are `0x141580086` and `0x141581657` (re-checked with a direct grep).
* `A` = the active shadow distance global at `0x1434869a8`, read at `0x14157f12a`. Then `F = min(A, camera far)`.
* `n` and the camera far value, read from the camera's view frustum at camera `+0x160` and `+0x164` (`0x14157f108–0x14157f145`). The same offsets hold the near and far values in the pixel-constant writer of G3.
* The mix weight 0.5 (`0x141b5be14`) is an image constant. It is not a setting.

The name `fSplitDistanceExp` has no string in the image. The log weight is fixed at one half.

```text
t0     = min(D/N, max(S, 500)) / D
t_i    = t0 + (1 - t0) * i / (N - 1)          for N >= 2   (N = 1 uses t0)
base_i = 0.5 * ( n * (F/n)^t_i + n + (F - n) * t_i )
far_i  = base_i + O
near_0 = n
near_(i+1) = far_i - 2*O  =  base_i - O
```

The loop that stores `near_i` (`0x141580070`) and `far_i` (`0x14158008e`) and the next-near step (`0x141581657–0x141581678`) were re-read. They agree with #806 and #1052.

**Verified, derived.** Shipped INI values. `Skyrim_Default.ini` sets `fFirstSliceDistance=2000.0000` in `[Display]` (line 17). The compiled default is 1250. `Low.ini`, `Medium.ini`, `High.ini` and `Ultra.ini` set `fShadowDistance` to 3000, 3000, 8000, 10000. None of the five files sets `iNumSplits`, `fSplitOverlap`, `fInteriorShadowDistance` or either bias scale. Which `S` applies in a real install depends on the first-run copy rule in #1052 G02. Both are shown below.

Example values. They assume `n = 15`, `O = 100`, `N = 2` and camera far at least `A`. The value `n = 15` equals the compiled `fNearDistance:Display`, but the link from that setting to the world camera was **not traced** (**unverified**). The pre-existing getter for it is at `0x140ff4bb0`. Treat `n` as an input. Values are in game units.

| Case | `S` | `t0` | cascade 0 `[near, far]` | cascade 1 `[near, far]` |
|---|---|---|---|---|
| Exterior default / High (`D = A = 8000`) | 1250 | 0.15625 | [15, 751.3] | [551.3, 8100] |
| Exterior default / High | 2000 | 0.25 | [15, 1141.7] | [941.7, 8100] |
| Low and Medium (`D = A = 3000`) | 1250 | 0.41667 | [15, 797.6] | [597.6, 3100] |
| Low and Medium | 2000 | 0.5 | [15, 959.8] | [759.8, 3100] |
| Ultra (`D = A = 10000`) | 1250 | 0.125 | [15, 748.5] | [548.5, 10100] |
| Ultra | 2000 | 0.2 | [15, 1133.5] | [933.5, 10100] |
| Interior, `A = 3000`, `D = 8000` | 1250 | 0.15625 | [15, 357.9] | [157.9, 3100] |
| Interior, `A = 3000`, `D = 8000` | 2000 | 0.25 | [15, 508.8] | [308.8, 3100] |

The interior rows hold only if the sun cascade update runs in that interior (G7).

**Confidence: high** for inputs and formula. **Low** for the example numbers' link to a real camera (`n`, camera far). What would change it: a runtime read of the camera frustum values.

### G2. How `O` enters the cascade bounds

**Verified.** The update builds, for each cascade `i`, a set of points on the camera view axis at the distances `near_i` (read from `+0x598 + 4i`, `0x141580221`) and `far_i` (read from `+0x5a4 + 4i`, `0x1415802b0` and `0x14158038e`). The code scales the camera frustum extents by those distances to build corner points. So `near_i` and `far_i` are the slice ends of cascade `i`.

**Inferred.** The corner points are the eight corners of the camera-frustum slice that the cascade covers, and the shadow projection for cascade `i` is fitted to them. The fitting step after the corners (`0x141580476–0x141580ae0`) was not decoded.

**Verified, derived.** Because `far_i = base_i + O` and `near_(i+1) = base_i - O`, the slice of cascade `i` extends `O` past its nominal end and the slice of cascade `i + 1` starts `O` before the same nominal boundary. Cascade 0 starts at `n` with no overlap. The last cascade ends at `F + O` (for `N >= 2`, `base_(N-1) = F`). The overlap region of two neighbours is `2 * O` wide and centred on `base_i`.

**Verified.** `O` is one global float. No per-cascade value exists. The setting has no reads other than the two above.

**Confidence: high** for the end values. **Medium** for "the shadow projection is fitted to these slices", because the fitting code was not decoded. What would change it: decoding `0x141580476–0x141580ae0` or a capture of the cascade matrices.

### G3. Receiver side: cascade selection, blend and range

**Verified.** The sun-shadow mask is produced by pixel shaders in shader group 7 (utility shader). Five permutations were decoded in full (`0x202002`, `0x202102`, `0x242002`, `0x282002`, `0x302002`). Their cascade, bias and blend logic is identical. They differ in the filter (one tap, hardware compare 3×3, hardware compare 16 taps) and in extra inputs of `0x202102`. The key builder at `0x14158ea10` (range `0x14158ea42–0x14158eab7`) ORs a filter bit chosen by the global that `uShadowFilterType` is copied into (`0x1414eaebb` writes it to `0x1420d6840`): value 1 sets bit 17, 2 sets bit 18, 3 sets bit 19, 4 sets bit 20. The compiled `uShadowFilterType` is 3 (`#1052` table). So the default permutation is `0x282002`, the 16-tap compare shader (**verified** for the key bits; the default use is **inferred** because the setting could be overridden).

**Verified.** The CPU writer for the cascade pixel constants is in the technique setup `0x1566710` (technique bit 21 gate at `0x141566b14`, loop at `0x141566b60–0x141566bae`). It reads the camera `n` and `f` (`+0x160`, `+0x164` of the camera stored in the global `0x1433d3d28`, assigned in `RenderShadowmasks` at `0x141539ae5` from the same scene camera that the update reads). For each cascade it converts a view distance `v` to a depth-buffer value:

```text
d(v) = f * (v - n) / ( v * (f - n) )          (standard perspective depth, 0 at n, 1 at f)
```

It stores `d(far_i)` for `i < N` into one float4 `Far[0..2]`, then sets `Far[2] = Far[N-1]` and `Far[3] = N` (as float). It stores `d(near_i)` into another float4 `Near[0..2]` and sets `Near[3] = 4.0` (the integer at `0x141b49710`, converted). `Near[3]` is not read by the five decoded shaders. Evidence: `0x141566b04–0x141566bdd`.

**Verified (offsets), inferred (buffer identity).** The pixel-shader record header bytes at object offsets `+0x4b` and `+0x4c` (header bytes 11 and 12) are 8 and 12 in all 21 group 7 records that carry key bit `0x200000`. The writer reads these two bytes and uses them as float offsets (`0x141566b2c–0x141566b38`). So `Far` is row 2 and `Near` is row 3 of the constant buffer that the shader reads as `cb0`. The same records have header byte 0 equal to 8 (the bias row, see G5) and header byte 8 equal to 12 (the fade row `cb2[3]`, where the shader reads `cb2[3].z`). That the CPU writes reach that buffer is by fit of value order and meaning. For example, the shader tests depth against `cb0[2].z` as "inside the last cascade end" and uses `cb0[2].w > 2.5` as "three cascades".

The group 7 records with key bit `0x200000` number 21. The key normaliser at `0x14158ea10` maps a sun mask key to `0x202002` or `0x202102` plus one filter bit chosen from `uShadowFilterType` (1 to 4 select bits 17 to 20). Up to ten keys are reachable that way. The cascade select, blend and bias logic is the same in every record compared.

**Verified.** The shader logic, in prose. Let `z` be the depth-buffer sample at the pixel.

1. If `z > Far[2]` (beyond the last cascade end `F + O`), the mask is fully lit (1.0).
2. Otherwise the cascade is 2 if `N >= 3` and `z > Far[1]`, else 1 if `z > Far[0]`, else 0. The comparisons are strict.
3. The lit fraction `L` comes from the chosen cascade's map, with the bias of G5.
4. Blend. Only when the chosen cascade is 0 and `z > Near[1]`: compute `u = saturate((z - Near[1]) / (Far[0] - Near[1]))`, `w = u²(3 - 2u)`. Take `L1` from cascade 1 (slice index 1, its matrices, bias `z`). The result is `L + w * (L1 - L)`.
5. Final mask = `1 + strength * (result - 1)`, with the radial `strength = 1 - (r²/B)^8` from #806.

No blend exists for a pixel whose chosen cascade is 1 or 2. So with three cascades the 1 to 2 boundary is a hard switch at `Far[1]`, and the 0 to 1 boundary is smooth.

**Verified, derived.** Because `d(v)` is affine in `1/v`, the weight parameter `u` is linear in `1/v` across the band. With `v1 = near_1` and `v0 = far_0`: `u(v) = (1/v1 - 1/v) / (1/v1 - 1/v0)`. The camera `n` and `f` cancel. The half-weight point is the harmonic mean `2 * v1 * v0 / (v1 + v0)`. Example: exterior default with `S = 1250`, `v1 = 551.3` and `v0 = 751.3` give 636.0 (the arithmetic middle is 651.3). With `S = 2000` the values are 941.7, 1141.7 and 1032.1. This holds if the depth texture holds the standard perspective depth of the same camera. The writer's conversion implies that.

**Verified.** The Lighting pixel shaders that read the mask at `t14` (group 6 feature 0, the eight keys `0x6001`, `0x6005`, `0x6007`, `0x6201`, `0x6205`, `0x6207`, `0x6401`, `0x6405`) contain no cascade, overlap or bias term. Each has exactly one `t14` use. It samples `t14` at the screen position (scaled and clamped by pixel constants from the frame buffer `cb12`, slots 43 and 44, and the shader's own `cb0[2]`), takes the first channel, and multiplies it with the directional light colour (`cb2[1].xyz`) and with `saturate(N·L)` (`cb2[0].xyz`). All overlap and blend behaviour therefore lives in the mask pass.

**Confidence: high** for the shader logic and the CPU conversion. **Medium** for the buffer identity of the slot mapping and for the `u(v)` closed form. What would change it: a constant-buffer capture of one frame.

### G4. Other uses of the far depths

**Verified.** The routine at `0x1531b30` (saved chunk `0x141531ba5–0x141531cbc`) converts `far_0` and `far_1` with the same depth formula. It stores them, then the value at index `N-1`, then `N` as a float, then a 1.0 / 0.0 flag (1.0 when `iEnableShadowCastingFlag` is 1), into a global block starting at `0x143435ec0`. The mask shaders of G3 do not use it. **Unverified:** the consumer of this block. No direct address read of `0x143435ec0` was found, and the block sits inside an array that the same routine uploads from `0x143435db0`.

**Confidence: medium** that this block is a second copy. What would change it: finding the reader of `0x143435ec0` through its base array `0x143435db0`.

### G5. Bias scales: where they enter, units, final values

**Verified.** Only one reader of the light bias field `B` (light `+0x540`) exists in the code range `0x140e00000–0x1415fffff` (direct displacement grep): the writer in function `0x1568300–0x1568964` (reads at `0x141568906` and `0x141568920`). Creators write the field at `0x14155c572` (base constructor from `fShadowBiasScale`, `0x1420d9080`), `0x14157e8a3` (sun constructor, constant 60.0) and `0x14150c970` (local lights, from a creation descriptor). `fShadowBiasScale` has one read (`0x14155c56a`). `fShadowDirectionalBiasScale` has one read (`0x1415688f4`). I re-checked all four with direct address greps.

**Verified.** The writer stores two floats per light in the pixel constant row `cb2[2]`: `y = B * 0.00025 * k * G` and `z = B * (1/12000) * S' * G`. `k = fShadowDirectionalBiasScale` for directional lights (predicate `r`, see #1052 G04) and 1.0 otherwise. `S'` is the image float at `0x1420d8ffc` (1.0, no setting). `G` is the global at `0x1434869b0`.

**Verified, new.** `G` is 0.0 in the file image and becomes 1.0 only in the large startup routine `0x1414ea2d0` (store at `0x1414eaea7`; `S'` is stored 1.0 at `0x1414eaeb1`). That routine runs once, right after the call that creates the shadow scene node (`ShadowSceneNode::ctor` call at `0x140655b46`, call to `0x1414ea2d0` at `0x140655b63`). That call is the only direct call. A small wrapper at `0x14eb110` also tail-jumps to the routine. The wrapper has no direct call and no 8-byte data pointer, so a later second run is not excluded. So `G = 1.0` before any frame draws, in the normal start order. This closes the order question that #1052 G04 left **unverified**. Tag: inferred, high (call order, not a trace).

**Verified.** In all five mask shaders the bias selection is: cascade 0 uses `cb2[2].y`. Cascades 1 and 2 use `cb2[2].z`. The shader subtracts the bias from the receiver's depth in light space, then lights the pixel if the stored depth is greater than or equal to the result (explicit compare in key `0x202002`; hardware comparison sampler with the same reference in the filter permutations). The cascade-1 sample inside the blend of G3 also uses `cb2[2].z`. The shader reads no normal and has no slope-dependent term. The constants are the only bias in these shaders.

**Verified, derived.** Final sun values at default settings (float32 arithmetic with the image constants gives `0.0045000003` and `0.0050000004`):

```text
y = 60.0 * 0.00025 * 0.3 * 1.0           = 0.0045      (cascade 0)
z = 60.0 * (1/12000) * 1.0 * 1.0         = 0.005       (cascades 1 and 2)
```

`fShadowBiasScale` (1.0) does not enter the sun values. The sun constructor overwrites the field. A local light receives `b / 4000` and `b / 12000` where `b` is its creation-descriptor float. The placed-light producer takes `b` from the light form's data (not read here, plugin data). The loading-menu producer uses `fLoadingMenuShadowBias` (compiled 30.64).

**Inferred.** Units: the compared value is normalised light-space depth of the cascade projection. To convert to game units one must multiply by the cascade's depth extent. That extent was not traced. So the world-space bias differs per cascade, even though `y` and `z` are nearly equal.

**Unverified.** (a) Verified for the offset: the bias writer indexes by object byte `+0x40` (record header byte 0), which is 8 for the mask records, so the two floats land in row 2 of the buffer the shader reads as `cb2` (`y` for cascade 0, `z` for the others). That the write goes to that buffer is by fit. (b) Any rasteriser depth bias or slope bias in the shadow-map generation pass: no read of the two settings or of `B` occurs there, but a fixed render-state bias was not searched for. (c) Whether other receivers (terrain or LOD shadow code) use these constants.

**Confidence: high** for the producers, the formula and the arithmetic. **Medium** for the buffer identity of the slot mapping and for units. **Low** for the claim that no other bias exists in the casting pass. What would change it: a constant-buffer capture, or a scan of the shadow-map pass render state.

### G6. `fInteriorShadowDistance` and the active distance

**Verified.** The setting `fInteriorShadowDistance:Display` has its object at `0x1420d9030` and value field `0x1420d9038`, compiled 3000, class `INIPrefSetting` (`SkyrimPrefs.ini` domain, per the #1052 table). None of the five shipped INIs sets it. Its code references are exactly three: reads at `0x1414ebf0a` and `0x1414ebf49`, and a store at `0x14155c678` in a small routine (`0x14155c670`) that sets `fShadowDistance`, `fInteriorShadowDistance` and `A` to one value. No direct call or data pointer to `0x14155c670` exists in the image (**verified** by grep and a data scan), so this setter is unreferenced statically.

**Verified.** `UpdateShadowDistanceAndInteriorFlag` (`0x14ebf00`, `CRASHLOGGER_PDB(59818@2026.10.24)`) stores its argument byte at `0x1420d68f4`, then sets `A` (`0x1434869a8`) to `fInteriorShadowDistance` if the byte is non-zero, else to `fShadowDistance`, and `A²` (`0x1434869ac`). A twin routine without the argument at `0x14ebf40` has no caller. The startup routine sets `A = fShadowDistance` and `A² = A * A` at `0x1414eae8b–0x1414eae9f`.

**Verified (call sites), inferred (meaning).** Four direct callers of `0x14ebf00`:

* `0x1401a2d0d` passes 1. It sits in the routine that stores a cell pointer at `TES + 0xc0` just before (`0x1401a2d06`).
* `0x1401a30be` passes 0, at the entry of a sibling routine.
* `0x14099bdf8` passes 0 (inside a world-load style routine).
* `0x14099c513` passes `(TES + 0xc0) != 0`.

The earlier point-lights finding (`findings/point-lights-selection-retail-facts.md`, G11) already reads `TES + 0xc0` as the current interior cell. So the flag is "an interior cell is current". Confidence for that meaning: medium.

**Verified.** Readers of `A` or `A²`:

| Address | What it does with the value | Tag |
|---|---|---|
| `0x14157f12a` | Cascade far clamp `F = min(A, camera far)` (G1) | verified |
| `0x1415676ce`, `0x141568982` | Fade constant `B = A²` when the light's fade flag is set, else 1e8 (`0x14192d610`). The mask shader uses `1 - (r²/B)^8` with the camera-centred radius `r` (#806 G2). Interior default: fade radius 3000. | verified |
| `0x141587ea3`, `0x14158885f` | Local shadow light rejected when `(distance² - radius²) * lodAdjust >= A²` and the light's `lodFade` flag is set. Re-read, agrees with #806 G5. Interior default `A² = 9000000`. | verified |
| `0x1414e6540`, `0x1414e67fe`, `0x1414e681c` | See next paragraph (mesh LOD fade distances raised to at least `A`) | verified reads, medium meaning |
| `0x1415500cf` | A volumetric-lighting parameter routine (`ImageSpaceEffectVolumetricLighting::UpdateParams`, name `CRASHLOGGER_PDB(59818@2026.10.24)`) computes a practical split depth from `A` with `t = 1/N`, ignoring `S` and `O` | verified read, meaning unverified |
| `0x141566ebf`, `0x1415677d4` | Read inside other technique-setup chunks (a two-value split block gated by technique bit 18 uses `0.2 * A` and `A - 5`) | verified read, purpose unverified |

**Verified.** The mesh LOD fade routine in the range `0x1414e6440–0x1414e6842` (unnamed, GUESS: "mesh LOD fade distance helper") computes each LOD-level fade distance as a per-node factor times a global. When the global is positive and the product is below `A`, the result is set to `A`. The globals at `0x1433d3c28–0x1433d3c80` are copied at `0x1414e6ec0–0x1414e6f4c` from the settings `fMeshLODLevel1FadeDist`, `fMeshLODLevel2FadeDist` and the two `…TreeDistance` settings. So `A` is a lower bound on those fade distances. **Verified (reads), inferred (effect).** The shipped Low preset sets `fMeshLODLevel2FadeDist` to 1600 and Medium sets it to 3000. The Low value is below the Low active distance of 3000. Whether the floor changes a result depends on the per-node factor that multiplies the global. That factor was not decoded, so the product can be above or below `A`. The compiled values 9999999 and the High and Ultra preset values 999999 are above every `A` in this finding. The floor depends on `A`, so entering an interior (`A` = 3000 at the compiled default) can raise a computed fade distance that is below 3000. Static only: no run or capture shows a changed fade. The per-node factor and the exact meaning of each global were not decoded (**medium**).

**Confidence: high** for the setting, the setter and the reads. **Medium** for the flag meaning and the fade floor. What would change it: tracing the node factor, or a runtime read of `A` while entering a cell.

### G7. Do interiors use cascades?

**Verified.** The directional update `0x157f080` has no read of the interior flag. Its only interior-dependent input is `A` through `F` (G1). The split fraction still uses the exterior `fShadowDistance` as `D`. With the defaults the interior cascade 0 is therefore shorter than the exterior one (G1 table), and the last cascade ends at `3000 + O`.

**Verified.** The per-frame callers that update the sun light (`0x141538075` and `0x1415388ec` call the light's update virtual unconditionally when the byte `0x143436311` is zero) have no interior test. The byte `0x143436311` has no direct write anywhere in the image: nine reads, no store (checked with and without `0x`). Its image value is 0. A block clear or a store through a pointer was not excluded. This extends #806 G5, which left the byte's writer **unverified**.

**Verified.** The cascade update returns early without work when bit 0 of the flag word at `+0xf4` of the light's attached object is set (`0x14157f0fb–0x14157f102`). The earlier point-lights finding skips ordinary lights whose light-object flag word has bit 0 set. The meaning of the bit for the sun, and what sets it in an interior, was not traced (**unverified**).

**Verified.** Three other render sites read the interior flag at `0x1420d68f4`: `0x14151a64f` (lighting-property pass setup, sets a boolean to 0 in interiors), `0x14152c972` (water pass key, sets bit `0x20`) and `0x141541434` (an image-space setup argument). Their effect on shadows was not traced.

**Inferred (limited).** Neither the cascade update nor its two per-frame callers test the interior flag. The cascade update does return at once when bit 0 of the flag word at `+0xf4` of the light's attached object is set. What sets that bit for the sun, including in an interior cell, was not traced. The code that decides whether the sun light object is enabled in an interior was not followed to the shadow update. (The sky mode 1 path of `Sky::Update` builds the sun direction from the cell's lighting angles, per `findings/sky-sun-ambient-day-retail-facts.md`.) So whether an interior draws cascade shadows is **unknown** from this static reading. What would change it: a trace of the sun light's enabled state and of the `+0xf4` flag bit for an interior cell, or a render capture.

**Confidence: high** for "no interior branch in the cascade update". **Low** for any claim about drawn interior sun shadows.

### G8. Found on the way for #919 (sun shadow direction update)

**Verified.** The sun shadow direction is latched in the cascade update. `bDisableShadowJumps` (compiled 1, `0x1420d9500`) is tested at `0x14157f323`. With the compiled value 1 the update runs an inline path. With 0 it calls the helper `0x141581730` (its only call, `0x14157f41a`).

**Verified.** Inline path (default). The update sets a flag at light `+0x5b4` when the length of a camera-position difference exceeds 0.01 (`0x14157f2fd–0x14157f314`; what the second position at camera `+0xd4` is was not identified). A progress value at light `+0x5b0` exists. If the progress is at most 1.0 and the flag is clear, the code adds `global / max(fSunStaticTimeUpdateScale, 1e-6)` to the progress and keeps the held direction (`0x14157f34f–0x14157f396`). `fSunStaticTimeUpdateScale` compiles to 0.1 (value field `0x1420d94b8`). The global numerator is `0x1420d68dc`. It is 0.0 in the file image and has no static writer, so it is a run-time value. Its meaning (a frame time is likely) is **unverified**. If the progress is above 1.0 or the flag is set, the code replaces the held direction with the normalised current direction of the light (first column of the light object's world rotation) and sets the progress to 0 (`0x14157f39b–0x14157f410`).

**Verified.** Helper path (`bDisableShadowJumps = 0`). `fSunUpdateThreshold` (compiled 0.5, value field `0x1420d9488`) is read once, in the sun constructor (`0x14157e559`). The read runs only while the cached cosine at `0x1420d9528` is below 0 (compiled value -1.0). The code clamps it to `[0, 90]`, multiplies by pi/180 (`0x1418121c8`), applies the C runtime `cosf`, and caches the result at `0x1420d9528`. The only reader of the cache is the helper (`0x1415817ed`). The helper keeps the held direction while `dot(held, new) >= cos(threshold)`, replaces it at once if the dot is below `2 * cos(threshold) - 1`, and otherwise starts a blend whose progress grows by `global / max(fSunShadowUpdateTime, 1e-6)` (`0x1415818e2–0x141581906`, compiled `fSunShadowUpdateTime` 1.0, `0x1420d94a0`). A second helper at `0x1415819c0` has no direct call and no data pointer in the image.

**Consequence (derived).** At the compiled defaults, the cascade update reaches `fSunStaticTimeUpdateScale` but not `fSunUpdateThreshold` or `fSunShadowUpdateTime`. `fSunUpdateThreshold` is still read once at light construction, whatever `bDisableShadowJumps` is. The cached cosine that this read produces is consumed only by the helper at `0x141581730`, which runs only when `bDisableShadowJumps` is 0. `fSunShadowUpdateTime` has one read, inside that helper. The merged #806 text says the timing helper reads `fSunShadowUpdateTime`. That is correct. This run adds that the helper runs only when `bDisableShadowJumps` is 0.

**Unverified.** Units of the progress rate, the identity of the stored position at camera `+0xd4`, and how the latched direction feeds the shadow camera after `0x14157f464`. This is a lead for #919. Confidence: **high** for which setting is read where. **Low** for the timing meaning.

## Relation to earlier findings

**No error found** in #806 (`findings/sun-shadows-retail-facts.md`) or #1052 (`findings/compiled-ini-defaults-retail-facts.md`). The re-read items agree: the split formula and its endpoint values, the reads of `0x1420d94e8`, the producers and formulas of both bias scales, the 60.0 constructor store, `y = 0.0045`, `z = 0.005`, the radial fade `1 - (r²/B)^8`, `B = A²` or 1e8, and the local-light rejection formula with `A²`.

This finding adds the following. Each closes an item that the earlier text marked unverified or left unsaid. None contradicts it.

* #1052 G03 left open which path consumes the near and far arrays for blending. G3 answers it.
* #1052 G04 left the run order of the store at `0x1414eaea7` unverified. G5 gives the call order at startup (not a trace).
* #1052 G04 called the bias slot index inferred. G5 reads the offset from the record header (verified), and keeps the buffer identity by fit.
* #806 §5 left the writer of the byte `0x143436311` unverified. G7 reports that no direct writer exists (nine reads, no store).
* #806 §2 says the radial fade and the projected final-split test use separate comparisons. That is right. G3 adds that the cascade ends are compared in depth-buffer units, not view distance.
* #806 says the sun-direction timing helper reads `fSunShadowUpdateTime`. That is right. G8 adds that the helper runs only when `bDisableShadowJumps` is 0.

## Interpretation and alternatives

**Inferred.** Retail builds each cascade from a slice of the camera frustum that is widened by `O` on both sides at every internal boundary. It uses the widened overlap to blend cascade 0 into cascade 1 with a smoothstep that is linear in `1/distance`. The first-cascade length is set by `fFirstSliceDistance` through `t0`. The overlap parameter does not change that length except through the `+O` shift.

**Alternative for the shadow-map fit.** The fit stage after the corners may enlarge, round or snap the projection (`bDirShadowMapFullViewPort`, `bDisableShadowJumps`). If it does, the real map coverage of cascade `i` can exceed `[near_i, far_i]`. This does not change the shader's selection and blend, which use the stored ends.

**Alternative for the slot mapping.** The record header bytes give the row offsets (8 and 12). If the CPU writes went to a different buffer than the one the shader reads as `cb0`, the logic of G3 would change. The fit in value order and meaning makes this unlikely, but it was not excluded by a capture.

## Negative results and limitations

* **Verified.** No setting named `fSplitDistanceExp` exists in the image.
* **Verified.** No code read of `fShadowBiasScale` affects the sun (overwritten at construction).
* **Unverified.** Camera near and far values at run time. The example numbers in G1 assume `n = 15`.
* **Unverified.** The fit of the cascade projection to the slice, that the CPU constant writes reach the buffer the shader reads (by fit only), and any fixed rasteriser bias in the casting pass. A fixed render-state bias was not searched.
* **Unverified.** Whether an interior draws the sun shadow, what sets the sun light's disabled bit, and the meaning of the other three readers of the interior flag.
* **Unverified.** The reader of the global block at `0x143435ec0`, the purpose of the volumetric-lighting and technique-setup reads of `A`, and support for more than three cascades (the shader tests at most three).
* **Static only.** No run, capture, comparator result or visual result supports any statement here. No plugin value was read. The depth-space formula assumes a standard perspective depth buffer for the same camera.

## Amendments in this PR

The same PR adds three dated one-paragraph amendments (2026-11-25, UNREVIEWED, static only) to the two earlier findings. Each states a fact from G3, G5 or G7 where the earlier text said unverified. No earlier claim is changed.

* `findings/compiled-ini-defaults-retail-facts.md`, G03: the technique setup sends the cascade near and far depths to the sun-mask pixel shaders (consumer path).
* `findings/compiled-ini-defaults-retail-facts.md`, G04: the call order of the startup store of the bias global.
* `findings/sun-shadows-retail-facts.md`, section 5 confidence line: the byte at `0x143436311` has nine reads and no direct store.

## Independent review

Reviewer: a fresh-context Sonnet 5.5 run (`claude-sonnet-5-5`), separate from the author. Sol was unavailable on a usage limit. The reviewer wrote its own results first, from the pinned image, a saved listing and decoded shader records, before it opened the draft or the author's handoff. Static only. The reviewer found no wrong claim in the formula, constants or readers. It found two over-reaching sentences and three tag upgrades or clarifications.

Result: **7 confirmed, 2 corrected, 0 unverified, 0 rejected** (nine items: G1 to G8 and the relation block).

| Group | Verdict | Main correction |
|---|---|---|
| G1 (inputs, formula, example values) | Confirmed | None. All eight example rows and both half-weight points were recomputed exactly. |
| G2 (how `O` enters the bounds) | Confirmed | None. |
| G3 (receiver, blend, key) | Confirmed, tag upgrade | The slot offsets are verified from the record header bytes. Only the buffer identity stays by fit. The family has 21 records, not five. |
| G4 (second copy of far depths) | Confirmed | None. The consumer stays unverified. |
| G5 (bias scales) | Confirmed, tag upgrade | The bias slot offset is verified (header byte 0). The buffer identity stays by fit. |
| G6 (`fInteriorShadowDistance`) | Corrected | One sentence claimed the Low preset value changes under the mesh LOD floor. The per-node factor was not decoded, so the sentence was replaced with a conditional form. |
| G7 (interiors and cascades) | Corrected | One sentence said nothing blocks an interior sun shadow. That contradicts the early return on the `+0xf4` flag bit. It now says the matter is unknown. |
| G8 (#919 lead) | Confirmed, clarification | One sentence added: `fSunUpdateThreshold` is still read once at construction. |
| Relation to earlier findings | Confirmed | None. No contradiction with #806 or #1052. |

Counts: confirmed as written or with a tag or clarification 7 (G1, G2, G3, G4, G5, G8, the relation block). Corrected 2 (G6, G7). The reviewer did not verify: the camera near and far values at run time, the fit stage after the corner points, all eight Lighting `t14` keys (it decoded one record), a line-by-line comparison of all 21 mask records (it compared four in full and the other 17 by pattern), and any run-time effect.

After the review, the correcting author re-read these items in the pinned image and the saved listing (the measured hash matched the pin first). All matched, with two small changes noted at the end.

1. The split code at `0x14157ff1c–0x14158008e`: the reads of `fShadowDistance` and `fFirstSliceDistance`, the 500.0 floor, the cascade count from the light's `+0x140` field, the `t0` and `t_i` steps, the linear and logarithmic mean with the 0.5 weight, and `far = base + O`. Values read from the image: `D` 8000, `S` 1250, `O` 100, `iNumSplits` 2.
2. The next-near step at `0x141581657–0x141581678`: `far_i - 2 * O` with the 2.0 constant.
3. The readers of `fSplitOverlap`: exactly two, at `0x141580086` and `0x141581657` (direct grep of the listing).
4. The pixel-constant writer at `0x141566b04–0x141566bdd`: the depth conversion, `Far[2] = Far[N-1]`, `Far[3] = N`, and `Near[3] = 4.0`.
5. The blend in the decoded `0x282002` record: the `cb0[2].w > 2.5` gate, `u = saturate((d - cb0[3].y) / (cb0[2].x - cb0[3].y))` and the smoothstep `u²(3 - 2u)`.
6. The bias products. The constants are 0.00025 (`0x141b4aca8`), 1/12000 (`0x141b4aca4`), `fShadowDirectionalBiasScale` 0.3 and the float 1.0 at `0x1420d8ffc`. By hand: `60 × 0.00025 × 0.3 = 0.0045` and `60 / 12000 = 0.005`. In float32 with the image constants the results are `0.0045000003` and `0.0050000004`.
7. The 60.0 overwrite at `0x14157e8a3`, and the single reader of the light bias field in the writer (`0x141568906`, `0x141568920`).
8. The cascade selection in the `0x282002` record: `cb2[2].y` for cascade 0 and `cb2[2].z` for cascades 1 and 2, and `cb2[2].z` for the cascade-1 sample inside the blend.
9. The record header bytes of the 21 group 7 records with key bit `0x200000`: byte 0 is 8, byte 8 is 12, byte 11 is 8 and byte 12 is 12 in every record. The writer reads `+0x4b` and `+0x4c` (`0x141566b2c`, `0x141566b34`), and the bias writer reads `+0x40` (`0x1415688b0`).
10. The interior distance. Exactly three references to `0x1420d9038`: `0x1414ebf0a`, `0x1414ebf49` and `0x14155c678`. The reads of the active distance and its square (11 read sites, grouped as in G6, besides the stores in the setters). The four direct callers of `0x14ebf00` and the flag byte at `0x1420d68f4` (three further readers).
11. The startup order. The store at `0x1414eaea7` and the single direct call of `0x1414ea2d0` at `0x140655b63`, after the `ShadowSceneNode::ctor` call at `0x140655b46`.
12. The #919 settings. The `bDisableShadowJumps` tests at `0x14157f323` and `0x1415817af`, the constructor read of `fSunUpdateThreshold` at `0x14157e559` (guarded by a negative cache, compiled -1.0), the only consumer of the cache at `0x1415817ed`, and the reads of the two other sun timing settings.
13. The byte `0x143436311`: nine reads, all compares, no store.
14. The example numbers were recomputed by script with the formula. The first example was also done by hand: `t0 = 1250 / 8000 = 0.15625`, `base_0 = 0.5 × (15 × (8000/15)^0.15625 + 15 + 7985 × 0.15625) = 651.3`. So cascade 0 ends at 751.3 and cascade 1 starts at 551.3.

Changes from the re-read. (a) The float32 value of the cascade 1 bias is `0.0050000004`, not `0.0049999999`. The draft had the wrong rounding. (b) The routine at `0x1414ea2d0` has a second reference: a tail jump from a small wrapper at `0x14eb110`. The wrapper has no direct call and no 8-byte data pointer. The reviewer wrote "only caller". G5 now states the wrapper and that a later second run is not excluded.

Source exposure of the review: pinned native binary, shipped INI files and shipped shader records. This is a static review. It is not match evidence for any function, and it does not decide transfer eligibility.

Reviewer and outcome: Reviewed independently by a Sonnet 5.5 run. Outcome: 7 confirmed, 2 corrected, 0 rejected. Static evidence only. Transfer status: UNREVIEWED.
