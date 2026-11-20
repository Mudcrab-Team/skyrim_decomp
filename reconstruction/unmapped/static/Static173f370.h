// Source exposure: binary-analysis; no external implementation source reused.
// Static173f370, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173f370;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173f370*);
    virtual void release(Static173f370*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173f370*);
struct Static173f370 {
    void* value;
    Static173f370();
    ~Static173f370() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
