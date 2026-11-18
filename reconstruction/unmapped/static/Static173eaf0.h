// Source exposure: binary-analysis; no external implementation source reused.
// Static173eaf0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173eaf0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173eaf0*);
    virtual void release(Static173eaf0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173eaf0*);
struct Static173eaf0 {
    void* value;
    Static173eaf0();
    ~Static173eaf0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
