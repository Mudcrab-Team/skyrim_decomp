// Source exposure: binary-analysis; no external implementation source reused.
// Static1791eb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1791eb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1791eb0*);
    virtual void release(Static1791eb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1791eb0*);
struct Static1791eb0 {
    void* value;
    Static1791eb0();
    ~Static1791eb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
