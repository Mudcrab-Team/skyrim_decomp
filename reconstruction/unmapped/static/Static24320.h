// Source exposure: binary-analysis
// Static24320, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static24320;
extern void construct(Static24320*, const Descriptor*);
extern void destroy(Static24320*);
struct Static24320 {
    void* value;
    Static24320() { construct(this, &descriptor); }
    ~Static24320() { destroy(this); }
};
