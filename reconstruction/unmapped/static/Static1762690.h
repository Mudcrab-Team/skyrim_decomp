// Source exposure: binary-analysis; no external implementation source reused.
// Static1762690, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1762690;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1762690*);
    virtual void release(Static1762690*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1762690*);
struct Static1762690 {
    void* value;
    Static1762690();
    ~Static1762690() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
