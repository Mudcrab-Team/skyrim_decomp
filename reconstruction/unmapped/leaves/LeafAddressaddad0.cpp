// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressaddad0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xaddad0 LeafAddressaddad0::Address
#include "LeafAddressaddad0.h"
extern unsigned char leaf_global;
void* LeafAddressaddad0::Address() { return &leaf_global; }
