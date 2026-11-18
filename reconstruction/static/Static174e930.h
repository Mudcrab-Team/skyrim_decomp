// Source exposure: binary-analysis; no external implementation source reused.
// Static174e930, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174e930;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174e930*);
    virtual void release(Static174e930*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174e930*);
struct Static174e930 {
    void* value;
    Static174e930();
    ~Static174e930() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
