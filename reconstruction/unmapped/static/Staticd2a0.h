// Source exposure: binary-analysis
// Staticd2a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd2a0;
extern void construct(Staticd2a0*, const Descriptor*);
extern void destroy(Staticd2a0*);
struct Staticd2a0 {
    void* value;
    Staticd2a0() { construct(this, &descriptor); }
    ~Staticd2a0() { destroy(this); }
};
