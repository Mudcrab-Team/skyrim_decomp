# Finding: grass generation, fade and shading constants

Status: OBSERVED (values and rules read in the pinned image, its shipped shaders and INIs, unless marked agent-reported); HYPOTHESIS where marked inferred. Function names are GUESS.
Author / human operator: eclepso
AI assistance / model: claude-opus-5-5 (analysis and fact-check); DeepSeek V4.1 Flash worker drafts, re-checked where marked verified
Date (UTC): 2026-11-20
Target build id / image SHA-256: `sse-steam-1-7-104` (hash pinned in `builds/target.json`)
Function RVA / size (if applicable): 0x209020 (2912), 0x2afb20 (2131), 0x208f60 (82), 0x1523440 (322); also cited: 0x2067f0, 0x206d40, 0xce4460, 0xce44e0, 0x1522870
Source exposure: mixed (binary-analysis of the pinned image; the shipped shader bytecode, INIs and Skyrim.esm; for comparison only, Mudcrab's grass code and its published audit of the MIT-licensed spud engine. No FNV or Fallout 4 sibling source was used.)
Sources and immutable revisions / licenses: the pinned image and the operator's own retail install; no third-party code reproduced
Name provenance: GUESS
Confidence: high where marked verified; medium where agent-reported; inferred items are stated as such

Addresses are VAs in the pinned image (base `0x140000000`). Values and rules only: no recovered
implementation or line-by-line translation is included. Intended reader: Mudcrab's grass labels
(Mudcrab-Team/mudcrab#824 and its retail-facts registry). Any transfer still needs the boundary
review in `docs/clean-room.md`.

Tags: **verified** = re-read by the operator at the source; **agent-reported** = from a worker draft
and not independently re-read.

## Question and method

Which grass constants and rules does the retail game use, so that a reimplementation can label each
of its own grass constants as retail or not? Method: static reading of the grass manager, per-cell
generator, per-layer instancer, layer record filler and grass shader setup in the pinned image;
reading the retail grass vertex and pixel shader bytecode; reading setting defaults and the shipped
INIs. Worker drafts were re-checked by the operator, and each item says which parts were re-read.

## Observations

### <a id="g01"></a>G01. Grass settings: compiled defaults and shipped values (verified)

| Setting | Compiled default | Shipped override | Effective |
|---|---|---|---|
| iMinGrassSize | 20 | none | 20 |
| fGrassStartFadeDistance | 7000 | presets Low 1000, Medium 2300, High 7000, Ultra 7000 | 7000 (High/Ultra) |
| fGrassFadeRange | 1000 | none | 1000 |
| iGrassCellRadius | 2 | none | 2 |
| fGrassMinStartFadeDistance | 400 | `Skyrim_Default.ini` 0 | 0 |
| fGrassMaxStartFadeDistance | 7000 | `Skyrim_Default.ini` 7000 | 7000 |
| fGrassWindMagnitudeMin / Max | 5 / 125 | none | 5 / 125 |
| fTexturePctThreshold | 0.0 | none | 0.0 |
| iMaxGrassTypesPerTexure | 2 | none | 2 |
| bDrawShaderGrass | 1 | none | 1 |
| bAllowCreateGrass | 1 | `Skyrim_Default.ini` 1 | 1 |
| bAllowLoadGrass | 0 | `Skyrim_Default.ini` 0 | 0 |
| bGenerateGrassDataFiles | 0 | none | 0 |
| bEnableGrassFade | 1 | none | 1 |
| fWindGrassMultiplier:Display | 1.0 | none | 1.0 |
| fShadowClampValue:Display | 0.3 | none | 0.3 |

Evidence: setting value fields `0x142079430` (iMinGrassSize), `0x1420793e8`, `0x142079400`,
`0x142079478`, `0x1420793b8`, `0x1420793d0`, `0x142079460`, `0x142079448`, `0x14207b8b0`,
`0x14207b898`, `0x1420793a0`, `0x1420794a8`, `0x1420794c0`, `0x142079490`, `0x1420794f0`,
`0x1420d6d30`, `0x1420d6d48`; shipped INI files of the pinned install.

### <a id="g02"></a>G02. Grass on/off gate (verified)

Grass is enabled only when `bDrawShaderGrass` is set and
`fGrassStartFadeDistance >= fGrassMinStartFadeDistance + 0.5`. The test is re-run when the setting
changes. Evidence: `0x14020693b`–`0x140206967`, repeated in `0x140208c20`–`0x140208c59`.

### <a id="g03"></a>G03. Fade end and effective fade start (verified)

`fadeEnd = fGrassStartFadeDistance + fGrassFadeRange`, clamped to `uGridsToLoad * 4096`
(20480 at uGridsToLoad 5, so the defaults are not clamped). The fade start handed to the grass
shaders is `min(fadeEnd, fGrassStartFadeDistance)`. Evidence: `0x140206a4e`–`0x140206a94`
(repeated in `0x140208c60`–`0x140208ca6`); shader fade-start writer `0x140208f60`.

### <a id="g04"></a>G04. iMinGrassSize is a raw divisor (verified)

iMinGrassSize is used directly as a divisor with no lower clamp (0 would divide by zero).
Evidence: `0x140206aa8`–`0x140206ab7`.

### <a id="g05"></a>G05. Candidate grid per 256-unit tile (verified)

Tiles are 256 units on a side. Candidates per axis:
`n = min(trunc(256 / positionRange), trunc(256 / iMinGrassSize))`; with the defaults (32, 20)
n = 8. The minimum uses an unsigned comparison of the two truncated values, which gives these edge
cases:
- positionRange = 0: 256/0 truncates to 0, so n = 0 and the grass type places nothing.
- positionRange < 0: the negative quotient compares as a huge unsigned value, so n is the
  iMinGrassSize cap (12 at the default 20).

Evidence: `0x1402090d4`–`0x14020910e`. The edge cases are read from the conversion and compare in
that range (medium-high: the semantics are inferred from the instruction behaviour).

### <a id="g06"></a>G06. Random source and per-cell seed (verified, partly agent-reported)

One process-wide Mersenne-Twister variant serves grass. Its twist mixes neighbours with a `% 624`
index (not the textbook split loop) and uses twist constant `0x9908B0DF` and the standard tempering
masks (verified). Initialisation multiplier 1812433253 and the first draw from word 623 are
agent-reported. Before generating a cell the generator is re-seeded with the 32-bit product of the
two cell coordinates (verified: product of the two values; that they are cell X and Y is
agent-reported). Draw scales: `r * 2^-31 - 1` for a signed unit, `r * 2^-33` for the colour factor,
and a 15-bit draw (0..32767) for acceptance. Evidence: draw `0x140ce44e0` (twist constant
`0x140ce45a1`, modulo `0x140ce455e`, `0x140ce4587`, `0x140ce45e6`, masks `0x140ce4600`,
`0x140ce460f`), seed `0x140ce4460`, re-seed `0x140206eb2`–`0x140206ec5`.

### <a id="g07"></a>G07. Sixteen grass slots per cell pass (verified)

The per-cell generator builds an array of 16 grass slots and passes 16 as the collector's maximum,
so at most 16 grass entries are generated per pass. Evidence: `0x140206e98`–`0x140206eb0`,
`0x140206fc4`–`0x140206fdc`.

### <a id="g08"></a>G08. Texture support test: nine samples and the 25/255 floor (verified)

Each layer is tested on nine samples of the 17×17 per-quadrant blend grid (stride 17, 289 per
layer): the centre and offsets −18, −17, −16, −1, +1, +16, +17, +18. A layer is skipped unless
at least one of the nine coverage bytes is greater than 25 (out of 255). Evidence: offsets
`0x1402afccc`–`0x1402afdda`, grid stride `0x1402afed1`, floor `0x1402afef2`–`0x1402affc2`.

### <a id="g09"></a>G09. fTexturePctThreshold handling (verified)

T is first clamped to `max(T, 0)`, and a value above 1 becomes 0.9. Each sample contributes only if
its percentage is greater than T; if the mean of the nine samples is below T the layer is dropped.
At the shipped T = 0 both tests pass for any non-zero coverage. Evidence: clamp
`0x1402afb4f`–`0x1402afb78` (0.9 at `0x141820e24`), mean-of-nine `0x1402afe0d`–`0x1402afe62`.

### <a id="g10"></a>G10. Density per corner (verified)

A corner's acceptance weight is `density * 0.01` when its coverage byte is greater than
`trunc(T * 255)`, else 0. Evidence: `0x1402b00e7`–`0x1402b0126` (0.01 at `0x141b5bdd0`, 255 at
`0x141b5bf6c`).

### <a id="g11"></a>G11. Per-candidate acceptance (verified)

`v = trunc(bilinear(corner weights) * 32768 * 1.0)` (the 1.0 is a field the caller hard-codes). If
v is 0 the candidate is rejected without drawing; otherwise it is accepted when a 15-bit draw
(0..32767) is less than v. Evidence: `0x140209332`–`0x140209363` (32768 at `0x1417ff7e0`).

### <a id="g12"></a>G12. Position jitter (verified)

Each accepted candidate draws x and then y offsets of `(r * 2^-31 - 1) * (spacing / 2)` around its
cell centre, where spacing = 256 / n. Evidence: half-spacing `0x1402091e1`–`0x1402091f3`, offsets
`0x140209393`–`0x1402093e8`.

### <a id="g13"></a>G13. Slope limits (verified index, agent-reported table content)

Minimum and maximum slope in degrees index a 512-entry table built at runtime:
`index = trunc(deg * 1.4222222) & 511` (512/360; values past 360 wrap). The surface normal's z is
accepted when `table[max] <= n.z <= table[min]`. The table is a cosine table (inferred from its use;
not read). Evidence: `0x140209141`–`0x14020918d` (1.4222222 at `0x1417ff7d4`), test
`0x1402096a3`–`0x1402096b6`.

### <a id="g14"></a>G14. Instance colour scale (verified)

`lum = 0.31 R + 0.37 G + 0.32 B` of the landscape colour at the sample (0..1);
`f = (r * 2^-33 - 0.25) * colorRange + (1 - colorRange)` with a full 32-bit draw r;
`x = lum * f`; if `x >= 1.0` the stored value is 0.99, otherwise `max(x, 0)`. Values in
[0.99, 1.0) are kept unchanged; this is not a [0, 0.99] clamp. Evidence: `0x1402096bd`–`0x140209739`
(0.31 `0x1417ff7c8`, 0.37 `0x1417ff7cc`, 0.32 `0x141b5be08`, 2^-33 `0x1417ff7c0`, 0.25 `0x141b5be00`,
0.99 `0x1417ff7d0`).

### <a id="g15"></a>G15. Water placement modes (verified bound)

The grass type's water mode selects one of six tests (0..5). A mode greater than 5 skips the water
test entirely and continues to the slope test, so it places grass without a water constraint.
Evidence: switch `0x14020951b`–`0x140209535`, out-of-range target `0x14020967f`. The meaning of each
of the six modes is agent-reported (band above, band below, inside, outside).

### <a id="g16"></a>G16. 960 instances per grass geometry (verified)

Before upload, each grass geometry's instance count is clamped to 960; the excess is not drawn (no
re-batching was seen, agent-reported). Evidence: `0x141522f1c`–`0x141522f29`,
`0x141523455`–`0x141523460`.

### <a id="g17"></a>G17. Grass shading: ambient factor 1.0 (verified)

Lit grass pixels compute
`rgb = (NdotL * C * sunColour * T * shadow + C * ambient * T) * outScale`, with
`shadow = mask + fShadowClampValue * (1 - mask)`. The ambient term has an implicit factor of 1.0 and
is not shadowed; no grass vertex or pixel shader contains 1/π. `outScale` is a per-pass constant
applied to the whole colour (exists: verified; value about 0.8333: agent-reported). Evidence: grass
PS bodies in the retail shader package (shaders011 PS 30–47), CPU constant setup `0x141522870`.

### <a id="g18"></a>G18. Distance fade (verified)

Per vertex: `fade = 1 - saturate((d - fadeStart) / fadeRange)`, where d is the length of the
clip-space position's xyz before the perspective divide. In the alpha-tested pixel shaders the fade
multiplies the texture alpha inside the alpha test (`tex.a * fade < cutoff` discards); it never
scales colour or output alpha. The opaque variants ignore it. Evidence: grass VS 00012 of the retail
shader package; PS 37–47.

### <a id="g19"></a>G19. Layout constants (mixed)

- 17×17 blend grid per layer, 289 samples (verified, stride above); 4096-unit cells (verified,
  constant used by the instancer `0x1417ff7dc`); 2048-unit quadrants of 8×8 tiles (agent-reported).
- Layers per quadrant: five weighted layers plus the base (agent-reported).
- iMaxGrassTypesPerTexure is applied after adding a type (agent-reported).
- Per-instance encoding: retail stores the rotation basis (from `s = r * 2^-31 - 1`,
  `c = +sqrt(1 - s^2)`) and a half-float scale offset `rand(-1, 1) * heightRange` used as
  `1 + v * expansion` in the vertex shader (agent-reported).

## Interpretation and alternatives

- The exact value and source of the per-pass output scale in G17.
- The base-layer residual arithmetic, if any.
- Which of the six water modes is which (G15).
- The slope table contents (G13) are inferred to be cosines from their use.

Synthetic cases that follow from the rules above:

- G05: positionRange 32, iMinGrassSize 20 → n = 8; positionRange 0 → no instances;
  positionRange −1 → n = 12.
- G09: fTexturePctThreshold 1.5 behaves as 0.9; −0.2 behaves as 0.
- G14: lum 1.0, colorRange 0, any draw → stored 0.99; x = 0.995 → stored 0.995.
- G15: water mode 6 places grass regardless of water height.
- No original-game captures are part of this specification.

## Reproduction and sanitized evidence

Generate local listings of the addresses above from your own copy of the pinned image and compare
the constants and control flow named in each item. Shader items: disassemble the retail grass
shaders from your own install. Keep listings in `.local/`.

## Negative results and limitations

- No original-game captures were made; every item is static.
- The slope table contents, the per-pass output scale value and the water-mode meanings are not
  read directly (see above).

## Reviewer and outcome

Not yet reviewed.
