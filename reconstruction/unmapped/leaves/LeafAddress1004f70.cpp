// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1004f70, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1004f70 LeafAddress1004f70::Address
#include "LeafAddress1004f70.h"
extern unsigned char leaf_global;
void* LeafAddress1004f70::Address() { return &leaf_global; }
