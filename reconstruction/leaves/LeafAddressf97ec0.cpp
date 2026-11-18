// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf97ec0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf97ec0 LeafAddressf97ec0::Address
#include "LeafAddressf97ec0.h"
extern unsigned char leaf_global;
void* LeafAddressf97ec0::Address() { return &leaf_global; }
