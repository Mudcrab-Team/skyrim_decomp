// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: body adapted from the permitted sibling and checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Game/SaveGame/BGSSaveLoadHeader.cpp:27
// 0x61f430 BGSSaveLoadHeader::GetFileCreationDate
// Adapted bodies: BGSSaveLoadHeader::GetFileCreationDate from the sibling source named above
#include "BGSSaveLoadHeader_61f430.h"

void BGSSaveLoadHeader::GetFileCreationDate(_FILETIME& a_fileTime)
{
    _SYSTEMTIME localSysTime;
    _FILETIME localFileTime;
    GetLocalTime(&localSysTime);
    SystemTimeToFileTime(&localSysTime, &localFileTime);
    LocalFileTimeToFileTime(&localFileTime, &a_fileTime);
}
