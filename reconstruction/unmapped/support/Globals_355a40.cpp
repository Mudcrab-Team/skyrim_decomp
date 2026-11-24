// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: f3m_00525d00::Func00525d00.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00520000_o2_2.cpp:31
// 0x355a40 f3m_00525d00::Func00525d00
#include "Globals_355a40.h"

namespace f3m_00525d00 {
bool Func00525d00(ParamInfo* a1,void* a2,TESObjectREFR* a3,TESObjectREFR* a4,Script* a5,ScriptEventList* a6,double* out,unsigned int* a8) {
 unsigned int option;Obj525d00* receiver;void* target;
 receiver=0;target=0;option=0;
 if(!Func00517950(a1,a2,a8,a3,a4,a5,a6,&receiver,&target,&option)) return false;
 *out=0.0;
 if(target && receiver) receiver->Func00551360(target,option);
 return true;
}
}
