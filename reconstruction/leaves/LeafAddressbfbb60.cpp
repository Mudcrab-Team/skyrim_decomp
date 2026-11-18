// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressbfbb60, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xbfbb60 LeafAddressbfbb60::Address
#include "LeafAddressbfbb60.h"
extern unsigned char leaf_global;
void* LeafAddressbfbb60::Address() { return &leaf_global; }
