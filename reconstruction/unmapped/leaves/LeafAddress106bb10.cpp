// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress106bb10, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x106bb10 LeafAddress106bb10::Address
#include "LeafAddress106bb10.h"
extern unsigned char leaf_global;
void* LeafAddress106bb10::Address() { return &leaf_global; }
