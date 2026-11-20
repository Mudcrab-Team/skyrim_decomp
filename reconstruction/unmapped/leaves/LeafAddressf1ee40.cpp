// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf1ee40, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf1ee40 LeafAddressf1ee40::Address
#include "LeafAddressf1ee40.h"
extern unsigned char leaf_global;
void* LeafAddressf1ee40::Address() { return &leaf_global; }
