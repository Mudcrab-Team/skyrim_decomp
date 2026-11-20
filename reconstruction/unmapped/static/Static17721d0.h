// Source exposure: binary-analysis; no external implementation source reused.
// Static17721d0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17721d0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17721d0*);
    virtual void release(Static17721d0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17721d0*);
struct Static17721d0 {
    void* value;
    Static17721d0();
    ~Static17721d0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
