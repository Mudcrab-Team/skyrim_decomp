// Source exposure: binary-analysis
// Staticb99e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb99e0;
extern void construct(Staticb99e0*, const Descriptor*);
extern void destroy(Staticb99e0*);
struct Staticb99e0 {
    void* value;
    Staticb99e0() { construct(this, &descriptor); }
    ~Staticb99e0() { destroy(this); }
};
