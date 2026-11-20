// Source exposure: binary-analysis; no external implementation source reused.
// Static1788930, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1788930;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1788930*);
    virtual void release(Static1788930*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1788930*);
struct Static1788930 {
    void* value;
    Static1788930();
    ~Static1788930() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
