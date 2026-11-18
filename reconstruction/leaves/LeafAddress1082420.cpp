// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1082420, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1082420 LeafAddress1082420::Address
#include "LeafAddress1082420.h"
extern unsigned char leaf_global;
void* LeafAddress1082420::Address() { return &leaf_global; }
