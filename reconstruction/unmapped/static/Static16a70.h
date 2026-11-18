// Source exposure: binary-analysis
// Static16a70, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static16a70;
extern void construct(Static16a70*, const Descriptor*);
extern void destroy(Static16a70*);
struct Static16a70 {
    void* value;
    Static16a70() { construct(this, &descriptor); }
    ~Static16a70() { destroy(this); }
};
