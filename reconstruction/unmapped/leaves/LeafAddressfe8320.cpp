// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfe8320, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfe8320 BSOcclusionBox::GetRTTI
#include "LeafAddressfe8320.h"
extern unsigned char leaf_global;
void* LeafAddressfe8320::Address() { return &leaf_global; }
