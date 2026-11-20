// Source exposure: binary-analysis
// Static18040, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static18040;
extern void construct(Static18040*, const Descriptor*);
extern void destroy(Static18040*);
struct Static18040 {
    void* value;
    Static18040() { construct(this, &descriptor); }
    ~Static18040() { destroy(this); }
};
