// Source exposure: binary-analysis; no external implementation source reused.
// Static179ee50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179ee50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179ee50*);
    virtual void release(Static179ee50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179ee50*);
struct Static179ee50 {
    void* value;
    Static179ee50();
    ~Static179ee50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
