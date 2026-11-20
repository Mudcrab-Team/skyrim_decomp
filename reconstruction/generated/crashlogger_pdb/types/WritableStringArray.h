// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: WritableStringArray; size 0x40
#pragma once

struct BSFixedString_char_83b572b4;
struct ScrapHeap_aea37981;
struct StringChunk;
struct WritableStringArray {
    ScrapHeap_aea37981* heap;
    BSFixedString_char_83b572b4* _sentinel;
    BSFixedString_char_83b572b4** tailPtr;
    BSFixedString_char_83b572b4* headPtr;
    StringChunk* freeList;
    BSFixedString_char_83b572b4* curPos;
    StringChunk* firstChunk;
    unsigned int count;
    unsigned int pad3C;
};
static_assert(sizeof(WritableStringArray) == 64, "WritableStringArray layout differs from the PDB");
