// Source exposure: binary-analysis (class names from the image's RTTI; sizes and the inlined destructor body from the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// ArchiveRegistrationTaskData: EXE_RTTI; an anonymous-namespace type of the resource system in the image
// ArchiveRegistrationTaskBase: GUESS(low); the base type, only its out-of-line destructor is modelled
#pragma once

class ArchiveRegistrationTaskBase
{
public:
    ArchiveRegistrationTaskBase();
    virtual ~ArchiveRegistrationTaskBase();

    unsigned char unk08[0x48];  // 08
};

class ArchiveRegistrationTaskData : public ArchiveRegistrationTaskBase
{
public:
    ArchiveRegistrationTaskData();
    ~ArchiveRegistrationTaskData() override {}
};
static_assert(sizeof(ArchiveRegistrationTaskData) == 0x50, "size from the deleting destructor");
