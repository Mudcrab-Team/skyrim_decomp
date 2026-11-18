// Source exposure: binary-analysis; no external implementation source reused.
// Static1764df0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1764df0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1764df0*);
    virtual void release(Static1764df0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1764df0*);
struct Static1764df0 {
    void* value;
    Static1764df0();
    ~Static1764df0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
