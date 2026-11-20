// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress465390, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x465390 LeafAddress465390::Address
#include "LeafAddress465390.h"
extern unsigned char leaf_global;
void* LeafAddress465390::Address() { return &leaf_global; }
