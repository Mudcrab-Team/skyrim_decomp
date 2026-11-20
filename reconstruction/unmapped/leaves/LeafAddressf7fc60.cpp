// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf7fc60, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf7fc60 LeafAddressf7fc60::Address
#include "LeafAddressf7fc60.h"
extern unsigned char leaf_global;
void* LeafAddressf7fc60::Address() { return &leaf_global; }
