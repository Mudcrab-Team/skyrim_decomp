// Source exposure: binary-analysis
// Staticd4e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd4e0;
extern void construct(Staticd4e0*, const Descriptor*);
extern void destroy(Staticd4e0*);
struct Staticd4e0 {
    void* value;
    Staticd4e0() { construct(this, &descriptor); }
    ~Staticd4e0() { destroy(this); }
};
