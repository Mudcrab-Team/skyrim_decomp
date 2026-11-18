// Source exposure: binary-analysis; no external implementation source reused.
// Static17acb50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17acb50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17acb50*);
    virtual void release(Static17acb50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17acb50*);
struct Static17acb50 {
    void* value;
    Static17acb50();
    ~Static17acb50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
