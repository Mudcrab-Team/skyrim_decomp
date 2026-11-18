// Source exposure: binary-analysis; no external implementation source reused.
// Static173ddd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173ddd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173ddd0*);
    virtual void release(Static173ddd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173ddd0*);
struct Static173ddd0 {
    void* value;
    Static173ddd0();
    ~Static173ddd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
