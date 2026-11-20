// Source exposure: binary-analysis; no external implementation source reused.
// Static174ed50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174ed50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174ed50*);
    virtual void release(Static174ed50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174ed50*);
struct Static174ed50 {
    void* value;
    Static174ed50();
    ~Static174ed50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
