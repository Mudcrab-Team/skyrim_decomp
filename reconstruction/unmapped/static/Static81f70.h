// Source exposure: binary-analysis
// Static81f70, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static81f70;
extern void construct(Static81f70*, const Descriptor*);
extern void destroy(Static81f70*);
struct Static81f70 {
    void* value;
    Static81f70() { construct(this, &descriptor); }
    ~Static81f70() { destroy(this); }
};
