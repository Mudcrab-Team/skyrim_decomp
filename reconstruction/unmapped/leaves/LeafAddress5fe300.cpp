// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress5fe300, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x5fe300 LeafAddress5fe300::Address
#include "LeafAddress5fe300.h"
extern unsigned char leaf_global;
void* LeafAddress5fe300::Address() { return &leaf_global; }
