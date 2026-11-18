// Source exposure: binary-analysis
// Statica01b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica01b0;
extern void construct(Statica01b0*, const Descriptor*);
extern void destroy(Statica01b0*);
struct Statica01b0 {
    void* value;
    Statica01b0() { construct(this, &descriptor); }
    ~Statica01b0() { destroy(this); }
};
