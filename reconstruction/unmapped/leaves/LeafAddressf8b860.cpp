// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf8b860, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf8b860 LeafAddressf8b860::Address
#include "LeafAddressf8b860.h"
extern unsigned char leaf_global;
void* LeafAddressf8b860::Address() { return &leaf_global; }
