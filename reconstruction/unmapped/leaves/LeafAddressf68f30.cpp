// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf68f30, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf68f30 LeafAddressf68f30::Address
#include "LeafAddressf68f30.h"
extern unsigned char leaf_global;
void* LeafAddressf68f30::Address() { return &leaf_global; }
