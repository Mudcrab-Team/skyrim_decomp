// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: f3m_006f8ff0::Actor::IsInFaction_1405F8500.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_006e0000_o2.cpp:4452
// 0x69df00 f3m_006f8ff0::Actor::IsInFaction_1405F8500
#include "Actor_69df00.h"

namespace f3m_006f8ff0 {
bool Actor::IsInFaction_1405F8500(void* item){
    List6f8* list=holder.Func0040e4f0();
    Owner6f8* o=owner;
    bool has=o->set.Func0044fc00(item);
    if(!list)return has;
    if(has&&!list->Func0041f9e0(item)||list->Func0041f9a0(item))return true;
    return false;
}
}
