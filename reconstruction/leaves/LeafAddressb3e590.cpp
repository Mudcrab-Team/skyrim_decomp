// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb3e590, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb3e590 LeafAddressb3e590::Address
#include "LeafAddressb3e590.h"
extern unsigned char leaf_global;
void* LeafAddressb3e590::Address() { return &leaf_global; }
