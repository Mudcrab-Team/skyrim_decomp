// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressadeb60, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xadeb60 LeafAddressadeb60::Address
#include "LeafAddressadeb60.h"
extern unsigned char leaf_global;
void* LeafAddressadeb60::Address() { return &leaf_global; }
