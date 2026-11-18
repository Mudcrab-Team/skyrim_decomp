// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf85f20, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf85f20 LeafAddressf85f20::Address
#include "LeafAddressf85f20.h"
extern unsigned char leaf_global;
void* LeafAddressf85f20::Address() { return &leaf_global; }
