// Source exposure: binary-analysis; no external implementation source reused.
// Static17ad610, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ad610;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ad610*);
    virtual void release(Static17ad610*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ad610*);
struct Static17ad610 {
    void* value;
    Static17ad610();
    ~Static17ad610() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
