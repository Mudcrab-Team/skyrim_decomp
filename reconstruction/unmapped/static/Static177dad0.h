// Source exposure: binary-analysis; no external implementation source reused.
// Static177dad0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177dad0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177dad0*);
    virtual void release(Static177dad0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177dad0*);
struct Static177dad0 {
    void* value;
    Static177dad0();
    ~Static177dad0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
