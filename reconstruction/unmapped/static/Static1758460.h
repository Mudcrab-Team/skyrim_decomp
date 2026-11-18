// Source exposure: binary-analysis; no external implementation source reused.
// Static1758460, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1758460;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1758460*);
    virtual void release(Static1758460*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1758460*);
struct Static1758460 {
    void* value;
    Static1758460();
    ~Static1758460() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
