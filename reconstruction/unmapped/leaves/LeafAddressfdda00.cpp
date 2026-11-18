// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfdda00, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfdda00 LeafAddressfdda00::Address
#include "LeafAddressfdda00.h"
extern unsigned char leaf_global;
void* LeafAddressfdda00::Address() { return &leaf_global; }
