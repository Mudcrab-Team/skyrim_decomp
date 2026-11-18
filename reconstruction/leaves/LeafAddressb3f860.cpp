// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb3f860, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb3f860 LeafAddressb3f860::Address
#include "LeafAddressb3f860.h"
extern unsigned char leaf_global;
void* LeafAddressb3f860::Address() { return &leaf_global; }
