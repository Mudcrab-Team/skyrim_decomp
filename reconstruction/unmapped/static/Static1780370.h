// Source exposure: binary-analysis; no external implementation source reused.
// Static1780370, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1780370;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1780370*);
    virtual void release(Static1780370*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1780370*);
struct Static1780370 {
    void* value;
    Static1780370();
    ~Static1780370() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
