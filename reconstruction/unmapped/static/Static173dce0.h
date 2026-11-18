// Source exposure: binary-analysis; no external implementation source reused.
// Static173dce0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173dce0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173dce0*);
    virtual void release(Static173dce0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173dce0*);
struct Static173dce0 {
    void* value;
    Static173dce0();
    ~Static173dce0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
