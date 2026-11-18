// Source exposure: binary-analysis
// Staticd3c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd3c0;
extern void construct(Staticd3c0*, const Descriptor*);
extern void destroy(Staticd3c0*);
struct Staticd3c0 {
    void* value;
    Staticd3c0() { construct(this, &descriptor); }
    ~Staticd3c0() { destroy(this); }
};
