// Source exposure: binary-analysis
// Staticd5d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd5d0;
extern void construct(Staticd5d0*, const Descriptor*);
extern void destroy(Staticd5d0*);
struct Staticd5d0 {
    void* value;
    Staticd5d0() { construct(this, &descriptor); }
    ~Staticd5d0() { destroy(this); }
};
