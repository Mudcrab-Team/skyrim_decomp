// Source exposure: binary-analysis
// Staticb55e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb55e0;
extern void construct(Staticb55e0*, const Descriptor*);
extern void destroy(Staticb55e0*);
struct Staticb55e0 {
    void* value;
    Staticb55e0() { construct(this, &descriptor); }
    ~Staticb55e0() { destroy(this); }
};
