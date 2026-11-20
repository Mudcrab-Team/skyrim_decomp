// Source exposure: binary-analysis; no external implementation source reused.
// Static173d150, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173d150;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173d150*);
    virtual void release(Static173d150*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173d150*);
struct Static173d150 {
    void* value;
    Static173d150();
    ~Static173d150() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
