// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1333b0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1333b0 LeafAddress1333b0::Address
#include "LeafAddress1333b0.h"
extern unsigned char leaf_global;
void* LeafAddress1333b0::Address() { return &leaf_global; }
