// Source exposure: binary-analysis; no external implementation source reused.
// Static176edf0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176edf0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176edf0*);
    virtual void release(Static176edf0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176edf0*);
struct Static176edf0 {
    void* value;
    Static176edf0();
    ~Static176edf0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
