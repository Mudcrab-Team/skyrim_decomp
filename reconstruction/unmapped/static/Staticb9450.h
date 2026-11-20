// Source exposure: binary-analysis
// Staticb9450, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb9450;
extern void construct(Staticb9450*, const Descriptor*);
extern void destroy(Staticb9450*);
struct Staticb9450 {
    void* value;
    Staticb9450() { construct(this, &descriptor); }
    ~Staticb9450() { destroy(this); }
};
