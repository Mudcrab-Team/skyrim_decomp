// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1002870, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1002870 LeafAddress1002870::Address
#include "LeafAddress1002870.h"
extern unsigned char leaf_global;
void* LeafAddress1002870::Address() { return &leaf_global; }
