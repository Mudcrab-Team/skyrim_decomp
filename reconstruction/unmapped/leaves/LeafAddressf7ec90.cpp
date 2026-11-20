// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf7ec90, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf7ec90 LeafAddressf7ec90::Address
#include "LeafAddressf7ec90.h"
extern unsigned char leaf_global;
void* LeafAddressf7ec90::Address() { return &leaf_global; }
