// Source exposure: mixed (community headers; the pinned image listing).
// Sibling source: fo4-private@1b765c70 src/Game/SaveGame/BGSSaveLoadHeader.cpp:27
// BGSSaveLoadHeader, BGSSaveLoadHeader::GetFileCreationDate: SIBLING(fo4-private@1b765c70, author-permission) STANDIN
// _SYSTEMTIME, _FILETIME, GetLocalTime, SystemTimeToFileTime, LocalFileTimeToFileTime: OBSERVED; plain Win32 structures and imports, declared here to avoid the SDK headers
#pragma once

struct _FILETIME
{
    unsigned long dwLowDateTime;
    unsigned long dwHighDateTime;
};

struct _SYSTEMTIME
{
    unsigned short wYear;
    unsigned short wMonth;
    unsigned short wDayOfWeek;
    unsigned short wDay;
    unsigned short wHour;
    unsigned short wMinute;
    unsigned short wSecond;
    unsigned short wMilliseconds;
};

extern "C" {
__declspec(dllimport) void __stdcall GetLocalTime(_SYSTEMTIME* a_time);
__declspec(dllimport) int __stdcall SystemTimeToFileTime(const _SYSTEMTIME* a_time, _FILETIME* a_fileTime);
__declspec(dllimport) int __stdcall LocalFileTimeToFileTime(const _FILETIME* a_local, _FILETIME* a_fileTime);
}

class BGSSaveLoadHeader
{
public:
    static void GetFileCreationDate(_FILETIME& a_fileTime);
};
