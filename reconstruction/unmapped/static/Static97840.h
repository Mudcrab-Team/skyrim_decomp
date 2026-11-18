// Source exposure: binary-analysis
// Static97840, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static97840;
extern void construct(Static97840*, const Descriptor*);
extern void destroy(Static97840*);
struct Static97840 {
    void* value;
    Static97840() { construct(this, &descriptor); }
    ~Static97840() { destroy(this); }
};
