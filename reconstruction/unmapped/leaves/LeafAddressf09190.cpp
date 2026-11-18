// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf09190, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf09190 NiSkinPartition::GetRTTI
#include "LeafAddressf09190.h"
extern unsigned char leaf_global;
void* LeafAddressf09190::Address() { return &leaf_global; }
