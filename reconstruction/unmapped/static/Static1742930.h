// Source exposure: binary-analysis; no external implementation source reused.
// Static1742930, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1742930;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1742930*);
    virtual void release(Static1742930*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1742930*);
struct Static1742930 {
    void* value;
    Static1742930();
    ~Static1742930() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
