// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1099740, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1099740 LeafAddress1099740::Address
#include "LeafAddress1099740.h"
extern unsigned char leaf_global;
void* LeafAddress1099740::Address() { return &leaf_global; }
