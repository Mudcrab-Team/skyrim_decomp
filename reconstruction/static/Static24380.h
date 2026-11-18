// Source exposure: binary-analysis
// Static24380, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static24380;
extern void construct(Static24380*, const Descriptor*);
extern void destroy(Static24380*);
struct Static24380 {
    void* value;
    Static24380() { construct(this, &descriptor); }
    ~Static24380() { destroy(this); }
};
