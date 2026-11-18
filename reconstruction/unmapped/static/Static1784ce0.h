// Source exposure: binary-analysis; no external implementation source reused.
// Static1784ce0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1784ce0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1784ce0*);
    virtual void release(Static1784ce0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1784ce0*);
struct Static1784ce0 {
    void* value;
    Static1784ce0();
    ~Static1784ce0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
