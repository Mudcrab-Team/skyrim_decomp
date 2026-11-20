// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf744f0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf744f0 LeafAddressf744f0::Address
#include "LeafAddressf744f0.h"
extern unsigned char leaf_global;
void* LeafAddressf744f0::Address() { return &leaf_global; }
