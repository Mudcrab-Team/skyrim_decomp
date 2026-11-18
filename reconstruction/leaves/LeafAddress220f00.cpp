// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress220f00, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x220f00 LeafAddress220f00::Address
#include "LeafAddress220f00.h"
extern unsigned char leaf_global;
void* LeafAddress220f00::Address() { return &leaf_global; }
