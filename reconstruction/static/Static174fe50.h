// Source exposure: binary-analysis; no external implementation source reused.
// Static174fe50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174fe50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174fe50*);
    virtual void release(Static174fe50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174fe50*);
struct Static174fe50 {
    void* value;
    Static174fe50();
    ~Static174fe50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
