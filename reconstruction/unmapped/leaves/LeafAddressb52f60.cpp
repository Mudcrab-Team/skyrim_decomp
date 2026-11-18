// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb52f60, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb52f60 LeafAddressb52f60::Address
#include "LeafAddressb52f60.h"
extern unsigned char leaf_global;
void* LeafAddressb52f60::Address() { return &leaf_global; }
