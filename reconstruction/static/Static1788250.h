// Source exposure: binary-analysis; no external implementation source reused.
// Static1788250, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1788250;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1788250*);
    virtual void release(Static1788250*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1788250*);
struct Static1788250 {
    void* value;
    Static1788250();
    ~Static1788250() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
