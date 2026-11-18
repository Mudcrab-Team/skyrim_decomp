// Source exposure: binary-analysis; no external implementation source reused.
// Static174f220, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174f220;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174f220*);
    virtual void release(Static174f220*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174f220*);
struct Static174f220 {
    void* value;
    Static174f220();
    ~Static174f220() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
