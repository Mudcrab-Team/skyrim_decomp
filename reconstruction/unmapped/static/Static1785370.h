// Source exposure: binary-analysis; no external implementation source reused.
// Static1785370, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1785370;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1785370*);
    virtual void release(Static1785370*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1785370*);
struct Static1785370 {
    void* value;
    Static1785370();
    ~Static1785370() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
