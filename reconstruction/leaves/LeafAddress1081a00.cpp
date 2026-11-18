// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1081a00, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1081a00 LeafAddress1081a00::Address
#include "LeafAddress1081a00.h"
extern unsigned char leaf_global;
void* LeafAddress1081a00::Address() { return &leaf_global; }
