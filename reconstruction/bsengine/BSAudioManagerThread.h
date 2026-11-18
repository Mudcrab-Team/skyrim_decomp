// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSAudioManagerThread: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
#pragma once
#include <cstdint>
#include <cstddef>
struct ThreadCriticalSection { void* debugInfo; std::int32_t lockCount,recursionCount; void* owningThread; void* lockSemaphore; std::uintptr_t spinCount; };
class BSThread { public: virtual ~BSThread(); virtual std::uint32_t Unk_01(); virtual void Unk_02(); ThreadCriticalSection lock; void* thread; void* ownerThread; std::uint32_t threadID,ownerThreadID; bool initialized; };
class BSAudioManagerThread : public BSThread { public: BSAudioManagerThread(); ~BSAudioManagerThread() override; std::uint32_t Unk_01() override; void* wakeEvent; void* exitSemaphore; bool stopRequested,processing; std::uint16_t unknown62; std::uint32_t delay; };
static_assert(sizeof(BSAudioManagerThread)==0x68,"audio thread size");
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
extern "C" __declspec(dllimport) std::uint32_t __stdcall WaitForSingleObject(void*,std::uint32_t);
extern "C" __declspec(dllimport) void __stdcall Sleep(std::uint32_t);
extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void*,std::int32_t,std::int32_t*);
extern std::uint32_t AudioHeapState; extern std::uint64_t AudioHeapManager; extern const char AudioHeapName[]; extern void* AudioManager;
void InitializeAudioHeap(void*,std::uint32_t*); void SetAudioHeapName(void*,const char*); void AudioWorkA(void*); void AudioWorkB(void*);

