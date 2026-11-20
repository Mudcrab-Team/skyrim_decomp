// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressef3f00, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xef3f00 LeafAddressef3f00::Address
#include "LeafAddressef3f00.h"
extern unsigned char leaf_global;
void* LeafAddressef3f00::Address() { return &leaf_global; }
