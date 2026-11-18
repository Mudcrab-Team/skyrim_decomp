// Source exposure: binary-analysis
// Staticb59d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb59d0;
extern void construct(Staticb59d0*, const Descriptor*);
extern void destroy(Staticb59d0*);
struct Staticb59d0 {
    void* value;
    Staticb59d0() { construct(this, &descriptor); }
    ~Staticb59d0() { destroy(this); }
};
