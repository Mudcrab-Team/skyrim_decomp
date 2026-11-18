// Source exposure: binary-analysis
// Statice8ac0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statice8ac0;
extern void construct(Statice8ac0*, const Descriptor*);
extern void destroy(Statice8ac0*);
struct Statice8ac0 {
    void* value;
    Statice8ac0() { construct(this, &descriptor); }
    ~Statice8ac0() { destroy(this); }
};
