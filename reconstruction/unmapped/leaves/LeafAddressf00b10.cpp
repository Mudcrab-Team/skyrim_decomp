// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf00b10, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf00b10 NiDefaultAVObjectPalette::GetRTTI
#include "LeafAddressf00b10.h"
extern unsigned char leaf_global;
void* LeafAddressf00b10::Address() { return &leaf_global; }
