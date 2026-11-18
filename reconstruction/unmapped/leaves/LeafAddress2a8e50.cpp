// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress2a8e50, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x2a8e50 NiColorData::GetRTTI
#include "LeafAddress2a8e50.h"
extern unsigned char leaf_global;
void* LeafAddress2a8e50::Address() { return &leaf_global; }
