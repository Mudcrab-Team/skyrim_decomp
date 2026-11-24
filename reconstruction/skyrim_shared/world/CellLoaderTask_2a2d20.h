// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// CellLoaderTask, IOTask: EXE_RTTI
// IOTask: STANDIN EXE_RTTI; only the members and destructors the function needs
#pragma once

class IOTask
{
public:
    IOTask();
    virtual ~IOTask();
};

class CellLoaderTask : public IOTask
{
public:
    CellLoaderTask();
    ~CellLoaderTask() override {}

    char unk08[0x38];
};
static_assert(sizeof(CellLoaderTask) == 0x40, "CellLoaderTask size from the deleting destructor");
