// Source exposure: binary-analysis
// Staticd810, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd810;
extern void construct(Staticd810*, const Descriptor*);
extern void destroy(Staticd810*);
struct Staticd810 {
    void* value;
    Staticd810() { construct(this, &descriptor); }
    ~Staticd810() { destroy(this); }
};
