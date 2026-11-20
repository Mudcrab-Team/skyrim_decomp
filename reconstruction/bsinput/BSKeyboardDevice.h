// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSKeyboardDevice: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
#pragma once
#include <cstdint>
#include <cstddef>
class BSIInputDevice { public: virtual ~BSIInputDevice() {} virtual void Initialize(); virtual void Process(float); virtual void Release(); virtual void Mapping0(); virtual void Mapping1(); virtual void Mapping2(); virtual bool IsEnabled() const; virtual void Reset(); };
struct ButtonMapTail { ~ButtonMapTail(); std::uint32_t unknown00,capacity,freeCount,good; void* sentinel; std::uint64_t allocatorState; void* entries; };
struct NameMapTail { ~NameMapTail(); std::uint32_t unknown00,capacity,freeCount,good; void* sentinel; std::uint64_t allocatorState; void* entries; };
struct ButtonMap { std::uint64_t unknown00; ButtonMapTail tail; };
struct NameMap { std::uint64_t unknown00; NameMapTail tail; };
class BSInputDevice : public BSIInputDevice { public: ~BSInputDevice() override { ResetButtonMaps(); } void ResetButtonMaps(); std::uint32_t device; ButtonMap deviceButtons; NameMap buttonNameIDMap; };
static_assert(sizeof(BSInputDevice)==0x70,"input device size");
class BSKeyboardDevice : public BSInputDevice { public: BSKeyboardDevice(); ~BSKeyboardDevice() override; }; static_assert(sizeof(BSKeyboardDevice)==0x70,"keyboard device size");
