// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressbfbb70, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xbfbb70 LeafAddressbfbb70::Address
#include "LeafAddressbfbb70.h"
extern unsigned char leaf_global;
void* LeafAddressbfbb70::Address() { return &leaf_global; }
