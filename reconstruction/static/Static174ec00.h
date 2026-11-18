// Source exposure: binary-analysis; no external implementation source reused.
// Static174ec00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174ec00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174ec00*);
    virtual void release(Static174ec00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174ec00*);
struct Static174ec00 {
    void* value;
    Static174ec00();
    ~Static174ec00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
