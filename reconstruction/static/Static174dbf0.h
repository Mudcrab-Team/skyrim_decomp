// Source exposure: binary-analysis; no external implementation source reused.
// Static174dbf0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174dbf0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174dbf0*);
    virtual void release(Static174dbf0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174dbf0*);
struct Static174dbf0 {
    void* value;
    Static174dbf0();
    ~Static174dbf0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
