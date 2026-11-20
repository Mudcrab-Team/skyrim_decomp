// Source exposure: binary-analysis
// Staticb4dd0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb4dd0;
extern void construct(Staticb4dd0*, const Descriptor*);
extern void destroy(Staticb4dd0*);
struct Staticb4dd0 {
    void* value;
    Staticb4dd0() { construct(this, &descriptor); }
    ~Staticb4dd0() { destroy(this); }
};
