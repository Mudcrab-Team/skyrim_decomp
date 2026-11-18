// Source exposure: binary-analysis; no external implementation source reused.
// Static1760250, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1760250;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1760250*);
    virtual void release(Static1760250*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1760250*);
struct Static1760250 {
    void* value;
    Static1760250();
    ~Static1760250() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
