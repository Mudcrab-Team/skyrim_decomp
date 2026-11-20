// Source exposure: binary-analysis
// Static81f40, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static81f40;
extern void construct(Static81f40*, const Descriptor*);
extern void destroy(Static81f40*);
struct Static81f40 {
    void* value;
    Static81f40() { construct(this, &descriptor); }
    ~Static81f40() { destroy(this); }
};
