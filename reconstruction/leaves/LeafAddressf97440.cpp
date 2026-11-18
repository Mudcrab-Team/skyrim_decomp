// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf97440, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf97440 LeafAddressf97440::Address
#include "LeafAddressf97440.h"
extern unsigned char leaf_global;
void* LeafAddressf97440::Address() { return &leaf_global; }
