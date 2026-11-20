// Source exposure: binary-analysis
// Static101440, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static101440;
extern void construct(Static101440*, const Descriptor*);
extern void destroy(Static101440*);
struct Static101440 {
    void* value;
    Static101440() { construct(this, &descriptor); }
    ~Static101440() { destroy(this); }
};
