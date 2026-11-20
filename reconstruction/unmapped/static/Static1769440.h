// Source exposure: binary-analysis; no external implementation source reused.
// Static1769440, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1769440;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1769440*);
    virtual void release(Static1769440*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1769440*);
struct Static1769440 {
    void* value;
    Static1769440();
    ~Static1769440() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
