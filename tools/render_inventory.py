#!/usr/bin/env python3
"""Inventory of the rendering subsystem, derived from the repository's public data only.

    python3 tools/render_inventory.py                     # markdown tables on stdout
    python3 tools/render_inventory.py --json OUT.json     # the full structure
    python3 tools/render_inventory.py --fetch-claims      # also exclude functions under open claim issues
    python3 tools/render_inventory.py --claims FILE.json  # the same, from a saved list of claims
    python3 tools/render_inventory.py --update-doc docs/milestones/rendering.md

Inputs: reconstruction/generated/crashlogger_pdb/{names,boundaries}, data/symbol-names.json,
data/progress.json, data/ready-queue.json, data/giveups and reconstruction/INDEX.md. Only RVAs, names,
sizes and counts are read or written. Nothing here is evidence of a match.

Every number is a count of what those files already say, so it is a lower bound on the real subsystem: a
function with no public name is invisible to this script, and the committed ready list is capped, so a
function missing from it is "not listed", not "proven blocked". The report states both limits.
"""
import argparse
import collections
import glob
import json
from pathlib import Path
import re
import sys

ROOT = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(ROOT / 'tools')]

PDB_DIR = 'reconstruction/generated/crashlogger_pdb'
BUCKETS = (16, 64, 256, 1024)
ENTRY_POINTS = 15
BLOCK_START, BLOCK_END = '<!-- inventory:start -->', '<!-- inventory:end -->'

WORKSTREAMS = {
    'A': 'Foundation',
    'B': 'Shaders and materials',
    'C': 'Batching, passes, camera, culling',
    'D': 'Shadows, image space, sky, water system',
    '-': 'Adjacent',
}
WORKSTREAM_SCOPE = {
    'A': 'BSGraphics state, render targets, buffers, textures and resources, render geometry, lights',
    'B': 'shader classes, shader properties, materials, sky and water shaders',
    'C': 'render passes, batch renderer, accumulators, camera, frustum, culling, portals',
    'D': 'shadows, image space, sky, weather, fog, water',
    '-': 'listed for context, owned by the general rounds',
}

# (id, workstream, title, rules). A rule is ('class', regex) tested on the class key or ('name', regex) tested
# on the whole cleaned name. The first group with a matching rule wins, so a narrow group sits above a broad one.
GROUPS = [
    ('C1', 'C', 'Render passes, batch renderer, accumulators', [
        ('class', r'^BSShaderProperty::RenderPassArray$'),
        ('class', r'^(BSBatchRenderer(::.*)?|BSRenderPass|BSRenderPassCache|BSShaderAccumulator|NiAccumulator|'
                  r'NiAlphaAccumulator|NiBackToFrontAccumulator|BSAccumProcess)$'),
        ('name', r'^(RenderPassImmediately_|DrainRenderPassDeferredFreeQueue|AccumulateSceneGraphNode|'
                 r'AccumulateNodeChildren|FinishAccumulatingMode|FirstListAccumulationJob|ListAccumulationJob|'
                 r'CullJob_|AppendRoomToAccumList)')]),
    ('A1', 'A', 'BSGraphics renderer and state', [
        ('class', r'^(BSGraphics|BSGraphics::Renderer|BSGraphics::State|BSGraphics::Utility|RendererShadowState|'
                  r'RendererData)$')]),
    ('A2', 'A', 'Render targets, buffers and depth-stencil', [
        ('class', r'^(BSGraphics::RenderTargetManager|RenderTargetManager|BSShaderRenderTargets)$'),
        ('name', r'^(CreateIndexBuffer|GetID3D11Resource|GetDepthStencilTarget_|GetImageSpaceRenderTarget|'
                 r'SetPSTextureFilterMode|UpdateOrAssignShadowCSTexture|PollOcclusionQuery)')]),
    ('A3', 'A', 'Shader manager, shader resources and textures', [
        ('class', r'^(BSShaderManager|BSShaderResourceManager|NiTexture|NiSourceTexture|BSScaleformExternalTexture|'
                  r'ITextureDB|BSTextureDB.*)$'),
        ('name', r'^CreateSourceTexture')]),
    ('B1', 'B', 'Shader classes (lighting, effect, grass, tree, blood, particle, utility)', [
        ('class', r'^(BSShader|BSLightingShader|BSUtilityShader|BSComputeShader|BSEffectShader|BSGrassShader|'
                  r'BSDistantTreeShader|BSBloodSplatterShader|BSParticleShader|BSParticleShaderMacros)$'),
        ('name', r'^(ClearBSShaders|GetLightingShaderDefines|BSParticleShaderMacros)')]),
    ('B2', 'B', 'Shader properties and their controllers', [
        ('class', r'^(BSShaderProperty|BSShaderPropertyLightData|BSLightingShaderProperty|BSEffectShaderProperty|'
                  r'BSGrassShaderProperty|BSDistantTreeShaderProperty|BSBloodSplatterShaderProperty)$'),
        ('class', r'^BS(Lighting|Effect)ShaderProperty(Color|Float|UShort)Controller$'),
        ('name', r'^OnLoadTextureSet')]),
    ('B4', 'B', 'Sky and water shaders, properties and materials', [
        ('class', r'^(BSWaterShader|BSWaterShaderProperty|BSWaterShaderMaterial|BSSkyShader|BSSkyShaderProperty|'
                  r'BSSkyShaderMaterial)$')]),
    ('B3', 'B', 'Shader materials and texture sets', [
        ('class', r'^(BSLightingShaderMaterial\w*|BSEffectShaderMaterial|BSShaderMaterial|BSShaderTextureSet|'
                  r'BSTextureSet)$')]),
    ('A4', 'A', 'Lights', [
        ('class', r'^(BSLight|NiLight|NiPointLight|NiSpotLight|NiDirectionalLight|NiAmbientLight|'
                  r'NiLightColorController|NiLightDimmerController)$'),
        ('name', r'^CalculateActiveNonShadowCasterLights')]),
    ('C2', 'C', 'Camera, frustum, culling, occlusion and portals', [
        ('class', r'^(NiCamera|BSCubeMapCamera|NiFrustum|NiFrustumPlanes|BSCompoundFrustum|NiCullingProcess|'
                  r'BSCullingProcess|BSParabolicCullingProcess|BSGeometryListCullingProcess|BSFadeNodeCuller|'
                  r'HighActorCuller|BSOcclusion\w*|BSPortal\w*|BSFrustumFOVController|SubmitCullResultsJob)$'),
        ('name', r'^(PruneFrustumPlanes|NodeInFrustum|PointInFrustum|SetupCullingJobManager|thunk_DrawWorld)')]),
    ('A5', 'A', 'Render geometry (shapes, skin instances)', [
        ('class', r'^(NiGeometry|BSGeometry|NiGeometryData|BSTriShape|BSLODTriShape|BSMeshLODTriShape|'
                  r'BSDynamicTriShape|BSSubIndexTriShape|BSLODMultiIndexTriShape|BSMultiIndexTriShape|'
                  r'NiAdditionalGeometryData|NiSkinInstance|NiSkinData|NiSkinPartition)$')]),
    ('D1', 'D', 'Shadow lights and shadow scene node', [
        ('class', r'^(BSShadowLight|BSShadowDirectionalLight|BSShadowParabolicLight|BSShadowFrustumLight|'
                  r'ShadowSceneNode|ShadowmapDescriptor|BSTArray_ShadowmapDescriptor_)$'),
        ('name', r'^(ShadowSceneNode_|RenderActiveShadowCasterLights|CalculateAndDrawShadowCasterLights|'
                 r'CalculateActiveShadowCasterLights|ResetCalculatedShadowCasterLights|ProcessAllQueuedLights|'
                 r'RenderVolumetricLightingShadowMaps|BSShadowParabolicLight_)')]),
    ('D2', 'D', 'Image space: manager, effects and image-space shaders', [
        ('class', r'^(BSImagespaceShader\w*|ImageSpace\w*|TESImageSpace\w*|TESImagespace\w*)$'),
        ('name', r'^(GetVLTemporalAccumulationFactor|UpdateVolumetricLightingRenderData|VolumetricLightingDescriptor)')]),
    ('D3', 'D', 'Sky, sun, clouds, weather and fog', [
        ('class', r'^(Sky|Sun|Clouds|Atmosphere|Moon|Stars|Aurora|Precipitation|Precipitation::.*|TESWeather|'
                  r'BSFogProperty|NiFogProperty|SkyObject\w*)$')]),
    ('D4', 'D', 'Water system, displacement and reflections', [
        ('class', r'^(TESWaterSystem|TESWaterForm|TESWaterDisplacement|TESWaterReflections|TESWaterNormals)$')]),
    ('X1', '-', 'Particle systems and emitters', [
        ('class', r'^(NiParticle\w*|NiPSys\w*|BSPSys\w*|BSMasterParticleSystem|BSParticleSystemManager|'
                  r'BSParticleShader\w*Emitter|BSParticleShaderGeometry\w*|BGSShaderParticleGeometryData|'
                  r'BSStripParticleSystem)$')]),
    ('X2', '-', 'Scaleform UI renderer', [
        ('class', r'^Scaleform::Render\b.*$')]),
    ('X3', '-', 'Game cameras and camera states', [
        ('class', r'^(PlayerCamera|TESCamera|LocalMapCamera|MapCamera|\w*CameraState|PlayerCameraTransitionState|'
                  r'RaceSexCamera)$')]),
    ('X4', '-', 'Render-related forms, decals, effects, grass and LOD', [
        ('class', r'^(TESEffectShader|BGSTextureSet|BGSMaterialType|BGSMaterialObject|BGSVolumetricLighting|'
                  r'BGSLightingTemplate|TESGrass|GrassManager|BSTempEffectSimpleDecal|BSTempEffectGeometryDecal|'
                  r'BSTempEffectParticle|BGSDecalNode|BSDecalPlacementVectorExtraData|ShaderReferenceEffect|'
                  r'BGSTerrainManager|BGSTerrainBlock|BSTerrainEffect|TESLandTexture|TESTexture\w*|'
                  r'BGSReferenceEffect|ReferenceEffect)$')]),
]
GROUP_META = {g[0]: g for g in GROUPS}
COMPILED = [(g[0], [(kind, re.compile(rx)) for kind, rx in g[3]]) for g in GROUPS]

TEMPLATE_ARGS = re.compile(r'<[^<>]*>')
ADDRESS_SUFFIX = re.compile(r'_[0-9a-fA-F]{6,}$')
RENDERER_ALIAS = re.compile(r'^(BSGraphics::)?(Renderer|BSGraphics_Renderer)(::|_)')


def clean(name):
    """The name without template arguments, an import-thunk prefix or a trailing address suffix."""
    for _ in range(4):
        reduced = TEMPLATE_ARGS.sub('', name)
        if reduced == name:
            break
        name = reduced
    name = re.sub(r'^thunk_', '', name)
    return ADDRESS_SUFFIX.sub('', name)


def class_key(name):
    """Owner of a function name: the part before the last scope operator, or the name itself when it has none."""
    if RENDERER_ALIAS.match(name):
        return 'BSGraphics::Renderer'
    return name.rsplit('::', 1)[0] if '::' in name else name


def group_of(*names):
    """First group whose rules match any of the candidate names, else None."""
    cleaned = [clean(n) for n in names if n]
    for gid, rules in COMPILED:
        for name in cleaned:
            key = class_key(name)
            for kind, rx in rules:
                if rx.search(key if kind == 'class' else name):
                    return gid, key
    return None


def bucket(size):
    return next((i for i, bound in enumerate(BUCKETS) if size < bound), len(BUCKETS))


def read_tsv(path):
    for line in Path(path).read_text(encoding='utf-8', errors='replace').splitlines():
        if line and not line.startswith('#'):
            yield line.split('\t')


def load_names(root):
    out = {}
    for path in sorted(glob.glob(str(Path(root) / PDB_DIR / 'names' / '*.tsv'))):
        for row in read_tsv(path):
            if len(row) >= 2:
                out[int(row[0], 16)] = row[1]
    return out


def load_sizes(root):
    out = {}
    for path in sorted(glob.glob(str(Path(root) / PDB_DIR / 'boundaries' / '*.tsv'))):
        for row in read_tsv(path):
            if len(row) >= 2:
                out[int(row[0], 16)] = int(row[1], 16)
    return out


def load_json(path):
    return json.loads(Path(path).read_text(encoding='utf-8'))


def load_giveups(root):
    out = {}
    for path in sorted(glob.glob(str(Path(root) / 'data/giveups/*/*.json'))):
        doc = load_json(path)
        records = doc.get('records') or []
        if records:
            out[int(doc['rva'], 16)] = records[-1].get('category', 'other')
    return out


def load_index_areas(root):
    """RVA -> unit area (first path component of the unit) from the generated index table."""
    out = {}
    path = Path(root) / 'reconstruction/INDEX.md'
    if not path.is_file():
        return out
    for line in path.read_text(encoding='utf-8', errors='replace').splitlines():
        if not line.startswith('| `'):
            continue
        cells = [c.strip() for c in line.strip('|').split('|')]
        if len(cells) < 6:
            continue
        match = re.search(r'/ `0x([0-9a-f]+)` /', cells[2])
        if match:
            out[int(match[1], 16)] = cells[0].strip('`').split('/')[0]
    return out


def ready_info(queue):
    """(ready entries by RVA, size below which the committed list is complete)."""
    entries = {int(e['rva'], 16): e for e in queue.get('entries', [])}
    total = (queue.get('counts') or {}).get('ready', len(entries))
    ordered = queue.get('entries', [])
    if len(entries) >= total or not ordered:
        return entries, None
    return entries, (BUCKETS[bucket(ordered[-1]['size']) - 1] if bucket(ordered[-1]['size']) else 0)


def claim_ranges(claims):
    """[(start, end, issue number)] from claim dicts holding half-open `entries` ranges."""
    out = []
    for claim in claims or []:
        for start, end in claim.get('entries', []):
            out.append((int(start), int(end), claim.get('number')))
    return out


def claimed_by(ranges, rva):
    return sorted({n for a, b, n in ranges if a <= rva < b})


def build(root, claims=None):
    root = Path(root)
    pdb = load_names(root)
    sizes = load_sizes(root)
    progress = load_json(root / 'data/progress.json')
    queue = load_json(root / 'data/ready-queue.json')
    symbols = load_json(root / 'data/symbol-names.json').get('classes', {})
    giveups = load_giveups(root)
    areas = load_index_areas(root)
    ready, complete_below = ready_info(queue)
    ranges = claim_ranges(claims)

    inventory = {int(f['rva']): f for f in progress['functions']}
    rows = []
    for rva in sorted(set(pdb) | set(inventory)):
        entry = inventory.get(rva)
        found = group_of(pdb.get(rva), entry and entry['name'])
        if not found:
            continue
        gid, key = found
        size = (entry or {}).get('size') or sizes.get(rva)
        status = 'matched' if entry and entry['status'] == 'matched' else 'open'
        row = dict(rva=rva, name=pdb.get(rva) or entry['name'], group=gid, cls=key, size=size, status=status,
                   mapped=bool(entry and entry['status'] != 'matched'))
        if status == 'open':
            row['state'], row['why'] = open_state(row, ready, complete_below, giveups, ranges)
            row['claims'] = claimed_by(ranges, rva)
            row['blocks'] = int(ready[rva]['blocks']) if rva in ready else 0
        rows.append(row)
    return dict(rows=rows, areas=areas, symbols=symbols, ready=ready, complete_below=complete_below,
                queue_counts=queue.get('counts', {}), queue_stamp=queue.get('progress_updated_at'),
                progress_stamp=progress.get('updated_at'), build_id=progress.get('target_build_id'),
                claims_used=claims is not None, claim_count=len({n for _, _, n in ranges}))


def open_state(row, ready, complete_below, giveups, ranges):
    rva, size = row['rva'], row['size']
    if claimed_by(ranges, rva):
        return 'claimed', 'open claim'
    if rva in giveups:
        return 'blocked', f'give-up record, {giveups[rva]}'
    if rva in ready:
        return 'ready', ''
    if size is None:
        return 'blocked', 'size unknown'
    if complete_below is None or size < complete_below:
        return 'blocked', 'unmatched callee or non-ordinary kind'
    return 'unlisted', 'ready list capped; readiness unknown'


def summarize(inv):
    """Totals per group and per class from the built rows."""
    groups = {}
    classes = {}

    def bump(table, key, row):
        cell = table.setdefault(key, collections.Counter())
        cell['known'] += 1
        if row['status'] == 'matched':
            cell['matched'] += 1
        else:
            cell[row['state']] += 1
            if row['state'] != 'claimed':
                cell['open_bytes'] += row['size'] or 0
            if row['state'] in ('blocked', 'unlisted'):
                cell['why:' + row['why']] += 1

    for row in inv['rows']:
        bump(groups, row['group'], row)
        bump(classes, (row['group'], row['cls']), row)
    return groups, classes


def main_blocker(cell):
    """Most common reason an unmatched, unclaimed, not-ready function is held, in a few words."""
    why = [(n, k[4:]) for k, n in cell.items() if k.startswith('why:')]
    if not why:
        return ''
    count, reason = max(why)
    return f'{reason} ({count})'


def unplaced(inv, cls):
    entry = inv['symbols'].get(cls) or {}
    return len(entry.get('candidates') or {})


def entry_points(inv, letter, limit):
    """Easiest unclaimed open functions of a workstream: ready ones first, then the smallest unlisted ones.

    Within each tier the order is smallest size, then most callers unlocked. An unlisted function may be
    ready or waiting; `./sr next --class` on a machine with the function table tells which.
    """
    rows = [r for r in inv['rows'] if GROUP_META[r['group']][1] == letter and r['status'] == 'open'
            and r['state'] in ('ready', 'unlisted') and r['size']]
    rows.sort(key=lambda r: (r['state'] != 'ready', r['size'], -r['blocks'], r['rva']))
    return rows[:limit]


def render_entry_points(inv, limit, letters='ABCD'):
    lines = []
    for letter in letters:
        lines.append(f'**Workstream {letter} entry points** (names are CrashLogger-derived, '
                     f'CRASHLOGGER_PDB(59818@2026.10.24))')
        lines.append('')
        lines.append('| RVA | Name | Size | State | Callers unlocked |')
        lines.append('|---|---|---:|---|---:|')
        for r in entry_points(inv, letter, limit):
            state = 'ready' if r['state'] == 'ready' else 'unlisted'
            lines.append(f'| `0x{r["rva"]:x}` | {r["name"]} | {r["size"]} | {state} | {r["blocks"] or ""} |')
        lines.append('')
    return '\n'.join(lines)


def workstream_cells(inv, groups):
    out = {}
    for gid, cell in groups.items():
        letter = GROUP_META[gid][1]
        total = out.setdefault(letter, collections.Counter())
        total.update({k: v for k, v in cell.items() if not k.startswith('why:')})
    return out


def pct(part, whole):
    return f'{100 * part / whole:.1f}%' if whole else 'n/a'


def count_cells(c):
    return (f'{c["known"]} | {c["matched"]} | {c["claimed"]} | {c["ready"]} | {c["blocked"]} | {c["unlisted"]}')


def render(inv):
    groups, classes = summarize(inv)
    letters = workstream_cells(inv, groups)
    lines = []
    claims = (f'functions under {inv["claim_count"]} open claim issues are counted as claimed'
              if inv['claims_used'] else 'no claim list was read, so the claimed column is 0')
    lines.append(f'Build `{inv["build_id"]}`. The committed ready list holds {inv["queue_counts"].get("listed")} of '
                 f'{inv["queue_counts"].get("ready")} ready functions and is filtered against '
                 f'`data/progress.json`; {claims}.')
    lines.append('')
    lines.append('| Workstream | Known | Matched | Matched % | Claimed | Ready | Waiting | Unlisted | Open bytes |')
    lines.append('|---|---:|---:|---:|---:|---:|---:|---:|---:|')
    grand = collections.Counter()
    for letter in 'ABCD':
        c = letters.get(letter, collections.Counter())
        grand.update(c)
        lines.append(f'| {letter}: {WORKSTREAMS[letter]} | {c["known"]} | {c["matched"]} | '
                     f'{pct(c["matched"], c["known"])} | {c["claimed"]} | {c["ready"]} | {c["blocked"]} | '
                     f'{c["unlisted"]} | {c["open_bytes"]} |')
    lines.append(f'| **Total A-D** | {grand["known"]} | {grand["matched"]} | {pct(grand["matched"], grand["known"])} | '
                 f'{grand["claimed"]} | {grand["ready"]} | {grand["blocked"]} | {grand["unlisted"]} | {grand["open_bytes"]} |')
    adj = letters.get('-', collections.Counter())
    lines.append(f'| Adjacent, not assigned | {adj["known"]} | {adj["matched"]} | {pct(adj["matched"], adj["known"])} | '
                 f'{adj["claimed"]} | {adj["ready"]} | {adj["blocked"]} | {adj["unlisted"]} | {adj["open_bytes"]} |')
    lines.append('')
    lines.append('Known = functions with a public name in the CrashLogger tables or `data/progress.json` (a lower '
                 'bound). Ready = every callee matched and the function is in the committed list. Waiting = proven '
                 'blocked (a give-up record, or under 16 bytes and absent from the complete part of the list). '
                 'Unlisted = not matched, not claimed, not in the capped list: ready or waiting, unknown here. Open bytes = '
                 'the sizes of the Ready, Waiting and Unlisted functions together.')
    lines.append('')
    for letter in 'ABCD-':
        title = f'Workstream {letter}' if letter != '-' else 'Adjacent'
        lines.append(f'### {title}: {WORKSTREAMS[letter]}')
        lines.append('')
        lines.append(f'Scope: {WORKSTREAM_SCOPE[letter]}.')
        lines.append('')
        lines.append('| Group | Known | Matched | Claimed | Ready | Waiting | Unlisted | Main blocker | Unit area |')
        lines.append('|---|---:|---:|---:|---:|---:|---:|---|---|')
        for gid, _, gtitle, _ in sorted(GROUPS):
            if GROUP_META[gid][1] != letter or gid not in groups:
                continue
            c = groups[gid]
            area = collections.Counter(inv['areas'][r['rva']] for r in inv['rows']
                                       if r['group'] == gid and r['rva'] in inv['areas']).most_common(1)
            lines.append(f'| {gid} {gtitle} | {count_cells(c)} | {main_blocker(c)} | '
                         f'{area[0][0] if area else "-"} |')
        lines.append('')
        lines.append(f'<details><summary>Classes of {title[0].lower() + title[1:]} with unmatched functions</summary>')
        lines.append('')
        lines.append('| Class | Group | Known | Matched | Claimed | Ready | Waiting | Unlisted | Sibling names not placed |')
        lines.append('|---|---|---:|---:|---:|---:|---:|---:|---:|')
        picked = [(k, c) for k, c in classes.items() if GROUP_META[k[0]][1] == letter and c['known'] > c['matched']]
        for (gid, cls), c in sorted(picked, key=lambda t: (t[0][0], -t[1]['known'], t[0][1])):
            lines.append(f'| {cls} | {gid} | {count_cells(c)} | {unplaced(inv, cls)} |')
        lines.append('')
        lines.append('</details>')
        lines.append('')
    lines.append('<details><summary>Entry points</summary>')
    lines.append('')
    lines.append(render_entry_points(inv, ENTRY_POINTS))
    lines.append('</details>')
    return '\n'.join(lines).rstrip() + '\n'


def to_json(inv):
    groups, classes = summarize(inv)
    return {
        'build_id': inv['build_id'], 'progress_stamp': inv['progress_stamp'], 'queue_stamp': inv['queue_stamp'],
        'groups': {g: dict(v) for g, v in groups.items()},
        'classes': {f'{g}:{c}': dict(v) for (g, c), v in classes.items()},
        'rows': [{k: v for k, v in r.items()} for r in inv['rows']],
    }


def replace_block(text, body):
    if BLOCK_START not in text or BLOCK_END not in text:
        raise SystemExit(f'document lacks {BLOCK_START} / {BLOCK_END}')
    head, rest = text.split(BLOCK_START, 1)
    tail = rest.split(BLOCK_END, 1)[1]
    return f'{head}{BLOCK_START}\n\n{body}\n{BLOCK_END}{tail}'


def fetch_claims(root):
    import claims as claims_tool
    return [dict(number=c['number'], entries=c['entries']) for c in claims_tool.GitHub(root).open_claims()]


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    ap.add_argument('--root', type=Path, default=ROOT)
    ap.add_argument('--claims', type=Path, help='JSON list of {"number", "entries": [[start, end], ...]}')
    ap.add_argument('--fetch-claims', action='store_true', help='read open claim issues with gh')
    ap.add_argument('--json', type=Path, dest='json_out')
    ap.add_argument('--entry-points', type=int, metavar='N', help='print N entry points per workstream and exit')
    ap.add_argument('--update-doc', type=Path, help='rewrite the inventory block of a milestone document')
    args = ap.parse_args(argv)
    claims = None
    if args.claims:
        claims = load_json(args.claims)
    elif args.fetch_claims:
        claims = fetch_claims(args.root)
    inv = build(args.root, claims)
    if args.entry_points:
        sys.stdout.write(render_entry_points(inv, args.entry_points))
        return 0
    if args.json_out:
        args.json_out.write_text(json.dumps(to_json(inv), indent=1) + '\n', encoding='utf-8')
    body = render(inv)
    if args.update_doc:
        args.update_doc.write_text(replace_block(args.update_doc.read_text(encoding='utf-8'), body), encoding='utf-8')
    elif not args.json_out:
        sys.stdout.write(body)
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
