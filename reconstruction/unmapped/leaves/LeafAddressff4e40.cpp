// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressff4e40, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xff4e40 LeafAddressff4e40::Address
#include "LeafAddressff4e40.h"
extern unsigned char leaf_global;
void* LeafAddressff4e40::Address() { return &leaf_global; }
