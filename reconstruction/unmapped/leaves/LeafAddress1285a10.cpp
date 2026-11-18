// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1285a10, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1285a10 LeafAddress1285a10::Address
#include "LeafAddress1285a10.h"
extern unsigned char leaf_global;
void* LeafAddress1285a10::Address() { return &leaf_global; }
