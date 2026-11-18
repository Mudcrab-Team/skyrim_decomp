// Source exposure: binary-analysis; no external implementation source reused.
// Static17c0bf0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17c0bf0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17c0bf0*);
    virtual void release(Static17c0bf0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17c0bf0*);
struct Static17c0bf0 {
    void* value;
    Static17c0bf0();
    ~Static17c0bf0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
