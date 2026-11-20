// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1570120, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1570120 LeafAddress1570120::Address
#include "LeafAddress1570120.h"
extern unsigned char leaf_global;
void* LeafAddress1570120::Address() { return &leaf_global; }
