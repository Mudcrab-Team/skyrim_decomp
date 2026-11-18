// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf15ad0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf15ad0 LeafAddressf15ad0::Address
#include "LeafAddressf15ad0.h"
extern unsigned char leaf_global;
void* LeafAddressf15ad0::Address() { return &leaf_global; }
