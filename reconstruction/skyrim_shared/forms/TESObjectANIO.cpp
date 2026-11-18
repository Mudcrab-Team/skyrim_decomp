// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
// 0x27bb70 TESObjectANIO::GetFormEditorID
// 0x27b9b0 TESObjectANIO::InitItemImpl
#include "TESObjectANIO.h"

const char* TESObjectANIO::GetFormEditorID() const
{
    return editorID ? editorID : g_defaultFormEditorIDString;
}

