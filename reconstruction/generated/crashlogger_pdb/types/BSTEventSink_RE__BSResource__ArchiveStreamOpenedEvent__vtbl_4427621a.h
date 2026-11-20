// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSink<RE::BSResource::ArchiveStreamOpenedEvent>_vtbl; size 0x10
#pragma once

#include "BSEventNotifyControl.h"
struct BSTEventSink_RE__BSResource__ArchiveStreamOpenedEvent__vtbl_4427621a {
    void (*_dtor_BSTEventSink)(void);
    BSEventNotifyControl (*ProcessEvent)(char32_t* , char32_t* );
};
static_assert(sizeof(BSTEventSink_RE__BSResource__ArchiveStreamOpenedEvent__vtbl_4427621a) == 16, "BSTEventSink_RE__BSResource__ArchiveStreamOpenedEvent__vtbl_4427621a layout differs from the PDB");
