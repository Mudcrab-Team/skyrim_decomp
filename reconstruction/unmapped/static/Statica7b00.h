// Source exposure: binary-analysis
// Statica7b00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica7b00;
extern void construct(Statica7b00*, const Descriptor*);
extern void destroy(Statica7b00*);
struct Statica7b00 {
    void* value;
    Statica7b00() { construct(this, &descriptor); }
    ~Statica7b00() { destroy(this); }
};
