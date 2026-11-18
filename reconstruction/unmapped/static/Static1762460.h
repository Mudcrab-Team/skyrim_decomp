// Source exposure: binary-analysis; no external implementation source reused.
// Static1762460, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1762460;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1762460*);
    virtual void release(Static1762460*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1762460*);
struct Static1762460 {
    void* value;
    Static1762460();
    ~Static1762460() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
