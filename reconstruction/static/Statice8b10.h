// Source exposure: binary-analysis
// Statice8b10, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statice8b10;
extern void construct(Statice8b10*, const Descriptor*);
extern void destroy(Statice8b10*);
struct Statice8b10 {
    void* value;
    Statice8b10() { construct(this, &descriptor); }
    ~Statice8b10() { destroy(this); }
};
