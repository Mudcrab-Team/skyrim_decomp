// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// SimpleAnimationGraphManagerHolder, IAnimationGraphManagerHolder, BSAnimationGraphManager, BSTSmartPointer, animationGraphManager, refCount: GUESS(low); selected fields corroborated by target.
/*
MIT License

Copyright (c) 2018 Ryan-rsm-McKenzie

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/
#pragma once
#include <intrin.h>
struct BSAnimationGraphEvent; template<class T> class BSTEventSink { public: virtual ~BSTEventSink(); }; struct BSIntrusiveRefCounted { volatile long refCount; }; class BSAnimationGraphManager: public BSTEventSink<BSAnimationGraphEvent>, public BSIntrusiveRefCounted {};
// Atomic reference counting preserves shared ownership across threads.
template<class T> class BSTSmartPointer { public: T* ptr; BSTSmartPointer& operator=(const BSTSmartPointer& rhs) { T* next=rhs.ptr; T* old=ptr; if(next!=old) { if(next) _InterlockedIncrement(&next->refCount); ptr=next; if(old && _InterlockedDecrement(&old->refCount)==0) delete old; } return *this; } };
class BSFixedString; class NiAVObject; class BSAnimationGraphChannel; class BShkbAnimationGraph; class BSScrapArrayAllocator; template<class T, class Allocator> class BSTArray; template<class T> using BSScrapArray = BSTArray<T, BSScrapArrayAllocator>;
class IAnimationGraphManagerHolder { public: virtual ~IAnimationGraphManagerHolder(); virtual bool NotifyAnimationGraph(const BSFixedString&); virtual bool GetAnimationGraphManagerImpl(BSTSmartPointer<BSAnimationGraphManager>&) const = 0; virtual bool SetAnimationGraphManagerImpl(BSTSmartPointer<BSAnimationGraphManager>&) = 0; virtual bool PopulateGraphNodesToTarget(BSScrapArray<NiAVObject*>&); virtual bool ConstructAnimationGraph(BSTSmartPointer<BShkbAnimationGraph>&) = 0; virtual void Unk_06(); virtual void Unk_07(); virtual bool SetupAnimEventSinks(const BSTSmartPointer<BShkbAnimationGraph>&); virtual void Unk_09(); virtual bool CreateAnimationChannels(BSScrapArray<BSTSmartPointer<BSAnimationGraphChannel>>&); virtual void PostCreateAnimationGraphManager(BSTSmartPointer<BSAnimationGraphManager>&); virtual void Unk_0C(); virtual void PostChangeAnimationManager(const BSTSmartPointer<BShkbAnimationGraph>&, const BSTSmartPointer<BShkbAnimationGraph>&); virtual void Unk_0E(); virtual unsigned int GetGraphVariableCacheSize() const; virtual bool GetGraphVariableImpl1(const BSFixedString&, float&) const; virtual bool GetGraphVariableImpl2(const BSFixedString&, int&) const; virtual bool GetGraphVariableImpl3(const BSFixedString&, bool&) const; }; 
class SimpleAnimationGraphManagerHolder: public IAnimationGraphManagerHolder { public: bool GetAnimationGraphManagerImpl(BSTSmartPointer<BSAnimationGraphManager>&) const override; bool SetAnimationGraphManagerImpl(BSTSmartPointer<BSAnimationGraphManager>&) override; bool ConstructAnimationGraph(BSTSmartPointer<BShkbAnimationGraph>&) override; virtual void Unk_13(); BSTSmartPointer<BSAnimationGraphManager> animationGraphManager; };
