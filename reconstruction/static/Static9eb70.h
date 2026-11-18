// Source exposure: binary-analysis
// Static9eb70, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9eb70;
extern void construct(Static9eb70*, const Descriptor*);
extern void destroy(Static9eb70*);
struct Static9eb70 {
    void* value;
    Static9eb70() { construct(this, &descriptor); }
    ~Static9eb70() { destroy(this); }
};
