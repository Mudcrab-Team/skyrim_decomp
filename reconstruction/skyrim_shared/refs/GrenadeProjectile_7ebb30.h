// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// GrenadeProjectile::Process3D: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/GrenadeProjectile.cpp:47
// GrenadeProjectile, Projectile, TESObjectREFR: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/G/GrenadeProjectile.h, include/RE/P/Projectile.h, include/RE/T/TESObjectREFR.h, include/RE/E/ExtraDataList.h, include/RE/N/NiTransform.h and include/RE/B/BSSoundHandle.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
struct Point3 { float x,y,z; }; struct Matrix3 { float value[3][3]; }; struct Transform { Matrix3 rotation; Point3 translation; float scale; };
class Component { public: virtual ~Component(); virtual void InitializeDataComponent(); virtual void ClearDataComponent(); virtual void CopyComponent(Component*); };
#include <cstdint>
class BSFixedString; struct FORM; struct FORM_GROUP; class TESBoundObject; using FormID = std::uint32_t; class TESFile; class BGSSaveFormBuffer; class BGSLoadFormBuffer; class TESObjectREFR; enum class FormType : unsigned char;
class TESForm : public Component { public:
virtual void                               InitializeData();
virtual void                               ClearData();
virtual bool                               Load(TESFile* a_mod);
virtual bool                               LoadPartial(TESFile* a_mod);
virtual bool                               LoadEdit(TESFile* a_mod);
virtual TESForm*                           CreateDuplicateForm(bool a_createEditorID, void* a_arg2);
virtual bool                               AddChange(std::uint32_t a_changeFlags);
virtual void                               RemoveChange(std::uint32_t a_changeFlags);
virtual bool                               FindInFileFast(TESFile* a_mod);
virtual bool                               CheckSaveGame(BGSSaveFormBuffer* a_buf);
virtual void                               SaveGame(BGSSaveFormBuffer* a_buf);
virtual void                               LoadGame(BGSLoadFormBuffer* a_buf);
virtual void                               InitLoadGame(BGSLoadFormBuffer* a_buf);
virtual void                               FinishLoadGame(BGSLoadFormBuffer* a_buf);
virtual void                               Revert(BGSLoadFormBuffer* a_buf);
virtual void                               InitItemImpl();
virtual TESFile*             GetDescriptionOwnerFile() const;
virtual FormType             GetSavedFormType() const;
virtual void                               GetFormDetailedString(char* a_buf, std::uint32_t a_bufLen);
virtual bool                 GetKnown() const;
virtual bool                 GetRandomAnim() const;
virtual bool                 GetPlayable() const;
virtual bool                 IsHeadingMarker() const;
virtual bool                 GetDangerous() const;
virtual bool                 QHasCurrents() const;
virtual bool                 GetObstacle() const;
virtual bool                 QIsLODLandObject() const;
virtual bool                 GetOnLocalMap() const;
virtual bool                 GetMustUpdate() const;
virtual void                               SetOnLocalMap(bool a_set);
virtual bool                 GetIgnoredBySandbox() const;
virtual void                               SetDelete(bool a_set);
virtual void                               SetAltered(bool a_set);
virtual void                               SaveObjectBound();
virtual void                               LoadObjectBound(TESFile* a_mod);
virtual bool                 IsBoundObject() const;
virtual bool                 IsObject() const;
virtual bool                 IsMagicItem() const;
virtual bool                 IsWater() const;
virtual TESObjectREFR*                     AsReference1();
virtual const TESObjectREFR* AsReference2() const;
virtual std::uint32_t        GetRefCount() const;
virtual const char*          GetTextForParsedSubTag(const BSFixedString& a_tag) const;
virtual void                               Copy(TESForm* a_srcForm);
virtual bool                               BelongsInGroup(FORM* a_form, bool a_allowParentGroups, bool a_currentOnly);
virtual void                               CreateGroupData(FORM* a_form, FORM_GROUP* a_group);
virtual const char*          GetFormEditorID() const;
virtual bool                               SetFormEditorID(const char* a_str);
virtual bool                               IsParentForm();
virtual bool                               IsParentFormTree();
virtual bool                               IsFormTypeChild(FormType a_type);
virtual bool                               Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, std::uint8_t a_arg3, TESBoundObject* a_object, std::int32_t a_targetCount);
virtual void                               SetFormID(FormID a_id, bool a_updateFile);
virtual const char*          GetObjectTypeName() const;
virtual bool                 QAvailableInGame() const;
 void* files; unsigned formFlags, id; unsigned short inGameFlags; unsigned char type, pad; unsigned pad2;
};

class NiRefObject { public: virtual ~NiRefObject(); unsigned refCount, pad; };
class BSHandleRefObject : public NiRefObject {};
class EventSink { public: virtual ~EventSink(); };
class AnimationHolder { public: virtual ~AnimationHolder(); };
struct ObjectReference { void* object; Point3 angle, location; };
class BaseExtraList { public: virtual ~BaseExtraList(); void* data; void* presence; };
struct Lock { unsigned owner, count; };
struct ExtraDataList { BaseExtraList data; Lock lock; };
class BGSLocation; class NiPoint3; class TESObjectCELL; class TESTopicInfo; class BGSAnimationSequencer; class BGSKeyword; class TESPackage; class BGSScene; class DialogueResponse; class BGSDialogueBranch; class ActorCause; class ObjectRefHandle; enum class ITEM_REMOVE_REASON : int; class ExtraDataList; class TrapData; class TrapEntry; class TargetEntry; class MagicCaster; class MagicTarget; class TESActorBase; class BSFaceGenNiNode; class BSFaceGenAnimationData; class NiAVObject;
namespace MagicSystem { enum class CastingSource : int; }
class TESObjectREFR : public TESForm, public BSHandleRefObject, public EventSink, public AnimationHolder { public:
virtual void                                            Predestroy();
virtual BGSLocation*                      GetEditorLocation1() const;
virtual bool                                            GetEditorLocation2(NiPoint3& a_outPos, NiPoint3& a_outRot, TESForm*& a_outWorldOrCell, TESObjectCELL* a_fallback);
virtual void                                            ForceEditorLocation(BGSLocation* a_location);
virtual void                                            Update3DPosition(bool a_warp);
virtual void                                            UpdateSoundCallBack(bool a_endSceneAction);
virtual bool                                            SetDialogueWithPlayer(bool a_flag, bool a_forceGreet, TESTopicInfo* a_topic);
virtual void                                            DamageObject(float a_objectHealth, bool a_arg3);
virtual bool                              GetFullLODRef() const;
virtual void                                            SetFullLODRef(bool a_set);
virtual BGSAnimationSequencer*            GetSequencer() const;
virtual bool                              QCanUpdateSync() const;
virtual bool                              GetAllowPromoteToPersistent() const;
virtual bool                              HasKeywordHelper(const BGSKeyword* a_keyword) const;
virtual TESPackage*                       CheckForCurrentAliasPackage();
virtual BGSScene*                         GetCurrentScene() const;
virtual void                                            SetCurrentScene(BGSScene* a_scene);
virtual bool                                            UpdateInDialogue(DialogueResponse* a_response, bool a_unused);
virtual BGSDialogueBranch*                GetExclusiveBranch() const;
virtual void                                            SetExclusiveBranch(BGSDialogueBranch* a_branch);
virtual void                                            PauseCurrentDialogue();
virtual void                                            SetActorCause(ActorCause* a_cause);
virtual ActorCause*                       GetActorCause() const;
virtual NiPoint3                          GetStartingAngle() const;
virtual NiPoint3                          GetStartingLocation() const;
virtual void                                            SetStartingPosition(const NiPoint3& a_pos);
virtual void                                            UpdateRefLight();
virtual ObjectRefHandle                                 RemoveItem(TESBoundObject* a_item, std::int32_t a_count, ITEM_REMOVE_REASON a_reason, ExtraDataList* a_extraList, TESObjectREFR* a_moveToRef, const NiPoint3* a_dropLoc = 0, const NiPoint3* a_rotate = 0);
virtual bool                                            AddWornItem(TESBoundObject* a_item, std::int32_t a_count, bool a_forceEquip, std::uint32_t a_arg4, std::uint32_t a_arg5);
virtual void                                            DoTrap1(TrapData& a_data);
virtual void                                            DoTrap2(TrapEntry* a_trap, TargetEntry* a_target);
virtual void                                            AddObjectToContainer(TESBoundObject* a_object, ExtraDataList* a_extraList, std::int32_t a_count, TESObjectREFR* a_fromRefr);
virtual NiPoint3                          GetLookingAtLocation() const;
virtual MagicCaster*                      GetMagicCaster(MagicSystem::CastingSource a_source);
virtual MagicTarget*                      GetMagicTarget();
virtual bool                              IsChild() const;
virtual TESActorBase*                                   GetTemplateActorBase();
virtual void                                            SetTemplateActorBase(TESActorBase* a_template);
virtual BSFaceGenNiNode*                  GetFaceNodeSkinned();
virtual BSFaceGenNiNode*                  GetFaceNode();
virtual BSFaceGenAnimationData*           GetFaceGenAnimationData();
virtual bool                                            ClampToGround();
virtual bool                                            DetachHavok(NiAVObject* a_obj3D);
virtual void                                            InitHavok();
virtual void                                            Unk_67(void);
virtual void                                            Unk_68(void);
virtual void                                            Unk_69(void);
virtual NiAVObject*                                     Load3D(bool a_backgroundLoading);
virtual void                                            Release3DRelatedData();
virtual void                                            Set3D(NiAVObject* a_object, bool a_queue3DTasks = true);
virtual bool                                            ShouldBackgroundClone() const;
virtual void                                            Unk_6E(void);
virtual NiAVObject*                       Get3D1(bool a_firstPerson) const;
virtual NiAVObject*                       Get3D2() const;
 ObjectReference data; void* parentCell; void* loadedData; ExtraDataList extraList; unsigned long long unknown90; unsigned short refScale; signed char modelState; bool preDestroyed; unsigned pad9c;
};

struct List { void* item; void* next; };
struct SoundHandle { unsigned id; bool success; unsigned char pad; unsigned short pad2; unsigned state; };
class LoadBuffer; class SaveBuffer;
class Projectile : public TESObjectREFR { public:
 List impacts; Transform transform; float unknownE4; void* phantom; Lock lock; Point3 velocity, linearVelocity; void* light; void* unknown118; void* actorCause; unsigned shooter, desiredTarget; SoundHandle sound, countdown; unsigned* unknown148; void* inventoryEntry; void* explosion; void* spell; unsigned castingSource, pad16c; void* effectSetting; void* projectileDBFiles; unsigned long long unknown180, unknown188; float power, speedMult, range, livingTime, weaponDamage, transparency, explosionTimer; unsigned unknown1ac; float unknown1b0, unknown1b4; void* weaponSource; void* ammoSource; float distanceMoved; unsigned unknown1cc; float scale; unsigned flags; bool unknown1d8, unknown1d9; unsigned char unknown1da[6];
 void Revert(LoadBuffer*); void SaveGame(SaveBuffer*); void LoadGame(LoadBuffer*); void FinishLoadGame(LoadBuffer*);
};
class DecalGroup { public: void SaveGame(SaveBuffer*); void LoadGame(LoadBuffer*); void FinishLoadGame(); };
class GrenadeProjectile : public Projectile { public: DecalGroup* decalGroup; bool collisionGroupReset; void Revert(LoadBuffer*); void SaveGame(SaveBuffer*); void LoadGame(LoadBuffer*); void FinishLoadGame(LoadBuffer*); void Track(); void Process3D(); void SetLightState(NiAVObject*, bool); };
