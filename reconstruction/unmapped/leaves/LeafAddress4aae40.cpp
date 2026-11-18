// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress4aae40, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x4aae40 BSTempEffectDebris::GetRTTI
#include "LeafAddress4aae40.h"
extern unsigned char leaf_global;
void* LeafAddress4aae40::Address() { return &leaf_global; }
