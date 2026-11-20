// Source exposure: binary-analysis; no external implementation source reused.
// Static1758640, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1758640;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1758640*);
    virtual void release(Static1758640*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1758640*);
struct Static1758640 {
    void* value;
    Static1758640();
    ~Static1758640() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
