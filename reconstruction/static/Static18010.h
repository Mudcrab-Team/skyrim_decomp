// Source exposure: binary-analysis
// Static18010, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static18010;
extern void construct(Static18010*, const Descriptor*);
extern void destroy(Static18010*);
struct Static18010 {
    void* value;
    Static18010() { construct(this, &descriptor); }
    ~Static18010() { destroy(this); }
};
