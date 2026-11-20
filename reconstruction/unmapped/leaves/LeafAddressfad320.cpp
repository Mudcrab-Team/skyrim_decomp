// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfad320, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfad320 LeafAddressfad320::Address
#include "LeafAddressfad320.h"
extern unsigned char leaf_global;
void* LeafAddressfad320::Address() { return &leaf_global; }
