// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressef9cb0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xef9cb0 LeafAddressef9cb0::Address
#include "LeafAddressef9cb0.h"
extern unsigned char leaf_global;
void* LeafAddressef9cb0::Address() { return &leaf_global; }
