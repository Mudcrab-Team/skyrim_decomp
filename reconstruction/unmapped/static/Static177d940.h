// Source exposure: binary-analysis; no external implementation source reused.
// Static177d940, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177d940;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177d940*);
    virtual void release(Static177d940*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177d940*);
struct Static177d940 {
    void* value;
    Static177d940();
    ~Static177d940() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
