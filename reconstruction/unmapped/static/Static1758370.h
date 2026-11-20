// Source exposure: binary-analysis; no external implementation source reused.
// Static1758370, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1758370;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1758370*);
    virtual void release(Static1758370*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1758370*);
struct Static1758370 {
    void* value;
    Static1758370();
    ~Static1758370() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
