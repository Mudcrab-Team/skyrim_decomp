// Source exposure: binary-analysis
// Static109a40, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static109a40;
extern void construct(Static109a40*, const Descriptor*);
extern void destroy(Static109a40*);
struct Static109a40 {
    void* value;
    Static109a40() { construct(this, &descriptor); }
    ~Static109a40() { destroy(this); }
};
