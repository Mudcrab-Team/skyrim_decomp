// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1107870, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1107870 LeafAddress1107870::Address
#include "LeafAddress1107870.h"
extern unsigned char leaf_global;
void* LeafAddress1107870::Address() { return &leaf_global; }
