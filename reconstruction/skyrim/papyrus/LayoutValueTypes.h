// Source exposure: community-headers
// Code origin: data-only storage adaptation, no external method bodies.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/{A/ActorValues.h,M/MagicSystem.h,B/BSTList.h,H/hkRefPtr.h,B/BSPointerHandle.h,N/NiPoint3.h,B/BSSoundHandle.h,N/NiSmartPointer.h,B/BSTSmartPointer.h,B/BSTArray.h,M/MaterialIDs.h}; MIT.
// ActorValue, MATERIAL_ID, CastingSource, NiPointer, hkRefPtr, BSSimpleList: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
namespace ResearchLayouts {
struct NiPoint3 { float x; float y; float z; };
static_assert(sizeof(NiPoint3) == 12, "public value storage");
struct ObjectRefHandle { std::uint32_t value; };
static_assert(sizeof(ObjectRefHandle) == 4, "public value storage");
struct ActorHandle { std::uint32_t value; };
static_assert(sizeof(ActorHandle) == 4, "public value storage");
enum class ActorValue : std::int32_t {};
enum class MATERIAL_ID : std::uint32_t {};
namespace MagicSystem { enum class CastingSource : std::int32_t {}; }
template<class T> struct NiPointer { T* value; };
template<class T> struct BSTSmartPointer { T* value; };
template<class T> struct hkRefPtr { T* _ptr; };
template<class T> struct BSSimpleList { struct Node { T item; Node* next; }; Node head; };
struct ArrayAllocatorStorageLayout { void* data; std::uint32_t capacity; };
struct ArrayCountStorageLayout { std::uint32_t size; };
template<class T> struct BSTArray : ArrayAllocatorStorageLayout, ArrayCountStorageLayout {};
static_assert(sizeof(BSTArray<void*>)==24,"public heap-array representation");
static_assert(offsetof(BSTArray<void*>,data)==0,"public allocator pointer");
static_assert(offsetof(BSTArray<void*>,capacity)==8,"public allocator capacity");
static_assert(offsetof(BSTArray<void*>,size)==16,"public array count");
static_assert(offsetof(NiPoint3,x)==0,"public coordinate offset");
static_assert(offsetof(NiPoint3,y)==4,"public coordinate offset");
static_assert(offsetof(NiPoint3,z)==8,"public coordinate offset");
static_assert(offsetof(ObjectRefHandle,value)==0,"public handle storage offset");
static_assert(offsetof(ActorHandle,value)==0,"public handle storage offset");
static_assert(sizeof(ActorValue)==4,"public enum underlying size");
static_assert(sizeof(MATERIAL_ID)==4,"public material enum size");
static_assert(sizeof(MagicSystem::CastingSource)==4,"public casting enum size");
static_assert(sizeof(NiPointer<void>)==8,"public smart pointer storage");
static_assert(offsetof(NiPointer<void>,value)==0,"public smart pointer offset");
using PointerListNodeLayout = BSSimpleList<void*>::Node;
using HandleListNodeLayout = BSSimpleList<ObjectRefHandle>::Node;
static_assert(offsetof(PointerListNodeLayout,item)==0,"public inline node item");
static_assert(offsetof(PointerListNodeLayout,next)==8,"public inline node link");
static_assert(offsetof(HandleListNodeLayout,item)==0,"public inline node handle");
static_assert(offsetof(HandleListNodeLayout,next)==8,"public inline node link");
class LayoutValueTypes {};
static_assert(sizeof(hkRefPtr<void>)==8,"public pointer storage");
static_assert(offsetof(hkRefPtr<void>,_ptr)==0,"public pointer offset");
static_assert(sizeof(BSSimpleList<void*>)==16,"public inline list node");
static_assert(sizeof(BSSimpleList<ObjectRefHandle>)==16,"public inline handle list node");
static_assert(offsetof(BSSimpleList<void*>,head)==0,"public node offset");
}
