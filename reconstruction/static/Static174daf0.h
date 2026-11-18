// Source exposure: binary-analysis; no external implementation source reused.
// Static174daf0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174daf0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174daf0*);
    virtual void release(Static174daf0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174daf0*);
struct Static174daf0 {
    void* value;
    Static174daf0();
    ~Static174daf0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
