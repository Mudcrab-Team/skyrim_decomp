// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: minimal declarations from community headers; layout checked against the assigned local pack.
// ExtraSeenData, BSExtraData, SeenData, seenData, next: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once
#include <cstddef>

class SeenData { public: virtual ~SeenData(); };
class BSExtraData {
public:
    virtual ~BSExtraData() {}
    BSExtraData* next;
};
class ExtraSeenData : public BSExtraData {
public:
    // 0x156510 ExtraSeenData::~ExtraSeenData
    virtual ~ExtraSeenData();
    SeenData* seenData; // 0x10
};
static_assert(sizeof(ExtraSeenData) == 0x18, "ExtraSeenData size");
