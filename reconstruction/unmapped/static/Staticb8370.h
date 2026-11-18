// Source exposure: binary-analysis
// Staticb8370, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb8370;
extern void construct(Staticb8370*, const Descriptor*);
extern void destroy(Staticb8370*);
struct Staticb8370 {
    void* value;
    Staticb8370() { construct(this, &descriptor); }
    ~Staticb8370() { destroy(this); }
};
