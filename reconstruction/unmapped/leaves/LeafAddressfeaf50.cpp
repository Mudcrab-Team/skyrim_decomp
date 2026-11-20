// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfeaf50, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfeaf50 LeafAddressfeaf50::Address
#include "LeafAddressfeaf50.h"
extern unsigned char leaf_global;
void* LeafAddressfeaf50::Address() { return &leaf_global; }
