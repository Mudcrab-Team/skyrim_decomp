// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressc49890, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xc49890 LeafAddressc49890::Address
#include "LeafAddressc49890.h"
extern unsigned char leaf_global;
void* LeafAddressc49890::Address() { return &leaf_global; }
