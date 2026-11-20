// Source exposure: binary-analysis; no external implementation source reused.
// Static174adf0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174adf0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174adf0*);
    virtual void release(Static174adf0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174adf0*);
struct Static174adf0 {
    void* value;
    Static174adf0();
    ~Static174adf0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
