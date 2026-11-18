// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress474090, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x474090 LeafAddress474090::Address
#include "LeafAddress474090.h"
extern unsigned char leaf_global;
void* LeafAddress474090::Address() { return &leaf_global; }
