// Source exposure: binary-analysis; no external implementation source reused.
// Static176a610, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176a610;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176a610*);
    virtual void release(Static176a610*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176a610*);
struct Static176a610 {
    void* value;
    Static176a610();
    ~Static176a610() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
