// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1005490, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1005490 BSNiNode::GetRTTI
#include "LeafAddress1005490.h"
extern unsigned char leaf_global;
void* LeafAddress1005490::Address() { return &leaf_global; }
