// Source exposure: binary-analysis
// Staticf34c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticf34c0;
extern void construct(Staticf34c0*, const Descriptor*);
extern void destroy(Staticf34c0*);
struct Staticf34c0 {
    void* value;
    Staticf34c0() { construct(this, &descriptor); }
    ~Staticf34c0() { destroy(this); }
};
