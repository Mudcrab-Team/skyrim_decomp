// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb52db0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb52db0 LeafAddressb52db0::Address
#include "LeafAddressb52db0.h"
extern unsigned char leaf_global;
void* LeafAddressb52db0::Address() { return &leaf_global; }
