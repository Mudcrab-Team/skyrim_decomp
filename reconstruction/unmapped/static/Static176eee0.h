// Source exposure: binary-analysis; no external implementation source reused.
// Static176eee0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176eee0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176eee0*);
    virtual void release(Static176eee0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176eee0*);
struct Static176eee0 {
    void* value;
    Static176eee0();
    ~Static176eee0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
