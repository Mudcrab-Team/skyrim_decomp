// Source exposure: binary-analysis
// Staticd9c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd9c0;
extern void construct(Staticd9c0*, const Descriptor*);
extern void destroy(Staticd9c0*);
struct Staticd9c0 {
    void* value;
    Staticd9c0() { construct(this, &descriptor); }
    ~Staticd9c0() { destroy(this); }
};
