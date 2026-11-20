// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfe9c10, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfe9c10 BSOcclusionPlane::GetRTTI
#include "LeafAddressfe9c10.h"
extern unsigned char leaf_global;
void* LeafAddressfe9c10::Address() { return &leaf_global; }
