// Source exposure: binary-analysis
// Static9f580, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9f580;
extern void construct(Static9f580*, const Descriptor*);
extern void destroy(Static9f580*);
struct Static9f580 {
    void* value;
    Static9f580() { construct(this, &descriptor); }
    ~Static9f580() { destroy(this); }
};
