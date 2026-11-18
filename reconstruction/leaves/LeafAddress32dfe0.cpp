// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress32dfe0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x32dfe0 BSTextureSet::GetRTTI
#include "LeafAddress32dfe0.h"
extern unsigned char leaf_global;
void* LeafAddress32dfe0::Address() { return &leaf_global; }
