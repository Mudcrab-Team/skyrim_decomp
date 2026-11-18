// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressade270, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xade270 LeafAddressade270::Address
#include "LeafAddressade270.h"
extern unsigned char leaf_global;
void* LeafAddressade270::Address() { return &leaf_global; }
