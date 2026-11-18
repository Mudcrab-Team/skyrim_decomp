// Source exposure: binary-analysis; no external implementation source reused.
// Static1783200, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1783200;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1783200*);
    virtual void release(Static1783200*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1783200*);
struct Static1783200 {
    void* value;
    Static1783200();
    ~Static1783200() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
