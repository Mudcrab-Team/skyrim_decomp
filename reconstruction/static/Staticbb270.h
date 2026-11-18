// Source exposure: binary-analysis
// Staticbb270, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbb270;
extern void construct(Staticbb270*, const Descriptor*);
extern void destroy(Staticbb270*);
struct Staticbb270 {
    void* value;
    Staticbb270() { construct(this, &descriptor); }
    ~Staticbb270() { destroy(this); }
};
