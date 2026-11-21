Transfer status: UNREVIEWED

# Finding: interior portal admission

Status: OBSERVED for the tagged branches and values. Geometric deductions are tagged **inferred**. Static only.

Author: MR-2, a `gpt-6.2-sol` run via Codex (not the reviewer below).  
Human operator: Taylor.  
AI assistance / model: `gpt-6.2-sol` via Codex.  
Date (UTC): 2026-11-21.  
Target build id / image SHA-256: `sse-steam-1-7-104` / `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f`.  
Primary function RVAs: `0x1a97b0`, `0x15100b0`, `0xfeea10`, `0xfe94e0`, `0xff79c0`, `0xfdb980`.  
Source exposure: mixed. Static analysis of the operator's Steam executable and its native listing, plus public generated CrashLogger metadata. The analysis used no Mudcrab source or sibling implementation.  
Sources and immutable revisions: the pinned image and generated metadata at `3b2d3051afa64fd02862a831389cdef8d26b292b`. The metadata catalogue identifies [CrashLogger mod 59818](https://www.nexusmods.com/skyrimspecialedition/mods/59818), version `2026.10.24`. Only names and layout metadata are cited.  
Intended recipient: Skyrim Research department lead for boundary review. The proposed downstream use is Mudcrab's retail-facts work. The maintainer's transfer decision is pending.

Name provenance: `CRASHLOGGER_PDB(59818@2026.10.24)` applies to the generated routine names and layouts cited below. It includes `TES::UpdatePortalVisibility`, `ShadowSceneNode::PropagateRoomVisibility`, `BSCompoundFrustum::ProcessPortal`, `BSCompoundFrustum::AddPortalOpening`, `BSMultiBoundNode::OnVisible`, `BSPortal`, `NiRTTI`, `ActivePlane::kNear`, and the fields `size`, `skipViewFrustum`, `lastAccumTime`, `visibilityState`, `twoSided`, `multiBound`, and `visibleUnboundSpace`. The retail type-descriptor identity in G02 is `EXE_RTTI`. Descriptive names for the sixth-argument bypass and the culling-service stamp are `GUESS`.

Tags: **verified** means read in the pinned image at the cited addresses. **Inferred** means derived from those observations. **Unverified** means the trace did not establish the claim. Evidence addresses below are virtual addresses (VAs) at image base `0x140000000`.

## Question and method

When does crossing an interior portal add a room to the camera's visibility map? The static trace follows the camera update, the propagation decisions, both geometry tests, and the map consumers. The executable SHA-256 was asserted against `builds/target.json`. The analysis used a native listing of the pinned image. Keep listings and other game-derived material in `.local/`. None is published here.

## Observations

### G01. Room admission order (verified, high for the traced camera calls)

The camera entry is `TES::UpdatePortalVisibility` (RVA `0x1a97b0`). The traversal decision is in `ShadowSceneNode::PropagateRoomVisibility` (RVA `0x15100b0`).

1. Skip a null portal or a portal whose shared-node key already has a non-null visibility-map value.
2. Require the base camera test unless the source frustum has `skipViewFrustum` set.
3. Require the compound test unless propagation argument six is nonzero. All three traced camera calls pass zero.
4. Use endpoint `+0x118`. If it equals the current room, use `+0x120`. Skip the crossing if the selected endpoint still equals the current room.
5. A crossing back to the seed goes straight to shared-node marking. Other crossings attempt FIFO insertion before the destination map lookup.

When a non-null destination expression is absent or empty, the threshold for retaining inherited operators is at most `25`. Existing nonempty room expressions and null endpoints have separate paths. The traced admission loop has no depth comparison or additional identified open-state, distance, or entrance-side veto.

Evidence: camera calls `0x1401a99cb`, `0x1401a9a29`, and `0x1401a9a68`. Queue and admission `0x1415102cb`–`0x141510354`, `0x141510370`–`0x141510492`. Existing expression `0x1415104a3`–`0x141510552`. Threshold `0x141510557`–`0x1415105cf`. Shared-node marking `0x1415106d4`–`0x1415106e6`. Unbound path `0x14151076e`–`0x14151092e`. Other traversals are **unverified**.

### G02. Base camera and compound frustum tests (verified, high for finite, nondegenerate geometry)

Let `E` be the eye, `T` the portal translation, `(n,d)` the nominal portal plane, and `F` the signed plane function for camera-frustum slot 0, labelled near. Set `s = n·E − d` and `P = E − s n`. The projected-eye extent tests use zero-based stored rows 1 and 2. Both include equality.

- `|row1 · (P − T)| ≤ size[0]`
- `|row2 · (P − T)| ≤ size[1]`

If `−5 ≤ s + F(E) < 5` and both extents pass, the base test returns the exact type-descriptor comparison. The ordinary portal returns the `BSPortal` descriptor pointer. A mismatch returns false immediately. Outside that short-circuit branch, the test accepts a quad hit against the active camera planes. After a quad miss, acceptance requires both extent tests and strict `F(P) > F(E)`.

`BSCompoundFrustum::ProcessPortal` (RVA `0xff79c0`) accepts an empty expression. In a populated expression, opening predicates use plane intersection with the optional projected-point fallback disabled. Occluder predicates negate all-corners containment, which includes signed zero. The expression follows the predicate results.

The quad test rejects if every corner has signed value `< 0` against the same active plane. An edge is viable if both endpoints are inside, or if it crosses an active plane at a point inside every other active plane. An edge rejected by a shared outside plane is ineligible. Edge crossing includes both segment endpoints and signed zero on the other planes. The four edge bytes record the classifications when reached. A viable edge has byte value zero. The all-corners rejection and the base type short circuit can leave earlier bytes in place.

If all edges miss, the test uses a ray from `d₀n₀` through `d₀n₀ + n₀`, using plane slot 0. The face intersection requires a nonparallel ray and `t > 0`. Both comparisons with the quad's edge-derived half lengths include equality. If that test misses, the two diagonals are tested against candidate plane slots 2–5 regardless of candidate activity. A diagonal hit includes both segment endpoints and requires a signed value strictly above the stored float32 `−0.0010000000474974513` on every active plane.

Evidence: base dispatch at vtable `0x141a6ef90`, slot `+0xd8`, through `0x140feea10` to `0x140fe94e0`. Base comparisons `0x140fe95b0`–`0x140fe980b`, constants `0x141b5c0a4` and `0x141b5be6c`. Ordinary portal vtable `0x141800560`, slot `+0x10`, returns the descriptor at `0x14332e268` through `0x140213c50`. Descriptor initializer `0x1400e8540`–`0x1400e8555`. Compound expression `0x140ff79c0`–`0x140ff7ad3`, predicates at `0x140fe8e60` and `0x140fe93c0`. Quad clipping `0x140fdba07`–`0x140fdbb13` and `0x140fdbb80`–`0x140fdbf77`, with the early return at `0x140fdc0ed`. Ray and diagonals `0x140fdbf7d`–`0x140fdc38b`. Diagonal helper `0x140fdb830`–`0x140fdb96f`, tolerance `0x1417eab78`. The general behavior for degenerate or nonfinite geometry is **unverified**.

### G03. Rotation, plane orientation, and units (verified reads and comparisons, high; geometric deductions inferred)

The dirty corner rebuild reads stored matrix columns 0 and 2. Column 0 uses offsets `+0x1c`, `+0x28`, and `+0x34`. Column 2 uses `+0x24`, `+0x30`, and `+0x3c`. Let `X = size[0]·col0` and `Z = size[1]·col2`. The stored corner order is `T+X+Z`, `T+X−Z`, `T−X−Z`, `T−X+Z`. The two projected-eye comparisons use stored rows 1 and 2 directly. The corner and extent routines perform no separate transpose.

The plane helper forms `(B−A) × (C−B)` from the first three points. It normalizes above the stored float32 length `9.999999974752427e−7`. At or below that cutoff it returns a zero normal for finite inputs. It stores `d = n·A`. The opening builder reverses the winding when nominal `s` is positive. It keeps the winding when `s` is zero or negative. The active-plane test includes `n·p − d = 0` in the inside half-space.

**Inferred.** The corner formula gives nominal direction `+col1` for a proper rotation and positive half extents when the cross product exceeds the cutoff. The winding rule puts an off-plane eye on the negative side of a nondegenerate opening face. The arithmetic uses a common game coordinate scale for positions and half extents. With a unit normal, plane distance has the same scale and the normal is dimensionless.

The winding builder starts its temporary plane mask at `0x3f` and clears side-plane bits according to the edge bytes. `BSCompoundFrustum::AddPortalOpening` overwrites the copied mask with `0` for `|s| ≤ 5` and `0x3f` otherwise. This is the mask on the appended opening. G02's asymmetric near-plane interval is a separate test.

Evidence: corner rebuild `0x140fe8770`–`0x140fe88b6`, row comparisons `0x140fe9675`–`0x140fe96ea` and `0x140fe97a3`–`0x140fe9803`, plane helper `0x140ef74f0` and cutoff `0x141b5bdb0`. Winding `0x140fe8a60`, temporary mask `0x140fe8ae2` and `0x140fe8ce8`–`0x140fe8d21`, opening mask `0x140ff7e5d`–`0x140ff7f30`. Authored transform conventions, entrance/exit polarity, and SI conversion are **unverified**.

### G04. Visible set and culling cache (verified, high for the traced update)

The graph-backed camera update clears the visibility map and room accumulation list. Propagation gives a non-null seed a room-map entry. A null seed starts with the separate unbound frustum and a null FIFO entry. The accumulation list deduplicates non-null room pointers as they are dequeued.

On the traced camera path, a non-null destination gets a room frustum on its first insertion. A later crossing into a destination with a nonempty expression adds a union contribution. The contribution includes the opening and applicable source and destination constraints. Shared-node marking stores a pooled value under the shared-node key.

The room and shared-node consumers consult their respective keys when a graph entry is present. Each can continue after a miss in culling modes `0` and `2`. When the room path uses the stored frustum, it prepares the frustum before traversing the room's children.

The node stamp is written on the separate culling path. The bound-test cache in `BSMultiBoundNode::OnVisible` compares a 32-bit culling-service value with node offset `+0x134` by integer equality. It saves a mismatched value and refreshes the bound test. A zero cached classification also triggers the bound test. Mode `4` bypasses the stamp comparison and tests the shape directly. The generated layout names the node field `lastAccumTime`. The service value's meaning, its cadence, and the map's correspondence to every rendered frame are **unverified**.

Evidence: reset calls `0x1401a9841` and `0x1401a984d`. Seed and accumulation `0x141510168`–`0x1415102cb`, `0x141510318`–`0x141510346`, and `0x140fd95c0`. Destination insertion `0x1415106aa`–`0x1415106c3`. Expression union `0x1415104a3`–`0x141510552`, composition helpers `0x140ff8820` and `0x140ff8bb0`. Shared-node marking `0x1415106d4`–`0x1415106e6`. Consumers `0x140fcddd0`–`0x140fcded6` and `0x140fe9e20`–`0x140fe9ee4`. Cache `0x140ff2e06`–`0x140ff2e9d`.

### G05. Authored open state and missing room bound (verified, high for the traced branches)

- **Verified.** The traced camera gate has no direct read of `visibilityState` at `+0x40` or `twoSided` at `+0xf4`. The inspected creation branch sets `visibilityState` to zero. The inspected attachment writes the transform and dirty byte, assigns the shared node, and fills endpoint slots when the associated room resolves.
- **Verified.** The base and compound tests have the bypasses in G01. In the absent or empty destination room-expression path, the destination skip flag is set if the inherited source was dropped or already had the skip flag set. It is also set if the source has zero operators and all four edge bytes are zero.
- **Verified.** A null FIFO entry sets `visibleUnboundSpace` when dequeued. A null selected endpoint can reach that path. If the null endpoint equals the seed, the crossing goes directly to shared-node marking. A non-null endpoint takes the room path without a destination `multiBound` check in admission. The seed containment routine dereferences the room's `multiBound` at `+0x128` without a null guard at that access. The inspected regular attachment assigns the bound field before room registration.
- **Unverified.** The trace did not establish an authored “always open” flag or its upstream mapping. Runtime behavior for malformed or alternatively registered rooms with a null `multiBound` is also unverified.

Evidence: creation `0x14021322f`–`0x140213246`. Portal attachment `0x1402d7b9c`–`0x1402d7de3`. Gate `0x141510370`–`0x141510492`, derived flag `0x14151063e`–`0x1415106a3`. Null FIFO entry `0x141510318`–`0x141510354`. Seed containment `0x140fce0d0`–`0x140fce0da`. Bound assignment and registration `0x1402d7ae5`–`0x1402d7b58`, setter `0x1402dd220`, registration `0x140fda080`.

## Interpretation and alternatives

A recorded shared-node key suppresses another crossing of that key in the same update. A room expression can accumulate several portal contributions. The opening face has a geometric orientation relative to the eye. The relation between that orientation and the authored entrance and exit names remains unverified.

## Negative results and limitations

Static only. Runtime room visibility was not tested. The findings cover the pinned build and cited paths. Authored open-state decoding, alternate registration, service stamp cadence, and general behavior for degenerate or nonfinite inputs remain unverified.

## Independent review (2026-11-21)

Reviewer: GPT 6.2 Sol (`gpt-6.2-sol`) through Codex, high effort, fresh context, separate run. The reviewer did not author or draft this finding. The review was arranged by the skyrim-research department lead (Claude Sonnet 5.5), which also did not draft the finding. Date: 2026-11-21.
Source reviewed: the draft of this finding, against the pinned image `sse-steam-1-7-104` (measured SHA-256 equals the pin in the "Target build id / image SHA-256" line above), its native listing, and the generated CrashLogger metadata at `3b2d3051afa64fd02862a831389cdef8d26b292b`. Exposure of the review: mixed (retail executable and its native listing, generated metadata, the draft). No Mudcrab source or sibling implementation was used. Method: the reviewer traced the key branches and operands independently, checked stored values and virtual table entries in the image, and checked every cited VA and generated name. This is a static finding review. It is not match evidence for any function. It does not decide transfer eligibility (`docs/clean-room.md`).

The observations above already include the corrected text. The evidence addresses were extended where the review asked.

| Group | Verdict | One-line status |
|---|---|---|
| G01 | Corrected | Gate order holds. The queue evidence is extended and the 25-operator threshold is scoped to absent or empty room expressions. |
| G02 | Corrected | Base inequalities hold. The exact type-descriptor return, clipping boundaries and plane-derived ray are specified. |
| G03 | Corrected | Column and row reads hold. The normalization threshold is added and the temporary and stored plane masks are distinguished. |
| G04 | Corrected | Room and shared-key entries hold. Union, consumer modes and cache refresh are qualified. |
| G05 | Corrected | The traced bypass and bound accesses hold. The derived flag is scoped and null endpoints are distinguished from null bounds. |

Summary: 0 groups confirmed unchanged, 5 corrected, 0 rejected.

## Reviewer and outcome

Reviewed independently on 2026-11-21 by GPT 6.2 Sol (Codex, high effort, fresh context), separate from author MR-2. Outcome: 0 confirmed unchanged, 5 corrected, 0 rejected. Static only. A review verdict is not match evidence, and transfer eligibility is not decided. Unverified: entrance/exit polarity, culling stamp cadence, authored always-open behaviour, and runtime handling of rooms with null bounds.
