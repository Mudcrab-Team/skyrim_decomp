Transfer status: UNREVIEWED

# Finding: frame flags, fog constant and projection for the exterior colour pass (object LOD, near Lighting, terrain LOD)

## Answer

| Question | Answer |
|---|---|
| 1. Which caller and argument predicates set flag bit 1 and bit 2 of the frame-constant writer in the main exterior colour pass? | **Verified (code path), high.** Mask `0x2` (bit 1) gives S=0. Mask `0x4` (bit 2) gives T=1. The main colour finish sets the camera and frame constants once through helper `0x15152d0` at `0x153a02f` with flag word `0x41` (or `0x51`). Its second stage calls slot `+0x158` through `0x1515360` at `0x153a1ef` with `0x40` or `0x41`. Neither word has bit 1 or bit 2, so the ordinary state is **(S,T) = (1,0)**. The first stage reaches the camera-state loader once more, at `0x153a6fd` through `0x153a6b0`, with flag word `1`. That word is also (1,0). Inside the second stage the writer is called again with `F` at `0x151f779`, with `F\|4` at `0x151f88c` and `0x151fa79`, and with `F` at `0x151f914` and `0x151fb2a`. The OR with 4 is unconditional at `0x151f887`. Only the draws between `0x151f88c` and `0x151f914` (pass group 7, category 9) and the sorted-list draw after `0x151fa79` (category 1) run with T=1. The sorted list runs with T=1 only when byte `0x20d69d8` is not 2. Bit 1 is never set by the colour passes. It enters only through callers that pass `3`, `0x43` or `0x53` (`0x1537df7`, `0x15398ee`, `0x1537c11`). Among the traced call sites, none passes bit 2. Four computed words (G01) are not bounded, and none is on the world colour chain. |
| 2. Which setters change the shared `1 / FramebufferRange` value (`0x20d694c`)? | **Verified, high.** Two stores and one restore only. (a) The console command handler `0x37ac30` stores `1.0 / argument`. The command table entry names it `SetFramebufferRange` (short `sfbr`). (b) Function `0x116ac80` stores `1.0` and restores the saved value at its end. Its two callers are `0x656921` and `0x6e4dc0`. Neither store is in the Lighting colour passes, the fog writer or the weather path. The ordinary exterior pass reads the image value `0.8333333` (`1/1.2`). |
| 3. Which projection and depth convention give the pre-divide clip XYZ in the stock object LOD fog vertex shader? | **Verified (arithmetic), high; medium for the far-plane source.** Clip XYZ is the row-transposed product `view × projection` of the active camera, cached per camera and flag bit 0 and uploaded as `VS b12[8..11]`. The view has rotation only. The projection is the standard left-handed form with clip Z `= F/(F−N) × (z − N)` and `w = z`. It is not reversed-Z. The viewport depth range is `0..1` by default. N is `fNearDistance:Display` (15) and F comes from scene far getter `0x665740` (default path 10240). The depth-shift ("viewport split") stage changes the camera far plane and viewport maximum, but the static trace found no rebuild of the cached matrices between the camera set and the draws. See G07, G08. |
| 4a. Do near Lighting and object LOD techniques share one flag argument in the ordinary pass? | **Verified for the code path, medium for stock BTO membership.** Yes. Both are drawn in the first stage ("Pass A", `0x151ef40`) under the single camera-set state (1,0). Stock BTO Lighting passes take category 7 (group 1) when blend is off and alpha times fade is at least 1. Near opaque passes go to the default list or categories 11 or 15. Blended Lighting passes with fade scalar at least 1 (category 1, the sorted list) and faded blended passes that take category 9 (group 7) run later with T=1. Faded blended passes that take category 10, 11 or 15 under the further predicates run in the first stage under (1,0). |
| 4b. Is exterior fog drawn with the object LOD vertex fog, or only through the shared fog writer? | **Verified, high.** Both. The 16 object LOD VS compute fog strength and colour from `VS b0[1..3]` and the 20 PS blend it. Those constants have one producer, the shared fog writer `0x154c010`, called from a single site (`0x1548614`). With (S,T) = (1,0) and the default clamp `B = 1.0`, the PS output equals `L` in every channel where `k × M ≤ 1.0` (`M ≤ 1.2`), so the fog does not change target 0 there. A channel with `M > 1.2` is lowered by `k × M − 1.0`. The full output is `L − max(0, k × M − B)`. With T=1 the output is `min(k × M, B)`. |
| 4c. Is the object LOD fog colour pair the same as the terrain LOD pair? | **Verified shared producer, high. Same values statically.** Both read the same fog property fields (`+0x38` and `+0x44`) through the same writer call. Both get the same day colours of weather `NAM0` rows 1 and 12 for one weather and time (G09). Runtime values, the active scene index and timing between technique setups are **unverified**. |

| Item | Evidence record |
|---|---|
| Status | OBSERVED for verified claims. Inferred and unverified claims are marked. Static only. |
| Author / human operator | A Sonnet 5.5 research run (`claude-sonnet-5-5`) that continued an interrupted Sol run (`gpt-6.2-sol` via Codex) / Taylor. |
| Reviewer | A separate fresh-context Sonnet 5.5 run (`claude-sonnet-5-5`). Sol was unavailable on usage limits. See "Independent review" below. |
| Date | 2026-11-24 CST, which is 2026-11-24 UTC. The independent review began at 02:06 CST. |
| Build | `sse-steam-1-7-104`, retail `1.7.104.0`, Steam build 24914197. Measured executable SHA-256 `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f` equals the asserted pin in [builds/target.json](../builds/target.json). |
| Principal function RVAs | `0x100ae80` (frame-constant writer), `0x101c660` and `0x101e7f0` (camera-state lookup and load), `0x101e4e0` (cache entry build), `0x101d400` (view, projection and view-projection builder), `0x101cb50` (cache refresh), `0x1515230`, `0x15152d0` and `0x1515360` (camera set plus accumulator start and finish), `0x1539f10` (main colour stage), `0x153a6b0` (camera set inside the first stage), `0x151ee90`, `0x151ef00`, `0x151ef40` and `0x151f540` (finish slots, first and second stage), `0x1521190` (batch draw), `0x151fb80` (sorted list draw), `0x151e4e0` (pass registration), `0x151a160` (Lighting pass builder), `0x15377f0` and `0x1537950` (depth shift), `0x140ef17a0` (frustum setter), `0x665740`, `0x665720`, `0xff4b70`, `0xff4bb0` (far and near getters), `0x154c010` (fog writer), `0x37ac30`, `0x116ac80`, `0x380300`, `0x37fa00` (command handlers). Descriptive function labels are GUESS. |
| Sources and revisions | Pinned executable and the retail shader package records for Lighting group 6 (member `shadersfx/shaders011.fxp`, SHA-256 `72cfc73eb0938d5949f0b3a8683722a33b671a34b41b750ba138de8d154c5fbc`, the same member as #1003). The weather-override statement in G09 rests on a read of the base and update plugin records of the same install. This finding publishes no plugin values. Published cross-checks: #812, #822, #946, #979 and #1003. |
| Source exposure | Pinned native binary analysis, shipped shader bytecode and a read of shipped plugin records. No sibling, downstream or leaked source. No decompiler text or disassembly appears below. |
| Name provenance | Command names `SetFramebufferRange`, `ToggleDepthShift` and `ToggleAlphaEffectJittering`, settings `fNearDistance`, `fNoLODFarDistanceMin/Max/Pct`, `fGamma` and `fLightingOutputColourClampPostLit`, and class names `BSShaderAccumulator`, `SceneGraph` and `BSSceneGraph` come from strings and RTTI in the pinned image. All other names are GUESS. |
| Intended recipient | Skyrim Research department lead for boundary review under [docs/clean-room.md](../docs/clean-room.md). Proposed use is Mudcrab issue #946. Maintainer transfer decision is pending. |

Addresses are RVAs for image base `0x140000000`. `bN[i]` is constant buffer N, float4 element i. VS and PS are vertex and pixel shader. **Verified** means re-read at the cited static source. **Inferred** means a deduction with stated assumptions. **Unverified** means not read or not resolvable statically. Flag bit numbers follow the earlier findings: bit 1 is mask `0x2` and bit 2 is mask `0x4`. The document contains facts and formulas only.

## Question and method

Mudcrab issue #946 needs the frame-flag state that the object LOD pixel shaders see, where the shared fog coefficient can change, which projection feeds the fog distance, and whether near Lighting and object LOD share one state. The earlier Sol run stopped on a usage limit with the lead that "the later colour stages can force T=1" and an open check of "which geometry those stages can receive and how the viewport split affects the fog projection". That statement was treated as unverified. This run re-read the writer, every caller, the accumulator finish slots, both passes, the pass-category assignment in the Lighting builder, the depth-shift code, the camera matrix cache and the fog constant writers. Method: static disassembly of the pinned image (a private local listing, not published), a small symbolic trace of the writer's matrix moves, and a read of the shipped vertex and pixel shader records. No game launch, capture or live value was used.

Every group below was re-derived in this run. Callers come from a plain search of the saved listing.

## Observations

### G01. Writer lanes and the complete caller inventory

**Verified.** The writer `0x100ae80` takes its flag word in `edx`. It stores `1.0 / fGamma:Display` (image default 1.0) in lane X of `PS b12[42]`. It stores lane Y (S) as 0 when mask `0x2` is set and 1.0 otherwise. It stores lane Z (T) as 1.0 when mask `0x4` is set and 0 otherwise (`0x100b327–0x100b349`). Lane W is 1.0 when mask `0x80` is set and 0 otherwise (`0x100b351–0x100b358`). The function then calls two virtuals of the device-context object (`+0x70` before and `+0x78` after a block copy, a map/copy/unmap pattern) on every call. That identification is inferred. It also loads the cached matrices from the global block at `0x20cffb0–0x20d0160` (G07).

**Verified.** The complete list of call sites follows. It comes from a plain search of the full listing for direct targets, plus the one tail jump.

| Call site | Flag word passed |
|---|---|
| `0x656771`, `0x65686e`, `0x656915` (frame function `0x6565b0`) | `0` |
| `0x151f88c`, `0x151fa79` (second stage `0x151f540`) | `F \| 4` (`esi = edi \| 4`, set at `0x151f887`) |
| `0x151f914`, `0x151fb2a` (second stage) | `F` |
| Tail jump `0x101ec1b` from the camera-state loader `0x101e7f0` | The third argument of `0x101c660` (`r8d`) |

`0x101c660` has 15 call sites. Their third argument is `0` at `0x40eb0d`, `0x40f72f`, `0x1520acd`, `0x1520bb6`, `0x1520e8c` and `0x153abc9`. It is `1` at `0x657165`, `0x657188`, `0x657234` and `0x153a6fd`. It is the caller's own flag word at `0x1515257` and `0x15152f7` (helpers `0x1515230` and `0x15152d0`), at `0x151f779` (second stage, `F`) and at `0x1539ad9` (`dil`). At `0x989c52` it is a byte with bit 9 added. The lookup keys its cache on the camera pointer and flag bit 0 and reuses an entry when one exists (`0x101c6a0–0x101c6c0`).

**Verified.** Camera helpers `0x1515230` and `0x15152d0` call `0x101c660` with the flag word `F`, then the accumulator's start slot (`+0x128`) and finish slot (`+0x150`) with the same `F` as `edx`. `0x1515230` then tail-jumps to slot `+0x158` with `F`. The values of `F` at their call sites: `0` (`0x248912`, `0x248a03`, `0x40ec0f`, `0x40f82e`, `0x65862e`, `0x153a320`), `1` (`0x153935b`), `0x21` (`0x153911b`), `3` (`0x1537df7`, `0x15398ee`), `0x43 or 0x53` (`0x1537c11`, the byte times 16 ORed with `0x43`), `0x41 or 0x51` (`0x153a02f`), `8` (`0x155a178`), a computed word with `0x20` ORed (`0x989e10`) and a computed word with bit 10 set (`0x155d3d7`). Among the traced sites only `3`, `0x43` and `0x53` carry bit 1, and no traced site passes bit 2. The computed words at `0x989c52`, `0x989e10`, `0x98a02e` and `0x155d3d7` come from caller arguments that were not traced. They are not on the world colour chain.

**Confidence: high.** A trace of live `edx` at the writer would confirm the values for one frame.

### G02. The ordinary exterior colour pass: camera set, accumulator, finish slots

**Verified.** In the world render function `0x656e60` the call at `0x6576be` enters `0x1539f10`. Its argument is the unsigned test "`[0x219e5c0 object + 0x160] > 0`". The test result is `bl`. `0x1539f10` calls the camera helper `0x15152d0` at `0x153a02f` with the camera `[[0x34362e8] + 0x128]`, the accumulator `[0x3436230]` and the flag word `(bl << 4) | 0x41`, so `0x41` or `0x51`. That call runs the writer once through `0x101c660` and then finish slot `+0x150` with the same word. Later in the same function (`0x153a1d6–0x153a1ef`) it calls `0x1515360` with the same camera and accumulator and the flag word `0x40 + (byte 0x20d6d10 ≠ 0)`. This reaches finish slot `+0x158`. The byte `0x20d6d10` is the state of the console toggle `ToggleAlphaEffectJittering` (short `tej`, handler `0x37fa00`, image default 1). Both words lack bit 1 and bit 2.

**Verified.** The accumulator constructor `0x151dea0` sets the mode field (`+0x150`) to 0. I found no direct store of another mode to the object at `0x3436230`. Modes 0xc, 0x10, 0x16, 0x17 and 0x1b are stored for other accumulators (`0x651901–0x651ed2`, `0x65856f`). Finish slot `0x151ee90` with mode 0 jumps to the first stage `0x151ef40` (`0x151eeb8–0x151eec4`). Slot `+0x158` (`0x151ef00`) with mode 0 calls the second stage `0x151f540` and then tail-jumps to `0x140f1ede0`. For a non-zero mode the table at `0x33d4b20` (default `0x151ee60`) calls both stages from the finish slot instead (`0x14eac91–0x14eac98`, `0x151ee6f–0x151ee83`).

**Inferred.** `[0x3436230]` is the primary world colour accumulator. Evidence: the world accumulate routine `0x1538430` binds it to the camera `[[0x34362e8]+0x128]` and starts the accumulate jobs on the object at `0x3436038`, and no other accumulator receives a colour word of `0x41/0x51` followed by `0x40/0x41`. The scene object at `0x34362e8` has no direct store in the saved listing. Its class is not proven.

**Confidence: high** for the call chain and the flag words. **Medium** for the identity of the accumulator. A draw capture of `edx` at `0x100ae80` would settle both.

### G03. What each stage draws, and the writer state it draws under

**Verified.** The first stage `0x151ef40` makes no call to the writer. When its flag word has bit `0x40`, it calls `0x153a6b0` at `0x151f49b`, after all its list draws and after a depth clear to 1.0. That routine calls `0x101c660` at `0x153a6fd` with flag word `1` (S=1, T=0), for the same camera and the same cache entry (flag bit 0 = 1) that `0x153a02f` loaded. No other routine reached from the first stage by direct calls calls the writer or `0x101c660`. Every list draw in the stage therefore uses the state loaded at `0x153a02f`, **(S,T) = (1,0)**, and the state after the call at `0x153a6fd` is the same. The draws are issued by `0x1521190` (arguments: first and last pass id, group index, draw-flag word). In order:

1. Default list, pass ids `1` to `0x5c00002f`. A Lighting pass id is `0x4800002d + (technique << 24) + feature bits` (`0x151adb8–0x151ae5e`). The ids of techniques 0–19, including 13 and 15, are inside this range.
2. Group 9 (category 11), then the default list for ids `0x5c000030` to `0x5c00005c`, then group 8 (category 15), group 1 (category 7) and group 0 (category 6). Each group draw uses ids `1` to `0x5c006074`.
3. After group 0 the depth shift is switched back (`0x151f11c`). The remaining first-stage draws (default ids from `0x5c00005d`, group 13, subpasses `0x151fd60`, `0x151ff00` for groups 3, 2 and 4) follow a second depth-shift call at `0x151f1fa`, and the stage ends with the restore at `0x151f51b`.

**Verified.** The second stage `0x151f540` draws, in order: group 10 (category 13), the default list for ids `0x5c000071` to `0x5c006071`, then the writer is called with `F` (`0x151f779`), then groups 11 and 12, all under T=0. Then the writer is called with `F|4` (`0x151f88c`) and **group 7 (category 9)** is drawn with T=1. The writer is called with `F` again (`0x151f914`). A block guarded by flag bit `0x40` and a pointer test `[[0x33d40a0]+0x168]+8 ≠ 0` sets and later clears the selector `0x3436408` (`0x151f9b5`, `0x151fb1a`). Then, unless `0x20d69d8` equals 2, the writer is called with `F|4` (`0x151fa79`) and the **sorted base list** (category 1) is drawn by `0x151fb80` (`0x151fa80`) with T=1. The last writer call restores `F` (`0x151fb2a`) before a draw of the single id `0x5c006072`. When `0x20d69d8` equals 2, `0x151fb80` runs earlier (`0x151f58e`) with the draw-flag word `F|4` but under the camera-set state (T=0).

**Verified.** The pass category is a byte at pass `+0x1c`, set by the Lighting pass builder `0x151a160`. The registration routine `0x151e4e0` maps it to a group list (table at `0x151e840`): category 1 to the base sorted list (offset `+0xf0`), 2 to group 3, 3 to group 4, 4 to group 5, 5 to group 6, 6 to group 0, 7 to group 1, 9 to group 7, 11 to group 9, 13 to group 10, 14 to group 11, 15 to group 8, 16 to group 12, 17 and 18 to group 13. Categories 8, 10, 12 and 0 take the renderer's own add routine (the default list).

**Verified.** The builder's category rules for a property whose flag word has bits 26 and 27 clear (stock BTO flags; `0x151a8fc–0x151acc8`):

- If the "blend" predicate is false (property alpha times fade scalar is at least 1, and the alpha property blend bit is clear) and the flag word has any of bits 33, 34 or 63: category `6 | (bit 33 clear)`. Stock object LOD flags have bit 34 (technique 13) or bit 63 (technique 15) and bit 33 clear, so category **7, group 1**. Terrain LOD (bit 33) is category 6, group 0.
- If the predicate is false and none of those bits is set (near opaque Lighting): category 0 (default list), or 15 or 11 under light-count and flag-bit-61 predicates.
- If the predicate is true and the fade scalar is at least 1: category 1 (sorted blended list). If it is true and the fade scalar is below 1: category 9 (group 7) or 10, 11 or 15 under further predicates.

**Verified.** Categories 1 and 9 run with T=1 (category 1 only when `0x20d69d8` is not 2). Categories 10, 11 and 15 run in the first stage with S=1 and T=0.

**Verified.** Groups 0, 1 and 2 can be pre-recorded by `0x1520db0` (called from `0x41ca0f`), which calls `0x101c660` with flag word 0 (`0x1520e8c`). The replay at `0x14155df50` runs the recorded commands. **Unverified:** the writer state during that replay. This run did not re-read it.

**Inferred.** For the 2,428 stock BTO Lighting properties of #1003 G01 (alpha test on, blend off, flag bits 33 clear) with default alpha and fade of 1.0, object LOD Lighting is category 7 and runs in the first stage at (1,0). This assumes the fade scalar (`material + 0x130`) and property alpha (`+0x80`) read 1.0. **Unverified:** their runtime values during LOD transitions. A value below 1 makes the blend predicate true. The pass then takes category 9 (T=1) or category 10, 11 or 15 (T=0), under the further predicates.

**Confidence: high** for the stage order, the writer calls and the category table. **Medium** for the stock BTO category result. A capture of `edx` at the first draw of one BTO block would settle it.

### G04. Other flag words: where bit 1 (S=0) and the other frame callers matter

**Verified.** Flag words with bit 1 reach the finish slots only from `0x1537c11` (`0x43` or `0x53`, accumulator `[0x3436240]`, mode 0x16), `0x1537df7` (`3`, main accumulator `[0x3436230]`) and `0x15398ee` (`3`, accumulator `[0x3436228]`, mode 0xc). Pass code treats bit 1 and bit 3 (`0xa`) as "no depth shift" (`0x151ef9f–0x151efa6`). With bit 1 set, S=0, the shader output is `min(L, B)` with no fog term (G05). `0x1537b10` is called from `0x6577d1` and also changes the viewport depth range to `0..0.01` or `0..0.1` (`0x1537b7e–0x1537b9a`).

**Inferred.** Mode 0x16 is the first-person accumulator. The published #1003 G04 notes a first-person mask in the mode-0x16 light selector. The `0x1537df7` draw re-uses the main accumulator with a node at `[0x34362f8]` whose flag bit is toggled around it. So the bit-1 calls are first-person or depth stages, not the world's near, terrain LOD or object LOD Lighting draws. The `0x15398ee` stage belongs to the mode-0xc accumulator (the shadow-mask mode named in #806). I did not read what geometry `0x1537df7` receives beyond that toggle.

**Confidence: high** for the flag words. **Low** for the geometry labels. A scene-graph or capture trace would settle them.

### G05. Output equations by (S,T)

**Verified.** All 20 object LOD PS, the near keys without highlights and the four terrain LOD PS emit, per RGB channel, `out = min(L, S × Q + B) − T × S × Q`, with `M = L + F × (Cf − L)`, `Q = L − k × M`, `k = PS b0[0].w` and `B = PS b0[1].x` (the checked `ps-0d000001` record, and #1003 G05). Here `L` is the lit colour, `Cf` and `F` are the interpolated fog colour and strength, and `M` is the fogged colour. Substituting `L − Q = k × M`:

| Case | Target 0 RGB |
|---|---|
| S=1, T=0 (ordinary colour passes) | `L + min(0, B − k × M)`. This is `L` in every channel where `k × M ≤ B`, and it is lower than `L` by `k × M − B` in a channel where `k × M > B`. |
| S=1, T=1 (sorted blended list, group 7) | `min(k × M, B)` |
| S=0 (flag bit 1) | `min(L, B)` |

**Verified.** With the defaults `B = 1.0` (`fLightingOutputColourClampPostLit`) and `k = 0.8333333` the threshold is `M = B / k = 1.2` per channel. Here `M = L + F × (Cf − L)` lies between the lit colour `L` and the fog colour `Cf`. While every channel of `M` is at most 1.2, case S=1, T=0 returns exactly `L`, and the fog term has no effect on target 0. A lit channel above 1.2 is reduced. Example at the defaults: `L = 2.0`, `Cf = 0.6`, `F = 0.5` give `M = 1.3` and an output of 1.9167. With zero fog factor and `L = 1.5` the output is 1.25. Whether stock lit colours reach 1.2 is **unverified** (static only). In the T=1 case the output is the fogged colour scaled by `k`, limited to `B`. In the S=0 case the output is the lit colour limited to `B`.

**Verified.** The sequence in the saved PS record is: `M`, then `Q = L − k × M`, then `S × Q + B`, then the per-channel minimum with `L`, then the subtraction of `T × S × Q`. An independent numeric run of the three cases at the defaults (single-precision `k`, threshold `1.2000000286`) agreed with the sequence for 200,000 random inputs.

**Confidence: high** for the algebra. The runtime `B`, `k` and `F` remain **unverified**.

### G06. Setters of `1 / FramebufferRange` (`0x20d694c`)

**Verified.** The image value is `0x3f555555`, 0.8333333 (`1/1.2`). A search of the full listing for every operand that resolves to `0x20d694c` finds three stores. The reads are in the fog writer (`0x154c07b`) and in other shader constant uploads.

- `0x37ac8f`, inside `0x37ac30`: stores `1.0 / (float parsed from the command argument)` after the parser `0x344ca0` succeeds. The command record at `0x2092770` names it `SetFramebufferRange` (short `sfbr`, help text "Set frambuffer range").
- `0x116acfb`: stores `1.0`, inside `0x116ac80`, only when byte `[object + 0x1c0]` is non-zero. The previous value was loaded at `0x116aceb` and is stored back at `0x116afb6`. The routine walks an array at `[object + 0x110]` (count at `+0x120`) and calls a virtual on each entry. The object is the one at `[0x219e5c0]`.
- No other store, no INI or setting binding, and no store in the weather, fog or Lighting setup paths.

**Verified.** The caller `0x656921` follows the world render in `0x6565b0`: `0x656a73` or `0x656834` renders the world first, and the flow reaches `0x65689f`, then `0x656915` (writer, word 0) and `0x656921`. So the temporary 1.0 is not active during the ordinary world colour pass. **Inferred** from that order. The identity of the object list in `0x116ac80` and the second caller `0x6e4dc0` are **unverified**.

**Confidence: high** for the three stores. **Medium** for the timing. A write watch on `0x20d694c` for one frame would settle the timing.

### G07. Projection, depth convention and sources of N and F

**Verified.** The writer's matrix block at `0x20cffb0`, `0x20cfff0` and `0x20d0030` comes from one cache entry loaded by `0x101e7f0` (entry offsets `+0x40`, `+0x80`, `+0xc0`). The entry is built by `0x101e4e0` through `0x101d400` (call at `0x101e648`) with three outputs: the view (`+0x40`), the projection (`+0x80`) and `view × projection` (`+0xc0`, multiply routine `0x4ae420`). A symbolic trace of the writer's moves shows the transposed blocks are stored as `b12[0..3] = viewᵀ`, `b12[4..7] = projᵀ` and `b12[8..11] = (view × proj)ᵀ`. Later slots hold further blocks and the results of matrix routine `0x4ae130` (not decoded here). The vertex shader record `VS 0d000000` builds clip X, Y and Z from `b12[8..10]` and W from `b12[11]`, and its fog distance is the length of that clip XYZ before the divide by W. The earlier fog finding (#812 G04–G05, as corrected) and the terrain LOD shading finding (#822) report the same expression for all checked object LOD and terrain LOD vertex records.

**Verified.** The view built by `0x101d400` copies a 3×3 rotation from the camera (`+0x7c`–`+0x9c`) with zero translation lanes and a unit last row, so positions arrive camera-relative. The perspective projection is `x' = 2x/(r−l) − (r+l)/(r−l) × z`, `y'` likewise, `z' = F/(F−N) × z − N×F/(F−N)` and `w' = z`. The frustum comes from the camera at `+0x150..+0x164` (left, right, top, bottom, N, F) and `+0x168` (orthographic byte). The default viewport depth range is `0..1` (`0x20d01c0`, `0x20d01c4`). There is no reversed-Z form. Fog distance is therefore `d = sqrt(x'^2 + y'^2 + z'^2)` with `z' = F/(F−N) × (z − N)`.

**Verified.** Flag bit 0 of the camera word selects the cache entry, and with the temporal-jitter byte `[[0x33d40a0]+0x1f0]+0x18` set it multiplies the projection by a sub-pixel translation before `view × proj` (`0x101e6a8–0x101e78f`). So `0x41`, `0x51` and `0x41` give the jittered pair. `0x40` gives the unjittered pair. The jitter adds `jx × z` to clip X and `jy × z` to clip Y, a second-order change to the fog length.

**Verified.** N and F come from the camera frustum fields, which `0x140ef17a0` writes from its arguments (`+0x160`, `+0x164`). The two getters used by the depth-shift code are scene virtual slots `+0x1f8` (near) and `+0x1f0` (far) of the object at `0x34362e8` (calls at `0x1537858`, `0x1537840`). For the base class `BSSceneGraph` near is `fNearDistance:Display` (`0x20cf9b0`, image 15.0). Far is `20480.0` (`0x1914d08`) when byte `+0x138` is set, otherwise `(Max − Min) × Pct + Min` with the three `fNoLODFarDistance` settings (defaults 100, 10240 and 1.0 at `0x20cf968`, `0x20cf980`, `0x20cf998`), which is **10240** at defaults. The derived `SceneGraph` getters (`0x665720`, `0x665740`) first return an override (`+0x140` when byte `+0x148`, `+0x144` when byte `+0x149`). Far also passes through a branch on a cell object reached from `[0x32303b8]` (`0x665786–0x6657f1`). It either keeps the settings path or uses the constant `353840.0` (`0x1a70458`) with no lerp, and a positive value returned by `0x2bc4d0` can lower it. I did not resolve which branch an ordinary exterior takes.

**Inferred.** The world scene graph has its camera at `+0x128`, the same layout as `[0x3230740]` (`0x656d68`). `0x34362e8` is the same object or a copy. Which class and which far branch applies to an ordinary exterior is **unverified**.

**Confidence: high** for the matrix producer, the depth convention and the VS use. **Medium** for the far-plane source. A write watch on camera `+0x160/+0x164` would give the exact N and F per frame.

### G08. The depth-shift ("viewport split") stage and its effect on the fog projection

**Verified.** The image names the stage "Depth Shifting". Console command `ToggleDepthShift` (short `tdh`, handler `0x380300`, help text "Toggles depth shift for debugging purposes") flips byte `0x20d72c0` (image default 1). Routine `0x15377f0` runs when that byte is non-zero and the scene object `0x34362e8` exists, unless byte `0x3436058` is zero and byte `0x3436311` is non-zero. `0x3436058` is stored per frame at `0x6571d2` from a keyed lookup in the object at `0x219e5c0` (entry flag `0x40`, `0x1169530`). `0x3436311` has no store in the saved listing. The first stage calls it at `0x151efa6` only when the flag word has neither bit 1 nor bit 3.

**Verified.** The routine reads N and F from the two getters (G07), stores them (`0x3436054`, `0x3436050`) and sets the camera frustum to `N` and `D = N × F / ((N − F) × K + F)` through `0x140ef17a0`. `K` is the float at `0x1b436b4`, 1.0000020. It then lowers the viewport maximum depth to `min(current max, 0.9999980)` (float at `0x1b436b0`, `fminf` import) through `0x14101d5d0`. `0x1537950` restores F and the saved depth range.

For N = 15 and F = 10240: `D = 10254.1655` (14.17 above F). `D/(D−N) = 1.00146496` against `F/(F−N) = 1.00146699`, a relative change of −2.03e-6 in the clip Z scale. For F = 20480 the same figures are `D = 20536.78` and −2.03e-6. The two segments give depth values equal to within 4e-6 over the range, with the near segment slightly smaller (nearer the camera).

**Verified.** The cached matrices are not rebuilt by this routine. It calls no cache function. The cache entry for a camera and flag bit 0 is built on a miss by `0x101c660` and refreshed only by `0x101cb50` (called from `0x6570f5–0x657144` and `0x989c28`, all at frame setup). `0x101ca60` only copies current matrices to the previous-frame slots.

**Inferred (medium).** In the colour passes `b12[8..11]` therefore hold the full-range `F` projection built at frame setup. The depth-shift far plane `D` and the viewport maximum do not enter the fog distance. If `D` did enter it (a first-time cache build during the shifted state), the clip Z scale would change by about 2e-6 relative, below any visible effect. This conclusion needs a capture of `b12[8..11]` in a shifted draw.

**Confidence: high** for the stage arithmetic and gating. **Medium** for the no-rebuild inference.

### G09. Fog constants and the colour pair (questions 4b and 4c)

**Verified.** The Lighting fog writer `0x154c010` has one call site (`0x1548614`, inside technique setup `0x1547db8–0x15486ca`, straight-line after the state updates). It reads the fog property of the scene selected by byte `0x20d6970` and copies near RGB (`+0x38..+0x40`) and far RGB (`+0x44..+0x4c`) without transform. It writes the near RGB plus `k` to `VS b0[2]` and `PS b0[0]`, the far RGB to `VS b0[3]`, and the scalar vector `(near/(far−near), 1/(far−near), power, max)` to `VS b0[1]`. All Lighting techniques (near, terrain LOD 9 and 18, object LOD 13 and 15) use this constant source. The vertex shader record for technique 13 reads `cb0[1..3]` only for fog and returns `lerp(near, far, F)` in `COLOR1`. Right after the call the common bind writes the three post-lit clamp settings into `PS b0` (`0x1548633–0x1548650`, globals from `0x343640c`). The first of them supplies `B`.

**Verified.** Byte `0x20d6970` has stores at `0x529a5d`, `0x989bd3`, `0x98a073`, `0x14ecdac`, `0x150c2c5` and `0x150c748` and is read by the Lighting, grass and other shader setups. For all techniques in one frame it is the same scene index unless one of those stores runs between setups. That timing is **unverified**.

**Verified.** The weather side (#812 G01–G03, as corrected): near fog RGB is the day colour of `WTHR.NAM0` zero-based row 1, far fog RGB is row 12, mixed by time and weather weights. The same colours reach object LOD, terrain LOD and near Lighting because the vertex stage reads one constant set. The `0x20d694c` scalar `k` enters only the PS. An `Update.esm` record can override a base weather record. The winning record, with both plugins loaded, supplies the colours. This finding states no plugin colour values. The climate weather lists and the weather chosen for a given hour are not enumerated.

**Confidence: high** for the shared producer and call site. **Medium** for equal values at draw time. **Unverified:** a capture of `VS b0` at an object LOD draw and at a terrain LOD draw in one frame.

### G10. Notes on earlier findings

**Verified, high confidence.** This run found no error in the S and T lane mapping, in the `0x20d694c` initial value or in the `T=1 → min(k×M, B)` statement of #1003 G05, #812 G04, #822 or #946. The items below are refinements, each scoped:

- #1003 G05: the formula and the S, T lane statements agree with G05 above. No change to #1003 is needed. The short statement that fog has almost no colour effect at S=1, T=0 is correct. The effect is zero in every channel where `k × M ≤ B` and is a reduction of `k × M − B` in a channel where it is above (see G05).
- #1003 G05 ("the pinned image has later writes") and #946 ("its native writer can change it"): the writers are the `SetFramebufferRange` command handler and the temporary 1.0 in `0x116ac80` (G06). Neither belongs to the ordinary exterior pass.
- #1003 G05 table: the frame-flag selection is now resolved for the colour pass (G01–G03) and no longer "unverified".

## Interpretation and alternatives

**Verified, G02–G05.** In the ordinary exterior colour pass near Lighting, terrain LOD and stock object LOD all take the same (S,T) = (1,0). With the default `B` and `k` the shader then returns `L` in every channel where the fogged colour `M` is at most 1.2, so the fog does not change the LOD or near colour in target 0 for such channels. T=1 applies to blended Lighting passes of category 1 (the sorted list) and category 9 (group 7), and flips the output to `min(k × M, B)`.

**Inferred.** A reproduction in Mudcrab should treat (1,0) as the base state with the output `L + min(0, B − k × M)`, use `min(k × M, B)` for category 1 and category 9 Lighting passes, and use `min(L, B)` for first-person and prepass draws.

**Alternative.** If stock BTO passes had alpha times fade below 1 during a transition, the blend predicate would be true. They would move to category 9 (T=1) or to category 10, 11 or 15 (T=0), depending on the further predicates. This run found no evidence either way.

## Relation to earlier findings

- **#812** (exterior fog): G09 reuses its `NAM0` row mapping and G04 (S and T lanes). This finding gives no correction to #812.
- **#822** (terrain LOD shading): its vertex expression for the fog distance agrees with G07. This finding gives no correction to #822.
- **#946** (terrain LOD versus near landscape): its output expression and its 1.25 example agree with G05. G06 names the writers that #946 leaves open. This finding gives no correction to #946.
- **#979** (near technique 19 order): its fog-bound order agrees with G05. This finding gives no correction to #979.
- **#1003** (object LOD ambient, sun and colour output): its G05 formula and lane statements agree with G05 here. G01 to G06 resolve the frame-flag selection and the later writes of `0x20d694c` that it lists as open. #1003 G05 needs no change.

Published corrections stay in force.

## Negative results and limitations

- **Unverified.** Climate weather lists and the weather chosen for a given hour are not enumerated.
- **Unverified.** The class of `[0x34362e8]`, the far-plane branch for an ordinary exterior and the exact N and F per frame.
- **Unverified.** The runtime values of `0x3436058`, `0x3436311`, `0x20d69d8` (image 0, other stores at `0x65799d` and `0x529bef–0x529c96`), `0x20d68f4`, the material fade scalar and the alpha property bits for stock BTOs.
- **Unverified.** The identity of the object lists in `0x116ac80` and `0x1537b10`, and the geometry that `0x1537df7` draws.
- **Unverified.** The writer state during the replay of pre-recorded groups 0 to 2 (`0x1520db0`).
- **Unverified.** The mapping of the PS constant table index to slots `PS b0[0]` and `PS b0[1]`. It was inferred from the record header bytes and the PS reads. A capture of `PS b0` would settle it.
- **Unverified.** Every runtime value, draw capture, resource view and visible output. The work is static only.
- **Not checked.** Pass B categories 13, 14, 16 (groups 10 to 12) assignment conditions, and the draw lists of `0x151fd60`/`0x151ff00` beyond their group indices.
- **Not traced.** Four computed flag words (`0x989c52`, `0x989e10`, `0x98a02e`, `0x155d3d7`). None is on the world colour chain.

## Independent review

Reviewer: a fresh-context Sonnet 5.5 run (`claude-sonnet-5-5`), separate from the author. Sol was unavailable on usage limits. The reviewer wrote its own results first, then compared them with the draft. Static only.

Result: **6 confirmed (G01, G02, G04, G06, G07, G08), 4 corrected (G03, G05, G09, G10), 0 rejected.** This file contains the corrected wording.

| Group | Verdict | Main correction |
|---|---|---|
| G01. Writer lanes and caller inventory | Confirmed | The scope of "no site passes bit 2" is now limited to the traced sites (four computed words are not bounded). |
| G02. Colour pass chain | Confirmed | None. |
| G03. Stage draws and categories | Corrected | The first stage does reach `0x101c660`, with flag word 1 through `0x153a6b0`. The result (1,0) is unchanged. Only categories 1 and 9 run with T=1. |
| G04. Other flag words | Confirmed | None. Geometry labels stay low confidence. |
| G05. Output equations | Corrected | "Equals `L` exactly" holds only where every channel of `M` is at most 1.2. Otherwise `out = L − (k × M − B)`. |
| G06. Setters of `0x20d694c` | Confirmed | None. |
| G07. Projection and depth convention | Confirmed | None. |
| G08. Depth shift | Confirmed | None. |
| G09. Fog constants and colour pair | Corrected | An `Update.esm` record can override a base weather record. The weather example is removed, and this finding states no plugin values. |
| G10. Notes on earlier findings | Corrected | The "exactly zero" wording is replaced by the scoped statement. Process notes are removed. |

After the review, a third Sonnet 5.5 run applied the corrections. It re-read 15 corrected or newly cited items in the pinned image. All matched: the call at `0x151f49b` and its flag test, the camera word `1` at `0x153a6fd`, the OR at `0x151f887`, the writer call list, the camera words at `0x153a02f` and `0x153a1ef`, the lane tests at `0x100b327`, the three stores of `0x20d694c`, the image value of `0x20d694c`, the computed words, the category stores, the early sorted-list call under `0x20d69d8 == 2`, the fog writer call site, the depth-shift gate and the PS output sequence. A numeric run of the output equation agreed (G05).

Source exposure of the review: pinned native binary, shipped shader bytecode and shipped plugin records. This is a static review. It is not match evidence for any function, and it does not decide transfer eligibility.

Reviewer and outcome: Reviewed independently by a Sonnet 5.5 run. Outcome: 6 confirmed, 4 corrected, 0 rejected. Static evidence only. Transfer status: UNREVIEWED.
