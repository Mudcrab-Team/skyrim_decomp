// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressee3530, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xee3530 NiNode::GetRTTI
#include "LeafAddressee3530.h"
extern unsigned char leaf_global;
void* LeafAddressee3530::Address() { return &leaf_global; }
