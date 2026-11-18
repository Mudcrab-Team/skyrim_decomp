// Source exposure: binary-analysis; no external implementation source reused.
// Static1780820, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1780820;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1780820*);
    virtual void release(Static1780820*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1780820*);
struct Static1780820 {
    void* value;
    Static1780820();
    ~Static1780820() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
