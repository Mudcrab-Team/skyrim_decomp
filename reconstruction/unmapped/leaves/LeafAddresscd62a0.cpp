// Source exposure: binary-analysis; no external implementation reused.
// LeafAddresscd62a0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xcd62a0 LeafAddresscd62a0::Address
#include "LeafAddresscd62a0.h"
extern unsigned char leaf_global;
void* LeafAddresscd62a0::Address() { return &leaf_global; }
