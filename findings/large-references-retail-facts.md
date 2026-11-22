Transfer status: UNREVIEWED

# Finding: large-reference selection, loading, and object LOD suppression

Status: OBSERVED where verified. INFERRED and UNVERIFIED items are marked. Static only: static analysis of the pinned image, the shipped master and shipped INIs. No runtime capture.

Author: the Sol research run, `gpt-6.2-sol` via Codex (not the reviewer below).  
Human operator: Taylor.  
AI assistance / model: `gpt-6.2-sol` via Codex.  
Date (UTC): 2026-11-22.  
Target build id: `sse-steam-1-7-104` (retail Skyrim SE 1.7.104.0). The measured image SHA-256 `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f` equals the pin in [builds/target.json](../builds/target.json). Both runs measured the hash and asserted equality.  
Principal function RVAs (descriptive labels are GUESS): `0x30ba10`, `0x28ffb0`, `0x290e50`, `0x1a0630`, `0x2921f0`, `0x2925b0`, `0x2939f0`, `0x2044e0`, `0x2942a0`, `0x292330`, `0x292990`, `0x518fa0`, `0x519ab0`, and `0x291cf0`.  
Source exposure: mixed. Both runs used the operator's pinned executable, the shipped `Skyrim.esm` and shipped INIs, the installed example INIs, and public generated layout names. The reviewer also parsed both shipped mesh archives and consulted the earlier object LOD segments finding and its review. The analysis used no sibling implementation and no downstream source.  
Sources and immutable revisions: `Skyrim.esm` SHA-256 `e198c3b85e5e48e0c92a6580d8f66e644256b68d812ee32b61735cf9b753df73`. Generated layout metadata at `3b2d3051afa64fd02862a831389cdef8d26b292b`. `findings/object-lod-retail-facts.md` §C at `790aaeb65be00c5f5828f44ff0bf15ed7cc46dfa`. Reviewed draft SHA-256 `3040f9d442898a4a36458a59290b99d982cfa4af4a79664dc56fc6845e3e1b5d`.  
Intended recipient: Skyrim Research department lead for boundary review under [docs/clean-room.md](../docs/clean-room.md). The proposed downstream use is the Mudcrab object LOD work, where distant rocks go missing. The maintainer's transfer decision is pending. This finding names no cause for that symptom.

Name provenance: layout names and fields taken from the public generated tables carry the label CRASHLOGGER_PDB(59818@2026.10.24) at each use below. Task, extra-data, and setting-collection type names come from native type metadata (EXE_RTTI). Setting names come from the image and the INIs. Descriptive function labels are our own and are GUESS.

Addresses are RVAs at image base `0x140000000`. [findings/object-lod-segments-retail-facts.md](object-lod-segments-retail-facts.md) (PR #816) writes its addresses as virtual addresses at the same base. **Verified** identifies a result checked against the pinned image or shipped inputs. **Inferred** identifies a possible explanation. **Unverified** identifies a result the checks did not establish. Keep listings of the game files in `.local/`. Nothing game-derived is in this file except counts, field offsets and addresses.

## Question and method

What selects a large reference, which cells can promote it, and when does its distant segment yield? Both runs traced the native importer, setting and grid reads, reference lifecycle, and object LOD filter. The reviewer independently counted master records, followed both timing gates, and compared the filter with the corrected object LOD segments finding. A plugin scan compared the `RNAM` tuples of Tamriel with reference positions and parent cells. This is static only.

## Observations

### G01. Selection at plugin load and the separate size test

**Verified.** `WRLD.RNAM` supplies large-reference membership for that worldspace. Each subrecord has a packed header cell key, an unsigned 32-bit tuple count, and tuples with a FormID and a packed placement cell key. The packed keys store signed 16-bit Y low and signed 16-bit X high. The importer remaps FormIDs and fills the cell-to-FormID and FormID-to-cell maps (`TESWorldSpace.largeRefData` at `+0x250`, CRASHLOGGER_PDB(59818@2026.10.24)). It compares the two serialized keys to build the filtered cell map, with duplicate checks. Promotion reads the filtered map. The comparison uses neither the reference's parent record nor its header flags or size. Evidence at `0x30c01f–0x30c029`, `0x28ffb0`, `0x2900bb–0x29025b`, `0x290406–0x290810`, and `0x2926e5–0x292734`.

**Verified for Tamriel in shipped `Skyrim.esm`.** The census found 8,455 `RNAM` subrecords with 8,455 unique header keys and 160,247 tuples. The tuples cover 34,034 distinct FormIDs and 140,453 distinct header, placement, and FormID triples. All placement keys match the reference positions in `REFR.DATA`, at 4,096 units per cell. The 34,569 equal-key tuples cover all 34,034 FormIDs. For 120,659 tuples with reference header bit `0x400` clear, the parent `CELL.XCLC` matches the tuple's placement cell. For the other 39,588 tuples the parent coordinate differs. Among the equal-key tuples, 1,070 have bit `0x400` set and 6,946 have bit `0x8000` set. Neither bit is required for filtered membership. Both bits also occur clear.

**Verified field scope.** The Tamriel scan interpreted `WRLD.EDID` and `WRLD.RNAM`, `REFR` header FormID and flags, `REFR.DATA` XY, `CELL.XCLC` XY, and the group links used to find parent cells. It enumerated the other Tamriel `WRLD` tags without interpreting their payloads.

**Verified.** The size predicate accepts a Static base or a MovableStatic base with bit `0x4` set at offset `+0x88`. It requires a size strictly greater than `fLargeRefMinSize`, compiled to 1024.0. It uses the norm of three floats if extra-data type `0x67` supplies them. Otherwise it uses half the base bounds diagonal times the reference scale. The dynamic insertion route requires this predicate and clear runtime form bit `0x20`. The importer has no size check. Some worker and sky-cell paths continue after a false size result, with different cleanup or flag behavior. The post-load timer also has a size-gated branch. The evidence gives separate input rules for import and for dynamic insertion. It establishes neither a universal joint requirement nor a universal size-only alternative for promotion. Evidence at `0x290e50–0x290f0b`, `0x290cd0–0x290e2d`, `0x2df491–0x2df504`, `0x204a81–0x204a9f`, `0x311270–0x31137e`, and `0x193fbc–0x193fdb`.

**Confidence: high** for the imported map, the master census, and the stated size branches. The authoring rule for the shipped lists, the meaning of the three floats, and general cross-plugin override behavior remain **unverified**.

### G02. Grid setting, units, and center

**Verified.** The executable registers the following settings. The value fields are eight bytes before their name pointers.

| Key | Collection | Value RVA | Compiled value |
|---|---|---:|---:|
| `[General] uGridsToLoad` | `INISettingCollection` | `0x2079eb0` | 5 |
| `[General] uLargeRefLODGridSize` | `INIPrefSettingCollection` | `0x207b628` | 9 |
| `[General] uLMaxCellDemotePerFrame` | `INISettingCollection` | `0x207b640` | 1 |
| `fLargeRefMinSize` | `GameSettingCollection` | `0x207b610` | 1024.0 |

**Verified.** The size threshold is a game setting. Its registered key has no INI section. `Skyrim_Default.ini` contains none of the four keys. Low, Medium, High, and Ultra ship large grid widths of 5, 7, 9, and 11 in `[General]` and omit the other three keys. The two installed example INIs beside the executable contain ordinary width 5 in `Skyrim.ini` and large width 9 in `SkyrimPrefs.ini`. No `SkyrimCustom.ini` is in that directory. These values describe the files examined. Registration evidence at `0x17436c3` and `0x1747cb3–0x1747d53`.

**Verified for the traced file passes.** The startup path attempts `Skyrim.ini`, `SkyrimCustom.ini`, and `Skyrim.ini` again through the main collection. It next attempts `Skyrim.ini` then `SkyrimPrefs.ini` through the preference collection. The unsigned reader uses the current value as fallback. Thus the final successful main read reapplies a readable duplicate from `Skyrim.ini`. A readable preference duplicate in `SkyrimPrefs.ini` takes precedence over the preference read from `Skyrim.ini`. A separate routine reads main then custom through the main collection and prefs through the preference collection. The first startup path can copy `Skyrim_Default.ini` to create the main file. Evidence at `0x652b83–0x652b87`, `0x653195–0x653378`, `0x65dcf8–0x65dd43`, `0x371300–0x371555`, and `0xfd1150–0xfd1167`. Later pass invocation, any live reload path, and effective session values remain **unverified**.

**Verified.** The bulk promotion sweep and the BTO cell predicate require `uLargeRefLODGridSize > uGridsToLoad`. Both use `TES.currentGridX/Y` (CRASHLOGGER_PDB(59818@2026.10.24)). Exterior cells are 4,096 world units wide. The traced normal exterior caller supplies the player position, which the exterior update converts to cell coordinates. The fixed-center branch uses bit `0x40` in worldspace flags and the fixed center (`TESWorldSpace.flags` and `fixedCenter` at `+0xa4/+0xa6`, CRASHLOGGER_PDB(59818@2026.10.24)). The `WRLD` loader takes these fields from `DATA` and `WCTR`, respectively. The per-cell promotion path exits if the active worldspace has that bit set. The shipped master has 19 worldspaces with `WCTR`, all with `RNAM` and that `DATA` bit set. Tamriel has no `WCTR`. Evidence at `0x65908e–0x6590a7`, `0x1a04ef–0x1a050e`, `0x1a1220–0x1a123d`, `0x30bc68–0x30bcc2`, `0x30c247–0x30c358`, and `0x292649–0x292661`.

**Verified.** For width N, the bulk sweep visits N cells per axis from center minus `floor(N/2)`. The per-cell gates allow an absolute offset at most `floor(N/2)` on each axis. Even widths therefore admit an extra positive edge in the per-cell test. The BTO overlap test uses a cached width and admits contact with either rectangle boundary. With the compiled widths, the large-reference width is 9 and the near grid is 5. Evidence at `0x29226d–0x2922f2`, `0x2925ff–0x292643`, `0x291d0c–0x291d54`, and `0x519ab0–0x519aea`.

**Confidence: high** for the defaults, collection ownership, stated file passes and grid geometry. A live startup trace with conflicting keys would establish the effective values for a session.

### G03. Promotion beyond the ordinary grid and demotion

**Verified.** One exterior setup path calls the promotion sweep after its ordinary-grid loops. The sweep includes inner cells and can reach outside that grid. Per-cell promotion checks the active worldspace, bounds, worldspace flags, existing tracking, and the filtered FormID bucket. It attempts to resolve each FormID as a full `TESObjectREFR`. One resolved-reference branch with runtime form bit `0x8` processes the reference immediately. Another puts its FormID and packed cell key into `QueuedPromoteLargeReferencesTask`. The task constructor also receives a sky-cell pointer. The worker can resolve eligible references and collect handles. Evidence at `0x1ab12e–0x1ab3e4`, `0x2925b0–0x29283f`, `0x2939f0`, and `0x2047a0–0x204810`.

**Verified.** The completion callback resolves handles, updates reference extra data, and can move a reference into the active worldspace's `skyCell` (`+0xf8`, CRASHLOGGER_PDB(59818@2026.10.24)). The accessor may use a parent's sky cell when parent-use bit `0x40` is set. Otherwise it can return or allocate the current world's sky cell. The worldspace has a separate `persistentCell` field (`+0x88`, CRASHLOGGER_PDB(59818@2026.10.24)). In the native `QueuedReference` path, `0x193839` calls `Load3D`. The `Set3D` call at `0x193c8a` takes null and clears 3D. A completion branch reaches the large-reference timer after a passing size test. Evidence at `0x2942dd–0x29435c`, `0x2944d2–0x2944e6`, `0x311270`, `0x311640–0x311727`, and `0x193fbc–0x193fdb`.

**Verified.** Demotion selects tracked cells outside the new square. A capped branch uses `uLMaxCellDemotePerFrame`. The demoter removes task and deadline entries, cancels queued work, and revisits the filtered references. For eligible references in a checked cell branch it clears 3D, removes the reference from its current cell, and calls additional cleanup. Evidence at `0x1a0b47`, `0x292330`, `0x2924ed–0x2924fa`, `0x292990`, and `0x292be1–0x292c94`.

**Confidence: medium** for the full lifecycle and high for the listed task and callback branches. The traced cell-level gate contains no separate eye-distance or frustum test. Successful dispatch from every promotion task to non-null 3D, the no-model case, visible attachment, object release, final destruction, and behavior outside the checked paths remain **unverified**.

### G04. BTO marker, cell predicates, and refresh

**Verified.** The `BSDistantObjectLargeRefExtraData` payload has a Boolean byte after the base extra-data name reference. The reader normalizes nonzero to true and the filter reads it per shape. The marker has no reference IDs or cell list. Both mesh archives together contain 1,522 marked shapes in 721 width-4 BTOs. The scan found no markers at widths 8 or 16. In a width-4 node the segment's ordinal is `4 × dx + dy` for cell offsets from the signed node origin. Y advances first and the ordinal resets on each shape. Evidence at `0xff6be0`, `0xf0fe70–0xf0fecb`, `0x51907d–0x519130`, and `0x519247–0x519268`.

**Verified.** The ordinary near-grid route can suppress a nonempty slot before the marker branch. It requires a resolved eligible exterior cell, cell state 7, and a timing gate or override. The helper compares the unsigned clock with a deadline at loaded-cell data `+0x178` (`TESObjectCELL.loadedData` at `+0x130`, CRASHLOGGER_PDB(59818@2026.10.24)). On the checked exterior-cell setup path the deadline is initialized to current time plus 2,000 if the distant-reference count at `+0x174` is zero. The other branch initializes it to `0xffffffff`. A checked completion path also writes current time plus 2,000 when the count reaches zero. The filter can bypass the deadline helper through a global at RVA `0x3203340`. Evidence at `0x519130–0x5191e7`, `0x2c5ce0–0x2c5cfc`, `0x2bd21e–0x2bd25c`, and `0x2c9962–0x2c99b5`.

**Verified.** Fallback large-reference suppression requires node overlap and a true shape marker. It suppresses the assigned nonempty segment when the width exceeds `uGridsToLoad`, the cell passes both inclusive bounds, and its packed key has a deadline strictly below the unsigned clock. A missing match or equality fails. The table is rooted at worldspace `+0x320` with its backing pointer at `+0x340`. The table is not named in the cited generated layout. It is the same pointer that [findings/object-lod-segments-retail-facts.md](object-lod-segments-retail-facts.md) (PR #816) reads, through the large-reference data at `+0x250` plus offset `+0xf0`. That file lists the meaning of the entry field and the source of the clock as unverified. This file resolves both, as the next paragraphs state. The predicate, the unsigned strict comparison and the near-grid route agree between the two files. The table tracks promotion separately from imported `RNAM` and from the near-cell deadline. A positive count at insertion sets the deadline to `0xffffffff`. A nonpositive count sets it to current time plus 2,000. The recorded final decrement sets the same deadline and stores `0xffffffff` as the count sentinel. The checked immediate path excludes refs already in state 2 from the pending count. Evidence at `0x5191e9–0x51922c`, `0x291d0c–0x291e56`, `0x292804–0x292813`, `0x2928cd–0x29291f`, `0x291044–0x2910aa`, and `0x294415–0x294480`.

**Verified.** Both checks read the timer field at RVA `0x3275610`, named `BSTimer.smoothedRunTimeMS` in the generated layout (CRASHLOGGER_PDB(59818@2026.10.24)). The routine called at `0x659d80` updates that field. A pause-related path also writes it at `0xce3a98`. The counter helper at `0xce8430` uses `QueryPerformanceCounter`. The delay uses engine milliseconds. Elapsed wall-clock time across pause or timing adjustments remains **unverified**.

**Verified.** Three direct callers run the segment filter on initial object payload attachment, overlap refresh, or refresh-enabled object traversal. Each requires node width to equal `BGSTerrainManager.segmentedBlockLevel` (CRASHLOGGER_PDB(59818@2026.10.24)), initialized to 4. The terrain manager has conditional refresh branches. A deadline crossing can change the result at the next eligible evaluation. Evidence at `0x50578c`, `0x517c4a`, `0x518362`, `0x515a07`, `0x516320`, `0x516361`, `0x5163b5`, and `0x51643e`.

**Confidence: high** for the marker, ordinal, and two predicates. **Medium** for refresh timing. Immediate filter calls at cell attach or deadline crossing, unconditional per-frame refresh, same-frame handover, and draw coverage remain **unverified**.

## Interpretation and alternatives

These items are candidate checks for a missing distant rock. They are not findings about a cause.

**Inferred.** Check missing effective filtered membership, a cell outside the effective square, large width at or below ordinary width, absent active worldspace, the fixed-center flag, or failed reference resolution. Each can block the relevant traced promotion route. Below-threshold size can block the size-gated dynamic or timer routes.

**Inferred.** A marked shape can lose a segment when the cell predicate passes. A full model for a particular rock can still be missing, because the predicate only tests cell-level state.

**Unverified.** The downstream symptom has no confirmed cause. The independent review inspected no downstream code, configuration, or failing rocks.

## Negative results and limitations

The evidence establishes the static cell and reference rules for the pinned build. The counts cover the operator's shipped master, two shipped mesh archives and the shipped and installed INIs. They cover no plugin outside the shipped master. This file gives no visual result, live INI precedence, loader scheduling guarantee, or same-frame handover. The cause of the downstream missing rocks, their full-model availability, and on-screen takeover remain **unverified**.

## Independent review (2026-11-22)

Reviewer: `gpt-6.2-sol` through Codex, high effort, fresh context, separate run. The reviewer did not author or draft this finding. Date: 2026-11-22.
Source reviewed: the draft of this finding (SHA-256 above), against the pinned image `sse-steam-1-7-104` (measured SHA-256 equals the pin in [builds/target.json](../builds/target.json)), the shipped `Skyrim.esm`, two shipped mesh archives, five shipped INI templates, two installed example INIs and the generated public layout names at `3b2d3051afa64fd02862a831389cdef8d26b292b`. Exposure of the review: mixed (retail executable, shipped assets, generated names, the draft). Method: the reviewer re-read the pinned sources, parsed the master and archives independently, and compared the filter with the corrected object LOD segments finding. This is a static finding review. It is not match evidence for any function. It does not decide transfer eligibility ([docs/clean-room.md](../docs/clean-room.md)).

The observations above already include the corrected text. A Claude Sonnet 5.5 worker only assembled this file from the corrected text and drafted nothing.

| Group | Verdict | One-line status |
|---|---|---|
| G01. Selection | Corrected | The importer compares two packed keys from `RNAM`. Imported membership and the size-gated update paths have different requirements. |
| G02. Grid and settings | Corrected | The defaults and width rules hold. The setting collections are specified, file precedence is scoped to the traced passes, and `WRLD.DATA` and `WCTR` bind to the fixed-center branch. |
| G03. Promotion and demotion | Corrected | Reference resolution, queuing, and sky-cell transfer hold. The cited `Set3D` call clears 3D. The demotion branch that removes a reference is stated and the attachment chain stays unverified. |
| G04. BTO suppression | Corrected | The marker and the segment order agree with the object LOD segments finding. The pending-count threshold is corrected and two distinct deadlines on the same engine clock are identified. |

Summary: 0 groups confirmed, 4 corrected, 0 rejected.

## Reviewer and outcome

Reviewed independently on 2026-11-22 by `gpt-6.2-sol` (Codex, high effort, fresh context), separate from the author. Outcome: 0 confirmed, 4 corrected (G01, G02, G03, G04), 0 rejected. Static only. A review verdict is not match evidence, and transfer eligibility is not decided. Unverified:

- Exact refresh timing: immediate filter calls at cell attach or deadline crossing, unconditional per-frame refresh, same-frame ordering, and elapsed wall-clock time across pause.
- On-screen takeover: draw coverage and the handover from distant segment to full model.
- Shipped list authorship: which tool or rule produced the `RNAM` population, and the meaning of the three floats behind extra-data type `0x67`.
- Plugin override behavior: how lists from several plugins combine.
- INI precedence details: which later startup routines run in a live session, any live reload path, the effective session values, and the source of a serialized fixed center beyond the importer binding.
- Full-model attachment and release: dispatch from every promotion task to non-null 3D, the no-model case, visible attachment, object release, final destruction, and paths outside the checked branches.
- The cause of the missing distant rocks downstream. The candidate checks under "Interpretation and alternatives" are inferred only. No downstream code, configuration, or failing rock was inspected.
