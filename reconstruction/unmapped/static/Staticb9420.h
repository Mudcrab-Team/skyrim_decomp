// Source exposure: binary-analysis
// Staticb9420, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb9420;
extern void construct(Staticb9420*, const Descriptor*);
extern void destroy(Staticb9420*);
struct Staticb9420 {
    void* value;
    Staticb9420() { construct(this, &descriptor); }
    ~Staticb9420() { destroy(this); }
};
