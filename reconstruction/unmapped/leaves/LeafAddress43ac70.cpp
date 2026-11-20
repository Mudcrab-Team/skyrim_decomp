// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress43ac70, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x43ac70 BSFaceGenNiNode::GetRTTI
#include "LeafAddress43ac70.h"
extern unsigned char leaf_global;
void* LeafAddress43ac70::Address() { return &leaf_global; }
