Transfer status: UNREVIEWED

# Finding: object LOD segment order and large-reference suppression

Status: OBSERVED where verified. INFERRED and UNVERIFIED items are marked. Static only: static analysis of the pinned image and shipped assets, plus bounded synthetic checks in the independent review. No runtime capture.

Author: MR-6, a `gpt-6.2-sol` research run via Codex (not the reviewer below).  
Human operator: Taylor.  
AI assistance / model: `gpt-6.2-sol` via Codex.  
Date (UTC): 2026-11-22.  
Target build id: `sse-steam-1-7-104`. The measured image SHA-256 `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f` equals the pin in [builds/target.json](../builds/target.json). Both runs measured the hash and asserted equality.  
Principal function RVAs (descriptive labels are GUESS): `0x518fa0` (per-cell object filter), `0x518d40`, `0x51a6c0`, `0xff60a0` (segment stream reader), `0xff6780` and `0xff6850` (whole-shape helpers), `0xff6800` (per-slot enable helper), `0xff6be0` (large-reference reader), `0xf0fe70`, `0x519ab0`, and `0x291cf0` (large-reference cell predicate).  
Source exposure: mixed. Both runs read the operator's pinned executable and shipped mesh archives, and used the public generated layout names. The author consulted earlier object LOD research and its review. The reviewer also read five shipped INI templates and ran isolated native checks with synthetic inputs. The analysis used no sibling implementation and no downstream source.  
Sources and immutable revisions: the pinned image and shipped assets, generated layout metadata at `3b2d3051afa64fd02862a831389cdef8d26b292b`, and `findings/object-lod-retail-facts.md` §C at `790aaeb65be00c5f5828f44ff0bf15ed7cc46dfa`.  
Intended recipient: Skyrim Research department lead for boundary review under [docs/clean-room.md](../docs/clean-room.md). The proposed downstream use is Mudcrab's object LOD work. The maintainer's transfer decision is pending.

Name provenance: `BGSTerrainManager.segmentedBlockLevel`, `TES.currentGridX/Y`, and `TESWorldSpace.largeRefData` are CRASHLOGGER_PDB(59818@2026.10.24) names. Type names come from serialized or native data. Setting names come from the image and shipped INIs. Descriptive function names are our own and are GUESS.

Addresses are virtual addresses at image base `0x140000000`. **Verified** identifies facts checked against the pinned image or shipped inputs. **Inferred** identifies a possible explanation. **Unverified** identifies a result the checks did not establish.

## Question and method

Which cell does each width-4 object LOD mesh (BTO) segment index address? How do empty and surplus slots affect the filter? What does the large-reference marker do?

Both runs checked the stream reader, the per-cell filter, its direct callers, and the worldspace predicate. The reviewer checked synthetic slot and cell inputs and independently parsed both shipped mesh archives. The Tamriel analysis applied the serialized shape transform to each indexed vertex. The scan checked parent identity for all shapes in the geometry comparison.

## Observations

### G01. Width-4 segment order

**Verified.** The per-cell filter starts at ordinal zero on each shape. For a width-4 node, its ordinal is `i = 4 × dx + dy` for offsets `dx,dy` from 0 through 3. The inverse for a block origin `(x,y)` is `(x + ⌊i/4⌋, y + (i mod 4))`, with integer quotient and remainder. The order is X-major, with Y advancing first. The filter uses the signed node origin and these offsets for the cell key. The shape supplies the slots and their stored count. Geometry and the serialized segment fields supply no cell coordinates to this filter. Evidence at `0x1405190bd–0x140519130`, `0x140519247–0x140519268`, and `0x14051a6c0`.

**Confidence: high** for the width-4 rule on this path. Both synthetic shapes produced the same ordinal-to-cell sequence.

### G02. Empty slots, surplus slots, and coarser widths

**Verified.** The `BSSubIndexTriShape` stream reader reads a 32-bit count, then a leading byte, a start index, and a triangle count for each slot. A zero-triangle slot retains its ordinal and the reader sets its start to zero. The per-slot enable helper requires a positive triangle count. The width-4 per-cell loop visits existing ordinals in 0–15 and skips missing slots. Separate whole-shape helpers can access slots beyond 15. Both helpers accessed all 20 supplied slots in the checked paths. Evidence at `0x140ff613b–0x140ff6287`, `0x140ff6780`, `0x140ff6800–0x140ff6849`, `0x140ff6850`, and `0x1405190bd–0x140519268`.

**Verified.** The per-cell body uses the node's width. Forced entries at widths 8, 16, and 32 processed 64, 80, and 80 of 80 supplied slots, respectively. The three direct retail callers require the width to equal `BGSTerrainManager.segmentedBlockLevel` (CRASHLOGGER_PDB(59818@2026.10.24)), initialized to 4. At that value the three call sites bypass the per-cell body for widths 8, 16, and 32. Evidence at `0x140519015–0x140519026`, `0x14050578c`, `0x140517c4a`, `0x140518362`, and `0x140515a01–0x140515a07`.

**Verified.** Both archives together contain 744 width-4, 248 width-8, and 86 width-16 BTOs. Width-4 shapes store 1–16 slots. All 384 width-8 shapes and all 152 width-16 shapes store one slot each, with triangles. The scan found no width-32 BTO.

**Confidence: high** for serialization and the static branches checked here. Runtime gate values, other coarse processing paths, and drawing surplus slots remain **unverified**.

### G03. Tamriel geometry comparison

**Verified for this census.** The 517 width-4 Tamriel files contain 1,408 shapes and 6,730 nonempty slots. Excluding 22 one-slot shapes leaves 6,708 nonempty slots. The test compares the indexed geometry after the shape transform with the assigned cell's world-space XY rectangle. Each cell is 4,096 units wide. Boundary contact counts and the test adds no tolerance.

| Fit rule for the 6,708 slots | Slots that pass |
|---|---:|
| Indexed-vertex XY bounds overlap the assigned cell | 6,698 |
| At least one indexed vertex is inside or on the boundary | 6,697 |
| At least one projected triangle intersects the cell | 6,697 |
| Bounds overlap using the axis-transposed mapping | 2,403 |

The ten bounds misses have a gap on at least one axis. Exact projected triangle intersection on these same inputs requires bounds overlap.

**Unverified.** The downstream team's supplied 6,706-of-6,708 result has no documented geometry test or case identities. If the population is the same, its rule accepts at least eight of the ten disjoint-bound cases in this scan. The method difference, identities of the two supplied misses, and cause of either set of mismatches remain **unverified**.

**Confidence: high** for the counted population and stated fit tests. The downstream cohort and test would allow case-by-case comparison.

### G04. Large-reference marker and segment suppression

**Verified.** `BSDistantObjectLargeRefExtraData` stores a single Boolean byte after the base extra-data name reference. The reader normalizes nonzero values to true and stores the Boolean at runtime offset `+0x18`. The filter looks for this class and reads the value per shape. The marker carries no cell list or reference identifiers. The archive census found 1,522 true markers, attached to 1,522 shapes in 721 width-4 BTOs. Widths 8 and 16 contain no markers. Evidence at `0x140ff6be0`, `0x140f0fe70–0x140f0fecb`, `0x140ff6da0`, and `0x14051907d–0x14051909e`.

**Verified.** In the checked path the near-grid route can suppress a segment for a resolved exterior cell with state byte `+0x44` equal to 7. This route has separate eligibility gates, including a global or helper condition. When it suppresses a slot, the filter skips the large-reference test for that slot. This route can operate without a true shape marker. Evidence at `0x140519130–0x1405191e7`. The runtime sources and meaning of the additional gates remain **unverified**.

**Verified.** On the separate large-reference route, the node must overlap the large-reference grid and the shape marker must be true. A true cell predicate disables a nonempty slot. The predicate requires `uLargeRefLODGridSize > uGridsToLoad`. Each absolute cell-coordinate offset from the current grid center must be at most half the large-reference grid size, rounded down. The predicate then looks up the packed cell key in a table for the worldspace. The matching entry's unsigned 32-bit field at `+0x04` must be strictly below the 32-bit global at `0x143275610`. Equality fails. A missing table or key also fails. The checked per-cell update can enable a nonempty slot if neither route suppresses it. Evidence at `0x1405191e9–0x14051922c`, `0x140291d0c–0x140291e56`, and `0x140ff6800–0x140ff6849`. The predicate reads the table pointer at an offset beyond the named `BGSLargeRefData` extent in the cited generated layout, so the table stays unnamed here.

**Verified.** The `[General]` settings are global values. Compiled `uGridsToLoad` is 5 at `0x142079eb0`. Compiled `uLargeRefLODGridSize` is 9 at `0x14207b628`. Shipped Low, Medium, High, and Ultra presets set the large-reference grid to 5, 7, 9, and 11, respectively. Neither key appears in `Skyrim_Default.ini`. The four presets omit `uGridsToLoad`.

**Confidence: high** for the marker ownership, setting values, and stated static suppression conditions. The table field's meaning, threshold producer, plugin import, and full-reference visibility remain **unverified**.

## Interpretation and alternatives

**Inferred.** Geometry authored outside its assigned cell or grouped from another cell could explain a mismatch. The geometry test measures where indexed triangles lie. The filter selects each cell from the ordinal.

## Negative results and limitations

The counts cover the operator's shipped archives and the five INI templates. Synthetic inputs establish conditions along the tested instruction paths. The static trace stops at segment eligibility. It supplies no frame timing and no full-reference draw result. Custom BTOs, custom asset rendering, effective user settings, and visible takeover remain **unverified**.

## Independent review (2026-11-22)

Reviewer: `gpt-6.2-sol` through Codex, high effort, fresh context, separate run. The reviewer did not author or draft this finding. Date: 2026-11-22.
Source reviewed: the draft of this finding, against the pinned image `sse-steam-1-7-104` (measured SHA-256 equals the pin in [builds/target.json](../builds/target.json)), both shipped mesh archives, five shipped INI templates and the generated public layout names at `3b2d3051afa64fd02862a831389cdef8d26b292b`. Exposure of the review: mixed (retail executable, shipped assets, generated names, the draft). Method: the reviewer re-read the pinned sources, parsed the archives independently, and ran bounded native checks with synthetic state and stubbed dependencies. This is a static finding review. It is not match evidence for any function. It does not decide transfer eligibility ([docs/clean-room.md](../docs/clean-room.md)).

The observations above already include the corrected text. A Claude Sonnet 5.5 worker only assembled this file from the corrected text and drafted nothing.

| Group | Verdict | One-line status |
|---|---|---|
| G01. Width-4 segment order | Confirmed | X-major ordinals restart on each shape. Y advances first. The cell lookup uses the signed node origin and ordinal-derived offsets. |
| G02. Empty slots, surplus slots, and coarser widths | Corrected | The 0–15 bound applies to the width-4 per-cell loop. Whole-shape helpers can touch surplus slots. Forced widths and the call-site gate are recorded. |
| G03. Tamriel geometry comparison | Confirmed | 6,698 bounds overlaps out of 6,708 reproduced. Exact projected triangle intersection gives 6,697. The supplied 6,706 result still lacks a reproducible method. |
| G04. Large-reference marker and suppression | Corrected | Marker storage, global grid settings, the per-worldspace lookup, the strict unsigned threshold, and the separate near-grid state route are stated. |

Summary: 2 groups confirmed, 2 corrected, 0 rejected.

## Reviewer and outcome

Reviewed independently on 2026-11-22 by `gpt-6.2-sol` (Codex, high effort, fresh context), separate from the author. Outcome: 2 confirmed (G01, G03), 2 corrected (G02, G04), 0 rejected. Static only. A review verdict is not match evidence, and transfer eligibility is not decided. Unverified:

- The downstream 6,706-of-6,708 result and its two misfits. They cannot be verified or explained. The static overlap census gives 6,698 of 6,708 under the zero-tolerance bounds test stated in G03. The method difference and the cause of the ten disjoint bounds are unknown.
- Visible takeover timing of full references, which full references the worldspace data selects, how plugins populate the runtime tables, the meaning of the table entry field, and the runtime source of the threshold global.
- Rendering of custom surplus slots (more than 16 slots on a width-4 shape), custom width-32 payloads and other coarse processing paths, and the runtime values of the call-site width gate.
- The runtime sources and meaning of the extra near-grid gates.
- Live cell state, draw output, and effective user INI settings.
