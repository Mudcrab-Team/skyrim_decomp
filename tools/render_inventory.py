#!/usr/bin/env python3
"""Inventory of the rendering subsystem, derived from the repository's public data only.

    python3 tools/render_inventory.py                     # markdown tables on stdout
    python3 tools/render_inventory.py --json OUT.json     # the full structure
    python3 tools/render_inventory.py --fetch-claims      # also exclude functions under open claim issues
    python3 tools/render_inventory.py --claims FILE.json  # the same, from a saved list of claims
    python3 tools/render_inventory.py --update-doc docs/milestones/rendering.md
    python3 tools/render_inventory.py --fetch-claims --update-issues

Inputs: reconstruction/generated/crashlogger_pdb/{names,boundaries}, data/symbol-names.json,
data/progress.json, the published ready queue, data/giveups and reconstruction/INDEX.md. Only RVAs, names,
sizes and counts are read or written. Nothing here is evidence of a match.

The inventory is a lower bound on the subsystem because it can only place functions with a public name.
"""
import argparse
import collections
import glob
import json
from pathlib import Path
import re
import sys

import ready_queue

ROOT = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(ROOT / 'tools')]

PDB_DIR = 'reconstruction/generated/crashlogger_pdb'
ENTRY_POINTS = 15
BLOCK_START, BLOCK_END = '<!-- inventory:start -->', '<!-- inventory:end -->'
SLOTS = 'ABCDE'
TRACKING_ISSUE = 1185
TASK_ISSUES = dict(zip(SLOTS, (1186, 1187, 1188, 1189, 1191)))
ENTRY_HEADER = '| RVA | Name | Size | State | Callers unlocked |\n|---|---|---:|---|---:|'

WORKSTREAMS = {
    'A': 'Foundation',
    'B': 'Shaders and materials',
    'C': 'Batching, passes, camera, culling',
    'D': 'Image space, sky, water system',
    'E': 'Shadows',
    '-': 'Adjacent',
}
WORKSTREAM_SCOPE = {
    'A': 'BSGraphics state, render targets, buffers, textures and resources, render geometry, lights',
    'B': 'shader classes, shader properties, materials, sky and water shaders',
    'C': 'render passes, batch renderer, accumulators, camera, frustum, culling, portals',
    'D': 'image space, sky, weather, fog, water',
    'E': 'shadow lights, shadow scene node, shadow-map setup and shadow passes',
    '-': 'listed for context, owned by the general rounds',
}

# (id, workstream, title, rules). A rule is ('class', regex) tested on the class key or ('name', regex) tested
# on the whole cleaned name. The first group with a matching rule wins, so a narrow group sits above a broad one.
GROUPS = [
    ('E1', 'E', 'Shadow lights, scene node, maps and passes', [
        ('class', r'^(BSShadowLight|BSShadowDirectionalLight|BSShadowParabolicLight|BSShadowFrustumLight|'
                  r'ShadowSceneNode|ShadowmapDescriptor|BSTArray_ShadowmapDescriptor_)$'),
        ('name', r'^(ShadowSceneNode_|BSShadowParabolicLight_|RenderActiveShadowCasterLights|'
                 r'CalculateAndDrawShadowCasterLights|CalculateActiveShadowCasterLights|'
                 r'ResetCalculatedShadowCasterLights|ProcessAllQueuedLights|RenderVolumetricLightingShadowMaps|'
                 r'DrawWorld_RenderShadowCasters|RenderShadowmasks|UpdateOrAssignShadowCSTexture)')]),
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
                 r'SetPSTextureFilterMode|PollOcclusionQuery)')]),
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
    total = (queue.get('counts') or {}).get('ready')
    if total == len(entries):
        return entries, None
    for entry in reversed(queue.get('entries', [])):
        if 'unlock_rank' not in entry:
            band = ready_queue.bucket(entry['size'])
            return entries, ready_queue.BUCKETS[band - 1] if band else 0
    return entries, 0


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
    queue = ready_queue.read_queue(root, progress.get('target_build_id'))
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
            row['unlocks'] = int(ready[rva]['unlocks']) if rva in ready else 0
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
        return 'blocked', 'absent from the ready queue'
    return 'unlisted', 'readiness unknown from available queue'


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

    Within each tier the order is smallest size, then most callers unlocked.
    """
    rows = [r for r in inv['rows'] if GROUP_META[r['group']][1] == letter and r['status'] == 'open'
            and r['state'] in ('ready', 'unlisted') and r['size']]
    rows.sort(key=lambda r: (r['state'] != 'ready', r['size'], -r['unlocks'], r['rva']))
    return rows[:limit]


def render_entry_points(inv, limit, letters=SLOTS):
    lines = []
    for letter in letters:
        lines.append(f'**Workstream {letter} entry points** (names are CrashLogger-derived, '
                     f'CRASHLOGGER_PDB(59818@2026.10.24))')
        lines.append('')
        lines.append(entry_table(inv, letter, limit))
        lines.append('')
    return '\n'.join(lines)


def entry_table(inv, letter, limit):
    lines = [ENTRY_HEADER]
    for row in entry_points(inv, letter, limit):
        unlocked = row['unlocks'] if row['state'] == 'ready' else ''
        lines.append(f'| `0x{row["rva"]:x}` | {row["name"]} | {row["size"]} | {row["state"]} | {unlocked} |')
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


def progress_table(letters, adjacent=False):
    lines = ['| Workstream | Known | Matched | Matched % | Claimed | Ready | Waiting | Unlisted | Open bytes |',
             '|---|---:|---:|---:|---:|---:|---:|---:|---:|']

    def row(title, c):
        return (f'| {title} | {c["known"]} | {c["matched"]} | {pct(c["matched"], c["known"])} | '
                f'{c["claimed"]} | {c["ready"]} | {c["blocked"]} | {c["unlisted"]} | {c["open_bytes"]} |')

    grand = collections.Counter()
    for letter in SLOTS:
        c = letters.get(letter, collections.Counter())
        grand.update(c)
        lines.append(row(f'{letter}: {WORKSTREAMS[letter]}', c))
    lines.append(row('**Total A-E**', grand))
    if adjacent:
        lines.append(row('Adjacent, not assigned', letters.get('-', collections.Counter())))
    return '\n'.join(lines)


def render(inv):
    groups, classes = summarize(inv)
    letters = workstream_cells(inv, groups)
    lines = []
    claims = (f'functions under {inv["claim_count"]} open claim issues are counted as claimed'
              if inv['claims_used'] else 'no claim list was read, so the claimed column is 0')
    counts = inv['queue_counts']
    coverage = (f'The published queue lists {counts["listed"]} of {counts["ready"]} ready functions'
                if 'listed' in counts and 'ready' in counts else 'The published ready queue is unavailable')
    lines.append(f'Build `{inv["build_id"]}`. {coverage}. Matched functions come from '
                 f'`data/progress.json`, and {claims}.')
    lines.append('')
    lines.append(progress_table(letters, adjacent=True))
    lines.append('')
    lines.append('Known counts functions named in the CrashLogger tables or `data/progress.json`. Ready counts '
                 'available functions in the published queue. Waiting covers give-ups, functions of unknown size '
                 'and functions absent from the portion of the queue with complete coverage. Unlisted marks '
                 'unknown readiness when the queue has incomplete coverage or is unavailable. Open bytes sum the '
                 'sizes of the Ready, Waiting and Unlisted functions.')
    lines.append('')
    for letter in SLOTS + '-':
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
    head, start, rest = text.partition(BLOCK_START)
    _, end, tail = rest.partition(BLOCK_END)
    if not start or not end or text.count(BLOCK_START) != 1 or text.count(BLOCK_END) != 1:
        raise ValueError(f'expected one {BLOCK_START} / {BLOCK_END} block')
    return f'{head}{BLOCK_START}\n\n{body}\n{BLOCK_END}{tail}'


def update_doc(path, inv):
    old = path.read_text(encoding='utf-8')
    new = replace_block(old, render(inv))
    if old != new:
        path.write_text(new, encoding='utf-8')
    return old != new


TASK_COUNTS = re.compile(r'^Known functions: [^\n]+\n\nClasses(?: and named helpers)? \(open of known\): [^\n]+', re.M)
TASK_ENTRIES = re.compile(r'^(## First entry points \(easiest first\)\n\n)The current queue lists [^\n]+\n\n'
                          + re.escape(ENTRY_HEADER) + r'(?:\n\| [^\n]+ \|)*', re.M)
OLD_CLAIM_NOTES = (
    'Functions under any open claim issue, including the 300-function claim #1180, are excluded; '
    'the inventory reads them automatically.',
    'The inventory excludes functions under open claims, including #1180.',
)


def render_tracking_issue(body, letters):
    summary = ('Counts cover functions with public names. Matched counts come from `data/progress.json`.\n\n'
               + progress_table(letters) + '\n')
    if BLOCK_START not in body and BLOCK_END not in body:
        body = f'{body.rstrip()}\n\n## Progress\n\n{BLOCK_START}\n{BLOCK_END}\n'
    body = body.replace('Open claims, including the 300-function claim #1180, are excluded from the counts and '
                        'from `./sr next`.', 'Functions under open claims are excluded from the available counts '
                        'and from `./sr next`.')
    return replace_block(body, summary)


def render_task_issue(body, inv, letter, totals, classes):
    available = totals['ready'] + totals['blocked'] + totals['unlisted']
    counts = (f'Known functions: {totals["known"]}, matched: {totals["matched"]}, '
              f'under open claims: {totals["claimed"]}, open and available: {available} '
              f'({totals["ready"]} listed ready). The inventory counts functions with public names.')
    ranked = []
    for (gid, cls), cell in classes.items():
        remaining = cell['known'] - cell['matched'] - cell['claimed']
        if GROUP_META[gid][1] == letter and remaining:
            ranked.append((remaining, cls, cell['known']))
    ranked.sort(key=lambda item: (-item[0], item[1]))
    listed = ', '.join(f'`{cls}` ({remaining} open of {known})' for remaining, cls, known in ranked[:30])
    if len(ranked) > 30:
        listed += f', and {len(ranked) - 30} smaller groups in the milestone document'
    counts += '\n\nClasses and named helpers (open of known): ' + (listed or 'none') + '.'
    entries = (f'The current queue lists {totals["ready"]} ready functions for this workstream after excluding open claims.'
               f'\n\n{entry_table(inv, letter, ENTRY_POINTS)}')
    body, counts_found = TASK_COUNTS.subn(lambda _: counts, body)
    body, entries_found = TASK_ENTRIES.subn(lambda m: m[1] + entries, body)
    if (counts_found, entries_found) != (1, 1):
        raise ValueError(f'expected one counts and entry-point section in workstream {letter}')
    for note in OLD_CLAIM_NOTES:
        body = body.replace(note, 'Functions under open claims are excluded from the available counts and entry points.')
    return body


def update_issues(root, inv, gh=None):
    """Edit the tracking and workstream issue bodies in place. Return the numbers that changed."""
    from claims import GitHub, REPO

    gh = gh or GitHub(root)
    groups, classes = summarize(inv)
    letters = workstream_cells(inv, groups)
    updated = []
    for number, letter in [(TRACKING_ISSUE, None), *((n, l) for l, n in TASK_ISSUES.items())]:
        issue = gh.api(f'repos/{REPO}/issues/{number}')
        if 'pull_request' in issue or not issue.get('body'):
            raise ValueError(f'expected an issue with a body at #{number}')
        old = issue['body']
        new = (render_tracking_issue(old, letters) if letter is None else
               render_task_issue(old, inv, letter, letters.get(letter, collections.Counter()), classes))
        if new != old:
            gh.run('issue', 'edit', number, '--repo', REPO, body=new)
            updated.append(number)
    return updated


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
    ap.add_argument('--update-issues', action='store_true', help='refresh the tracking and workstream issue bodies')
    args = ap.parse_args(argv)
    if args.update_issues and (not args.fetch_claims or args.claims or args.entry_points is not None):
        ap.error('--update-issues requires --fetch-claims and cannot be used with --claims or --entry-points')
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
    if args.update_doc:
        try:
            update_doc(args.update_doc, inv)
        except ValueError as exc:
            ap.error(str(exc))
    if args.update_issues:
        updated = update_issues(args.root, inv)
        print('Updated issues ' + ', '.join(f'#{n}' for n in updated) if updated else 'Rendering issues are current')
    if not (args.update_doc or args.update_issues or args.json_out):
        sys.stdout.write(render(inv))
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
