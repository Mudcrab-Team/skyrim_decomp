// Source exposure: mixed (community headers; the pinned image listing).
// Sibling source: fo4-private@1b765c70 src/Shared/AI/BGSPackageDataRef.cpp:135
// BGSPackageDataRef::RemapInterruptData: SIBLING(fo4-private@1b765c70, author-permission); the Skyrim slot is the sixth of the IPackageData chain
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSPackageDataRef: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI STANDIN
// PACK_INTERRUPT_TARGET: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN; only the underlying width is used
// PACK_INTERRUPT_LOCATION: GUESS(low); only the underlying width is used
// BGSPackageTargetData, BGSPackageTargetData::GetTargType, BGSPackageTargetData::GetTargInterruptData, BGSPackageTargetData::SetTargType, BGSPackageTargetData::SetTargReference: GUESS(low); the method names are the ones the sibling body calls, the class name is invented
// BGSPackageDataRef::pointer, PointerHandleCopy: GUESS(low)
#pragma once

#include <cstdint>

enum class PACK_INTERRUPT_TARGET : std::int32_t
{
    kNone = -1
};

enum class PACK_INTERRUPT_LOCATION : std::int32_t
{
    kNone = -1
};

class PointerHandleCopy
{
public:
    PointerHandleCopy(const PointerHandleCopy& a_other) :
        id(a_other.id)
    {}

    std::uint32_t id;
};

class BGSPackageTargetData
{
public:
    std::int32_t GetTargType() const;
    std::int32_t GetTargInterruptData() const;
    void SetTargType(std::int32_t a_type);
    void SetTargReference(PointerHandleCopy a_ref);
};

class BGSPackageDataRef
{
public:
    virtual ~BGSPackageDataRef();
    virtual void RemapInterruptData(PACK_INTERRUPT_TARGET a_target, PACK_INTERRUPT_LOCATION a_location, PointerHandleCopy a_ref);

    std::uint64_t unknown08;      // 08
    BGSPackageTargetData* pointer;  // 10
};
