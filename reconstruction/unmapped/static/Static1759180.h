// Source exposure: binary-analysis; no external implementation source reused.
// Static1759180, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1759180;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1759180*);
    virtual void release(Static1759180*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1759180*);
struct Static1759180 {
    void* value;
    Static1759180();
    ~Static1759180() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
