// Source exposure: binary-analysis
// Static9ab70, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9ab70;
extern void construct(Static9ab70*, const Descriptor*);
extern void destroy(Static9ab70*);
struct Static9ab70 {
    void* value;
    Static9ab70() { construct(this, &descriptor); }
    ~Static9ab70() { destroy(this); }
};
