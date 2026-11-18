// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1097080, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1097080 LeafAddress1097080::Address
#include "LeafAddress1097080.h"
extern unsigned char leaf_global;
void* LeafAddress1097080::Address() { return &leaf_global; }
