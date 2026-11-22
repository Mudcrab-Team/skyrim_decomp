// Source exposure: mixed (pinned image listing, sibling hint, community declarations).
// Code origin: existing sibling-adapted methods plus original reconstruction of Function5564e0.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SimpleAnimationGraphManagerHolder, IAnimationGraphManagerHolder, BSAnimationGraphManager, BSTSmartPointer, animationGraphManager, loadingTask: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// refCount, Function5564e0, unknown10, state2C8: GUESS(low)
#pragma once
#include <cstdint>
#include <intrin.h>
struct BSAnimationGraphEvent;
template<class T> class BSTEventSink { public: virtual ~BSTEventSink(); };
struct BSIntrusiveRefCounted { volatile long refCount; };
class BSAnimationGraphManager : public BSTEventSink<BSAnimationGraphEvent>, public BSIntrusiveRefCounted {
public:
    std::uint8_t unknown10[0x2B8];
    std::uint32_t state2C8;
};
// Atomic reference counting preserves shared ownership across threads.
template<class T> class BSTSmartPointer { public: T* ptr; BSTSmartPointer& operator=(const BSTSmartPointer& rhs) { T* next=rhs.ptr; T* old=ptr; if(next!=old) { if(next) _InterlockedIncrement(&next->refCount); ptr=next; if(old && _InterlockedDecrement(&old->refCount)==0) delete old; } return *this; } };
class BSFixedString; class NiAVObject; class BSAnimationGraphChannel; class BShkbAnimationGraph; class BSScrapArrayAllocator; template<class T, class Allocator> class BSTArray; template<class T> using BSScrapArray = BSTArray<T, BSScrapArrayAllocator>;
class IAnimationGraphManagerHolder { public: virtual ~IAnimationGraphManagerHolder(); virtual bool NotifyAnimationGraph(const BSFixedString&); virtual bool GetAnimationGraphManagerImpl(BSTSmartPointer<BSAnimationGraphManager>&) const = 0; virtual bool SetAnimationGraphManagerImpl(BSTSmartPointer<BSAnimationGraphManager>&) = 0; virtual bool PopulateGraphNodesToTarget(BSScrapArray<NiAVObject*>&); virtual bool ConstructAnimationGraph(BSTSmartPointer<BShkbAnimationGraph>&) = 0; virtual void Unk_06(); virtual void Unk_07(); virtual bool SetupAnimEventSinks(const BSTSmartPointer<BShkbAnimationGraph>&); virtual void Unk_09(); virtual bool CreateAnimationChannels(BSScrapArray<BSTSmartPointer<BSAnimationGraphChannel>>&); virtual void PostCreateAnimationGraphManager(BSTSmartPointer<BSAnimationGraphManager>&); virtual void Unk_0C(); virtual void PostChangeAnimationManager(const BSTSmartPointer<BShkbAnimationGraph>&, const BSTSmartPointer<BShkbAnimationGraph>&); virtual void Unk_0E(); virtual unsigned int GetGraphVariableCacheSize() const; virtual bool GetGraphVariableImpl1(const BSFixedString&, float&) const; virtual bool GetGraphVariableImpl2(const BSFixedString&, int&) const; virtual bool GetGraphVariableImpl3(const BSFixedString&, bool&) const; };
class SimpleAnimationGraphManagerLoadingTask {
public:
    std::uint8_t unknown00[0x2C8];
    std::uint32_t state2C8;
};
class SimpleAnimationGraphManagerHolder : public IAnimationGraphManagerHolder {
public:
    bool GetAnimationGraphManagerImpl(BSTSmartPointer<BSAnimationGraphManager>&) const override;
    bool SetAnimationGraphManagerImpl(BSTSmartPointer<BSAnimationGraphManager>&) override;
    bool ConstructAnimationGraph(BSTSmartPointer<BShkbAnimationGraph>&) override;
    virtual void Unk_13();
    bool Function5564e0() const;
    BSTSmartPointer<BSAnimationGraphManager> animationGraphManager;
    SimpleAnimationGraphManagerLoadingTask* loadingTask;
};
