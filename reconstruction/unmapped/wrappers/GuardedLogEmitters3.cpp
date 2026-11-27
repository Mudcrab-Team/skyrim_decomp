// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// GuardedLogEmitters3, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
// CI hash: 0x1379df0 ?Wrap1379df0@GuardedLogEmitters3@@SAXPEAX_NPEBD@Z
// CI hash: 0x137de80 ?Wrap137de80@GuardedLogEmitters3@@SAXPEAX_NPEBD@Z
// CI hash: 0x137df00 ?Wrap137df00@GuardedLogEmitters3@@SAXPEAX_NPEBD@Z
// CI hash: 0x1384950 ?Wrap1384950@GuardedLogEmitters3@@SAXPEAX_NPEBD@Z
// CI hash: 0x1393650 ?Wrap1393650@GuardedLogEmitters3@@SAXPEAX_NPEBD@Z
// CI hash: 0x13bb270 ?Wrap13bb270@GuardedLogEmitters3@@SAXPEAX_NPEBD@Z
// CI hash: 0x13d0030 ?Wrap13d0030@GuardedLogEmitters3@@SAXPEAX_NPEBD@Z
// CI hash: 0x13d5710 ?Wrap13d5710@GuardedLogEmitters3@@SAXPEAX_NPEBD@Z
// CI hash: 0x13d5790 ?Wrap13d5790@GuardedLogEmitters3@@SAXPEAX_NPEBD@Z
// CI hash: 0x13d5810 ?Wrap13d5810@GuardedLogEmitters3@@SAXPEAX_NPEBD@Z
// CI hash: 0x13d5890 ?Wrap13d5890@GuardedLogEmitters3@@SAXPEAX_NPEBD@Z
// CI hash: 0x13de030 ?Wrap13de030@GuardedLogEmitters3@@SAXPEAX_NPEBD@Z
// CI hash: 0x13e0240 ?Wrap13e0240@GuardedLogEmitters3@@SAXPEAX_NPEBD@Z
// CI hash: 0x13e02c0 ?Wrap13e02c0@GuardedLogEmitters3@@SAXPEAX_NPEBD@Z
// CI hash: 0x13e6060 ?Wrap13e6060@GuardedLogEmitters3@@SAXPEAX_NPEBD@Z
// CI hash: 0x13fc5a0 ?Wrap13fc5a0@GuardedLogEmitters3@@SAXPEAX_NPEBD@Z
// CI hash: 0x1407320 ?Wrap1407320@GuardedLogEmitters3@@SAXPEAX_NPEBD@Z
// CI hash: 0x1410be0 ?Wrap1410be0@GuardedLogEmitters3@@SAXPEAX_NPEBD@Z
// CI hash: 0x1410c60 ?Wrap1410c60@GuardedLogEmitters3@@SAXPEAX_NPEBD@Z
// CI hash: 0x141e010 ?Wrap141e010@GuardedLogEmitters3@@SAXPEAX_NPEBD@Z
// 0x1379df0 GuardedLogEmitters3::Wrap1379df0
// 0x137de80 GuardedLogEmitters3::Wrap137de80
// 0x137df00 GuardedLogEmitters3::Wrap137df00
// 0x1384950 GuardedLogEmitters3::Wrap1384950
// 0x1393650 GuardedLogEmitters3::Wrap1393650
// 0x13bb270 GuardedLogEmitters3::Wrap13bb270
// 0x13d0030 GuardedLogEmitters3::Wrap13d0030
// 0x13d5710 GuardedLogEmitters3::Wrap13d5710
// 0x13d5790 GuardedLogEmitters3::Wrap13d5790
// 0x13d5810 GuardedLogEmitters3::Wrap13d5810
// 0x13d5890 GuardedLogEmitters3::Wrap13d5890
// 0x13de030 GuardedLogEmitters3::Wrap13de030
// 0x13e0240 GuardedLogEmitters3::Wrap13e0240
// 0x13e02c0 GuardedLogEmitters3::Wrap13e02c0
// 0x13e6060 GuardedLogEmitters3::Wrap13e6060
// 0x13fc5a0 GuardedLogEmitters3::Wrap13fc5a0
// 0x1407320 GuardedLogEmitters3::Wrap1407320
// 0x1410be0 GuardedLogEmitters3::Wrap1410be0
// 0x1410c60 GuardedLogEmitters3::Wrap1410c60
// 0x141e010 GuardedLogEmitters3::Wrap141e010
#include "GuardedLogEmitters3.h"

void GuardedLogEmitters3::Wrap1379df0(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters3::Wrap137de80(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters3::Wrap137df00(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters3::Wrap1384950(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters3::Wrap1393650(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters3::Wrap13bb270(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters3::Wrap13d0030(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters3::Wrap13d5710(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters3::Wrap13d5790(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters3::Wrap13d5810(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters3::Wrap13d5890(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters3::Wrap13de030(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters3::Wrap13e0240(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters3::Wrap13e02c0(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters3::Wrap13e6060(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters3::Wrap13fc5a0(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters3::Wrap1407320(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters3::Wrap1410be0(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters3::Wrap1410c60(void* unused, bool ok, const char* msg)
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

void GuardedLogEmitters3::Wrap141e010(void* unused, bool ok, const char* msg)
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
