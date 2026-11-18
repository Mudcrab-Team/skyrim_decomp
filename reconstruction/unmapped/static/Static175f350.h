// Source exposure: binary-analysis; no external implementation source reused.
// Static175f350, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175f350;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175f350*);
    virtual void release(Static175f350*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175f350*);
struct Static175f350 {
    void* value;
    Static175f350();
    ~Static175f350() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
