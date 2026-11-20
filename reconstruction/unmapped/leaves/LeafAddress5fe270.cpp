// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress5fe270, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x5fe270 LeafAddress5fe270::Address
#include "LeafAddress5fe270.h"
extern unsigned char leaf_global;
void* LeafAddress5fe270::Address() { return &leaf_global; }
