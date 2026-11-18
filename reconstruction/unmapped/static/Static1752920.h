// Source exposure: binary-analysis; no external implementation source reused.
// Static1752920, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1752920;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1752920*);
    virtual void release(Static1752920*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1752920*);
struct Static1752920 {
    void* value;
    Static1752920();
    ~Static1752920() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
