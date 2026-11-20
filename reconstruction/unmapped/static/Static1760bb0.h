// Source exposure: binary-analysis; no external implementation source reused.
// Static1760bb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1760bb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1760bb0*);
    virtual void release(Static1760bb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1760bb0*);
struct Static1760bb0 {
    void* value;
    Static1760bb0();
    ~Static1760bb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
