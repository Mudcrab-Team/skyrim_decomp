// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressadcc50, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xadcc50 LeafAddressadcc50::Address
#include "LeafAddressadcc50.h"
extern unsigned char leaf_global;
void* LeafAddressadcc50::Address() { return &leaf_global; }
