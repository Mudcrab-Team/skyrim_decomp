// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1085170, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1085170 LeafAddress1085170::Address
#include "LeafAddress1085170.h"
extern unsigned char leaf_global;
void* LeafAddress1085170::Address() { return &leaf_global; }
