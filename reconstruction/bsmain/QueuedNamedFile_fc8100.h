// Source exposure: binary-analysis (class names from the image's RTTI; sizes and the inlined destructor body from the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// QueuedNamedFile: EXE_RTTI
// QueuedNamedFileBase, QueuedNamedFileName: GUESS(low); the base type and the member type at 0x38, only their out-of-line destructors are modelled
#pragma once

class QueuedNamedFileBase
{
public:
    QueuedNamedFileBase();
    virtual ~QueuedNamedFileBase();

    unsigned char unk08[0x30];  // 08
};

class QueuedNamedFileName
{
public:
    ~QueuedNamedFileName();

    unsigned char unk00[0x8];  // 00
};

class QueuedNamedFile : public QueuedNamedFileBase
{
public:
    QueuedNamedFile();
    ~QueuedNamedFile() override {}

    QueuedNamedFileName unk38;  // 38
};
static_assert(sizeof(QueuedNamedFile) == 0x40, "size from the deleting destructor");
