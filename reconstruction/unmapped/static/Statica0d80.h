// Source exposure: binary-analysis
// Statica0d80, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica0d80;
extern void construct(Statica0d80*, const Descriptor*);
extern void destroy(Statica0d80*);
struct Statica0d80 {
    void* value;
    Statica0d80() { construct(this, &descriptor); }
    ~Statica0d80() { destroy(this); }
};
