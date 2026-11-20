// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfc1320, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfc1320 LeafAddressfc1320::Address
#include "LeafAddressfc1320.h"
extern unsigned char leaf_global;
void* LeafAddressfc1320::Address() { return &leaf_global; }
