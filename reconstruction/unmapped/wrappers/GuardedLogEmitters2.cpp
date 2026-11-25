// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// GuardedLogEmitters2, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
// CI hash: 0x1272250 ?Wrap1272250@GuardedLogEmitters2@@SAXPEAX_NPEBD@Z
// CI hash: 0x12722d0 ?Wrap12722d0@GuardedLogEmitters2@@SAXPEAX_NPEBD@Z
// CI hash: 0x1283470 ?Wrap1283470@GuardedLogEmitters2@@SAXPEAX_NPEBD@Z
// CI hash: 0x128f9d0 ?Wrap128f9d0@GuardedLogEmitters2@@SAXPEAX_NPEBD@Z
// CI hash: 0x12ae2a0 ?Wrap12ae2a0@GuardedLogEmitters2@@SAXPEAX_NPEBD@Z
// CI hash: 0x12d28f0 ?Wrap12d28f0@GuardedLogEmitters2@@SAXPEAX_NPEBD@Z
// CI hash: 0x12d2970 ?Wrap12d2970@GuardedLogEmitters2@@SAXPEAX_NPEBD@Z
// CI hash: 0x12de130 ?Wrap12de130@GuardedLogEmitters2@@SAXPEAX_NPEBD@Z
// CI hash: 0x12de1b0 ?Wrap12de1b0@GuardedLogEmitters2@@SAXPEAX_NPEBD@Z
// CI hash: 0x12de230 ?Wrap12de230@GuardedLogEmitters2@@SAXPEAX_NPEBD@Z
// CI hash: 0x12fb4a0 ?Wrap12fb4a0@GuardedLogEmitters2@@SAXPEAX_NPEBD@Z
// CI hash: 0x1300da0 ?Wrap1300da0@GuardedLogEmitters2@@SAXPEAX_NPEBD@Z
// CI hash: 0x1300e20 ?Wrap1300e20@GuardedLogEmitters2@@SAXPEAX_NPEBD@Z
// CI hash: 0x1304bd0 ?Wrap1304bd0@GuardedLogEmitters2@@SAXPEAX_NPEBD@Z
// CI hash: 0x1308420 ?Wrap1308420@GuardedLogEmitters2@@SAXPEAX_NPEBD@Z
// CI hash: 0x1318770 ?Wrap1318770@GuardedLogEmitters2@@SAXPEAX_NPEBD@Z
// CI hash: 0x131b190 ?Wrap131b190@GuardedLogEmitters2@@SAXPEAX_NPEBD@Z
// CI hash: 0x131b210 ?Wrap131b210@GuardedLogEmitters2@@SAXPEAX_NPEBD@Z
// CI hash: 0x1347570 ?Wrap1347570@GuardedLogEmitters2@@SAXPEAX_NPEBD@Z
// CI hash: 0x134a9a0 ?Wrap134a9a0@GuardedLogEmitters2@@SAXPEAX_NPEBD@Z
// 0x1272250 GuardedLogEmitters2::Wrap1272250
// 0x12722d0 GuardedLogEmitters2::Wrap12722d0
// 0x1283470 GuardedLogEmitters2::Wrap1283470
// 0x128f9d0 GuardedLogEmitters2::Wrap128f9d0
// 0x12ae2a0 GuardedLogEmitters2::Wrap12ae2a0
// 0x12d28f0 GuardedLogEmitters2::Wrap12d28f0
// 0x12d2970 GuardedLogEmitters2::Wrap12d2970
// 0x12de130 GuardedLogEmitters2::Wrap12de130
// 0x12de1b0 GuardedLogEmitters2::Wrap12de1b0
// 0x12de230 GuardedLogEmitters2::Wrap12de230
// 0x12fb4a0 GuardedLogEmitters2::Wrap12fb4a0
// 0x1300da0 GuardedLogEmitters2::Wrap1300da0
// 0x1300e20 GuardedLogEmitters2::Wrap1300e20
// 0x1304bd0 GuardedLogEmitters2::Wrap1304bd0
// 0x1308420 GuardedLogEmitters2::Wrap1308420
// 0x1318770 GuardedLogEmitters2::Wrap1318770
// 0x131b190 GuardedLogEmitters2::Wrap131b190
// 0x131b210 GuardedLogEmitters2::Wrap131b210
// 0x1347570 GuardedLogEmitters2::Wrap1347570
// 0x134a9a0 GuardedLogEmitters2::Wrap134a9a0
#include "GuardedLogEmitters2.h"

void GuardedLogEmitters2::Wrap1272250(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters2::Wrap12722d0(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters2::Wrap1283470(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters2::Wrap128f9d0(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters2::Wrap12ae2a0(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters2::Wrap12d28f0(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters2::Wrap12d2970(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters2::Wrap12de130(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters2::Wrap12de1b0(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters2::Wrap12de230(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters2::Wrap12fb4a0(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters2::Wrap1300da0(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters2::Wrap1300e20(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters2::Wrap1304bd0(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters2::Wrap1308420(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters2::Wrap1318770(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters2::Wrap131b190(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters2::Wrap131b210(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters2::Wrap1347570(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters2::Wrap134a9a0(void* unused, bool ok, const char* msg)
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
