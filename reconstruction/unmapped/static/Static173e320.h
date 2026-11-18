// Source exposure: binary-analysis; no external implementation source reused.
// Static173e320, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173e320;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173e320*);
    virtual void release(Static173e320*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173e320*);
struct Static173e320 {
    void* value;
    Static173e320();
    ~Static173e320() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
