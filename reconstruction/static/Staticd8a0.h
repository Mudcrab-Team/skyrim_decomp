// Source exposure: binary-analysis
// Staticd8a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd8a0;
extern void construct(Staticd8a0*, const Descriptor*);
extern void destroy(Staticd8a0*);
struct Staticd8a0 {
    void* value;
    Staticd8a0() { construct(this, &descriptor); }
    ~Staticd8a0() { destroy(this); }
};
