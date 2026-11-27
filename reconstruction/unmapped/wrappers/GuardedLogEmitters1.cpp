// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// GuardedLogEmitters1, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
// CI hash: 0x125a220 ?Wrap125a220@GuardedLogEmitters1@@SAXPEAX_NPEBD@Z
// CI hash: 0x125a2a0 ?Wrap125a2a0@GuardedLogEmitters1@@SAXPEAX_NPEBD@Z
// CI hash: 0x125a320 ?Wrap125a320@GuardedLogEmitters1@@SAXPEAX_NPEBD@Z
// CI hash: 0x125a3a0 ?Wrap125a3a0@GuardedLogEmitters1@@SAXPEAX_NPEBD@Z
// CI hash: 0x125a420 ?Wrap125a420@GuardedLogEmitters1@@SAXPEAX_NPEBD@Z
// CI hash: 0x125a4a0 ?Wrap125a4a0@GuardedLogEmitters1@@SAXPEAX_NPEBD@Z
// CI hash: 0x125a520 ?Wrap125a520@GuardedLogEmitters1@@SAXPEAX_NPEBD@Z
// CI hash: 0x1271bd0 ?Wrap1271bd0@GuardedLogEmitters1@@SAXPEAX_NPEBD@Z
// CI hash: 0x1271c50 ?Wrap1271c50@GuardedLogEmitters1@@SAXPEAX_NPEBD@Z
// CI hash: 0x1271cd0 ?Wrap1271cd0@GuardedLogEmitters1@@SAXPEAX_NPEBD@Z
// CI hash: 0x1271d50 ?Wrap1271d50@GuardedLogEmitters1@@SAXPEAX_NPEBD@Z
// CI hash: 0x1271dd0 ?Wrap1271dd0@GuardedLogEmitters1@@SAXPEAX_NPEBD@Z
// CI hash: 0x1271e50 ?Wrap1271e50@GuardedLogEmitters1@@SAXPEAX_NPEBD@Z
// CI hash: 0x1271ed0 ?Wrap1271ed0@GuardedLogEmitters1@@SAXPEAX_NPEBD@Z
// CI hash: 0x1271f50 ?Wrap1271f50@GuardedLogEmitters1@@SAXPEAX_NPEBD@Z
// CI hash: 0x1271fd0 ?Wrap1271fd0@GuardedLogEmitters1@@SAXPEAX_NPEBD@Z
// CI hash: 0x1272050 ?Wrap1272050@GuardedLogEmitters1@@SAXPEAX_NPEBD@Z
// CI hash: 0x12720d0 ?Wrap12720d0@GuardedLogEmitters1@@SAXPEAX_NPEBD@Z
// CI hash: 0x1272150 ?Wrap1272150@GuardedLogEmitters1@@SAXPEAX_NPEBD@Z
// CI hash: 0x12721d0 ?Wrap12721d0@GuardedLogEmitters1@@SAXPEAX_NPEBD@Z
// 0x125a220 GuardedLogEmitters1::Wrap125a220
// 0x125a2a0 GuardedLogEmitters1::Wrap125a2a0
// 0x125a320 GuardedLogEmitters1::Wrap125a320
// 0x125a3a0 GuardedLogEmitters1::Wrap125a3a0
// 0x125a420 GuardedLogEmitters1::Wrap125a420
// 0x125a4a0 GuardedLogEmitters1::Wrap125a4a0
// 0x125a520 GuardedLogEmitters1::Wrap125a520
// 0x1271bd0 GuardedLogEmitters1::Wrap1271bd0
// 0x1271c50 GuardedLogEmitters1::Wrap1271c50
// 0x1271cd0 GuardedLogEmitters1::Wrap1271cd0
// 0x1271d50 GuardedLogEmitters1::Wrap1271d50
// 0x1271dd0 GuardedLogEmitters1::Wrap1271dd0
// 0x1271e50 GuardedLogEmitters1::Wrap1271e50
// 0x1271ed0 GuardedLogEmitters1::Wrap1271ed0
// 0x1271f50 GuardedLogEmitters1::Wrap1271f50
// 0x1271fd0 GuardedLogEmitters1::Wrap1271fd0
// 0x1272050 GuardedLogEmitters1::Wrap1272050
// 0x12720d0 GuardedLogEmitters1::Wrap12720d0
// 0x1272150 GuardedLogEmitters1::Wrap1272150
// 0x12721d0 GuardedLogEmitters1::Wrap12721d0
#include "GuardedLogEmitters1.h"

void GuardedLogEmitters1::Wrap125a220(void* unused, bool ok, const char* msg)
{
    (void)unused;
    if (!ok)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, msg);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, msg);
            }
        }
    }
}

void GuardedLogEmitters1::Wrap125a2a0(void* unused, bool ok, const char* msg)
{
    (void)unused;
    if (!ok)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, msg);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, msg);
            }
        }
    }
}

void GuardedLogEmitters1::Wrap125a320(void* unused, bool ok, const char* msg)
{
    (void)unused;
    if (!ok)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, msg);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, msg);
            }
        }
    }
}

void GuardedLogEmitters1::Wrap125a3a0(void* unused, bool ok, const char* msg)
{
    (void)unused;
    if (!ok)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, msg);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, msg);
            }
        }
    }
}

void GuardedLogEmitters1::Wrap125a420(void* unused, bool ok, const char* msg)
{
    (void)unused;
    if (!ok)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, msg);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, msg);
            }
        }
    }
}

void GuardedLogEmitters1::Wrap125a4a0(void* unused, bool ok, const char* msg)
{
    (void)unused;
    if (!ok)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, msg);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, msg);
            }
        }
    }
}

void GuardedLogEmitters1::Wrap125a520(void* unused, bool ok, const char* msg)
{
    (void)unused;
    if (!ok)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, msg);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, msg);
            }
        }
    }
}

void GuardedLogEmitters1::Wrap1271bd0(void* unused, bool ok, const char* msg)
{
    (void)unused;
    if (!ok)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, msg);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, msg);
            }
        }
    }
}

void GuardedLogEmitters1::Wrap1271c50(void* unused, bool ok, const char* msg)
{
    (void)unused;
    if (!ok)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, msg);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, msg);
            }
        }
    }
}

void GuardedLogEmitters1::Wrap1271cd0(void* unused, bool ok, const char* msg)
{
    (void)unused;
    if (!ok)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, msg);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, msg);
            }
        }
    }
}

void GuardedLogEmitters1::Wrap1271d50(void* unused, bool ok, const char* msg)
{
    (void)unused;
    if (!ok)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, msg);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, msg);
            }
        }
    }
}

void GuardedLogEmitters1::Wrap1271dd0(void* unused, bool ok, const char* msg)
{
    (void)unused;
    if (!ok)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, msg);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, msg);
            }
        }
    }
}

void GuardedLogEmitters1::Wrap1271e50(void* unused, bool ok, const char* msg)
{
    (void)unused;
    if (!ok)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, msg);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, msg);
            }
        }
    }
}

void GuardedLogEmitters1::Wrap1271ed0(void* unused, bool ok, const char* msg)
{
    (void)unused;
    if (!ok)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, msg);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, msg);
            }
        }
    }
}

void GuardedLogEmitters1::Wrap1271f50(void* unused, bool ok, const char* msg)
{
    (void)unused;
    if (!ok)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, msg);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, msg);
            }
        }
    }
}

void GuardedLogEmitters1::Wrap1271fd0(void* unused, bool ok, const char* msg)
{
    (void)unused;
    if (!ok)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, msg);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, msg);
            }
        }
    }
}

void GuardedLogEmitters1::Wrap1272050(void* unused, bool ok, const char* msg)
{
    (void)unused;
    if (!ok)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, msg);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, msg);
            }
        }
    }
}

void GuardedLogEmitters1::Wrap12720d0(void* unused, bool ok, const char* msg)
{
    (void)unused;
    if (!ok)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, msg);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, msg);
            }
        }
    }
}

void GuardedLogEmitters1::Wrap1272150(void* unused, bool ok, const char* msg)
{
    (void)unused;
    if (!ok)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, msg);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, msg);
            }
        }
    }
}

void GuardedLogEmitters1::Wrap12721d0(void* unused, bool ok, const char* msg)
{
    (void)unused;
    if (!ok)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, msg);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, msg);
            }
        }
    }
}
