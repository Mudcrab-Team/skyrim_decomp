// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressffff30, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xffff30 LeafAddressffff30::Address
#include "LeafAddressffff30.h"
extern unsigned char leaf_global;
void* LeafAddressffff30::Address() { return &leaf_global; }
