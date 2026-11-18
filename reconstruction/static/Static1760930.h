// Source exposure: binary-analysis; no external implementation source reused.
// Static1760930, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1760930;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1760930*);
    virtual void release(Static1760930*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1760930*);
struct Static1760930 {
    void* value;
    Static1760930();
    ~Static1760930() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
