// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfaffd0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfaffd0 LeafAddressfaffd0::Address
#include "LeafAddressfaffd0.h"
extern unsigned char leaf_global;
void* LeafAddressfaffd0::Address() { return &leaf_global; }
