Transfer status: UNREVIEWED

# Finding: HDR frame leftovers (adapt time base, frame order, first frame, later draws, texture names, image-space selection, bloom kernel)

## Answer

Static only. No game run. No capture. No visual result is claimed. Group numbers in the last column point to "Observations".

| Question | Answer | Group |
|---|---|---|
| (a) What does `T` in the adapt rate measure? | **Verified, static only.** `T` is a time in seconds. In a running frame it is the float at `0x3275608`, member `+0x18` of a frame-timer object at `0x32755f0`. The timer update `0xce36b0` computes it from real elapsed milliseconds × `0.001`. A measured frame time above 1/6 s is clamped to 1/6 s. With the compiled defaults (`bCompensateUnstableFrameTime` 1, `iUnstableFrameTimeHistorySize` 8) the value is `(S − min(M, 0.05) − m) / 6`. `S`, `M` and `m` are the sum, the largest and the smallest of the last 8 frame times. So a spike above 0.05 s is only partly removed. A global time multiplier (`0x20ccac8`, image value 1.0) then scales the result. `iFPSClamp` 1 to 199 replaces the measured time with a fixed step of 1/`iFPSClamp` s. While the pause counter at `[0x219e5c0]+0x160` is nonzero, the HDR update uses `fConstHDRAdaptTimerForMenu` (0.3) instead of `T`. `T` is read one frame late, because the refill of `T` runs before `UpdateTimeManager` in every path. Two loops (`0x2c63f0`, `0x2c67c0`) call `Main::Render` and then store 0.0 into `T`. A render that follows such a refill sees 0.0. | L01, L02 |
| (b) What is the frame order of the modifier apply, the normaliser and the HDR update? | **Verified** inside one call of `Main::OnIdle` (`0x658870`), when its menu test does not skip the first steps: (1) cross-fade clock step; (2) clear the working block and copy the base data into it; (3) loop over the active modifier instances, each applies itself; (4) normaliser; (5) refill of the four timer floats; (6) `Main::Render`; (7) `UpdateTimeManager`. In a frame whose "not paused" flag is off, step 7 runs before step 6. The HDR update runs inside `Main::Render`, so it reads the finished working block of the same frame. **Unverified:** the order of the sky update against step 2. | L03, L04 |
| (c) What does the first frame, or a cleared adapted value, sample? | **Verified (code reading).** When the adapted handle at `0x20d7608` has id −1, the HDR render skips the adapt draw. It assigns the handle to the current frame's final luminance target. So each texel of the first sampled pair is `(n, n, n)`, with `n` the current average. The ratio `A.y / A.x` is 1 for `n > 0`. For `n = 0` the tonemap computes `L × 0 / 0`. That frame has no lag. When the handle exists, the adapt draw replaces the final luminance step, so one draw does not read and write the same target. The adapted texture is 2 by 2 texels at the default setting. It is 1 by 1 with `bUseMultipleLuminanceReferences` 0. The tonemap samples it at the screen coordinate with a bilinear filter. Clamp addressing is **inferred**. | L05, L06 |
| (d) What draws after the SAO/fog composite? | **Verified call order, blend states unverified.** After the composite call (`0x153a1ca`) and before the HDR stage the frame runs: the accumulator post-pass (depth-sorted alpha passes and more batches), a render of a second accumulator, the first-person view and, when enabled, volumetric-lighting steps. The composite saturates its own output. No saturate by the engine on the later draws was found. The default target is `R11G11B10_FLOAT`, which holds values above 1. **Inferred:** the tonemap input can exceed 1. | L07 |
| (e) What are the native names of the tonemap textures and the HDR targets? | **Verified.** `t0` = `kHDR_BLOOM` (24). `t1` = the HDR effect input, which is `kMAIN` (1) when no earlier post effect ran. `t2` = the persistent adapted handle at `0x20d7608`. It has no render-target name of its own. It points to one of the two targets of the final `kHDR_DOWNSAMPLE` level. Other targets: `kHDR_BLURSWAP` (22), `kLDR_BLURSWAP` (23), `kLDR_DOWNSAMPLE0` (25), `kHDR_DOWNSAMPLE0` to `kHDR_DOWNSAMPLE13` (26 to 39). | L08 |
| (f) Which image space and weather apply? | **Verified for the rules. No plugin data was read.** Exterior cell: if the world space has no lighting template, the base is the weather block at `0x31df470`. The weather blend (`0x4158d0`) rebuilds it from up to four IMGS (two weathers × two day parts). If the world space has a lighting template (the field at world-space `+0x160`; name **inferred**, medium), the interior rule applies. Interior cell: the cell's own IMGS (extra-data type `0x56`), or form id `0x167` when the cell has none. Interior cell with cell flag bit 8 set: the weather block. Room image spaces cross-fade with a timed smoothstep. A console or script override (manager `+0xb0`) wins over the base. IMAD modifiers apply on top. | L09 |
| (g) What is the bloom blur kernel? | **Verified for structure and tables.** There is no mip pyramid. One 4-tap downsample writes `kHDR_DOWNSAMPLE0` (about 1/4 size). Then two passes run: pass 0 is the bright-pass blur (vertical), pass 1 is the plain blur (horizontal) into `kHDR_BLOOM`. Both use `2k+1` taps with `k = clamp(trunc(BloomBlurRadius), 1, 7)`, integer texel offsets −k to k and the static weights below. The bright pass is `k_r × BloomScale × Σ w_i max(c_i / k_r − T_b, 0)` per channel. `k_r` is 0.8333333 in an ordinary frame and `T_b` is `BloomThreshold` plus a boost. The tonemap adds `b × saturate(ReceiveBloomThreshold − Lt)`. The fraction of the radius is not used. | L10 |

**Bloom weights, all seven tables.** Engine constants from the executable, at `0x20d7640 + (k − 1) × 0xf0`. Each row lists `w(u)` for `u` = 0, ±1, ±2 and so on. Each value after the first applies to `+u` and to `−u`.

| k | Taps | `w(0); w(±1); ...; w(±k)` |
|---|---|---|
| 1 | 3 | 0.786985755; 0.10650672 |
| 2 | 5 | 0.402619928; 0.244201481; 0.054488569 |
| 3 | 7 | 0.270682156; 0.216745213; 0.11128068; 0.036632769 |
| 4 | 9 | 0.204163671; 0.180173829; 0.123831593; 0.066282138; 0.027630489 |
| 5 | 11 | 0.163967222; 0.151360765; 0.119064637; 0.079811372; 0.045588955; 0.022190502 |
| 6 | 13 | 0.137022808; 0.129617959; 0.109719232; 0.083108582; 0.05633172; 0.03416691; 0.018543981 |
| 7 | 15 | 0.117695801; 0.112988554; 0.099966809; 0.081512466; 0.061254777; 0.042423215; 0.027077802; 0.015928362 |

| Item | Evidence record |
|---|---|
| Status | OBSERVED for verified claims. Inferred and unverified claims are marked. Static only. No runtime trace. |
| Author / human operator | A Sonnet 5.5 research run (`claude-sonnet-5-5`) for the department operator. A later Sonnet 5.5 run applied the review corrections and re-read key items. |
| Reviewer | A separate fresh-context Sonnet 5.5 run (`claude-sonnet-5-5`). Sol was unavailable on a usage limit. The reviewer had read a memory note that summarised the author's claims before it re-derived them. See "Independent review". |
| Date | 2026-11-25 CST. Author run 15:43 to about 16:10. Independent review from 16:11, review written 16:32. Corrections applied from 16:35. |
| Build | `sse-steam-1-7-104`, retail `1.7.104.0`, Steam build 24914197. Measured executable SHA-256 `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f` equals the asserted pin in [builds/target.json](../builds/target.json). |
| Principal function RVAs | `0x659d10` (`UpdateTimeManager`), `0xce36b0` (`BSTimer::Update`), `0xce3b10` (timer history size, GUESS), `0x658870` (`Main::OnIdle`), `0x14eec10` (working-block reset and base copy, GUESS), `0x14eeca0`, `0x14eece0` (modifier apply wrappers, GUESS), `0x15370b0`, `0x1537310` (modifier apply, GUESS), `0x14eed00` (normaliser wrapper, GUESS), `0x2a4270` (cross-fade clock step, GUESS), `0x153d120` (`ImageSpaceEffectHDR::Render`), `0x153d860` (`ImageSpaceEffectHDR::UpdateParams`), `0x153d830` (adapted-light release, GUESS), `0x153b680` (render-target setup, GUESS), `0x1583400` (`ImageSpaceEffectBlur::Setup`), `0x15836d0` (blur parameter update, GUESS), `0x1553b90` (`ImageSpaceEffect::Render`), `0x1554640` (texture bind, GUESS), `0x1555140` (sampler and view setter, GUESS), `0x1539f10` (`Main::RenderWorld`), `0x151f540` (`BSShaderAccumulator::RenderPostAccumulationPasses`), `0x411ec0` (`Sky::Update`), `0x4158d0`, `0x415660` (weather image-space blend and day-part selector, GUESS), `0x2bf340` (cell image-space block getter, GUESS). |
| Sources and revisions | The operator's pinned executable. Shader package member `shadersfx/shaders011.fxp`, SHA-256 `72cfc73eb0938d5949f0b3a8683722a33b671a34b41b750ba138de8d154c5fbc`. Groups 26, 29 to 36, 43 and 50 were decoded for the author run. The reviewer decoded groups 26, 29 to 31, 34, 36, 38, 42, 43, 49, 50, 52 and 56. The compiled INI defaults finding (#1052). Committed CrashLogger name and layout tables on `origin/main`. Earlier published findings (see "Relation to earlier findings"). |
| Source exposure | Mixed. Pinned native binary analysis, shipped shader bytecode decoded locally and offscreen, committed public tables and earlier published findings. The author run also read the project's own local reconstructions of a few functions. No statement here rests on them alone. **No value was read from any game plugin.** This file holds no plugin record value. No decompiler text and no disassembly appears below. No downstream or sibling implementation source was used. |
| Name provenance | Names marked `CRASHLOGGER_PDB(59818@2026.10.24)` come from the committed generated tables: `ImageSpaceEffectHDR::Render` and `::UpdateParams`, `ImageSpaceEffectBlur::Setup`, `ImageSpaceEffect::Render`, `Main::OnIdle`, `Main::Draw`, `Main::Render`, `Main::RenderWorld`, `Main::RenderFirstPersonView`, `Main::PostRenderCleanup`, `UpdateTimeManager`, `BSTimer::Update`, `TESImagespaceManager::PostProcessing`, `BSShaderAccumulator` member names, `NiCamera::RenderCameraView` and `::UpdateLensFlareEffect`, `Sky::Update`, `Script::SetImageSpace`, `PlayerCharacter::MoveToPositionInCell`, `BSExtraDataList::GetRoomImageSpace`, `RENDER_TARGET` enumerators, `TextureFilterMode`, `ImageSpaceTexture` and `ImageSpaceManager` field names. Other function labels are GUESS. Some table labels name only a piece of a larger function; this file says so where it matters. |
| Intended recipient | Skyrim Research department lead for boundary review under [docs/clean-room.md](../docs/clean-room.md). Proposed use: a follow-up on the exterior HDR path for the Mudcrab research list. Maintainer transfer decision pending. |

Addresses are RVAs for image base `0x140000000`. Code and data addresses use the same form. PS means pixel shader. `cbN[i]` means constant buffer N, float4 element i. **Verified** means re-read at the cited static source. **Inferred** means a deduction with assumptions. **Unverified** means the evidence leaves the claim open. The document contains facts and formulas only.

## Question and method

Seven questions, (a) to (g), in the Answer table. They follow from the open list of the exterior HDR path finding (#1059).

Method. The author run read the pinned image through a private local listing and through range reads of single functions. It read the committed name and layout tables. It decoded shipped image-space shaders locally and offscreen. The independent reviewer re-derived the claims. A third run applied the corrections and re-read key items. The changes to statements of #1059 are published as a dated amendment in that finding.

## Observations

### L01. What `T` measures (question a)

**Verified.** The HDR update reads `T` from the float at `0x20d68d4` (`0x153daf2`). That float is element 1 of four floats at `0x20d68d0`. The main update loop (`0x658d24–0x658d58`) refills the four floats through the function pointer at `0x33d3d08` (function `0x65f530`). For element 1 the function returns the float at `0x3275608` when the pause flag byte `0x32303b3` is 0. It returns 0.0 when the flag is nonzero. The flag byte equals `([0x219e5c0]+0x160 != 0)` and is stored at `0x658948`. The HDR update uses `fConstHDRAdaptTimerForMenu` (0.3, value field `0x20d7d68`) when the same field is nonzero (`0x153daf2–0x153db09`).

**Verified.** The float at `0x3275608` is member `+0x18` of an object at `0x32755f0`. The timer update `0xce36b0` stores it, and so does the multiplier setter `0xce3970`. I found no other direct store to the member. `UpdateTimeManager` (`0x659d10`) reads the system clock (`0xce8430`), subtracts the start time at `0x32755f8` and divides by the ticks-per-millisecond float at `0x32755e0` (image value 0.0, so it is set at run time). It passes the result in milliseconds to `0xce36b0` (`0x659d80`). The timer update then works as follows.

| Step | Rule |
|---|---|
| Raw delta | `Δms` = the new time minus the last stored time. `Δs = Δms × 0.001` (float at `0x1b5bdc4`). If `Δms` is above 166.67 (`0x1a220f8`), the delta is set to the float 0.16667 (`0x1869dd8`), which is 1/6 s. |
| Paused timer | If the pause count at `+0x34` is nonzero, `+0x18` is set to 0. |
| Fixed step | If the float at `+0x10` is nonzero, the delta is that many milliseconds × 0.001 instead of the measured time (the fraction of the millisecond count is carried in `+0x14`). When `iFPSClamp:General` (value field `0x20b5b90`, compiled default 0) is 1 to 199, the code at `0x6559a6–0x6559ce` stores `1000 / iFPSClamp` in `+0x10`. At the default 0 this site stores nothing, and the field is 0 in the image. So the measured time is used. A second writer sets the same field from `iFPS:CameraPath` (value field `0x20b5da0`) inside `Main::Render` when the camera-path recording flag (byte `0x3230739`) toggles on, and to 0 when it toggles off (`0x656b3c`, `0x656b46`). The code at `0x65a8ba` to `0x65b154` does the same. It is a recording path and is not part of an ordinary frame. After a toggle off, the `iFPSClamp` step is gone. |
| History | If the history size byte at `+0x38` is 3 or more, the delta joins a ring buffer of that many floats (index byte `+0x39`). `UpdateTimeManager` sets the size through `0xce3b10`: `iUnstableFrameTimeHistorySize:Display` (value field `0x20b5848`, compiled default 8) when `bCompensateUnstableFrameTime:Display` (value field `0x20b5830`, compiled default 1) is set, else 0. The setup accepts 3 to 254. The ring is prefilled with 0.016 s (`0x3c83126f`). |
| Smoothed value | `+0x18 = (Σ ring − min(M, 0.05) − m) / (N − 2)`, with `M` the largest and `m` the smallest ring entry. The cap of 0.05 on the removed maximum is the float at `0x17ed69c`, read at `0xce38e3`. So a spike above 0.05 s is only partly removed. The purpose of the cap is unknown. |
| Scaling | `+0x1c` = the smoothed value. `+0x18` = the smoothed value × the float at `0x20ccac8` (image value 1.0). The function at `0xce3970` stores a target at `0x20ccacc`. The function at `0xce39d0`, which `UpdateTimeManager` calls when the pause flag byte is 0, multiplies `0x20ccac8` by `1 + 0.02` or `1 − 0.02` per call (`0x20ccad0` = 0.02) toward the target and stops at it. Which game feature drives the target was not traced. |

So the value `T` that the adapt formula uses (`E = 30 × T`) is **a time in seconds**: the smoothed real frame time × the time multiplier. The unit follows from the `× 0.001` conversion from milliseconds. The factor 30 makes the rate formulas count in units of 1/30 s. **Inferred:** the adapt speed is therefore independent of the frame rate, apart from the `1/256` step floor, which acts once per frame.

**Verified.** `UpdateTimeManager` has two call sites. A local "not paused" flag in `Main::OnIdle` is set when the pause counter is 0 and a byte at `+0x16` of an object that the function holds is 0 (`0x658940–0x65895f`). The flag is written only once and is not changed before either call site. The call at `0x658d8f` runs when the flag is off. The call at `0x65932a` runs when it is on, after `Main::Render` (`0x659319`). So the timer advances once per frame. The refill of `T` precedes the call in both paths. `Main::Render` in frame N therefore reads the `T` that the call of the previous frame produced.

**Verified.** Other readers of `0x3275608` include the modifier clock `0x31a5810`, which grows by it in each unpaused frame (`0x658bcd`), and the room cross-fade timer (`0x412062`). The cross-fade clock step `0x2a4270` reads `T` from `0x20d68d4`. So IMAD durations and room fades also use this time base.

**Confidence: high** for the unit and the formulas. **Medium** for the meaning of the pause counter (a field of a singleton at `0x219e5c0`; its role is inferred from use). What would change it: a runtime read of `0x20d68d4` in a frame.

### L02. Loops that store 0.0 (question a)

**Verified.** The refill code at `0x2c65e6` (function `0x2c63f0`) and at `0x2c689c` (function `0x2c67c0`) passes the flag 1, so element 1 becomes 0.0. Both functions call `Main::Render` (`0x2c65da` and `0x2c6890`) and refill the floats after that call. `Main::Render` has four call sites: these two, the main frame (`0x659319`) and a call at `0x1a2b13` (code that the table labels as a cell-load piece). The last one does not refill `T`. In each of the two loops the first render sees the value from the earlier refill. Only renders after a refill see 0.0, or 0.3 under the pause counter. With `T = 0` both adapt rates are 0, and each channel moves only by the `1/256` floor per adapt draw.

**Unverified.** What these two functions are for, and whether the HDR stage runs in them.

**Confidence: high** for the stores. **Low** for what the functions are.

### L03. Frame order inside one frame (question b)

**Verified.** `Main::OnIdle` (`0x658870`) runs this sequence. A menu test (`0x658ba8–0x658bb1`) can skip rows 1 to 5.

| Order | Address | Action |
|---|---|---|
| 1 | `0x658bb7` | `0x2a4270` advances the cross-fade clock `0x31a57dc` by `T` and updates the pending modifier fade. |
| 2 | `0x658bc3` | `0x14eec10` (manager `+0xc8` is the working block): clear the modifier accumulators (`0x1536f50`), copy the override block (manager `+0xb0`) or else the base block (`+0xa8`) into the working block (`0x1536f80`; it premultiplies the tint RGB by the tint amount and keeps the amount at block `+0x98`), then clear the accumulators again. |
| 3 | `0x658bcd` | If the "not paused" flag is on, add the float at `0x3275608` to the modifier clock at `0x31a5810`. |
| 4 | `0x658be5–0x658cef` | Loop over the modifier instance list at `[0x32303b8]+0x108`. For each instance, a true result from virtual `+0x128` means that the instance is finished, and its list node is removed. Otherwise, if byte `0x207b7e0` is nonzero (image value 1), virtual `+0x130` applies the instance. The IMAD form instance applies through `0x2a6fb0`, which calls the wrapper `0x14eeca0`. That wrapper runs `0x15370b0` (HDR and cinematic floats, tint) and then `0x1537310` (fade). The depth-of-field and radial-blur instances reach `0x14eece0` (fade only). |
| 5 | `0x658cf6` | `0x14eed00` calls the normaliser `0x1536ff0`. |
| 6 | `0x658d24–0x658d58` | Refill the four timer floats (L01). |
| 7 | `0x659319` | `Main::Render` (`0x6565b0`), in every frame that reaches this point. |
| 8 | `0x65932a`, or `0x658d8f` | `UpdateTimeManager`. With the "not paused" flag on, it runs after `Main::Render` (`0x65932a`). With the flag off, it runs earlier, right after the refill and before `Main::Render` (`0x658d8f`), and not a second time. |

The refill (row 6) always precedes `UpdateTimeManager`, so `Main::Render` reads the `T` that the previous frame's `UpdateTimeManager` produced.

**Verified.** The working block is rebuilt each frame by rows 2, 4 and 5. The clear in row 2 removes the fade and tint sums of the previous frame. So with no modifier, the working block holds the base block, and the normaliser restores the tint RGB (#1059 G08).

**Verified.** `Main::Render` reaches the HDR stage as follows. `Main::Draw` calls the stage function `0x153ac00` at `0x6578d1` (only if byte `0x33d3d12` and byte `0x20d6b7c` are nonzero). That function calls `TESImagespaceManager::PostProcessing` (`0x14edbf0`) at `0x153ade7` with input target 1 (`kMAIN`). `PostProcessing` renders the HDR effect through `0x14ee060`, which calls the effect's `Render` (virtual `+0x8`). The HDR `Render` calls `UpdateParams` (virtual `+0x38`, `0x153d860`) near its start (`0x153d1bb`) when the effect's enable byte is set. So the HDR update reads the working block after rows 2 to 5 of the same frame.

**Unverified.** `Sky::Update` is not called directly from `Main::OnIdle`. The thunk at `0x65a210` jumps to it (`0x65a243`) and is entered from job code (`0x6e5d27`), so its order against row 2 was not fixed by this reading. The weather block at `0x31df470` that row 2 copies may therefore be one frame old.

**Verified.** The same copy and normaliser pair also appears at `0x65a275` and `0x65a3b2` (function `0x65a250`), at `0x964b2c` and `0x964b39`, at `0x98a153` and `0x98a15f`, and at `0x9a0548`, `0x9a0554` and `0x9a06ca`. **Inferred:** these are other render contexts, such as menus and 3D previews.

**Confidence: high** for the order inside `Main::OnIdle` and for the render path. The sky update order is open.

### L04. Values the HDR update reads (question b)

**Verified.** The update reads the working block (manager `+0xc8`) and the settings listed in #1059 G05 and G06. The offsets in this group are manager offsets. The block starts at manager `+0xc8`, so a struct offset of #1059 G07 is the offset here minus `0xc8` (EyeAdaptSpeed: struct `0x00` = manager `+0xc8`; BloomBlurRadius: `0x04` = `+0xcc`; ReceiveBloomThreshold: `0x10` = `+0xd8`). With that layout: `+0xc8` EyeAdaptSpeed, `+0xcc` BloomBlurRadius, `+0xd0` BloomThreshold, `+0xd4` BloomScale, `+0xd8` ReceiveBloomThreshold, `+0xdc` White, `+0xe8` EyeAdaptStrength, `+0xec`, `+0xf0`, `+0xf4` saturation, brightness and contrast, `+0xf8` tint amount, `+0xfc` to `+0x104` tint RGB, `+0x118` fade amount, `+0x11c` to `+0x124` fade RGB. The HDR render reads `+0xcc`, `+0xd0`, `+0xd4` and `+0x118` (the fade test) when it picks the blur and the tonemap shader. The values of these fields for a given scene come from the selection rules of L09.

**Confidence: high.**

### L05. First frame, `ClearAdaptedLight` and the adapt draw (question c)

**Verified.** The adapted handle is an `ImageSpaceTexture` object at `0x20d7608` (community layout: texture pointer `+0`, render-target id `+8`, a second index `+0xc`, filter `+0x10`, address mode `+0x14`). The release function `0x15550d0` drops the texture reference, sets id and index to −1 and sets filter and address mode to 0.

**Verified.** First frame. The adapt step is at `0x153d500`. If the id at `0x20d7610` is below 0, the code skips the adapt draw. In that case the final luminance step was drawn as usual, and the code assigns the handle to its result (`0x153d509–0x153d5fd`). So in that frame the adapted pair is the final luminance target of the chain, which holds `(n, n, n)` per texel (the 16-tap luminance step writes the first channel to all three, #1059 G04). The tonemap of the same frame samples it as `t2`. Hence `A.x = A.y = n` per texel, and the ratio `A.y / A.x` is 1 for `n > 0`. For `n = 0` (a fully black chain result) the tonemap computes `L × 0 / 0`. No smoothing applies in that frame.

**Verified.** Later frames. The chain loop (`0x153d350–0x153d4fb`) continues while either size is above the limit `n` of #1059 G03. In the iteration that reaches `n × n` it picks the target id as the next id plus 2 times a flag that it toggles each frame (flag at `0x3436360`, `0x153d3b6–0x153d3c2`), so the final level alternates between two targets of the same size. If the adapted id is 0 or higher at that point, the draw of the final 16-tap luminance step is skipped (`0x153d3d6–0x153d3f0`). The adapt draw (`0x153d500–0x153d5f1`, shader slot 8) takes its place. It has the level above the final one as `t0`, the previous adapted handle as `t1`, and the new alternate final target as output. After the draw the adapted handle is assigned that output. So the adapt shader does the last 16-tap step itself, and the draw never reads and writes one target.

**Verified.** Ways the adapted handle gets released (id −1). This list comes from a scan of the direct callers of `0x153d830`, of the request byte `0x343635f` and of the release calls named here. Indirect paths were not searched.

| Trigger | Evidence |
|---|---|
| Console command `ClearAdaptedLight` | The handler `0x377920` calls `0x153d830`, which releases the handle and clears the request byte. |
| Request byte `0x343635f` set to 1 | Near the start of `ImageSpaceEffectHDR::Render` (`0x153d1c1–0x153d1df`) the handle is released and the byte cleared. The writer of the byte is at `0x412024` in `Sky::Update` (`0x411ec0`): it runs when bit 8 of the sky flag word at `+0x1dc` is set, and it clears that bit. Writers of that sky bit were found at `0x411666`, `0x6231a4`, `0x62629d` and `0x743acd` (their callers include save-load, player-move and cell-grid load paths). **Inferred:** the bit means "jump to the new weather and image space now". Its meaning was not traced. |
| Render-target rebuild | `0x153b680` releases the handle at its start (`0x153b69f`), so a resolution or format change resets it. |
| Virtual slot 3 of the HDR effect | `0x153dd00` releases it. **Unverified:** who calls it. |
| `UpdateParams` | `0x153d86f` releases it if byte `0x343635d` is nonzero. That byte has no store in the executable, so this does not run. |
| Other callers of `0x153d830` | `0x964b3f`, `0x967f97`, `0x98a164` and `0x99c030`. The table labels there name only code pieces and do not identify them. **Inferred:** menu and UI render code, so these menu renders reset the adapted light too. |
| `Main::PostRenderCleanup` | `0x153a5da` calls `0x153d830` when byte `0x33d3d30` is nonzero. The byte is stored from `0x1010890`, a stub that returns 0, so this does not run in this build. |

**Confidence: high** for the first-frame behaviour, the clear behaviour and the adapt draw.

### L06. Adapted pair size and filters (question c)

**Verified.** The render-target setup `0x153b680` builds the chain targets from the render size `W × H` (dwords at `0x33363c4` and `0x33363c8`). Target 26 has size `max(ceil(W/4), 2) × max(ceil(H/4), 2)`. Each next target divides again by 4 with the same minimum 2 (`0x153c1b3–0x153c2ab`). The loop creates targets until one is 2 by 2, and it creates a duplicate of that level at id +2 (`0x153c24c`). For 1920 by 1080 the sizes are 480×270, 120×68, 30×17, 8×5 and 2×2. After the 2 by 2 level the setup creates a 1 by 1 target (same format) and its alternate at +2 (`0x153c2b0–0x153c318`). The render loop uses the same divide rule with the limit `n`. At the default settings `n` is 2, and the adapted pair is **2 by 2 texels**. With `bUseMultipleLuminanceReferences` 0, or byte `0x343635d` nonzero (it has no store in this executable), `n` is 1 and the adapted texture is 1 by 1: one value for the whole screen.

**Inferred.** The last 16-tap step (the adapt shader when the handle exists) uses offsets of −1.5, −0.5, 0.5 and 1.5 source texels (item 5 of the 2026-11-25 amendment to #1059). A destination texel therefore averages a 4 by 4 block of source texels centred on the destination texel centre. For the 2×2 target this is about one quarter of the screen per texel. The exact area depends on the source size (for example 8×5). So the four values are four coarse regional references, not one global average.

**Verified.** The bind function `0x1554640(effect, slot, texture, flag)` stores the texture pointer and writes `flag` into the texture's filter field (`0x1555120`). The draw-time function `0x1555140` copies the filter and address mode of each bound texture into the sampler state arrays at `0x20cfcfc` and `0x20cfcbc`, and sets the view. `TextureFilterMode` (community enum): 0 nearest, 1 bilinear, 2 trilinear, 3 anisotropic, 4 comparison bilinear. The flags in the HDR render:

| Draw | Slot (register) | Texture | Flag |
|---|---|---|---|
| Slot-4 step (`ISHDRDownSample4`) | 1 (`t0`) | Effect input colour | 1 (bilinear) |
| First luminance step (slot 5) | 1 (`t0`) | `kHDR_DOWNSAMPLE0` | 1 (bilinear) |
| Later luminance steps (slot 6) | 1 (`t0`) | Previous target | 0 (nearest) |
| Adapt draw (slot 8) | 1 (`t0`) | Chain level above the final one | 1 (bilinear) |
| Adapt draw | 2 (`t1`) | Previous adapted pair | 0 (nearest) |
| Tonemap | 1 (`t0`) | `kHDR_BLOOM` | 1 (bilinear) |
| Tonemap | 2 (`t1`) | Scene colour | 0 (nearest) |
| Tonemap | 3 (`t2`) | Adapted pair | 1 (bilinear) |

So the tonemap binds the adapted pair with the bilinear flag and samples it at the screen coordinate. **Inferred (medium):** the bind-time flags are the draw-time filters. The per-pass function `0x1553cb0` can overwrite the filters of an effect's inputs from a per-pass table. The HDR setup `0x153cab0` builds no such table (it makes no call to `0x1554270` or `0x1554310`). For a coordinate below 0.25 or above 0.75 on an axis, a bilinear 2-texel axis gives a constant value. Between 0.25 and 0.75 it interpolates between the two texel centres. The address mode is the object field `+0x14`, which is 0 (clamp on both axes) in the default state and is copied on assignment, so clamp is **inferred**.

**Confidence: high** for sizes and filter flags. **Medium** for the address mode and for the regional-average reading.

### L07. Draws after the SAO/fog composite (question d)

**Verified.** `Main::RenderWorld` (`0x1539f10`) first renders the scene with the main accumulator (pointer at `0x3436230`) and unbinds the render targets. It calls the composite function `0x1541f40` twice: at `0x153a102` (input 1, output 1, with byte `0x343639c` = 0) and at `0x153a1ca` (input 113 `kSNOW_SWAP`, output 1, with the byte = 1). The first call generates the ambient occlusion and does not reach the composite code (#1077 G04). The second call is the composite of the exterior haze trace (#1077) and of the live-`k` finding (#1121). After it, in the same function:

| Address | Call | What it does |
|---|---|---|
| `0x153a1ef` | `0x1515360` with the main accumulator and a flags value `0x40`, plus 1 if byte `0x20d6d10` is nonzero | Calls virtual `+0x158` of the accumulator: `BSShaderAccumulator::FinishAccumulatingPostResolveDepth` (`0x151ef00`). It calls `RenderPostAccumulationPasses` (`0x151f540`). That function calls `RenderEffects` (`0x151fb80`) twice (`0x151f591`, `0x151fa83`) with alpha-group sort, depth and sorted-pass steps. It also appends sorted alpha-group passes (`0x15617d0`), renders batches with the pass masks `0x5c006074`, `0x5c000071`, `0x5c006071` and `0x5c006072`, clears render-target views and reaches a dynamic-resolution upsample step (`0x151f6fe`). It binds a target with id 85 (`kTEMPORAL_AA_MASK`) at `0x151f9e2`. **Unverified:** which of these sub-passes write `kMAIN`. |
| `0x153a320` | `NiCamera::RenderCameraView` (`0x1515230`) | Renders a second accumulator (pointer at `0x3436250`, mode value 23, set at `0x651ed2`) with the camera of an object at `0x31a5000`. That object is built at `0x24c550` with a camera and a node. **Unverified:** what it draws. |

In `Main::Draw`, after `RenderWorld` returns (call at `0x6576be`): `Main::RenderFirstPersonView` (`0x1537b10`, call at `0x6577d1`) draws the first-person view with its own depth range through `RenderFirstPersonViewPasses` (`0x1520a10`). Then `0x153ac00` (call at `0x6578d1`) runs. Before it calls `PostProcessing`, it runs the volumetric-lighting effects (`0x153df60` and `0x15403f0`) only if byte `0x3435f44` and a manager object field are set (the image value of the byte is 0). It also calls `0x14edfd0` (not traced) and `NiCamera::UpdateLensFlareEffect` (`0x152ea20`).

**Verified.** The composite pixel shaders (trailing records 49, 51 and 53 of the shader package) end with a saturate on all four channels. This agrees with the exterior haze trace (#1077 G05). No engine saturate on the later draws was found. The Lighting PS output is bent by the soft limiter of #1059 G12, which for `k_r` = 5/6 and no fog gives `(1 − k_r) × L + 1` above `L = 1.2`. The default target format is `R11G11B10_FLOAT` (#1059 G02), which holds unsigned floats well above 1.

**Inferred.** The post-pass draws depth-sorted alpha passes, so they are blended. The first-person view mixes opaque and alpha geometry. So these draws can add colour to `kMAIN` after the composite, and the tonemap scene input can exceed 1. A reading that the composite bounds the whole tonemap input to [0,1] is true only for pixels that no later draw changed.

**Unverified.** The blend state of each pass, the meaning of the pass masks, the render-target ids of the post-pass sub-passes, and the target of the first-person draws.

**Confidence: high** for the order and the saturate. **Medium** for "alpha passes are blended". **Low** for blend modes and render-target ids.

### L08. Native names (question e)

**Verified.** Tonemap texture roles (bind calls at `0x153d73c–0x153d789`, slot `k` feeds `t(k−1)`): `t0` = `kHDR_BLOOM` (handle made from id 24 at `0x153d1e6`), `t1` = element 1 of the effect input array, `t2` = the handle at `0x20d7608`.

**Verified.** `0x14ee060(manager, slot, inputId, outputId)` fills the input array of an effect: element 0 is the output (id `outputId`) and element 1 is the input (id `inputId`). `PostProcessing` is called at `0x153ade7` with input id 1 (`kMAIN`). The earlier effects (the slots among 0 to 7 that report active through virtual `+0x30`; slots 3 to 7 are deferred when the manager flag `usesLDR` is set) swap the input id and a temporary id from manager `+0x60` between them. So `t1` is `kMAIN` when no earlier slot is active, otherwise the output target of the last earlier slot. The HDR output is `kIMAGESPACE_TEMP_COPY` (41) when later effects exist, otherwise the output id passed in.

**Verified.** HDR-related targets (community `RENDER_TARGET` enumerators): 22 `kHDR_BLURSWAP`, 23 `kLDR_BLURSWAP`, 24 `kHDR_BLOOM`, 25 `kLDR_DOWNSAMPLE0`, 26 to 39 `kHDR_DOWNSAMPLE0` to `kHDR_DOWNSAMPLE13`. The targets 22, 23 and 24 are created with size `(W >> 2) × (H >> 2)` (`0x153b70e–0x153b848`). Target 26 has `ceil(W/4)` by `ceil(H/4)` (L06). So the blur-swap and bloom targets can be one texel smaller than `kHDR_DOWNSAMPLE0` when the render size is not a multiple of 4. Targets 22, 24 and the `kHDR_DOWNSAMPLE` chain take the HDR format of the setup (26 or 10, #1059 G02). Target 23 (`kLDR_BLURSWAP`) has the fixed format value 28 (`0x153b848–0x153b84b`). The format of target 25 was not read.

**Confidence: high** for the roles and ids. **Medium** for `t1` when earlier slots are active (their identity was not resolved).

### L09. Which image space applies (question f)

**Verified.** The manager keeps four block pointers: current base (`+0xa8`), override (`+0xb0`), underwater (`+0xb8`) and console data (`+0xc0`) (community layout). The per-frame copy (L03, row 2) uses `+0xb0` if it is not null, else `+0xa8`. Setters: `0x14eeaf0` (`+0xa8`), `0x14eeb00` (`+0xb0`), `0x14eeb10` (`+0xb8`) and `0x14eeb20` (console data; it installs a copy as both `+0xc0` and `+0xb0`).

**Verified.** The callers that set `+0xa8`: `Sky::Update` (`0x4121d2`), `PlayerCharacter::MoveToPositionInCell` (`0x75f44d–0x75f45c`: it sets the base to the block of the new cell on a move into a cell), and the reset function `0x2a6af0` (it sets the override to null and the base to the manager's default block at `0x33d40b0`). The callers that set `+0xb0` include that reset function, `Script::SetImageSpace` (`0x360ea0`) and functions between `0x9644d0` and `0x9a06be` (not identified). The callers of the underwater setter are at `0x1a6540` and `0x5257f0` (not identified).

**Verified.** The getter `0x2bf340(cell)` returns the block pointer of a cell. It uses the 16-bit cell flag word at `cell+0x40`.

| Cell state | Returned block |
|---|---|
| Bit 0 set and bit 8 clear (interior case) | `form +0x20` of the image space found by extra-data type `0x56` in the cell's extra-data list (`cell+0x48`, `0x16fa80`). If none is found, of the form with id `0x167` (`0x2bf390`). |
| Bit 0 set and bit 8 set | The weather block `0x31df470`. |
| Bit 0 clear (exterior case) | If the world-space pointer (`cell+0x128`) is non-null and its field at `+0x160` is nonzero: the extra-data lookup of the first row. Otherwise the weather block `0x31df470`. |

**Inferred (medium).** The world-space field at `+0x160` is a lighting template. It is a form pointer. It is stored at `0x30c7da` only if the looked-up form has type byte 108 (`0x30c7d4`), the lighting-template form type. The generated layout also puts a `BGSLightingTemplate*` there. The name rests on the type number and the layout.

The community name of extra-data type `0x56` is `ExtraCellImageSpace` (the link is **inferred**). The form id `0x167` is an immediate compare value in the executable. It is the engine's fallback image space. Which record it is, and its values, are plugin data and were not read.

**Verified.** Room image spaces. `Sky::Update` (`0x4120bd–0x4121d2`) takes the room image space (extra-data type `0x77`, `BSExtraDataList::GetRoomImageSpace` `0x16bbb0`) of the previous and of the current room reference. A missing side falls back to the cell block. It cross-fades with `m = s²(3 − 2s)`, where `s = clamp(elapsed / D, 0, 1)`. The elapsed time grows by the float at `0x3275608` per frame. `D` is the float at `0x209e7c8` (image value 3.0; the setting name was not resolved). While the fade value is above 0, the blend `0x1536c70` writes the result into `0x31df470` and the base pointer is set to that buffer. Otherwise the base is set to the second block. When neither room has an image space and no local reset flag is set, this code does not set the base. The base then keeps its last value.

**Verified.** The weather block at `0x31df470` is rebuilt by `0x4158d0` (#1059 G08): it clears the block and adds up to four IMGS blocks with the weights `q×m`, `(1−q)×m`, `q×(1−m)` and `(1−q)×(1−m)`. The IMGS of a weather for day part `i` is the entry at weather `+0x7d8 + 8i` (index 0 to 3). When the entry is null, the code uses the form with id `0x167`. The selector `0x415660` handles the sky mode at `[sky+0x1bc]`: modes 1 and 2 return without a blend, mode 0 copies the block of the form `0x167`, and other values use the day-part blend. `m` is `[sky+0x1b8]`, and the two weathers are `[sky+0x48]` and `[sky+0x50]`. The interior-case block uses no day part.

**Unverified.** Which IMSP index maps to which day-part name, the numeric `q`, and the weathers and IMGS of any world space. These are plugin data or were not re-derived.

**Confidence: high** for the cell-block rule and the base setters. **Medium** for the name of the world-space field and for the interaction with the unresolved sky update order.

### L10. Bloom chain (question g)

**Verified.** The HDR render picks the bloom blur effect at index `23 + j` of the manager effect array, with `j = clamp(trunc(BloomBlurRadius) − 1, 0, 6)` (`0x153d610–0x153d689`). The manager setup (`0x14ef5b9–0x14ef783`) creates three families of `ImageSpaceEffectBlur` objects (constructor `0x15832e0`) in a loop over `s` = 23 to 29: at index `s − 14` (plain, HDR), at index `s − 7` (non-HDR) and at index `s` (bright-pass). Each object gets the size index `k = s − 22` (1 to 7) through virtual `+0x50` (`0x1584ce0`, stores `+0x90`) and its flags through virtual `+0x58` (`0x1584cc0`, byte `+0x94`) and `+0x60` (`0x1584cd0`, byte `+0x95`). So the bloom effect at `23 + j` has `k = j + 1`, bright-pass flag 1 and HDR flag 1. The render also writes `float(k)` to `0x3698f10` before the call (`0x153d67a`). So **`k = clamp(trunc(BloomBlurRadius), 1, 7)`**. A radius below 2 gives `k` = 1 (3 taps). A radius of 7 or more gives `k` = 7 (15 taps).

**Verified.** `ImageSpaceEffectBlur::Setup` (`0x1583400`) wires two passes. With the bright-pass flag set, the shader index of pass 0 is `(k − 1) + 79`, so `ISBrightPassBlur{3,5,...,15}`. With the HDR flag set, the shader of pass 1 is `(k − 1) + 65` (`ISBlur{2k+1}`). The input array of the effect is `[0]` = `kHDR_BLOOM` (24), `[1]` = a copy of the handle `kHDR_DOWNSAMPLE0` (26), `[2]` = `kHDR_BLURSWAP` (22), `[3]` = the adapted pair. Pass 0 reads input 1 and writes input 2. Pass 1 reads input 2 and writes input 0 (**inferred** from the argument roles of the wiring calls `0x1554310`, `0x1554270` and `0x1554150`).

| Pass | Shader | Reads | Writes | Offset direction |
|---|---|---|---|---|
| 0 | `ISBrightPassBlur(2k+1)` | `kHDR_DOWNSAMPLE0` | `kHDR_BLURSWAP` | Vertical: `(0, u/H)` |
| 1 | `ISBlur(2k+1)` | `kHDR_BLURSWAP` | `kHDR_BLOOM` | Horizontal: `(u/W, 0)` |

In this table `W` and `H` are the width and height of input 2 (`kHDR_BLURSWAP`), read by `0x1555030`. There is no mip pyramid and no further level. All three targets have about 1/4 of the render size per axis (L08).

**Verified (arithmetic of the parameter update `0x15836d0`).** For tap `t` from 0 to 14, with `u = t − 7`, each constant array entry is `(offset.x, offset.y, weight, 0)`. For pass 0 the entry is `(0, u/H, w, 0)`. For pass 1 it is `(u/W, 0, w, 0)`. The upload copies the entries `7 − k` to `7 + k` (`2k + 1` entries, `16 × (2k + 1)` bytes, through `0x152b1b0`) into `cb2[3..]`. The update interpolates between two neighbouring weight tables with the factor `1 + G − k`, where `G` is the float at `0x3698f10`. For the bloom effect `G = k`, so the factor is 1 and the weight is table `k` exactly. Other effects that share this function can set `G` to a fraction.

**Verified.** The static weight tables sit at `0x20d7640 + (k − 1) × 0xf0` (15 entries of 16 bytes, weight in the third float). No store into them was found. All seven tables are symmetric, zero beyond `±k`, and sum to 1 within `1e-6` (table 1: 0.9999992). The nonzero weights are in the table below the Answer table. The tables look like truncated Gaussian weights. That is an interpretation.

**Verified.** Pixel arithmetic, from the decoded `ISBrightPassBlur3` PS (group 50) and `ISBlur3` PS (group 36). The larger variants differ in the tap count only: **verified** for groups 38, 42, 52 and 56 (loop bound and declared size of `cb2` only), **inferred** for groups 37, 39 to 41, 51 and 53 to 55. `k_r` is the global at `0x20d694c`. Its value in an ordinary frame is 0.8333333. The console command `sfbr` changes it. The interface draw sets it to 1.0 for its own duration only (live-`k` finding, #1121). `T_b` is `BloomThreshold + fGlobalBloomThresholdBoost` (or `fGlobalMapBloomThresholdBoost` when byte `0x343635e` is set; the sum is stored at `0x20d9544`). `S_b` is `BloomScale` (stored at `0x20d9548`).

| Pass | Formula, per colour channel |
|---|---|
| 0 | `out0 = k_r × S_b × Σ_i w_i × max(c_i / k_r − T_b, 0)`, with `c_i` the sample at `uv + (0, u_i/H)`. |
| 1 | `out1 = k_r × Σ_j w_j × (out0_j / k_r)`, with the sample at `uv + (u_j/W, 0)`. So `k_r` cancels. |

So the bloom colour is `b = k_r × S_b × Σ_j w_j Σ_i w_i max(c_ji / k_r − T_b, 0)`: a separable weighted sum with the threshold applied per tap and per channel before the weights. The output alpha of pass 0 is the luminance of the adapted texture sample divided by `k_r`. The shader does not use that sample for the colour. **Inferred:** the tonemap does not use this alpha (bloom enters through its RGB, #1059 G05 step 3).

**Verified.** The constants: `cb2[0]` = `(T_b, S_b, 0, 0)` in the bright pass. `cb2[1]` = `(flag, 0, k_r, 1/k_r)`, where `flag` is 1.0 when byte `+0x88` of the effect is 0, and 0.0 otherwise. The HDR render sets that byte to 0 around the bloom call. So the pixel shader takes the plain `uv + offset` path, not the dynamic-resolution clamp path.

**Inferred (medium).** Both blur passes fetch their textures with filter flag 0 (nearest). The per-pass input table stores the filter next to each input index (`0x1554270`, `0x1554310`; the setup passes 0), and the draw code (`0x1553d0e–0x1553d6e`) applies it. With equal source and target size and integer offsets, this is an exact texel fetch per tap. In pass 0 the source (`kHDR_DOWNSAMPLE0`) can differ from the target size by one texel (L08).

**Verified.** The bloom enters the tonemap as in #1059 G05 step 3: `colour = c × Lt / L + b × saturate(cb2[2].x − Lt)`, with `cb2[2].x` = `ReceiveBloomThreshold`. `t0` is bound with the bilinear flag (L06), so the bloom is upsampled from `kHDR_BLOOM` with a bilinear filter.

**Confidence: high** for the structure, the index math and the tables. **Medium** for the filter statement. What would change it: a capture of the sampler state during the bloom passes.

## Interpretation and alternatives

**Verified (arithmetic and structure only).** The HDR adapt rate counts in units of 1/30 s of the time multiplier × the smoothed real frame time. The bloom is `k_r × BloomScale` × a separable Gaussian-like blur (vertical, then horizontal) of the per-channel thresholded quarter-size downsample, sampled bilinearly in the tonemap. The adapted exposure reference is a 2×2 bilinear field, not one number, at the default setting, and one value with `bUseMultipleLuminanceReferences` 0. The first frame after a reset has no lag.

**Alternative for L06.** If the 2×2 texels are not regional averages (for example if the last step covers the whole source for each texel), the four values would be equal and the field would be flat. The tap geometry argues against that. A capture of the adapted texture would test it.

## Relation to earlier findings

- **#1059** ([exterior HDR path](exterior-hdr-path-retail-facts.md)), with its amendments. This finding answers several items of its open list: the meaning of `T`, the first-frame adapted texture, the names of the tonemap textures, the frame order of the modifier apply and normaliser, the bloom blur and the adapted texture size. It also corrects one statement of G02 on the sizes of targets 22 and 24. All changes to #1059 are in its amendment dated 2026-11-25, which also publishes the items of a second review of that finding. The 2026-11-24 tree LOD amendment is not affected.
- **#1121** ([live k and composite target](live-k-composite-target-retail-facts.md)): the composite call, its saturate and the `kMAIN` target agree with L07. L10 uses the same global `k`. No correction.
- **#1258** (interior point-light look, an open pull request at the time of writing): its composite saturate, its statement that later draws are not covered by that bound, and its interior image-space source agree with L07 and L09. L09 adds two conditions: `Sky::Update` sets the base only under the room or reset-flag conditions, and the world-space field that selects the cell image space in an exterior is read as a lighting template. This finding makes no correction to it.
- **#1077** ([exterior haze trace](exterior-haze-trace-retail-facts.md)): the composite of L07 is the one it describes. No correction.
- **#1052** ([compiled INI defaults](compiled-ini-defaults-retail-facts.md)): the setting values used here agree with it where it lists them.

## Negative results and limitations

- **Unverified.** The call order of the sky update against the frame-start copy (L03).
- **Unverified.** The blend state, pass masks and targets of each post-composite pass, and what the second accumulator draws (L07).
- **Unverified.** The meaning of sky flag bit 8, and who calls virtual slot 3 of the HDR effect (L05).
- **Unverified.** The identity of the functions that call `0x153d830` outside the console handler (L05).
- **Unverified.** The value of `T` that the first render sees in each of the two loops of L02, and what those loops are for.
- **Unverified.** The constants `cb12[43]` and `cb12[44]` (dynamic resolution).
- **Unverified.** The shader forms of groups 37, 39 to 41, 51 and 53 to 55 (L10).
- **Not read.** Game plugin data: IMGS, IMAD and weather values, the identity of the form with id `0x167`, and the meaning of the IMSP indices. This file holds none.
- **Static only.** No runtime trace and no visual claim. A frame capture or a runtime watch would settle the open points on sampler states, blend states and render targets.
- Caller lists come from searches for direct calls and direct address uses. Calls through pointers and aliased writes can be missed.

## Independent review

Reviewer: a separate fresh-context run of `claude-sonnet-5-5`. The reviewer is not the author. A Sol run was not available because of a usage limit. **Disclosure:** before it started, the reviewer read a memory note that summarised the author's claims. It used the note as a pointer to the topic and re-derived each item from the binary. Its agreement on points that the note states is slightly weaker than a fully blind result. It saved its independent results before it opened the text under review. It did not open the author's work directory before that.

The reviewer checked about 95 statements that carry an address, a number or a formula. 14 needed a change, of which 5 were substantive. No headline answer (a) to (g) was reversed.

Verdict: **7 confirmed, 5 corrected, 1 unverified and cut.** The groups L11 and "correction" of the reviewed text are now the 2026-11-25 amendment to #1059.

| Group of the reviewed text | Verdict | Main point |
|---|---|---|
| L01 Time base | Confirmed | Three additions: the 0.05 cap on the removed maximum, the camera-path fixed step, the one-frame lag. |
| L02 Loops that store 0.0 | Confirmed | A further `Main::Render` caller does no refill. |
| L03 Frame order | Corrected | The table put `UpdateTimeManager` before `Main::Render`. That is the order only when the "not paused" flag is off. |
| L04 Values read | Confirmed | The offsets are manager offsets. |
| L05 First frame and adapt draw | Corrected | The adapt draw replaces the last luminance draw, which resolves an item that the author left open. More release callers. The ratio is 1 only for `n > 0`. |
| L06 Size and filters | Corrected | A 1 by 1 target exists for the single-reference mode. |
| L07 Later draws | Confirmed | The call order reproduces. The open items stay open. |
| L08 Native names | Corrected | Target 23 has a fixed format, not the HDR format. |
| L09 Image-space selection | Corrected | The exterior exception is the lighting-template field of the world space. |
| L10 Bloom chain | Confirmed | All seven tables reproduce. Four larger shader variants were decoded. |
| L11 Second-review items on #1059 | Confirmed | Moved to the amendment. |
| Correction to #1059 G02 | Confirmed | Moved to the amendment. |
| L12 Process notes on local reconstructions | Unverified, cut | Process material, not a retail fact. It is not in this file. |

**Re-read after the review.** The run that applied the corrections wrote its own binary reader with a hash check and re-read these items: the `T` read and the menu constant; the refill loop and the element-1 return; the timer update arithmetic; the setting names and compiled values, the history prefill and the multiplier step; the frame order and the two `UpdateTimeManager` calls; the store of 0.0 in one loop and the four `Main::Render` callers; the first-frame skip; the skipped final luminance draw and the adapt draw; the bloom `k` clamp and effect index; all seven weight tables, recomputed by script (35 listed values, 0 mismatches), and the two tap tables; the blur constructor and shader indices; the sizes and formats of targets 18, 22, 23 and 24; the chain target loop and the 1 by 1 target; a displacement scan that finds exactly three readers of `iShadowMaskQuarter`; the cell image-space getter, the per-frame base copy, the room selection code and the lighting-template type check; the tonemap binds; the direct callers of the release function; the call order after the composite; and the numeric examples of the amendment. The reviewer did not re-read the inner steps of the post-pass in L07, the modifier apply functions of L03, the writers of sky flag bit 8 in L05, or shader groups 37, 39 to 41, 51 and 53 to 55. The correcting run then re-read the post-pass calls and pass masks, the second accumulator mode and camera load, the modifier apply wrappers and the four bit-8 writers. It did not re-read the target-id 85 bind or the listed shader groups. Three wording points changed after these re-reads and have no independent review: the fixed-step writer stores nothing at `iFPSClamp` 0; the "not paused" flag also depends on a second byte, not only on the pause counter; and the modifier apply wrapper runs two functions.

Source exposure of the review: mixed. The reviewer used the pinned executable, the shipped shader package, the committed name and layout tables and published findings. It did not open a game plugin. This is a static review. It is not match evidence for any function, and it does not decide transfer eligibility.

Reviewer and outcome: Reviewed independently by a separate fresh-context `claude-sonnet-5-5` run. Outcome: 7 confirmed, 5 corrected, 1 unverified and cut, 0 rejected. Static evidence only. Transfer status: UNREVIEWED.
