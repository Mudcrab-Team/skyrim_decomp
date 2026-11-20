// Source exposure: binary-analysis
// Statica65c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica65c0;
extern void construct(Statica65c0*, const Descriptor*);
extern void destroy(Statica65c0*);
struct Statica65c0 {
    void* value;
    Statica65c0() { construct(this, &descriptor); }
    ~Statica65c0() { destroy(this); }
};
