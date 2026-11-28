// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// GFxLog, LogScriptError: CRASHLOGGER_PDB(59818@2026.10.24)
// GFxState, GFxLogBase, LogMessageVarg, unk08: GUESS(low) STANDIN
#pragma once

#include <cstdarg>
#include <cstdint>

class GFxState
{
public:
    virtual ~GFxState();
    virtual void LogMessageVarg(std::uint32_t messageType, const char* fmt, std::va_list argList);  // 08

    std::uint8_t unk08[0x10];  // 08
};
static_assert(sizeof(GFxState) == 0x18, "GFxState size");

template <class Derived>
class GFxLogBase
{
public:
    virtual ~GFxLogBase();

    void LogScriptError(const char* fmt, ...);
};

class GFxLog : public GFxState, public GFxLogBase<GFxLog>
{
public:
};
static_assert(sizeof(GFxLog) == 0x20, "GFxLog size");
