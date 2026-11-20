// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf19e80, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf19e80 LeafAddressf19e80::Address
#include "LeafAddressf19e80.h"
extern unsigned char leaf_global;
void* LeafAddressf19e80::Address() { return &leaf_global; }
