// Source exposure: binary-analysis
// Static101320, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static101320;
extern void construct(Static101320*, const Descriptor*);
extern void destroy(Static101320*);
struct Static101320 {
    void* value;
    Static101320() { construct(this, &descriptor); }
    ~Static101320() { destroy(this); }
};
