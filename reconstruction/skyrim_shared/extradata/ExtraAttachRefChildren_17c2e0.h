// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSExtraData, ExtraAttachRefChildren, ExtraAttachRefChildren::children, BSExtraData::next: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSSimpleList, ObjectRefHandle: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN; only the destructor the function needs
#pragma once

class ObjectRefHandle
{
public:
    unsigned int native;
};

template <class T>
class BSSimpleList
{
public:
    ~BSSimpleList();

    T item;
    void* next;
};

class BSExtraData
{
public:
    BSExtraData();
    virtual ~BSExtraData() {}

    BSExtraData* next;
};

class ExtraAttachRefChildren : public BSExtraData
{
public:
    ExtraAttachRefChildren();

    BSSimpleList<ObjectRefHandle> children;
};
static_assert(sizeof(ExtraAttachRefChildren) == 0x20, "ExtraAttachRefChildren size from the deleting destructor");
