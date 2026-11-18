// Source exposure: binary-analysis
// Staticb58b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb58b0;
extern void construct(Staticb58b0*, const Descriptor*);
extern void destroy(Staticb58b0*);
struct Staticb58b0 {
    void* value;
    Staticb58b0() { construct(this, &descriptor); }
    ~Staticb58b0() { destroy(this); }
};
