// Source exposure: binary-analysis
// Statice8a30, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statice8a30;
extern void construct(Statice8a30*, const Descriptor*);
extern void destroy(Statice8a30*);
struct Statice8a30 {
    void* value;
    Statice8a30() { construct(this, &descriptor); }
    ~Statice8a30() { destroy(this); }
};
