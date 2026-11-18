// Source exposure: binary-analysis
// Statica69b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica69b0;
extern void construct(Statica69b0*, const Descriptor*);
extern void destroy(Statica69b0*);
struct Statica69b0 {
    void* value;
    Statica69b0() { construct(this, &descriptor); }
    ~Statica69b0() { destroy(this); }
};
