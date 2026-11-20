// Source exposure: binary-analysis
// Statice9300, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statice9300;
extern void construct(Statice9300*, const Descriptor*);
extern void destroy(Statice9300*);
struct Statice9300 {
    void* value;
    Statice9300() { construct(this, &descriptor); }
    ~Statice9300() { destroy(this); }
};
