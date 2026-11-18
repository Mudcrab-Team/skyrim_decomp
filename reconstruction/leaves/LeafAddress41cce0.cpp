// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress41cce0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x41cce0 NiBillboardNode::GetRTTI
#include "LeafAddress41cce0.h"
extern unsigned char leaf_global;
void* LeafAddress41cce0::Address() { return &leaf_global; }
