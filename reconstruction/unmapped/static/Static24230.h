// Source exposure: binary-analysis
// Static24230, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static24230;
extern void construct(Static24230*, const Descriptor*);
extern void destroy(Static24230*);
struct Static24230 {
    void* value;
    Static24230() { construct(this, &descriptor); }
    ~Static24230() { destroy(this); }
};
