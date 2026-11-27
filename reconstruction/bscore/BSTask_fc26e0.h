// Source exposure: mixed (community headers, pinned image, image RTTI and the 2013 map).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Code origin: class declaration follows powerof3/CommonLibSSE; size checked against the pinned image.
// BSTask: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0) EXE_RTTI
// BSTask::~BSTask: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// BSTask::Run: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// BSTask::Finish: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// BSTask::Cancel: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// BSTask::GetDescription: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// BSTask::GetDescription: SYMBOLS(tesv-2013-map)
// BSTask::refCount: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// BSTask::unk0C: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// BSTask::unk10: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
#pragma once
#include <cstdint>

class BSTask
{
public:
    virtual ~BSTask();                                                    // 00
    virtual void Run() = 0;                                               // 01
    virtual void Finish() = 0;                                            // 02
    virtual void Cancel(std::uint32_t a_previousState, void* a_unk);      // 03
    virtual bool GetDescription(char* a_dest, std::uint32_t a_maxCount);  // 04

    // volatile: the community header declares the task reference count volatile; it is shared between threads.
    volatile std::int32_t refCount;  // 08
    std::uint32_t         unk0C;     // 0C
    std::uint64_t         unk10;     // 10
};
static_assert(sizeof(BSTask) == 0x18, "size differs from the pinned constructor");
