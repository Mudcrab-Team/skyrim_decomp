// Source exposure: binary-analysis; no external implementation source reused.
// Static1759ef0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1759ef0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1759ef0*);
    virtual void release(Static1759ef0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1759ef0*);
struct Static1759ef0 {
    void* value;
    Static1759ef0();
    ~Static1759ef0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
