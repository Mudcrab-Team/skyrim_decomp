// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb3e5c0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb3e5c0 LeafAddressb3e5c0::Address
#include "LeafAddressb3e5c0.h"
extern unsigned char leaf_global;
void* LeafAddressb3e5c0::Address() { return &leaf_global; }
