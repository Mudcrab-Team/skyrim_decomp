// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1048650, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1048650 LeafAddress1048650::Address
#include "LeafAddress1048650.h"
extern unsigned char leaf_global;
void* LeafAddress1048650::Address() { return &leaf_global; }
