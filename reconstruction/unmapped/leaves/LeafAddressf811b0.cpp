// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf811b0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf811b0 LeafAddressf811b0::Address
#include "LeafAddressf811b0.h"
extern unsigned char leaf_global;
void* LeafAddressf811b0::Address() { return &leaf_global; }
