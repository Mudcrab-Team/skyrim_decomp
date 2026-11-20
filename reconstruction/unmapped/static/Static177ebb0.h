// Source exposure: binary-analysis; no external implementation source reused.
// Static177ebb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177ebb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177ebb0*);
    virtual void release(Static177ebb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177ebb0*);
struct Static177ebb0 {
    void* value;
    Static177ebb0();
    ~Static177ebb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
