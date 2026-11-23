// Source exposure: mixed (binary-analysis, community-headers).
// Community source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT.
// Array storage, indexed search, append and removal reconstructed from the selected build.
// LockedArray_770a60, Sink, Event, ArrayFunctor, ArrayStorage, ArrayBase, Lock, Guard: GUESS(low) STANDIN
// Add, Remove, Push, Find, At, Erase, EraseExternal, Reserve, Move, Allocate, Reallocate, Deallocate, Unlock: GUESS(low)
// data, capacity, size, array, owner, count, sinks, pendingRegisters, pendingUnregisters, lock, notifying, ProcessEvent: GUESS(low)
// GetCurrentThreadId: OBSERVED
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <new>
namespace p117_770a60 {
struct Event;
class LockedSource_F063_770a60;
struct Sink { virtual ~Sink(); virtual unsigned ProcessEvent(const Event*, LockedSource_F063_770a60*)=0; };
struct ArrayFunctor {
 virtual bool Allocate(unsigned,unsigned);
 virtual bool Reallocate(unsigned,unsigned,unsigned,unsigned,unsigned);
 virtual void Deallocate();
 virtual ~ArrayFunctor() {}
 void* array;
 explicit ArrayFunctor(void* object) : array(object) {}
};
struct ArrayBase { unsigned size; void Move(void*,unsigned,unsigned,unsigned,unsigned); unsigned Reserve(ArrayFunctor&&,unsigned,unsigned); };
template<class T> struct ArrayStorage { T* data; unsigned capacity; };
template<class T> inline void Construct(T* destination,const T& value) { ::new(static_cast<void*>(destination)) T(value); }
template<class T> struct LockedArray_770a60 : ArrayStorage<T>, ArrayBase {
 unsigned Find(const T& value) const {
  unsigned found=~0u; unsigned count=this->size;
  for(unsigned i=0;i<count;++i) { if(found!=~0u) break; auto* entries=this->data; const unsigned index=i; if(entries[index]==value) found=index; }
  return found;
 }
 T& At(unsigned index) const { return this->data[index]; }
 // noinline: The selected append has its own body at the independently extracted append RVA; retain that call boundary while comparing it separately.
 __declspec(noinline) void Push(const T& value) {
  unsigned index=Reserve(ArrayFunctor(this),this->capacity,sizeof(T));
  if(index!=~0u) Construct(this->data+index,value);
 }
 void Erase(unsigned index,unsigned amount=1) {
  unsigned remaining=this->size-index-amount;
  unsigned moved=remaining<amount?remaining:amount;
  Move(this->data,index,this->size-moved,moved,sizeof(T)); this->size-=amount;
 }
 void EraseExternal(unsigned,unsigned);
 T* begin() { return this->size?this->data:nullptr; }
 T* end() { return this->size?this->data+this->size:nullptr; }
 void Clear() { if(this->data) this->size=0; }
};
static_assert(sizeof(LockedArray_770a60<Sink*>)==0x18,"pointer array stride");
}
