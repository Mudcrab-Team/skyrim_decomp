// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf8af30, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf8af30 LeafAddressf8af30::Address
#include "LeafAddressf8af30.h"
extern unsigned char leaf_global;
void* LeafAddressf8af30::Address() { return &leaf_global; }
