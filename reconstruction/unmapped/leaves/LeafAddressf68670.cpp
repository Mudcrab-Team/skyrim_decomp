// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf68670, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf68670 LeafAddressf68670::Address
#include "LeafAddressf68670.h"
extern unsigned char leaf_global;
void* LeafAddressf68670::Address() { return &leaf_global; }
