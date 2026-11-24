// Source exposure: mixed (sibling source and the pinned image listing).
// Code origin: original reconstruction shaped after the FNV destructor and Close.
// Adapted bodies: BSFile::~BSFile follows momusdigital/fnv_decomp@91e1b6e8 src/bssystem/bsfile.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/bssystem/bsfile.cpp:55
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00460000_o2.cpp:26763
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/bssystem/bsfile.cpp:39
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xebeb50 BSFile::~BSFile
#include "BSFile_ebeb50.h"

extern "C" __declspec(dllimport) int _fclose_nolock(void* a_file);

inline void BSFile::Close()
{
    if (isGood && file) {
        FlushBuffer();
        _fclose_nolock(file);
    }
    ReleaseBuffer();
    file = nullptr;
}

BSFile::~BSFile()
{
    Close();
}
