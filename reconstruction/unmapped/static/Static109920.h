// Source exposure: binary-analysis
// Static109920, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static109920;
extern void construct(Static109920*, const Descriptor*);
extern void destroy(Static109920*);
struct Static109920 {
    void* value;
    Static109920() { construct(this, &descriptor); }
    ~Static109920() { destroy(this); }
};
