// Source exposure: binary-analysis; no external implementation source reused.
// Static1782120, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1782120;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1782120*);
    virtual void release(Static1782120*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1782120*);
struct Static1782120 {
    void* value;
    Static1782120();
    ~Static1782120() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
