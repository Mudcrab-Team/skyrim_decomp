// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress15709e0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x15709e0 BSOrderedNode::GetRTTI
#include "LeafAddress15709e0.h"
extern unsigned char leaf_global;
void* LeafAddress15709e0::Address() { return &leaf_global; }
