// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1514400, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1514400 LeafAddress1514400::Address
#include "LeafAddress1514400.h"
extern unsigned char leaf_global;
void* LeafAddress1514400::Address() { return &leaf_global; }
