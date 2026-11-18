// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfdfc40, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfdfc40 LeafAddressfdfc40::Address
#include "LeafAddressfdfc40.h"
extern unsigned char leaf_global;
void* LeafAddressfdfc40::Address() { return &leaf_global; }
