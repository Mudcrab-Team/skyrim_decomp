// Source exposure: binary-analysis
// Static9e930, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9e930;
extern void construct(Static9e930*, const Descriptor*);
extern void destroy(Static9e930*);
struct Static9e930 {
    void* value;
    Static9e930() { construct(this, &descriptor); }
    ~Static9e930() { destroy(this); }
};
