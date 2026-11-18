// Source exposure: binary-analysis; no external implementation source reused.
// Static177bbe0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177bbe0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177bbe0*);
    virtual void release(Static177bbe0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177bbe0*);
struct Static177bbe0 {
    void* value;
    Static177bbe0();
    ~Static177bbe0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
