// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress32dfd0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x32dfd0 BSShaderTextureSet::GetRTTI
#include "LeafAddress32dfd0.h"
extern unsigned char leaf_global;
void* LeafAddress32dfd0::Address() { return &leaf_global; }
