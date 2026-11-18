// Source exposure: binary-analysis; no external implementation source reused.
// Static1752ba0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1752ba0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1752ba0*);
    virtual void release(Static1752ba0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1752ba0*);
struct Static1752ba0 {
    void* value;
    Static1752ba0();
    ~Static1752ba0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
