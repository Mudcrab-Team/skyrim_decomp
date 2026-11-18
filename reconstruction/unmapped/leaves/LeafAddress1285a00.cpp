// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1285a00, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1285a00 LeafAddress1285a00::Address
#include "LeafAddress1285a00.h"
extern unsigned char leaf_global;
void* LeafAddress1285a00::Address() { return &leaf_global; }
