// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress15a9724, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x15a9724 LeafAddress15a9724::Address
#include "LeafAddress15a9724.h"
extern unsigned char leaf_global;
void* LeafAddress15a9724::Address() { return &leaf_global; }
