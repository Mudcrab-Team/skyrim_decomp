// Source exposure: binary-analysis; no external implementation source reused.
// Static174fc70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174fc70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174fc70*);
    virtual void release(Static174fc70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174fc70*);
struct Static174fc70 {
    void* value;
    Static174fc70();
    ~Static174fc70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
