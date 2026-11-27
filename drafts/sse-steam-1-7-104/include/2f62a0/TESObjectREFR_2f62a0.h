// Exposure detail: (community declarations and pinned-image observations).
// Source exposure: mixed
// Code origin: original; compact views of fields used by the query
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectREFR, TESBoundObject, TESObjectSTAT, FormType, Static, formType, data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// OBJ_REFR, OBJ_REFR::objectReference: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESBoundObject, TESObjectREFR: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); fields used by this query only
// TESObjectSTAT::QIsSkyObject: CRASHLOGGER_PDB(59818@2026.10.24)
// TESObjectREFR::Function2f62a0: GUESS(low); unknown query name

#pragma once
#include <cstdint>
#include <cstddef>

enum class FormType : std::uint8_t { Static = 34 };

class TESBoundObject
{
public:
    std::uint8_t formPrefix[0x1A];
    FormType formType;
};

class TESObjectSTAT : public TESBoundObject
{
public:
    bool QIsSkyObject() const;
};

struct OBJ_REFR
{
    TESBoundObject* objectReference;
};

class TESObjectREFR
{
public:
    bool Function2f62a0() const;
    std::uint8_t referencePrefix[0x40];
    OBJ_REFR data;
};
static_assert(offsetof(TESBoundObject, formType) == 0x1A, "formType offset");
static_assert(offsetof(TESObjectREFR, data) == 0x40, "reference data offset");
