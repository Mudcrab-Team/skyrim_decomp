// Source exposure: binary-analysis; no external implementation source reused.
// Static1762370, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1762370;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1762370*);
    virtual void release(Static1762370*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1762370*);
struct Static1762370 {
    void* value;
    Static1762370();
    ~Static1762370() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
