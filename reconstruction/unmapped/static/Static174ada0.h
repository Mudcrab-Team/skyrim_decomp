// Source exposure: binary-analysis; no external implementation source reused.
// Static174ada0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174ada0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174ada0*);
    virtual void release(Static174ada0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174ada0*);
struct Static174ada0 {
    void* value;
    Static174ada0();
    ~Static174ada0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
