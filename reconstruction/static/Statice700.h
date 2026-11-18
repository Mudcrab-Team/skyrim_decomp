// Source exposure: binary-analysis
// Statice700, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statice700;
extern void construct(Statice700*, const Descriptor*);
extern void destroy(Statice700*);
struct Statice700 {
    void* value;
    Statice700() { construct(this, &descriptor); }
    ~Statice700() { destroy(this); }
};
