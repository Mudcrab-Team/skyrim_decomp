// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressbb00e0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xbb00e0 LeafAddressbb00e0::Address
#include "LeafAddressbb00e0.h"
extern unsigned char leaf_global;
void* LeafAddressbb00e0::Address() { return &leaf_global; }
