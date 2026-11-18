// Source exposure: binary-analysis
// Static81f10, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static81f10;
extern void construct(Static81f10*, const Descriptor*);
extern void destroy(Static81f10*);
struct Static81f10 {
    void* value;
    Static81f10() { construct(this, &descriptor); }
    ~Static81f10() { destroy(this); }
};
