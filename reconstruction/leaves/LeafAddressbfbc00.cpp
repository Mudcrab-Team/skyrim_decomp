// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressbfbc00, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xbfbc00 LeafAddressbfbc00::Address
#include "LeafAddressbfbc00.h"
extern unsigned char leaf_global;
void* LeafAddressbfbc00::Address() { return &leaf_global; }
