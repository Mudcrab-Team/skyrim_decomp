// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress108f220, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x108f220 LeafAddress108f220::Address
#include "LeafAddress108f220.h"
extern unsigned char leaf_global;
void* LeafAddress108f220::Address() { return &leaf_global; }
