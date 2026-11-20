// Source exposure: binary-analysis; no external implementation source reused.
// Static1758820, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1758820;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1758820*);
    virtual void release(Static1758820*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1758820*);
struct Static1758820 {
    void* value;
    Static1758820();
    ~Static1758820() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
