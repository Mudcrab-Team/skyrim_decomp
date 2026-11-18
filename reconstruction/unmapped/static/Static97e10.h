// Source exposure: binary-analysis
// Static97e10, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static97e10;
extern void construct(Static97e10*, const Descriptor*);
extern void destroy(Static97e10*);
struct Static97e10 {
    void* value;
    Static97e10() { construct(this, &descriptor); }
    ~Static97e10() { destroy(this); }
};
