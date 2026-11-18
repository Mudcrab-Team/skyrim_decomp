// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfdc650, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfdc650 BSOcclusionShape::GetRTTI
#include "LeafAddressfdc650.h"
extern unsigned char leaf_global;
void* LeafAddressfdc650::Address() { return &leaf_global; }
