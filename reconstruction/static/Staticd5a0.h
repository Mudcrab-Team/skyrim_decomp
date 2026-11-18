// Source exposure: binary-analysis
// Staticd5a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd5a0;
extern void construct(Staticd5a0*, const Descriptor*);
extern void destroy(Staticd5a0*);
struct Staticd5a0 {
    void* value;
    Staticd5a0() { construct(this, &descriptor); }
    ~Staticd5a0() { destroy(this); }
};
