// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb52f90, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb52f90 LeafAddressb52f90::Address
#include "LeafAddressb52f90.h"
extern unsigned char leaf_global;
void* LeafAddressb52f90::Address() { return &leaf_global; }
