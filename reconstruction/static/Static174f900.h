// Source exposure: binary-analysis; no external implementation source reused.
// Static174f900, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174f900;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174f900*);
    virtual void release(Static174f900*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174f900*);
struct Static174f900 {
    void* value;
    Static174f900();
    ~Static174f900() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
