// Source exposure: binary-analysis; no external implementation source reused.
// Static174dba0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174dba0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174dba0*);
    virtual void release(Static174dba0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174dba0*);
struct Static174dba0 {
    void* value;
    Static174dba0();
    ~Static174dba0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
