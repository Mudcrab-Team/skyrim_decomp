// Source exposure: binary-analysis; no external implementation source reused.
// Static1750670, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1750670;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1750670*);
    virtual void release(Static1750670*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1750670*);
struct Static1750670 {
    void* value;
    Static1750670();
    ~Static1750670() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
