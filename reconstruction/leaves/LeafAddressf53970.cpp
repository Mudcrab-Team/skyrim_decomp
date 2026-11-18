// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf53970, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf53970 LeafAddressf53970::Address
#include "LeafAddressf53970.h"
extern unsigned char leaf_global;
void* LeafAddressf53970::Address() { return &leaf_global; }
