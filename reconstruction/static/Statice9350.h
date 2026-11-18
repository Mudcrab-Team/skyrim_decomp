// Source exposure: binary-analysis
// Statice9350, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statice9350;
extern void construct(Statice9350*, const Descriptor*);
extern void destroy(Statice9350*);
struct Statice9350 {
    void* value;
    Statice9350() { construct(this, &descriptor); }
    ~Statice9350() { destroy(this); }
};
