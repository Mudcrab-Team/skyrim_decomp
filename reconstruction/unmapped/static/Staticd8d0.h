// Source exposure: binary-analysis
// Staticd8d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd8d0;
extern void construct(Staticd8d0*, const Descriptor*);
extern void destroy(Staticd8d0*);
struct Staticd8d0 {
    void* value;
    Staticd8d0() { construct(this, &descriptor); }
    ~Staticd8d0() { destroy(this); }
};
