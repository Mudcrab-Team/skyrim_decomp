// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae65e0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae65e0 LeafAddressae65e0::Address
#include "LeafAddressae65e0.h"
extern unsigned char leaf_global;
void* LeafAddressae65e0::Address() { return &leaf_global; }
