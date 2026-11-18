// Source exposure: mixed (authorized target analysis and anonymous permitted sibling source).
// Origin: adapted from the cited game-code body under anonymous author permission.
// Licence: fo4-private reused with author permission conditional on anonymity.
// BSFixedString: STANDIN GUESS(low)
// data: GUESS(low)
// TESTexture, GetAsNormalFile: SIBLING(fo4-private@1b765c70, author-permission)
// Adapted bodies: TESTexture::GetAsNormalFile and TESTexture::GetAsSkinFile.
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESTexture.cpp:116
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESTexture.cpp:125
// GetAsSkinFile: SIBLING(fo4-private@1b765c70, author-permission)
// 0x1f2dc0 TESTexture::GetAsNormalFile
#include "TESTexture.h"
void TESTexture::GetAsNormalFile(const char *apTextureName, char *apNormalTextureName)
{
    strcpy_s(apNormalTextureName, 0x104u, apTextureName);
    char *v3 = strrchr(apNormalTextureName, '.');
    if (v3)
        strcpy_s(v3, apNormalTextureName - v3 + 260, "_n.dds");

}

void TESTexture::GetAsSkinFile(const char *apTextureName, char *apSkinTextureName)
{
    strcpy_s(apSkinTextureName, 0x104u, apTextureName);
    char *v3 = strrchr(apSkinTextureName, '.');
    if (v3)
        strcpy_s(v3, apSkinTextureName - v3 + 260, "_sk.dds");

}
