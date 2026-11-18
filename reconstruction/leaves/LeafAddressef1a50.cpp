// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressef1a50, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xef1a50 LeafAddressef1a50::Address
#include "LeafAddressef1a50.h"
extern unsigned char leaf_global;
void* LeafAddressef1a50::Address() { return &leaf_global; }
