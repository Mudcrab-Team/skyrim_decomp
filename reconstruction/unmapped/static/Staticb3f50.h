// Source exposure: binary-analysis
// Staticb3f50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb3f50;
extern void construct(Staticb3f50*, const Descriptor*);
extern void destroy(Staticb3f50*);
struct Staticb3f50 {
    void* value;
    Staticb3f50() { construct(this, &descriptor); }
    ~Staticb3f50() { destroy(this); }
};
