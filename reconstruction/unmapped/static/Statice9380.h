// Source exposure: binary-analysis
// Statice9380, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statice9380;
extern void construct(Statice9380*, const Descriptor*);
extern void destroy(Statice9380*);
struct Statice9380 {
    void* value;
    Statice9380() { construct(this, &descriptor); }
    ~Statice9380() { destroy(this); }
};
