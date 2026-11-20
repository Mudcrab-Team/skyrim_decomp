// Origin: adapted declarations from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// BGSScene: EXE_RTTI
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
// BGSScene, TESForm, BaseFormComponent, TESFileContainer, TESFileArray, BSTArray, BGSScenePhase, BGSSceneAction, phases, actors, actorFlags, actorProgressionFlags, actions: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Function3a8980, SceneVisitor, Apply, scene, arg, value: GUESS(low)
class TESFileArray; class BGSScenePhase; class BGSSceneAction;
enum class SCENE_ACTOR_FLAG : std::uint32_t;
enum class FormType : std::uint8_t;
namespace stl { template<class E, class T> struct enumeration { T value; }; }
struct TESFileContainer { TESFileArray* array; };
class BaseFormComponent { public: virtual ~BaseFormComponent(); };
class TESForm : public BaseFormComponent {
public:
 enum class InGameFormFlag : std::uint16_t;
 TESFileContainer sourceFiles;
 std::uint32_t formFlags, formID;
 stl::enumeration<InGameFormFlag, std::uint16_t> inGameFormFlags;
 stl::enumeration<FormType, std::uint8_t> formType;
 std::uint8_t pad1B;
 std::uint32_t pad1C;
};
struct SceneVisitor;
struct BSTArrayHeapAllocator { void* data; std::uint32_t capacity; };
struct BSTArrayBase { std::uint32_t size; };
template<class T> class BSTArray : public BSTArrayHeapAllocator, public BSTArrayBase { public: void Apply(SceneVisitor* visitor); };
class BGSScene : public TESForm {
public:
 enum class BehaviourFlag : std::uint32_t;
 void Function3a8980(void* arg, std::uint32_t value);
 BSTArray<BGSScenePhase*> phases;
 BSTArray<std::uint32_t> actors;
 BSTArray<stl::enumeration<SCENE_ACTOR_FLAG, std::uint32_t>> actorFlags;
 BSTArray<stl::enumeration<BehaviourFlag, std::uint32_t>> actorProgressionFlags;
 BSTArray<BGSSceneAction*> actions;
};
struct SceneVisitor { BGSScene* scene; void* arg; std::uint32_t value; };
