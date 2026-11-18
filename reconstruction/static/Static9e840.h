// Source exposure: binary-analysis
// Static9e840, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9e840;
extern void construct(Static9e840*, const Descriptor*);
extern void destroy(Static9e840*);
struct Static9e840 {
    void* value;
    Static9e840() { construct(this, &descriptor); }
    ~Static9e840() { destroy(this); }
};
