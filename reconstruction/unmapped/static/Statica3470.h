// Source exposure: binary-analysis
// Statica3470, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica3470;
extern void construct(Statica3470*, const Descriptor*);
extern void destroy(Statica3470*);
struct Statica3470 {
    void* value;
    Statica3470() { construct(this, &descriptor); }
    ~Statica3470() { destroy(this); }
};
