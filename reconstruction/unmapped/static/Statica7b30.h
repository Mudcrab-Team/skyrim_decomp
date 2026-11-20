// Source exposure: binary-analysis
// Statica7b30, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica7b30;
extern void construct(Statica7b30*, const Descriptor*);
extern void destroy(Statica7b30*);
struct Statica7b30 {
    void* value;
    Statica7b30() { construct(this, &descriptor); }
    ~Statica7b30() { destroy(this); }
};
