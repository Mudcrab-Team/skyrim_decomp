// Source exposure: binary-analysis
// Staticb92a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb92a0;
extern void construct(Staticb92a0*, const Descriptor*);
extern void destroy(Staticb92a0*);
struct Staticb92a0 {
    void* value;
    Staticb92a0() { construct(this, &descriptor); }
    ~Staticb92a0() { destroy(this); }
};
