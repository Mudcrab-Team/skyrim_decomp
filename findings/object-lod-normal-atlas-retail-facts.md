Transfer status: UNREVIEWED

# Finding: object LOD normal atlases in Skyrim Special Edition

| Item | Evidence record |
|---|---|
| Status | OBSERVED for verified claims. INFERRED and UNVERIFIED items are marked. Static only. |
| Author | The Sol research run, `gpt-6.2-sol` via Codex (not the reviewer below). |
| Human operator | Taylor. |
| Reviewer | A separate `gpt-6.2-sol` run via Codex, high effort, fresh context. See "Independent review" below. |
| Date | The draft date is 2026-11-23 UTC. The independent review ran on 2026-11-23 CST, from 00:25 CST to 00:38 CST (06:25 to 06:38 UTC). The review found that the draft date agrees with the retained evidence. The author's exact start time is **unverified**: the draft's initial clock reading was unavailable. |
| Reviewed draft SHA-256 | `21a909ea9a5c86895a57e6ec99bd51c2e54860579164692adc47bf53e43904e7` |
| Build | `sse-steam-1-7-104`, retail `1.7.104.0`. Executable SHA-256 `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f`, equal to the pin in [builds/target.json](../builds/target.json). Both runs measured the hash and asserted the equality. |
| Principal function RVAs | `0x5048a0`, `0x504da0`, `0x51caf0`, `0x51cb20`, `0xfd3840`, `0x14ea872`, `0x14ec0a0`, `0x1518970`, `0x1523d20`, `0x1523f00`, `0x1524370` and `0x1547d20`. All descriptive native function labels are our own names and are GUESS. |
| Source exposure | Mixed. Both runs used the operator's pinned executable, the shipped shader package, the shipped DDS headers and BTO metadata, and the five shipped INI templates, from the operator's retail install. The review also read BC3 alpha data of the shipped atlases. Prior reviewed findings supplied anchors. No downstream implementation source and no sibling implementation was used. |
| Name provenance | This file takes no field, enum or type name from the public generated tables. If a later edit adds one, it must carry the label CRASHLOGGER_PDB(59818@2026.10.24). Lighting technique labels `LODOBJECTS` and `LODOBJECTSHD` come from the feature-name table of the pinned image. Setting names come from the image and the shipped INIs. Descriptive native function labels are our own and are GUESS. |
| Intended recipient | Skyrim Research department lead for boundary review under [docs/clean-room.md](../docs/clean-room.md). Proposed downstream use: the Mudcrab object LOD work (issue #940), which asks whether retail object LOD samples the worldspace normal atlas. Priority medium. |

All addresses are RVAs for the pinned build at image base `0x140000000`. Shader record offsets are relative to the start of the shader package. **Verified** identifies a static read at the cited source. **Inferred** identifies an interpretation of those facts. **Unverified** identifies missing evidence. VS means vertex shader record. PS means pixel shader record. `tN/sN` means texture slot N with sampler slot N. Keep listings of the game files in `.local/`. Nothing game-derived is in this file except counts, field offsets, addresses, constants, formulas, shader keys and shipped asset names.

## Review verdicts

| Group | Verdict | Main correction |
|---|---|---|
| G01. Ordinary Lighting pixel shader resource coverage | Corrected | All 20 PS retain the base samples. Ten also sample projected detail, including two auxiliary-output keys. |
| G02. Shipped atlas headers and serialized references | Confirmed | Fourteen BC3 normal atlases. One exact pair in each of 915 BTOs. |
| G03. Tangent-space normal and geometry inputs | Corrected | Blue supplies Z directly. The input layout, frame assembly and projected blend direction are now documented. |
| G04. Native atlas request, material and sampler binding | Corrected | Paired properties bind clamp for both slots. The object sampler permits anisotropic mip selection. |
| G05. Lighting use, alpha and auxiliary outputs | Corrected | The four auxiliary keys use full-vector dots. The light order and the atlas-alpha use are now specified. |
| G06. Missing normal texture and link-time defaults | Corrected | A null path, a null resource result and null render data are distinguished. The joined-name explanation remains inferred. |
| G07. Flags, technique selection and settings | Corrected | The setting search is bounded. The projected upload, resource selection and base binding are separated. |

## Question and method

Does retail object LOD sample the worldspace normal atlas? The method compares shipped DDS headers and BTO metadata with the indexed shader package and the pinned native image. This extends the object LOD finding (#675) and the object LOD segment finding (#816). It uses the terrain LOD findings (#822 and #946) as terrain controls. The file states the full answer in "Interpretation and alternatives".

## Observations

### G01. Ordinary Lighting pixel shader resource coverage

**Verified, high confidence.** Evidence is zero-based group 6 of `shadersfx/shaders011.fxp` in `Skyrim - Shaders.bsa`. The native loader at `0x14ea872` and the feature-name dispatch at `0x15894b0–0x15894d2` select it and resolve Lighting and the two object names. The package SHA-256 is `72cfc73eb0938d5949f0b3a8683722a33b671a34b41b750ba138de8d154c5fbc`. Group 6 contains 127 VS and 6,924 PS records. The native feature-name table at `0x1589648` names techniques 13 and 15 as `LODOBJECTS` and `LODOBJECTSHD`. Each technique contributes eight VS and ten PS. Together the two techniques account for 16 VS and 20 PS records, including the projected variants. The eight matching VS key suffixes have identical payloads across the two techniques. Representative package offsets for keys `0d000001` and `0f000001` are 8,940,744 and 8,987,392 for VS and 49,486,012 and 50,472,024 for PS.

| Stage | Complete six-digit key suffixes for each prefix `0d` and `0f` |
|---|---|
| VS | `000000`, `000001`, `008000`, `008001`, `040000`, `040001`, `048000`, `048001` |
| PS | `000001`, `008001`, `040001`, `048001`, `100001`, `108001`, `140001`, `148001`, `208001`, `248001` |

**Verified, high confidence.** All 20 PS take one sample each at `t0/s0` and `t1/s1`. Both samples use the same interpolated UV with implicit derivatives. All 16 VS omit texture sampling. Ten projected PS also sample slot 12, with three samples per record. These ten PS carry key bit `0x00040000`. The five projected suffixes per technique are `040001`, `048001`, `140001`, `148001` and `248001`. The two `248001` keys also write target 3. The keys with bit `0x00008000` also use slots 3, 8, 10 and 11. The table gives the complete checked key set.

**Scope.** Generic Lighting, tree LOD, other shader groups and passes are outside this check. The terrain LOD techniques 9 and 18 (see #822) also resolve to LOD landscape and are outside this sample census. A different package or pass selection could change which records apply. **Unverified.** The shader key that a particular live draw uses.

### G02. Shipped atlas headers and serialized references

**Verified, high confidence.** The checked archive indices contain 14 object atlas pairs, one diffuse and one normal atlas for each of the 14 worldspaces with BTOs. Textures5, Textures6, Textures7, the Deadlands archive and the QN World archive supply 5, 6, 1, 1 and 1 pairs. The 12 standard worldspaces use `<world>.objects_n.dds`. The two Creation Club worldspaces use `<world>objectslod_n.dds`. All 14 normal DDS headers specify DXT5 (BC3). The checked archive indices contain no dotted-name pair for either Creation Club world. The scan reads DDS headers. It does not inspect atlas pixels in this group.

| Worldspaces | Normal atlas dimensions | Header mip count | Diffuse DDS format |
|---|---:|---:|---|
| Blackreach, DeepwoodRedoubtWorld, DLC01FalmerValley, DLC01SoulCairn, DLC1HunterHQWorld, DLC2ApocryphaWorld, DLC2SolstheimWorld, JaphetsFollyWorld, MarkarthWorld, SkuldafnWorld, Sovngarde, Tamriel | 2048 × 2048 | 11 | Uncompressed 32-bit RGBA, one mip |
| ccbgssse067deadlandsworld | 2048 × 512 | 9 | DXT5, nine mips |
| cckrtsse001qnworld | 2048 × 256 | 8 | DXT5, eight mips |

Evidence is the DDS header census in `Skyrim - Textures5.bsa`, `Skyrim - Textures6.bsa`, `Skyrim - Textures7.bsa`, `ccbgssse067-daedinv.bsa` and `cckrtsse001_altar.bsa`. Normal and diffuse dimensions match within each pair. A different installation or an archive replacement could change this census.

**Verified, high confidence.** The scan found 1,109 BTOs. The three archives that contain BTOs contribute 1,078 base and DLC files, 26 Deadlands files and five QN World files. These BTOs contain 1,587 serialized texture sets, and both entries 0 and 1 are nonempty in every set. Exactly 915 files each contain one set that names the world's diffuse atlas in entry 0 and its normal atlas in entry 1. That comparison normalizes case and separators and removes the serialized leading `Data` path component. No other set matches either slot alone under this comparison. The 14 of 26 Deadlands files and 3 of 5 QN World files are among the 915. The paired sets link to 1,600 Lighting properties, including 14 in Deadlands and three in QN World. The other 194 files contain zero matching sets. A file with a matching set can also contain other sets. The 915 paired sets hold 1,830 individual atlas references. All 1,830 resolve textually to archive member paths after the removal and normalization above. Evidence is the BTO header and texture-set census in `Skyrim - Meshes1.bsa` and the two Creation Club archives above. This is a file and linkage census. **Unverified.** Live path resolution, mount precedence, replacement views, resource binds and live draws.

### G03. Tangent-space normal and geometry inputs

**Verified, high confidence.** The PS decodes atlas RGB as signed tangent-space XYZ with `2 × RGB − 1`. Blue supplies Z directly, with no reconstruction. The terrain LOD block decode in #822 and #946 instead uses R/B/G, with green supplying Z. The terrain LOD block meshes in those findings have no vertex normal or tangent attributes. The object PS use the interpolated vertex basis described below.

**Verified, high confidence.** The object VS reads float32x4 position, float16x2 UV, UNORM8x4 `NORMAL0` and UNORM8x4 `BINORMAL0` at bytes 0, 16, 20 and 24. The input layout is at `0x1011750–0x1011996`. The 32-byte layout adds UNORM8x4 colour at byte 28. The 28-byte layout omits colour. The BTO census found 1,603 shapes with 28-byte vertex records and 825 with 32-byte records. In the checked VS sets, key bit 0 selects the variant that reads `COLOR0`. The other VS write literal white in its place. The shader reads position W directly and remaps the two packed vectors to signed values with `2 × value − 1`. The basis maps tangent-space X onto `(POSITION0.w, signed NORMAL0.w, signed BINORMAL0.w)`, Y onto signed `BINORMAL0.xyz` and Z onto signed `NORMAL0.xyz`. The VS assembles these rows in `TEXCOORD1..3`. It does not calculate a cross product and does not rebuild a third vector from a handedness sign. The PS applies these interpolated model-space basis rows to the tangent-space normal and normalizes for lighting. The PS also uses a separate interpolated basis for the auxiliary normal output. The later `0x00008000` material overlay can modify the tangent-space normal that target 2 uses, after the main lighting normal is computed. A custom vertex layout or a different shader could change the input contract.

**Verified, high confidence.** The ten projected PS normalize a three-plane detail sample from slot 12. They mix from that detail toward the signed atlas normal with `PS b2[8].z`. A weight of zero selects the detail. A weight of one selects the atlas normal. The PS normalizes the mixture, then applies the main basis and normalizes again for lighting. **Unverified.** The live blend weight, the conditioning of the interpolated basis, replacement inputs and the effective atlas contribution for a specific draw.

### G04. Native atlas request, material and sampler binding

**Verified, high confidence.** The keyed request at `0x504da0` formats the standard diffuse and normal names separately, then requests both through `0xfd3840`. The formatters at `0x51caf0` and `0x51cb20` use `<world>.Objects.DDS` and `<world>.Objects_n.DDS` in the world's object texture directory. The native preload templates at `0x18e3358` and `0x18e3388` name dotted files. The request carries both references. The BTO loader at `0x5048a0` processes both references before it loads the mesh stream. The preload has no branch that selects the joined Creation Club filenames. Evidence at `0x504e42–0x504eb5`, `0x509fe9–0x50a015` and `0x50491c–0x504956`.

**Verified, high confidence.** The shipped BTO Lighting properties in this census use serialized material type 0. The factory at `0x1524370` constructs the ordinary Lighting material for that type. Its base initializer clears both texture pointers and the texture-set pointer. The material has the common texture-set loader at virtual slot 8. When it resolves a linked set, entry 0 supplies the diffuse field at `+0x48` and entry 1 supplies the normal field at `+0x58`. The normal entry uses the same slot resolver as diffuse. Evidence at `0x15188a7`, `0x15243a9–0x1524401`, vtable `0x18d7ba8` and `0x1523d7c–0x1523de5`.

**Verified, high confidence.** The material setup table at `0x15494e4` sends techniques 13 and 15 to the common dispatch target at `0x1548f9d`. They preserve the enabled value of the shared base-bind gate at `0x15492bd`. Slot 0 receives the diffuse field when the diffuse render-target override at `+0x50` is −1. Otherwise slot 0 receives the indexed render-target view. Slot 1 receives the normal field's view. Both sampler addresses come from material field `+0x70`, including the slot-0 render-target branch. The slot 1 sampler addressing is set at `0x1549321`. The view-state writers are at `0x15492bd–0x1549369` and `0x154c9a0–0x154c9fd`.

**Verified, high confidence.** The type-0 constructor initializes `+0x70` to wrap, enum 3. The linked property reader calls its material's virtual entry at `+0x68` at `0x1518954`. The type-0 entry at `0x15241d0` reads the serialized value into that field. All 1,600 Lighting properties linked to the atlas pairs serialize enum 0, clamp. The other 828 properties in this census serialize enum 3, wrap. The setup table at `0x15487c0` sends techniques 13 and 15 to `0x154860c`. That routine preserves filter enum 3 for slots 0 and 1, from `0x1547e56` and `0x1547e78`. The descriptor table at `0x102b910–0x102baf3` implements this filter as anisotropic filtering, maximum anisotropy 16, zero bias, and LOD limits from −FLT_MAX to FLT_MAX. The two slots can therefore select mips that their bound views expose. The four terrain LOD controls in #822 and #946 instead use a descriptor capped at view-relative mip zero. The generic legacy DXT5 load path documented in #946 uses BC3_UNORM.

**Unverified.** The exact resource view for a live draw. The actual bound formats, view mip ranges, the mip selected for a pixel and later draw-time state overrides. A trace across the stream and draw boundaries would confirm which resource each draw receives.

### G05. Lighting use, alpha and auxiliary outputs

**Verified, high confidence.** All 20 PS use the atlas-derived lighting normal N from G03 for diffuse sun, directional ambient and diffuse point lights. The checked PS follow the same order, shown in the table. P is the interpolated position that the light loop uses. All constants in the table are pixel-stage constants. The base and projected VS supply P differently, so equal live light positions and projected coordinates are **unverified**.

| Order | Operation |
|---|---|
| 1 | Initialize the accumulator with `saturate(dot(N, b2[0].xyz)) × b2[1].rgb`. |
| 2 | Visit indices below `min(b2[29].x, 7)` in increasing order. Form D from `b2[15+i].xyz − P`, then a from `saturate(length(D) / b2[15+i].w)`. Multiply the saturated dot of N with normalized D by `b2[22+i].rgb`. Multiply-add that RGB with `1 − a²` into the accumulator. |
| 3 | Evaluate the three directional ambient row dots at `b2[11..13]` with (N,1). Add `b2[4].yzw` to the ambient RGB before adding the result to the accumulator. |
| 4 | Multiply-add `b1[8].x × b1[8].yzw`. Multiply the result by effective diffuse RGB, then by vertex RGB, to obtain L. |
| 5 | Interpolate from L toward interpolated fog RGB using fog alpha, to obtain F. Form Q = L − `b0[0].w` × F. Let S = Q × `b12[42].y`. Take the component-wise minimum of L and the separate multiply-add Q × `b12[42].y` + `b0[1].x`. Subtract S × `b12[42].z` by multiply-add. |

In words: the sun term is a saturated dot of the normal with the sun direction, times sun RGB. Point lights accumulate in index order up to the shader limit of seven. Each uses the saturated light-normal dot, the point RGB and the attenuation `1 − saturate(distance/radius)²`. The shader adds unsaturated directional ambient evaluated with the normal extended by one, plus the per-property emissive RGB product. It then adds the separate Lighting shader object's colour and scalar product. The result is multiplied by effective diffuse RGB, then vertex RGB. Row 5 is the target-0 arithmetic before fixed-function output. The two added RGB terms have separate producers. The property RGB product is at `0x1549f3a–0x1549f9c`. The Lighting shader object product is at `0x154936f–0x15493c6`. This agrees with #946.

**Verified, high confidence.** All five projected technique-15 PS can adjust effective diffuse RGB, using a weight derived from the original diffuse RGB. The `0x00008000` overlay can already have modified the effective diffuse RGB that this adjustment receives. Technique 13 has no corresponding projected colour adjustment. The projected normal blend can alter the normal that all three light terms use. The projected keys keep these uses and blend a contribution from `t12/s12` into the tangent-space normal before the basis transform. The checked target-0 RGB paths have no direct sun or point specular term.

**Verified, high confidence.** Diffuse alpha times `PS b2[3].z` supplies target-0 alpha and the eight cutout tests. Atlas-normal alpha has no dependency path to target 0. It feeds target 2 W only on the packed-normal output branch. On that branch the shader scales a cubic smoothstep of the sampled alpha, between `PS b2[7].x − 0.00001` and `PS b2[7].y`, by `PS b2[7].w`. When `PS b2[7].z > 0.00001`, target 2 copies target 0 instead. The shader uses the RGB channels as the three normal components, with alpha separate. A BC3 alpha census of in-bounds texels found variable base-mip alpha in all 12 standard atlases, including both 0 and 255. Both joined-name Creation Club normal atlases store alpha 255 throughout all shipped mips. This establishes stored alpha variation and the shader's consumers. **Unverified.** Offline baking intent and downstream interpretation of alpha.

**Verified, high confidence.** The four auxiliary keys `0d208001`, `0d248001`, `0f208001` and `0f248001` each form two angular powers. Each power uses one minus a saturated dot with the vector of approximately (0.577350, 0.577350, 0.577350). The first dot uses the normalized geometric basis normal and the exponent `PS b1[13].y`. The second dot uses N and the exponent `PS b1[13].z`. The shader multiplies the two powers and scales the product by `PS b1[13].x`. It gates the result by `PS b1[13].w > 0.00001` and by the overlay mask branch. Target 3 X takes the gated scalar through luminance weights. Neither power feeds target 0. The other 16 PS omit these terms. **Unverified.** The live constants, resource views, light lists, detail contribution, the downstream use of targets 2 and 3, and the effect of target 3. A separate pass or shader package could have a different specular path.

### G06. Missing normal texture and link-time defaults

**Verified, high confidence.** The shader-property link at `0x1518970` connects the serialized texture set to the material at `0x15189cb–0x15189e7`. It invokes material virtual slot 8 at `0x1518b55` with no replacement set. The skip gate tests lower flag mask `0x01000000` at `0x1518a60–0x1518a69`. Both lower flag words in this BTO census clear that mask, so the call is allowed. In the ordinary material loader at `0x1523d20`, the lookup resolves entries 0 and 1 from the linked set when the diffuse field is null or equals the shared default. A populated non-default diffuse field skips both lookups.

**Verified, high confidence.** The slot resolver at `0x153b3f5–0x153b46b` skips the resource lookup for a null stored texture path and can write null to the destination. For a named path, entry 1 clears the alternate-default selector, and entry 4 sets it. The resolver calls `0x14ec0a0` for the lookup. If the lookup returns null, the shared pointer at `0x3336448` is selected with the selector clear. The alternate pointer at `0x3336430` is selected with the selector set. The shared pointer is also used by diffuse and is selected by the special ERR and NOR aliases. Both globals are zero in the pinned file image. Evidence at `0x14ec0da–0x14ec22d`. A separate default-fill routine at `0x1523f00` can supply the shared pointer for a null normal field when the shared pointer exists. The bind at `0x154931d–0x1549351` dereferences the texture object. It can submit a null view when that object has no render data. The checked shader records still sample slot 1.

**Inferred, medium confidence.** A named missing entry-1 file can cause the shared default to be selected, if the resource lookup returns null and the default pointer is initialized.

**Verified, high confidence.** The 17 paired Creation Club BTOs (14 Deadlands, three QN World) have joined filenames in their serialized texture sets. The checked archive indices contain the joined pairs. The material lookup takes the serialized paths separately from the keyed preload formatter.

**Inferred, medium confidence.** The serialized material lookup can supply the joined Creation Club atlas filenames even though the keyed preload formats dotted filenames. This follows from the joined-name entries and the standard material resolver. A live trace could distinguish a joined atlas bind from the shared default or from a different draw route.

**Unverified.** Whether a missing file in this load returns null. Runtime initialization and identity of the default pointers. The default's texel values. Invocation of the separate fill routine on every BTO load. The result and failure handling of the dotted preload request. Asset lookup precedence. The live resolution of the joined Creation Club filenames and the resource actually bound in either Creation Club world. A runtime resource trace would establish the result for a particular missing asset.

### G07. Flags, technique selection and settings

**Verified, high confidence for the standard selector.** The stock BTO census contains 2,428 serialized type-0 Lighting properties. The 2,392 base and DLC properties have lower flag word `0x80400000`. Of these, 1,583 have upper flag word `0x00000005` and 809 have `0x80000021`. The two Creation Club archives add 36 properties with lower word `0x80000300`. Of these, 20 have upper word `0x00000005` and 16 have `0x80000021`. The standard selector at `0x151ad44–0x151ad61` reads runtime flag bits 34 and 63 to select techniques 13 and 15, under the conditions in #675 B2. Preserve the bypass and context qualifications of #675. The Creation Club draw context and the live key selection remain **unverified**.

**Verified, high confidence for the checked keys.** Cutout key bit `0x00100000` selects eight PS records, the cutout path in #675 B4. Key bit `0x00040000` selects the ten projected PS records. It adds projected normal detail and retains the base `t1/s1` sample. That bit gates the native cache bind for slots 12 and 13 at `0x154a530–0x154a61a`, which supplies the slot-12 map overlay from `0x20d6920`. Of those two resources, the checked object shaders sample slot 12 only. Key bit `0x00200000` selects the four records that write target 3. The corresponding native material path uploads rim parameters at `0x1549267–0x15492b7`. That upload includes an enable lane that `bEnableSnowRimLighting:Display`, initial value 1, can set to zero (lane at `0x1549273–0x15492b7`). The three compiled constants supply intensity 0.3000000119, geometry exponent 3 and normal exponent 2. A value at a particular draw remains **unverified**. Every listed pixel key samples slot 1. Material type 0 and the two object LOD technique IDs describe separate choices.

**Verified, scoped.** The search covered the active assignment names in the five shipped INI templates: `Skyrim_Default.ini`, `Low.ini`, `Medium.ini`, `High.ini` and `Ultra.ini`. The compiled-name scan covered NUL-terminated ASCII type-prefixed `name:section` settings in the raw-backed `.rdata` and `.data` sections. The scan used these case-insensitive name fragments: object, LOD, normal, atlas, projected/projecte UV, snow, mipbias and anisotrop. It returned 112 compiled names. Selected defaults and native readers were checked. No base-atlas toggle appeared in those results or in the traced slot-1 bind. The closest projected setting is `bEnableProjecteUVDiffuseNormals:Display`. Its default is 1 at `0x20d8d78`. The four presets set it to 0, 1, 1 and 1 in Low through Ultra order. `bEnableProjecteUVDiffuseNormalsOnCubemap:Display` starts at 0. The native reader at `0x154a0de–0x154a116` applies these settings to a separate overlay parameter flag. The conditional writer at `0x154c600–0x154c6f6` converts that flag to a zero or one W lane. The projected bind at `0x154a530` and the base binds at `0x15492bd–0x1549369` have separate predicates. Direct references to `bSAONormalMap:Display` and `bIndNormalMap:Display` occur at `0x1541e96` and `0x1543d2d`, outside those binds. A connection from either setting to the base object atlas is **unverified**.

**Unverified.** Settings with unmatched names or other string encodings, additional settings stores, user overrides, alternate passes, key remaps and downstream consumers. The scan does not establish that no setting can alter object LOD visibility, live sampling or normal-map use indirectly. A separate mode or key remap beyond the cited paths could add a control.

## Interpretation and alternatives

**Verified, high confidence for the standard static path.** The BTO texture set supplies the normal atlas name in entry 1. The native material resolves that entry to the normal field and supplies it to `t1`. All 20 applicable PS records sample `t1/s1` and use the decoded normal for lighting. This chain ties the serialized normal atlas to the two checked techniques. The projected blend can change the base atlas contribution.

**Inferred, medium confidence.** The separate serialized texture-set lookup can supply the joined Creation Club names even though the preload formatter requests dotted names. A live trace could distinguish a joined atlas bind from a shared default or from a different draw route.

## Relation to earlier findings

- #675 (object and tree LOD): its B2 and B4 support the standard selector flags, the 20 ordinary object PS records and the eight cutout keys, and the live pass selection keeps its qualification.
- #816 (object LOD segments): it checks segment eligibility and suppression in its 1,078-file corpus, so a serialized atlas pair here says nothing about whether a segment reaches a draw, and the 1,109-file population here, which adds the two Creation Club archives, does not expand its suppression evidence.
- #822 (terrain LOD shading): its four terrain LOD PS decode the block normal in R/B/G order and use a base sampler capped at the first mip that the view exposes, so its decode and sampler rule differ from the object rule in G03 and G04.
- #946 (terrain LOD versus near landscape): it agrees with this file on the two additive light terms and their common upload sources, and it documents the generic legacy DXT5 load path that G04 cites.

## Negative results and limitations

**Verified, high confidence within the checked records.** The base normal decode requires no Z reconstruction. The projected variants retain the base normal sample. The checked colour output and binding paths establish neither a base-atlas toggle nor an ordinary sun or point specular term. G01 and G07 define the coverage of these negative results.

**Unverified.** Live permutation selection, draw admission, resource identity, fallback texels, downstream use of auxiliary targets, and visual results. This finding is static only. The archive scan counts serialized references and does not establish live texture residency.

## The answer in three lines

- Slot: object LOD binds the diffuse atlas at slot 0 and the normal atlas at slot 1. All 20 checked object LOD PS sample slot 1.
- Space: the stored normal is signed tangent-space XYZ, and the PS maps it to model space with the interpolated vertex basis before lighting.
- Decode: the shader decodes atlas RGB with `2 × RGB − 1`. Blue supplies Z directly, with no reconstruction. The terrain LOD block decode in #822 and #946 instead uses R/B/G, with green supplying Z.

## Independent review (2026-11-23 CST, 2026-11-23 UTC)

Reviewer: `gpt-6.2-sol` via Codex, high effort, fresh context, separate run. The reviewer did not author the finding. Review window: 00:25:46 to 00:38:50 CST on 2026-11-23, which is 06:25:46 to 06:38:50 UTC. Source reviewed: the draft of this finding (SHA-256 above), against the pinned image `sse-steam-1-7-104` (measured SHA-256 equals the pin in [builds/target.json](../builds/target.json)), the installed shader and texture archives and the BTO archives, and the five shipped INI templates. Exposure of the review: mixed (retail executable, shipped assets, the draft). Method: the reviewer independently extracted the shader package and walked its 79 groups, decoded all 36 selected records, ran the DDS, BTO and BC3 alpha censuses, and read the native paths. It sealed its seven verdicts (sealed record SHA-256 `6c3acfdd582cd98ca17a9ee6386dd38520d28c5f13dd7ca75707c2084fd6b98b`) before it opened the author's handoff. After the seal, the author's handoff agreed with the review on the image, the package, the shader coverage, the RGB decode, the paired-file count and the conditional default. The handoff's "915 atlas references" means 915 paired sets in 915 files, which is 1,830 individual references. The author's final check counted slot-12 samples across all 20 saved pixel records and found ten projected records. The initial tally had omitted the two keys that also write target 3. The sealed snapshot keeps the initial tally. The final G01 verdict is Corrected, and G03, G05 and G07 use the corrected count. The review also found that the draft's description of the target 3 dot products was incorrect (it described the Z component only) and that two sampler settings and the scope of the settings search needed the additions above.

This is a static finding review. It is not match evidence for any function. It does not decide transfer eligibility ([docs/clean-room.md](../docs/clean-room.md)).

The observations above already include the corrected text. A Claude Sonnet 5.5 worker only assembled this file from the corrected text and drafted nothing. The reviewed draft contains no apparent recovered source, no disassembly byte sequence and no private machine path. Shader keys, RVAs, field offsets and asset names are identifiers. The draft's date header is a UTC calendar date. It claims no author start time.

| Group | Verdict | One-line status |
|---|---|---|
| G01. Ordinary Lighting pixel shader resource coverage | Corrected | All 20 PS retain the base samples. Ten also sample projected detail, including two auxiliary-output keys. |
| G02. Shipped atlas headers and serialized references | Confirmed | Fourteen BC3 normal atlases. One exact pair in each of 915 BTOs. |
| G03. Tangent-space normal and geometry inputs | Corrected | Blue supplies Z directly. The input layout, frame assembly and projected blend direction are documented. |
| G04. Native atlas request, material and sampler binding | Corrected | Paired properties bind clamp for both slots. The object sampler permits anisotropic mip selection. |
| G05. Lighting use, alpha and auxiliary outputs | Corrected | The four auxiliary keys use full-vector dots. The light order and the atlas-alpha use are specified. |
| G06. Missing normal texture and link-time defaults | Corrected | A null path, a null resource result and null render data are distinguished. The joined-name explanation remains inferred. |
| G07. Flags, technique selection and settings | Corrected | The setting search is bounded. The projected upload, resource selection and base binding are separated. |

Summary: 1 confirmed (G02), 6 corrected (G01, G03, G04, G05, G06, G07), 0 rejected.

## Reviewer and outcome

Reviewed independently on 2026-11-23 CST (2026-11-23 UTC) by `gpt-6.2-sol` (Codex, high effort, fresh context), separate from the author. Outcome: 1 confirmed (G02), 6 corrected (G01, G03, G04, G05, G06, G07), 0 rejected. Static only. A review verdict is not match evidence, and transfer eligibility is not decided. Transfer status: UNREVIEWED. Unverified:

- Live resource identity: the actual atlas or fallback resource and view bound in a draw, its format, exposed mip range and the mip chosen for a pixel.
- Draw selection: the live shader key, pass and permutation, draw admission, and the Creation Club draw context.
- Fallback texels: whether a missing file returns null, the identity of the shared default, and its texel values. The missing-file behaviour (shared default selected) is **inferred**, not verified.
- Live resolution of the joined Creation Club filenames, and the result of the dotted preload request in those worlds.
- Downstream use of auxiliary targets 2 and 3.
- Live rendering: live constants, blend weights, light lists and visual results. No game launch, render capture, GPU capture or live constant read was performed.
- The author's exact start time. The draft's initial clock reading was unavailable. The draft date 2026-11-23 UTC agrees with the retained evidence.
