Transfer status: UNREVIEWED

# Finding: worldspace grass suppression and sun direction timing

Status: OBSERVED where verified. INFERRED and UNVERIFIED items are marked. Static only: static analysis of the pinned image, the shipped masters and the shipped INIs. No runtime capture.

Author: the Sol research run, `gpt-6.2-sol` via Codex (not the reviewer below).  
Human operator: Taylor.  
AI assistance / model: `gpt-6.2-sol` via Codex.  
Date (UTC): 2026-11-22.  
Reviewed draft SHA-256: `afbb51bb8d8c24ec8e232451cb7a3662d3a77b292670abdc06701ba18ddbf704`.  
Target build id: `sse-steam-1-7-104`. The measured image SHA-256 `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f` equals the pin in [builds/target.json](../builds/target.json). Both runs measured the hash and asserted equality.  
Principal function RVAs (descriptive labels are GUESS): `0x30dde0`, `0x30de00`, `0x30ba10`, `0x747d60`, `0x208c20`, `0x206d40`, `0x157f41a` (sun helper call site), and `0x1581730`. Addresses are RVAs at image base `0x140000000`. The sun shadows finding writes its addresses as virtual addresses at the same base.  
Source exposure: mixed. Both runs used the operator's pinned executable, the five shipped masters, the five shipped INI templates, a native listing of the executable, and public generated naming metadata. The reviewer also checked two installed example INIs. The evidence comes from retail inputs and generated naming metadata.  
Sources and immutable revisions: the author inspected the grass findings and the naming table at `4d8f3a7721354794d8770561822e843b9988ecd6`. The grass findings last changed there at `fadac7b58d5c08996230c2940cfdccc1ea0252e7`. The reviewer used generated layouts at `3b2d3051afa64fd02862a831389cdef8d26b292b`. The sun shadows finding (PR #806) is at `2495dffcb5b5e62654fb6f995005237a5616ad3d`. Input receipts and reproduction commands are kept locally and are not in this repository.  
Intended recipient: Skyrim Research department lead for boundary review under [docs/clean-room.md](../docs/clean-room.md). The question came from a Mudcrab comparison. The maintainer's transfer decision is pending.

Name provenance: `TESWorldSpace::GetNoGrass` at `0x30dde0` is a GUESS label with low confidence. The author's run reports that the generated table lists the same spelling at that address. The independent review did not confirm that, so the label stays GUESS. `BSShadowDirectionalLight::InterpolateSunDirection`, `PlayerCharacter::SetParentCell` and `GrassManager::AddCellGrass` are names from the public generated tables and carry the label CRASHLOGGER_PDB(59818@2026.10.24) at each use below. `AddCellGrassTask` is from native type metadata (EXE_RTTI). Setting names come from the image and the INIs. All other descriptive labels are our own and are GUESS.

Addresses are RVAs. **Verified** identifies a result checked against the cited inputs. **Inferred** marks a conclusion from those observations. **Unverified** identifies an open claim. Keep listings of the game files in `.local/`. Nothing game-derived is in this file except counts, worldspace record names, field offsets, addresses and setting values.

## Question and method

Which worldspace flag reaches the grass manager, and which grass work does it suppress? Which shipped worldspaces carry it? What threshold and timing govern the sun direction update?

Trace the flag from `WRLD.DATA` to the manager and its cell callers. Screen the full executable listing for getter references, exact and overlapping `+0xA0` operands, masks, sign and shift tests, and short register and address aliases. Check literal getter references in the PE. Resolve master records by owner-remapped FormID and compare sun settings with their compiled fields and the shipped INIs.

## Observations

### G01. Flag, default, and loader

**Verified.** Getter `0x30dde0` (`TESWorldSpace::GetNoGrass`, GUESS) returns bit 7 (`0x80`) from the worldspace flags byte at `+0xA0`. Initialization leaves bit 7 clear. The worldspace load routine `0x30ba10` replaces the byte from `WRLD.DATA`. The shipping path reads one byte. The four-byte compatibility path conditionally swaps byte order and uses the low byte. The parent pointer and parent-use flags load separately. The getter uses the current object's byte. Evidence at `0x30ae92–0x30aeac`, `0x30b504–0x30b51b`, `0x30bc68–0x30bcc2`, and `0x30c05d–0x30c0ac`.

**Verified.** A loaded plugin override that supplies an effective `DATA` byte can set or clear the bit. A record without `DATA` skips that branch's write. Setter `0x30de00` replaces bit 7 and preserves bits 0–6. The author's direct-reference and literal-reference searches found no caller or address reference to it.

**Confidence: high** for the field, default, and replacement rule. **Unverified.** The full lifecycle of an override omitting `DATA`, affected sessions with conflicting plugins, and live reachability of the standalone setter. A load trace across competing overrides would resolve the lifecycle.

### G02. Readers

**Verified.** The direct call at `0x748073` is the sole getter call found. The literal VA and RVA search found no getter table reference. For a changed, non-null exterior cell with a worldspace, `PlayerCharacter::SetParentCell` (`0x747d60`, CRASHLOGGER_PDB(59818@2026.10.24)) sends the inverse of bit 7 to the grass manager refresh. The checked interior and missing-worldspace cases send false. Evidence at `0x747d89` and `0x74804c–0x7480ad`.

**Verified within the search.** The expanded offset scan checked byte and wider operands, flag-like operations, and short register and address aliases. It identified no additional behavioral read of bit 7. The checked fixed-center, terrain LOD, and large-reference routes test bit 6 (`0x40`). The same-offset terrain candidates at `0x517c98`, `0x517ebc`, `0x518263`, `0x519c2e`, and `0x519d4c` read the terrain manager's field. That object holds its worldspace separately. Candidates at `0x1a10c8`, `0x1aae6e`, and `0x3189e0` belong to camera objects. The checked landscape, LOD, water, and cell routes yielded no further bit-7 gate. Some byte updates preserve bit 7 while changing other flags.

**Confidence: high** for the direct caller. **Medium** for wider coverage. Long or indirect aliases, generic object copies, computed call targets, and plugin code remain **unverified**. An attributable additional read would change the result.

### G03. Grass cell population

**Verified.** The refresh at `0x208c20` updates the singleton grass manager's byte at `+0x88`. For finite values, it enables population when the caller flag and `bDrawShaderGrass` are true and `fGrassStartFadeDistance` is at least `fGrassMinStartFadeDistance` plus `0.5`. The constructor initializes the byte from settings. The console grass toggle can also write it and has separate removal and regeneration paths. The refresh returns before the fade recalculation at `0x208c60`. Evidence at `0x20693b–0x206967`, `0x208c20–0x208c59`, and `0x37128d`.

**Verified.** Per-cell population in `GrassManager::AddCellGrass` (`0x206d40`, CRASHLOGGER_PDB(59818@2026.10.24)) uses this byte to gate both cache loading and generation. With the byte set and `bAllowLoadGrass` true, it tries cell-associated cached data, then the cell's `.gid` resource if the first attempt returns false. A true return from either route bypasses generation. With the byte set and no true cache result, generation requires `bAllowCreateGrass`. The compiled defaults are `bAllowLoadGrass=0` and `bAllowCreateGrass=1`, also present in `Skyrim_Default.ini`. Evidence at `0x206dd1–0x206e19`, `0x207980`, and `0x2081a0`.

**Verified.** The synchronous grid caller and the `AddCellGrassTask` worker (EXE_RTTI) use the same population gate. The grid update visits available new members of the square within the inclusive `iGrassCellRadius`, which defaults to 2. `bGenerateGrassDataFiles` defaults to zero. The checked grid branch makes a synchronous call when that setting's manager byte is set and queues work when it is clear. Queue creation and teardown cancellation have separate conditions. The disabled population path releases the cell's associated task reference. The update can remove grass from departing cells through a separate routine. The world policy write itself only updates the enable byte. Evidence at `0x1a0ee3–0x1a1040`, `0x19edb0`, `0x19ef4f`, `0x2c7489`, `0x2078d1–0x2078e4`, and `0x2085e0`.

**Inferred.** Entering a flagged exterior worldspace suppresses cache population and generation for cells that reach the shared gate while the byte remains clear. The player transition supplies the world flag. The cell routine consults the current manager byte for each population call. This gate precedes per-texture placement, including its water checks, and grass drawing.

**Related evidence.** [grass-retail-constants.md](grass-retail-constants.md) covers the settings and the refresh in its G01–G03, and generation and placement in its G05–G15. This file adds the caller flag that the player transition supplies to that refresh. [grass-retail-leftovers.md](grass-retail-leftovers.md) covers draw-group capacity, shading, and fade in its G16–G18. The worldspace gate sits upstream of those operations. Group numbers in those two files are their own and do not match the numbers in this file.

**Confidence: high** for the traced gates. **Unverified.** Pending and in-flight scheduling, the lifetime of grass already present during a transition, and the visible result. An ordered transition trace could resolve them.

### G04. Shipped worldspaces

**Verified.** The five masters contain 77 `WRLD` records with one-byte `DATA`, representing 49 distinct worldspace identities. Seven records carry the bit.

| Master | WRLD records | Records with bit 7 | Names with bit 7 |
|---|---:|---:|---|
| Skyrim.esm | 37 | 2 | WhiterunWorld, LabyrinthianWorld03 |
| Update.esm | 13 | 1 | WhiterunWorld |
| Dawnguard.esm | 16 | 2 | WhiterunWorld, DLC1VampireCastleCourtyard |
| HearthFires.esm | 6 | 1 | WhiterunWorld |
| Dragonborn.esm | 5 | 1 | DLC2ApocryphaWorld |

**Verified.** The three `WhiterunWorld` overrides agree with the base. The remaining flagged entries each represent a different worldspace. Zero other worldspace identities in the scanned masters carry bit 7.

**Confidence: high** for these inputs. A changed plugin set can change the effective flag values.

### G05. Sun direction threshold and timing

**Verified.** This extends group 1 of [sun-shadows-retail-facts.md](sun-shadows-retail-facts.md) (PR #806), which lists the compiled `fSunShadowUpdateTime` and `bDisableShadowJumps` values and their setting reads. This file adds the threshold, the blend and the hold path. `fSunUpdateThreshold:Display` is a binary32 angle with compiled default `0.5°` at `0x20d9488`. The binary32 cosine cache at `0x20d9528` starts at `-1.0`. On the negative-cache path, setup clamps the angle to 0–90 degrees, converts it to radians, and computes `cosf`. Evidence at `0x157e54c–0x157e57a`. **Inferred from the default angle.** The initialized cosine is approximately `0.9999619`.

**Verified.** At completed progress in mode 0 with `bDisableShadowJumps=0`, helper `0x1581730` (`BSShadowDirectionalLight::InterpolateSunDirection`, CRASHLOGGER_PDB(59818@2026.10.24)) compares the dot product of the incoming and stored target directions with the cached cosine. For finite values, a dot product at or above the cosine holds the stored direction. A dot product below the cosine and at or above `1 − 2(1 − cosine)` starts a blend. A lower value snaps to the input. An active blend advances without repeating the comparison. Mode 1 can blend toward the current input. A switch from mode 0 to mode 1 at completed progress restarts that blend. The caller selects mode 1 when a displacement magnitude exceeds `0.01`. The two point identities remain **unverified**. Evidence at `0x1581746–0x1581972` and `0x157f2b2–0x157f314`.

**Verified.** `fSunShadowUpdateTime:Display` is binary32 `1.0` second by default at `0x20d94a0`. Progress advances by real-time frame delta divided by the blend time, with a divisor floor of `1e-6` seconds. Progress caps at 1. The helper normalizes the linear blend. The delta comes from timer selector 3 and uses seconds before the global time multiplier. Evidence at `0x15818c7–0x1581972`, `0x658d24–0x658d58`, `0x65f554–0x65f559`, and `0xce393a–0xce3952`.

**Verified.** The traced caller calls the helper at `0x157f41a` when `bDisableShadowJumps=0`. The helper's mode-0 branch also checks the Boolean and holds the stored direction if the setting is true. The compiled Boolean defaults to 1 at `0x20d9500`. In that default branch, the caller holds the prior direction and advances a counter by the same real-time delta divided by `fSunStaticTimeUpdateScale:Display`. The binary32 scale at `0x20d94b8` defaults to `0.1` seconds and uses the same divisor floor. The caller refreshes when the counter is already strictly above 1 or mode 1 is active. It normalizes a nondegenerate input, stores the result, and resets the counter. Evidence at `0x157f323–0x157f41a` and `0x15817af–0x15817b6`. The five shipped templates omit all four settings. The installed example `Skyrim.ini` sets `bDisableShadowJumps=1`.

**Confidence: high** for the compiled settings and specified branches. **Unverified.** Effective live settings, actual refresh interval, branch use, and visible shadow motion. A live direction and timer trace could establish them.

## Interpretation and limits

**Inferred.** The flag applies a player-world policy at grass cell population. Existing grass lifetime follows separate paths, and the policy can affect queued work when it reaches the shared gate. The sun threshold describes the traced interpolation route when the jump setting is clear. The compiled setting selects the separate timed hold and refresh route in that caller.

No retail process ran. Optional plugin behavior, exhaustive indirect coverage, live scheduling, and visible effects remain **unverified**. Transfer requires the boundary review in [docs/clean-room.md](../docs/clean-room.md).

## Independent review (2026-11-22)

Reviewer: `gpt-6.2-sol` through Codex, high effort, fresh context, separate run. The reviewer did not author or draft this finding. Date: 2026-11-22.  
Source reviewed: the draft of this finding (SHA-256 above), against the pinned image `sse-steam-1-7-104` (measured SHA-256 equals the pin in [builds/target.json](../builds/target.json)), the five shipped masters, the five shipped INI templates, two installed example INIs, the generated public layout names at `3b2d3051afa64fd02862a831389cdef8d26b292b`, and the sun shadows finding at the revision above. Exposure of the review: mixed (retail executable, shipped masters and INIs, generated names, the draft). Method: the reviewer traced the pinned executable independently, searched the full native listing, and checked the masters and INIs. The reviewer saved its independent conclusions before opening the draft and the author's handoff. This is a static finding review. It is not match evidence for any function. It does not decide transfer eligibility ([docs/clean-room.md](../docs/clean-room.md)).

The observations above already include the corrected text. A Claude Sonnet 5.5 worker only assembled this file from the corrected text and drafted nothing.

| Group | Verdict | One-line status |
|---|---|---|
| G01. Flag, default, and loader | Corrected | The source and clear default agree. A loaded override with an effective `DATA` byte can set or clear the bit. Omission across the complete override lifecycle remains unverified. |
| G02. Readers | Confirmed | One direct call and no second behavioral reader identified. The expanded scan distinguishes unrelated terrain and camera fields at the same offset. |
| G03. Grass cell population | Corrected | The byte gates both cache routes and generation. Queue creation, cancellation, and removal follow separate paths. |
| G04. Shipped worldspaces | Confirmed | Seven records across exactly four worldspaces carry the bit. The five masters contain 77 records for 49 worldspace identities. |
| G05. Sun direction | Corrected | The binary32 defaults and ordinary interpolation comparisons agree. Mode 1 and the sample-and-hold branch selected by the compiled jump setting are now described. |

Summary: 2 groups confirmed, 3 corrected, 0 rejected.

## Reviewer and outcome

Reviewed independently on 2026-11-22 by `gpt-6.2-sol` (Codex, high effort, fresh context), separate from the author run. Outcome: 2 confirmed (G02, G04), 3 corrected (G01, G03, G05), 0 rejected. Static only. A review verdict is not match evidence, and transfer eligibility is not decided. Unverified: in-flight and pending scheduling at a transition; the removal and lifetime of grass that already exists; visible effects of either feature; exhaustive indirect consumers of the flag (long aliases, generic copies, computed call targets, plugin code); the lifecycle of an override that omits `DATA`; live reachability of the standalone setter; and effective live sun settings, refresh interval and branch use. No retail process ran. Transfer status is UNREVIEWED.
