// Source exposure: binary-analysis; no external implementation source reused.
// Static175ee00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175ee00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175ee00*);
    virtual void release(Static175ee00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175ee00*);
struct Static175ee00 {
    void* value;
    Static175ee00();
    ~Static175ee00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
