# Milestone: Rendering 1:1

Decompile Skyrim SE's rendering subsystem, function by function, until each function is a byte match, so the
renderer can be understood from source that provably compiles to the same code. The work is split into four
workstreams (A to D) so that people can work in parallel without touching each other's classes.

Tracking issue: [#1185](https://github.com/Mudcrab-Team/skyrim_decomp/issues/1185). Task issues: A [#1186](https://github.com/Mudcrab-Team/skyrim_decomp/issues/1186), B [#1187](https://github.com/Mudcrab-Team/skyrim_decomp/issues/1187), C [#1188](https://github.com/Mudcrab-Team/skyrim_decomp/issues/1188), D [#1189](https://github.com/Mudcrab-Team/skyrim_decomp/issues/1189). GitHub milestone:
[Rendering 1:1](https://github.com/Mudcrab-Team/skyrim_decomp/milestone/1).

## Goal and scope

- **Goal:** every function of the render subsystem in `data/progress.json` reaches `matched`: a byte match on two
  hosts plus one admitted review, exactly the gate in [verification.md](../verification.md). Nothing about the
  acceptance rule, the PR route or the check jobs changes for this milestone.
- **In scope:** the classes in the inventory below, workstreams A to D. They are the `BSGraphics` layer (renderer,
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
| D | Shadows, image space, sky, water | `BSShadowLight` family, `ShadowSceneNode`, `BSImagespaceShader*`, `ImageSpace*` effects and manager, `TESImageSpace*`, `Sky`, `Sun`, `Clouds`, `Atmosphere`, `Precipitation`, `TESWeather`, fog properties, `TESWater*` | A, B, C |

Owner slots A to D are filled by the task issues. An issue marked "Owner: open" is free: claim it by commenting.
The coordinator and reviewer contact for the milestone is the maintainer, awarebayes.

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

### D. Shadows, image space, sky, water

- **Entry points:** the image-space group is about 80 percent matched, so the remaining image-space functions are mostly
  managers, parameters and the few non-leaf effects; then `ShadowSceneNode` and the shadow lights, then `Sky`, `Sun` and
  weather, then `TESWater*`.
- **Known blockers:** shadow and sky functions are large (several hundred bytes on average), so this workstream
  carries the most bytes; if it falls behind, split the shadow group into a fifth slot. Image-space functions depend on
  A's render-target helpers (`GetImageSpaceRenderTarget_*` has 11 callers waiting).
- **Feeds Mudcrab:** the deferred L2 and L4 stages: sun shadows and interior shadow-light admission
  (`findings/sun-shadows-retail-facts.md`), exterior fog and haze, sky, sun and ambient over the day, the HDR and
  image-space chain, water displacement and reflections.

## Avoiding collisions

1. **Claim per class.** Run `./sr claim --class <ClassName> --skip-conflicts` for the classes you start. Each class belongs
   to one workstream (the tables below); do not claim another workstream's class without a comment on its task issue.
   A claim lapses after 24 hours without activity and anyone may take it over, so keep a PR or comment moving.
2. **General rounds skip claimed classes.** `./sr next`, `claim --skip-conflicts` and the project's own queue read the same
   claim issues, so a claimed function is not offered to anyone else. Claims are advisory, not locks; staying inside
   your own classes is what avoids duplicated work.
3. **Existing open claims stay excluded.** The inventory reads every open claim issue and counts its functions as
   claimed, not available. This includes the 300-function claim #1180. Take a class that overlaps one only by
   asking in that issue.
4. **One PR per round**, 50 to 200 functions, touching only `reconstruction/**` and `docs/cookbook-notes/**`
   ([contributor-card.md](../contributor-card.md)). Send lesson notes with it.
5. **Adjacent classes** are open to anyone through the normal claim route; they are not part of this milestone's count.

## Progress

Generated by `python3 tools/render_inventory.py --fetch-claims --update-doc docs/milestones/rendering.md`. The numbers are
read from the repository's data, never typed in: refresh the block, do not edit it.

<!-- inventory:start -->

Build `sse-steam-1-7-104`. The committed ready list holds 5000 of 17734 ready functions and is filtered against `data/progress.json`; functions under 60 open claim issues are counted as claimed.

| Workstream | Known | Matched | Matched % | Claimed | Ready | Waiting | Unlisted | Open bytes |
|---|---:|---:|---:|---:|---:|---:|---:|---:|
| A: Foundation | 402 | 147 | 36.6% | 14 | 12 | 6 | 223 | 63392 |
| B: Shaders and materials | 445 | 222 | 49.9% | 20 | 3 | 3 | 197 | 64878 |
| C: Batching, passes, camera, culling | 327 | 83 | 25.4% | 7 | 12 | 2 | 223 | 80531 |
| D: Shadows, image space, sky, water system | 828 | 557 | 67.3% | 20 | 4 | 2 | 245 | 124404 |
| **Total A-D** | 2002 | 1009 | 50.4% | 61 | 31 | 13 | 888 | 333205 |
| Adjacent, not assigned | 952 | 373 | 39.2% | 91 | 22 | 2 | 464 | 149140 |

Known = functions with a public name in the CrashLogger tables or `data/progress.json` (a lower bound). Ready = every callee matched and the function is in the committed list. Waiting = proven blocked (a give-up record, or under 16 bytes and absent from the complete part of the list). Unlisted = not matched, not claimed, not in the capped list: ready or waiting, unknown here. Open bytes = the sizes of the Ready, Waiting and Unlisted functions together.

### Workstream A: Foundation

Scope: BSGraphics state, render targets, buffers, textures and resources, render geometry, lights.

| Group | Known | Matched | Claimed | Ready | Waiting | Unlisted | Main blocker | Unit area |
|---|---:|---:|---:|---:|---:|---:|---|---|
| A1 BSGraphics renderer and state | 57 | 0 | 4 | 8 | 4 | 41 | ready list capped; readiness unknown (41) | - |
| A2 Render targets, buffers and depth-stencil | 10 | 1 | 1 | 2 | 0 | 6 | ready list capped; readiness unknown (6) | unmapped |
| A3 Shader manager, shader resources and textures | 64 | 39 | 1 | 2 | 2 | 20 | ready list capped; readiness unknown (20) | bsshader |
| A4 Lights | 78 | 29 | 7 | 0 | 0 | 42 | ready list capped; readiness unknown (42) | gamebryo |
| A5 Render geometry (shapes, skin instances) | 193 | 78 | 1 | 0 | 0 | 114 | ready list capped; readiness unknown (114) | gamebryo |

<details><summary>Classes of workstream A with unmatched functions</summary>

| Class | Group | Known | Matched | Claimed | Ready | Waiting | Unlisted | Sibling names not placed |
|---|---|---:|---:|---:|---:|---:|---:|---:|
| BSGraphics::Renderer | A1 | 51 | 0 | 3 | 6 | 4 | 38 | 0 |
| BSGraphics::State | A1 | 3 | 0 | 0 | 0 | 0 | 3 | 0 |
| BSGraphics | A1 | 1 | 0 | 1 | 0 | 0 | 0 | 0 |
| BSGraphics::Utility | A1 | 1 | 0 | 0 | 1 | 0 | 0 | 0 |
| RendererShadowState | A1 | 1 | 0 | 0 | 1 | 0 | 0 | 0 |
| BSGraphics::RenderTargetManager | A2 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| BSShaderRenderTargets | A2 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| CreateIndexBuffer | A2 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| GetID3D11Resource | A2 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| GetImageSpaceRenderTarget_TAAMASK_SSRMASK_SWAP | A2 | 1 | 0 | 0 | 1 | 0 | 0 | 0 |
| PollOcclusionQuery | A2 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| RenderTargetManager | A2 | 1 | 0 | 1 | 0 | 0 | 0 | 0 |
| SetPSTextureFilterMode | A2 | 1 | 0 | 0 | 1 | 0 | 0 | 0 |
| UpdateOrAssignShadowCSTexture | A2 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| NiSourceTexture | A3 | 11 | 5 | 0 | 0 | 0 | 6 | 32 |
| NiTexture | A3 | 10 | 5 | 0 | 1 | 0 | 4 | 56 |
| BSScaleformExternalTexture | A3 | 5 | 0 | 0 | 0 | 1 | 4 | 0 |
| BSShaderManager | A3 | 5 | 0 | 1 | 1 | 0 | 3 | 0 |
| BSTextureDB__QueuedHandles__dtor | A3 | 2 | 0 | 0 | 0 | 1 | 1 | 0 |
| BSTextureDB__anonymous_namespace__NiTextureDBForwarded | A3 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| CreateSourceTexture | A3 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| BSLight | A4 | 20 | 5 | 0 | 0 | 0 | 15 | 105 |
| NiPointLight | A4 | 15 | 8 | 1 | 0 | 0 | 6 | 17 |
| NiLight | A4 | 9 | 5 | 0 | 0 | 0 | 4 | 19 |
| NiLightColorController | A4 | 8 | 0 | 0 | 0 | 0 | 8 | 0 |
| NiSpotLight | A4 | 8 | 1 | 4 | 0 | 0 | 3 | 0 |
| NiLightDimmerController | A4 | 7 | 4 | 1 | 0 | 0 | 2 | 12 |
| NiDirectionalLight | A4 | 6 | 4 | 0 | 0 | 0 | 2 | 13 |
| NiAmbientLight | A4 | 4 | 2 | 1 | 0 | 0 | 1 | 0 |
| CalculateActiveNonShadowCasterLights | A4 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| NiGeometry | A5 | 28 | 20 | 0 | 0 | 0 | 8 | 48 |
| BSGeometry | A5 | 25 | 13 | 0 | 0 | 0 | 12 | 52 |
| BSDynamicTriShape | A5 | 20 | 8 | 0 | 0 | 0 | 12 | 24 |
| NiSkinInstance | A5 | 18 | 10 | 0 | 0 | 0 | 8 | 31 |
| BSTriShape | A5 | 17 | 6 | 0 | 0 | 0 | 11 | 13 |
| NiSkinPartition | A5 | 14 | 3 | 0 | 0 | 0 | 11 | 0 |
| NiGeometryData | A5 | 13 | 7 | 0 | 0 | 0 | 6 | 84 |
| BSMeshLODTriShape | A5 | 11 | 1 | 0 | 0 | 0 | 10 | 0 |
| BSSubIndexTriShape | A5 | 11 | 3 | 0 | 0 | 0 | 8 | 21 |
| BSLODTriShape | A5 | 10 | 0 | 0 | 0 | 0 | 10 | 0 |
| BSMultiIndexTriShape | A5 | 8 | 4 | 0 | 0 | 0 | 4 | 23 |
| NiSkinData | A5 | 7 | 2 | 0 | 0 | 0 | 5 | 0 |
| NiAdditionalGeometryData | A5 | 6 | 0 | 1 | 0 | 0 | 5 | 0 |
| BSLODMultiIndexTriShape | A5 | 5 | 1 | 0 | 0 | 0 | 4 | 0 |

</details>

### Workstream B: Shaders and materials

Scope: shader classes, shader properties, materials, sky and water shaders.

| Group | Known | Matched | Claimed | Ready | Waiting | Unlisted | Main blocker | Unit area |
|---|---:|---:|---:|---:|---:|---:|---|---|
| B1 Shader classes (lighting, effect, grass, tree, blood, particle, utility) | 52 | 12 | 7 | 2 | 1 | 30 | ready list capped; readiness unknown (30) | bsshader |
| B2 Shader properties and their controllers | 190 | 91 | 4 | 1 | 1 | 93 | ready list capped; readiness unknown (93) | bsshader |
| B3 Shader materials and texture sets | 155 | 99 | 7 | 0 | 1 | 48 | ready list capped; readiness unknown (48) | bsshader |
| B4 Sky and water shaders, properties and materials | 48 | 20 | 2 | 0 | 0 | 26 | ready list capped; readiness unknown (26) | bsshader |

<details><summary>Classes of workstream B with unmatched functions</summary>

| Class | Group | Known | Matched | Claimed | Ready | Waiting | Unlisted | Sibling names not placed |
|---|---|---:|---:|---:|---:|---:|---:|---:|
| BSLightingShader | B1 | 10 | 4 | 0 | 0 | 0 | 6 | 70 |
| BSEffectShader | B1 | 7 | 1 | 2 | 0 | 0 | 4 | 26 |
| BSUtilityShader | B1 | 7 | 2 | 2 | 0 | 0 | 3 | 25 |
| BSGrassShader | B1 | 6 | 1 | 1 | 0 | 0 | 4 | 24 |
| BSDistantTreeShader | B1 | 5 | 1 | 1 | 0 | 0 | 3 | 34 |
| BSParticleShader | B1 | 5 | 1 | 0 | 0 | 0 | 4 | 0 |
| BSShader | B1 | 4 | 0 | 1 | 0 | 1 | 2 | 0 |
| BSComputeShader | B1 | 3 | 1 | 0 | 0 | 0 | 2 | 5 |
| BSBloodSplatterShader | B1 | 2 | 1 | 0 | 0 | 0 | 1 | 0 |
| BSParticleShaderMacros | B1 | 1 | 0 | 0 | 1 | 0 | 0 | 0 |
| ClearBSShaders | B1 | 1 | 0 | 0 | 1 | 0 | 0 | 0 |
| GetLightingShaderDefines | B1 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| BSEffectShaderProperty | B2 | 57 | 13 | 0 | 0 | 0 | 44 | 55 |
| BSLightingShaderProperty | B2 | 24 | 11 | 2 | 0 | 1 | 10 | 97 |
| BSShaderProperty | B2 | 17 | 11 | 0 | 0 | 0 | 6 | 83 |
| BSDistantTreeShaderProperty | B2 | 12 | 6 | 1 | 0 | 0 | 5 | 18 |
| BSBloodSplatterShaderProperty | B2 | 11 | 7 | 0 | 0 | 0 | 4 | 11 |
| BSEffectShaderPropertyColorController | B2 | 11 | 8 | 0 | 0 | 0 | 3 | 18 |
| BSEffectShaderPropertyFloatController | B2 | 11 | 7 | 0 | 0 | 0 | 4 | 18 |
| BSLightingShaderPropertyColorController | B2 | 11 | 8 | 0 | 0 | 0 | 3 | 18 |
| BSGrassShaderProperty | B2 | 10 | 5 | 0 | 0 | 0 | 5 | 23 |
| BSLightingShaderPropertyFloatController | B2 | 10 | 7 | 0 | 0 | 0 | 3 | 18 |
| BSLightingShaderPropertyUShortController | B2 | 10 | 8 | 0 | 0 | 0 | 2 | 18 |
| BSShaderPropertyLightData | B2 | 5 | 0 | 0 | 1 | 0 | 4 | 0 |
| OnLoadTextureSet | B2 | 1 | 0 | 1 | 0 | 0 | 0 | 0 |
| BSLightingShaderMaterialMultiLayerParallax | B3 | 13 | 8 | 2 | 0 | 0 | 3 | 9 |
| BSLightingShaderMaterialBase | B3 | 12 | 9 | 1 | 0 | 0 | 2 | 0 |
| BSLightingShaderMaterialEnvmap | B3 | 12 | 10 | 0 | 0 | 0 | 2 | 9 |
| BSLightingShaderMaterialEye | B3 | 11 | 9 | 0 | 0 | 0 | 2 | 8 |
| BSLightingShaderMaterialSnow | B3 | 11 | 10 | 0 | 0 | 0 | 1 | 0 |
| BSLightingShaderMaterialLandscape | B3 | 10 | 5 | 0 | 0 | 0 | 5 | 0 |
| BSLightingShaderMaterialFacegenTint | B3 | 9 | 7 | 0 | 0 | 0 | 2 | 3 |
| BSShaderMaterial | B3 | 9 | 7 | 1 | 0 | 0 | 1 | 12 |
| BSEffectShaderMaterial | B3 | 8 | 3 | 0 | 0 | 0 | 5 | 13 |
| BSLightingShaderMaterialFacegen | B3 | 8 | 2 | 1 | 0 | 0 | 5 | 0 |
| BSLightingShaderMaterialHairTint | B3 | 8 | 6 | 0 | 0 | 1 | 1 | 5 |
| BSLightingShaderMaterialLODLandscape | B3 | 8 | 5 | 0 | 0 | 0 | 3 | 10 |
| BSLightingShaderMaterialParallaxOcc | B3 | 8 | 3 | 0 | 0 | 0 | 5 | 14 |
| BSShaderTextureSet | B3 | 8 | 6 | 0 | 0 | 0 | 2 | 12 |
| BSLightingShaderMaterialParallax | B3 | 7 | 4 | 1 | 0 | 0 | 2 | 9 |
| BSTextureSet | B3 | 5 | 2 | 1 | 0 | 0 | 2 | 0 |
| BSLightingShaderMaterial | B3 | 4 | 2 | 0 | 0 | 0 | 2 | 0 |
| BSLightingShaderMaterialGlowmap | B3 | 4 | 1 | 0 | 0 | 0 | 3 | 0 |
| BSWaterShaderProperty | B4 | 14 | 8 | 1 | 0 | 0 | 5 | 24 |
| BSWaterShaderMaterial | B4 | 13 | 6 | 0 | 0 | 0 | 7 | 9 |
| BSSkyShaderProperty | B4 | 11 | 4 | 0 | 0 | 0 | 7 | 24 |
| BSWaterShader | B4 | 7 | 1 | 1 | 0 | 0 | 5 | 39 |
| BSSkyShader | B4 | 3 | 1 | 0 | 0 | 0 | 2 | 0 |

</details>

### Workstream C: Batching, passes, camera, culling

Scope: render passes, batch renderer, accumulators, camera, frustum, culling, portals.

| Group | Known | Matched | Claimed | Ready | Waiting | Unlisted | Main blocker | Unit area |
|---|---:|---:|---:|---:|---:|---:|---|---|
| C1 Render passes, batch renderer, accumulators | 122 | 33 | 4 | 6 | 0 | 79 | ready list capped; readiness unknown (79) | bsshader |
| C2 Camera, frustum, culling, occlusion and portals | 205 | 50 | 3 | 6 | 2 | 144 | ready list capped; readiness unknown (144) | gamebryo |

<details><summary>Classes of workstream C with unmatched functions</summary>

| Class | Group | Known | Matched | Claimed | Ready | Waiting | Unlisted | Sibling names not placed |
|---|---|---:|---:|---:|---:|---:|---:|---:|
| BSShaderAccumulator | C1 | 47 | 17 | 2 | 0 | 0 | 28 | 145 |
| BSBatchRenderer | C1 | 26 | 0 | 0 | 4 | 0 | 22 | 0 |
| NiAlphaAccumulator | C1 | 10 | 8 | 0 | 0 | 0 | 2 | 12 |
| BSShaderProperty::RenderPassArray | C1 | 7 | 3 | 0 | 0 | 0 | 4 | 0 |
| BSRenderPass | C1 | 6 | 0 | 2 | 1 | 0 | 3 | 0 |
| NiAccumulator | C1 | 5 | 4 | 0 | 1 | 0 | 0 | 0 |
| NiBackToFrontAccumulator | C1 | 5 | 1 | 0 | 0 | 0 | 4 | 0 |
| AccumulateNodeChildren | C1 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| AccumulateSceneGraphNode | C1 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| AppendRoomToAccumList | C1 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| BSAccumProcess | C1 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| BSBatchRenderer::GeometryGroup | C1 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| BSRenderPassCache | C1 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| CullJob_AccumulateAndFlush | C1 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| CullJob_SetupDeferredAppend | C1 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| DrainRenderPassDeferredFreeQueue | C1 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| FinishAccumulatingMode20_LodLandscapePass | C1 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| FinishAccumulatingMode25_VolumetricOrOcclusion | C1 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| FinishAccumulatingMode28_PrecipitationOcclusionMap | C1 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| FirstListAccumulationJob | C1 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| ListAccumulationJob | C1 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| RenderPassImmediately_Custom | C1 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| RenderPassImmediately_Standard | C1 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| BSCompoundFrustum | C2 | 29 | 2 | 0 | 0 | 1 | 26 | 0 |
| NiCamera | C2 | 28 | 6 | 1 | 1 | 1 | 19 | 36 |
| BSCullingProcess | C2 | 25 | 2 | 0 | 1 | 0 | 22 | 0 |
| BSOcclusionPlane | C2 | 17 | 7 | 0 | 0 | 0 | 10 | 30 |
| BSOcclusionBox | C2 | 15 | 7 | 0 | 0 | 0 | 8 | 19 |
| BSPortalGraph | C2 | 15 | 5 | 0 | 0 | 0 | 10 | 0 |
| BSParabolicCullingProcess | C2 | 12 | 1 | 0 | 1 | 0 | 10 | 0 |
| BSPortalGraphEntry | C2 | 12 | 4 | 0 | 2 | 0 | 6 | 19 |
| BSCubeMapCamera | C2 | 7 | 2 | 0 | 0 | 0 | 5 | 11 |
| BSGeometryListCullingProcess | C2 | 6 | 2 | 0 | 0 | 0 | 4 | 0 |
| BSOcclusionShape | C2 | 5 | 4 | 0 | 1 | 0 | 0 | 0 |
| BSPortalSharedNode | C2 | 5 | 1 | 0 | 0 | 0 | 4 | 0 |
| BSFrustumFOVController | C2 | 4 | 1 | 1 | 0 | 0 | 2 | 0 |
| BSPortal | C2 | 4 | 1 | 0 | 0 | 0 | 3 | 0 |
| HighActorCuller | C2 | 4 | 1 | 0 | 0 | 0 | 3 | 3 |
| NiCullingProcess | C2 | 4 | 1 | 0 | 0 | 0 | 3 | 0 |
| BSFadeNodeCuller | C2 | 3 | 2 | 0 | 0 | 0 | 1 | 3 |
| NiFrustumPlanes | C2 | 2 | 0 | 0 | 0 | 0 | 2 | 0 |
| SubmitCullResultsJob | C2 | 2 | 0 | 0 | 0 | 0 | 2 | 0 |
| NiFrustum | C2 | 1 | 0 | 1 | 0 | 0 | 0 | 0 |
| PointInFrustum | C2 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| PruneFrustumPlanes | C2 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| SetupCullingJobManager | C2 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| SetupCullingJobManager2 | C2 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |

</details>

### Workstream D: Shadows, image space, sky, water system

Scope: shadows, image space, sky, weather, fog, water.

| Group | Known | Matched | Claimed | Ready | Waiting | Unlisted | Main blocker | Unit area |
|---|---:|---:|---:|---:|---:|---:|---|---|
| D1 Shadow lights and shadow scene node | 109 | 25 | 9 | 0 | 0 | 75 | ready list capped; readiness unknown (75) | bsshader |
| D2 Image space: manager, effects and image-space shaders | 611 | 498 | 6 | 4 | 2 | 101 | ready list capped; readiness unknown (101) | bsshader |
| D3 Sky, sun, clouds, weather and fog | 69 | 18 | 4 | 0 | 0 | 47 | ready list capped; readiness unknown (47) | skyrim_shared |
| D4 Water system, displacement and reflections | 39 | 16 | 1 | 0 | 0 | 22 | ready list capped; readiness unknown (22) | skyrim_shared |

<details><summary>Classes of workstream D with unmatched functions</summary>

| Class | Group | Known | Matched | Claimed | Ready | Waiting | Unlisted | Sibling names not placed |
|---|---|---:|---:|---:|---:|---:|---:|---:|
| ShadowSceneNode | D1 | 43 | 1 | 6 | 0 | 0 | 36 | 120 |
| BSShadowLight | D1 | 18 | 10 | 0 | 0 | 0 | 8 | 55 |
| BSShadowDirectionalLight | D1 | 17 | 6 | 1 | 0 | 0 | 10 | 10 |
| BSShadowParabolicLight | D1 | 12 | 6 | 1 | 0 | 0 | 5 | 9 |
| BSShadowFrustumLight | D1 | 7 | 2 | 1 | 0 | 0 | 4 | 10 |
| BSTArray_ShadowmapDescriptor_ | D1 | 3 | 0 | 0 | 0 | 0 | 3 | 0 |
| BSShadowParabolicLight_RenderImpl | D1 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| CalculateActiveShadowCasterLights | D1 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| CalculateAndDrawShadowCasterLights | D1 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| ProcessAllQueuedLights | D1 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| RenderActiveShadowCasterLights | D1 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| RenderVolumetricLightingShadowMaps | D1 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| ResetCalculatedShadowCasterLights | D1 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| ShadowSceneNode_SetShadowCasterLightArrayEntry | D1 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| ShadowmapDescriptor | D1 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| BSImagespaceShader | D2 | 19 | 15 | 1 | 0 | 1 | 2 | 29 |
| TESImageSpaceModifier | D2 | 13 | 3 | 0 | 1 | 0 | 9 | 0 |
| ImageSpaceEffect | D2 | 7 | 1 | 0 | 0 | 0 | 6 | 0 |
| ImageSpaceEffectNoise | D2 | 7 | 0 | 0 | 0 | 0 | 7 | 0 |
| ImageSpaceModifierInstanceForm | D2 | 7 | 1 | 0 | 0 | 1 | 5 | 19 |
| BSImagespaceShaderCopyCustomViewport | D2 | 6 | 4 | 0 | 0 | 0 | 2 | 0 |
| BSImagespaceShaderWaterFlow | D2 | 6 | 4 | 0 | 0 | 0 | 2 | 0 |
| ImageSpaceEffectGetHit | D2 | 6 | 0 | 0 | 0 | 0 | 6 | 0 |
| TESImagespaceManager | D2 | 6 | 0 | 0 | 1 | 0 | 5 | 0 |
| BSImagespaceShaderISBlur | D2 | 5 | 4 | 0 | 0 | 0 | 1 | 0 |
| ImageSpaceEffectDepthOfField | D2 | 5 | 0 | 0 | 0 | 0 | 5 | 0 |
| ImageSpaceEffectFullScreenBlur | D2 | 5 | 1 | 0 | 0 | 0 | 4 | 0 |
| ImageSpaceEffectRefraction | D2 | 5 | 0 | 0 | 0 | 0 | 5 | 0 |
| ImageSpaceShaderParam | D2 | 5 | 0 | 1 | 0 | 0 | 4 | 0 |
| TESImageSpace | D2 | 5 | 1 | 1 | 0 | 0 | 3 | 0 |
| TESImageSpaceModifiableForm | D2 | 5 | 4 | 0 | 1 | 0 | 0 | 0 |
| BSImagespaceShaderFXAA | D2 | 4 | 3 | 0 | 0 | 0 | 1 | 2 |
| BSImagespaceShaderISLightingCompositeMenu | D2 | 4 | 3 | 1 | 0 | 0 | 0 | 0 |
| BSImagespaceShaderLensFlareVisibility | D2 | 4 | 3 | 0 | 0 | 0 | 1 | 4 |
| BSImagespaceShaderLensFlare | D2 | 3 | 2 | 0 | 0 | 0 | 1 | 0 |
| ImageSpaceEffectBlur | D2 | 3 | 0 | 0 | 0 | 0 | 3 | 0 |
| ImageSpaceEffectHDR | D2 | 3 | 0 | 0 | 0 | 0 | 3 | 0 |
| ImageSpaceEffectMap | D2 | 3 | 0 | 0 | 0 | 0 | 3 | 0 |
| ImageSpaceEffectVolumetricLighting | D2 | 3 | 0 | 0 | 0 | 0 | 3 | 0 |
| ImageSpaceEffectWaterDisplacement | D2 | 3 | 0 | 0 | 0 | 0 | 3 | 0 |
| ImageSpaceEffectWorldMap | D2 | 3 | 0 | 0 | 0 | 0 | 3 | 0 |
| ImageSpaceManager | D2 | 3 | 0 | 1 | 0 | 0 | 2 | 0 |
| ImageSpaceModifierInstance | D2 | 3 | 1 | 0 | 0 | 0 | 2 | 0 |
| ImageSpaceModifierInstanceDOF | D2 | 3 | 1 | 1 | 0 | 0 | 1 | 0 |
| ImageSpaceModifierInstanceTemp | D2 | 3 | 2 | 0 | 0 | 0 | 1 | 0 |
| ImageSpaceEffectOption | D2 | 2 | 0 | 0 | 0 | 0 | 2 | 0 |
| ImageSpaceEffectParam | D2 | 2 | 1 | 0 | 0 | 0 | 1 | 0 |
| ImageSpaceEffectRadialBlur | D2 | 2 | 0 | 0 | 0 | 0 | 2 | 0 |
| ImageSpaceModifierInstanceRB | D2 | 2 | 1 | 0 | 0 | 0 | 1 | 0 |
| GetVLTemporalAccumulationFactor | D2 | 1 | 0 | 0 | 1 | 0 | 0 | 0 |
| UpdateVolumetricLightingRenderData | D2 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| VolumetricLightingDescriptor | D2 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| Sky | D3 | 31 | 7 | 3 | 0 | 0 | 21 | 145 |
| BSFogProperty | D3 | 5 | 3 | 0 | 0 | 0 | 2 | 0 |
| Precipitation | D3 | 5 | 0 | 0 | 0 | 0 | 5 | 0 |
| Sun | D3 | 5 | 0 | 1 | 0 | 0 | 4 | 0 |
| Atmosphere | D3 | 4 | 1 | 0 | 0 | 0 | 3 | 0 |
| TESWeather | D3 | 4 | 0 | 0 | 0 | 0 | 4 | 0 |
| Clouds | D3 | 3 | 0 | 0 | 0 | 0 | 3 | 0 |
| Moon | D3 | 2 | 1 | 0 | 0 | 0 | 1 | 0 |
| Stars | D3 | 2 | 0 | 0 | 0 | 0 | 2 | 0 |
| Precipitation::OcclusionMapData | D3 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| SkyObject | D3 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| TESWaterForm | D4 | 15 | 9 | 0 | 0 | 0 | 6 | 134 |
| TESWaterSystem | D4 | 15 | 7 | 1 | 0 | 0 | 7 | 0 |
| TESWaterDisplacement | D4 | 4 | 0 | 0 | 0 | 0 | 4 | 0 |
| TESWaterReflections | D4 | 3 | 0 | 0 | 0 | 0 | 3 | 0 |
| TESWaterNormals | D4 | 2 | 0 | 0 | 0 | 0 | 2 | 0 |

</details>

### Adjacent: Adjacent

Scope: listed for context, owned by the general rounds.

| Group | Known | Matched | Claimed | Ready | Waiting | Unlisted | Main blocker | Unit area |
|---|---:|---:|---:|---:|---:|---:|---|---|
| X1 Particle systems and emitters | 531 | 200 | 66 | 2 | 0 | 263 | ready list capped; readiness unknown (263) | gamebryo |
| X2 Scaleform UI renderer | 49 | 0 | 0 | 8 | 0 | 41 | ready list capped; readiness unknown (41) | - |
| X3 Game cameras and camera states | 151 | 62 | 18 | 7 | 1 | 63 | ready list capped; readiness unknown (63) | skyrim |
| X4 Render-related forms, decals, effects, grass and LOD | 221 | 111 | 7 | 5 | 1 | 97 | ready list capped; readiness unknown (97) | skyrim_shared |

<details><summary>Classes of adjacent with unmatched functions</summary>

| Class | Group | Known | Matched | Claimed | Ready | Waiting | Unlisted | Sibling names not placed |
|---|---|---:|---:|---:|---:|---:|---:|---:|
| NiPSysEmitterCtlr | X1 | 22 | 13 | 4 | 0 | 0 | 5 | 30 |
| NiParticleSystem | X1 | 19 | 7 | 1 | 0 | 0 | 11 | 0 |
| BSMasterParticleSystem | X1 | 16 | 7 | 0 | 0 | 0 | 9 | 0 |
| NiPSysBombModifier | X1 | 15 | 8 | 3 | 0 | 0 | 4 | 0 |
| NiPSysGravityModifier | X1 | 13 | 7 | 2 | 0 | 0 | 4 | 0 |
| NiPSysMeshEmitter | X1 | 13 | 3 | 1 | 0 | 0 | 9 | 33 |
| NiParticles | X1 | 13 | 6 | 1 | 0 | 0 | 6 | 24 |
| NiPSysData | X1 | 12 | 0 | 1 | 0 | 0 | 11 | 22 |
| NiPSysModifier | X1 | 11 | 8 | 3 | 0 | 0 | 0 | 14 |
| NiPSysModifierCtlr | X1 | 11 | 8 | 1 | 0 | 0 | 2 | 0 |
| BSPSysHavokUpdateModifier | X1 | 10 | 4 | 0 | 0 | 0 | 6 | 0 |
| NiPSysBoundUpdateModifier | X1 | 10 | 1 | 3 | 0 | 0 | 6 | 16 |
| BSPSysMultiTargetEmitterCtlr | X1 | 9 | 1 | 0 | 0 | 0 | 8 | 0 |
| BSParticleSystemManager | X1 | 9 | 0 | 0 | 0 | 0 | 9 | 0 |
| NiPSysMeshUpdateModifier | X1 | 9 | 1 | 5 | 0 | 0 | 3 | 0 |
| NiPSysSpawnModifier | X1 | 9 | 2 | 4 | 0 | 0 | 3 | 0 |
| BSPSysInheritVelocityModifier | X1 | 8 | 2 | 0 | 0 | 0 | 6 | 0 |
| BSPSysRecycleBoundModifier | X1 | 8 | 0 | 2 | 0 | 0 | 6 | 0 |
| NiPSysCollider | X1 | 8 | 0 | 2 | 1 | 0 | 5 | 0 |
| BSPSysArrayEmitter | X1 | 7 | 3 | 0 | 0 | 0 | 4 | 23 |
| NiPSysAgeDeathModifier | X1 | 7 | 2 | 1 | 0 | 0 | 4 | 0 |
| NiPSysAirFieldModifier | X1 | 7 | 2 | 0 | 0 | 0 | 5 | 0 |
| NiPSysBoxEmitter | X1 | 7 | 1 | 3 | 0 | 0 | 3 | 0 |
| NiPSysColorModifier | X1 | 7 | 4 | 1 | 0 | 0 | 2 | 0 |
| NiPSysDragModifier | X1 | 7 | 2 | 2 | 0 | 0 | 3 | 0 |
| NiPSysFieldModifier | X1 | 7 | 2 | 3 | 0 | 0 | 2 | 0 |
| NiPSysGrowFadeModifier | X1 | 7 | 1 | 1 | 0 | 0 | 5 | 0 |
| NiPSysModifierBoolCtlr | X1 | 7 | 4 | 0 | 0 | 0 | 3 | 0 |
| NiPSysModifierFloatCtlr | X1 | 7 | 3 | 1 | 0 | 0 | 3 | 0 |
| NiPSysPlanarCollider | X1 | 7 | 0 | 0 | 0 | 0 | 7 | 0 |
| NiPSysRotationModifier | X1 | 7 | 1 | 3 | 0 | 0 | 3 | 0 |
| NiPSysSphereEmitter | X1 | 7 | 2 | 2 | 0 | 0 | 3 | 0 |
| NiPSysVolumeEmitter | X1 | 7 | 4 | 2 | 0 | 0 | 1 | 0 |
| BSPSysLODModifier | X1 | 6 | 2 | 0 | 0 | 0 | 4 | 0 |
| BSPSysStripUpdateModifier | X1 | 6 | 3 | 0 | 0 | 0 | 3 | 0 |
| BSPSysSubTexModifier | X1 | 6 | 1 | 1 | 0 | 0 | 4 | 0 |
| NiPSysCylinderEmitter | X1 | 6 | 1 | 2 | 0 | 0 | 3 | 0 |
| NiPSysDragFieldModifier | X1 | 6 | 1 | 2 | 0 | 0 | 3 | 0 |
| NiPSysSphericalCollider | X1 | 6 | 0 | 0 | 0 | 0 | 6 | 0 |
| NiPSysVortexFieldModifier | X1 | 6 | 3 | 1 | 0 | 0 | 2 | 0 |
| NiParticleMeshesData | X1 | 6 | 0 | 0 | 0 | 0 | 6 | 0 |
| BSPSysScaleModifier | X1 | 5 | 1 | 0 | 0 | 0 | 4 | 0 |
| BSPSysSimpleColorModifier | X1 | 5 | 0 | 0 | 0 | 0 | 5 | 0 |
| NiPSysEmitter | X1 | 5 | 1 | 1 | 0 | 0 | 3 | 0 |
| NiPSysGravityFieldModifier | X1 | 5 | 2 | 1 | 0 | 0 | 2 | 0 |
| NiPSysModifierActiveCtlr | X1 | 5 | 3 | 0 | 0 | 0 | 2 | 14 |
| NiPSysUpdateCtlr | X1 | 5 | 1 | 0 | 0 | 0 | 4 | 0 |
| NiParticlesData | X1 | 5 | 0 | 0 | 0 | 0 | 5 | 0 |
| BGSShaderParticleGeometryData | X1 | 4 | 1 | 1 | 0 | 0 | 2 | 0 |
| BSParticleShaderGeometry | X1 | 4 | 2 | 0 | 0 | 0 | 2 | 3 |
| BSParticleShaderGeometryEmitter | X1 | 4 | 2 | 0 | 0 | 0 | 2 | 4 |
| BSStripParticleSystem | X1 | 4 | 1 | 1 | 0 | 0 | 2 | 0 |
| NiPSysEmitterCtlrData | X1 | 4 | 1 | 2 | 0 | 0 | 1 | 0 |
| NiPSysEmitterDeclinationCtlr | X1 | 4 | 3 | 0 | 0 | 0 | 1 | 14 |
| NiPSysEmitterDeclinationVarCtlr | X1 | 4 | 3 | 0 | 0 | 0 | 1 | 14 |
| NiPSysEmitterInitialRadiusCtlr | X1 | 4 | 3 | 0 | 0 | 0 | 1 | 14 |
| NiPSysEmitterLifeSpanCtlr | X1 | 4 | 3 | 0 | 0 | 0 | 1 | 14 |
| NiPSysEmitterPlanarAngleCtlr | X1 | 4 | 3 | 0 | 0 | 0 | 1 | 14 |
| NiPSysEmitterPlanarAngleVarCtlr | X1 | 4 | 3 | 0 | 0 | 0 | 1 | 14 |
| NiPSysEmitterSpeedCtlr | X1 | 4 | 3 | 0 | 0 | 0 | 1 | 14 |
| NiPSysFieldAttenuationCtlr | X1 | 4 | 3 | 0 | 0 | 0 | 1 | 14 |
| NiPSysFieldMagnitudeCtlr | X1 | 4 | 3 | 0 | 0 | 0 | 1 | 14 |
| NiPSysFieldMaxDistanceCtlr | X1 | 4 | 3 | 0 | 0 | 0 | 1 | 14 |
| NiPSysGravityStrengthCtlr | X1 | 4 | 3 | 0 | 0 | 0 | 1 | 14 |
| NiPSysInitialRotAngleCtlr | X1 | 4 | 3 | 0 | 0 | 0 | 1 | 14 |
| NiPSysInitialRotAngleVarCtlr | X1 | 4 | 3 | 0 | 0 | 0 | 1 | 14 |
| NiPSysInitialRotSpeedCtlr | X1 | 4 | 3 | 0 | 0 | 0 | 1 | 14 |
| NiPSysInitialRotSpeedVarCtlr | X1 | 4 | 3 | 0 | 0 | 0 | 1 | 14 |
| NiPSysResetOnLoopCtlr | X1 | 4 | 1 | 1 | 0 | 0 | 2 | 0 |
| NiParticleMeshes | X1 | 4 | 0 | 0 | 0 | 0 | 4 | 0 |
| BSParticleShaderCollisionEmitter | X1 | 3 | 1 | 1 | 0 | 0 | 1 | 4 |
| BSParticleShaderRayEmitter | X1 | 3 | 2 | 0 | 0 | 0 | 1 | 4 |
| NiPSysAirFieldAirFrictionCtlr | X1 | 3 | 2 | 0 | 0 | 0 | 1 | 14 |
| NiPSysAirFieldInheritVelocityCtlr | X1 | 3 | 2 | 0 | 0 | 0 | 1 | 14 |
| NiPSysAirFieldSpreadCtlr | X1 | 3 | 2 | 0 | 0 | 0 | 1 | 14 |
| NiPSysColliderManager | X1 | 3 | 0 | 0 | 0 | 0 | 3 | 0 |
| NiPSysRadialFieldModifier | X1 | 3 | 2 | 0 | 0 | 0 | 1 | 0 |
| NiPSysTurbulenceFieldModifier | X1 | 3 | 1 | 0 | 0 | 0 | 2 | 0 |
| BSParticleShaderEmitter | X1 | 2 | 1 | 0 | 0 | 0 | 1 | 0 |
| BSParticleShaderObjectEmitter | X1 | 2 | 1 | 0 | 0 | 0 | 1 | 2 |
| NiPSysPositionModifier | X1 | 2 | 1 | 0 | 0 | 0 | 1 | 0 |
| NiParticleInfo | X1 | 2 | 0 | 0 | 1 | 0 | 1 | 0 |
| NiParticleSDM | X1 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| Scaleform::Render::Text::DocView | X2 | 15 | 0 | 0 | 0 | 0 | 15 | 0 |
| Scaleform::Render::Text | X2 | 6 | 0 | 0 | 0 | 0 | 6 | 0 |
| Scaleform::Render::Text::ParagraphFormat | X2 | 4 | 0 | 0 | 1 | 0 | 3 | 0 |
| Scaleform::Render::Text::Highlighter | X2 | 3 | 0 | 0 | 1 | 0 | 2 | 0 |
| Scaleform::Render::Text::HighlighterRangeIterator | X2 | 2 | 0 | 0 | 1 | 0 | 1 | 0 |
| Scaleform::Render::Text::Paragraph | X2 | 2 | 0 | 0 | 1 | 0 | 1 | 0 |
| Scaleform::Render::Text::TextFormat | X2 | 2 | 0 | 0 | 0 | 0 | 2 | 0 |
| Scaleform::Render::Cxform | X2 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| Scaleform::Render::D3D1x::ShaderManager | X2 | 1 | 0 | 0 | 1 | 0 | 0 | 0 |
| Scaleform::Render::GlyphQueue | X2 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| Scaleform::Render::GradientData | X2 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| Scaleform::Render::Matrix2x4 | X2 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| Scaleform::Render::RBGenericImpl::DepthStencilBuffer | X2 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| Scaleform::Render::RBGenericImpl::RenderBufferManager | X2 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| Scaleform::Render::ScreenToWorld | X2 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| Scaleform::Render::Text::HighlighterPosIterator | X2 | 1 | 0 | 0 | 1 | 0 | 0 | 0 |
| Scaleform::Render::Text::LineBuffer | X2 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| Scaleform::Render::Text::LineBuffer::Line | X2 | 1 | 0 | 0 | 1 | 0 | 0 | 0 |
| Scaleform::Render::Text::Paragraph::CharactersIterator | X2 | 1 | 0 | 0 | 1 | 0 | 0 | 0 |
| Scaleform::Render::Text::Paragraph::TextBuffer | X2 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| Scaleform::Render::Text::SGMLParser | X2 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| Scaleform::Render::Text::StyledText | X2 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| PlayerCamera | X3 | 53 | 28 | 3 | 0 | 1 | 21 | 144 |
| DragonCameraState | X3 | 13 | 5 | 1 | 1 | 0 | 6 | 0 |
| HorseCameraState | X3 | 13 | 5 | 0 | 1 | 0 | 7 | 6 |
| FreeCameraState | X3 | 10 | 4 | 0 | 0 | 0 | 6 | 0 |
| LocalMapCamera | X3 | 10 | 4 | 0 | 1 | 0 | 5 | 0 |
| FurnitureCameraState | X3 | 8 | 2 | 0 | 0 | 0 | 6 | 0 |
| VATSCameraState | X3 | 8 | 1 | 4 | 1 | 0 | 2 | 0 |
| TESCamera | X3 | 7 | 4 | 2 | 0 | 0 | 1 | 9 |
| TweenMenuCameraState | X3 | 7 | 2 | 3 | 0 | 0 | 2 | 0 |
| PlayerCameraTransitionState | X3 | 6 | 1 | 3 | 0 | 0 | 2 | 0 |
| BleedoutCameraState | X3 | 5 | 1 | 1 | 1 | 0 | 2 | 0 |
| MapCamera | X3 | 5 | 0 | 1 | 2 | 0 | 2 | 0 |
| RaceSexCamera | X3 | 2 | 1 | 0 | 0 | 0 | 1 | 0 |
| TESGrass | X4 | 28 | 26 | 0 | 1 | 0 | 1 | 22 |
| ReferenceEffect | X4 | 17 | 6 | 2 | 1 | 0 | 8 | 0 |
| BGSLightingTemplate | X4 | 16 | 14 | 0 | 0 | 0 | 2 | 67 |
| ShaderReferenceEffect | X4 | 16 | 6 | 0 | 0 | 0 | 10 | 0 |
| BSTerrainEffect | X4 | 15 | 4 | 1 | 0 | 1 | 9 | 0 |
| TESEffectShader | X4 | 12 | 7 | 0 | 0 | 0 | 5 | 83 |
| BGSTerrainManager | X4 | 11 | 9 | 0 | 1 | 0 | 1 | 0 |
| BSTempEffectSimpleDecal | X4 | 11 | 6 | 0 | 0 | 0 | 5 | 36 |
| TESLandTexture | X4 | 11 | 5 | 1 | 0 | 0 | 5 | 0 |
| GrassManager | X4 | 10 | 0 | 1 | 1 | 0 | 8 | 0 |
| BGSTextureSet | X4 | 9 | 1 | 0 | 1 | 0 | 7 | 0 |
| BSTempEffectGeometryDecal | X4 | 9 | 4 | 0 | 0 | 0 | 5 | 0 |
| BGSMaterialType | X4 | 8 | 1 | 0 | 0 | 0 | 7 | 0 |
| BSTempEffectParticle | X4 | 8 | 2 | 0 | 0 | 0 | 6 | 0 |
| BGSMaterialObject | X4 | 7 | 2 | 1 | 0 | 0 | 4 | 0 |
| TESTexture | X4 | 7 | 5 | 1 | 0 | 0 | 1 | 0 |
| BGSReferenceEffect | X4 | 6 | 3 | 0 | 0 | 0 | 3 | 0 |
| BGSDecalNode | X4 | 5 | 3 | 0 | 0 | 0 | 2 | 20 |
| BSDecalPlacementVectorExtraData | X4 | 5 | 0 | 0 | 0 | 0 | 5 | 0 |
| BGSTerrainBlock | X4 | 4 | 3 | 0 | 0 | 0 | 1 | 0 |
| BGSVolumetricLighting | X4 | 3 | 1 | 0 | 0 | 0 | 2 | 0 |

</details>

<details><summary>Entry points</summary>

**Workstream A entry points** (names are CrashLogger-derived, CRASHLOGGER_PDB(59818@2026.10.24))

| RVA | Name | Size | State | Callers unlocked |
|---|---|---:|---|---:|
| `0x14ec000` | BSShaderManager::SetShadowSceneNode | 15 | ready | 3 |
| `0x101d730` | RendererShadowState::GetViewDepthRange | 16 | ready | 3 |
| `0x1010920` | BSGraphics::Renderer::GetScaleformRendererParameters | 16 | ready | 2 |
| `0x1008b10` | Renderer::SetWindowPosition | 20 | ready | 1 |
| `0x10193a0` | BSGraphics::Utility::CopyNiColorAToFloat | 23 | ready | 4 |
| `0xec1e40` | NiTexture::QLoadLevel | 28 | ready | 3 |
| `0x101e2d0` | SetPSTextureFilterMode | 29 | ready | 2 |
| `0x100c6f0` | BSGraphics::Renderer::UnmapDynamicBuffer | 34 | ready | 1 |
| `0x1010290` | BSGraphics::Renderer_SetPixelShader | 36 | ready | 2 |
| `0x100fee0` | BSGraphics::Renderer_SetShader | 41 | ready | 2 |
| `0x153c900` | GetImageSpaceRenderTarget_TAAMASK_SSRMASK_SWAP | 46 | ready | 11 |
| `0x1010620` | Renderer::SetScissorRect | 63 | ready | 2 |
| `0x100c6d0` | BSGraphics::Renderer::MapDynamicShapeBuffer | 21 | unlisted |  |
| `0xf7e7d0` | NiLightColorController::ctor | 39 | unlisted |  |
| `0xf1b540` | BSLODTriShape::ctor_default | 40 | unlisted |  |

**Workstream B entry points** (names are CrashLogger-derived, CRASHLOGGER_PDB(59818@2026.10.24))

| RVA | Name | Size | State | Callers unlocked |
|---|---|---:|---|---:|
| `0x1569460` | BSShaderPropertyLightData::PushLightListFence | 8 | ready | 3 |
| `0x1594070` | BSParticleShaderMacros::GetVertexShaderID | 13 | ready | 1 |
| `0x15608d0` | ClearBSShaders | 55 | ready | 11 |
| `0x151d650` | BSGrassShaderProperty::CopyMembers | 56 | unlisted |  |
| `0x118c2c0` | BSEffectShaderProperty::AsLinesGeom | 59 | unlisted |  |
| `0x118bb10` | BSEffectShaderProperty::QShader | 61 | unlisted |  |
| `0x118d5c0` | BSEffectShaderProperty::ForEachTexture | 61 | unlisted |  |
| `0x1526f70` | BSLightingShaderMaterialFacegenTint::ComputeCRC32 | 67 | unlisted |  |
| `0x14e8080` | BSShaderProperty::SetPreRegisteredMaterial | 71 | unlisted |  |
| `0x1578930` | BSEffectShader::SetAlphaTestRef | 72 | unlisted |  |
| `0x1522440` | BSGrassShader::ctor | 76 | unlisted |  |
| `0x154d080` | BSWaterShader::ctor | 76 | unlisted |  |
| `0x1556690` | BSEffectShader::ctor | 76 | unlisted |  |
| `0x1558ed0` | BSDistantTreeShader::ctor | 76 | unlisted |  |
| `0x1566460` | BSUtilityShader::ctor | 76 | unlisted |  |

**Workstream C entry points** (names are CrashLogger-derived, CRASHLOGGER_PDB(59818@2026.10.24))

| RVA | Name | Size | State | Callers unlocked |
|---|---|---:|---|---:|
| `0x15606d0` | BSBatchRenderer::ClearAlphaGeometryGroups | 11 | ready | 2 |
| `0x154d070` | BSRenderPass::GetSceneLights_1412f5d40 | 14 | ready | 3 |
| `0x1515360` | NiCamera::sub_1412C1690 | 16 | ready | 1 |
| `0xfeea50` | BSCullingProcess::TestBaseVisibility | 20 | ready | 1 |
| `0x15606b0` | BSBatchRenderer::InitSDM | 23 | ready | 2 |
| `0x15606f0` | BSBatchRenderer::SortAlphaGeometryGroups | 33 | ready | 1 |
| `0xf1eda0` | NiAccumulator::ctor | 41 | ready | 4 |
| `0x1560940` | BSBatchRenderer::HasActivePassIndexInRange | 47 | ready | 1 |
| `0xfdb610` | BSOcclusionShape::CopyTransformTo | 51 | ready | 3 |
| `0x8d9500` | BSPortalGraphEntry::SetRoomRoot | 53 | ready | 5 |
| `0xfd9500` | BSPortalGraphEntry::SetRoomRoot | 53 | ready | 4 |
| `0x1586d80` | BSParabolicCullingProcess::SetBackHemisphereAccumulator | 59 | ready | 2 |
| `0xef76f0` | NiCamera::ComputeFrustumPlanes | 16 | unlisted |  |
| `0x15617d0` | BSBatchRenderer::AppendPassToAlphaGroupSorted | 19 | unlisted |  |
| `0x1561610` | BSBatchRenderer::AppendPassToGeometryGroup | 20 | unlisted |  |

**Workstream D entry points** (names are CrashLogger-derived, CRASHLOGGER_PDB(59818@2026.10.24))

| RVA | Name | Size | State | Callers unlocked |
|---|---|---:|---|---:|
| `0x1e8630` | TESImageSpaceModifiableForm::ctor | 22 | ready | 6 |
| `0x1530d70` | GetVLTemporalAccumulationFactor | 22 | ready | 1 |
| `0x2a8440` | TESImageSpaceModifier::MakeDefaultGetHit | 25 | ready | 1 |
| `0x14eedf0` | TESImagespaceManager::IsScreenshotSaved | 25 | ready | 1 |
| `0x52af40` | TESWaterSystem::ResetWaterDisplacementSimulation | 22 | unlisted |  |
| `0x1585b60` | ImageSpaceEffectNoise::UpdateParams | 25 | unlisted |  |
| `0x1516b90` | ShadowSceneNode::CollectLightingShaderGeometry | 31 | unlisted |  |
| `0x152b1b0` | ImageSpaceShaderParam::sub_1412D6730 | 32 | unlisted |  |
| `0x40e0c0` | Sky::SetWeather | 39 | unlisted |  |
| `0x150e300` | ShadowSceneNode::TryQueueLightRemove | 41 | unlisted |  |
| `0x1586480` | ImageSpaceEffectNoise::Bias | 48 | unlisted |  |
| `0x15832a0` | ImageSpaceEffectGetHit::dtor_deleting | 52 | unlisted |  |
| `0x150ba00` | BSImagespaceShaderCopyCustomViewport::Func6_1412B8530 | 54 | unlisted |  |
| `0x14a1250` | ShadowSceneNode::RemoveLight_1 | 59 | unlisted |  |
| `0x41ad30` | Sun::GetSunOcclusionPercent | 64 | unlisted |  |

</details>

<!-- inventory:end -->
