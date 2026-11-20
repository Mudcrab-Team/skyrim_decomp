// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1055c00, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1055c00 LeafAddress1055c00::Address
#include "LeafAddress1055c00.h"
extern unsigned char leaf_global;
void* LeafAddress1055c00::Address() { return &leaf_global; }
