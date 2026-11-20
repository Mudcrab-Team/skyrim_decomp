// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfe4420, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfe4420 BSInstanceTriShape::GetRTTI
#include "LeafAddressfe4420.h"
extern unsigned char leaf_global;
void* LeafAddressfe4420::Address() { return &leaf_global; }
