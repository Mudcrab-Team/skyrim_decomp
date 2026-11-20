// Source exposure: binary-analysis; no external implementation source reused.
// Static177b320, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177b320;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177b320*);
    virtual void release(Static177b320*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177b320*);
struct Static177b320 {
    void* value;
    Static177b320();
    ~Static177b320() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
