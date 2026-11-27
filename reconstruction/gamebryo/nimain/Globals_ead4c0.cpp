// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: BuildAbsolutePath.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nisystem/nipath.cpp:125
// 0xead4c0 BuildAbsolutePath
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nisystem/nipath.cpp:130
#include "Globals_ead4c0.h"

size_t BuildAbsolutePath(char* pcOutPath, size_t stOutSize, const char* pcRelativePath, const char* pcBasePath)
{
    size_t stBaseLen = strlen(pcBasePath);
    size_t stRelLen = strlen(pcRelativePath);
    bool bAppendSlash = (pcBasePath[stBaseLen - 1] != '\\');
    size_t stTotalLen = stBaseLen + (bAppendSlash ? 1 : 0) + stRelLen + 1;
    if (stOutSize < stTotalLen)
    {
        if (stOutSize > 0)
            pcOutPath[0] = 0;
        return 0;
    }
    strcpy_s(pcOutPath, stOutSize, pcBasePath);
    if (bAppendSlash)
        strcat_s(pcOutPath, stOutSize, "\\");
    strcat_s(pcOutPath, stOutSize, pcRelativePath);
    RemoveParentDirSegments(pcOutPath);
    return strlen(pcOutPath);
}
