// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress7dfd70, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x7dfd70 LeafAddress7dfd70::Address
#include "LeafAddress7dfd70.h"
extern unsigned char leaf_global;
void* LeafAddress7dfd70::Address() { return &leaf_global; }
