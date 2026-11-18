// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf04cb0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf04cb0 LeafAddressf04cb0::Address
#include "LeafAddressf04cb0.h"
extern unsigned char leaf_global;
void* LeafAddressf04cb0::Address() { return &leaf_global; }
