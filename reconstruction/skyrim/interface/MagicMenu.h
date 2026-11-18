// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GMemoryHeap: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// HeapSlot1, HeapSlot2, HeapSlot3, HeapSlot4, HeapSlot5, HeapSlot6, HeapSlot7, HeapSlot8, HeapSlot9, HeapSlot10, HeapSlot11, GlobalHeap: GUESS(low)
class GMemoryHeap { public: virtual ~GMemoryHeap(); virtual void HeapSlot1(); virtual void HeapSlot2(); virtual void HeapSlot3(); virtual void HeapSlot4(); virtual void HeapSlot5(); virtual void HeapSlot6(); virtual void HeapSlot7(); virtual void HeapSlot8(); virtual void HeapSlot9(); virtual void HeapSlot10(); virtual void HeapSlot11(); virtual void Free(void*); };
extern GMemoryHeap* GlobalHeap;
// MagicMenu: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
#pragma once
#include <cstdint>
#include <cstddef>
class FxDelegateHandler { public: virtual ~FxDelegateHandler(); std::int32_t refCount; };
class IMenu : public FxDelegateHandler { public: ~IMenu() override; void* movie; std::int8_t depth; std::uint32_t flags,inputContext; void* delegate; };
void ReleaseMenuObject(void*,void*,void*);
// TestManaged: GUESS(low); by-value managed-value flag test.
inline bool TestManaged(std::uint32_t flags,std::uint32_t bit) { return ((flags>>bit)&1)!=0; }
struct GFxValue { void* objectInterface; std::uint32_t type; void* value; ~GFxValue() { if(TestManaged(type,6)) { ReleaseMenuObject(objectInterface,this,value); objectInterface=nullptr; } } };
struct InventoryModel { void* itemBase; void* modelObject; void* model; std::uint64_t unknown18; };
struct InventorySmallArray { std::uint32_t capacity; union { InventoryModel* heap; InventoryModel local[7]; }; std::uint32_t count; };
struct InventoryExtra { virtual ~InventoryExtra(); void* data; void* presence; std::uint32_t lockThread,lockCount; };
template <class>
	struct BSTSingletonSDMBase;

	template <class T>
	struct BSTSingletonSDMOpStaticBuffer
	{};

	template <class T, class Alloc = BSTSingletonSDMOpStaticBuffer<T>>
	struct BSTSDMTraits
	{
		using Type = T;
		using Allocator = Alloc;
	};

	template <class Traits>
	struct BSTSingletonSDMBase :
		public Traits,
		public Traits::Allocator
	{
		using Type = typename Traits::Type;
		using Allocator = typename Traits::Allocator;
	};

	template <class T, template <class> class Singleton = BSTSingletonSDMOpStaticBuffer>
	struct BSTSingletonSDM : public BSTSingletonSDMBase<BSTSDMTraits<T, Singleton<T>>>
	{};

// Localized from the published p106 layout headers at 5f41e5eab; their MIT notice is above.
namespace ResearchLayouts {
class BSIntrusiveRefCountedLayout {
public:
    volatile std::uint32_t _refCount;
};
static_assert(sizeof(BSIntrusiveRefCountedLayout) == 4, "community represented size");
static_assert(offsetof(BSIntrusiveRefCountedLayout, _refCount) == 0, "_refCount offset");
}

namespace ResearchLayouts {
class MenuEventHandlerLayout : public BSIntrusiveRefCountedLayout {
public:
    virtual ~MenuEventHandlerLayout();
    bool registered;
    std::uint8_t unk0D;
};
static_assert(sizeof(MenuEventHandlerLayout) == 16, "community represented size");
static_assert(offsetof(MenuEventHandlerLayout, registered) == 12, "registered offset");
static_assert(offsetof(MenuEventHandlerLayout, unk0D) == 13, "unk0D offset");
}

class Inventory3DManager : public BSTSingletonSDM<Inventory3DManager>, public ResearchLayouts::MenuEventHandlerLayout { public: ~Inventory3DManager() override; std::uint8_t unknown11; std::uint16_t unknown12; float positionCopy[3],position[3],scaleCopy,scale; std::uint32_t unknown34; void* tempRef; InventoryExtra originalExtra; InventorySmallArray models; std::uint32_t unknown150; float zoomProgress; void* loadTask; std::uint8_t unknown160,readyForRender,unknown162; };
extern Inventory3DManager* InventoryManager; extern void* BlurManager; extern void* MenuState; void DecrementMenuBlur(void*); void PopMenuHUD(const char*); void FinishMagicMenu(void*,bool);
class MagicMenu : public IMenu { public: MagicMenu(); ~MagicMenu() override; static void operator delete(void* ptr) { GlobalHeap->Free(ptr); } void* itemList; void* itemCard; void* bottomBar; GFxValue root; bool controlsReady; }; static_assert(sizeof(MagicMenu)==0x68,"magic menu size");


static_assert(offsetof(Inventory3DManager,readyForRender)==0x161,"AE inventory render flag");
