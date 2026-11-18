// Source exposure: binary-analysis
// Statica0b10, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica0b10;
extern void construct(Statica0b10*, const Descriptor*);
extern void destroy(Statica0b10*);
struct Statica0b10 {
    void* value;
    Statica0b10() { construct(this, &descriptor); }
    ~Statica0b10() { destroy(this); }
};
