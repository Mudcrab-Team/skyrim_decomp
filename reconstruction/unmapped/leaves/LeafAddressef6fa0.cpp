// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressef6fa0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xef6fa0 LeafAddressef6fa0::Address
#include "LeafAddressef6fa0.h"
extern unsigned char leaf_global;
void* LeafAddressef6fa0::Address() { return &leaf_global; }
