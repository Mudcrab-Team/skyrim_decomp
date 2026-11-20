// Source exposure: binary-analysis; no external implementation source reused.
// Static1755da0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1755da0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1755da0*);
    virtual void release(Static1755da0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1755da0*);
struct Static1755da0 {
    void* value;
    Static1755da0();
    ~Static1755da0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
