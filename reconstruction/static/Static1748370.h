// Source exposure: binary-analysis; no external implementation source reused.
// Static1748370, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1748370;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1748370*);
    virtual void release(Static1748370*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1748370*);
struct Static1748370 {
    void* value;
    Static1748370();
    ~Static1748370() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
