// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf8b870, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf8b870 LeafAddressf8b870::Address
#include "LeafAddressf8b870.h"
extern unsigned char leaf_global;
void* LeafAddressf8b870::Address() { return &leaf_global; }
