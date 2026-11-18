// Source exposure: binary-analysis; no external implementation source reused.
// Static174a000, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174a000;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174a000*);
    virtual void release(Static174a000*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174a000*);
struct Static174a000 {
    void* value;
    Static174a000();
    ~Static174a000() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
