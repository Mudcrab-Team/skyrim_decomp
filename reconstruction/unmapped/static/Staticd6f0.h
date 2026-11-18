// Source exposure: binary-analysis
// Staticd6f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd6f0;
extern void construct(Staticd6f0*, const Descriptor*);
extern void destroy(Staticd6f0*);
struct Staticd6f0 {
    void* value;
    Staticd6f0() { construct(this, &descriptor); }
    ~Staticd6f0() { destroy(this); }
};
