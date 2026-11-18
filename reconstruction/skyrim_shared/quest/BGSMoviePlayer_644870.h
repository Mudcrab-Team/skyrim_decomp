// Inferred names: GUESS(low)
// Origin: declarations adapted from CommonLibSSE-NG b93280e, MIT; bodies original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSMoviePlayer, MoviePlayer, BSTEventSink, BSTEventSource, BSTArray, BSTArrayBase, BSTArrayHeapAllocator, BSMusicEvent, BSIMusicType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Unk_03, Unk_04, musicType, msgType, kPause, kUnpause, sinks, pendingRegisters, pendingUnregisters, lock, notifying: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// pad51, pad52, pad54, unk08, unk10, unk18, unk20, unk28, unk30, unk38, unk40, unk48, unk50: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once
#include <cstdint>
class InputEvent; class BSIMusicType;
struct BSMusicEvent { enum class MUSIC_MESSAGE_TYPE { kAdd, kRemove, kRemoveImmediate, kPause, kUnpause }; BSIMusicType* musicType; MUSIC_MESSAGE_TYPE msgType; std::uint32_t pad0C; };
class BSTArrayHeapAllocator { public: void* _data; std::uint32_t _capacity; };
class BSTArrayBase { public: std::uint32_t _size; };
template <class T> class BSTArray : public BSTArrayHeapAllocator, public BSTArrayBase {};
struct BSSpinLock { std::uint32_t owningThread, lockCount; };
template <class T> class BSTEventSink { public: virtual ~BSTEventSink(); };
template <class T> class BSTEventSource { public: void SendEvent(const T*); BSTArray<BSTEventSink<T>*> sinks, pendingRegisters, pendingUnregisters; BSSpinLock lock; bool notifying; std::uint8_t pad51; std::uint16_t pad52; std::uint32_t pad54; };
class MoviePlayer { public: virtual ~MoviePlayer(); std::uint64_t unk08, unk10, unk18, unk20, unk28, unk30, unk38, unk40, unk48, unk50; };
class BGSMoviePlayer : public MoviePlayer, public BSTEventSink<InputEvent*>, public BSTEventSource<BSMusicEvent> { public: void Unk_03(); void Unk_04(); };
