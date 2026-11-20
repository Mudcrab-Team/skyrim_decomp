// Source exposure: binary-analysis
// Static21580, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static21580;
extern void construct(Static21580*, const Descriptor*);
extern void destroy(Static21580*);
struct Static21580 {
    void* value;
    Static21580() { construct(this, &descriptor); }
    ~Static21580() { destroy(this); }
};
