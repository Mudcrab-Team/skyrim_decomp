Transfer status: UNREVIEWED

# Finding: placed LOD statics and Markarth terrain texture fallback

| Item | Evidence record |
|---|---|
| Status | OBSERVED for verified claims. INFERRED and UNVERIFIED items are marked. Static analysis only. No runtime capture. |
| Author | The Sol research run, `gpt-6.2-sol` via Codex (not the reviewer below). |
| Human operator | Taylor. |
| Reviewer | A separate `gpt-6.2-sol` run via Codex, high effort, fresh context. See "Independent review" below. |
| Date | Review in 2026-11-22 CST (2026-11-23 UTC). |
| Reviewed draft SHA-256 | `2372a9ef3b06322e671dd163c5b602e340e47ac43086dba97ced7826296f4465` |
| Target build and SHA-256 | `sse-steam-1-7-104`, `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f`. Both runs asserted the measured image hash against the project pin in [builds/target.json](../builds/target.json). |
| Source exposure | Mixed. Both runs used the operator's pinned executable, shipped plugin records, terrain mesh fields, archive indices, and generated layout metadata. The reviewer independently parsed the plugins and reran the asset scans. No sibling source was used. |
| Immutable source revisions | Prior findings #675, #816, #821, and #822 and generated metadata at `1d5e0c441992ea7824658d6920098bc852a5fa57`. CommonLibSSE-NG labels at `b93280e832f263dbef44e44cbe2936622a02f91a`. |
| Name provenance | Generated layout names, including `kHasDistantLOD`, are taken from the public generated tables and carry the label CRASHLOGGER_PDB(59818@2026.10.24) at each use below. CommonLibSSE-NG supplies the STAT-specific flag label and `kHidden`. Descriptive function labels are our own and are GUESS. Editor IDs and setting names come from the shipped records and the image. |
| Intended recipient | Skyrim Research department lead for boundary review under [docs/clean-room.md](../docs/clean-room.md). Proposed downstream use: the Mudcrab LOD work. A downstream report gives a count of 117 from a pack database ([issue comment](https://github.com/Mudcrab-Team/mudcrab/issues/934#issuecomment-7088619354)) and white castle surfaces. That report supplies no query or input manifest for the count. This finding names no cause for the white surfaces. |

All addresses are RVAs for the pinned build at image base `0x140000000`. **Verified** identifies evidence from the pinned image or the scanned shipped inputs. **Inferred** identifies a possible interpretation of those results. **Unverified** identifies an open result. Keep listings of the game files in `.local/`. Nothing game-derived is in this file except counts, field offsets, addresses and shipped editor IDs.

## Review verdicts

| Group | Verdict | Main correction |
|---|---|---|
| G01. Q1, flag and census | Corrected | Scope the flag name to the observed readers and document the tested rules behind the count. |
| G02. Q2, loading and visibility | Corrected | Tie queued 3D to ordinary cell attachment and qualify the sky-cell visibility decision. |
| G03. Q3, linkage and RNAM | Corrected | Distinguish promotion from BTO suppression and identify the second full castle placement. |
| G04. Item 10, terrain texture lookup | Corrected | Distinguish empty slots from failed requests and identify the point getter's result as a texture pointer. |

## Questions and method

The review checked the retail use of STAT `0x8000`, admission of placed LOD models, and candidate links to full placements. An independent reader walked plugin groups, resolved master-local record identities, and applied later records. The model census used a case-folded `lod.nif` suffix on the ordinary STAT `MODL` filename. The transform check compared serialized position and rotation, with scale 1 for a missing `XSCL`.

The item 10 check followed Markarth BTR links to their texture sets. It compared the named assets with 93 installed archive indices and the scoped loose texture directory. The native trace followed reference queueing, attachment, promotion, and the terrain material lookup. This is static only.

## Observations

### G01. Q1 — STAT flag and census

**Verified.** STAT header mask `0x8000` is bit 15 of the runtime base form's `TESForm.formFlags` (CRASHLOGGER_PDB(59818@2026.10.24)) at offset `+0x10`. The STAT loader uses the common form importer, which takes the bit from the current file record header. The predicates at `0x2e49c0` and `0x2e9e40` accept bit 15 on either the placed reference or its base. The optional queue predicate also has a type-gated fallback that requires a base bounds radius strictly above 700.0 world units. `kHasDistantLOD` (CRASHLOGGER_PDB(59818@2026.10.24)) is the available label for the bit. The observed use is eligibility for distant-reference handling, including selected queue, attachment, and 3D lifecycle decisions. Evidence at `0x287549`, `0x1ce137–0x1ce145`, `0x2e49c0–0x2e49e1`, `0x2e9e50–0x2e9eb0`, and `0x277a80`.

**Verified.** The five shipped masters contain 115 distinct nondeleted STAT bases under the literal suffix rule. Skyrim supplies 44, Dawnguard supplies 2, and Dragonborn supplies 69. Update, HearthFires, and the 75 installed Creation manifest entries add zero. Of the 115 bases, 41 set bit 15. These same 41 contain `MNAM`. The flag distribution is 73 at `0`, 40 at `0x8000`, one at `0x8200`, and one at `0x80000`. The ordinary STAT model route reads `MODL`. The observed `MNAM` correlation establishes co-occurrence in this census.

**Verified.** All 115 filenames end in literal `LOD.nif`, and exact lowercase gives zero. Across the five masters, an editor ID suffix gives 121, the narrower `_lod.nif` suffix gives 85, and a basename substring gives 173. The scan found zero deleted or overridden suffix rows. **Unverified.** The reason for the two-record difference from the downstream count of 117 named in the header. That report gives no query or input manifest.

**Confidence: high** for the import, cited readers, and census. The pack database query and input manifest would allow a record-level comparison.

### G02. Q2 — Ordinary reference 3D and visibility

**Verified.** The ordinary cell scan can queue a REFR after its deleted and disabled checks. Some callers request the bit-or-size test from G01. For a STAT base, `Load3D` (CRASHLOGGER_PDB(59818@2026.10.24)) can clone the model named in `MODL`. The queued work retains the resulting node and can pass it to the parent cell's reference attachment routine. A separate `Set3D` (CRASHLOGGER_PDB(59818@2026.10.24)) call at `0x193c8a` clears 3D. Evidence at `0x2cfce5–0x2cfd42`, `0x2e9ee0`, `0x277e00`, `0x276430`, `0x193839`, `0x193f0b`, `0x1a5e52–0x1a5e7b`, and `0x1a5f02`.

**Verified.** Exterior setup uses the active world for ordinary grid admission and for the separate RNAM promotion sweep. The bulk promotion sweep requires `uLargeRefLODGridSize > uGridsToLoad`. The compiled widths are 9 and 5, respectively. Promotion can move an eligible full reference to the world's sky cell and make its ordinary base model available for attachment. That model can itself have an `LOD.nif` suffix. Evidence at `0x1ab12e–0x1ab3e4`, `0x29226d–0x2922f2`, `0x2925b0–0x29283f`, `0x2942dd–0x29435c`, and `0x311270–0x31137e`. The large-reference finding [findings/large-references-retail-facts.md](large-references-retail-facts.md) (PR #821) covers eligibility, the grid setting and promotion in full.

**Verified.** Receiving-cell runtime bit 13 gates the checked hidden-bit update. The sky-cell constructor sets cell bit 13. All 42 shipped placements have it clear in their serialized parent cells. In the gated path, a size test and larger-grid setting can select the large-reference helper first. The bit-15 fallback checks the ordinary exterior grid with lower-inclusive and upper-exclusive bounds. It accepts immediately when an interior cell is present. With a nonnull reference, the large-reference helper accepts immediately when large width exceeds ordinary width. A narrower branch can consult extra data. A true result clears node bit 0 (`kHidden`, CommonLibSSE-NG), and a false result sets it. Bit 15 also conditions some fade state and 3D removal decisions. Evidence at `0x31170d`, `0x2d78cf–0x2d794f`, `0x1a2050–0x1a20f3`, `0x291110–0x29118a`, `0x2d8574–0x2d85c6`, and `0x1a5d5c–0x1a5dc1`.

**Verified.** An exterior world change can clean up old-world promotions before updating the active world. Cleanup can clear 3D and remove an eligible reference from its promoted cell. A separate branch preserves and reassociates the sky cell when both worlds resolve to the same sky-cell pointer. Evidence at `0x1a263b–0x1a2822`, `0x291f50`, and `0x292be1–0x292c94`.

**Inferred.** Active-world admission and promotion cleanup could explain a handover from the Tamriel castle placement to its Whiterun counterpart. **Unverified.** Simultaneous attached 3D for the two references, exact handover timing, a separate camera-distance cutoff or LOD tier for the ordinary placed model, and the final draw.

**Confidence: high** for the cited branches and **medium** for the inferred handover. A runtime trace would need to bind both references, their receiving cells, and their node state across the transition.

### G03. Q3 — Placed references, RNAM, and object LOD

**Verified.** Tamriel has 42 nondeleted temporary REFR placements using 42 distinct suffix-matching STAT bases. The placements come from `Skyrim.esm` and have zero overrides in the scanned inputs. Of these, 39 bases and three REFRs set bit 15. Each flagged REFR has a flagged base. All 42 have `NAME` and `DATA`, five have `XEMI`, and one has `XSCL`. Checks for an enable parent, a linked-reference tag, and REFR bit `0x100` found none. All 42 ordinary `MODL` assets occur in `Skyrim - Meshes0.bsa`.

**Verified.** Tamriel has 41 cohort members in RNAM, and all 41 qualify for its equal-key filtered map. `SWell_LOD` is absent. No other scanned world's RNAM contains a cohort identity. `WRCastleBridge01LOD` and `MrkTempleLOD` qualify with bit 15 clear on both forms. Their serialized base radius exceeds 700.0, while `SWell_LOD` falls below that threshold. This radius comparison establishes one input to the optional queue test. The importer builds a filtered cell bucket from matching serialized cell keys, and promotion reads the active world's filtered bucket. The BTO filter separately uses cell state. Its large-reference branch also uses a shape marker and the cell's promotion deadline. Evidence at `0x30c01f–0x30c029`, `0x28ffb0`, `0x290406–0x290810`, `0x2926e5–0x292734`, and `0x519130–0x51922c`. The large-reference finding [findings/large-references-retail-facts.md](large-references-retail-facts.md) (PR #821) covers the filtered map and the BTO predicate. The object LOD findings [findings/object-lod-retail-facts.md](object-lod-retail-facts.md) (PR #675, section C) and [findings/object-lod-segments-retail-facts.md](object-lod-segments-retail-facts.md) (PR #816) cover the BTO segment order and suppression.

**Verified.** `WhiterunWorld.WNAM` names Tamriel as parent and `PNAM` is `0x7f`. Parent-use bit `0x2` selects the parent chain for the terrain manager. The sky-cell accessor uses its local cache first. With an empty cache, bit `0x40` and a resolved parent select the parent accessor. The worldspace reads select shared world data. The checked reference fields and worldspace branches supply no pairwise link. Evidence at `0x30c033–0x30c0ac`, `0x30c9cc–0x30ca2a`, `0x30db20–0x30db55`, and `0x311683–0x3116b5`.

| Tamriel placement, by base editor ID | Shipped comparison |
|---|---|
| `WRCastleMainBuilding01LOD` | **Verified.** The full reference cited by the downstream report is in Whiterun and matches position, rotation, and scale. The two references have filtered RNAM membership in their respective worlds. The Tamriel base sets bit 15. The Tamriel REFR and both full forms have it clear. A second Whiterun placement uses the same full base, differs in position, and has no Whiterun RNAM entry. |
| `WRCastleBridge01LOD` | **Verified.** The same-stem Whiterun bridge differs in position and rotation and has equal scale. The Tamriel LOD reference qualifies for filtered RNAM with both bit-15 flags clear. |
| The reported keep | **Unverified.** The intended base or placement identity. The checked `MrkCastleLOD` candidate has both flags set and filtered Tamriel RNAM membership. The scan found neither a same-stem full STAT placement nor an exact-position full STAT placement for that candidate. |

**Verified.** The ordinary REFR path and RNAM promotion can admit placed models as full references. BTO suppression operates on cell segments. **Unverified.** Inclusion of any particular cohort model in baked BTO geometry or a runtime rule that swaps the named pair.

**Confidence: high** for the shipped counts, fields, and named comparisons. A keep identity or an additional linkage reader could refine the pairing assessment.

### G04. Item 10 — Markarth terrain texture lookup

**Verified.** All 277 shipped Markarth BTRs name a diffuse and a normal path in their linked texture set. Both named files are absent for 238 blocks across 93 installed archive indices and the scoped loose texture directory. Both are present for the other 39. Missing pairs at widths 4, 8, 16, and 32 number 169, 49, 16, and 4. The other seven slots in each linked set are serialized empty. For the shading of these terrain surfaces see [findings/terrain-lod-shading-retail-facts.md](terrain-lod-shading-retail-facts.md) (PR #822).

**Verified.** An empty serialized path becomes null in the stored texture set and bypasses the resource helper. The LOD landscape material callback resolves slots when a texture set exists and its current diffuse pointer is null or equals the shared default. A named slot reaches resource lookup. Evidence at `0xee4c3d–0xee4c53`, `0xeb0f90`, `0x153b1b0`, `0x1518b55`, `0x1523d20`, and `0x153b3d0`.

**Verified.** A named diffuse or normal request that returns null selects the shared default stored at `0x3336448`. The special `ERR` and `NOR` aliases select that pointer directly. The alternate selector used by slot 4 selects `0x3336430` on a null result. Both globals are zero in the pinned file image. Separate base and landscape material routines can also fill null fields when the shared default is available. Evidence at `0x14ec0da–0x14ec22d`, `0x1523f00`, and `0x1527e60`.

**Verified.** The point getters at `0x516660` and `0x5166a0` select a terrain chunk and use `0x511520` to return its diffuse or normal texture pointer, or null. The checked point getter path shows no retry at another terrain tier.

**Inferred.** A missing Markarth file can take the fallback when its runtime resource request returns null. **Unverified.** The mount and cache state, request result for a particular block, default texture contents, bound resource, draw admission, and rendered appearance.

**Confidence: high** for the census and conditional fallback. **Confidence: medium** for taking the branch in a particular session. A runtime observation of the request and bound texture would resolve that question.

## Interpretation and limitations

**Verified.** Ordinary reference attachment, RNAM promotion, and BTO suppression follow separate conditions. The plugin and archive results apply to the scanned inputs. The checked Markarth fallback occurs during texture lookup.

**Unverified.** The final draw for the castle references and the cause of the downstream white castle surfaces. The Markarth terrain result leaves the castle material and its bound resources unverified. This finding names no cause for those surfaces.

## Independent review (2026-11-23)

Reviewer: `gpt-6.2-sol` through Codex, high effort, fresh context, separate run. The reviewer did not author the finding. The review ran on 2026-11-22 CST, which is 2026-11-23 UTC. The heading date is UTC.
Source reviewed: the draft of this finding (SHA-256 above), against the pinned image `sse-steam-1-7-104` (measured SHA-256 equals the pin in [builds/target.json](../builds/target.json)), the shipped plugin records and archive indices, and the generated public layout names. Exposure of the review: mixed (retail executable, shipped assets, generated names, the draft). Method: the reviewer sealed its four conclusions before it opened the author's handoff, parsed the plugins and archives independently, and reran the asset scans. This is a static finding review. It is not match evidence for any function. It does not decide transfer eligibility ([docs/clean-room.md](../docs/clean-room.md)).

The observations above already include the corrected text. A Claude Sonnet 5.5 worker only assembled this file from the corrected text and drafted nothing.

| Group | Verdict | One-line status |
|---|---|---|
| G01. STAT bit 15 and census | Corrected | The flag import, readers and 115/41 counts reproduce. The label is scoped to the observed reference decisions and the rules tested against 117 are documented. |
| G02. Reference load and visibility | Corrected | The ordinary queued node reaches cell attachment. Sky-cell visibility is conditional. Simultaneous castle loading and the final draw remain unverified. |
| G03. Reference linkage and RNAM | Corrected | The 42/42 placements and 41 RNAM members reproduce. The main building has two same-stem full placements. BTO suppression is per cell segment. |
| G04. Terrain texture lookup | Corrected | The 238 missing pairs and conditional fallback reproduce. Empty slots bypass lookup. The point getter returns a texture pointer or null. |

Summary: 0 groups confirmed, 4 corrected, 0 rejected.

## Reviewer and outcome

Reviewed independently on 2026-11-22 CST (2026-11-23 UTC) by `gpt-6.2-sol` (Codex, high effort, fresh context), separate from the author. Outcome: 0 confirmed, 4 corrected (G01, G02, G03, G04), 0 rejected. Static only. A review verdict is not match evidence, and transfer eligibility is not decided. Transfer status: UNREVIEWED. Unverified:

- Simultaneous castle loading: whether the Tamriel placement and its Whiterun counterpart hold attached 3D at the same time, and the exact handover timing.
- The final draw of the castle references, including any separate camera-distance cutoff or LOD tier for the ordinary placed model.
- The cause of the downstream white castle surfaces. The finding names no cause. No downstream code or configuration was inspected.
- The census difference from the downstream count of 117. Our independent counts are 115 suffix matches, 41 flagged bases, 42 placements using 42 bases, and 41 of those placements in the filtered Tamriel RNAM. The reason for the two-record difference is unknown.
- The identity of the reported keep. The checked `MrkCastleLOD` candidate has no same-stem or exact-position full STAT placement.
- The Markarth draw result: the mount and cache state, the resource result for each block, the default texture contents, the bound resource, draw admission, and the rendered appearance.
- Inclusion of any particular cohort model in baked BTO geometry, and a runtime rule that swaps the named castle pair.
