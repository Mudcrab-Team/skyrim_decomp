// Source exposure: binary-analysis
// Staticb9270, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb9270;
extern void construct(Staticb9270*, const Descriptor*);
extern void destroy(Staticb9270*);
struct Staticb9270 {
    void* value;
    Staticb9270() { construct(this, &descriptor); }
    ~Staticb9270() { destroy(this); }
};
