// Source exposure: binary-analysis
// Statica30b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica30b0;
extern void construct(Statica30b0*, const Descriptor*);
extern void destroy(Statica30b0*);
struct Statica30b0 {
    void* value;
    Statica30b0() { construct(this, &descriptor); }
    ~Statica30b0() { destroy(this); }
};
