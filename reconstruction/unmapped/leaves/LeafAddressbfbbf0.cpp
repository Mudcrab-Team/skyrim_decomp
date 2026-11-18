// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressbfbbf0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xbfbbf0 LeafAddressbfbbf0::Address
#include "LeafAddressbfbbf0.h"
extern unsigned char leaf_global;
void* LeafAddressbfbbf0::Address() { return &leaf_global; }
