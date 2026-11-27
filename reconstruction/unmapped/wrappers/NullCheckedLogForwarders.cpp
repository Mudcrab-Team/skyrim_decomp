// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// NullCheckedLogForwarders, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
// CI hash: 0x1270450 ?Wrap1270450@NullCheckedLogForwarders@@SAXPEAXPEBD@Z
// CI hash: 0x1270690 ?Wrap1270690@NullCheckedLogForwarders@@SAXPEAXPEBD@Z
// CI hash: 0x1270950 ?Wrap1270950@NullCheckedLogForwarders@@SAXPEAXPEBD@Z
// CI hash: 0x1270c10 ?Wrap1270c10@NullCheckedLogForwarders@@SAXPEAXPEBD@Z
// CI hash: 0x12f5c70 ?Wrap12f5c70@NullCheckedLogForwarders@@SAXPEAXPEBD@Z
// CI hash: 0x131af50 ?Wrap131af50@NullCheckedLogForwarders@@SAXPEAXPEBD@Z
// CI hash: 0x1328a50 ?Wrap1328a50@NullCheckedLogForwarders@@SAXPEAXPEBD@Z
// CI hash: 0x134a850 ?Wrap134a850@NullCheckedLogForwarders@@SAXPEAXPEBD@Z
// CI hash: 0x1371f50 ?Wrap1371f50@NullCheckedLogForwarders@@SAXPEAXPEBD@Z
// CI hash: 0x13d4bc0 ?Wrap13d4bc0@NullCheckedLogForwarders@@SAXPEAXPEBD@Z
// CI hash: 0x13d4c70 ?Wrap13d4c70@NullCheckedLogForwarders@@SAXPEAXPEBD@Z
// CI hash: 0x13d4f30 ?Wrap13d4f30@NullCheckedLogForwarders@@SAXPEAXPEBD@Z
// CI hash: 0x13e5bf0 ?Wrap13e5bf0@NullCheckedLogForwarders@@SAXPEAXPEBD@Z
// CI hash: 0x1458f90 ?Wrap1458f90@NullCheckedLogForwarders@@SAXPEAXPEBD@Z
// CI hash: 0x1463de0 ?Wrap1463de0@NullCheckedLogForwarders@@SAXPEAXPEBD@Z
// 0x1270450 NullCheckedLogForwarders::Wrap1270450
// 0x1270690 NullCheckedLogForwarders::Wrap1270690
// 0x1270950 NullCheckedLogForwarders::Wrap1270950
// 0x1270c10 NullCheckedLogForwarders::Wrap1270c10
// 0x12f5c70 NullCheckedLogForwarders::Wrap12f5c70
// 0x131af50 NullCheckedLogForwarders::Wrap131af50
// 0x1328a50 NullCheckedLogForwarders::Wrap1328a50
// 0x134a850 NullCheckedLogForwarders::Wrap134a850
// 0x1371f50 NullCheckedLogForwarders::Wrap1371f50
// 0x13d4bc0 NullCheckedLogForwarders::Wrap13d4bc0
// 0x13d4c70 NullCheckedLogForwarders::Wrap13d4c70
// 0x13d4f30 NullCheckedLogForwarders::Wrap13d4f30
// 0x13e5bf0 NullCheckedLogForwarders::Wrap13e5bf0
// 0x1458f90 NullCheckedLogForwarders::Wrap1458f90
// 0x1463de0 NullCheckedLogForwarders::Wrap1463de0
#include "NullCheckedLogForwarders.h"

void NullCheckedLogForwarders::Wrap1270450(void* ctx, const char* str)
{
    if (str == nullptr)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, Text_1acd328);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, Text_1acd328);
            }
        }
        return;
    }
    Forward_1270500(ctx, str, StrLen_128eb90(str));
}

void NullCheckedLogForwarders::Wrap1270690(void* ctx, const char* str)
{
    if (str == nullptr)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, Text_1acd328);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, Text_1acd328);
            }
        }
        return;
    }
    Forward_1259dd0(ctx, str, StrLen_128eb90(str));
}

void NullCheckedLogForwarders::Wrap1270950(void* ctx, const char* str)
{
    if (str == nullptr)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, Text_1acd328);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, Text_1acd328);
            }
        }
        return;
    }
    Forward_1270a00(ctx, str, StrLen_128eb90(str));
}

void NullCheckedLogForwarders::Wrap1270c10(void* ctx, const char* str)
{
    if (str == nullptr)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, Text_1acd328);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, Text_1acd328);
            }
        }
        return;
    }
    Forward_1270cc0(ctx, str, StrLen_128eb90(str));
}

void NullCheckedLogForwarders::Wrap12f5c70(void* ctx, const char* str)
{
    if (str == nullptr)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, Text_1acd328);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, Text_1acd328);
            }
        }
        return;
    }
    Forward_1270740(ctx, str, StrLen_128eb90(str));
}

void NullCheckedLogForwarders::Wrap131af50(void* ctx, const char* str)
{
    if (str == nullptr)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, Text_1acd328);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, Text_1acd328);
            }
        }
        return;
    }
    Forward_131b000(ctx, str, StrLen_128eb90(str));
}

void NullCheckedLogForwarders::Wrap1328a50(void* ctx, const char* str)
{
    if (str == nullptr)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, Text_1acd328);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, Text_1acd328);
            }
        }
        return;
    }
    Forward_128baf0(ctx, str, StrLen_128eb90(str));
}

void NullCheckedLogForwarders::Wrap134a850(void* ctx, const char* str)
{
    if (str == nullptr)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, Text_1acd328);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, Text_1acd328);
            }
        }
        return;
    }
    Forward_12ddef0(ctx, str, StrLen_128ebf0(str));
}

void NullCheckedLogForwarders::Wrap1371f50(void* ctx, const char* str)
{
    if (str == nullptr)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, Text_1acd328);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, Text_1acd328);
            }
        }
        return;
    }
    Forward_12716a0(ctx, str, StrLen_128eb90(str));
}

void NullCheckedLogForwarders::Wrap13d4bc0(void* ctx, const char* str)
{
    if (str == nullptr)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, Text_1acd328);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, Text_1acd328);
            }
        }
        return;
    }
    Forward_1379590(ctx, str, StrLen_128eb90(str));
}

void NullCheckedLogForwarders::Wrap13d4c70(void* ctx, const char* str)
{
    if (str == nullptr)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, Text_1acd328);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, Text_1acd328);
            }
        }
        return;
    }
    Forward_13d4d20(ctx, str, StrLen_128eb90(str));
}

void NullCheckedLogForwarders::Wrap13d4f30(void* ctx, const char* str)
{
    if (str == nullptr)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, Text_1acd328);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, Text_1acd328);
            }
        }
        return;
    }
    Forward_12fb060(ctx, str, StrLen_128eb90(str));
}

void NullCheckedLogForwarders::Wrap13e5bf0(void* ctx, const char* str)
{
    if (str == nullptr)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, Text_1acd328);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, Text_1acd328);
            }
        }
        return;
    }
    Forward_13e5ca0(ctx, str, StrLen_128eb90(str));
}

void NullCheckedLogForwarders::Wrap1458f90(void* ctx, const char* str)
{
    if (str == nullptr)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, Text_1acd328);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, Text_1acd328);
            }
        }
        return;
    }
    Forward_12ae090(ctx, str, StrLen_128eb90(str));
}

void NullCheckedLogForwarders::Wrap1463de0(void* ctx, const char* str)
{
    if (str == nullptr)
    {
        if (!LogFilter_128c360(gLogChannel_20d5024, 3))
        {
            if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 3)
            {
                LogConsole_12586a0(3, Text_1acd380, Text_1acd328);
            }
            if (LogSinkEn_128c1a0(3, gLogChannel_20d5024))
            {
                LogSink_12586e0(3, Text_1acd380, Text_1acd328);
            }
        }
        return;
    }
    Forward_1463e90(ctx, str, StrLen_128eb90(str));
}
