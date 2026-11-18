// Source exposure: binary-analysis; no external implementation source reused.
// Static177cae0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177cae0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177cae0*);
    virtual void release(Static177cae0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177cae0*);
struct Static177cae0 {
    void* value;
    Static177cae0();
    ~Static177cae0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
