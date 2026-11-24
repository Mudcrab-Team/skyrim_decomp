// Source exposure: mixed (community declarations, sibling spelling and pinned image).
// Code origin: original reconstruction from the pinned image, shaped after the sibling destructor.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xeae0b0 NiFile::~NiFile
// Adapted bodies: NiFile::~NiFile follows momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/nisystem/console/nifile_console.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/nisystem/console/nifile_console.cpp:7
// Adapted bodies: NiFile::~NiFile also follows momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nisystem/console/nifile_console.cpp
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nisystem/console/nifile_console.cpp:8
#include "NiFile_eae0b0.h"

extern "C" __declspec(dllimport) int fclose(_iobuf* file);

// The constructor emits the vftable and its deleting destructor.
NiFile::NiFile()
{
}

NiFile::~NiFile()
{
    if (isGood && file)
    {
        Flush();
        fclose(file);
    }
    NiFree(buffer);
}
