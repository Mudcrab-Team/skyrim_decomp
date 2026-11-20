// Source exposure: binary-analysis; no external implementation source reused.
// Static17abee0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17abee0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17abee0*);
    virtual void release(Static17abee0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17abee0*);
struct Static17abee0 {
    void* value;
    Static17abee0();
    ~Static17abee0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
