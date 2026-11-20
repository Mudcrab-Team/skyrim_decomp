// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressefc000, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xefc000 LeafAddressefc000::Address
#include "LeafAddressefc000.h"
extern unsigned char leaf_global;
void* LeafAddressefc000::Address() { return &leaf_global; }
