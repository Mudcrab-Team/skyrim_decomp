// Source exposure: binary-analysis; no external implementation source reused.
// Static1778670, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1778670;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1778670*);
    virtual void release(Static1778670*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1778670*);
struct Static1778670 {
    void* value;
    Static1778670();
    ~Static1778670() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
