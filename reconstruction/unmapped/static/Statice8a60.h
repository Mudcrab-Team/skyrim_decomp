// Source exposure: binary-analysis
// Statice8a60, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statice8a60;
extern void construct(Statice8a60*, const Descriptor*);
extern void destroy(Statice8a60*);
struct Statice8a60 {
    void* value;
    Statice8a60() { construct(this, &descriptor); }
    ~Statice8a60() { destroy(this); }
};
