// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf739a0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf739a0 LeafAddressf739a0::Address
#include "LeafAddressf739a0.h"
extern unsigned char leaf_global;
void* LeafAddressf739a0::Address() { return &leaf_global; }
