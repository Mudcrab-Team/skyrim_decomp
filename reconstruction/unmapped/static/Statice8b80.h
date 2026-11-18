// Source exposure: binary-analysis
// Statice8b80, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statice8b80;
extern void construct(Statice8b80*, const Descriptor*);
extern void destroy(Statice8b80*);
struct Statice8b80 {
    void* value;
    Statice8b80() { construct(this, &descriptor); }
    ~Statice8b80() { destroy(this); }
};
