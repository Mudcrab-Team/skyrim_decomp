// Source exposure: binary-analysis
// Staticb6620, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb6620;
extern void construct(Staticb6620*, const Descriptor*);
extern void destroy(Staticb6620*);
struct Staticb6620 {
    void* value;
    Staticb6620() { construct(this, &descriptor); }
    ~Staticb6620() { destroy(this); }
};
