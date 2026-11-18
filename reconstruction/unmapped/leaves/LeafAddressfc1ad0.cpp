// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfc1ad0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfc1ad0 LeafAddressfc1ad0::Address
#include "LeafAddressfc1ad0.h"
extern unsigned char leaf_global;
void* LeafAddressfc1ad0::Address() { return &leaf_global; }
