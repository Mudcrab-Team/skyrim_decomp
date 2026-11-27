// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// 0x623470 BGSSaveLoadManager::sub_140587B80
// Adapted bodies: none
#include "BGSSaveLoadManager_623470.h"

#include <cstring>

// Formats the user name, local timestamp, version string, and save state into a_buffer.
void BGSSaveLoadManager::sub_140587B80(char* a_buffer, std::uint32_t a_bufferSize)
{
    char userName[260];
    std::memset(userName, 0, sizeof(userName));
    char timeStamp[260];
    std::memset(timeStamp, 0, sizeof(timeStamp));

    unsigned long userNameSize = 260;
    GetUserNameA(userName, &userNameSize);

    SystemTime localTime;
    GetLocalTime(&localTime);

    FormatSaveString(
        timeStamp,
        sizeof(timeStamp),
        kTimeStampFormat,
        localTime.month,
        localTime.day,
        localTime.year,
        localTime.hour,
        localTime.minute,
        localTime.second);

    const std::uint8_t stateByte = g_saveStateByte;
    const char* version = GetSaveVersionString();
    FormatSaveString(
        a_buffer,
        a_bufferSize,
        kSaveInfoFormat,
        userName,
        timeStamp,
        version,
        g_saveStateDword,
        stateByte);
}
