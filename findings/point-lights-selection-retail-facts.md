Transfer status: UNREVIEWED

# Finding: which point lights a geometry receives, light flicker and pulse, and the distance dimmer

## Answer

| Question | Answer |
|---|---|
| (1) Which up to 7 point lights does one geometry receive? | **Verified for the list consumer, mixed for the list builders.** The pass takes the geometry's shader-property light list in array order and keeps the first entries. The list is [sun] + [shadow-slot lights] + [ordinary lights in list order]. The selector skips entries with the frustum/fade state `0xff` or NiLight flag bit 0 set. The cut is at capacity 16 for the whole list and at 7 for points: points = min(total − 1, 7). The writer reads array entries 1..points. **There is no nearest-first or brightest-first sort at the cut.** Attach order decides the list order. Light-centric attach appends a new light to the end of each affected geometry's list. Geometry-centric attach (queued objects) rebuilds the list in visiting order. Small queued nodes (bound radius below 150) visit candidates sorted by (distance to bound centre − bound radius) / light radius, **largest first**. Geometry, and nodes with bound radius 150 or more, visit lights without sorting. The candidate array is the light array of the immediate parent when that parent is a `BSMultiBoundRoom` (`+0x180`, count `+0x190`) or a `BSPortalSharedNode` (`+0x128`, count `+0x138`). Otherwise it is the scene's active ordinary-light array (`+0x130`, count `+0x140`) in the order lights were queued. Shadow lights come before ordinary lights and use the same slots. Candidates need a bound/light-sphere overlap, `IsValidLight`, and (in the registered-object path with the list-`+0x1e0` flag) no stale `0xff` state. Interior and exterior cells use the same code. See G01–G05. |
| (2) Flicker and pulse | **Verified.** LIGH DATA flags: bit 3 (`0x8`) Flicker, bit 6 (`0x40`) Flicker Slow, bit 7 (`0x80`) Pulse, bit 8 (`0x100`) Pulse Slow. The registration test is `flags & 0x1c8`. The per-frame modulation tests only bit 3 and bits 7/8. It changes NiLight **fade** (+0x134) and the NiLight **local translate** (+0x6c..0x74). It does not change radius or diffuse. Pulse: `fade = base × (1 − I + I·cos P)` with `I = 0.5 × intensityAmp` and `P` advancing by `dt × period`. Flicker: `fade = base × (1 − I + I·n)` with `n` from three random-rate phases and a 512-entry sine table, n in [−0.2, 0.5333]. Update runs only for lights within `fFlickeringLightDistance` (1024) of the player. See G06–G09. |
| (3) Distance dimmer (`BSLight.lodDimmer`, wrapper +0x14) | **Verified.** For each light with `lodFade` set and inside the camera frustum: `q = d² − R²` (d = camera to light centre, R = NiLight radius). `q < begin²` gives dimmer 1. `end² == 0` gives 1. `q > end²` gives 0 and the light is flagged culled (`0xff`) and skipped by the selector. Otherwise `dimmer = 1 − (q − begin²) / (end² − begin²)`. Begin and end come from `Sky::UpdateLightLODFadeDistances` and the Sky mode: room lighting template, else interior cell fade begin/end (or its template), else the exterior lighting override, else `fLightLODStartFade` and `fLightLODStartFade + fLightLODRange`. An interior cell that carries lighting data does not keep a stored fade pair of exactly 0.0: the cell initialiser replaces a zero begin with `fLightLODStartFade` and a zero end with `fLightLODRange + fLightLODStartFade` (see G11). With the shipped `Skyrim_Default.ini` value of 3500 and the compiled range of 500, begin is 3500 and end is 4000. The dimmer is 1 for every light only when the cell has no lighting data (begin² and end² are both 0). An ordinary exterior also uses begin 3500 and end 4000 with the shipped INI and the compiled range. Static only. See G10–G11. |

| Item | Evidence record |
|---|---|
| Status | OBSERVED for verified claims. Inferred and unverified claims are marked. Static only. No runtime capture. |
| Author / human operator | A Sonnet 5.5 research run (`claude-sonnet-5-5`) for the department operator. A third Sonnet 5.5 run applied the review corrections. |
| Reviewer | A separate fresh-context Sonnet 5.5 run (`claude-sonnet-5-5`). Sol was unavailable on usage limits. See "Independent review" below. |
| Date | 2026-11-24 CST. The author run and the independent review ran between 02:14 and 02:54 CST. The corrections were applied afterwards. |
| Build | `sse-steam-1-7-104`, retail `1.7.104.0`, Steam build 24914197. Measured executable SHA-256 `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f` equals the asserted pin in [builds/target.json](../builds/target.json). |
| Principal function RVAs | `0x1569550` (pass light list selector), `0x151a160` (pass builder), `0x15690f0` (list add), `0x1569460` and `0x1569470` (list fence push and pop), `0x15765d0` (attach geometry), `0x150ee90` (per-geometry attach), `0x150ed00` (node walk), `0x150e860` (node candidate collection and sort), `0x1577060` (sort key), `0x150f0c0` (apply sorted list), `0x150d410` (queued-light and queued-object processing), `0x150e400` (enable light), `0x1513290` and `0x1576490` (light-centric attach), `0x15768e0` (sphere test), `0x14e8350` (light validity), `0x154bb90` (point values), `0x1575d20` (dimmer and frustum state), `0x416240` and `0x412df0` (fade distances), `0x2b8ed0` (cell initialiser), `0x274bc0` (flicker and pulse), `0x2b9750` (cell flicker pass). Function labels are GUESS unless a CrashLogger name is given. |
| Sources and revisions | Pinned executable. The shipped `Skyrim_Default.ini` text. Published cross-check: #1003 (merged at `14d2b01797`), read from `origin/main`. Related findings #806, #812, #946 and #1061 are listed under "Relation to earlier findings". |
| Source exposure | Pinned native binary analysis and shipped INI text. Public generated layouts and names. No downstream or sibling implementation source. This finding publishes no plugin values. No decompiler text or disassembly appears here. |
| Name provenance | Names marked `CRASHLOGGER_PDB(59818@2026.10.24)` come from the committed generated tables (`names/`, `types/`). They include `BSLight` fields (`lodDimmer`, `frustrumCull`, `lodFade`, `dynamic`, `pointLight`, `portalStrict`, `affectLand`), `NiLight.fade`, `Sky.extLightingOverride`, `Sky::Mode`, `INTERIOR_DATA.lightFadeStart` and `lightFadeEnd`, `TESObjectLIGH::Data` fields and the function names `ShadowSceneNode::ProcessQueuedLights`, `ShadowSceneNode::EnableLight`, `BSFadeNode::CullRoomLights`, `BSGeometry::AttachNearbyLights`, `BSLight::AttachGeometry`, `BSLight::IsInRange`, `BSLight::UpdateLODFadeAndCull`, `BSShaderPropertyLightData::AddLight`, `Sky::UpdateLightLODFadeDistances`, `BSLightingShader::GeometrySetupConstantPointLights`. The class names `BSMultiBoundRoom` and `BSPortalSharedNode`, and the settings names, come from strings in the pinned image. Descriptive labels beyond those are GUESS. A PDB field name is not evidence of what the binary stores: see G13. |
| Intended recipient | Skyrim Research department lead for boundary review under [docs/clean-room.md](../docs/clean-room.md). Proposed use is Mudcrab issue #955, item 20. Maintainer transfer decision is pending. |

Addresses are RVAs for image base `0x140000000`. `d` is Euclidean distance. `R` is `NiLight.radius.x` (+0x128) in world units. `dt` is the frame-time float at `0x3275608` (see G08). **Verified** means re-read at the cited static source. **Inferred** means a deduction with assumptions. **Unverified** means the evidence leaves the claim open. The document contains facts and formulas only.

## Question and method

Mudcrab issue #955 (item 20) lights each placed light with traced retail equations (colour × fade × dimmer, and the attenuation `1 − saturate(d/r)²` of #1003 G04 and G05). Three retail inputs were untraced: the 7-light selection per geometry, the flicker and pulse modulation, and the distance dimmer. This work reads the pinned image statically. It starts from the #1003 G04 anchors (selector `0x1569550`, capacity 16, point count cap 7, shadow count cap 4, `0x15690f0`, `0x150e400`, `0x1513290`, `0x150d6a0`) and extends them to ordinary near geometry. It follows the writers and readers of the geometry light list, the writer of wrapper `+0x14`, the Sky function that supplies the fade distances, the cell initialiser that stores the fade pair, and the LIGH flicker code. The method is a static disassembly listing of the pinned image (private, not published), small slice reads and PE data reads. Nothing was run in the game.

## Observations

### G01. The pass selector, the list order and the cut at 7

**Verified.** The Lighting pass builder at `0x151a160` calls the selector at `0x1569550` once per pass with output capacity 16 (call at `0x151a88c`, capacity argument set at `0x151a87e`). The selector's input is the property's light list at `[property + 0x70]` (CrashLogger name `BSShaderPropertyLightData`). That list has the array pointer at `+0x0`, count at `+0x10`, an insertion fence at `+0x18` (default `0xffffffff`), an active shadow-slot mask at `+0x1c` and a dirty byte at `+0x20`. Evidence at `0x1569550–0x1569744`, `0x15690f0–0x1569251`, `0x1569460–0x1569548`.

**Verified.** The output array is built in this order. Entry 0 is the scene sun (`scene +0x200`), or `+0x210` when the context byte is set, or `+0x208` (cloud light) when property flag bit 52 is set (`0x1569583–0x15695b9`). Entries from index 1 are the shadow-slot lights, only when the shadow-scan argument is set. Each shadow slot `i` below the limit (8, plus the sun entry's `+0x140` value when the context byte is set) is tested against the list mask at `+0x1c` (or against a first-person mask argument). The light comes from `ShadowSceneNode::GetShadowCasterLightArrayEntry` (`0x150fee0`, call at `0x156964a`). It is rejected when null, equal to the previous entry, or rejected by `IsValidLight` (`0x14e8350`, call at `0x156967a`). Each accepted shadow light increments the shadow counter (`0x1569694–0x15696a1`). After the shadow scan, a compaction pass at `0x1569780` removes null or NiLight-less entries from the property list (call at `0x15696e3`). Then every property-list entry is scanned in array order from index 0 (`0x1569700–0x1569737`).

**Verified.** An ordinary entry is skipped when `BSLight.frustrumCull` (wrapper `+0x5c`) equals `0xff` (`0x1569713–0x156971a`) or when its NiLight flag word has bit 0 set (`0x156971c–0x1569727`). Any other entry is appended. The scan stops when the output index reaches the capacity (`0x1569700–0x1569703`). Evidence for the capacity test in the shadow scan: `0x1569620–0x1569623`. Shadow lights and ordinary lights therefore share the 16 slots. The selector reads no distance, radius, colour or luminance value. It also does not test `NiLight.fade`.

**Verified.** The pass builder derives the key bits from the returned total `T` (including the sun). The point count is `min(T − 1, 7)`. The shadow count is `min(shadowCount, 4)` (`0x151a932–0x151a954`). The upload extracts the point count `(key >> 3) & 7` and shadow count `(key >> 6) & 7` (`0x1549fa0–0x1549fbf`) and passes the point count to `BSLightingShader::GeometrySetupConstantPointLights` (`0x154bb90`, call at `0x154a080`). The writer reads output entries starting at index 1 (byte offset 8 at `0x154bc01`) and writes `count` entries in order. The first `shadowCount` of them receive the shadow-slot index from wrapper `+0x520` (`0x154bda1–0x154bdb0`). Shadow-slot lights therefore occupy point slots 1..s before any ordinary light. If more than 7 qualified, entries from index 8 are not uploaded.

**Confidence: high.** The consumer is fully traced. **What would change it:** a different stage key or pass that calls the selector with another capacity (callers at `0x1529f58` and `0x152cc4c` serve other shaders and were not traced), or a second writer that reorders the output. Static only.

### G02. How a light enters a geometry's list, and the resulting order

**Verified.** All additions go through `BSLight::AttachGeometry` (`0x15765d0`). It needs a non-null shader property on the geometry (`[geometry + 0x128]`) whose light list pointer (`+0x70`) is non-null, and a true result from `IsValidLight` (`0x14e8350`, call at `0x15765d0+0x7e`). It has **no distance or sphere test of its own**. It records the geometry in the light's own geometry list and calls `BSShaderPropertyLightData::AddLight` (`0x15690f0`, calls at `0x1576699` and `0x1576762`). Evidence at `0x15765d0–0x1576767`.

**Verified.** `AddLight` has two behaviours. With the fence at `0xffffffff` it appends the light at the end of the array when it is not already present, and does nothing when it is. With the fence set it removes an existing copy and inserts the light at the fence index, then increments the fence. A new light then sits at the fence index, so lights added in one fenced pass keep their call order and precede everything older. `PushLightListFence` (`0x1569460`) sets the fence to 0. `PopLightListFence` (`0x1569470`) walks entries from the end down to the fence and removes each whose wrapper byte `+0x46` (`dynamic`) is 0, also dropping the geometry from that light's geometry list (`0x1569cc0`). Entries with `dynamic != 0` stay after the new ones. The pop then sets the fence back to `0xffffffff`. The push has three callers (`0x150eed3`, `0x150f1fb`, `0x150f2da`). All three are geometry-centric. Evidence at `0x15690f0–0x1569251`, `0x1569460–0x1569548`.

**Verified.** There are two attach families.

- **Light-centric** (no fence): `ShadowSceneNode::EnableLight` (`0x150e400`) dispatches an ordinary light to `0x1513290`. That builds or refreshes a culling process around the light position with radius `NiLight.radius.x` (`0x1513350–0x1513450`, class name `BSParabolicCullingProcess`, `UpdateLightPlanes` at `0x1586c90`). It then traverses the scene and calls `AttachGeometry` for each geometry that passes the culling test against its bound (`0x1576490–0x157657d`, test through virtual `+0xe0`). New attaches append at the end of each affected list. `ProcessQueuedLights` (`0x150d410`) calls `EnableLight` for queued new lights and for queued updates (`0x150d57d`, `0x150d5da`). Each frame it also calls it for every active ordinary light whose wrapper has `dynamic` (+0x46) and `pointLight` (+0x44) set, whose NiLight flag bit 0 is clear and whose `frustrumCull` is not `0xff` (`0x150da63–0x150daf2`), unless scene byte `+0x219` is nonzero. In the ShadowSceneNode range `0x150ba50–0x1514280` that byte is written only in the constructor (to 0). Whether other code writes it is not traced.
- **Geometry-centric** (fenced): objects registered by `0x150e780` into the scene arrays at `+0x1e0` and `+0x1c8` are processed in `ProcessQueuedLights` (`0x150d6a0–0x150d813`). The arrays are cleared at the end of the same function (`0x150d95e–0x150d9e8`), so each registration is processed once. A registered object that is a node with bound radius below the constant at `0x1b5bf34` (150.0) goes to `BSFadeNode::CullRoomLights` (`0x150e860`, call at `0x150d6df` and `0x150d7a0`). Any other object goes to `BSGeometry::AttachNearbyLights` (`0x150ee90`, geometry) or to the node walk `0x150ed00`.

**Verified.** The registration function `0x150e780` has 20 direct references across the image: 19 calls and one tail jump (`0x14ec089`). They are in functions that carry no CrashLogger name. Which game events register an object was not resolved.

**Inferred.** For a placed object loaded after the cell's lights exist, the geometry-centric path builds its first list. For a dynamic point light, the light-centric path then re-attaches it every frame, but `AddLight` skips lights already present, so the stored order stays. A light that is removed and attached again goes to the end. The order of a given geometry's list therefore depends on load and attach history. A fixed rule such as "nearest first" is not what the lists encode.

**Confidence: high** that the list order is attach order, as stated. **Medium** for which family builds the list for a given placed object. **What would change it:** a trace of the registration callers, or a runtime dump of one geometry's list across a cell load.

### G03. Candidate admission rules

A light is attached when the conditions of the path that attaches it hold. Items 2 and 3 apply to both families. Item 1 applies to the light-centric family.

**Verified.**

1. Light-centric path only. `EnableLight` (`0x150e400`) detaches the light (`0x1576870`, which removes it from every geometry list and clears the light's geometry list) when the NiLight flag word (`+0xf4`) has bit 0 set, or when `NiLight.fade` (`+0x134`) is below 0.05 (constant `0x1417ed69c`). Otherwise it attaches (`0x150e433–0x150e453`, detach jump target `0x150e4dc`). The geometry-centric collectors (`0x150e860`, `0x150ee90`, `0x150ed00`) do not read `NiLight.fade` or the NiLight flags. They test `frustrumCull` (only with the list-`+0x1e0` context flag), the wrapper query at vtable `+0x18` (a true result skips the wrapper), the sphere test and `IsValidLight`. The selector (G01) skips NiLight flag bit 0 but does not test fade. A light below 0.05 that a geometry-centric pass attached therefore stays in the list, and takes a slot with its small colour, until `EnableLight` next runs for it. `EnableLight` runs each frame only for active lights with `dynamic` (`+0x46`) and `pointLight` (`+0x44`) set, flag bit 0 clear and `frustrumCull` not `0xff`, unless scene byte `+0x219` is nonzero.
2. `IsValidLight` (`0x14e8350`): true when wrapper `affectLand` (+0x61) is nonzero, or when the property flag word (+0x38) has neither bit 14 (`0x4000`) nor bit 46 (`0x400000000000`). Otherwise false. Evidence `0x14e8350–0x14e8376`.
3. Geometry-centric sphere test (`BSLight::IsInRange`, `0x15768e0`): directional lights always pass (the class test is against the `NiDirectionalLight` descriptor). For other lights, `(|lightWorldPos + renderOffset − boundCentre|) − boundRadius × scale < NiLight.radius.x`, with scale 1.0 at the call sites. The render offset is scene `+0x2e8` when the global mode word `0x33d3db0` is `0x11` or `0x16`, else the zero vector at `0x331c458` (`0x15768e0–0x15769bc`). Node-level collection uses the node's bound (`+0xe4..+0xf0`) and **applies the result to every geometry beneath that node** with no per-geometry test (`0x150f0c0`, `0x150e860`). A node with bit 11 of its flag word set bypasses the sphere test (`0x150e9d3–0x150e9ff`).
4. Light-centric traversal: culling-process test against each node and geometry bound. The traversal skips subtrees by the flag filter given in #1003 G04 (bits 26 and 11, scope pointer `+0x130`). The exact shape of the culling volume (sphere or hemisphere set) is **unverified**.
5. Wrapper scope: a light with scope pointer `+0x130` set is attached only below that scope. In the global candidate scan (`0x150ebd2–0x150ec2e`) a light with a scope pointer is skipped. Scoped lights come from the scope's own array.
6. Frustum and fade state (G10): a light whose sphere lies outside one of the camera frustum planes, or whose `d² − R²` exceeds `end²`, has `frustrumCull = 0xff`. It stays in the geometry lists but the selector skips it every frame, so it does not take a slot. The state is recomputed each frame by `0x1575d20`.
7. Registered-object path only: with the context flag set (list `+0x1e0`), candidates with `frustrumCull == 0xff` are also dropped at collection (`0x150e9a4–0x150e9b5`).

**Confidence: high** for items 1–3, 5 and 6. **Medium** for item 4. **What would change it:** a trace of `BSParabolicCullingProcess` virtual `+0xe0`.

### G04. The sort key and the order of node-level candidates

**Verified.** `0x150e860` (`BSFadeNode::CullRoomLights`) collects candidates for one registered node into a temporary array of wrapper pointers. For each candidate it calls the key writer `0x1577060` (calls at `0x150ea3b`, `0x150eb4b`, `0x150ec29`). The key stored at wrapper `+0x10` is `(d − boundRadius) / NiLight.radius.x`, where `d` is the distance from the light position (plus render offset, same rule as G03 item 3) to the node bound centre. It is negative when the light centre is inside the node's bound sphere. The array is then sorted with the C runtime `qsort` (import at `0x17c9268`, call at `0x150ec59`, element size 8, comparator at `0x1512370`). The comparator returns −1 when the first key is larger than the second, 0 when equal, and +1 when smaller. Larger keys sort first: **the candidate farthest from the node, in units of its own radius, comes first.** `0x150f0c0` then calls `AttachGeometry` for each geometry under the node in this order (`0x150f200–0x150f21b`), inside the fence. The resulting property list is therefore in descending key order, and the selector's first 7 entries after sun and shadows are the 7 largest keys.

**Verified.** For geometry, and for nodes with bound radius 150 or more, `0x150ee90` and `0x150ed00` visit an input array without sorting. The source is the light array of an immediate `BSMultiBoundRoom` parent (`+0x180`, count `+0x190`), else that of an immediate `BSPortalSharedNode` parent (`+0x128`, count `+0x138`), else the scene's active ordinary-light array (`+0x130`, count `+0x140`). The caller `0x150d6a0` tests only the immediate parent (`object +0x30`; the virtual at `+0x10` returns the class descriptor, compared at `0x150d6e9–0x150d71b`). The descriptor objects at `0x143327818` and `0x14332e278` are built at start-up from the name strings `BSMultiBoundRoom` (`0x141a69a08`) and `BSPortalSharedNode` (`0x141a6def0`). The last source skips lights with a scope pointer. Each light must pass `IsInRange` against the geometry's own bound (`0x150ef4f–0x150ef65`, `0x150efef–0x150f003`, `0x150f07c–0x150f09d`). The scene array receives a light at the end when it is queued (`0x150d4e0–0x150d56b`), so its order is queue order. Entries are removed with their slot closed up (`0x150db42`).

**Tie rules.** `qsort` is not stable. Equal keys have implementation-defined order. A float key tie is unlikely for distinct lights. Duplicates cannot occur because `AddLight` suppresses them.

**Confidence: high** for the sign of the comparator, the key formula and the visiting order. **Medium** for the practical claim that retail keeps the largest-key candidates in this path: it depends on no later reorder, and none was found between `0x150f200` and the selector. **What would change it:** a runtime dump of one property list next to the `+0x10` keys of its entries.

### G05. Near geometry in interior and exterior cells

**Verified.** None of the functions in G01–G04 branch on interior versus exterior. The only global mode read in the attach code is the render-offset selector `0x33d3db0` (G03 item 3). No read of the TES or player singleton occurs in `0x150b000–0x1578000`. Interior and exterior cells differ in these inputs only: which lights exist; the fade begin and end values (G11); whether lights carry a scope pointer (portal-strict and room lights); which light array an object resolves to (an immediate `BSMultiBoundRoom` or `BSPortalSharedNode` parent has its own array, G04); and the set of objects that the engine registers.

**Verified.** `BSLight.portalStrict` (`+0x47`) is set at creation from LIGH flag bit 13 for placed lights (`0x2747b9–0x2747c5`, copy at `0x150c9f0`). The reading `portalStrict` is the CrashLogger name of `+0x47`. Its effect on attachment (the per-property light array at `[wrapper + 0x128] + 0x30190` read at `0x150e9c1`) was not traced beyond the candidate filter at `0x150ea14–0x150ea27`.

**Inferred.** The 7-slot cut applies the same way in a room and in an exterior. A room with more than 7 qualifying lights loses the ones that are late in the list, as G04 describes. A rule that keeps the 64 nearest enabled lights uses more lights per geometry than retail whenever more than 7 non-shadow lights qualify for one geometry. The count of retail-qualifying lights also drops lights outside the camera frustum and lights beyond the fade end (G10).

**Confidence: high** for the absence of a cell-type branch. **Medium** for the inference. **What would change it:** an interior capture with more than 7 lights near one mesh.

### G06. LIGH DATA flag bits

**Verified.** The LIGH loader copies `DATA` into the form starting at `+0xe0`: `Time` (+0xe0), `Radius` (+0xe4), `LightColor` (+0xe8), `LightFlags` (+0xec), `FallOffExponent` (+0xf0), `Fov` (+0xf4), `NearDistance` (+0xf8), the flicker period field (+0xfc, CrashLogger name `FlickerPeriodRecip`), `FlickerIntensityAmplitude` (+0x100), `FlickerMovementAmplitude` (+0x104). `FNAM` stores a float at `+0x108` (base fade). Evidence at `0x273c93–0x273d45` and `0x273e82–0x273ead`.

**Verified.** The function at `0x274330` maps flag bits to the editor names: bit 3 to `Flicker`, bit 6 to `Flicker Slow`, bit 7 to `Pulse`, bit 8 to `Pulse Slow`, else `None` (strings at `0x1814518–0x1814538`). The cell registration tests `flags & 0x1c8` (= bits 3, 6, 7, 8) at `0x2d7ff6` and `0x2d81bd`. The per-frame modulation function `0x274bc0` tests **bit 3 only** for flicker (`0x274c4f–0x274c57`) and **`flags & 0x180`** (bits 7 and 8) for pulse (`0x274f24`). **Bit 6 alone has no modulation in this function.** The value `0x1000` is not a flicker or pulse bit. The values `0x8`, `0x80` and `0x100` match the bits above. The value `0x40` is Flicker Slow.

**Unverified.** Whether other code reads bit 6 and modulates Flicker Slow lights. The search covered `0x274bc0` and the registration tests only.

**Confidence: high** for the bit mapping and the tests. **What would change it:** another reader of bit 6 outside the functions traced.

### G07. Pulse waveform

**Verified.** `0x274bc0` runs per light when the explicit-fade argument is negative. For flag bits 7 or 8 (and bit 3 clear) it does the following (`0x274f24–0x275011`).

- `P` is the phase stored in the NiPointLight attenuation memory at `light +0x140`. Each call: `P = P + dt × period`; if `P > 2π` then `P = P − 2π` (single subtract). `period` is the form field at `+0xfc`. `I = 0.5 × FlickerIntensityAmplitude` (+0x100).
- `base` is `FNAM` fade (+0x108) plus the reference's extra-data float at `+0x14` of type `0x91` when the reference carries one (`0x300020`, `0x16c640`). The extra-data type name is **inferred** as the reference light-data record. If the reference's extra-data float equals the largest finite single-precision value (`0x1417ed6a8`), that value is returned unchanged instead of the sum (`0x14030003f–0x140300059`). Which references carry that value is not traced.
- `NiLight.fade = base × (1 − I + I × cos P)`. The cosine is a lookup in a 512-entry table: index `trunc(P × 81.4873) & 511`, where `81.4873 = 512 / 2π`. Fade ranges from `base` (at P = 0) to `base × (1 − 2I) = base × (1 − amplitude)` (at P = π). Which table holds the cosine is **inferred** (see G08).
- Light local translate = `A × (cos P, sin P, sin P × cos P)` where `A` is `FlickerMovementAmplitude` (+0x104), written to `+0x6c`, `+0x70`, `+0x74`. These are the NiAVObject local translate fields (CrashLogger `NiAVObject` member `local`, field `translate`).

Pulse (bit 7) and Pulse Slow (bit 8) use the same formula and constants. The function has no slow/fast difference. The time per cycle is `2π / period` seconds if `dt` is in seconds.

**Confidence: high** for the formula. **What would change it:** `dt` units (G08), or another flag-dependent path.

### G08. Flicker waveform and the frame-time input

**Verified.** For flag bit 3 (`0x274c4f–0x274f1f`) three phases `A`, `B`, `C` live at `light +0x140`, `+0x144`, `+0x148` (defaults 1, 0, 0 when the light pointer is null). With `r = dt × period`:

- `A += r × U(1.1, 13.1)`, `B += r × U(1.2, 13.2)`, `C += r × U(1.3, 19.3)`, where `U(lo, hi)` is `lo + u × (hi − lo)` with `u` a 32-bit random integer times 2⁻³² (`0x1d6e40`). Each phase wraps once (`−2π`) when it exceeds `2π`.
- Movement: `s1 = sin(A + 1.7)`, `s2 = sin(B + 0.5)`, `s3 = sin(C + 0.3)` (table lookups, truncating). `M = 0.5 × FlickerMovementAmplitude × s1 × s2`, set to 0 if `amp + M ≤ 0`. Local translate = `(M × s1, M × s2, M × s3)`.
- Noise: `n = ((sin(1.3 B + 0.65) + 1) / 12) × (sin(1.1 A + 1.87) + 1) + 0.2 × sin(3 C + 0.9)`, clamped to [−1, 1]. The arguments are in radians. The code adds the offset and applies the scale in table-index units: the table index is `trunc(B × 105.93352 + 52.96676) & 511`, `trunc(A × 89.63606 + 152.38131) & 511` and `trunc(C × 244.46198 + 73.33860) & 511`. One index step is 2π/512 radians, so the factors are 81.4873 × (1.3, 1.1, 3) and the offsets are 81.4873 × (0.65, 1.87, 0.9). The range of `n` is [−0.2, 0.5333]. The sine and cosine tables are quantised to 512 steps, and the index is truncated. The six constants are at `0x141814574–0x141814588`.
- `I' = 0.5 × FlickerIntensityAmplitude`. `NiLight.fade = base × (1 − I' + I' × n)`. `base` is as in G07.

The tables are filled at start-up in one loop (`0xef2ca0`, step constant `0x1a48d00` = 0.0122718) from one call to the sincos helper `0x15a8050`. The table at `0x14331c6f0` receives the first result and `0x14331cef0` the second. **Inferred.** The first is the sine table and the second is the cosine table. This reading follows from G07, which needs a cosine at `0x14331cef0`. The table values are zero in the static image.

**Verified.** The function stores its phases in the memory that `NiPointLight` uses for the constant, linear and quadratic attenuation fields (CrashLogger offsets `0x140..0x148`). `NiPointLight::SetLightAttenuation` (`0x275600`) fills those fields from the `bLightAttenuation` settings at light creation. The point writer `0x154bb90` does not read them. The attenuation settings (`uLinearMethod` at `0x207ad18`, `bUseQuadratic` default 1, `fQuadraticValue` 16, and so on, value fields at `+8`) are read at `0x17334`, `0x274390` and `0x275600`. They do not reach the point constants.

**Unverified.** The unit of `dt`. The float at `0x3275608` has 204 readers and none that store to it directly. The neighbouring float at `0x3275600` is stored as a `1 / iFPS`-style value at `0x6559ce`. Whether `0x3275608` is seconds per frame is inferred from how the readers use it, not traced to a writer.

**Confidence: high** for the formulas and constants. **Low** for the unit of `dt`. **What would change it:** the writer of `0x3275608`, or one frame capture of two consecutive `light +0x134` values.

### G09. What the modulation changes, when it runs, and its effect on the 7-slot list

**Verified.** The point writer reads colour as `diffuse × NiLight.fade × BSLight.lodDimmer` and radius as `NiLight.radius.x` (`0x154bc13–0x154bc64`, `0x154bd8b`). Pulse and flicker change `NiLight.fade` and the light's local translate, which moves the light relative to its parent. Radius and diffuse RGB are not written by `0x274bc0`.

**Verified.** The flicker pass `0x2b9750` runs from the per-frame job `UpdateManagedNodesJob` (`0x2b79e0`, call at `0x2b7a19`) and from `0x1a1500`. For each light reference in the cell's flicker list (`[cell + 0x130] + 0x58`, count at `+0x68`) it calls `0x274bc0` only when the squared distance from the player reference position to the light reference is below `fFlickeringLightDistance²` (`0x2b98ae–0x2b9937`). The setting default is 1024 (value field `0x207ba88`). Lights beyond that distance are not updated in this pass. The pass does not reset their fade, so a light keeps its last modulated fade. That follows from the code read. No other reset was searched.

**Verified.** `0x274bc0` also has an explicit-fade mode (argument ≥ 0). It writes `NiLight.fade` directly. When the old fade was **below** 0.05 and the new fade is above 0, it calls `0x150e300`, which queues the light for `ProcessQueuedLights` and `EnableLight` processing (`0x274c15–0x274c45`, then the sequence `0x150e330–0x150e398`). `fLightEnableDisableFadeTime` (default 1, object `0x207ae38`, value field `0x207ae40`) is read at `0x27557b` and `0x2755b4`. This fade-in and fade-out path was not traced further.

**Inferred.** `EnableLight` detaches a light whose `NiLight.fade` is below 0.05 (G03 item 1). For a dynamic point light that `EnableLight` visits each frame, a modulated fade below 0.05 therefore removes the light from every geometry list. A later frame with fade at or above 0.05 attaches it again at the end of each list (G02). Pulse reaches `base × (1 − amplitude)` at its minimum, so a pulse light with amplitude near 1 or above drops out each cycle. An amplitude above 1 gives a negative fade at part of the cycle. At the lowest `n` of −0.2, flicker fade is `base × (1 − 1.2 × I')`. A light that `EnableLight` does not visit keeps its list entries (G03 item 1).

**Confidence: high** for the data path and update gate. **Medium** for the dropping and re-entering inference. **What would change it:** a frame capture of one pulse light across a minimum.

### G10. The dimmer and frustum state: formula and inputs

**Verified.** `BSLight::UpdateLODFadeAndCull` (`0x1575d20`) computes two values per light per call: wrapper `+0x5c` (`frustrumCull`) and wrapper `+0x14` (`lodDimmer`, written at `0x1575ed9`; the state at `0x1575ed5`). It takes the wrapper and a frustum object. The frustum object holds six planes at `+0x3c` (16 bytes each: normal xyz and offset) and an active-plane bit mask at `+0x9c` (`0x1575d70–0x1575dc1`).

1. Frustum test. For each active plane `i` with normal `n` and offset `c`, the test is `n · lightWorldPos − c > −R`. If the test fails for any plane, the state becomes `0xff` and the loop stops. Otherwise the state is 0. The light position is NiLight world translate (+0xa0..+0xa8) with no render offset. The loop covers planes 0..5 at most.
2. Dimmer. When the state is not `0xff`: if `lodFade` (+0x63) is 0 the dimmer is 1. Otherwise `q = |lightWorldPos − cameraWorldPos|² − R²`, where the camera position is the translate of the frustum object's node at `+0x18` (`0x1575dd9–0x1575e12`). Then: if `q < begin²` the dimmer is 1; else if `end² == 0` the dimmer is 1; else if `q > end²` the dimmer is 0 and the state becomes `0xff`; else `dimmer = 1 − (q − begin²) / (end² − begin²)` (`0x1575e12–0x1575e58`). `begin²` and `end²` are the globals at `0x33d3d34` and `0x33d3d38`.
3. When the state is `0xff` the dimmer keeps its previous value.
4. If the new state differs in the culled/visible sense, or the dimmer crosses zero, every geometry in the wrapper's geometry list has its light list's dirty byte set (`0x1575e62–0x1575ec3`).

The quantity compared is `d² − R²`, not the squared distance to the light sphere surface. A light is at full strength while the camera is inside the sphere or while `d² < begin² + R²`.

**Verified.** The callers are `ProcessQueuedLights` (`0x150db02`, over the scene's active ordinary-light array `+0x130`), `0x150fff0` (the same array, `0x151004c`) and `0x15121a0` (a given array, `0x1512262`). Which camera frustum the main call sites pass is **unverified**. Shadow-caster lights (the `+0x148` array) were not seen in these loops.

**Which lights.** The dimmer is computed for each light that these loops reach and that has `lodFade` nonzero. The placed-light constructor sets `lodFade` from the reference: it is 1 unless the reference's virtual at vtable offset `0xd0` returns true (CrashLogger `TESForm::IsHeadingMarker`, label GUESS) (`0x274802–0x2747f3`, copy at `0x14150ca3b`). Other creators of lights (`0x14098c1d6` and others) pass their own flag and were not traced. The wrapper constructor default is 1 (`0x1575a3f`). The sun light's upload has no dimmer (#1003 G03).

**Confidence: high** for the formula, state codes and the six-plane form. **Medium** for the set of lights. **What would change it:** the main call-site frustum, other light creators.

### G11. Where `begin` and `end` come from: interior, exterior and room lighting

**Verified.** `Sky::UpdateLightLODFadeDistances` (`0x416240`) stores `begin²` at `0x33d3d34` and `end²` at `0x33d3d38`. It runs from `Sky::Update` (`0x411ec0`, calls at `0x4121ff` and `0x4122ae`) through `0x412df0` (calls at `0x413280` and `0x4139da`). `0x412df0` branches on `Sky.mode` (`+0x1bc`: 0 `kNone`, 1 `kInterior`, 2 `kSkyDomeOnly`, 3 `kFull`, CrashLogger enum). Each source gives a pair `(begin, end)`. The function picks, in order:

1. The current room lighting template (`Sky::GetCurrentRoomLightingTemplate`, `0x419b30`): fade begin at form `+0x70`, end at form `+0x74` (`0x295920`, `0x295940`).
2. Else the interior cell (`TES +0xc0`): the cell's lighting struct `[cell + 0x68]` at `+0x50` and `+0x54` (CrashLogger `INTERIOR_DATA.lightFadeStart` and `lightFadeEnd`), or the cell's lighting template (`[cell + 0x138]`) at `+0x70` and `+0x74` when the struct's inherit flags (`+0x58`) have bit `0x400` set (`0x2bc540–0x2bc5de`).
3. Else `Sky.extLightingOverride` (`+0x28`): form `+0x70` and `+0x74`.
4. Else the settings: `begin = fLightLODStartFade` (value field `0x20d6ac0`), `end = begin + fLightLODRange` (value field `0x20d6ad8`).

When the Sky lighting transition fraction (`+0x38`) is above 0, the previous room template and the current one are blended linearly, each side resolved by the same order, and the blended `begin` and `end` are squared (`0x4163a7–0x4163c9`). Mode 1 and mode 2 can also write the squares directly from the interior cell (`0x413140–0x413171`, `0x4138b2–0x413912`). Mode 3 with no template and no override writes the settings pair (`0x413920–0x41396c`). Mode 0 writes the settings pair (`0x412fe6–0x413009`). The fade fields are used as distances (not squared) before squaring.

**Verified. A zero fade begin or end is replaced by the settings.** The cell initialiser (`0x2b8ed0`) ends with a default block (`0x2b9047–0x2b906a`). It runs when the form flag word has bit 3 clear (`0x2b8f1f–0x2b8f29`), the cell's lighting-data flag (`[cell + 0x40]` bit 0) is set and the lighting struct pointer (`[cell + 0x68]`) is non-null (`0x2b902e–0x2b903c`). For that struct, a begin (`+0x50`) that equals exactly 0.0 becomes `fLightLODStartFade` (value field `0x20d6ac0`). An end (`+0x54`) that equals exactly 0.0 becomes `fLightLODRange + fLightLODStartFade` (value fields `0x20d6ad8` and `0x20d6ac0`). The same two-field default is applied by `0x295b60` to a lighting template's `+0x70` and `+0x74` when form flag bit 3 is clear. Its callers were not found by direct call. The getters `0x2bc540` and `0x2bc5b0` return 0.0 when the cell's lighting-data flag is clear (or when the lighting struct pointer is null).

**Consequences.** A stored begin and end pair of 0/0 is not 0/0 when `0x416240` reads it. With the shipped `Skyrim_Default.ini` value `fLightLODStartFade=3500.0` and the compiled range 500, it reads 3500/4000. A stored begin that is nonzero with a stored end of exactly 0 gets end = range + start. That value can be smaller than begin. The dimmer is then 1 for `q < begin²` and 0 above (G10). `begin² = end² = 0` (dimmer 1 for every light) occurs only for a cell with no lighting data.

**Exterior.** In mode 3 with no room template and no `extLightingOverride` the settings pair applies. The image value of `fLightLODStartFade` is 0.0 (`0x20d6ac0`). A start-up initialiser (`0x1401001b0`) copies `fLightLODDefaultStartFade` (1000.0, `0x20d6aa8`) into it (`0x1401001c9–0x1401001d1`) and registers the setting object. **Inferred.** The INI loader sets registered settings later. The load order was not traced. `fLightLODRange` has the compiled value 500.0 (`0x20d6ad8`). The shipped `Skyrim_Default.ini` sets `fLightLODStartFade=3500.0`. With that value, `begin = 3500` and `end = 4000`. The setter of `Sky.extLightingOverride` was not traced.

**INI key with no setting.** The shipped `Skyrim_Default.ini` also lists `fLightLODMaxStartFade`. The pinned image contains no string of that name. The key has no effect on these values.

**Temporary override.** `0x9899c0` saves the two globals, writes two constants from `0x18de6c0` and `0x19843f4`, calls `ProcessQueuedLights`, then restores them (`0x989b92–0x989bce`, `0x98a26c–0x98a274`). The constants were not read. The purpose of that function is not traced.

**Confidence: medium-high** for the zero-value replacement. The function is identified from the form flag test, the record-type switch in the same function and the field offsets shared with the getters. **High** for the source order and the formulas. **Medium** for the exterior values because the effective INI values depend on files the game reads. **Low** for mode 1/2 inline paths versus `0x416240` when both run. **What would change it:** a runtime read of `0x33d3d34` and `0x33d3d38` in an interior cell whose lighting data carries a zero fade pair, and in an exterior.

### G12. Colour, radius and attenuation inputs, for completeness

**Verified.** Per point `i` (1..7), the point writer sends position (render-offset rules in #1003 G04), `NiLight.radius.x`, and RGB `NiLight.diffuse × NiLight.fade × lodDimmer`. Radius is divided by the geometry-scale argument on the model-space branch. The radius comes from `LIGH.Radius` (`+0xe4`) or a reference radius (`0x2ffd70`). A nonpositive value becomes about 0.1 (`0x2746a2–0x2746da`, constant at `0x1b5bde4`). Form flag bit 2 (Negative) negates the colour (#1003 G04). No `NiPointLight` attenuation coefficient and no `fLightLOD*` setting reaches the point constants other than through the dimmer.

**Confidence: high** for the colour and radius formula. **Not re-read by the reviewer:** the 0.1 fallback source, the reference radius and the colour negation.

### G13. Correction to earlier finding: the sort key at wrapper `+0x10` is not a luminance

**Verified.** Scope: the candidate-sort sentence in `findings/object-lod-ambient-sun-retail-facts.md` (#1003), G04, fourth paragraph. This is a wording correction to a merged finding. Other claims of #1003 G04 are consistent with this work (capacity 16, caps 7 and 4, shadow entries first, `0x15690f0` helper).

Published sentence: "The candidate sort used by `0x150e860` orders higher wrapper luminance first, using `+0x10` in the comparator at `0x1512370–0x1512398`."

Replacement sentence: "The candidate sort used by `0x150e860` orders larger wrapper `+0x10` values first (C runtime `qsort`, comparator at `0x1512370–0x1512398`, element size 8). At sort time `+0x10` holds the normalised distance `(distance from the light to the node's bound centre − bound radius) / NiLight.radius.x`, written by `0x1577060` for each candidate immediately before the sort. It is not a luminance. The lights farthest from the node in those units come first."

The comparator does order larger `+0x10` first. The CrashLogger field name `BSLight.luminance` at `+0x10` must not be read as the stored meaning here. The writer of `+0x10` in the candidate path (`0x1577060`, G04) stores a normalised distance. The statement "orders higher luminance first" therefore does not describe retail. The retail order is farthest-first in those units. The fix is wording only. It does not change the #1003 claim that Mudcrab need not use this sort for BTO geometry. This finding does not edit #1003. It is an amendment note for the maintainer.

**Confidence: high** for the writer and the comparator sign. The independent review re-derived both. **What would change it:** a second writer of `+0x10` that stores luminance and runs before the sort. The review found none between the key writer and the sort. The wrapper-specific callers of `0x1577060` are at `0x150ea3b`, `0x150eb4b`, `0x150ec29` and `0x1568f4f` (a range check against the constant at `0x1b4ad78`).

## Interpretation and alternatives

**Verified.** The retail cut is structural, not metric-based. A geometry's receiving lights are the first 7 lights in its list after the sun and shadow slots. The list is built from attach events, filtered each frame by the frustum and fade state.

**Inferred.** For a rule that matches retail in the common case, use: (a) candidates are non-shadow, enabled lights (NiLight fade ≥ 0.05) whose sphere overlaps the geometry bound sphere (`d − boundR < R`); (b) drop lights outside the camera frustum planes by radius and lights with `d² − R² > end²`; (c) apply `dimmer = 1 − (q − begin²)/(end² − begin²)` with begin and end from G11; (d) if more than 7 remain, the retail choice depends on attach order. The alternatives are "keep 7 nearest", which retail does not do, "largest-key first" for small queued nodes, which is what the sort produces, or "queue order" for objects without a room or portal parent. No single static rule reproduces all cases.

**Alternative reading of the sort.** If the comparator's sign or the apply order were reversed by something not found, the nearest candidates would be kept. No such reversal was found between the sort and the selector.

## Relation to earlier findings

- **#806** (sun shadows and interior shadow-light admission): G01 shows where shadow entries sit in the pass list (after the sun, before ordinary entries, same 16 slots). It does not restate the #806 admission gates. No correction to #806.
- **#812** (exterior fog): this finding makes no fog claim and gives no correction to #812.
- **#946** (terrain LOD versus near landscape shading): this finding makes no terrain LOD claim and gives no correction to #946.
- **#1003** (object LOD ambient, sun and point-light output): G01 to G03 extend its G04 anchors (selector, capacity 16, caps 7 and 4, `0x150e400`) and agree with them. G04 here names the parent arrays that #1003 calls "parent-associated". **G13 corrects one sentence of #1003 G04** (the candidate sort is not by luminance). It is a wording correction only.
- **#1061** (object LOD frame flags, fog output and projection): this finding makes no frame-flag, fog or projection claim and gives no correction to #1061.

Published corrections stay in force.

## Negative results and limitations

- **Unverified.** Runtime behaviour. Which family (light-centric or geometry-centric) builds the list for a given placed mesh (the attach path per placed mesh). The registration callers of `0x150e780`. The runtime order of one geometry's light list.
- **Unverified.** The exact shape of the light-centric culling volume, the shadow-scan enable argument of the selector, and the second and third callers of the selector (`0x1529f58`, `0x152cc4c`).
- **Unverified.** The unit of the frame-time float at `0x3275608`. Whether any code other than `0x274bc0` modulates Flicker Slow lights.
- **Unverified.** The main call-site frustum for `0x1575d20`, the shadow-light dimmer, and the creators of lights other than placed LIGH.
- **Unverified.** The effective INI values at run time, the INI load order against the start-up copy of `fLightLODStartFade`, the setter of `Sky.extLightingOverride`, and the callers of `0x295b60`.
- **Not found.** Any per-geometry sort by distance, luminance or colour in the selector or the writer. Any cell-type branch in the attach code.
- Static reading gives code paths and constants, not in-game values.

## Independent review

Reviewer: a fresh-context Sonnet 5.5 run (`claude-sonnet-5-5`), separate from the author. Sol was unavailable on usage limits. The reviewer wrote its own results first, then compared them with the draft. Static only.

Result: **7 confirmed (G01, G02, G06, G07, G10, G12 core, G13), 6 corrected (G03, G04 wording, G05, G08, G09, G11), 0 rejected.** This file contains the corrected wording.

| Group | Verdict | Main correction |
|---|---|---|
| G01. Selector, list order, cut at 7 | Confirmed | The reviewer also read the consumer. A null list element is removed by the compaction pass, not skipped by the selector loop (wording). |
| G02. Attach families and order | Confirmed | None. The reviewer did not re-read the light-centric traversals. |
| G03. Candidate admission | Corrected | The fade and flag-bit-0 test belongs to `EnableLight` (light-centric path) only. The geometry-centric collectors do not read them. |
| G04. Sort key and visiting order | Confirmed, wording corrected | The unsorted source arrays belong to an immediate `BSMultiBoundRoom` or `BSPortalSharedNode` parent. They are not "parent-associated" and "per-room" arrays. |
| G05. Interior and exterior | Corrected | The list of differing inputs now includes the parent-class array. A visual-sounding comparison is replaced by "uses more lights". |
| G06. LIGH flag bits | Confirmed | None to the bit mapping. Plugin-derived field statistics are not published. |
| G07. Pulse | Confirmed | The FLT_MAX case of the base value is now explained. The table identity is marked inferred. |
| G08. Flicker | Corrected | The noise formula listed table-index coefficients as radians. The radian form is now given with the index form. |
| G09. Modulation effects | Corrected | The explicit-fade call to `0x150e300` fires when the old fade is below 0.05. The draft said "at least". The re-attach inference now follows the `EnableLight` scope. |
| G10. Dimmer | Confirmed | None. |
| G11. Begin and end sources | Corrected | The cell initialiser replaces an exact zero begin or end with the settings. The draft said a 0/0 pair gives dimmer 1 for every light. That holds only for a cell with no lighting data. |
| G12. Colour, radius | Confirmed (core) | None. The 0.1 fallback, the reference radius and the negation were not re-read. |
| G13. Correction to #1003 G04 | Confirmed | The replacement sentence above is the reviewer's. |

The reviewer did not re-read these sub-claims: the light-centric traversals (`0x1513290`, `0x1576490`, `0x1577480`, `0x15776b0`), the callers `0x150fff0` and `0x15121a0` of `0x1575d20`, the `0x274330` strings, the LIGH loader range, the Sky mode mapping in `0x412df0`, and the `UpdateManagedNodesJob` call chain.

After the review, a third Sonnet 5.5 run applied the corrections. It re-read 21 corrected or newly cited items in the pinned image. All matched: the `EnableLight` flag and fade test, the compiled constants (0.05, 150.0, 0.1, 2π, the largest finite single-precision value), the explicit-fade condition at `0x274c25`, the cell initialiser default block and its two gates, the lighting-data getter, the start-up copy of the default start fade and the range value, the comparator, the selector capacity argument, the point and shadow count caps, the dimmer formula, the `0x300020` special case, the room and portal parent tests and their name strings, the modulation flag tests and the registration tests, the six noise constants and their index-unit scale, `IsValidLight`, the absence of the string `fLightLODMaxStartFade` in the image, the settings value fields, and the reference counts of `0x150e780` (19 calls and one tail jump) and `0x1575d20` (three callers).

Source exposure of the review: pinned native binary and shipped INI text. This is a static review. It is not match evidence for any function, and it does not decide transfer eligibility.

Reviewer and outcome: Reviewed independently by a Sonnet 5.5 run. Outcome: 7 confirmed, 6 corrected, 0 rejected. Static evidence only. Transfer status: UNREVIEWED.

## Amendment (2026-11-25, UNREVIEWED)

**Scope.** Wording only, for seven statements. No numeric formula, constant, address or range in this finding changes. The source is [light-flicker-time-base-retail-facts.md](light-flicker-time-base-retail-facts.md) (G01, G02, G05 and G08 there). **Verified, high. Static only.** Reviewed by an independent Sonnet 5.5 run in that finding.

1. **G08, the paragraph "Unverified. The unit of `dt`. …".** It now reads: **Verified (see the light flicker time-base finding).** The float at `0x3275608` is `BSTimer.delta`, in seconds. It is written only by `BSTimer` methods (frame update `0xce36b0`; the multiplier setter `0xce3970`). It is the real frame time from the performance counter (1 ms steps, capped at 1/6 s, smoothed over the last 8 frames by default), times the global time multiplier (default 1.0). The float at `0x3275600` is the fixed frame length in **milliseconds** (`1000 / N`), set from `iFPSClamp` or `iFPS:CameraPath` and 0 by default.
2. **G08, the confidence line.** It now reads: **Confidence: high** for the formulas, the constants and the unit of `dt`. **What would change it:** one frame capture of two consecutive `light +0x134` values.
3. **G07, the sentence "The time per cycle is `2π / period` seconds if `dt` is in seconds."** It now reads: `dt` is in real seconds times the global time multiplier `m` (default 1.0), and the loader clamps `period` to [0, 1]. One cycle takes `2π / (period × m)` seconds: at least 6.283 s at `m = 1`, and 6.283 / `period` s in general. In the G07 confidence line, "**What would change it:** `dt` units (G08), or another flag-dependent path." now reads: **What would change it:** another flag-dependent path.
4. **G06, the paragraph "Unverified. Whether other code reads bit 6 and modulates Flicker Slow lights. …".** It now reads: **Verified for the scope searched.** Bit 6 is read only by the editor-name function (`0x274330`) and the registration tests (`0x2d7ff6`, `0x2d81bd`). A `+0xec` displacement search found no other bit-6 test. Not covered: copies of the flag word and access through a pointer to the LIGH `DATA` block.
5. **G08, the table paragraph, and G07, the clause "Which table holds the cosine is inferred (see G08)".** "Inferred. The first is the sine table and the second is the cosine table. …" and the G07 clause now read: **Verified.** The fill loop `0xef2ca0` writes the sine to `0x331c6f0` and the cosine to `0x331cef0`.
6. **Negative results, the line "Unverified. The unit of the frame-time float at `0x3275608`. Whether any code other than `0x274bc0` modulates Flicker Slow lights."** It now reads: **Unverified.** Whether any indirect user of the flag word modulates Flicker Slow lights (see the time-base finding).
7. **Independent review table, row G08.** Add: Time base verified in the follow-up finding. The earlier outcome words stay.

The original text above stays unchanged. The amendment supersedes it for these statements only.
