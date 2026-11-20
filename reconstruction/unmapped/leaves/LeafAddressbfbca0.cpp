// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressbfbca0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xbfbca0 LeafAddressbfbca0::Address
#include "LeafAddressbfbca0.h"
extern unsigned char leaf_global;
void* LeafAddressbfbca0::Address() { return &leaf_global; }
