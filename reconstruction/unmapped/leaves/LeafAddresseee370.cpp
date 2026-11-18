// Source exposure: binary-analysis; no external implementation reused.
// LeafAddresseee370, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xeee370 NiSwitchNode::GetRTTI
#include "LeafAddresseee370.h"
extern unsigned char leaf_global;
void* LeafAddresseee370::Address() { return &leaf_global; }
