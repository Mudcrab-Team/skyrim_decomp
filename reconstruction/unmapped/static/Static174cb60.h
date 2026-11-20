// Source exposure: binary-analysis; no external implementation source reused.
// Static174cb60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174cb60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174cb60*);
    virtual void release(Static174cb60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174cb60*);
struct Static174cb60 {
    void* value;
    Static174cb60();
    ~Static174cb60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
