// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1082730, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1082730 LeafAddress1082730::Address
#include "LeafAddress1082730.h"
extern unsigned char leaf_global;
void* LeafAddress1082730::Address() { return &leaf_global; }
