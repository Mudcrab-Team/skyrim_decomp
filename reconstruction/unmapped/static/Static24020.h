// Source exposure: binary-analysis
// Static24020, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static24020;
extern void construct(Static24020*, const Descriptor*);
extern void destroy(Static24020*);
struct Static24020 {
    void* value;
    Static24020() { construct(this, &descriptor); }
    ~Static24020() { destroy(this); }
};
