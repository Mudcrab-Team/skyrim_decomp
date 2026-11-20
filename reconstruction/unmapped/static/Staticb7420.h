// Source exposure: binary-analysis
// Staticb7420, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7420;
extern void construct(Staticb7420*, const Descriptor*);
extern void destroy(Staticb7420*);
struct Staticb7420 {
    void* value;
    Staticb7420() { construct(this, &descriptor); }
    ~Staticb7420() { destroy(this); }
};
