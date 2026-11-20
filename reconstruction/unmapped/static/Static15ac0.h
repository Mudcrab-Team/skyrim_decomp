// Source exposure: binary-analysis
// Static15ac0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15ac0;
extern void construct(Static15ac0*, const Descriptor*);
extern void destroy(Static15ac0*);
struct Static15ac0 {
    void* value;
    Static15ac0() { construct(this, &descriptor); }
    ~Static15ac0() { destroy(this); }
};
