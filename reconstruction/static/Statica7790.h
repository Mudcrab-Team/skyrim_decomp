// Source exposure: binary-analysis
// Statica7790, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica7790;
extern void construct(Statica7790*, const Descriptor*);
extern void destroy(Statica7790*);
struct Statica7790 {
    void* value;
    Statica7790() { construct(this, &descriptor); }
    ~Statica7790() { destroy(this); }
};
