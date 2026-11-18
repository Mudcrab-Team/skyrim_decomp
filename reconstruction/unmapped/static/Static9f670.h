// Source exposure: binary-analysis
// Static9f670, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9f670;
extern void construct(Static9f670*, const Descriptor*);
extern void destroy(Static9f670*);
struct Static9f670 {
    void* value;
    Static9f670() { construct(this, &descriptor); }
    ~Static9f670() { destroy(this); }
};
