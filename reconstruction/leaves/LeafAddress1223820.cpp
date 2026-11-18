// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1223820, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1223820 LeafAddress1223820::Address
#include "LeafAddress1223820.h"
extern unsigned char leaf_global;
void* LeafAddress1223820::Address() { return &leaf_global; }
