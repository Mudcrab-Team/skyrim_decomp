// Source exposure: binary-analysis
// Statice9240, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statice9240;
extern void construct(Statice9240*, const Descriptor*);
extern void destroy(Statice9240*);
struct Statice9240 {
    void* value;
    Statice9240() { construct(this, &descriptor); }
    ~Statice9240() { destroy(this); }
};
