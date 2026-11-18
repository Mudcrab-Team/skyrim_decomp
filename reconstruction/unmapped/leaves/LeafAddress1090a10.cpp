// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1090a10, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1090a10 LeafAddress1090a10::Address
#include "LeafAddress1090a10.h"
extern unsigned char leaf_global;
void* LeafAddress1090a10::Address() { return &leaf_global; }
