// Source exposure: binary-analysis; no external implementation source reused.
// Static173d560, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173d560;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173d560*);
    virtual void release(Static173d560*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173d560*);
struct Static173d560 {
    void* value;
    Static173d560();
    ~Static173d560() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
