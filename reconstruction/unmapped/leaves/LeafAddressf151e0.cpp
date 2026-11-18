// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf151e0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf151e0 LeafAddressf151e0::Address
#include "LeafAddressf151e0.h"
extern unsigned char leaf_global;
void* LeafAddressf151e0::Address() { return &leaf_global; }
