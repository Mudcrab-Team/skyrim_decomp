// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xcd2b10 BSAudioManagerThread::~BSAudioManagerThread
// 0xcd1030 BSAudioManagerThread::Unk_01
#include "BSAudioManagerThread.h"
BSAudioManagerThread::BSAudioManagerThread() {}
BSAudioManagerThread::~BSAudioManagerThread() { stopRequested=true; CloseHandle(exitSemaphore); CloseHandle(wakeEvent); }
std::uint32_t BSAudioManagerThread::Unk_01() { if(AudioHeapState!=2) InitializeAudioHeap(&AudioHeapManager,&AudioHeapState); SetAudioHeapName(&AudioHeapManager,AudioHeapName); WaitForSingleObject(wakeEvent,0xffffffff); processing=false; while(stopRequested!=1) { AudioWorkA(AudioManager); Sleep(0); AudioWorkB(AudioManager); Sleep(delay); } ReleaseSemaphore(exitSemaphore,1,nullptr); return 0; }

