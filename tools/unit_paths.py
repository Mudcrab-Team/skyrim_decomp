"""Where a reconstruction unit lives: reconstruction/<area>/<Class>.cpp and .h.

The areas follow the engine's own subsystems, in the manner of the FNV decompilation's folders
(a library per engine layer, a shared game folder, a game folder), so a reader finds a class
where a maintainer of the original would have kept it. `place(owner)` picks the area from the
class name by ordered prefix rules; `data/unit-areas.json` overrides single classes. A class
with no rule is refused rather than filed somewhere by default (reconstruction/README.md).

Generated families that stand for no named class (static initialisers, deleting leaves, checked
copies and the like) live under `unmapped/`; their folder is chosen by the family, not the name.

    python3 tools/unit_paths.py Actor NiNode BSFixedString
"""
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
OVERRIDES = 'data/unit-areas.json'

AREAS = (
    'bsaudio', 'bscore', 'bshavok', 'bsinput', 'bsmain', 'bsscaleform', 'bsscript', 'bsshader', 'bssystem',
    'gamebryo/niparticle', 'gamebryo/nianimation', 'gamebryo/nimain',
    'skyrim/ai', 'skyrim/ai/combat', 'skyrim/ai/movement', 'skyrim/camera', 'skyrim/controls',
    'skyrim/interface', 'skyrim/magic', 'skyrim/papyrus',
    'skyrim_shared/actors', 'skyrim_shared/audio', 'skyrim_shared/conditions', 'skyrim_shared/dialogue',
    'skyrim_shared/extradata', 'skyrim_shared/facegen', 'skyrim_shared/forms', 'skyrim_shared/inventory',
    'skyrim_shared/magic', 'skyrim_shared/pathfinding', 'skyrim_shared/perks', 'skyrim_shared/quest',
    'skyrim_shared/refs', 'skyrim_shared/saveload', 'skyrim_shared/sky', 'skyrim_shared/tempeffects',
    'skyrim_shared/world',
    'thirdparty/scaleform',
    'unmapped/buffers', 'unmapped/fields', 'unmapped/leaves', 'unmapped/represented',
    'unmapped/static', 'unmapped/storage', 'unmapped/support', 'unmapped/wrappers',
)
# Headers published for contributors to include (docs/declaration-kit.md); not an engine area.
KIT_DIRS = ('declarations',)
# Single-level folders of the earlier layout. A unit already there stays valid until it is moved, so
# a change prepared against that layout still lands; no new unit is started in one.
LEGACY_AREA = re.compile(
    r'(?:bsengine|forms|actors|netimmerse|magic|inventory|havok|scaleform|shaders|layouts|unknown|fields|static|'
    r'leaves|storage|buffers|wrappers|f004support|represented_storage|contrib_[a-z0-9_]+|fo4[a-z0-9_]*|'
    r'small[0-9a-z_]*|actor20[0-9a-z_]*|conditions_[a-z0-9_]+)')

# Folders of generated families that are moved whole, as they were.
BULK_DIRS = {
    'static': 'unmapped/static', 'leaves': 'unmapped/leaves', 'storage': 'unmapped/storage',
    'fields': 'unmapped/fields', 'buffers': 'unmapped/buffers', 'represented_storage': 'unmapped/represented',
    'wrappers': 'unmapped/wrappers', 'f004support': 'unmapped/support',
}
# Name prefixes of the generated families (tools/*_generate*.py), for files that were filed by class
# area although no class stands behind them. Longest prefix first.
FAMILY_DIRS = (
    ('StringStatic', 'unmapped/static'), ('SharedTeardown', 'unmapped/static'), ('Static', 'unmapped/static'),
    ('DeletingLeaf', 'unmapped/leaves'), ('DeletingWrapper', 'unmapped/wrappers'),
    ('LeafForward', 'unmapped/leaves'), ('LeafAddress', 'unmapped/leaves'), ('ReturnLeaf', 'unmapped/leaves'),
    ('TableStoreLeaf', 'unmapped/leaves'), ('VirtualTail', 'unmapped/leaves'), ('Leaf', 'unmapped/leaves'),
    ('StorageInit', 'unmapped/storage'), ('FieldLeaf', 'unmapped/storage'),
    ('CheckedCopy', 'unmapped/buffers'), ('LockedArray_', 'unmapped/buffers'),
    ('LockedSource_', 'unmapped/buffers'), ('BSInlineHost', 'unmapped/wrappers'),
    ('F004Recover', 'unmapped/wrappers'), ('F004Represented', 'unmapped/wrappers'),
    ('CommunityLeaf', 'unmapped/leaves'),
)
FAMILY_STEM = re.compile(r'^(?:' + '|'.join(re.escape(p) for p, _ in FAMILY_DIRS) + r')[0-9a-fA-F_]*[0-9a-fA-F]$')
LAYOUT_SUFFIX = re.compile(r'(?:Field|Static)?(?:Thunk|Storage|Prefix)?Layout$')
RVA_TAG = re.compile(r'_[0-9a-f]{3,8}$')


def family_dir(stem):
    """The unmapped/ folder of a generated-family stem, or None for a class-named file."""
    if not FAMILY_STEM.match(stem):
        return None
    return next(d for p, d in FAMILY_DIRS if stem.startswith(p))


def owner_of(stem):
    """The class a unit stem stands for: the stem without a layout-unit suffix or a split-unit tag."""
    base = stem
    m = LAYOUT_SUFFIX.search(base)
    if m and m.start() > 0:
        base = base[:m.start()]
    return base


# First match wins; order matters (a specific family before its general prefix).
RULES = (
    # third-party libraries and the engine's script machine
    (r'(?:GFx|GAS|GRefCount|GRef)', 'thirdparty/scaleform'),
    (r'(?:NativeFunction|AutoPropertyFunction|FunctionPointerCallable|BoundArgumentCallable|BoundPairCallable|'
     r'CopyableLogFunctionCallable|LogCallableInterface|LogCopyableInterface|LogFunctionCallable|'
     r'ScalarCaptureCallable|ErasedSignature|ErasedCallableVptr|LayoutValueTypes|InitializeValues)', 'skyrim/papyrus'),
    (r'(?:Script|SkyrimVMInterface|BSVMLoadTask)', 'bsscript'),
    (r'(?:BSScaleformTranslator|BSUIScaleformData|IUIMessageData)', 'bsscaleform'),
    # Havok
    (r'(?:Bhk|bhk|Hkp|hk[A-Z]|CollisionFilter|ConstraintCollisionFilterListener|PhantomOverlapListener|BSIRagdollDriver)', 'bshavok'),
    # audio
    (r'(?:BSAudio|BSXAudio2|BSSoundHandle|BSNullImplGameSound|BSISound|BSIISound|BSIMusic|BSSound)', 'bsaudio'),
    (r'(?:BGSSound|BGSStandardSoundDef|BGSMusic|BGSReverb|BGSAcousticSpace|TESSound|DynamicAttenuation|BGSFootstep|'
     r'BGSVoiceType|BGSPickupPutdown|BGSSoundOutput|BGSSoundCategory|BGSImpactData|BGSMaterial(?:Type|Object))', 'skyrim_shared/audio'),
    # input
    (r'(?:BSIInputDevice|BSInputDevice|BS[A-Za-z0-9]*Device|BSDirectInputManager|BSPC|BSWin32|BSVirtualKeyboard|'
     r'InputEvent|CharEvent|DeviceConnectEvent)', 'bsinput'),
    # faces, saves, extra data, conditions
    (r'BSFaceGen', 'skyrim_shared/facegen'),
    (r'(?:BGSSave|BGSLoad|TempLoadGameBuffer|LoadStorageWrapper|SaveStorageWrapper|BSSaveDataSystemUtility)', 'skyrim_shared/saveload'),
    (r'(?:Extra[A-Z]|BSExtraData$|MultiBoundMarkerData)', 'skyrim_shared/extradata'),
    (r'(?:TESCondition|ConditionFunctions|ConditionalVirtualCall|ConditionalNotify)', 'skyrim_shared/conditions'),
    # inventory
    (r'(?:InventoryChanges|ArmorRatingVisitor|InventoryVisitorCaptureBase)', 'skyrim_shared/inventory'),
    # shaders and rendering state
    (r'BSParticleShader[A-Za-z]*Emitter', 'gamebryo/niparticle'),
    (r'(?:BSPSys|BSMasterParticleSystem|BSProceduralLightning|NiPSys|NiParticle)', 'gamebryo/niparticle'),
    (r'(?:BS[A-Za-z0-9]*Shader|BSImagespace|BSUtilityShader|BSLight|BSShadow|BSShaderAccumulator|BSCubeMapCamera|'
     r'BSTextureSet|ShaderBase|ShaderRef$|ShaderTable|ReloadShader|ImagespaceShader|ImageEffect$|BSMaterialObject)', 'bsshader'),
    # temporary effects, sky
    (r'(?:BSTempEffect|BSTerrainEffect|ReferenceEffect|ShaderReferenceEffect|ModelReferenceEffect|BGSReferenceEffect|'
     r'ActiveEffectReferenceEffectController|RefAttachTechniqueInput|BGSShaderParticleGeometryData|BGSDecalNode)', 'skyrim_shared/tempeffects'),
    (r'(?:Sky$|SkyEffectController|SkyObjectRoot)', 'skyrim_shared/sky'),
    # pathfinding
    (r'(?:BSPathing|PathingRequest|PathingCell|PathingDoor|BSNavmesh|NavMeshInfoMap|MasterFilePathing)', 'skyrim_shared/pathfinding'),
    # combat and movement AI
    (r'(?:Combat|AutoRegisterCombat|BlockBash|BGSBlockBash|Blocking|BGSAttackData|AttackDamage|TESAttackDamage)', 'skyrim/ai/combat'),
    (r'(?:Movement|IMovement|AutoRegisterPath|PathRegistrationBases)', 'skyrim/ai/movement'),
    (r'(?:BGSProcedure|IProcedureTreeItem|TESPackage|TES[A-Za-z]*PackageData|BGSPackageData|BGSOverridePackCollection|'
     r'(?:BGS)?AIWorld|AIProcess|ArrestProcess|PackageProcess|QueryProcess|ProcessLists|ActorProcess)', 'skyrim/ai'),
    # magic
    (r'(?:ActorMagicCaster|MagicCaster$|ActiveEffect|[A-Za-z]*ValueModifierEffect|[A-Za-z]+Effect$|WeaponEnchantmentController|'
     r'SpawnHazardEffect|NonActorMagicTarget)', 'skyrim/magic'),
    (r'(?:MagicItem|MagicTarget|MagicTraversalCaptureBase|SpellItem|EnchantmentItem|AlchemyItem|IngredientItem|'
     r'EffectSetting|ScrollItem|TESLevSpell|TESEnchantableForm)', 'skyrim_shared/magic'),
    # camera, interface, controls
    (r'(?:TESCamera|PlayerCamera|[A-Za-z]*CameraState|FirstPersonCameraData|OwnedCameraEffectController|LocalMapCamera|'
     r'BGSCamera|PlayerCombatView|AutoVanityState|ThirdPersonState)', 'skyrim/camera'),
    (r'(?:[A-Za-z]*Menu[A-Za-z]*|IMessageBoxCallback|IGiftMenu|UIBlurManager|Inventory3DManager|LoadingMenuData|MessageIconComponent|'
     r'BGSMessage|MessageCallbackCaptureBase|NeedToUpdateCreationClubCallback|ConsoleNativeUIMenu|ScreenshotHandler)', 'skyrim/interface'),
    (r'(?:[A-Za-z0-9]*Handler(?:Bulk|Represented)?|IHandlerFunctor[A-Za-z]*|ThirdPersonInput|IronSightsState|PlayerInput)', 'skyrim/controls'),
    # animation graphs and controllers
    (r'(?:BSAnimationGraph|IAnimationGraphManagerHolder|SimpleAnimationGraph|BSOffsetAnimationGenerator|BGSGamebryoSequenceGenerator|'
     r'BSWindModifier|BSSimpleScaleController|BSTreadTransfInterpolator|BSInterpValueModifier|BSIsActiveModifier|BSTweenerModifier|'
     r'BSDistTriggerModifier|BSPassByTargetTriggerModifier|NiBSpline|Ni[A-Za-z0-9]*Interpolator|Ni[A-Za-z0-9]*Controller|'
     r'NiTimeController|NiKeyBased|NiExtraDataController|NiPathController|NiRollController|NiLookAt)', 'gamebryo/nianimation'),
    # core, system and main
    (r'(?:NiAllocator|NiStandardAllocator|BSNiAllocator|BSFixedString|BSIntrusiveRefCounted|BSTEventSink|BSReadWriteLock|BSThread|'
     r'BSCounterStorage|BSMem|BSTimer|BSReference|BSHandleRefObject|BSReleaseOwner|BSSmallBlockAllocator|MemoryHeap|'
     r'BSPointerHandleManagerInterface|AdditionalInterface|ArrayAllocator|TaskQueueInterface|Dispatcher|SyncQueueObj|QueueDelete|HandleExtraDelete|EventCaptureDelete|'
     r'EventFactoryNameLink|EventInterfaceVptr|CodeTasklet|BSTaskletData|BSTask$|BSStorage$|IOTask|ModManagerData|RegistryEntry|'
     r'LockedArray|LockedSource)', 'bscore'),
    (r'(?:BSFile|ArchiveFile|CompressedArchiveFile|BSSearchPath|QueuedFile|ResourceAsyncStream|ResourceStreamBase|BSResourceNiBinaryStream|'
     r'BSStreamSystemUtility|BSSystemUtility|UnitTest_BSStream|NiFile|NiBinaryStream|NiMemStream|NiStream|QueuedPromoteReferencesTask)', 'bssystem'),
    (r'(?:Main$|TES$|BS$|SettingCollectionData|BSIntrusive)', 'bsmain'),
    # scene graph
    (r'(?:Ni|BSTriShape|BSGeometry|BSDynamicTriShape|BSMultiIndexTriShape|BSSubIndexTriShape|BSInstanceTriShape|BSFadeNode|BSLeafAnimNode|'
     r'BSOrderedNode|BSMultiBound|BSOcclusion|BSPortalGraph|BSDismemberSkinInstance|BSFlattenedBoneTree|BSBound|BSXFlags|BSInvMarker|'
     r'BSFogProperty|BSTreadTransf)', 'gamebryo/nimain'),
    # references and the game world
    (r'(?:TESObjectREFR|VirtualREFR|REFR|Projectile|[A-Za-z]+Projectile$|Explosion$|Hazard$|Horse$|ForwardTarget|TESObjectCELLExtra)', 'skyrim_shared/refs'),
    (r'(?:TESWorldSpace|TESObjectCELL|TESObjectLAND|TESLandTexture|GridArray|GridCellArray|BGSTerrain|BGSQueued|AddCellGrassTask|'
     r'TESWater|TESRegion|BGSEncounterZone|BGSLocation|BGSLightingTemplate|BGSVolumetricLighting|BGSLensFlare|TESImageSpace|'
     r'ImageSpaceModifierInstance|TESGrass|TESObjectTREE|TESFlora|BGSStaticCollection|BGSMovableStatic|BGSAddonNode|BGSCollisionLayer|'
     r'TESLoadScreen|BGSDefaultObjectManager)', 'skyrim_shared/world'),
    # dialogue, quests, perks
    (r'(?:TESTopic|BGSDialogue|ResponseData|TESShout|TESWordOfPower)', 'skyrim_shared/dialogue'),
    (r'(?:BGSStory|BGSScene|BGSBaseAlias|TESQuest|BGSNote|BGSMoviePlayer)', 'skyrim_shared/quest'),
    (r'(?:BGSPerk|BGSEntryPoint|BGSAbilityPerkEntry|BGSQuestPerkEntry|BGSAssociationType|BGSRelationship)', 'skyrim_shared/perks'),
    # actors
    (r'(?:Actor|Character|PlayerCharacter|EquippedActor|LimbActor|RelationshipActor|RotationActor|SceneActor|TESNPC|TESRace|'
     r'TESClass|TESCombatStyle|TESEyes|BGSHeadPart|BGSBodyPart|RaceComponent|BGSActionData|TESActionData|BGSOutfit|ChangeActor|PlayerVirtual)', 'skyrim_shared/actors'),
    # game forms: what is left under the form prefixes and the form-like helpers
    (r'(?:TES|BGS|BaseFormComponent|FormComponent|IFormFactory|ConcreteFormFactory|ConcreteObjectFormFactory|Gold$|StateRelated|'
     r'FieldRecovery|FindEqualsFunctor|FindNonExcludedDeliveryFunctor|BSIntrusive|HandleQuery|ScrollItem|BoundingVolumeDelete|'
     r'MovementSchemeDelete|Shield$|ImageEffect|LayoutValue|ResourcesPreload|MovementUpdate)', 'skyrim_shared/forms'),
)
COMPILED = tuple((re.compile(pattern), area) for pattern, area in RULES)


def overrides(root=ROOT):
    path = Path(root) / OVERRIDES
    return json.loads(path.read_text())['classes'] if path.is_file() else {}


def place(owner, root=ROOT, table=None):
    """The area for the class `owner`, or None when no rule or override covers it."""
    table = overrides(root) if table is None else table
    if owner in table:
        return table[owner]
    for pattern, area in COMPILED:
        if pattern.match(owner):
            return area
    return None


def unit_dir(owner, root=ROOT):
    area = place(owner, root)
    if area is not None and area not in AREAS:
        raise ValueError(f'area {area!r} for {owner} is not in unit_paths.AREAS')
    return area


def split_unit_path(name):
    """(area, stem, extension) of `reconstruction/<area>/<stem>.<ext>`, the area being one or more
    lower-case folders, or None for another shape."""
    m = re.fullmatch(r'reconstruction/((?:[a-z][a-z0-9_]*/)*[a-z][a-z0-9_]*)/([A-Za-z0-9_]+)\.(h|cpp)', name)
    return m.groups() if m else None


def area_accepted(area):
    """Whether a new unit may sit in `area`: one of AREAS, a kit folder, or a folder of the earlier layout."""
    return area in AREAS or area in KIT_DIRS or bool(LEGACY_AREA.fullmatch(area))


if __name__ == '__main__':
    for cls in sys.argv[1:]:
        print(f'{cls}: {unit_dir(cls)}')
