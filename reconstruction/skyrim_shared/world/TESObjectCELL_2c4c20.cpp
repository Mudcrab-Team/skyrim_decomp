// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectCELL.cpp:2801 (TESObjectCELL::IsFormTypeChild)
// TESObjectCELL, IsFormTypeChild, type: GUESS(low)
// 0x2c4c20 TESObjectCELL::IsFormTypeChild
#include "TESObjectCELL_2c4c20.h"

bool TESObjectCELL::IsFormTypeChild(unsigned char type)
{
    switch (type) {
    case 0x3d: case 0x3e: case 0x3f: case 0x40: case 0x41:
    case 0x42: case 0x43: case 0x44: case 0x45: case 0x46:
    case 0x48: case 0x49:
        return true;
    default:
        return false;
    }
}
