// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// Adapted bodies: none
// BGSSaveLoadManager, BGSSaveLoadManager::sub_140587B80: CRASHLOGGER_PDB(59818@2026.10.24)
// SystemTime, GetUserNameA, GetLocalTime, FormatSaveString, GetSaveVersionString, kTimeStampFormat, kSaveInfoFormat, g_saveStateByte, g_saveStateDword: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

struct SystemTime
{
    std::uint16_t year;
    std::uint16_t month;
    std::uint16_t dayOfWeek;
    std::uint16_t day;
    std::uint16_t hour;
    std::uint16_t minute;
    std::uint16_t second;
    std::uint16_t milliseconds;
};
static_assert(sizeof(SystemTime) == 0x10, "SystemTime size");

extern "C" {
__declspec(dllimport) int __stdcall GetUserNameA(char* a_buffer, unsigned long* a_bufferSize);
__declspec(dllimport) void __stdcall GetLocalTime(SystemTime* a_systemTime);
}

int FormatSaveString(char* a_buffer, std::size_t a_bufferSize, const char* a_format, ...);
const char* GetSaveVersionString();

extern const char kTimeStampFormat[];
extern const char kSaveInfoFormat[];
extern std::uint8_t g_saveStateByte;
extern std::uint32_t g_saveStateDword;

class BGSSaveLoadManager
{
public:
    void sub_140587B80(char* a_buffer, std::uint32_t a_bufferSize);
};
