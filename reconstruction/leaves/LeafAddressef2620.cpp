// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressef2620, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xef2620 BSTriShape::GetRTTI
#include "LeafAddressef2620.h"
extern unsigned char leaf_global;
void* LeafAddressef2620::Address() { return &leaf_global; }
