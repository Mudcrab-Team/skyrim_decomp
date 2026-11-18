// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf7d680, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf7d680 LeafAddressf7d680::Address
#include "LeafAddressf7d680.h"
extern unsigned char leaf_global;
void* LeafAddressf7d680::Address() { return &leaf_global; }
