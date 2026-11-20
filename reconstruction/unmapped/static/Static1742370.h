// Source exposure: binary-analysis; no external implementation source reused.
// Static1742370, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1742370;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1742370*);
    virtual void release(Static1742370*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1742370*);
struct Static1742370 {
    void* value;
    Static1742370();
    ~Static1742370() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
