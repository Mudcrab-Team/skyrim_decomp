// Source exposure: binary-analysis; no external implementation source reused.
// Static177aec0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177aec0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177aec0*);
    virtual void release(Static177aec0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177aec0*);
struct Static177aec0 {
    void* value;
    Static177aec0();
    ~Static177aec0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
