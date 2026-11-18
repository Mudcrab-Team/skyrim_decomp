// Source exposure: binary-analysis; no external implementation source reused.
// Static17acee0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17acee0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17acee0*);
    virtual void release(Static17acee0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17acee0*);
struct Static17acee0 {
    void* value;
    Static17acee0();
    ~Static17acee0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
