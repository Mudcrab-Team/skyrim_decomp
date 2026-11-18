// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf0ed00, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf0ed00 NiSkinData::GetRTTI
#include "LeafAddressf0ed00.h"
extern unsigned char leaf_global;
void* LeafAddressf0ed00::Address() { return &leaf_global; }
