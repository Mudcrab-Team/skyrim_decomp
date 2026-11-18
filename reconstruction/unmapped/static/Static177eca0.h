// Source exposure: binary-analysis; no external implementation source reused.
// Static177eca0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177eca0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177eca0*);
    virtual void release(Static177eca0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177eca0*);
struct Static177eca0 {
    void* value;
    Static177eca0();
    ~Static177eca0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
