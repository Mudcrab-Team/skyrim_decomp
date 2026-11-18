// Source exposure: binary-analysis
// Static19930, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static19930;
extern void construct(Static19930*, const Descriptor*);
extern void destroy(Static19930*);
struct Static19930 {
    void* value;
    Static19930() { construct(this, &descriptor); }
    ~Static19930() { destroy(this); }
};
