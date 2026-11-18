// Source exposure: binary-analysis
// Statica0c90, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica0c90;
extern void construct(Statica0c90*, const Descriptor*);
extern void destroy(Statica0c90*);
struct Statica0c90 {
    void* value;
    Statica0c90() { construct(this, &descriptor); }
    ~Statica0c90() { destroy(this); }
};
