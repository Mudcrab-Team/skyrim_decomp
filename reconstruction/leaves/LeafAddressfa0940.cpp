// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfa0940, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfa0940 LeafAddressfa0940::Address
#include "LeafAddressfa0940.h"
extern unsigned char leaf_global;
void* LeafAddressfa0940::Address() { return &leaf_global; }
