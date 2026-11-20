// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf00b00, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf00b00 NiAVObjectPalette::GetRTTI
#include "LeafAddressf00b00.h"
extern unsigned char leaf_global;
void* LeafAddressf00b00::Address() { return &leaf_global; }
