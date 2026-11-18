// Source exposure: binary-analysis
// Static9e990, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9e990;
extern void construct(Static9e990*, const Descriptor*);
extern void destroy(Static9e990*);
struct Static9e990 {
    void* value;
    Static9e990() { construct(this, &descriptor); }
    ~Static9e990() { destroy(this); }
};
