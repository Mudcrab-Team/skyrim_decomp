// Source exposure: binary-analysis; no external implementation source reused.
// Static1765930, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1765930;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1765930*);
    virtual void release(Static1765930*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1765930*);
struct Static1765930 {
    void* value;
    Static1765930();
    ~Static1765930() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
