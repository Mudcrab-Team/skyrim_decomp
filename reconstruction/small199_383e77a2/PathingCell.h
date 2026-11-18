// Inferred names: GUESS(low)
// Origin: declarations adapted from CommonLibSSE-NG b93280e, MIT; body original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// PathingCell, BSPathingCell, TESObjectCELL, TESForm, TESFullName: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BaseFormComponent, BSSpinLock, cellState, cellFlags, cellGameFlags, formFlags, formID, inGameFormFlags, formType, pad1B, pad1C, sourceFiles, fullName, grassCreateLock, grassTaskLock, _refCount, unk0C, unk10, cellID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetCell, IsAttached: GUESS(low)
#pragma once
#include <cstdint>
class BaseFormComponent { public: virtual ~BaseFormComponent(); };
class TESForm : public BaseFormComponent { public: void* sourceFiles; std::uint32_t formFlags; std::uint32_t formID; std::uint16_t inGameFormFlags; std::uint8_t formType; std::uint8_t pad1B; std::uint32_t pad1C; };
class TESFullName : public BaseFormComponent { public: const char* fullName; };
struct BSSpinLock { std::uint32_t owningThread; std::uint32_t lockCount; };
class TESObjectCELL : public TESForm, public TESFullName { public: BSSpinLock grassCreateLock; BSSpinLock grassTaskLock; std::uint16_t cellFlags; std::uint16_t cellGameFlags; std::uint8_t cellState; };
class BSPathingCell { public: virtual ~BSPathingCell(); std::uint32_t _refCount; std::uint32_t unk0C; };
class PathingCell : public BSPathingCell { public: bool IsAttached(); TESObjectCELL* GetCell(); std::uint32_t unk10; std::uint32_t cellID; };
