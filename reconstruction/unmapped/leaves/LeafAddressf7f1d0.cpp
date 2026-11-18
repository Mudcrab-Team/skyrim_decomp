// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf7f1d0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf7f1d0 LeafAddressf7f1d0::Address
#include "LeafAddressf7f1d0.h"
extern unsigned char leaf_global;
void* LeafAddressf7f1d0::Address() { return &leaf_global; }
