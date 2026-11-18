// Source exposure: binary-analysis; no external implementation source reused.
// Static1756930, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1756930;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1756930*);
    virtual void release(Static1756930*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1756930*);
struct Static1756930 {
    void* value;
    Static1756930();
    ~Static1756930() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
