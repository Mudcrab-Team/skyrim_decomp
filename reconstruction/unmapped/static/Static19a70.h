// Source exposure: binary-analysis
// Static19a70, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static19a70;
extern void construct(Static19a70*, const Descriptor*);
extern void destroy(Static19a70*);
struct Static19a70 {
    void* value;
    Static19a70() { construct(this, &descriptor); }
    ~Static19a70() { destroy(this); }
};
