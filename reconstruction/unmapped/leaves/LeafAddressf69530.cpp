// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf69530, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf69530 LeafAddressf69530::Address
#include "LeafAddressf69530.h"
extern unsigned char leaf_global;
void* LeafAddressf69530::Address() { return &leaf_global; }
