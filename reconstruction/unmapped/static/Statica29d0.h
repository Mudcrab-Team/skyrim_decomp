// Source exposure: binary-analysis
// Statica29d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica29d0;
extern void construct(Statica29d0*, const Descriptor*);
extern void destroy(Statica29d0*);
struct Statica29d0 {
    void* value;
    Statica29d0() { construct(this, &descriptor); }
    ~Statica29d0() { destroy(this); }
};
