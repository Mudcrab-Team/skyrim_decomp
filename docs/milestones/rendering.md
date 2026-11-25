# Milestone: Rendering 1:1

Decompile Skyrim SE's rendering subsystem, function by function, until each function is a byte match, so the
renderer can be understood from source that provably compiles to the same code. Five workstreams
(A to E) give each class one owner.

Tracking issue: [#1185](https://github.com/Mudcrab-Team/skyrim_decomp/issues/1185). Task issues: A [#1186](https://github.com/Mudcrab-Team/skyrim_decomp/issues/1186), B [#1187](https://github.com/Mudcrab-Team/skyrim_decomp/issues/1187), C [#1188](https://github.com/Mudcrab-Team/skyrim_decomp/issues/1188), D [#1189](https://github.com/Mudcrab-Team/skyrim_decomp/issues/1189), E [#1191](https://github.com/Mudcrab-Team/skyrim_decomp/issues/1191). GitHub milestone:
[Rendering 1:1](https://github.com/Mudcrab-Team/skyrim_decomp/milestone/1).

## Goal and scope

- **Goal:** every function of the render subsystem in `data/progress.json` reaches `matched`: a byte match on two
  hosts plus one admitted review, exactly the gate in [verification.md](../verification.md). Nothing about the
  acceptance rule, the PR route or the check jobs changes for this milestone.
- **In scope:** the classes in the inventory below, workstreams A to E. They are the `BSGraphics` layer (renderer,
  state, render targets, constant and buffer management, textures and resources), the `BSShader` hierarchy and its
  properties and materials, batching and render passes, lights, `NiCamera` and the culling paths, and the shadow,
  image-space, sky, weather and water code.
- **Listed but not assigned** (the "Adjacent" tables): particle systems, the Scaleform UI renderer, game cameras and
  camera states, and render-related forms, decals, grass and LOD. They stay with the general drafting rounds; a
  contributor may take one, claimed the usual way.
- **Out of scope:** behaviour specifications, anything that ports code into another project, and any claim about
  gameplay parity. A matched function is a statement about bytes only.
- The inventory counts only functions that the public data already names. It is a lower bound: many render functions
  have no public name yet, and the real subsystem is larger. Naming them (mapping, then claiming) is part of the work.

## Why it matters

1. **Understanding the renderer.** A matching reconstruction forces every constant, branch order and data layout to
   be right. The result is source that shows how Skyrim builds a frame: which targets exist, what a pass binds, how
   lights are chosen, in what order transparent geometry is drawn.
2. **Retail facts for Mudcrab.** Mudcrab is a separate Rust and wgpu engine. Its material compatibility table (L1,
   `docs/lighting-l1-compatibility.md` in the Mudcrab repository) lists the retail behaviours it still approximates:
   shader flags, tangent frames, parallax and environment-map response, tint and snow materials, transparency
   ordering, tree animation, effect shaders, and the sky, fog, water and image-space stages it defers. Each
   workstream below names the part it feeds. The facts leave this repository the way the existing retail-fact
   findings do (`findings/*retail-facts*.md`): as reviewed prose with a transfer status, never as code.
3. **Fewer unknowns for everyone.** Foundation classes (`BSGraphics`, textures, geometry, lights) are callees of most of
   the later groups, so matching them moves many other functions toward ready.

## Rules that do not change

- Follow [AGENTS.md](../../AGENTS.md), [LEGAL.md](../../LEGAL.md), [PROVENANCE.md](../../PROVENANCE.md) and
  [clean-room.md](../clean-room.md). No game bytes, disassembly, dumps or proprietary symbols in a commit, PR, issue or
  log. RVAs, names, sizes and counts are fine.
- Names from the CrashLogger tables carry `CRASHLOGGER_PDB(59818@2026.10.24)`; names from the sibling symbol files
  carry `SYMBOLS(<source-id>)`. The names in this document are CrashLogger-derived and are guesses until a function
  matches.
- **Mudcrab developers are welcome.** Reading or reconstructing code here is exposure in the sense of
  [clean-room.md](../clean-room.md): this milestone does not make anyone clean-room independent, does not copy
  reconstructed code or specifications into Mudcrab, and does not replace the transfer process described there. A
  contributor who also works on Mudcrab should record their exposure and keep the two repositories separate.
- Your own coding agent may help under the contributor rules ([contributing-agent.md](../contributing-agent.md)): ask
  once before it reads listings made from your own copy, and never publish anything game-derived.

## Workstreams

The order follows the call dependencies: a foundation class is a callee of the classes after it. Start every
workstream with the smallest ready functions; the large ones (over about 500 bytes) cost many compares each, so
read [near-tier-lessons.md](../near-tier-lessons.md) before them.

| Slot | Workstream | Classes | Depends on |
|---|---|---|---|
| A | Foundation | `BSGraphics::*` (renderer, state, utility), `RendererShadowState`, render-target and buffer helpers, `BSShaderManager`, `BSShaderResourceManager`, `NiTexture`, `NiSourceTexture`, texture database, render geometry (`BSGeometry`, `NiGeometry`, `BSTriShape` family, skin instances), lights (`BSLight`, `NiLight` family) | none |
| B | Shaders and materials | `BSShader`, `BSLightingShader`, `BSEffectShader`, `BSGrassShader`, `BSDistantTreeShader`, `BSBloodSplatterShader`, `BSParticleShader`, `BSUtilityShader`, `BSComputeShader`, `BSSkyShader`, `BSWaterShader`, `BSShaderProperty` and subclasses and controllers, `BSLightingShaderMaterial*`, `BSEffectShaderMaterial`, `BSWaterShaderMaterial`, texture sets | A |
| C | Batching, passes, camera, culling | `BSBatchRenderer`, `BSRenderPass`, `BSShaderAccumulator`, `NiAccumulator` family, `NiCamera`, `BSCompoundFrustum`, `NiCullingProcess` and subclasses, occlusion shapes and planes, portal graph | A, B |
| D | Image space, sky, water system | `BSImagespaceShader*`, `ImageSpace*` effects and manager, `TESImageSpace*`, `Sky`, `Sun`, `Clouds`, `Atmosphere`, `Precipitation`, `TESWeather`, fog properties, `TESWater*` | A, B, C |
| E | Shadows | `BSShadowLight` and its directional, parabolic and frustum subclasses, `ShadowSceneNode`, shadow-map descriptors and setup, shadow passes | A, B, C |

The task issues list the owners. TaylorTurnerIT owns D. The maintainer, awarebayes, owns E and is the
milestone coordinator and reviewer contact.

### A. Foundation

- **Entry points:** the ready list in the inventory below, easiest first. Small `BSGraphics::Renderer` accessors,
  `RendererShadowState` getters, texture and render-target helpers; then the `BSTriShape`, `BSLODTriShape` and
  `NiSkinPartition` constructors; then the lights.
- **Known blockers:** none of the `BSGraphics` renderer group is matched yet, and the public data names only a
  fraction of it (several hundred sibling-file member names are not placed). `Renderer::Init` has a give-up record.
  Most functions call Direct3D 11 through imports; declare them, never define them. State and buffer structures are
  best recovered from the CrashLogger layouts (`reconstruction/generated/crashlogger_pdb/types/`), as the contributor
  card describes.
- **Feeds Mudcrab:** render-target formats and the HDR chain (`findings/exterior-hdr-path-retail-facts.md`),
  sampler and rasteriser defaults, vertex channels and tangent frames of the shape classes, and which lights a
  geometry receives (`findings/point-lights-selection-retail-facts.md`).

### B. Shaders and materials

- **Entry points:** ready functions first (`ClearBSShaders` has 11 callers waiting on it), then the constructors
  and `ForEachTexture` / `CopyMembers` style methods of the property classes, then the material classes, which are
  about half matched already.
- **Known blockers:** the shader subclasses' technique and setup tables are large; the shader constructors share a
  shape across classes, so land one class and reuse its spelling. `BSShader::dtor` and the
  `BSLightingShaderProperty` constructor wait on an unmatched callee.
- **Feeds Mudcrab:** every row of the L1 table: ordinary lighting properties and flags, model-space normals,
  glow and emission controllers, alpha test and blend setup, tree and LOD materials, environment-map and eye
  materials, parallax, face, skin and hair tint, snow, landscape and effect shaders, and the sky and water shader
  shapes Mudcrab currently excludes. Related findings: `grass-retail-constants.md`, `landscape-normal-frame-retail-facts.md`,
  `near-t19-order-retail-facts.md`.

### C. Batching, passes, camera, culling

- **Entry points:** `BSBatchRenderer` list and group helpers, `BSRenderPass` getters, `NiAccumulator` constructors, then
  `NiCamera` frustum code and the culling-process test functions.
- **Known blockers:** it needs B's property and shader getters for the larger pass functions; the portal graph's
  two `SetRoomRoot` entries unlock several callers each. `NiCamera::WindowPointToRay` and
  `BSCompoundFrustum::SetActivePlaneState` wait on an unmatched callee.
- **Feeds Mudcrab:** transparency ordering (the L1 table says retail ordering is still missing), per-geometry light
  lists, culling and interior portal admission (`findings/interior-portal-admission.md`), and object LOD fade decisions.

### D. Image space, sky, water system

- **Entry points** include image-space managers and parameters, `Sky` and weather helpers, and `TESWater*`.
- **Known blockers** include A's render-target helpers, which image-space functions depend on.
- **Feeds Mudcrab** with findings on exterior fog and haze, sky and ambient light over the day, the HDR and
  image-space chain, water displacement and reflections.

### E. Shadows

- **Entry points** include ready methods on the shadow lights and `ShadowSceneNode`. The generated inventory
  lists them in size order.
- **Known blockers** include larger passes that depend on the light, shadow-map and culling setup.
- **Feeds Mudcrab** with findings on sun shadows and interior shadow-light admission.
  [Sun shadows retail facts](../../findings/sun-shadows-retail-facts.md)

## Avoiding collisions

1. **Claim per class.** Run `./sr claim --class <ClassName> --skip-conflicts` for the classes you start. Each class belongs
   to one workstream (the tables below); do not claim another workstream's class without a comment on its task issue.
   A claim lapses after 24 hours without activity and anyone may take it over, so keep a PR or comment moving.
2. **General rounds skip claimed classes.** `./sr next`, `claim --skip-conflicts` and the project's own queue read the same
   claim issues, so a claimed function is not offered to anyone else. Claims are advisory, not locks; staying inside
   your own classes is what avoids duplicated work.
3. **Existing open claims stay excluded.** The inventory counts functions under open claim issues as claimed.
   Ask in the claim issue before taking a class that overlaps it.
4. **One PR per round**, 50 to 200 functions, touching only `reconstruction/**` and `docs/cookbook-notes/**`
   ([contributor-card.md](../contributor-card.md)). Send lesson notes with it.
5. **Adjacent classes** are open to anyone through the normal claim route; they are not part of this milestone's count.

## Progress

The PR bot refreshes this block and the tracking and task issue bodies during hourly housekeeping when
`data/progress.json` changes on `main`. Run the same refresh manually with
`python3 tools/render_inventory.py --fetch-claims --update-doc docs/milestones/rendering.md --update-issues`.

<!-- inventory:start -->

Build `sse-steam-1-7-104`. The published queue lists 18868 of 18868 ready functions. Matched functions come from `data/progress.json`, and functions under 21 open claim issues are counted as claimed.

| Workstream | Known | Matched | Matched % | Claimed | Ready | Waiting | Unlisted | Open bytes |
|---|---:|---:|---:|---:|---:|---:|---:|---:|
| A: Foundation | 416 | 176 | 42.3% | 4 | 54 | 182 | 0 | 62989 |
| B: Shaders and materials | 454 | 236 | 52.0% | 3 | 37 | 178 | 0 | 89018 |
| C: Batching, passes, camera, culling | 331 | 181 | 54.7% | 2 | 28 | 120 | 0 | 70859 |
| D: Image space, sky, water system | 724 | 543 | 75.0% | 2 | 38 | 141 | 0 | 86395 |
| E: Shadows | 122 | 55 | 45.1% | 33 | 1 | 33 | 0 | 42240 |
| **Total A-E** | 2047 | 1191 | 58.2% | 44 | 158 | 654 | 0 | 351501 |
| Adjacent, not assigned | 991 | 453 | 45.7% | 32 | 125 | 381 | 0 | 163807 |

Known counts functions named in the CrashLogger tables or `data/progress.json`. Ready counts available functions in the published queue. Waiting covers give-ups, functions of unknown size and functions absent from the portion of the queue with complete coverage. Unlisted marks unknown readiness when the queue has incomplete coverage or is unavailable. Open bytes sum the sizes of the Ready, Waiting and Unlisted functions.

### Workstream A: Foundation

Scope: BSGraphics state, render targets, buffers, textures and resources, render geometry, lights.

| Group | Known | Matched | Claimed | Ready | Waiting | Unlisted | Main blocker | Unit area |
|---|---:|---:|---:|---:|---:|---:|---|---|
| A1 BSGraphics renderer and state | 64 | 10 | 0 | 18 | 36 | 0 | absent from the ready queue (35) | bsshader |
| A2 Render targets, buffers and depth-stencil | 9 | 3 | 0 | 3 | 3 | 0 | absent from the ready queue (3) | bsshader |
| A3 Shader manager, shader resources and textures | 64 | 41 | 0 | 5 | 18 | 0 | absent from the ready queue (18) | bsshader |
| A4 Lights | 78 | 33 | 3 | 12 | 30 | 0 | absent from the ready queue (30) | gamebryo |
| A5 Render geometry (shapes, skin instances) | 201 | 89 | 1 | 16 | 95 | 0 | absent from the ready queue (95) | gamebryo |

<details><summary>Classes of workstream A with unmatched functions</summary>

| Class | Group | Known | Matched | Claimed | Ready | Waiting | Unlisted | Sibling names not placed |
|---|---|---:|---:|---:|---:|---:|---:|---:|
| BSGraphics::Renderer | A1 | 58 | 10 | 0 | 15 | 33 | 0 | 0 |
| BSGraphics::State | A1 | 3 | 0 | 0 | 0 | 3 | 0 | 0 |
| BSGraphics | A1 | 1 | 0 | 0 | 1 | 0 | 0 | 0 |
| BSGraphics::Utility | A1 | 1 | 0 | 0 | 1 | 0 | 0 | 0 |
| RendererShadowState | A1 | 1 | 0 | 0 | 1 | 0 | 0 | 0 |
| BSGraphics::RenderTargetManager | A2 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| BSShaderRenderTargets | A2 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| CreateIndexBuffer | A2 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| GetImageSpaceRenderTarget_TAAMASK_SSRMASK_SWAP | A2 | 1 | 0 | 0 | 1 | 0 | 0 | 0 |
| PollOcclusionQuery | A2 | 1 | 0 | 0 | 1 | 0 | 0 | 0 |
| SetPSTextureFilterMode | A2 | 1 | 0 | 0 | 1 | 0 | 0 | 0 |
| NiSourceTexture | A3 | 11 | 5 | 0 | 2 | 4 | 0 | 32 |
| NiTexture | A3 | 10 | 5 | 0 | 2 | 3 | 0 | 56 |
| BSScaleformExternalTexture | A3 | 5 | 0 | 0 | 0 | 5 | 0 | 0 |
| BSShaderManager | A3 | 5 | 2 | 0 | 1 | 2 | 0 | 0 |
| BSTextureDB__QueuedHandles__dtor | A3 | 2 | 0 | 0 | 0 | 2 | 0 | 0 |
| BSTextureDB__anonymous_namespace__NiTextureDBForwarded | A3 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| CreateSourceTexture | A3 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| BSLight | A4 | 20 | 5 | 0 | 5 | 10 | 0 | 105 |
| NiPointLight | A4 | 15 | 8 | 1 | 0 | 6 | 0 | 17 |
| NiLight | A4 | 9 | 5 | 0 | 0 | 4 | 0 | 19 |
| NiLightColorController | A4 | 8 | 0 | 0 | 6 | 2 | 0 | 0 |
| NiSpotLight | A4 | 8 | 5 | 0 | 0 | 3 | 0 | 0 |
| NiLightDimmerController | A4 | 7 | 4 | 1 | 1 | 1 | 0 | 12 |
| NiDirectionalLight | A4 | 6 | 4 | 0 | 0 | 2 | 0 | 13 |
| NiAmbientLight | A4 | 4 | 2 | 1 | 0 | 1 | 0 | 0 |
| CalculateActiveNonShadowCasterLights | A4 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| NiGeometry | A5 | 28 | 20 | 0 | 0 | 8 | 0 | 48 |
| BSGeometry | A5 | 26 | 14 | 0 | 1 | 11 | 0 | 52 |
| BSDynamicTriShape | A5 | 21 | 9 | 0 | 0 | 12 | 0 | 24 |
| NiSkinInstance | A5 | 18 | 10 | 0 | 0 | 8 | 0 | 31 |
| BSTriShape | A5 | 17 | 6 | 0 | 2 | 9 | 0 | 13 |
| NiSkinPartition | A5 | 16 | 5 | 0 | 3 | 8 | 0 | 0 |
| BSLODTriShape | A5 | 13 | 4 | 0 | 5 | 4 | 0 | 0 |
| NiGeometryData | A5 | 13 | 7 | 0 | 1 | 5 | 0 | 84 |
| BSMeshLODTriShape | A5 | 11 | 1 | 0 | 2 | 8 | 0 | 0 |
| BSSubIndexTriShape | A5 | 11 | 5 | 0 | 0 | 6 | 0 | 21 |
| BSMultiIndexTriShape | A5 | 9 | 5 | 0 | 0 | 4 | 0 | 23 |
| NiSkinData | A5 | 7 | 2 | 0 | 0 | 5 | 0 | 0 |
| NiAdditionalGeometryData | A5 | 6 | 0 | 1 | 1 | 4 | 0 | 0 |
| BSLODMultiIndexTriShape | A5 | 5 | 1 | 0 | 1 | 3 | 0 | 0 |

</details>

### Workstream B: Shaders and materials

Scope: shader classes, shader properties, materials, sky and water shaders.

| Group | Known | Matched | Claimed | Ready | Waiting | Unlisted | Main blocker | Unit area |
|---|---:|---:|---:|---:|---:|---:|---|---|
| B1 Shader classes (lighting, effect, grass, tree, blood, particle, utility) | 53 | 14 | 0 | 6 | 33 | 0 | absent from the ready queue (33) | bsshader |
| B2 Shader properties and their controllers | 190 | 93 | 1 | 15 | 81 | 0 | absent from the ready queue (81) | bsshader |
| B3 Shader materials and texture sets | 162 | 108 | 2 | 12 | 40 | 0 | absent from the ready queue (39) | bsshader |
| B4 Sky and water shaders, properties and materials | 49 | 21 | 0 | 4 | 24 | 0 | absent from the ready queue (24) | bsshader |

<details><summary>Classes of workstream B with unmatched functions</summary>

| Class | Group | Known | Matched | Claimed | Ready | Waiting | Unlisted | Sibling names not placed |
|---|---|---:|---:|---:|---:|---:|---:|---:|
| BSLightingShader | B1 | 12 | 6 | 0 | 1 | 5 | 0 | 70 |
| BSEffectShader | B1 | 7 | 1 | 0 | 1 | 5 | 0 | 26 |
| BSUtilityShader | B1 | 7 | 2 | 0 | 1 | 4 | 0 | 25 |
| BSGrassShader | B1 | 6 | 1 | 0 | 0 | 5 | 0 | 24 |
| BSDistantTreeShader | B1 | 5 | 1 | 0 | 0 | 4 | 0 | 34 |
| BSParticleShader | B1 | 5 | 1 | 0 | 0 | 4 | 0 | 0 |
| BSShader | B1 | 4 | 0 | 0 | 2 | 2 | 0 | 0 |
| BSComputeShader | B1 | 3 | 1 | 0 | 0 | 2 | 0 | 5 |
| BSBloodSplatterShader | B1 | 2 | 1 | 0 | 0 | 1 | 0 | 0 |
| BSParticleShaderMacros | B1 | 1 | 0 | 0 | 1 | 0 | 0 | 0 |
| GetLightingShaderDefines | B1 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| BSEffectShaderProperty | B2 | 57 | 13 | 0 | 6 | 38 | 0 | 55 |
| BSLightingShaderProperty | B2 | 24 | 11 | 0 | 2 | 11 | 0 | 97 |
| BSShaderProperty | B2 | 17 | 11 | 0 | 0 | 6 | 0 | 83 |
| BSDistantTreeShaderProperty | B2 | 12 | 7 | 0 | 0 | 5 | 0 | 18 |
| BSBloodSplatterShaderProperty | B2 | 11 | 7 | 0 | 0 | 4 | 0 | 11 |
| BSEffectShaderPropertyColorController | B2 | 11 | 8 | 0 | 1 | 2 | 0 | 18 |
| BSEffectShaderPropertyFloatController | B2 | 11 | 7 | 0 | 2 | 2 | 0 | 18 |
| BSLightingShaderPropertyColorController | B2 | 11 | 8 | 0 | 1 | 2 | 0 | 18 |
| BSGrassShaderProperty | B2 | 10 | 5 | 0 | 1 | 4 | 0 | 23 |
| BSLightingShaderPropertyFloatController | B2 | 10 | 7 | 0 | 1 | 2 | 0 | 18 |
| BSLightingShaderPropertyUShortController | B2 | 10 | 8 | 0 | 0 | 2 | 0 | 18 |
| BSShaderPropertyLightData | B2 | 5 | 1 | 0 | 1 | 3 | 0 | 0 |
| OnLoadTextureSet | B2 | 1 | 0 | 1 | 0 | 0 | 0 | 0 |
| BSLightingShaderMaterialBase | B3 | 13 | 10 | 0 | 2 | 1 | 0 | 0 |
| BSLightingShaderMaterialMultiLayerParallax | B3 | 13 | 8 | 2 | 1 | 2 | 0 | 9 |
| BSLightingShaderMaterialEnvmap | B3 | 12 | 10 | 0 | 0 | 2 | 0 | 9 |
| BSLightingShaderMaterialEye | B3 | 11 | 9 | 0 | 1 | 1 | 0 | 8 |
| BSLightingShaderMaterialSnow | B3 | 11 | 10 | 0 | 0 | 1 | 0 | 0 |
| BSLightingShaderMaterialLandscape | B3 | 10 | 5 | 0 | 2 | 3 | 0 | 0 |
| BSLightingShaderMaterialFacegen | B3 | 9 | 4 | 0 | 1 | 4 | 0 | 0 |
| BSLightingShaderMaterialFacegenTint | B3 | 9 | 7 | 0 | 0 | 2 | 0 | 3 |
| BSLightingShaderMaterialParallaxOcc | B3 | 9 | 4 | 0 | 2 | 3 | 0 | 14 |
| BSShaderMaterial | B3 | 9 | 7 | 0 | 0 | 2 | 0 | 12 |
| BSEffectShaderMaterial | B3 | 8 | 3 | 0 | 1 | 4 | 0 | 13 |
| BSLightingShaderMaterialHairTint | B3 | 8 | 6 | 0 | 0 | 2 | 0 | 5 |
| BSLightingShaderMaterialLODLandscape | B3 | 8 | 5 | 0 | 1 | 2 | 0 | 10 |
| BSLightingShaderMaterialParallax | B3 | 8 | 5 | 0 | 1 | 2 | 0 | 9 |
| BSShaderTextureSet | B3 | 8 | 6 | 0 | 0 | 2 | 0 | 12 |
| BSLightingShaderMaterialGlowmap | B3 | 7 | 5 | 0 | 0 | 2 | 0 | 0 |
| BSTextureSet | B3 | 5 | 2 | 0 | 0 | 3 | 0 | 0 |
| BSLightingShaderMaterial | B3 | 4 | 2 | 0 | 0 | 2 | 0 | 0 |
| BSWaterShaderMaterial | B4 | 14 | 7 | 0 | 4 | 3 | 0 | 9 |
| BSWaterShaderProperty | B4 | 14 | 8 | 0 | 0 | 6 | 0 | 24 |
| BSSkyShaderProperty | B4 | 11 | 4 | 0 | 0 | 7 | 0 | 24 |
| BSWaterShader | B4 | 7 | 1 | 0 | 0 | 6 | 0 | 39 |
| BSSkyShader | B4 | 3 | 1 | 0 | 0 | 2 | 0 | 0 |

</details>

### Workstream C: Batching, passes, camera, culling

Scope: render passes, batch renderer, accumulators, camera, frustum, culling, portals.

| Group | Known | Matched | Claimed | Ready | Waiting | Unlisted | Main blocker | Unit area |
|---|---:|---:|---:|---:|---:|---:|---|---|
| C1 Render passes, batch renderer, accumulators | 127 | 76 | 1 | 3 | 47 | 0 | absent from the ready queue (47) | bsshader |
| C2 Camera, frustum, culling, occlusion and portals | 204 | 105 | 1 | 25 | 73 | 0 | absent from the ready queue (73) | gamebryo |

<details><summary>Classes of workstream C with unmatched functions</summary>

| Class | Group | Known | Matched | Claimed | Ready | Waiting | Unlisted | Sibling names not placed |
|---|---|---:|---:|---:|---:|---:|---:|---:|
| BSShaderAccumulator | C1 | 48 | 29 | 1 | 0 | 18 | 0 | 145 |
| BSBatchRenderer | C1 | 31 | 12 | 0 | 2 | 17 | 0 | 0 |
| NiAlphaAccumulator | C1 | 10 | 8 | 0 | 0 | 2 | 0 | 12 |
| BSShaderProperty::RenderPassArray | C1 | 7 | 5 | 0 | 0 | 2 | 0 | 0 |
| BSRenderPass | C1 | 6 | 5 | 0 | 0 | 1 | 0 | 0 |
| NiBackToFrontAccumulator | C1 | 5 | 4 | 0 | 0 | 1 | 0 | 0 |
| AccumulateNodeChildren | C1 | 1 | 0 | 0 | 1 | 0 | 0 | 0 |
| AccumulateSceneGraphNode | C1 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| BSAccumProcess | C1 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| BSRenderPassCache | C1 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| CullJob_SetupDeferredAppend | C1 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| DrainRenderPassDeferredFreeQueue | C1 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| FirstListAccumulationJob | C1 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| BSCompoundFrustum | C2 | 29 | 8 | 0 | 8 | 13 | 0 | 0 |
| BSCullingProcess | C2 | 25 | 12 | 0 | 3 | 10 | 0 | 0 |
| NiCamera | C2 | 25 | 10 | 0 | 2 | 13 | 0 | 36 |
| BSOcclusionPlane | C2 | 17 | 9 | 0 | 1 | 7 | 0 | 30 |
| BSOcclusionBox | C2 | 15 | 10 | 0 | 0 | 5 | 0 | 19 |
| BSPortalGraph | C2 | 15 | 9 | 0 | 3 | 3 | 0 | 0 |
| BSParabolicCullingProcess | C2 | 13 | 5 | 0 | 3 | 5 | 0 | 0 |
| BSPortalGraphEntry | C2 | 12 | 9 | 0 | 2 | 1 | 0 | 19 |
| BSCubeMapCamera | C2 | 7 | 2 | 0 | 0 | 5 | 0 | 11 |
| BSGeometryListCullingProcess | C2 | 6 | 5 | 0 | 0 | 1 | 0 | 0 |
| BSFrustumFOVController | C2 | 4 | 1 | 1 | 0 | 2 | 0 | 0 |
| BSPortal | C2 | 4 | 1 | 0 | 1 | 2 | 0 | 0 |
| HighActorCuller | C2 | 4 | 2 | 0 | 1 | 1 | 0 | 3 |
| NiCullingProcess | C2 | 4 | 3 | 0 | 1 | 0 | 0 | 0 |
| NiFrustumPlanes | C2 | 2 | 1 | 0 | 0 | 1 | 0 | 0 |
| SubmitCullResultsJob | C2 | 2 | 0 | 0 | 0 | 2 | 0 | 0 |
| PruneFrustumPlanes | C2 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| SetupCullingJobManager | C2 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |

</details>

### Workstream D: Image space, sky, water system

Scope: image space, sky, weather, fog, water.

| Group | Known | Matched | Claimed | Ready | Waiting | Unlisted | Main blocker | Unit area |
|---|---:|---:|---:|---:|---:|---:|---|---|
| D2 Image space: manager, effects and image-space shaders | 614 | 505 | 2 | 22 | 85 | 0 | absent from the ready queue (85) | bsshader |
| D3 Sky, sun, clouds, weather and fog | 71 | 21 | 0 | 8 | 42 | 0 | absent from the ready queue (42) | skyrim_shared |
| D4 Water system, displacement and reflections | 39 | 17 | 0 | 8 | 14 | 0 | absent from the ready queue (14) | skyrim_shared |

<details><summary>Classes of workstream D with unmatched functions</summary>

| Class | Group | Known | Matched | Claimed | Ready | Waiting | Unlisted | Sibling names not placed |
|---|---|---:|---:|---:|---:|---:|---:|---:|
| BSImagespaceShader | D2 | 19 | 15 | 0 | 0 | 4 | 0 | 29 |
| TESImageSpaceModifier | D2 | 13 | 3 | 0 | 3 | 7 | 0 | 0 |
| ImageSpaceEffect | D2 | 7 | 1 | 0 | 1 | 5 | 0 | 0 |
| ImageSpaceEffectNoise | D2 | 7 | 0 | 0 | 2 | 5 | 0 | 0 |
| ImageSpaceModifierInstanceForm | D2 | 7 | 1 | 0 | 2 | 4 | 0 | 19 |
| BSImagespaceShaderCopyCustomViewport | D2 | 6 | 4 | 0 | 0 | 2 | 0 | 0 |
| BSImagespaceShaderWaterFlow | D2 | 6 | 4 | 0 | 0 | 2 | 0 | 0 |
| ImageSpaceEffectGetHit | D2 | 6 | 1 | 0 | 0 | 5 | 0 | 0 |
| TESImagespaceManager | D2 | 6 | 0 | 0 | 2 | 4 | 0 | 0 |
| BSImagespaceShaderISBlur | D2 | 5 | 4 | 0 | 0 | 1 | 0 | 0 |
| ImageSpaceEffectDepthOfField | D2 | 5 | 0 | 0 | 0 | 5 | 0 | 0 |
| ImageSpaceEffectFullScreenBlur | D2 | 5 | 1 | 0 | 0 | 4 | 0 | 0 |
| ImageSpaceEffectRefraction | D2 | 5 | 0 | 0 | 0 | 5 | 0 | 0 |
| ImageSpaceShaderParam | D2 | 5 | 1 | 0 | 2 | 2 | 0 | 0 |
| TESImageSpace | D2 | 5 | 1 | 1 | 1 | 2 | 0 | 0 |
| BSImagespaceShaderFXAA | D2 | 4 | 3 | 0 | 0 | 1 | 0 | 2 |
| BSImagespaceShaderISLightingCompositeMenu | D2 | 4 | 3 | 0 | 1 | 0 | 0 | 0 |
| BSImagespaceShaderLensFlareVisibility | D2 | 4 | 3 | 0 | 0 | 1 | 0 | 4 |
| BSImagespaceShaderLensFlare | D2 | 3 | 2 | 0 | 0 | 1 | 0 | 0 |
| ImageSpaceEffectBlur | D2 | 3 | 0 | 0 | 0 | 3 | 0 | 0 |
| ImageSpaceEffectHDR | D2 | 3 | 0 | 0 | 0 | 3 | 0 | 0 |
| ImageSpaceEffectMap | D2 | 3 | 0 | 0 | 0 | 3 | 0 | 0 |
| ImageSpaceEffectVolumetricLighting | D2 | 3 | 0 | 0 | 0 | 3 | 0 | 0 |
| ImageSpaceEffectWaterDisplacement | D2 | 3 | 0 | 0 | 0 | 3 | 0 | 0 |
| ImageSpaceEffectWorldMap | D2 | 3 | 0 | 0 | 0 | 3 | 0 | 0 |
| ImageSpaceManager | D2 | 3 | 0 | 1 | 2 | 0 | 0 | 0 |
| ImageSpaceModifierInstance | D2 | 3 | 1 | 0 | 2 | 0 | 0 | 0 |
| ImageSpaceModifierInstanceDOF | D2 | 3 | 2 | 0 | 0 | 1 | 0 | 0 |
| ImageSpaceModifierInstanceTemp | D2 | 3 | 2 | 0 | 1 | 0 | 0 | 0 |
| ImageSpaceEffectOption | D2 | 2 | 0 | 0 | 1 | 1 | 0 | 0 |
| ImageSpaceEffectParam | D2 | 2 | 1 | 0 | 0 | 1 | 0 | 0 |
| ImageSpaceEffectRadialBlur | D2 | 2 | 0 | 0 | 0 | 2 | 0 | 0 |
| ImageSpaceModifierInstanceRB | D2 | 2 | 1 | 0 | 0 | 1 | 0 | 0 |
| GetVLTemporalAccumulationFactor | D2 | 1 | 0 | 0 | 1 | 0 | 0 | 0 |
| UpdateVolumetricLightingRenderData | D2 | 1 | 0 | 0 | 1 | 0 | 0 | 0 |
| VolumetricLightingDescriptor | D2 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| Sky | D3 | 31 | 8 | 0 | 3 | 20 | 0 | 145 |
| Sun | D3 | 6 | 1 | 0 | 3 | 2 | 0 | 0 |
| BSFogProperty | D3 | 5 | 3 | 0 | 0 | 2 | 0 | 0 |
| Precipitation | D3 | 5 | 0 | 0 | 0 | 5 | 0 | 0 |
| TESWeather | D3 | 5 | 1 | 0 | 1 | 3 | 0 | 0 |
| Atmosphere | D3 | 4 | 1 | 0 | 0 | 3 | 0 | 0 |
| Clouds | D3 | 3 | 0 | 0 | 0 | 3 | 0 | 0 |
| Moon | D3 | 2 | 1 | 0 | 0 | 1 | 0 | 0 |
| Stars | D3 | 2 | 0 | 0 | 0 | 2 | 0 | 0 |
| Precipitation::OcclusionMapData | D3 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| SkyObject | D3 | 1 | 0 | 0 | 1 | 0 | 0 | 0 |
| TESWaterForm | D4 | 15 | 9 | 0 | 3 | 3 | 0 | 134 |
| TESWaterSystem | D4 | 15 | 8 | 0 | 2 | 5 | 0 | 0 |
| TESWaterDisplacement | D4 | 4 | 0 | 0 | 2 | 2 | 0 | 0 |
| TESWaterReflections | D4 | 3 | 0 | 0 | 0 | 3 | 0 | 0 |
| TESWaterNormals | D4 | 2 | 0 | 0 | 1 | 1 | 0 | 0 |

</details>

### Workstream E: Shadows

Scope: shadow lights, shadow scene node, shadow-map setup and shadow passes.

| Group | Known | Matched | Claimed | Ready | Waiting | Unlisted | Main blocker | Unit area |
|---|---:|---:|---:|---:|---:|---:|---|---|
| E1 Shadow lights, scene node, maps and passes | 122 | 55 | 33 | 1 | 33 | 0 | absent from the ready queue (33) | bsshader |

<details><summary>Classes of workstream E with unmatched functions</summary>

| Class | Group | Known | Matched | Claimed | Ready | Waiting | Unlisted | Sibling names not placed |
|---|---|---:|---:|---:|---:|---:|---:|---:|
| ShadowSceneNode | E1 | 52 | 24 | 12 | 0 | 16 | 0 | 120 |
| BSShadowDirectionalLight | E1 | 18 | 9 | 5 | 0 | 4 | 0 | 10 |
| BSShadowLight | E1 | 18 | 11 | 5 | 0 | 2 | 0 | 55 |
| BSShadowParabolicLight | E1 | 12 | 8 | 1 | 0 | 3 | 0 | 9 |
| BSShadowFrustumLight | E1 | 7 | 2 | 4 | 0 | 1 | 0 | 10 |
| BSTArray_ShadowmapDescriptor_ | E1 | 3 | 1 | 2 | 0 | 0 | 0 | 0 |
| BSShadowParabolicLight_RenderImpl | E1 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| CalculateActiveShadowCasterLights | E1 | 1 | 0 | 1 | 0 | 0 | 0 | 0 |
| CalculateAndDrawShadowCasterLights | E1 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| DrawWorld_RenderShadowCasters | E1 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| ProcessAllQueuedLights | E1 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| RenderActiveShadowCasterLights | E1 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| RenderShadowmasks | E1 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| RenderVolumetricLightingShadowMaps | E1 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| ResetCalculatedShadowCasterLights | E1 | 1 | 0 | 1 | 0 | 0 | 0 | 0 |
| ShadowSceneNode_SetShadowCasterLightArrayEntry | E1 | 1 | 0 | 1 | 0 | 0 | 0 | 0 |
| ShadowmapDescriptor | E1 | 1 | 0 | 1 | 0 | 0 | 0 | 0 |
| UpdateOrAssignShadowCSTexture | E1 | 1 | 0 | 0 | 1 | 0 | 0 | 0 |

</details>

### Adjacent: Adjacent

Scope: listed for context, owned by the general rounds.

| Group | Known | Matched | Claimed | Ready | Waiting | Unlisted | Main blocker | Unit area |
|---|---:|---:|---:|---:|---:|---:|---|---|
| X1 Particle systems and emitters | 562 | 266 | 31 | 74 | 191 | 0 | absent from the ready queue (190) | gamebryo |
| X2 Scaleform UI renderer | 49 | 0 | 0 | 16 | 33 | 0 | absent from the ready queue (33) | - |
| X3 Game cameras and camera states | 154 | 68 | 0 | 25 | 61 | 0 | absent from the ready queue (60) | skyrim |
| X4 Render-related forms, decals, effects, grass and LOD | 226 | 119 | 1 | 10 | 96 | 0 | absent from the ready queue (96) | skyrim_shared |

<details><summary>Classes of adjacent with unmatched functions</summary>

| Class | Group | Known | Matched | Claimed | Ready | Waiting | Unlisted | Sibling names not placed |
|---|---|---:|---:|---:|---:|---:|---:|---:|
| NiPSysEmitterCtlr | X1 | 23 | 14 | 4 | 2 | 3 | 0 | 30 |
| BSMasterParticleSystem | X1 | 19 | 10 | 0 | 1 | 8 | 0 | 0 |
| NiParticleSystem | X1 | 19 | 7 | 1 | 3 | 8 | 0 | 0 |
| NiPSysBombModifier | X1 | 17 | 12 | 1 | 1 | 3 | 0 | 0 |
| BSParticleSystemManager | X1 | 13 | 4 | 0 | 1 | 8 | 0 | 0 |
| NiPSysGravityModifier | X1 | 13 | 7 | 2 | 2 | 2 | 0 | 0 |
| NiPSysMeshEmitter | X1 | 13 | 3 | 1 | 1 | 8 | 0 | 33 |
| NiParticles | X1 | 13 | 7 | 0 | 0 | 6 | 0 | 24 |
| BSPSysHavokUpdateModifier | X1 | 12 | 6 | 0 | 2 | 4 | 0 | 0 |
| NiPSysData | X1 | 12 | 0 | 1 | 5 | 6 | 0 | 22 |
| NiPSysModifierCtlr | X1 | 12 | 9 | 1 | 1 | 1 | 0 | 0 |
| NiPSysModifier | X1 | 11 | 9 | 2 | 0 | 0 | 0 | 14 |
| NiPSysBoundUpdateModifier | X1 | 10 | 3 | 1 | 0 | 6 | 0 | 16 |
| BSPSysMultiTargetEmitterCtlr | X1 | 9 | 2 | 0 | 2 | 5 | 0 | 0 |
| NiPSysColorModifier | X1 | 9 | 6 | 1 | 0 | 2 | 0 | 0 |
| NiPSysMeshUpdateModifier | X1 | 9 | 4 | 2 | 0 | 3 | 0 | 0 |
| NiPSysSpawnModifier | X1 | 9 | 4 | 2 | 2 | 1 | 0 | 0 |
| BSPSysInheritVelocityModifier | X1 | 8 | 2 | 0 | 2 | 4 | 0 | 0 |
| BSPSysLODModifier | X1 | 8 | 4 | 0 | 3 | 1 | 0 | 0 |
| BSPSysRecycleBoundModifier | X1 | 8 | 1 | 1 | 4 | 2 | 0 | 0 |
| NiPSysAgeDeathModifier | X1 | 8 | 4 | 0 | 1 | 3 | 0 | 0 |
| NiPSysCollider | X1 | 8 | 0 | 2 | 4 | 2 | 0 | 0 |
| NiPSysVolumeEmitter | X1 | 8 | 7 | 0 | 0 | 1 | 0 | 0 |
| BSPSysArrayEmitter | X1 | 7 | 3 | 0 | 0 | 4 | 0 | 23 |
| BSPSysStripUpdateModifier | X1 | 7 | 4 | 0 | 0 | 3 | 0 | 0 |
| NiPSysAirFieldModifier | X1 | 7 | 2 | 0 | 1 | 4 | 0 | 0 |
| NiPSysBoxEmitter | X1 | 7 | 2 | 2 | 1 | 2 | 0 | 0 |
| NiPSysDragFieldModifier | X1 | 7 | 4 | 0 | 1 | 2 | 0 | 0 |
| NiPSysDragModifier | X1 | 7 | 4 | 0 | 1 | 2 | 0 | 0 |
| NiPSysFieldModifier | X1 | 7 | 5 | 0 | 0 | 2 | 0 | 0 |
| NiPSysGrowFadeModifier | X1 | 7 | 2 | 0 | 3 | 2 | 0 | 0 |
| NiPSysModifierBoolCtlr | X1 | 7 | 4 | 0 | 1 | 2 | 0 | 0 |
| NiPSysModifierFloatCtlr | X1 | 7 | 4 | 0 | 1 | 2 | 0 | 0 |
| NiPSysPlanarCollider | X1 | 7 | 0 | 0 | 1 | 6 | 0 | 0 |
| NiPSysRotationModifier | X1 | 7 | 2 | 2 | 3 | 0 | 0 | 0 |
| NiPSysSphereEmitter | X1 | 7 | 3 | 1 | 1 | 2 | 0 | 0 |
| NiPSysVortexFieldModifier | X1 | 7 | 5 | 0 | 0 | 2 | 0 | 0 |
| BSPSysSimpleColorModifier | X1 | 6 | 2 | 0 | 1 | 3 | 0 | 0 |
| BSPSysSubTexModifier | X1 | 6 | 2 | 0 | 3 | 1 | 0 | 0 |
| NiPSysCylinderEmitter | X1 | 6 | 1 | 2 | 1 | 2 | 0 | 0 |
| NiPSysEmitter | X1 | 6 | 3 | 0 | 1 | 2 | 0 | 0 |
| NiPSysGravityFieldModifier | X1 | 6 | 4 | 0 | 0 | 2 | 0 | 0 |
| NiPSysSphericalCollider | X1 | 6 | 0 | 0 | 1 | 5 | 0 | 0 |
| NiPSysUpdateCtlr | X1 | 6 | 2 | 0 | 1 | 3 | 0 | 0 |
| NiParticleMeshes | X1 | 6 | 2 | 0 | 1 | 3 | 0 | 0 |
| NiParticleMeshesData | X1 | 6 | 0 | 0 | 3 | 3 | 0 | 0 |
| BSPSysScaleModifier | X1 | 5 | 1 | 0 | 1 | 3 | 0 | 0 |
| NiPSysModifierActiveCtlr | X1 | 5 | 3 | 0 | 0 | 2 | 0 | 14 |
| NiPSysResetOnLoopCtlr | X1 | 5 | 2 | 1 | 0 | 2 | 0 | 0 |
| NiParticlesData | X1 | 5 | 0 | 0 | 2 | 3 | 0 | 0 |
| BGSShaderParticleGeometryData | X1 | 4 | 1 | 0 | 0 | 3 | 0 | 0 |
| BSParticleShaderGeometry | X1 | 4 | 2 | 0 | 1 | 1 | 0 | 3 |
| BSParticleShaderGeometryEmitter | X1 | 4 | 2 | 0 | 1 | 1 | 0 | 4 |
| BSStripParticleSystem | X1 | 4 | 1 | 0 | 1 | 2 | 0 | 0 |
| NiPSysEmitterCtlrData | X1 | 4 | 2 | 1 | 1 | 0 | 0 | 0 |
| NiPSysEmitterDeclinationCtlr | X1 | 4 | 3 | 0 | 0 | 1 | 0 | 14 |
| NiPSysEmitterDeclinationVarCtlr | X1 | 4 | 3 | 0 | 0 | 1 | 0 | 14 |
| NiPSysEmitterInitialRadiusCtlr | X1 | 4 | 3 | 0 | 0 | 1 | 0 | 14 |
| NiPSysEmitterLifeSpanCtlr | X1 | 4 | 3 | 0 | 0 | 1 | 0 | 14 |
| NiPSysEmitterPlanarAngleCtlr | X1 | 4 | 3 | 0 | 0 | 1 | 0 | 14 |
| NiPSysEmitterPlanarAngleVarCtlr | X1 | 4 | 3 | 0 | 0 | 1 | 0 | 14 |
| NiPSysEmitterSpeedCtlr | X1 | 4 | 3 | 0 | 0 | 1 | 0 | 14 |
| NiPSysFieldAttenuationCtlr | X1 | 4 | 3 | 0 | 0 | 1 | 0 | 14 |
| NiPSysFieldMagnitudeCtlr | X1 | 4 | 3 | 0 | 0 | 1 | 0 | 14 |
| NiPSysFieldMaxDistanceCtlr | X1 | 4 | 3 | 0 | 0 | 1 | 0 | 14 |
| NiPSysGravityStrengthCtlr | X1 | 4 | 3 | 0 | 0 | 1 | 0 | 14 |
| NiPSysInitialRotAngleCtlr | X1 | 4 | 3 | 0 | 0 | 1 | 0 | 14 |
| NiPSysInitialRotAngleVarCtlr | X1 | 4 | 3 | 0 | 0 | 1 | 0 | 14 |
| NiPSysInitialRotSpeedCtlr | X1 | 4 | 3 | 0 | 0 | 1 | 0 | 14 |
| NiPSysInitialRotSpeedVarCtlr | X1 | 4 | 3 | 0 | 0 | 1 | 0 | 14 |
| NiPSysTurbulenceFieldModifier | X1 | 4 | 2 | 0 | 1 | 1 | 0 | 0 |
| BSParticleShaderCollisionEmitter | X1 | 3 | 2 | 0 | 0 | 1 | 0 | 4 |
| BSParticleShaderRayEmitter | X1 | 3 | 2 | 0 | 0 | 1 | 0 | 4 |
| NiPSysAirFieldAirFrictionCtlr | X1 | 3 | 2 | 0 | 0 | 1 | 0 | 14 |
| NiPSysAirFieldInheritVelocityCtlr | X1 | 3 | 2 | 0 | 0 | 1 | 0 | 14 |
| NiPSysAirFieldSpreadCtlr | X1 | 3 | 2 | 0 | 0 | 1 | 0 | 14 |
| NiPSysColliderManager | X1 | 3 | 0 | 0 | 1 | 2 | 0 | 0 |
| NiPSysPositionModifier | X1 | 3 | 2 | 0 | 0 | 1 | 0 | 0 |
| NiPSysRadialFieldModifier | X1 | 3 | 2 | 0 | 0 | 1 | 0 | 0 |
| BSParticleShaderEmitter | X1 | 2 | 1 | 0 | 0 | 1 | 0 | 0 |
| BSParticleShaderObjectEmitter | X1 | 2 | 1 | 0 | 0 | 1 | 0 | 2 |
| NiParticleInfo | X1 | 2 | 0 | 0 | 2 | 0 | 0 | 0 |
| NiParticleSDM | X1 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| Scaleform::Render::Text::DocView | X2 | 15 | 0 | 0 | 1 | 14 | 0 | 0 |
| Scaleform::Render::Text | X2 | 6 | 0 | 0 | 1 | 5 | 0 | 0 |
| Scaleform::Render::Text::ParagraphFormat | X2 | 4 | 0 | 0 | 2 | 2 | 0 | 0 |
| Scaleform::Render::Text::Highlighter | X2 | 3 | 0 | 0 | 2 | 1 | 0 | 0 |
| Scaleform::Render::Text::HighlighterRangeIterator | X2 | 2 | 0 | 0 | 2 | 0 | 0 | 0 |
| Scaleform::Render::Text::Paragraph | X2 | 2 | 0 | 0 | 1 | 1 | 0 | 0 |
| Scaleform::Render::Text::TextFormat | X2 | 2 | 0 | 0 | 0 | 2 | 0 | 0 |
| Scaleform::Render::Cxform | X2 | 1 | 0 | 0 | 1 | 0 | 0 | 0 |
| Scaleform::Render::D3D1x::ShaderManager | X2 | 1 | 0 | 0 | 1 | 0 | 0 | 0 |
| Scaleform::Render::GlyphQueue | X2 | 1 | 0 | 0 | 1 | 0 | 0 | 0 |
| Scaleform::Render::GradientData | X2 | 1 | 0 | 0 | 1 | 0 | 0 | 0 |
| Scaleform::Render::Matrix2x4 | X2 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| Scaleform::Render::RBGenericImpl::DepthStencilBuffer | X2 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| Scaleform::Render::RBGenericImpl::RenderBufferManager | X2 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| Scaleform::Render::ScreenToWorld | X2 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| Scaleform::Render::Text::HighlighterPosIterator | X2 | 1 | 0 | 0 | 1 | 0 | 0 | 0 |
| Scaleform::Render::Text::LineBuffer | X2 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| Scaleform::Render::Text::LineBuffer::Line | X2 | 1 | 0 | 0 | 1 | 0 | 0 | 0 |
| Scaleform::Render::Text::Paragraph::CharactersIterator | X2 | 1 | 0 | 0 | 1 | 0 | 0 | 0 |
| Scaleform::Render::Text::Paragraph::TextBuffer | X2 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| Scaleform::Render::Text::SGMLParser | X2 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| Scaleform::Render::Text::StyledText | X2 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| PlayerCamera | X3 | 53 | 28 | 0 | 5 | 20 | 0 | 144 |
| DragonCameraState | X3 | 13 | 5 | 0 | 3 | 5 | 0 | 0 |
| HorseCameraState | X3 | 13 | 5 | 0 | 1 | 7 | 0 | 6 |
| LocalMapCamera | X3 | 11 | 5 | 0 | 1 | 5 | 0 | 0 |
| FreeCameraState | X3 | 10 | 5 | 0 | 1 | 4 | 0 | 0 |
| FurnitureCameraState | X3 | 8 | 2 | 0 | 1 | 5 | 0 | 0 |
| TESCamera | X3 | 8 | 5 | 0 | 3 | 0 | 0 | 9 |
| TweenMenuCameraState | X3 | 8 | 3 | 0 | 3 | 2 | 0 | 0 |
| VATSCameraState | X3 | 8 | 1 | 0 | 3 | 4 | 0 | 0 |
| PlayerCameraTransitionState | X3 | 6 | 1 | 0 | 2 | 3 | 0 | 0 |
| BleedoutCameraState | X3 | 5 | 1 | 0 | 1 | 3 | 0 | 0 |
| MapCamera | X3 | 5 | 2 | 0 | 1 | 2 | 0 | 0 |
| RaceSexCamera | X3 | 2 | 1 | 0 | 0 | 1 | 0 | 0 |
| TESGrass | X4 | 28 | 26 | 0 | 1 | 1 | 0 | 22 |
| BGSLightingTemplate | X4 | 17 | 15 | 0 | 0 | 2 | 0 | 67 |
| ReferenceEffect | X4 | 17 | 8 | 0 | 1 | 8 | 0 | 0 |
| BSTerrainEffect | X4 | 16 | 5 | 0 | 0 | 11 | 0 | 0 |
| ShaderReferenceEffect | X4 | 16 | 6 | 0 | 0 | 10 | 0 | 0 |
| TESEffectShader | X4 | 12 | 7 | 0 | 0 | 5 | 0 | 83 |
| BGSTerrainManager | X4 | 11 | 9 | 0 | 1 | 1 | 0 | 0 |
| BSTempEffectSimpleDecal | X4 | 11 | 6 | 0 | 0 | 5 | 0 | 36 |
| TESLandTexture | X4 | 11 | 5 | 0 | 0 | 6 | 0 | 0 |
| BGSTextureSet | X4 | 10 | 2 | 0 | 2 | 6 | 0 | 0 |
| GrassManager | X4 | 10 | 0 | 0 | 1 | 9 | 0 | 0 |
| BSTempEffectGeometryDecal | X4 | 9 | 4 | 0 | 1 | 4 | 0 | 0 |
| TESTexture | X4 | 9 | 8 | 1 | 0 | 0 | 0 | 0 |
| BGSMaterialType | X4 | 8 | 1 | 0 | 0 | 7 | 0 | 0 |
| BSTempEffectParticle | X4 | 8 | 2 | 0 | 0 | 6 | 0 | 0 |
| BGSMaterialObject | X4 | 7 | 2 | 0 | 0 | 5 | 0 | 0 |
| BGSReferenceEffect | X4 | 6 | 3 | 0 | 0 | 3 | 0 | 0 |
| BGSDecalNode | X4 | 5 | 3 | 0 | 0 | 2 | 0 | 20 |
| BSDecalPlacementVectorExtraData | X4 | 5 | 0 | 0 | 3 | 2 | 0 | 0 |
| BGSTerrainBlock | X4 | 4 | 3 | 0 | 0 | 1 | 0 | 0 |
| BGSVolumetricLighting | X4 | 3 | 1 | 0 | 0 | 2 | 0 | 0 |

</details>

<details><summary>Entry points</summary>

**Workstream A entry points** (names are CrashLogger-derived, CRASHLOGGER_PDB(59818@2026.10.24))

| RVA | Name | Size | State | Callers unlocked |
|---|---|---:|---|---:|
| `0x1010920` | BSGraphics::Renderer::GetScaleformRendererParameters | 16 | ready | 1 |
| `0x101d730` | RendererShadowState::GetViewDepthRange | 16 | ready | 0 |
| `0x1008b10` | Renderer::SetWindowPosition | 20 | ready | 0 |
| `0x10193a0` | BSGraphics::Utility::CopyNiColorAToFloat | 23 | ready | 1 |
| `0xec1e40` | NiTexture::QLoadLevel | 28 | ready | 0 |
| `0x101e2d0` | SetPSTextureFilterMode | 29 | ready | 0 |
| `0x100c6f0` | BSGraphics::Renderer::UnmapDynamicBuffer | 34 | ready | 0 |
| `0x1010290` | BSGraphics::Renderer_SetPixelShader | 36 | ready | 0 |
| `0xf7e7d0` | NiLightColorController::ctor | 39 | ready | 0 |
| `0xf1b540` | BSLODTriShape::ctor_default | 40 | ready | 0 |
| `0xf7e5a0` | NiLightColorController::CopyMembers | 40 | ready | 0 |
| `0x100fee0` | BSGraphics::Renderer_SetShader | 41 | ready | 0 |
| `0x1555990` | BSGraphics::GetThreadRenderContextLock | 43 | ready | 0 |
| `0x1245df0` | NiSkinPartition::NiSkinPartition | 46 | ready | 0 |
| `0x153c900` | GetImageSpaceRenderTarget_TAAMASK_SSRMASK_SWAP | 46 | ready | 0 |

**Workstream B entry points** (names are CrashLogger-derived, CRASHLOGGER_PDB(59818@2026.10.24))

| RVA | Name | Size | State | Callers unlocked |
|---|---|---:|---|---:|
| `0x1594070` | BSParticleShaderMacros::GetVertexShaderID | 13 | ready | 0 |
| `0x1578930` | BSEffectShader::SetAlphaTestRef | 72 | ready | 0 |
| `0xd6e480` | BSEffectShaderProperty::CreateClone | 90 | ready | 0 |
| `0x154c9a0` | BSLightingShader::SetupTexture | 94 | ready | 0 |
| `0x157c030` | BSEffectShaderPropertyFloatController::InitSDM | 101 | ready | 0 |
| `0x15260f0` | BSLightingShaderMaterialParallax::GetTextures | 106 | ready | 0 |
| `0x1519140` | BSLightingShaderProperty::InitINISettings | 113 | ready | 0 |
| `0xd6e9e0` | BSEffectShaderProperty::GetRenderPasses_ShadowMapOrMask | 115 | ready | 0 |
| `0x118f2b0` | BSEffectShaderProperty::AsGeometry | 127 | ready | 0 |
| `0x151caa0` | BSGrassShaderProperty::ForEachTexture | 140 | ready | 0 |
| `0x1526620` | BSLightingShaderMaterialParallaxOcc::SaveBinary | 142 | ready | 0 |
| `0x15266c0` | BSLightingShaderMaterialParallaxOcc::LoadBinary | 142 | ready | 0 |
| `0x1578980` | BSShader::ctor | 163 | ready | 8 |
| `0x1526cd0` | BSLightingShaderMaterialFacegen::ReceiveValuesFromRootMaterial | 163 | ready | 0 |
| `0x1569260` | BSShaderPropertyLightData::RemoveLight | 164 | ready | 0 |

**Workstream C entry points** (names are CrashLogger-derived, CRASHLOGGER_PDB(59818@2026.10.24))

| RVA | Name | Size | State | Callers unlocked |
|---|---|---:|---|---:|
| `0xff91e0` | BSCompoundFrustum::GetActivePlaneState | 66 | ready | 0 |
| `0xff9230` | BSCompoundFrustum::SetActivePlaneState | 67 | ready | 0 |
| `0x152b6d0` | BSCullingProcess::InitCullDescriptor | 68 | ready | 0 |
| `0x1587090` | BSParabolicCullingProcess::TestBaseVisibility2 | 72 | ready | 0 |
| `0x155fed0` | BSBatchRenderer::GetNextPassSlotInGroup | 100 | ready | 0 |
| `0x15870e0` | BSParabolicCullingProcess::TestBaseVisibility1_14132C900 | 100 | ready | 0 |
| `0x213b70` | BSPortal::dtor_deleting | 110 | ready | 0 |
| `0xfda080` | BSPortalGraph::AddRoom | 171 | ready | 0 |
| `0x15617f0` | BSBatchRenderer::ComputeAlphaGroupDepth | 175 | ready | 0 |
| `0xfd95c0` | BSPortalGraphEntry::AddRoomToAccumList | 203 | ready | 0 |
| `0xff9280` | BSCompoundFrustum::RemoveEmptyGroups | 205 | ready | 0 |
| `0x1587150` | BSParabolicCullingProcess::GetHemisphereMask | 222 | ready | 1 |
| `0xfdacc0` | BSPortalGraph::RemoveByPointer | 228 | ready | 0 |
| `0xfd97a0` | BSPortalGraphEntry::HasSharedRoomVisibility | 250 | ready | 0 |
| `0xf049c0` | BSCullingProcess::CullNodeAgainstFrustum | 273 | ready | 0 |

**Workstream D entry points** (names are CrashLogger-derived, CRASHLOGGER_PDB(59818@2026.10.24))

| RVA | Name | Size | State | Callers unlocked |
|---|---|---:|---|---:|
| `0x52af40` | TESWaterSystem::ResetWaterDisplacementSimulation | 22 | ready | 0 |
| `0x1530d70` | GetVLTemporalAccumulationFactor | 22 | ready | 0 |
| `0x2a8440` | TESImageSpaceModifier::MakeDefaultGetHit | 25 | ready | 0 |
| `0x14eedf0` | TESImagespaceManager::IsScreenshotSaved | 25 | ready | 0 |
| `0x152b1b0` | ImageSpaceShaderParam::sub_1412D6730 | 32 | ready | 0 |
| `0x1586480` | ImageSpaceEffectNoise::Bias | 48 | ready | 0 |
| `0x150a7e0` | BSImagespaceShaderISLightingCompositeMenu::Unk_0D | 50 | ready | 0 |
| `0x41ad30` | Sun::GetSunOcclusionPercent | 64 | ready | 0 |
| `0x14edb20` | ImageSpaceManager::SetupEffects | 65 | ready | 0 |
| `0x3070b0` | TESWaterForm::sub_1402ACA10 | 67 | ready | 0 |
| `0x419d00` | Sky::CalcSunriseEnd | 67 | ready | 0 |
| `0x419d50` | Sky::CalcSunsetBegin | 67 | ready | 0 |
| `0x2a8120` | TESImageSpaceModifier::InitializeData | 68 | ready | 0 |
| `0x41cbb0` | Sun::GetSunPositionData | 69 | ready | 3 |
| `0x41b230` | Sun::sub_1403BA8B0 | 82 | ready | 0 |

**Workstream E entry points** (names are CrashLogger-derived, CRASHLOGGER_PDB(59818@2026.10.24))

| RVA | Name | Size | State | Callers unlocked |
|---|---|---:|---|---:|
| `0x100f7e0` | UpdateOrAssignShadowCSTexture | 99 | ready | 0 |

</details>

<!-- inventory:end -->
