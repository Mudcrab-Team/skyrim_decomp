// Source exposure: binary-analysis; no external implementation source reused.
// Static177b190, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177b190;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177b190*);
    virtual void release(Static177b190*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177b190*);
struct Static177b190 {
    void* value;
    Static177b190();
    ~Static177b190() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
