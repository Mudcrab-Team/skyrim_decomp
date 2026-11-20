// Source exposure: binary-analysis; no external implementation source reused.
// Static177b140, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177b140;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177b140*);
    virtual void release(Static177b140*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177b140*);
struct Static177b140 {
    void* value;
    Static177b140();
    ~Static177b140() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
