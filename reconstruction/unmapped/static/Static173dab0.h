// Source exposure: binary-analysis; no external implementation source reused.
// Static173dab0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173dab0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173dab0*);
    virtual void release(Static173dab0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173dab0*);
struct Static173dab0 {
    void* value;
    Static173dab0();
    ~Static173dab0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
