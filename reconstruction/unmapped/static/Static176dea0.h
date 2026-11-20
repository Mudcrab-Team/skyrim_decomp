// Source exposure: binary-analysis; no external implementation source reused.
// Static176dea0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176dea0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176dea0*);
    virtual void release(Static176dea0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176dea0*);
struct Static176dea0 {
    void* value;
    Static176dea0();
    ~Static176dea0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
