// Source exposure: binary-analysis; no external implementation source reused.
// Static177bc80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177bc80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177bc80*);
    virtual void release(Static177bc80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177bc80*);
struct Static177bc80 {
    void* value;
    Static177bc80();
    ~Static177bc80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
