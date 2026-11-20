// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress24db00, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x24db00 LeafAddress24db00::Address
#include "LeafAddress24db00.h"
extern unsigned char leaf_global;
void* LeafAddress24db00::Address() { return &leaf_global; }
