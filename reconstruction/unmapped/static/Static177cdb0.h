// Source exposure: binary-analysis; no external implementation source reused.
// Static177cdb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177cdb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177cdb0*);
    virtual void release(Static177cdb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177cdb0*);
struct Static177cdb0 {
    void* value;
    Static177cdb0();
    ~Static177cdb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
