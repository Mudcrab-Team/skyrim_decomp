// Source exposure: binary-analysis; no external implementation source reused.
// Static177baf0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177baf0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177baf0*);
    virtual void release(Static177baf0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177baf0*);
struct Static177baf0 {
    void* value;
    Static177baf0();
    ~Static177baf0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
