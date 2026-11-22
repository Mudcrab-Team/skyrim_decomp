Transfer status: UNREVIEWED

# Finding: sun shadows and interior shadow-light admission in Skyrim Special Edition

Status: OBSERVED where verified. Static analysis and synthetic probes.

Author: MR-4, a `gpt-6.2-sol` run via Codex (not the reviewer below).  
Human operator: Taylor.  
AI assistance / model: `gpt-6.2-sol` via Codex.  
Date (UTC): 2026-11-21.  
Target build id: `sse-steam-1-7-104`. The measured image SHA-256 `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f` equals the pin in [builds/target.json](../builds/target.json).  
Principal function RVAs: `0x157f080` (directional cascade update), `0x15389b0` (local light selector), `0x1587bc0` and `0x1588590` (local light camera updates), `0xfd97a0` (room test).  
Source exposure: The author's and reviewer's static analyses used the operator's pinned retail image, shipped INIs, shader bytecode, and LOD mesh metadata. Both consulted the generated CrashLogger name tables at `3b2d3051afa64fd02862a831389cdef8d26b292b`. The review also exercised selected native routines with synthetic inputs.  
Intended recipient: Skyrim Research department lead for boundary review. The proposed downstream use is Mudcrab's retail-facts work. The maintainer's transfer decision is pending.

Name provenance: Names marked `CRASHLOGGER_PDB(59818@2026.10.24)` come from the generated tables. Settings and technique strings come from the retail inputs. Descriptive function labels are GUESS.

Evidence addresses are VAs in the pinned image, base `0x140000000`. **Verified** identifies facts re-read at the cited inputs. **Unverified** identifies missing evidence. Transfer remains subject to [docs/clean-room.md](../docs/clean-room.md).

## Question and method

How does the retail renderer set up, fade, and consume exterior sun shadows? What does it establish about object and terrain LOD shadows? Which local light can receive a shadow map in an interior?

The evidence comes from native setting reads and render paths, five shipped INIs, pixel shader records, and the shipped LOD property census. Synthetic probes cover selected calculations and admission decisions.

## Observations

### 1. Cascade count, settings and map size

**Verified.** The sun setup and the depth-target setup read `iNumSplits`. Depth targets 2 and 3 have that many square array slices. The primary edge is `iShadowMapResolution`. The secondary edge uses integer division of the primary edge by eight. The directional render path includes a secondary-target branch for `iEnableShadowCastingFlag = 2`. Evidence at `0x14150bd6c`, `0x14155c650–0x14155c656`, `0x14153bfe8–0x14153c05c`, and `0x14157ebc9–0x14157ec83`.

**Verified.** The compiled count is two. The compiled resolution gives 2048 × 2048 primary slices and 256 × 256 secondary slices. Low, Medium, High, and Ultra give secondary edges of 128, 256, 256, and 512 pixels. A dash means the inspected INI file has no entry for that setting.

| Setting | Compiled default and value field | Skyrim_Default.ini | Low / Medium / High / Ultra |
|---|---|---|---|
| `iNumSplits` | 2, `0x1420d9050` | — | — |
| `fShadowDistance` | 8000, `0x1420d9458` | — | 3000 / 3000 / 8000 / 10000 |
| `fInteriorShadowDistance` | 3000, `0x1420d9038` | — | — |
| `fFirstSliceDistance` | 1250, `0x1420d9470` | 2000.0000 | — |
| `fSplitOverlap` | 100, `0x1420d94e8` | — | — |
| `iShadowMapResolution` | 2048, `0x1420d9008` | — | 1024 / 2048 / 2048 / 4096 |
| `fShadowBiasScale` | 1, `0x1420d9080` | — | — |
| `fShadowDirectionalBiasScale` | 0.300000012, `0x1420d9518` | — | — |
| `iEnableShadowCastingFlag` | 2, `0x1420d6d00` | — | — |
| `iNumFocusShadow` | 4, `0x1420d9068` | — | 1 / 2 / 4 / 4 |
| `fMaxFocusShadowMapDistance` | 450, `0x1420d9198` | — | — |
| `ffocusShadowMapDoubleEveryXUnit` | 450, `0x1420d9020` | — | — |
| `fSunShadowUpdateTime` | 1, `0x1420d94a0` | — | — |
| `bDirShadowMapFullViewPort` | 1, `0x1420d94d0` | — | — |
| `bDisableShadowJumps` | 1, `0x1420d9500` | — | — |
| `iShadowMapResolutionPrimary` | Unverified | 2048 | — |
| `fShadowLODMaxStartFade` | Unverified | 1000.0 | — |

**Verified.** The base shadow-light constructor copies `fShadowBiasScale` to a light field. The directional constructor writes 60.0 to the same field. A conditional shader-constant path reads `fShadowDirectionalBiasScale`. Evidence at `0x14155c56a`, `0x14157e8a3`, and `0x1415688f4`. The directional update reads `bDirShadowMapFullViewPort` at `0x141580eea`. The directional update and its timing helper read `bDisableShadowJumps` at `0x14157f323` and `0x1415817af`. The timing helper reads `fSunShadowUpdateTime` at `0x1415818e2`.

**Confidence: high** for compiled and shipped values and the descriptor math. Effective user settings, arbitrary cascade-count overrides, the full bias chain, and actual draws remain **unverified**.

### 2. Split calculation and far fade

**Verified.** The active range is `fShadowDistance` for exterior and `fInteriorShadowDistance` for interior. The range setter stores both the distance and its square. The split fraction separately uses exterior `fShadowDistance`, including when the active range differs. Distances, endpoints, and overlap use game world units. The squared range uses game units squared. These paths use no cell-size conversion. Evidence at `0x1414ebf00–0x1414ebf6f` and `0x14157ff1c–0x14157ffb5`.

**Verified.** For the traced positive cascade counts and finite positive distances, let `D` be exterior distance and `A` be active distance. Let `N` be the directional object's stored cascade count, `n` be the camera near distance, `F = min(A, cameraFar)`, and `O = fSplitOverlap`.

```text
t0 = min(D/N, max(fFirstSliceDistance, 500)) / D
t_i = t0 + (1 - t0) * i / (N - 1), for N >= 2 and 0 <= i < N
E_i = 0.5 * (n * pow(F/n, t_i) + n + (F - n) * t_i) + O
first near endpoint = n
next near endpoint = E_i - 2 * O
```

For a single cascade, the fraction is `t0`. For two or more, the last far endpoint is `F + O`, subject to float32 rounding. With the base INI first-slice setting and the four exterior distance presets, the first fractions are 0.5, 0.5, 0.25, and 0.20. Evidence at `0x14157f108–0x14157f145`, `0x14157f7a6–0x14157f7db`, `0x14157ff1c–0x14158008e`, and `0x141581657–0x141581678`.

**Verified.** Five directional mask pixel shaders reconstruct the position from screen coordinates and depth. They divide by W after applying the inverse camera-relative view-projection matrix from pixel constant buffer 12, rows 32–35. The vector's origin is the render camera used to build that buffer. Its length `r` is in game world units. The renderer builds the matrix without absolute camera translation and stores the translation separately. Evidence at `0x14101d400`, `0x14101e4e0–0x14101e7cf`, `0x14101e7f0–0x14101ec1b`, `0x14100b18d–0x14100b1d8`, `0x14100b408–0x14100b50d`, and `0x14101080d–0x141010825`.

**Verified.** For positive squared range `B`, the radial shadow strength is `1 - saturate(r²/B)^8`. The shader uses this strength to blend the sampled shadow attenuation toward fully lit. At `r = 0` the strength is one. At and beyond `sqrt(B)` it is zero. A separate projected-depth test includes equality in the in-range branch. Beyond the last projected split, surviving pixels take the fully lit value. These shaders can also discard pixels. Evidence from group 7 pixel keys `0x202002`, `0x202102`, `0x242002`, `0x282002`, and `0x302002`.

**Verified.** The writer supplies `B = A²` with the light fade flag set and `B = 100000000` with it clear. The latter yields a 10000-unit radial limit. The directional constructor chain initializes the flag to one. Evidence at `0x1415676c8–0x1415676f6` and `0x141575a3f`.

**Confidence: high** for the formulas, units, matrix origin, and tested shader comparisons. The effective camera, later fade-flag changes, and visible fade under a particular scene state remain **unverified**.

### 3. Shadow map and mask consumers

**Verified.** The directional mask pass writes color target 18. The generated name is `kSHADOW_MASK`, `CRASHLOGGER_PDB(59818@2026.10.24)`. The five directional variants in §2 sample a cascade array at `t3` or `t4`. Key `0x202102` also samples `t6` through its focus branch. The matching CPU binding supplies the depth resource view for depth target 4. Evidence at `0x141539a70`, `0x14153c07a`, `0x14100a980–0x14100ab55`, and `0x1415680de–0x141568176`.

**Verified.** Grass setup binds the mask at `t1`. Group 2 pixel keys `0x2`, `0x3`, and `0x6` load it. Lighting setup binds the mask at `t14` when technique bit 14 is set and bit 13 or any bit in `0x1c0` is set. Group 6 feature 0 samples it in keys `0x6001`, `0x6005`, `0x6007`, `0x6201`, `0x6205`, `0x6207`, `0x6401`, and `0x6405`. Evidence at `0x141522686`, `0x1415486c4–0x141548701`, and the listed shader records.

**Verified.** Two image-space paths bind the mask at `t7` and `t5`, at `0x1415413ee` and `0x141542abe`. The grass, lighting, and two image-space bindings account for the four direct references found to the mask texture field at `0x143332d10`.

**Confidence: high** for the listed bindings and shader samples. The active shader samples in the two image-space paths, indirect mask consumers, and the draw sequence in a live scene remain **unverified**.

### 4. Object and terrain LOD

**Verified.** The shipped `Skyrim - Meshes1.bsa` contains 2392 lighting properties across 1078 object LOD meshes and 9584 across 9584 terrain LOD meshes. Their serialized low flag words are `0x80400000` and `0x80401000`, respectively. Both clear bit 8 and bit 9, named `kReceiveShadows` and `kCastShadows` in `CRASHLOGGER_PDB(59818@2026.10.24)`. The native loader requests eight bytes at the property flag field. Evidence at `0x141518860` and `0x1414e7390–0x1414e73df`.

**Verified.** The 24 group 6 pixel permutations for features 9, 13, 15, and 18 omit `t14`. The respective counts are 2, 10, 10, and 2. The pinned image's technique strings are `LODLANDSCAPE`, `LODOBJECTS`, `LODOBJECTSHD`, and `LODLANDNOISE`. The feature 0 readers in §3 are positive controls. Evidence from the shader records, technique table `0x141589648`, and strings at `0x141b4f828`, `0x141b4f848`, `0x141b4f858`, and `0x141b4f838`.

**Verified.** `bLodZPrepass` compiles to 1 at `0x1420d6cb8`. Clearing it suppresses mode-12 pass generation when property bit 33 is set. All inspected terrain LOD properties serialize bit 33 as set. In modes other than 12, setting `iEnableShadowCastingFlag = 1` rejects a clear cast bit on the traced path. At setting 2, mode 14 can reach further pass tests with the cast bit clear when the directional accumulator sets its pass byte. Evidence at `0x14151b42f–0x14151b553` and `0x14157eb60`.

**Verified.** `bDrawLandShadows` compiles to 0 at `0x14207b840`. Full-cell land creation uses it to set cast bit 9 at `0x1402b3625–0x1402b3635`. The terrain LOD block settings are separate from the directional split inputs. The terrain state loader reads `fSplitDistanceMult` at `0x140519af8`.

| Terrain setting | Compiled default and value field | Low / Medium / High / Ultra |
|---|---|---|
| `fBlockLevel0Distance` | 35000, `0x1420b33f0` | 15000 / 20000 / 35000 / 60000 |
| `fBlockLevel1Distance` | 70000, `0x1420b3408` | 25000 / 32000 / 70000 / 90000 |
| `fBlockMaximumDistance` | 250000, `0x1420b3420` | 100000 / 100000 / 250000 / 250000 |
| `fSplitDistanceMult` | 1.5, `0x1420b33d8` | 0.5 / 1.1 / 1.5 / 1.5 |

**Confidence: high** for serialized flags, tested main lighting permutations, and the stated pass gates. Actual LOD caster-list membership, flag changes before enqueue, other receiver paths, and a dedicated LOD shadow cutoff remain **unverified**.

### 5. Interior local shadow-light admission

**Verified.** The ordinary light-form path requests a shadow light if any bit in `0x1c00` is set. The generated names are `kSpotShadow` (`0x400`), `kHemiShadow` (`0x800`), and `kOmniShadow` (`0x1000`), `CRASHLOGGER_PDB(59818@2026.10.24)`. Bit `0x200` alone leaves the shadow request clear. Spot takes precedence and supplies the effective field of view in radians. Otherwise hemi supplies π when set, or omni supplies 2π. For finite angles, the factory uses float32 boundaries. It selects a frustum below π, one-sided parabolic at or above π and below 2π, and two-sided parabolic at or above 2π. Registration checks the constructed object's shadow-type virtual. Evidence at `0x14027482a–0x1402748c0`, `0x1402fff70`, `0x14150c8aa–0x14150c96b`, and `0x14150cc4f–0x14150cc56`.

**Verified.** The selector uses the current render scene's camera and scans the active shadow-light array in ascending index order. The generated array name is `ShadowSceneNode.activeShadowLights`, `CRASHLOGGER_PDB(59818@2026.10.24)`. The directional branch reserves slot zero when the runtime byte at `0x143436311` is zero. Reservation still occurs if directional accumulation returns false. Room remains for three local lights after reservation, or four when that branch is disabled. Evidence at `0x1415389b0–0x141538a60`, `0x14150f8b0`, and `0x141538b20–0x141538b39`.

**Verified.** The ordinary selector applies these gates in order.

1. The array entry exists and the current slot count is below four.
2. The light's camera update succeeds. The ordinary frustum and parabolic updates first reject scene-object flag mask `0x1`. The frustum path then applies its intersection test to the view and light-camera frusta. The parabolic path tests a light sphere against the active view-frustum planes. That sphere test rejects exterior tangency as well as separation at any active plane.
3. Within that camera update, a set light fade flag requires the finite value `(distance² - radiusX²) * lodAdjust` to be strictly below `activeShadowDistance²`. The distance is between the light and render camera. The radius is the light radius's X component. Both are in game world units. The camera multiplier is dimensionless. Equality fails. Clearing the fade flag bypasses the distance test while retaining the visibility gate. The compiled interior range of 3000 gives a squared threshold of 9000000.
4. The light has a context owner and the owner has a portal entry. The view and light portal entries must both mark unbound space visible or contain equal stored room pointers.

Evidence at `0x141538b20–0x141538b96`, `0x141587bc0–0x141587ed2`, `0x141577a10–0x14157858a`, `0x141588590–0x1415888a6`, `0x140fe5770–0x140fe57ff`, and `0x140fd97a0–0x140fd988e`. Generated field names for the fade flag, radius, and camera factor are `BSLight.lodFade`, `NiLight.radius`, and `NiCamera.lodAdjust`, `CRASHLOGGER_PDB(59818@2026.10.24)`.

**Verified.** Each passing entry proceeds to accumulation and consumes one slot. A failed gate leaves the slot free for a later entry. Array index decides priority among eligible entries. The selector applies no brightness sort, distance sort, minimum caster count, minimum map resolution, or separate player-distance gate to ordinary admission. Evidence at `0x141538b20–0x141538b96`, `0x141538be3–0x141538c19`, and `0x141538e35–0x141538ea1`.

**Verified.** Focus has a separate occupied state. The directional path can occupy it when both controls at `0x1420d6810` and `0x1433d3e90` are nonzero. With those controls and focus free, a prepass can preserve the previous focus entry if it is still in the array. After a local entry passes ordinary gates, a set focus flag selects focus setup. For an unflagged entry, that branch requires focus to be free and the type predicate to pass. The ordinary frustum passes that predicate. The ordinary parabolic light can still take an ordinary slot. Evidence at `0x1415389c9–0x1415389f7`, `0x141538a28–0x141538ac1`, `0x141538b9c–0x141538be3`, and the virtuals at `0x141587f70` and `0x14155d960`. The focus settings have separate readers at `0x1414eaab4–0x1414eaaba`, `0x14065a4d7–0x14065a542`, and `0x14155cd49`.

**Verified.** The render iterator dispatches accumulated lights through their render virtuals. The frustum dispatch submits its ordinary map descriptor. The parabolic dispatch iterates the initialized hemisphere descriptors. Descriptor count and the four-light budget are separate. Evidence at `0x141538f00–0x141538f80`, `0x141587a30–0x141587a46`, and `0x141588c80–0x141588d35`.

**Confidence: high** for the traced admission order, form/type gates, strict range boundary, and slot budget. An actual interior selection depends on the live array and its order, the directional reservation state, camera and light geometry, the fade flag, and portal visibility. The directional byte's writer, other light producers, exact contact behavior of the frustum intersection test across every camera mode, and upstream array ordering remain **unverified**. Live focus decisions, caster lists, executed draws, and visible effects also remain **unverified**.

## Interpretation and alternatives

**Verified.** The first-slice setting controls a blend fraction. The actual cascade endpoint also depends on the camera range and overlap. Camera-relative radial fade and projected depth apply separate tests.

**Verified.** The serialized LOD flags and tested pixel shaders establish two specific exclusions. The directional pass still has a conditional route for a clear cast bit. Several eligible interior lights can reach map work in the same invocation.

## Negative results and limitations

**Verified.** Case-insensitive ASCII and UTF-16LE searches found zero occurrences of `iShadowMapResolutionPrimary`, `fShadowLODMaxStartFade`, and `bDrawShadows` in the pinned image. The base INI contains the first two strings. Use through another path is **unverified**. The evidence covers static paths and isolated synthetic probes.

## Independent review (2026-11-21)

Reviewer: GPT 6.2 Sol (`gpt-6.2-sol`) through Codex, high effort, fresh context, separate run. The reviewer did not author or draft this finding. The review was arranged by the skyrim-research department lead (Claude Sonnet 5.5), which also did not draft the finding. Date: 2026-11-21.  
Source reviewed: the draft of this finding (SHA-256 `b5ecd2799481cf4b21a306e1854e1bb729e908069ec3ae403cbf62770c098e0c`), against the pinned image `sse-steam-1-7-104` (measured SHA-256 equals the pin in [builds/target.json](../builds/target.json)), the five shipped INIs, the shader records, the LOD mesh metadata, and the generated CrashLogger metadata at `3b2d3051afa64fd02862a831389cdef8d26b292b`. Exposure of the review: mixed (retail executable, shipped INIs, shader bytecode, LOD mesh metadata, generated metadata, the draft, and isolated synthetic native probes). The reviewer saved independent conclusions for all five groups before reading the author's handoff. This is a static finding review with synthetic probes. It is not match evidence for any function. It does not decide transfer eligibility (`docs/clean-room.md`).

The observations above already include the corrected text.

| Group | Verdict | One-line status |
|---|---|---|
| 1. Cascade count and resolution | Confirmed | Two compiled cascades with 2048 × 2048 primary and 256 × 256 secondary slices. Shipped INIs override the first-slice distance and several preset values. |
| 2. Splits and far fade | Corrected | Split and fade formulas hold. The radial origin is the render camera. The projected split test includes equality on the sampling side. |
| 3. Mask consumers | Confirmed | Grass samples `t1` and tested lighting shaders sample `t14`. Two image-space paths bind the mask. The focus shader also reads depth target 4. |
| 4. Object and terrain LOD | Confirmed | Both shipped mesh classes clear serialized cast and receive bits. All 24 tested lighting permutations omit `t14`. Caster membership and other receiver paths remain unverified. |
| 5. Interior admission | Corrected | The ordinary selector admits the first eligible entries after camera, range, and portal checks. It has four local slots, or three after directional reservation. Focus has separate state. |

Summary: 3 groups confirmed, 2 corrected, 0 rejected.

## Reviewer and outcome

Reviewed independently on 2026-11-21 by GPT 6.2 Sol (Codex, high effort, fresh context), separate from author MR-4. Outcome: 3 confirmed (groups 1, 3, 4), 2 corrected (groups 2, 5), 0 rejected. Static and synthetic evidence only. A review verdict is not match evidence, and transfer eligibility is not decided. Unverified: actual interior light selections and draws, including upstream array order and the directional reservation byte's writer; caster-list membership and other LOD receiver paths; a dedicated LOD shadow cutoff; the shader consumers of the two image-space mask paths; the effective camera and later fade-flag changes behind the radial fade, and the visible fade in a scene.
