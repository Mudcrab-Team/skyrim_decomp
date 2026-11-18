// Source exposure: binary-analysis; no external implementation source reused.
// Static174fc20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174fc20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174fc20*);
    virtual void release(Static174fc20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174fc20*);
struct Static174fc20 {
    void* value;
    Static174fc20();
    ~Static174fc20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
