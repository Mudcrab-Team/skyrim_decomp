// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress485640, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x485640 LeafAddress485640::Address
#include "LeafAddress485640.h"
extern unsigned char leaf_global;
void* LeafAddress485640::Address() { return &leaf_global; }
