// Source exposure: binary-analysis
// Statice9590, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statice9590;
extern void construct(Statice9590*, const Descriptor*);
extern void destroy(Statice9590*);
struct Statice9590 {
    void* value;
    Statice9590() { construct(this, &descriptor); }
    ~Statice9590() { destroy(this); }
};
