// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressbb00b0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xbb00b0 LeafAddressbb00b0::Address
#include "LeafAddressbb00b0.h"
extern unsigned char leaf_global;
void* LeafAddressbb00b0::Address() { return &leaf_global; }
