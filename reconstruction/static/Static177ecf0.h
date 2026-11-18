// Source exposure: binary-analysis; no external implementation source reused.
// Static177ecf0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177ecf0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177ecf0*);
    virtual void release(Static177ecf0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177ecf0*);
struct Static177ecf0 {
    void* value;
    Static177ecf0();
    ~Static177ecf0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
