// Source exposure: binary-analysis
// Staticb7ac0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7ac0;
extern void construct(Staticb7ac0*, const Descriptor*);
extern void destroy(Staticb7ac0*);
struct Staticb7ac0 {
    void* value;
    Staticb7ac0() { construct(this, &descriptor); }
    ~Staticb7ac0() { destroy(this); }
};
