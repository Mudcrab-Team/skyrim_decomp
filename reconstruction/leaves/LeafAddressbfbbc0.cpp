// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressbfbbc0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xbfbbc0 LeafAddressbfbbc0::Address
#include "LeafAddressbfbbc0.h"
extern unsigned char leaf_global;
void* LeafAddressbfbbc0::Address() { return &leaf_global; }
