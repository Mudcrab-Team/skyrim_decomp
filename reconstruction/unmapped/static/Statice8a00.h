// Source exposure: binary-analysis
// Statice8a00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statice8a00;
extern void construct(Statice8a00*, const Descriptor*);
extern void destroy(Statice8a00*);
struct Statice8a00 {
    void* value;
    Statice8a00() { construct(this, &descriptor); }
    ~Statice8a00() { destroy(this); }
};
