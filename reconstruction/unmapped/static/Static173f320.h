// Source exposure: binary-analysis; no external implementation source reused.
// Static173f320, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173f320;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173f320*);
    virtual void release(Static173f320*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173f320*);
struct Static173f320 {
    void* value;
    Static173f320();
    ~Static173f320() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
