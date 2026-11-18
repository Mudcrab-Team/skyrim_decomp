// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfeef60, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfeef60 LeafAddressfeef60::Address
#include "LeafAddressfeef60.h"
extern unsigned char leaf_global;
void* LeafAddressfeef60::Address() { return &leaf_global; }
