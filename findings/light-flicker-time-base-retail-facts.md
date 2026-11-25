Transfer status: UNREVIEWED

# Finding: the time base of light flicker and pulse (frame-time float, phase increment, initial phases, Flicker Slow)

## Answer

| Question | Answer |
|---|---|
| (1) What is `dt`, who writes it, and what is the cycle length? | **Verified, high. Static only.** `dt` is `BSTimer.delta` (CrashLogger field name) at RVA `0x3275608`. It is real seconds from the performance counter, times the global time multiplier `m` (default 1.0). It is not game-hour seconds and it is not seconds × 60. The writer is `BSTimer::Update` (`0xce36b0`), called each frame from `UpdateTimeManager` (`0x659d10`). Per frame: `ms = trunc((QPC − baseline) / (QPF/1000))`. `raw` is the ms difference to the last frame. If `raw` is above 166.667 ms, `dt = 1/6 s`. Otherwise `dt = raw × 0.001`. Then an 8-sample trimmed-mean smoothing runs (default on). Then `dt` is multiplied by `m`. A fixed `dt = 1/N s` applies only when `iFPSClamp` (1..199) or `iFPS:CameraPath` is active. **Formula (default settings, steady frame rate, `m = 1`):** the pulse phase `P` advances `p` rad per real second. `p` is the LIGH period float at form `+0xfc` after the load clamp to [0, 1]. The pulse cycle is `T = 2π / p = 6.2832 / p` s (p = 1: 6.283 s; 0.5: 12.57 s; 0.25: 25.13 s; 0.05: 125.7 s). Flicker: three phases advance by `dt·p·U` with a new random `U` each frame. The mean rates are `7.1 p`, `7.2 p` and `10.3 p` rad/s. The three noise terms have mean periods `0.671/p`, `0.8045/p` and `0.203/p` s. Flicker has no single cycle. For `m ≠ 1` replace `p` by `p × m`. See G01, G02, G05. |
| (2) Clamped or scaled by the time multiplier? Other consumers? | **Verified, high for the light function.** Clamped: a raw frame time above 166.667 ms becomes 1/6 s. Smoothed: trimmed mean of the last 8 values (setting default). Scaled: by the global time multiplier (`0x20ccac8`, default 1.0). The multiplier moves toward its target by a factor of 1.02 (up) or 0.98 (down) per frame, once per frame, while the byte at `0x32303b3` is 0. The ramp is skipped while that byte is non-zero. `dt` itself is zero while the `BSTimer` pause count (`+0x34`) is non-zero. That happens when the window is not active and `bAlwaysActive` is 0. A second pause site is the call at `0x65f732`. The pause count does not change the multiplier `m`. `dt` is **not** scaled by the game-hour timescale: the light function reads `0x3275608` directly, and the only writers are `BSTimer` methods. Menu pause does not zero `0x3275608`: it zeroes a separate copy at `0x3230524`. There are 204 read sites of `0x3275608` in about 131 unwind owners. Only the light function was classified. See G02–G04. |
| (3) Initial pulse and flicker phases | **Verified, high for the data path. Medium for run-time values.** The phases are not random and not from the form id. They live in the NiLight attenuation fields (`+0x140`, `+0x144`, `+0x148`). The light builder (`0x274390`) writes them at light creation from the `bLightAttenuation` settings. With the compiled defaults: `+0x140 = 0.0`, `+0x144 = 0.0`, `+0x148 = fQuadraticValue / R² = 16 / R²`. `R` is the truncated light radius. If `R × mult` is 0, the value is 0.01. So the pulse starts at `P = 0` (fade = `base`) and the flicker phases start at `A = 0`, `B = 0`, `C = 16 / R²`. The RNG (a global MT19937) only sets the per-frame rate. See G06, G07. |
| (4) Other code that modulates Flicker Slow (`0x40`)? | **Verified for the scope searched. None found.** Bit 6 is read in two places only: the editor-name function (`0x274330`) and the cell registration tests (`0x2d7ff6`, `0x2d81bd`, mask `0x1c8`). The modulation function (`0x274bc0`) tests bit 3 and bits 7/8. A light with only bit 6 is registered and then does nothing in that function. Scope: every instruction in the pinned image with displacement `+0xec` (554 lines), plus the immediate-mask scan. Not covered: the flag copy that `0x2e8bd0` returns to indirect callers, and access through a pointer to the LIGH `DATA` block. See G08. |

| Item | Evidence record |
|---|---|
| Status | OBSERVED for verified claims. Inferred and unverified claims are marked. Static only. No game launch, no runtime capture and no visual claim. |
| Author / human operator | A Sonnet 5.5 research run (`claude-sonnet-5-5`) for the department operator. A later Sonnet 5.5 run applied the review corrections. |
| Reviewer | A separate fresh-context Sonnet 5.5 run (`claude-sonnet-5-5`). Sol was unavailable on a usage limit. See "Independent review" below. |
| Date | 2026-11-25 CST. The author run started at 11:03. The independent review started at 11:18. The corrections were applied afterwards on the same day, with the re-reads listed in "Independent review". |
| Build | `sse-steam-1-7-104`, retail `1.7.104.0`, Steam build 24914197. Measured SHA-256 of `SkyrimSE.exe` `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f` equals the pin in [builds/target.json](../builds/target.json). The measured hash was checked before the first read, and again before the re-reads after the review. |
| Principal function RVAs | `0xce36b0` (frame timer update), `0x659d10` (per-frame time manager update), `0xce3970` (set global time multiplier), `0xce39d0` (multiplier ramp), `0xce3ab0` and `0xce3a50` (pause and unpause), `0xce3b10` (set smoothing size), `0xce8350` (timer constructor), `0x65c310` (window activation handler), `0x658870` (main idle loop), `0x274bc0` (flicker and pulse), `0x274390` (light builder), `0x275600` (set light attenuation), `0x273ae0` (LIGH load), `0x2b9750` (cell flicker pass), `0x1d6e40` and `0xce44e0` (random float and random integer), `0xef2ca0` (table fill), `0x15a8050` (sincos helper). |
| Sources and revisions | The pinned executable. The shipped default INI text (searched for the keys below; none present). Earlier finding `findings/point-lights-selection-retail-facts.md` (#1073, merged). Committed CrashLogger tables on `origin/main` for names and the `BSTimer` layout. |
| Source exposure | Pinned native binary analysis. Public generated layouts and names. No downstream or sibling implementation source. **No value was read from any game plugin.** No decompiler text or disassembly appears below. No Mudcrab source path appears below. Transfer needs review under [docs/clean-room.md](../docs/clean-room.md). |
| Name provenance | Names marked `CRASHLOGGER_PDB(59818@2026.10.24)`: `BSTimer`, its fields (`delta`, `realTimeDelta`, `clamp`, `clampRemainder`, `pauseCount`, `smoothingSampleCount`, `smoothingBufferIndex`, `useGlobalTimeMultiplierTarget`, `qpcBaseline`), `BSTimer::Update`, `BSTimer::BSTimer`, `TimeManager::SetGlobalTimeMultiplier`, `TimeManager::Pause`, `TimeManager::Unpause`, `UpdateTimeManager`, `UpdateGlobalTimeMultiplier_140C07900`, `GameFunc::handler::SetGlobalTimeMultiplier`, `Main::OnIdle`, `GetRandomNumber`, `NiPointLight::SetLightAttenuation`, `UpdateManagedNodesJob`, and the `TESObjectLIGH` member names. Setting names come from the strings in the image. Other labels are GUESS. A PDB name is not evidence of behaviour: every claim here was re-read in the image. |
| Intended recipient | Skyrim Research department lead for boundary review under [docs/clean-room.md](../docs/clean-room.md). Proposed use: Mudcrab issue #955, item 25. Maintainer transfer decision is pending. |

Addresses are RVAs for image base `0x140000000`. `dt` is the float at `0x3275608`. `p` is the stored LIGH period float (form `+0xfc`). `m` is the global time multiplier. `R` is the truncated light radius. **Verified** means re-read at the cited static source. **Inferred** means a deduction. **Unverified** means not read or not decided. The document contains facts and formulas only. Numeric examples use invented values.

## Question and method

The earlier finding (#1073) left the unit and source of the frame-time float that the light flicker and pulse function uses as open. This work decoded the writers and readers of `0x3275608` in a saved native listing and in single-function slices of the pinned image. It then re-read the light function and the light builder for the initial phases. It then searched every `+0xec` access for readers of the LIGH flag word. Settings were identified by the name string at setting object `+0x10`. Initial float values were read from the static image. Nothing was run in the game.

## Observations

### G01. The writer and the unit of `dt`

**Verified.** `0x3275608` is member `+0x18` of a timer object at `0x32755f0` (CrashLogger type `BSTimer`, size 0x40; field `delta`). The member `+0x1c` (`0x327560c`, field `realTimeDelta`) holds the same value before the multiplier. The member `+0x10` (`0x3275600`, field `clamp`) holds a fixed frame length in **milliseconds**, normally 0. The member `+0x14` (`0x3275604`, `clampRemainder`) holds a fractional carry. The member `+0x8` (`0x32755f8`) holds the performance-counter baseline. The members at `0x32755e0` and `0x32755e4` are floats: counter ticks per millisecond and per microsecond, computed once from `QueryPerformanceFrequency` (`0xce8350`, `0xce8391`, `0xce8399`).

**Verified.** The only functions that write `+0x18` are `BSTimer::Update` (`0xce36b0`), the multiplier setter (`0xce3970`) and the constructor (`0xce8350`, zero). A direct search of the listing finds 204 operands that resolve to `0x3275608`, and none is a store. All 27 listing sites that reference the object address `0x32755f0` call a `BSTimer` or `TimeManager` method (Update, setter, ramp, pause, unpause, smoothing size, constructor, destructor at `0x17b1040`) or read the counter. No site passes the address to code that stores at `+0x18` other than these methods. The read of the counter is `QueryPerformanceCounter` (`0xce8430`).

**Verified.** `BSTimer::Update` has nine call sites. Two use the global timer: `0x659d80` (in `UpdateTimeManager`) and `0x65c38b` (in the window activation handler). The other seven use other `BSTimer` objects: a second global timer at `0x3258d50` (`0x9a02e6`, `0x9a082b`) and timers embedded in other objects (`0x6105cd`, `0x9c35ad`, `0x9c36fb`, `0x9c4b06`, `0x116aaae`). They do not write `0x3275608`.

**Verified.** Each frame, `UpdateTimeManager` (`0x659d10`) computes `ms = trunc((QPC − baseline) / ticksPerMs)` as a 32-bit integer and calls `BSTimer::Update(ms)`. `UpdateTimeManager` has two call sites in `Main::OnIdle` (`0x658d8f` and `0x65932a`). The window activation handler (`0x65c310`) also calls `BSTimer::Update` once when the window becomes active.

**Verified.** Unit: `delta` is `(ms difference between frames) × 0.001`, so seconds. The constant `0x1b5bdc4` is 0.001. The resolution is 1 ms before smoothing. See G02 for the clamp, the smoothing and the multiplier.

**Confidence: high.** **What would change it:** a second writer through a pointer that the listing search did not resolve. The listing shows no other `lea` of `0x32755f0` followed by a store to `+0x18`.

### G02. Per-frame computation: clamp, fixed step, smoothing, multiplier

**Verified.** `BSTimer::Update` does the following, in order (`0xce36b0–0xce3958`).

1. If the pause count (`+0x34`) is non-zero: `delta` and `realTimeDelta` are set to 0, and the function returns.
2. If `clamp` (`+0x10`) is 0 (normal case): `raw_ms = (now_ms − baseline_ms) − last_ms`. If `raw_ms` is above 166.667 (constant `0x1a220f8`), `delta = 0.1666667` (constant `0x1869dd8`) with **no** `× 0.001`. Otherwise `delta = raw_ms × 0.001`.
3. If `clamp` is non-zero: `delta = clamp × 0.001` always. The time carries `trunc(clamp + carry)` ms per frame, with the fraction kept in `clampRemainder`. So `delta = 1/N` s for `clamp = 1000 / N`.
4. Smoothing (when the sample count at `+0x38` is 3 or more): `delta` is written into a ring buffer. The new value is `(sum − max′ − min) / (count − 2)` over the whole ring, where `max′ = min(max(max, 0), 0.05)` (constant `0x17ed69c`, 0.05) and `min` starts from 1/6. The buffer is filled with 0.016 (constant `0x3c83126f`) when the size is set (`0xce3b10`). So a single frame spike above 0.05 s is only partly removed. Smoothing applies after both the free-running and the fixed-step case. In fixed-step mode the ring converges to the constant step once it has filled. With a sample count below 3, `delta` stays raw.
5. `realTimeDelta = delta` (smoothed). Then `delta = realTimeDelta × m`, where `m` is the float at `0x20ccac8` (writable data, initial value 1.0).

**Verified.** The smoothing size is set each frame in `UpdateTimeManager` from two settings: `bCompensateUnstableFrameTime:Display` (value field `0x20b5830`, compiled default 1) and `iUnstableFrameTimeHistorySize:Display` (`0x20b5848`, compiled default 8). The size is 0 (no smoothing) when the bool is 0. Names come from the image strings. The shipped default INI does not contain these keys (searched).

**Verified.** The fixed step. `clamp` is set to `1000 / N` ms (constant `0x1b5bffc` is 1000.0) from `iFPSClamp:General` (`0x20b5b90`, compiled default 0) at start-up (`0x6559ce`; applied only if 1 ≤ N ≤ 199) and from `iFPS:CameraPath` (`0x20b5da0`, compiled default 30) at `0x656b3c` and `0x65aaec`. It is set back to 0 at `0x65a8ba` and `0x65b154`. What puts the game in the camera-path state was not traced. The earlier finding called the value at `0x3275600` a "`1 / iFPS`-style value". It is milliseconds (see "Relation to earlier findings").

**Confidence: high** for the logic and constants. **Medium** for the effective settings at run time (INI load order not traced). **What would change it:** INI values for the settings above.

### G03. Time multiplier, pause, and menu pause (question 2)

**Verified.** The multiplier `m` is the float at `0x20ccac8`. Its target is the float at `0x20ccacc` (both 1.0 in the static image). A rate float at `0x20ccad0` is 0.02. `TimeManager::SetGlobalTimeMultiplier` (`0xce3970`) stores the target. If `useGlobalTimeMultiplierTarget` (timer `+0x3a`, copy of `bChangeTimeMultSlowly:General`, compiled default 1) is clear, the setter sets `m` to the target at once and re-scales the current `delta` by the ratio. If it is set and the second argument is true, `m` jumps to the target. If it is set and the second argument is false, `m` ramps. `UpdateGlobalTimeMultiplier` (`0xce39d0`), called each frame from `UpdateTimeManager` when the byte at `0x32303b3` is 0, multiplies `m` by `1 + rate` (1.02) when `m` is below the target and by `1 − rate` (0.98) when it is above. It clamps at the target. So the ramp is geometric and per frame, not per second. From exactly 0 it cannot rise.

**Verified.** There are 15 sites of the setter: 14 calls and one tail jump (`0x806cdd`). One call is in the handler named `GameFunc::handler::SetGlobalTimeMultiplier` (`0x360750`, call at `0x3607ca`), which clamps its argument to at least 1e-6 (`0x1b5bdb0`). Five sites load the constant 1.0 as the argument (the setter call follows the instruction at `0x62779c`, `0x805fc6`, `0x80674d`, `0x806cbc` and `0x7ce07e`). The remaining sites pass a computed value (the instruction before the call is at `0x7cdf30`, `0x807b22`, `0x807c02`, `0x807eb7`, `0x808234` and `0x381d06`). **Inferred:** the computed sites are the slow-time effects. This work did not trace what feeds them.

**Verified.** Pause: `TimeManager::Pause` (`0xce3ab0`) increments the pause count. `TimeManager::Unpause` (`0xce3a50`) decrements it and re-baselines the time counters when it reaches zero. While the count is non-zero, `dt` is 0 (G02 step 1). The pause count does not change `m`. The window activation handler (`0x65c310`) calls Pause when the window loses activation, and Unpause when it gains activation, unless `bAlwaysActive:General` (`0x20b58c0`) is set. A second Pause site is the call at `0x65f732`. Its paired Unpause call is at `0x65f8d5`.

**Verified.** Menu pause does not zero `0x3275608`. `UpdateTimeManager` copies `delta` into a second float (`0x3230524`) only when the byte at `0x32303b3` is 0, else it writes 0 there. This byte is set each frame in `Main::OnIdle` (`0x658948`) from `[singleton 0x14219e5c0 + 0x160] != 0`. **Inferred:** that field is a count of menus that pause the game. `0x3230524` has 7 reader sites. The light function does not read it.

**Unverified.** Whether the cell flicker pass (`0x2b9750`) runs while a pausing menu is open. The pass calls the light function, which reads the unpaused `0x3275608`. Whether the whole world update is skipped during menu pause was not traced.

**Confidence: high** for the mechanism. **Medium** for the pause-menu meaning. **What would change it:** a trace of the world update call under menu pause.

### G04. Other consumers of `dt` (question 2)

**Verified.** `0x3275608` has 204 read sites in the listing, in about 131 distinct unwind owners (animation, physics and AI-style code are not classified). `0x327560c` (unscaled) has 43 read sites. `UpdateTimeManager` passes `delta` to one call (`0x14104ab70`, not traced) and copies it as described in G03. The cell flicker pass caller `0x1a1500` also reads `0x3275608` once.

**Verified.** The light function (`0x274bc0`) reads `0x3275608` at two sites (`0x274c76` for flicker, `0x274f2f` for pulse), and multiplies it by the period float only. No game-hour or timescale term is applied. The game-hour timescale is therefore not part of the phase increment. **Unverified:** that no other path scales the *consumers* (not needed for the light function).

**Confidence: high** for the light function. **Low** for the full consumer list (not classified).

### G05. Phase increments and cycle lengths (question 1)

**Verified.** The LIGH loader (`0x273ae0`) copies the 40-byte `DATA` into the form at `+0xe0` (`0x273c3d`). After the copy it clamps the period at `+0xfc`. A stored value above 1.0 becomes 1.0 (`0x273d76–0x273d88`). A value below 0 becomes 0 (`0x273f01–0x273f06`). The zero comes from a register cleared at `0x273b34` and not reassigned on this path (**inferred** from a linear read). A NaN also ends as 0. The loader also sets the field of view to 90 if it is 0 and the falloff exponent to 1 if it is 0. So `p` is in [0, 1] for every loaded light. CrashLogger names the field `FlickerPeriodRecip`.

**Verified.** Pulse (flag bits 7 or 8), per call (`0x274f24–0x275011`):

- `r = dt × p`. `P ← P + r`. If `P > 2π` (constant `0x17ed6a0`) then `P ← P − 2π` once (constant `0x1814590`).
- `fade = base × (1 − I + I × cos P)`, with `I = 0.5 × intensityAmp` (constant `0x1b5be14`). The cosine is a table lookup at index `trunc(P × 81.4873) & 511`. The table has 512 entries at step `2π/512`.
- Closed form for the phase per real second: `dP/dt_real = p × m` rad (frame rate steady, smoothing at its mean). **One pulse cycle: `T = 2π / (p × m)` s.** At `m = 1` and `p` in [0, 1]: `T = 6.2832 / p` s, never below 6.283 s. At `p = 0` there is no motion. `P` is a per-frame sum, so the cycle is exact on average and is not tied to the frame rate.

**Verified.** Flicker (flag bit 3), per call (`0x274c4f–0x274f1f`): `r = dt × p`. Each frame three uniform random numbers `U_A ∈ [1.1, 13.1]`, `U_B ∈ [1.2, 13.2]` and `U_C ∈ [1.3, 19.3]` give `A += r × U_A`, `B += r × U_B` and `C += r × U_C`. Each phase is wrapped once by `−2π` when it is above `2π`. The noise is `n = ((sin(1.3 B + 0.65) + 1) / 12) × (sin(1.1 A + 1.87) + 1) + 0.2 × sin(3 C + 0.9)`, clamped to [−1, 1]. The constants and the table-index form are as in the earlier finding (G08 there).

**Inferred** (arithmetic on the verified constants). The mean phase rates are `E[U_A] = 7.1`, `E[U_B] = 7.2` and `E[U_C] = 10.3` rad per `(p × m)` per real second, because `E[U] = (lo + hi) / 2`. The mean periods of the underlying sine terms are `2π / (k × rate)`:

| Term | Mean angular rate | Mean period (s) |
|---|---|---|
| `sin(1.3 B + 0.65)` | `9.36 p m` | `0.671 / (p m)` |
| `sin(1.1 A + 1.87)` | `7.81 p m` | `0.8045 / (p m)` |
| `sin(3 C + 0.9)` | `30.9 p m` | `0.203 / (p m)` |
| movement `sin(A + 1.7)` | `7.1 p m` | `0.885 / (p m)` |
| movement `sin(B + 0.5)` | `7.2 p m` | `0.873 / (p m)` |
| movement `sin(C + 0.3)` | `10.3 p m` | `0.610 / (p m)` |

The rate is random each frame, so these are mean periods of a drifting phase and not fixed periods. The mean rates do not depend on the frame rate. The variance of the phase does. All flicker time constants scale as `1 / p`: at `p = 1` the three noise terms have mean periods of 0.20 to 0.80 s, and at `p = 0.05` they are 20 times longer.

**Inferred** (arithmetic). A phase wrap subtracts `2π` from the phase, and the terms use `1.3 B` and `1.1 A`. So at each wrap of `B` the argument of the first term steps by `−1.3 × 2π`, which is `−1.885` rad modulo `2π`. At each wrap of `A` the second term steps by `−0.628` rad. The `3 C` term has no step (3 is a whole number). The pulse and the movement terms (factor 1) have no step. The step is a property of the code. Whether it is visible was not tested.

**Verified** (this closes the "inferred" in the earlier G08). The sine table is at `0x14331c6f0` and the cosine table at `0x14331cef0`. The fill loop (`0xef2ca0`) runs 512 times with step `2π/512` (constant `0x1a48d00`, 0.0122718). It stores the low lane of the sincos helper result (`0x15a8050`) to the first table and the second lane to the second. The helper's small-angle branch returns `x` in the low lane and `1 − 0.5 x²` in the second lane. So the first table holds sin and the second holds cos.

**Unverified.** The unit of the editor "Flicker Period" value and its relation to the stored float. The CrashLogger name `FlickerPeriodRecip` suggests the stored float is a reciprocal. This work read no plugin, so it cannot say which editor values map to which stored values. The formulas above are in the stored value `p`.

**Confidence: high** for the formulas and constants and for `p` in [0, 1]. **Medium** for the flicker mean periods (arithmetic). **What would change it:** a trace of the editor-to-stored conversion in the plugin loader, or two frame captures.

### G06. Initial phases (question 3)

**Verified.** The phases are not stored in the form. They are read from, and written back to, the light object at `+0x140`, `+0x144`, `+0x148` (the memory the NiPointLight uses for the constant, linear and quadratic attenuation values). The light builder (`0x274390`, GUESS label "build the NiLight for a LIGH reference") fills them when it creates the light (`0x274903–0x274a5a`). The same code exists in `NiPointLight::SetLightAttenuation` (`0x275600`), which has no direct callers in the listing (reached indirectly). These are the only two sites that read the three attenuation settings with the light object as the target.

**Verified.** The values written. A flag byte at `0x31a5498` is computed at start-up from `bUseConstant`, `bUseLinear` and `bUseQuadratic` (`0x17330–0x17381`): bit 0, 1, 2 respectively, and the value 4 if none is set. Compiled defaults: constant 0, linear 0, quadratic 1, so the byte is 4. The builder first writes `+0x140`, then clears `+0x144` and `+0x148`, then computes each one only when its condition holds.

- `+0x140` = `fConstantValue` (compiled default 0.0) if bit 0 is set, else 0.
- `+0x144` = 0 unless bit 1 is set (or, when `bOutQuadInLin` is 1, when the interior-cell pointer `[0x1432303b8] + 0xc0` is non-null). If computed, it is `fLinearValue` (3.0) divided by `R × fLinearRadiusMult` for `uLinearMethod` 1, or divided by its square for method 2, or `fLinearValue` for method 0. If `R × mult` is 0 the value is 0.01 (`0x1b5bdd0`).
- `+0x148` = 0 unless bit 2 is set (or, when `bOutQuadInLin` is 1, when that pointer is null). With the default byte value 4 it is `fQuadraticValue` (16.0) divided by `(R × fQuadraticRadiusMult)²` for `uQuadraticMethod` 2 (the compiled default). Method 1 divides by `R × mult` without the square, and method 0 uses `fQuadraticValue`. If `R × mult` is 0 the value is 0.01.
- `bOutQuadInLin:bLightAttenuation` has compiled default 0, so the defaults in this group stand.
- `R` starts as the form radius (`+0xe4`, a 32-bit integer converted to float). It is replaced by the result of `0x2ffd70` when the builder has a reference and a flag byte at `+0x100` of its argument is 0. A result at or below 0 becomes 0.1 (`0x1b5bde4`). The same float is stored as the light radius at `+0x128`. The attenuation uses the integer truncation of `R` (`0x2748c5`). The source of the `0x2ffd70` value was not traced.

**Verified** (consequence). With compiled defaults: pulse `P₀ = 0.0`, so the first fade is `base` (the maximum). Flicker `A₀ = 0.0`, `B₀ = 0.0`, `C₀ = 16 / R²` (for an invented `R = 256` this is 0.000244; the value only illustrates the formula). The phase is per light object. A light created later starts again from these values. A null light pointer uses local defaults `A = 1`, `B = 0`, `C = 0` and stores nothing.

**Unverified.** The effective values of the `bLightAttenuation` settings at run time. They are compiled defaults in the image, and the shipped default INI has none of the keys (searched). INI load order and any override were not traced. If an INI sets `bUseConstant` and `fConstantValue`, `P₀` changes. Whether a later re-creation of a light (a second run of the builder) can occur for a live light was not traced.

**Confidence: high** for the data path and the formulas. **Medium** for the run-time values. **What would change it:** an INI that sets the attenuation keys.

### G07. The random number generator of the flicker rate

**Verified.** The per-frame random factor comes from `0x1d6e40`: `lo + (hi − lo) × (u × 2⁻³²)` with `u` a 32-bit integer from `GetRandomNumber` (`0xce44e0`) on the global generator at `0x14219e810`. The generator is a Mersenne Twister (624-word state, constant `0x9908b0df`). One flicker call draws three numbers. The generator is shared with other callers (209 reference sites of the address in the listing).

**Inferred.** The generator is seeded on first use from `_time64` (`0xce44fd` calls the import) unless another caller seeds it earlier (`0x206ec5`, `0xce4680` call the seed function; not traced). So flicker sequences are not reproducible between runs.

**Confidence: high** for the algorithm. **Low** for the seeding. **What would change it:** the seed callers.

### G08. Other readers of the LIGH flag word, and Flicker Slow (question 4)

**Verified.** The LIGH flag word is at form `+0xec`. The listing has 554 instructions with displacement `+0xec` (this includes vector and address-load forms). Each load was followed for 24 instructions for tests of bit 6 (`0x40`), of `shr 6`, and of masks with that bit. Bit 6 is read at two places only: the editor-name function (`0x274330`, shift by 6) and the cell registration (`0x2d7ff6` and `0x2d81bd`, mask `0x1c8` = bits 3, 6, 7, 8). A second scan for direct immediate tests on a `+0xec` operand finds the masks `0x20` (`0x274422`, `0x2744b2`), `0x4` (`0x27452a`) and `0x1c8` (the two registration tests) among LIGH-code sites.

**Verified.** The other readers of the flag word that are in LIGH code: bit 1 (can be carried: `0x275080`, `0x2e9092`, `0x2cf2e4`, `0x2384ed`, `0x23879c`, `0x6edc57`); bit 5 (`0x20`, "off by default": `0x274422`, `0x2744b2`) and bit 2 (`0x4`, `0x27452a`) in the light builder; bit 0 set (`0x27473b`); bits 10 to 12 (`0x1c00`) and bit 13 in the builder (`0x27482a`, `0x2747b9`); the modulation function (bit 3 at `0x274c4f`, bits 7 and 8 at `0x274f24`). Copies of the whole word: the loader (`0x273cdc`), the form-to-form copy (`0x2d0bb2`), and a function that returns radius, colour and flags to its caller (`0x2e8c07`).

**Verified.** In the modulation function a form with none of bits 3, 7, 8 skips straight to the function end (`0x274f29`, then `0x27504c`). So a light with only bit 6 set is on the cell flicker list and is not changed. A light with bits 3 and 6 flickers (bit 3 wins). A light with bits 6 and 7 or 8 pulses. Flicker Slow therefore does not change the rate: the pulse and flicker rates depend on `p` alone.

**Not found / limits.** The scan does not see accesses through a pointer to `form + 0xe0` (a struct with the flags at `+0xc`). The caller of the flag copy at `0x2e8c07` is reached through a virtual slot (`+0x380`) and its users were not enumerated. The scan covers only the saved listing of the pinned image.

**Confidence: high** for "no further bit-6 test by displacement". **Medium** for "no modulation anywhere", because of the indirect access limit. **What would change it:** an indirect user of the `0x2e8c07` struct that tests bit 6.

## Relation to earlier findings

The earlier finding is `findings/point-lights-selection-retail-facts.md` (#1073, merged). The items below are corrections of wording and scope. They change no numeric formula there. The amendment text is in the "Amendment" section of that file.

1. **Verified.** The earlier G08 says the float at `0x3275600` "is stored as a `1 / iFPS`-style value at `0x6559ce`". The stored value is `1000 / N` (milliseconds per frame, constant 1000.0 at `0x1b5bffc`), from `iFPSClamp:General` and `iFPS:CameraPath`, and it is `BSTimer.clamp`. It is not a reciprocal in seconds. Confidence high.
2. **Verified.** The earlier G08 leaves the unit of `0x3275608` unverified. G01 and G02 here trace its writer and its unit. Confidence high.
3. **Verified.** The earlier G07 says the pulse cycle is `2π / period` seconds "if `dt` is in seconds". `dt` is in seconds times `m`, and the full form is `T = 2π / (p × m)`. It must also say that the loader clamps `p` to [0, 1], so `T ≥ 6.283 s` at `m = 1`. Confidence high.
4. **Verified.** The earlier G07 and G08 mark the sine and cosine table identity as inferred. It is verified (G05 here).
5. **Verified for the scope searched.** The earlier G06 leaves open whether any code other than `0x274bc0` modulates Flicker Slow lights. G08 here answers it within the stated scope.

Nothing in G06 to G10 of the earlier finding was found to be wrong by this work. The numeric formulas, constants, addresses and ranges there agree with this finding.

## Interpretation and alternatives

- With `dt` in real seconds and `p ≤ 1`, a pulse cycle is at least 6.283 s and as long as `6.283 / p` s. For a small `p` the cycle is long (125.7 s at `p = 0.05`). The code gives no hidden constant of 60 or game-hour scale. An alternative reading is that the editor stores a reciprocal (`FlickerPeriodRecip`), so a small editor period maps to a large stored value that the loader clamps to 1. The code alone cannot separate these (G05, unverified part).
- The smoothing and the 1/6 s clamp make `dt` almost independent of single-frame spikes. Below 6 fps the phase runs slower than real time.
- The multiplier makes pulse and flicker run slower under any effect that lowers it (G03). The tie to named game effects is inferred only.

## Negative results and limitations

- Static only. No runtime capture. No visual claim.
- **Unverified.** The effective INI values of `bCompensateUnstableFrameTime`, `iUnstableFrameTimeHistorySize`, `iFPSClamp`, `bChangeTimeMultSlowly` and the attenuation settings. The shipped default INI has none of them. The run-time values the 15 multiplier setter sites pass.
- **Unverified.** Whether the cell flicker pass runs under menu pause.
- **Unverified.** The meaning of the editor period value (G05). It needs a read of a plugin value, which this work did not do.
- **Unverified.** The seeding of the random generator beyond the first-use path.
- **Not classified.** About 130 other consumers of `dt`.
- **Not found.** Any writer of `0x3275608` outside the `BSTimer` methods. Any bit-6 test outside `0x274330`, `0x2d7ff6`, `0x2d81bd` by displacement search. Not covered by that search: copies of the flag word and access through a pointer to the LIGH `DATA` block.

## Amendments in this PR

This PR adds one dated amendment section to the earlier finding `findings/point-lights-selection-retail-facts.md` (#1073). It replaces seven statements, by quotation, for these topics only: the unit of `dt`, the `0x3275600` value, the pulse cycle time, the Flicker Slow search, the table identity, the not-found list and the G08 review row. No numeric formula changes.

## Independent review

Reviewer: a fresh-context Sonnet 5.5 run (`claude-sonnet-5-5`), separate from the author. Sol was unavailable on a usage limit. The reviewer wrote its own results first, from the pinned image and a saved listing, before it opened the draft. Static only.

Result: **7 confirmed, 6 confirmed with a wording or scope fix, 0 claims changed, 0 refuted** (13 items: four answer rows, G01 to G08 and the relation block). The review found no wrong claim. This file contains the corrected wording.

| Group | Verdict | Main correction |
|---|---|---|
| Answer row 1 (time base) | Confirmed | None. The reviewer reached the same result without the draft. |
| Answer row 2 (clamp, multiplier, consumers) | Confirmed, wording | The pause clause had no subject: `dt` is zero under the pause count, not `m`. The ramp clause was reworded. |
| Answer row 3 (initial phases) | Confirmed, wording | The `bOutQuadInLin` path and the radius source were added (see G06). |
| Answer row 4 (Flicker Slow) | Confirmed | None. |
| G01 (writer, unit) | Confirmed | None. |
| G02 (clamp, fixed step, smoothing, multiplier) | Confirmed, wording | Smoothing also runs in fixed-step mode. |
| G03 (multiplier, pause, menu pause) | Confirmed, wording | The setter has 15 sites (14 calls and one tail jump), not 14. |
| G04 (other consumers) | Confirmed | None. |
| G05 (phase increments, cycles) | Confirmed, wording | One interpretation sentence that rested on the task text was removed. |
| G06 (initial phases) | Confirmed, scope | The `bOutQuadInLin` path (default 0) and the radius source (`0x2ffd70`, a result at or below 0 becomes 0.1) were added. |
| G07 (random generator) | Confirmed | None. First-use seeding stays inferred. |
| G08 (Flicker Slow readers) | Confirmed within scope | None. |
| Relation to earlier findings | Confirmed | None. |

Counts: confirmed as written 7 (G01, G04, G07, G08, the relation block, answer rows 1 and 4). Confirmed with a wording or scope correction 6 (G02, G03, G05, G06, answer rows 2 and 3). The reviewer did not verify: what the setter sites feed at run time, whether the flicker pass runs under menu pause, the effective INI values, and the editor-to-stored period meaning.

After the review, the author re-read these items in the pinned image and the saved listing (the measured hash matched the pin first). All matched, with two small changes noted at the end. (1) The global `dt` float: 204 operands, no store, 43 reads of the unscaled neighbour, 27 references to the timer object. (2) `BSTimer::Update`: the pause-count early exit, the 166.667 ms cap and the 1/6 s value without the 0.001 factor, the fixed-step branch falling into the smoothing, the trimmed mean with the 0.05 cap on the subtracted maximum, the ring prefill 0.016, and the final multiply by `m`. (3) The setter (rescale branch, jump branch) and the ramp (factor `1 ± rate`, rate 0.02, defaults 1.0 and 1.0), and the 15 setter sites. (4) Pause and unpause counting, and the second pause and unpause pair. (5) The pulse constants (2π, −2π, 81.4873, 0.5) and the single wrap. (6) The three flicker rate ranges, the six table-index constants, 1/12, 0.2, the [−1, 1] clamp, and the two `dt` reads. The three mean periods were recomputed by hand: 0.6713, 0.8045 and 0.2033 s. (7) The load clamp: the 1.0 store above 1.0, the zero store below 0 and for NaN. (8) The attenuation writes: the three stores, the flag-bit and `bOutQuadInLin` conditions, the radius source and its 0.1 fallback, the radius truncation, the methods, the 0.01 value, and the setting names and compiled values. (9) The bit-6 readers (`0x274330`, `0x2d7ff6`, `0x2d81bd`) and the direct immediate tests of the `+0xec` operands. (10) The setting names and compiled defaults, including 30 for `iFPS:CameraPath`.

Changes from the re-read: the second mean period is 0.8045 s (the first draft rounded it to 0.804). The `+0xe4` radius is an integer converted to float, and the review text called it a float. The count of `BSTimer::Update` call sites and the other timers were added to G01.

Source exposure of the review: pinned native binary. This is a static review. It is not match evidence for any function, and it does not decide transfer eligibility.

Reviewer and outcome: Reviewed independently by a Sonnet 5.5 run. Outcome: 7 confirmed, 6 confirmed with a wording or scope fix, 0 claims changed, 0 refuted. Static evidence only. Transfer status: UNREVIEWED.
