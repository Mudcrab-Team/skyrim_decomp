// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressbfbc30, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xbfbc30 LeafAddressbfbc30::Address
#include "LeafAddressbfbc30.h"
extern unsigned char leaf_global;
void* LeafAddressbfbc30::Address() { return &leaf_global; }
