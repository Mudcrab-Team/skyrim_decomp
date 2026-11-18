// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressabf3e0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xabf3e0 LeafAddressabf3e0::Address
#include "LeafAddressabf3e0.h"
extern unsigned char leaf_global;
void* LeafAddressabf3e0::Address() { return &leaf_global; }
