// Source exposure: binary-analysis; no external implementation source reused.
// Static1750bc0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1750bc0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1750bc0*);
    virtual void release(Static1750bc0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1750bc0*);
struct Static1750bc0 {
    void* value;
    Static1750bc0();
    ~Static1750bc0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
