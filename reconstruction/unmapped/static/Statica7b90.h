// Source exposure: binary-analysis
// Statica7b90, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica7b90;
extern void construct(Statica7b90*, const Descriptor*);
extern void destroy(Statica7b90*);
struct Statica7b90 {
    void* value;
    Statica7b90() { construct(this, &descriptor); }
    ~Statica7b90() { destroy(this); }
};
