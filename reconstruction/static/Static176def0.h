// Source exposure: binary-analysis; no external implementation source reused.
// Static176def0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176def0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176def0*);
    virtual void release(Static176def0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176def0*);
struct Static176def0 {
    void* value;
    Static176def0();
    ~Static176def0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
