// Source exposure: binary-analysis
// Static101260, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static101260;
extern void construct(Static101260*, const Descriptor*);
extern void destroy(Static101260*);
struct Static101260 {
    void* value;
    Static101260() { construct(this, &descriptor); }
    ~Static101260() { destroy(this); }
};
