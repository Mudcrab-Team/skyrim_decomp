// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf16650, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf16650 LeafAddressf16650::Address
#include "LeafAddressf16650.h"
extern unsigned char leaf_global;
void* LeafAddressf16650::Address() { return &leaf_global; }
