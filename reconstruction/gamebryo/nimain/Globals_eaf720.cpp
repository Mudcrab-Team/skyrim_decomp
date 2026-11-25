// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Func00aa1a40.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nisystem/nifile_iso_variant.cpp:114
// 0xeaf720 Func00aa1a40
#include "Globals_eaf720.h"

extern "C" bool Func00aa1a40(const char* name, NiFile::OpenMode mode)
{
    FileAccessObject file(name, mode, 0);
    return file.good;
}
