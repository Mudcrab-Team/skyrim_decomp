// Source exposure: binary-analysis; no external implementation source reused.
// Static1774930, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1774930;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1774930*);
    virtual void release(Static1774930*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1774930*);
struct Static1774930 {
    void* value;
    Static1774930();
    ~Static1774930() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
