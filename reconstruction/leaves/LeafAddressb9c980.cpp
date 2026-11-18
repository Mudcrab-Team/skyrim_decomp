// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb9c980, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb9c980 LeafAddressb9c980::Address
#include "LeafAddressb9c980.h"
extern unsigned char leaf_global;
void* LeafAddressb9c980::Address() { return &leaf_global; }
