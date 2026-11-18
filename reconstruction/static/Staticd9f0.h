// Source exposure: binary-analysis
// Staticd9f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd9f0;
extern void construct(Staticd9f0*, const Descriptor*);
extern void destroy(Staticd9f0*);
struct Staticd9f0 {
    void* value;
    Staticd9f0() { construct(this, &descriptor); }
    ~Staticd9f0() { destroy(this); }
};
